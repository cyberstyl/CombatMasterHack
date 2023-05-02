#pragma once

//with these command classes u can do a whole bunch of exploits
class Command
{
public:
	CLASS("Photon.Bolt", "Command");

	int GetServerFrame()
	{
		METHOD(int(**)(Command*), get_ServerFrame);
		return get_ServerFrame(this);
	}

	void SetServerFrame(int value)
	{
		METHOD(void(**)(Command*, int), set_ServerFrame);
		set_ServerFrame(this, value);
	}
};

class IPlayerCommandResult
{
public:
	CLASS("Photon.Bolt", "IPlayerCommandResult");

	Vector3D GetPlayerPosition()
	{
		METHOD(Vector3D(**)(IPlayerCommandResult*), get_PlayerPosition);
		return get_PlayerPosition(this);
	}

	void SetPlayerPosition(Vector3D value)
	{
		METHOD(void(**)(IPlayerCommandResult*, Vector3D), set_PlayerPosition);
		set_PlayerPosition(this, value);
	}

	Vector3D GetPlayerRotation()
	{
		METHOD(Vector3D(**)(IPlayerCommandResult*), get_PlayerRotation);
		return get_PlayerRotation(this);
	}

	void SetPlayerRotation(Vector3D value)
	{
		METHOD(void(**)(IPlayerCommandResult*, Vector3D), set_PlayerRotation);
		set_PlayerRotation(this, value);
	}

	Vector3D GetPlayerFPSRotation()
	{
		METHOD(Vector3D(**)(IPlayerCommandResult*), get_PlayerFPSRotation);
		return get_PlayerFPSRotation(this);
	}

	void SetPlayerFPSRotation(Vector3D value)
	{
		METHOD(void(**)(IPlayerCommandResult*, Vector3D), set_PlayerFPSRotation);
		set_PlayerFPSRotation(this, value);
	}

	Vector3D GetFallingAccumulativeSpeed()
	{
		METHOD(Vector3D(**)(IPlayerCommandResult*), get_FallingAccumulativeSpeed);
		return get_FallingAccumulativeSpeed(this);
	}

	void SetFallingAccumulativeSpeed(Vector3D value)
	{
		METHOD(void(**)(IPlayerCommandResult*, Vector3D), set_FallingAccumulativeSpeed);
		set_FallingAccumulativeSpeed(this, value);
	}
};

class PlayerCommandResult : IPlayerCommandResult
{
public:
	CLASS("Photon.Bolt", "PlayerCommandResult");

	Vector3D GetPlayerPosition()
	{
		METHOD(Vector3D(**)(PlayerCommandResult*), get_PlayerPosition);
		return get_PlayerPosition(this);
	}

	void SetPlayerPosition(Vector3D value)
	{
		METHOD(void(**)(PlayerCommandResult*, Vector3D), set_PlayerPosition);
		set_PlayerPosition(this, value);
	}

	Vector3D GetPlayerRotation()
	{
		METHOD(Vector3D(**)(PlayerCommandResult*), get_PlayerRotation);
		return get_PlayerRotation(this);
	}

	void SetPlayerRotation(Vector3D value)
	{
		METHOD(void(**)(PlayerCommandResult*, Vector3D), set_PlayerRotation);
		set_PlayerRotation(this, value);
	}

	Vector3D GetPlayerFPSRotation()
	{
		METHOD(Vector3D(**)(PlayerCommandResult*), get_PlayerFPSRotation);
		return get_PlayerFPSRotation(this);
	}

	void SetPlayerFPSRotation(Vector3D value)
	{
		METHOD(void(**)(PlayerCommandResult*, Vector3D), set_PlayerFPSRotation);
		set_PlayerFPSRotation(this, value);
	}

	Vector3D GetFallingAccumulativeSpeed()
	{
		METHOD(Vector3D(**)(PlayerCommandResult*), get_FallingAccumulativeSpeed);
		return get_FallingAccumulativeSpeed(this);
	}

	void SetFallingAccumulativeSpeed(Vector3D value)
	{
		METHOD(void(**)(PlayerCommandResult*, Vector3D), set_FallingAccumulativeSpeed);
		set_FallingAccumulativeSpeed(this, value);
	}
};

class IPlayerCommandInput
{
public:
	CLASS("Photon.Bolt", "IPlayerCommandInput");

	int GetChargedAmmoLeft()
	{
		METHOD(int(**)(IPlayerCommandInput*), get_ChargedAmmoLeft);
		return get_ChargedAmmoLeft(this);
	}

	void SetChargedAmmoLeft(int value)
	{
		METHOD(void(**)(IPlayerCommandInput*, int), set_ChargedAmmoLeft);
		return set_ChargedAmmoLeft(this, value);
	}

	int GetShootSeed()
	{
		METHOD(int(**)(IPlayerCommandInput*), get_ShootSeed);
		return get_ShootSeed(this);
	}

	void SetShootSeed(int value)
	{
		METHOD(void(**)(IPlayerCommandInput*, int), set_ShootSeed);
		return set_ShootSeed(this, value);
	}

	bool GetReadyForSpawn()
	{
		METHOD(bool(**)(IPlayerCommandInput*), get_ShootSeed);
		return get_ShootSeed(this);
	}

	void SetReadyForSpawn(bool value)
	{
		METHOD(void(**)(IPlayerCommandInput*, bool), set_ReadyForSpawn);
		return set_ReadyForSpawn(this, value);
	}
};

class PlayerCommand : Command
{
public:
	CLASS("Photon.Bolt", "PlayerCommand");

	IPlayerCommandInput GetInput()
	{
		METHOD(IPlayerCommandInput(**)(PlayerCommand*), get_Input);
		return get_Input(this);
	}

	IPlayerCommandResult GetResult()
	{
		METHOD(IPlayerCommandResult(**)(PlayerCommand*), get_Result);
		return get_Result(this);
	}
};
