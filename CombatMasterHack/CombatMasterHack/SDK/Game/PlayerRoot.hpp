#pragma once

class PlayerInput
{
public:
	CLASS("UnityEngine.InputSystem", "PlayerInput");

	int GetPlayerIndex()
	{
		METHOD(int(**)(PlayerInput*), get_playerIndex);
		return get_playerIndex(this);
	}
};

class PlayerInfoViewModel
{
public:
	CLASS("CombatMaster.View.UI.ViewModels", "PlayerInfoViewModel");

	MEMBER(std::string, PlayerName);
	MEMBER(int, Level);
	MEMBER(int, HardMoney);
	MEMBER(bool, XpBoostEventEnabled);
	MEMBER(bool, ProfileDoubleXpEnabled);
	MEMBER(bool, BattlePassDoubleXpEnabled);
};

class MatchInfo
{
public:
	CLASS("CombatMaster.GDI", "MatchInfo");

	MEMBER(int, VictoryExpBonus);
	MEMBER(int, FirstPlaceExpBonus);
	MEMBER(int, SecondPlaceExpBonus);
	MEMBER(int, ThirdPlaceExpBonus);
	MEMBER(float, HighlightExpMultiplier);
	MEMBER(int, MaxPlayers);
	MEMBER(float, WarmUpTime);
};

//this is exactly what it looks like :)
class NetPlayerData
{
public:
	CLASS("Photon.Bolt", "NetPlayerData");

	int GetKills()
	{
		METHOD(int(**)(NetPlayerData*), get_Kills);
		return get_Kills(this);
	}

	void SetKills(int value)
	{
		METHOD(void(**)(NetPlayerData*, int), set_Kills);
		return set_Kills(this, value);
	}

	int GetDeaths()
	{
		METHOD(int(**)(NetPlayerData*), get_Deaths);
		return get_Deaths(this);
	}

	void SetDeaths(int value)
	{
		METHOD(void(**)(NetPlayerData*, int), set_Deaths);
		return set_Deaths(this, value);
	}

	int GetScore()
	{
		METHOD(int(**)(NetPlayerData*), get_Score);
		return get_Score(this);
	}

	void SetScore(int value)
	{
		METHOD(void(**)(NetPlayerData*, int), set_Score);
		return set_Score(this, value);
	}

	int GetHeadshots()
	{
		METHOD(int(**)(NetPlayerData*), get_Headshots);
		return get_Headshots(this);
	}

	void SetHeadshots(int value)
	{
		METHOD(void(**)(NetPlayerData*, int), set_Headshots);
		return set_Headshots(this, value);
	}
};

class PlayerMobView
{
public:
	CLASS("CombatMaster.Battle.Gameplay.Player", "PlayerMobView");
	//@TODO
};

//their controller aim assist, when i first took it i didnt realize it was controller only lol
class PlayerAimAssist
{
public:
	CLASS("CombatMaster.Battle.Gameplay.Player", "PlayerAimAssist");

	MEMBER(float, _factor);
	MEMBER(float, _aimAngleThreshold);
	MEMBER(float, _aimEaseOutDampeningMultiplier);
	MEMBER(float, _timeToRegainOriginalInput);
	MEMBER(float, _deadZoneRadius);
	MEMBER(float, _timeToRegainOriginalInputSensitivity);
	MEMBER(float, _sensitivityMultiplierAtEdge);
	MEMBER(bool, _verticalCompensation);
	MEMBER(float, _verticalSmoothness);
	MEMBER(float, _lerpDistance);
	MEMBER(float, _horizontalSmoothnessTowardsTarget);
	MEMBER(float, _horizontalSmoothnessAwayFromTarget);
	MEMBER(float, _aimAssistSightAngle);
};

class OperatorInfo
{
public:
	CLASS("CombatMaster.GDI", "OperatorInfo");

	MEMBER(float, HeadHeight);
	MEMBER(bool, IsPremium);
	MEMBER(bool, IsSecret);
};

class PlayerMovement
{
public:
	CLASS("CombatMaster.Battle.Gameplay.Player", "PlayerMovement");
	static inline void(*oUpdate)(PlayerMovement*) = nullptr;

