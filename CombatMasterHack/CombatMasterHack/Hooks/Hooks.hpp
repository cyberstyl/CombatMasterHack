#pragma once
namespace Hooks
{
	namespace DirectX9
	{
		inline D3D11_VIEWPORT viewport;

		inline ID3D11Device* pDevice = nullptr;
		inline ID3D11DeviceContext* pContext = nullptr;
		inline ID3D11RenderTargetView* mainRenderTargetView = nullptr;

		inline UINT vps = 1;

		inline HRESULT(*oPresent)(IDXGISwapChain* swapChain, UINT uSyncInterval, UINT uFlags) = nullptr;
		inline WNDPROC oWndProc = nullptr;

		LRESULT WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		HRESULT Present(IDXGISwapChain* swapChain, UINT uSyncInterval, UINT uFlags);
	}

	namespace Game
	{
		//bool IsHackerDetected();
		void OnPlayerHealthUpdate(PlayerHealth* _this);
		void OnPlayerRootUpdate(PlayerRoot* _this);
		void OnPlayerMovementUpdate(PlayerMovement* _this);

		inline std::deque <PlayerRoot*> allPlayers;
		inline PlayerRoot* localPlayer = nullptr;
	}

	void Init();
	void UnInit();
}