#pragma once
//@TODO: fix dis
struct EntityType
{
public:
	CLASS("CombatMaster.GDI", "EntityType");

	String* GetLocalizedNameKey()
	{
		METHOD(String*(**)(EntityType*), get_LocalizeNameKey);
		return get_LocalizeNameKey(this);
	}

	//TypeInfo GetInfo()
	//{
	//	METHOD(TypeInfo(**)(EntityType*), get_Info);
	//	return get_Info(this);
	//}

	String* ToString()
	{
		METHOD(String*(**)(EntityType*), ToString);
		return ToString(this);
	}

	bool GetExists()
	{
		METHOD(bool(**)(EntityType*), get_Exists);
		return get_Exists(this);
	}
};