	bool GetIsClimbing()
	{
		METHOD(bool(**)(PlayerMovement*), get_IsClimbing);
		return get_IsClimbing(this);
	}

	bool GetIsZipLineMoving()
	{
		METHOD(bool(**)(PlayerMovement*), get_IsZipLineMoving);
		return get_IsZipLineMoving(this);
	}

	bool GetIsFreezeMovement()
	{
		METHOD(bool(**)(PlayerMovement*), get_IsFreezeMovement);
		return get_IsFreezeMovement(this);
	}

	bool GetIsParachute()
	{
		METHOD(bool(**)(PlayerMovement*), get_IsParachute);
		return get_IsParachute(this);
	}

	bool GetIsSliding()
	{
		METHOD(bool(**)(PlayerMovement*), get_IsSliding);
		return get_IsSliding(this);
	}

	bool GetIsCrouch()
	{
		METHOD(bool(**)(PlayerMovement*), get_IsCrouch);
		return get_IsCrouch(this);
	}

	bool GetIsFalling()
	{
		METHOD(bool(**)(PlayerMovement*), get_IsFalling);
		return get_IsFalling(this);
	}

	bool GetIsInAir()
	{
		METHOD(bool(**)(PlayerMovement*), get_IsInAir);
		return get_IsInAir(this);
	}

	float GetGroundDistance()
	{
		METHOD(float(**)(PlayerMovement*), get_DistanceToGround);
		return get_DistanceToGround(this);
	}

	void SetTargetRecoil(float newRecoil)
	{
		METHOD(void(**)(PlayerMovement*, float), SetTargetRecoil);
		SetTargetRecoil(this, newRecoil);
	}

	Vector3D GetVelocity()
	{
		METHOD(Vector3D(**)(PlayerMovement*), get_Velocity);
		return get_Velocity(this);
	}

	void ExecuteCommand(Command cmd, bool unkBool)
	{
		METHOD(void(**)(PlayerMovement*, Command, bool), ExecuteCommand);
		ExecuteCommand(this, cmd, unkBool);
	}
};

class BoltHitbox : public UnityEngine::Component
{
public:
	CLASS("Photon.Bolt.LagCompensation","BoltHitbox");

	Vector3D GetHitboxCenter()
	{
		METHOD(Vector3D(**)(BoltHitbox*), get_hitboxCenter);
		return get_hitboxCenter(this);
	}
};

class PlayerHealth
{
public:
	CLASS("CombatMaster.Battle.Gameplay.Player", "PlayerHealth");
	static inline void(*oUpdate)(PlayerHealth*) = nullptr;

	int GetHealth()
	{
		METHOD(int(**)(PlayerHealth*), get_Health);
		return get_Health(this);
	}

	int GetMaxHealth()
	{
		METHOD(int(**)(PlayerHealth*), get_MaxHealth);
		return get_MaxHealth(this);
	}

	void SetReadyForSpawn(bool unkBool)
	{
		METHOD(void(**)(PlayerHealth*, bool), set_ReadyForSpawn);
		set_ReadyForSpawn(this, unkBool);
	}

	int GetGasMaskStrength()
	{
		METHOD(int(**)(PlayerHealth*), get_GasMaskStrength);
		return get_GasMaskStrength(this);
	}

	int GetGasMaskFilters()
	{
		METHOD(int(**)(PlayerHealth*), get_GasMaskFilters);
		return get_GasMaskFilters(this);
	}

	bool GetIsSelfReviving()
	{
		METHOD(bool(**)(PlayerHealth*), get_IsSelfReviving);
		return get_IsSelfReviving(this);
	}

	bool GetIsDead()
	{
		METHOD(bool(**)(PlayerHealth*), get_IsDead);
		return get_IsDead(this);
	}

	int GetArmor()
	{
		METHOD(int(**)(PlayerHealth*), get_Armor);
		return get_Armor(this);
	}

	int GetMaxArmor()
	{
		METHOD(int(**)(PlayerHealth*), get_MaxArmor);
		return get_MaxArmor(this);
	}

	void ExecuteCommand(Command cmd, bool unkBool)
	{
		METHOD(void(**)(PlayerHealth*, Command, bool), ExecuteCommand);
		ExecuteCommand(this, cmd, unkBool);
	}

