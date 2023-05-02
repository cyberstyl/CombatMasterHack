#include "../../Includes.hpp"

void Menu::InitMenu(bool menuOpened)
{
	if (!menuOpened)
		return;

	ImGui::Begin("sus");
	{
		ImGui::BeginChild("balls");
		{
			ImGui::Checkbox("ESP", &Menu::Vars::esp);

			ImGui::Checkbox("Aimbot", &Menu::Vars::aimbot);
			//@TODO
			ImGui::Checkbox("Infinite Ammo", &Menu::Vars::infiniteAmmo);

			ImGui::Checkbox("Instakill Headshots", &Menu::Vars::instakillHeadshots);

			ImGui::Checkbox("Instakill Bash", &Menu::Vars::instakillBash);

			ImGui::Checkbox("Bash Rapidfire", &Menu::Vars::bashRapidFire);

			ImGui::Checkbox("Infinite Bash range", &Menu::Vars::infiniteBashRange);
			//@TODO
			ImGui::Checkbox("No Sway", &Menu::Vars::noSway);
			//@TODO
			ImGui::Checkbox("No Spread", &Menu::Vars::noSpread);

			ImGui::Checkbox("No Recoil", &Menu::Vars::noRecoil);
			//@TODO
			ImGui::Checkbox("FlyHack", &Menu::Vars::flyHack);

			ImGui::Checkbox("SpeedHack", &Menu::Vars::speedHack);

			ImGui::Checkbox("Instant Scope", &Menu::Vars::instantScope);

			ImGui::Checkbox("XP Hack", &Menu::Vars::xpHack);
			//@TODO
			ImGui::Checkbox("Unlock Battlepass", &Menu::Vars::unlockBattlepass);
			//@TODO
			ImGui::Checkbox("Bypass Hacker Detection", &Menu::Vars::bypassHackerDetection);

			ImGui::Checkbox("Teleport players to you (L KEY)", &Menu::Vars::teleportPlayers);

			if (ImGui::Button("Reset"))
				once = false;
		}
		ImGui::EndChild();
	}
	ImGui::End();

}