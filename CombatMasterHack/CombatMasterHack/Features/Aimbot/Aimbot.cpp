#include "../../Includes.hpp"

void Aimbot::OnTick()
{
	if (!Menu::Vars::aimbot)
		return;

	if (!Hooks::Game::localPlayer) {
		Hooks::Game::allPlayers.clear();
		return;
	}

	if (Hooks::Game::allPlayers.empty())
		return;

	if (!GetAsyncKeyState(VK_LBUTTON))
		return;

	auto localPos = Hooks::Game::localPlayer->GetFPSPivot()->GetPosition();
	auto localForward = Hooks::Game::localPlayer->GetFPSPivot()->GetForward();

	for (const auto currentPlayer : Hooks::Game::allPlayers) {
		if (!currentPlayer)
			continue;

		if (!currentPlayer->GetIsVisible())
			continue;

		Vector3D enemyPos = currentPlayer->GetTransform()->GetPosition() + currentPlayer->GetHeadHitbox()->GetHitboxCenter();
		Vector3D direction = enemyPos - localPos;

		MyQuaternion targetRotation = UnityEngine::Quaternion::LookRotation(direction);
		MyQuaternion aimAngle = UnityEngine::Quaternion::RotateTowards(Hooks::Game::localPlayer->GetFPSPivot()->GetRotation(), 
			                    targetRotation, UnityEngine::Time::GetDeltaTime() * 1000.f);

		Hooks::Game::localPlayer->GetFPSPivot()->SetRotation(aimAngle);
		//currently rotates camera also gets overridden in multiplayer, still works for auto guns since the server doesnt fix it instantly
	}
}

void Aimbot::RunTeleportHack()
{
	if (!Menu::Vars::teleportPlayers)
		return;

	if (!Hooks::Game::localPlayer)
		return;

	if (Hooks::Game::localPlayer->GetPlayerHealth()->GetIsDead())
		return;

	if (Hooks::Game::allPlayers.empty())
		return;

	if (!GetAsyncKeyState('L'))
		return;

	for (auto currentPlayer : Hooks::Game::allPlayers) {

		if (currentPlayer->GetTeamID() == Hooks::Game::localPlayer->GetTeamID())
			continue;

		if (currentPlayer->GetPlayerHealth()->GetIsDead())
			continue;

		if (Hooks::Game::localPlayer->GetPlayerHealth()->GetIsDead())
			continue;

		//only works in local match, to make this work in multiplayer look at playercommand classes, not too difficult
		currentPlayer->GetTransform()->SetPosition(Hooks::Game::localPlayer->GetTransform()->GetPosition() + Hooks::Game::localPlayer->GetTransform()->GetForward() * 2);
	}
}