	bool GetIsResurrecting()
	{
		METHOD(bool(**)(PlayerHealth*), get_IsResurrecting);
		return get_IsResurrecting(this);
	}

	bool GetIsDowned()
	{
		METHOD(bool(**)(PlayerHealth*), get_IsDowned);
		return get_IsDowned(this);
	}

	bool GetIsInvincible()
	{
		METHOD(bool(**)(PlayerHealth*), get_IsInvincible);
		return get_IsInvincible(this);
	}
};

class PlayerRoot : public UnityEngine::Component
{
public:
	CLASS("CombatMaster.Battle.Gameplay.Player", "PlayerRoot");
	static inline void(*oUpdate)(PlayerRoot*) = nullptr;

	MEMBER(Transform*, _firstPersonPivot);

	Transform* GetFPSPivot()
	{
		METHOD(Transform*(**)(PlayerRoot*), get_FirstPersonPivot);
		return get_FirstPersonPivot(this);
	}

	PlayerHealth* GetPlayerHealth()
	{
		METHOD(PlayerHealth*(**)(PlayerRoot*), get_PlayerHealth);
		return get_PlayerHealth(this);
	}

	bool* GetIsVisible()
	{
		METHOD(bool*(**)(PlayerRoot*), get_IsVisible);
		return get_IsVisible(this);
	}

	bool* GetIsRealPlayer()
	{
		METHOD(bool*(**)(PlayerRoot*), get_IsRealPlayer);
		return get_IsRealPlayer(this);
	}

	BoltHitbox* GetBodyHitbox()
	{
		METHOD(BoltHitbox*(**)(PlayerRoot*), get_BodyHitbox);
		return get_BodyHitbox(this);
	}

	BoltHitbox* GetHeadHitbox()
	{
		METHOD(BoltHitbox*(**)(PlayerRoot*), get_HeadHitbox);
		return get_HeadHitbox(this);
	}

	PlayerMovement* GetPlayerMovement()
	{
		METHOD(PlayerMovement*(**)(PlayerRoot*), get_PlayerMovement);
		return get_PlayerMovement(this);
	}

	PlayerArming* GetPlayerArming()
	{
		METHOD(PlayerArming*(**)(PlayerRoot*), get_PlayerArming);
		return get_PlayerArming(this);
	}

	MatchInfo* GetPlayerMatchInfo()
	{
		METHOD(MatchInfo*(**)(PlayerRoot*), get_MatchInfo);
		return get_MatchInfo(this);
	}

	NetPlayerData* GetPlayerData()
	{
		METHOD(NetPlayerData*(**)(PlayerRoot*), get_PlayerData);
		return get_PlayerData(this);
	}

	PlayerMobView* GetActiveMobView()
	{
		METHOD(PlayerMobView*(**)(PlayerRoot*), get_ActiveMobView);
		return get_ActiveMobView(this);
	}

	UnityEngine::Camera* GetMainCamera()
	{
		METHOD(UnityEngine::Camera*(**)(PlayerRoot*), get_MainCamera);
		return get_MainCamera(this);
	}

	int GetTeamID()
	{
		METHOD(int(**)(PlayerRoot*), get_TeamId);
		return get_TeamId(this);
	}

	OperatorInfo* GetOperatorInfo()
	{
		METHOD(OperatorInfo*(**)(PlayerRoot*), get_Info);
		return get_Info(this);
	}

	PlayerAimAssist* GetAimAssist()
	{
		METHOD(PlayerAimAssist*(**)(PlayerRoot*), get_PlayerAimAssist);
		return get_PlayerAimAssist(this);
	}
};

class WorldUIManager
{
public:
	CLASS("CombatMaster.View.UI.ViewModels", "WorldUIManager");
};

class PlayerUIManager
{
public:
	CLASS("CombatMaster.View.UI.Gameplay", "PlayerUIManager");

	static PlayerRoot* GetMyPlayer()
	{
		METHOD(PlayerRoot*(**)(), get_MyPlayer);
		return get_MyPlayer();
	}

	static float GetMatchTimeLeft()
	{
		METHOD(float(**)(), get_MatchTimeLeft);
		return get_MatchTimeLeft();
	}
};