#include "../../Includes.hpp"

void PlayerESP::GetBoundingBox(PlayerRoot* player, Box& box)
{ //not the best way of doing this but good enough
	if (!player) {
		Hooks::Game::allPlayers.clear();
		return;
	}

	Vector3D bottom = player->GetTransform()->GetPosition();
	Vector3D top = bottom + (player->GetHeadHitbox()->GetHitboxCenter() * 1.2f);

	Vector2D topScreen = player->GetMainCamera()->WorldToScreenPointFixed(top);
	Vector2D bottomScreen = player->GetMainCamera()->WorldToScreenPointFixed(bottom);

	Vector2D delta = topScreen - bottomScreen;

	box.h = fabsf(delta.y);
	box.w = box.h / 2;
	box.x = topScreen.x - (box.w / 2);
	box.y = topScreen.y;
}

void PlayerESP::OnRender()
{
	if (!Menu::Vars::esp)
		return;

	if (!Hooks::Game::localPlayer) {
		Hooks::Game::allPlayers.clear();
		return;
	}

	if (Hooks::Game::allPlayers.empty())
		return;

	//currently it will crash when leaving a match due to allPlayers not being reset when they need to
	//easily fixable but this project isnt for proper hack purposes or everything working, simply for me
	//to learn some unity gamehacking :)

	for (const auto currentPlayer : Hooks::Game::allPlayers) {
		if (!currentPlayer)
			continue;
		Box box;

		GetBoundingBox(currentPlayer, box);

		auto drawList = ImGui::GetForegroundDrawList();

		//@TODO put these in diff funcs so it doesnt look cluttered af

		//box
		auto color = currentPlayer->GetIsVisible() ? ImColor(225, 40, 40, 255) : ImColor(255, 255, 255, 255);

		drawList->AddRect(ImVec2(box.x - 1, box.y - 1), ImVec2(box.x + box.w + 1, box.y + box.h + 1), ImColor(0, 0, 0, 255));
		drawList->AddRect(ImVec2(box.x, box.y), ImVec2(box.x + box.w, box.y + box.h), color);
		drawList->AddRect(ImVec2(box.x + 1, box.y + 1), ImVec2(box.x + box.w - 1, box.y + box.h - 1), ImColor(0, 0, 0, 255));

		//health
		auto health = currentPlayer->GetPlayerHealth()->GetHealth();

		Box nBox =
		{
			box.x - 2,
			box.y,
			1,
			box.h
		};

		auto barHeight = (int)((float)health * (float)nBox.h / 100.0f);
		auto offset = nBox.h - barHeight;

		drawList->AddLine(ImVec2(nBox.x, nBox.y + offset), ImVec2(nBox.x, nBox.y + offset + barHeight), ImColor(50, 225, 50, 255));

		//flags
		int flagOffset = 0;

		if (!currentPlayer->GetIsRealPlayer()) {
			drawList->AddText(ImVec2(box.x + box.w + 1, box.y + flagOffset), ImColor(255, 225, 255, 255), "BOT");
			flagOffset += 12;
		}

		if (currentPlayer->GetIsVisible()) {
			drawList->AddText(ImVec2(box.x + box.w + 1, box.y + flagOffset), ImColor(255, 225, 255, 255), "Visible");
			flagOffset += 12;
		}

		if (currentPlayer->GetPlayerHealth()->GetIsInvincible()) {
			drawList->AddText(ImVec2(box.x + box.w + 1, box.y + flagOffset), ImColor(255, 225, 255, 255), "Invincible");
			flagOffset += 12;
		}

		if (currentPlayer->GetPlayerHealth()->GetIsSelfReviving()) {
			drawList->AddText(ImVec2(box.x + box.w + 1, box.y + flagOffset), ImColor(225, 40, 40, 255), "Self Revive");
			flagOffset += 12;
		}

		if (currentPlayer->GetPlayerHealth()->GetIsDowned()) {
			drawList->AddText(ImVec2(box.x + box.w + 1, box.y + flagOffset), ImColor(215, 190, 35, 255), "Downed");
			flagOffset += 12;
		}

		if (currentPlayer->GetPlayerArming()->GetIsBombPlantingOrDefusing()) {
			drawList->AddText(ImVec2(box.x + box.w + 1, box.y + flagOffset), ImColor(225, 40, 40, 255), "Plant/Diffuse");
			flagOffset += 12;
		}

		if (currentPlayer->GetPlayerArming()->GetIsReloading()) {
			drawList->AddText(ImVec2(box.x + box.w + 1, box.y + flagOffset), ImColor(215, 190, 35, 255), "Reloading");
			flagOffset += 12;
		}

		//weapon+ammo
		auto weapon = currentPlayer->GetPlayerArming()->GetActiveWeapon();
		auto isExplosive = weapon->GetWeaponInfo()->GetIsExplosive();
		auto isMelee = weapon->GetWeaponInfo()->GetIsMeleeWeapon();

		//@TODO: get actual weapon name lolz
		std::string weaponText = isExplosive ? "Explosive" : isMelee ? "Melee" : "Gun";
		auto weaponTextSize = ImGui::CalcTextSize(weaponText.c_str());

		std::string ammoText = isExplosive ? "" : isMelee ? "" : std::to_string(weapon->GetChargedAmmo()) + "/" + std::to_string(weapon->GetUnchargedAmmo());
		auto ammoTextSize = ImGui::CalcTextSize(ammoText.c_str());

		drawList->AddText(ImVec2(box.x + box.w / 2 - (weaponTextSize.x / 2), box.y + box.h + 1), ImColor(255, 255, 255, 255), weaponText.c_str());
		drawList->AddText(ImVec2(box.x + box.w / 2 - (ammoTextSize.x / 2), box.y + box.h + 13), ImColor(255, 255, 255, 255), ammoText.c_str());

		//@TODO: name esp
	}
}