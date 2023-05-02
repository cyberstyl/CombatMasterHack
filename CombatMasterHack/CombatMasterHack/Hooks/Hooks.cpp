#include "../Includes.hpp"

void CreateHook(LPVOID target, LPVOID detour, LPVOID* original, std::string hookName)
{
	MH_STATUS statusCode = MH_CreateHook(target, detour, original);

	if (statusCode != MH_OK) {
		printf("Failed to hook %s, %i\n", hookName.c_str(), statusCode);
		return;
	}

	printf("Successfully hooked %s, %i\n", hookName.c_str(), statusCode);
}

PVOID* GetD3DVTable() 
{
	IDXGISwapChain* swapChain = nullptr;
	ID3D11Device* device = nullptr;
	ID3D11DeviceContext* context = nullptr;
	auto featureLevel = D3D_FEATURE_LEVEL_11_0;

	DXGI_SWAP_CHAIN_DESC sd = { 0 };
	ZeroMemory(&sd, sizeof sd);
	sd.BufferCount = 1;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = FindWindowA(nullptr, "Combat Master");
	sd.SampleDesc.Count = 1;
	sd.Windowed = TRUE;
	sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

	if (FAILED(D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, 0, 0, &featureLevel, 1, D3D11_SDK_VERSION, &sd, &swapChain, &device, nullptr, &context)))
		MessageBoxW(0, (L"Failed to create D3D11 device and swapChain"), (L"Failure"), MB_ICONERROR);

	PVOID* VTable = *reinterpret_cast<PVOID**>(swapChain);

	context->Release();
	device->Release();
	swapChain->Release();

	return VTable;
}

void Hooks::Init()
{
	if (MH_Initialize() != MH_OK)
		return;

	PVOID* VTable = GetD3DVTable();

	//@TODO: clean this up, kinda cancer to look at

	const auto playerHealthUpdate = 
	*reinterpret_cast<void**>(Il2CppWrapper::GetClassFromName("CombatMaster.Battle.Gameplay.Player", "PlayerHealth")->GetMethodFromName("Update"));
	const auto playerRootUpdate = 
	*reinterpret_cast<void**>(Il2CppWrapper::GetClassFromName("CombatMaster.Battle.Gameplay.Player", "PlayerRoot")->GetMethodFromName("Update"));
	const auto playerMovementUpdate =
	*reinterpret_cast<void**>(Il2CppWrapper::GetClassFromName("CombatMaster.Battle.Gameplay.Player", "PlayerMovement")->GetMethodFromName("Update"));

	CreateHook((void*)VTable[8], &DirectX9::Present, (void**)&DirectX9::oPresent, "Present");
	DirectX9::oWndProc = (WNDPROC)SetWindowLongPtrW(FindWindowA(nullptr, "Combat Master"), GWLP_WNDPROC, (LONG_PTR)DirectX9::WndProc);

	CreateHook(playerHealthUpdate, &Game::OnPlayerHealthUpdate, (void**)&PlayerHealth::oUpdate, "OnPlayerHealthUpdate");
	CreateHook(playerRootUpdate, &Game::OnPlayerRootUpdate, (void**)&PlayerRoot::oUpdate, "OnPlayerRootUpdate");
	CreateHook(playerMovementUpdate, &Game::OnPlayerMovementUpdate, (void**)&PlayerMovement::oUpdate, "OnPlayerMovementUpdate");

	Hooks::Game::allPlayers.clear();

	MH_EnableHook(MH_ALL_HOOKS);
}

void Hooks::UnInit()
{
	MH_DisableHook(MH_ALL_HOOKS);
	MH_RemoveHook(MH_ALL_HOOKS);

	MH_Uninitialize();

	(WNDPROC)SetWindowLongPtrW(FindWindowA(nullptr, "Combat Master"), GWLP_WNDPROC, (LONG_PTR)DirectX9::oWndProc);
}

//@TODO: make different files for these hooks, this is cluttered af

IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT Hooks::DirectX9::WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) 
{
	if (GetAsyncKeyState(VK_INSERT) & 1)
		Menu::menuOpened = !Menu::menuOpened;

	if (Menu::menuOpened && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProcA(oWndProc, hWnd, uMsg, wParam, lParam);
}

HRESULT Hooks::DirectX9::Present(IDXGISwapChain* swapChain, UINT uSyncInterval, UINT uFlags) 
{
	if (!pDevice) {
		swapChain->GetDevice(__uuidof(pDevice), reinterpret_cast<PVOID*>(&pDevice));
		pDevice->GetImmediateContext(&pContext);
		ID3D11Texture2D* renderTarget = nullptr;
		swapChain->GetBuffer(0, __uuidof(renderTarget), reinterpret_cast<PVOID*>(&renderTarget));
		pDevice->CreateRenderTargetView(renderTarget, nullptr, &mainRenderTargetView);
		renderTarget->Release();
		ImGui::CreateContext();
		ImGui::GetIO();

		ImGui_ImplWin32_Init(FindWindowA(nullptr, "Combat Master"));
		ImGui_ImplDX11_Init(pDevice, pContext);
	}

	pContext->OMSetRenderTargets(1, &mainRenderTargetView, nullptr);
	pContext->RSGetViewports(&vps, &viewport);

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	Menu::InitMenu(Menu::menuOpened);
	PlayerESP::OnRender();

	ImGui::EndFrame();

	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	return oPresent(swapChain, uSyncInterval, uFlags);
}

void Hooks::Game::OnPlayerHealthUpdate(PlayerHealth* _this)
{
	_this->oUpdate(_this);
}

float maxMatchTimeLeft = 0.f;

void Hooks::Game::OnPlayerRootUpdate(PlayerRoot* _this)
{
	if (!once) {
		maxMatchTimeLeft = PlayerUIManager::GetMatchTimeLeft();
		once = true;
	}
	//explanation for this autistic workaround:
	//when the matchtime is 0 it gets reset to its max match time, 
	//i dont wanna check for each game mode and based on that put it
	//so instead i just take the maxmatchtime once, still need to reset that on match end etc
	if (!_this || PlayerUIManager::GetMatchTimeLeft() >= maxMatchTimeLeft || PlayerUIManager::GetMatchTimeLeft() <= 0.5f) {
		Hooks::Game::localPlayer = nullptr;
		allPlayers.clear();
		_this->oUpdate(_this);
	}
	else {
		Hooks::Game::localPlayer = PlayerUIManager::GetMyPlayer();

		//im aware this shit is disgusting !
		bool notInside = find(allPlayers.begin(), allPlayers.end(), _this) == allPlayers.end();
		bool inside = find(allPlayers.begin(), allPlayers.end(), _this) != allPlayers.end();

		if (notInside && _this->GetTeamID() != Hooks::Game::localPlayer->GetTeamID() && !_this->GetPlayerHealth()->GetIsDead())
			allPlayers.push_back(_this); //doing this autistic ass thing instead of AllPlayers inside of PlayerRoot

		if (inside && _this->GetPlayerHealth()->GetIsDead())
			allPlayers.clear();

		if (localPlayer) {
			auto matchInfo = localPlayer->GetPlayerMatchInfo();

			if (Menu::Vars::xpHack) {
				matchInfo->VictoryExpBonus() = 9999.f;
				matchInfo->HighlightExpMultiplier() = 5.f;
			}

			if (!localPlayer->GetPlayerHealth()->GetIsDead()) {
				//@NOTE: all this shit only needs to get set once on round start (some just once overall)
				//also needs to get reset, rn if u disable the features it wont reset

				if (Menu::Vars::instakillHeadshots)
					localPlayer->GetPlayerArming()->GetActiveWeapon()->GetWeaponInfo()->DamageHeadMultiplier() = 10.f;

				//@TODO: properly fix sway, this is disgusting
				//del

				//most of this shit wont work on online, u can still achieve similar effects and bypass them easily
				if (Menu::Vars::instakillBash)
					localPlayer->GetPlayerArming()->GetActiveWeapon()->GetWeaponInfo()->BashDamage() = 500;

				if (Menu::Vars::infiniteBashRange)
					localPlayer->GetPlayerArming()->GetActiveWeapon()->GetWeaponInfo()->BashRange() = 500;

				if (Menu::Vars::bashRapidFire)
					localPlayer->GetPlayerArming()->GetActiveWeapon()->GetWeaponInfo()->BashRPM() = 1000;

				//still needa do this
				/*if (Menu::Vars::infiniteAmmo)
					printf("ammo: %i\n", localPlayer->GetPlayerArming()->GetActiveWeapon()->GetWeaponInfo()->AmmoAmount());*/

				if (Menu::Vars::instantScope) {
					localPlayer->GetPlayerArming()->GetActiveWeapon()->GetWeaponInfo()->AdsEnterMultiplier() = 0.f;
					localPlayer->GetPlayerArming()->GetActiveWeapon()->GetWeaponInfo()->AdsExitMultiplier() = 0.f;
				}

				if (Menu::Vars::speedHack) {
					localPlayer->GetPlayerArming()->GetActiveWeapon()->GetWeaponInfo()->MovementSpeedMultiplier() = 5.f;
					localPlayer->GetPlayerArming()->GetActiveWeapon()->GetWeaponInfo()->MovementAdsSpeedMultiplier() = 5.f;
				}
			}
		}

		Aimbot::RunTeleportHack();
		Aimbot::OnTick();

		_this->oUpdate(_this);
	}
}

void Hooks::Game::OnPlayerMovementUpdate(PlayerMovement* _this)
{
	if (Menu::Vars::noRecoil && localPlayer)
		localPlayer->GetPlayerMovement()->SetTargetRecoil(-10.f);

	_this->oUpdate(_this);
}