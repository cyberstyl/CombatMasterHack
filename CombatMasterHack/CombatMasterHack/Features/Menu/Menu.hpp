#pragma once

namespace Menu
{
	inline bool menuOpened = false;

	void InitMenu(bool menuOpened);

	namespace Vars
	{
		inline bool noRecoil = true;
		inline bool flyHack = false;
		inline bool speedHack = false;
		inline bool instantScope = true;
		inline bool xpHack = true;
		inline bool aimbot = false;
		inline bool infiniteAmmo = true;
		inline bool instakillHeadshots = true;
		inline bool instakillBash = true;
		inline bool bashRapidFire = true;
		inline bool infiniteBashRange = true;
		inline bool noSway = true;
		inline bool noSpread = true;
		inline bool esp = true;
		inline bool unlockBattlepass = false;
		inline bool bypassHackerDetection = true;
		inline bool teleportPlayers = true;
	}
}