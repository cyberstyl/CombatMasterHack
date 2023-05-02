#pragma once
class WeaponView
{
public:
    CLASS("CombatMaster.Battle", "WeaponView");

    EntityType* GetType()
    {
        METHOD(EntityType*(**)(WeaponView*), get_Type);
        return get_Type(this);
    }
};

class WeaponShootEntityEvent
{
public:
    CLASS("Photon.Bolt", "WeaponShootEntityEvent");

    int GetWeaponID()
    {
        METHOD(int(**)(WeaponShootEntityEvent*), get_WeaponId);
        return get_WeaponId(this);
    }

    int GetSeed()
    {
        METHOD(int(**)(WeaponShootEntityEvent*), get_Seed);
        return get_Seed(this);
    }

    void SetSeed(int value)
    {
        METHOD(void(**)(WeaponShootEntityEvent*, int), set_Seed);
        set_Seed(this, value);
    }

    int GetBulletsCount()
    {
        METHOD(int(**)(WeaponShootEntityEvent*), get_BulletsCount);
        return get_BulletsCount(this);
    }

    void SetBulletsCount(int value)
    {
        METHOD(void(**)(WeaponShootEntityEvent*, int), set_BulletsCount);
        set_BulletsCount(this, value);
    }

    float GetSpreadReducePercent()
    {
        METHOD(float(**)(WeaponShootEntityEvent*), get_SpreadReducePercent);
        return get_SpreadReducePercent(this);
    }

    void SetSpreadReducePercent(float value)
    {
        METHOD(void(**)(WeaponShootEntityEvent*, float), set_SpreadReducePercent);
        set_SpreadReducePercent(this, value);
    }

    Vector3D GetSpreadVertical()
    {
        METHOD(Vector3D(**)(WeaponShootEntityEvent*), get_SpreadVertical);
        return get_SpreadVertical(this);
    }

    void SetSpreadVertical(Vector3D value)
    {
        METHOD(void(**)(WeaponShootEntityEvent*, Vector3D), set_SpreadVertical);
        set_SpreadVertical(this, value);
    }

    Vector3D GetSpreadHorizontal()
    {
        METHOD(Vector3D(**)(WeaponShootEntityEvent*), get_SpreadHorizontal);
        return get_SpreadHorizontal(this);
    }

    void SetSpreadHorizontal(Vector3D value)
    {
        METHOD(void(**)(WeaponShootEntityEvent*, Vector3D), set_SpreadHorizontal);
        set_SpreadHorizontal(this, value);
    }
};

class IWeaponShootEntityEventListener
{
public:
    CLASS("Photon.Bolt", "IWeaponShootEntityEventListener");
};

class EntityEventListener : WeaponShootEntityEvent
{
public:
    CLASS("Photon.Bolt", "EntityEventListener");
    static inline void(*oEvent)(EntityEventListener*, WeaponShootEntityEvent*) = nullptr;

    void OnEvent(WeaponShootEntityEvent event) 
    { 
        METHOD(void(**)(EntityEventListener*, WeaponShootEntityEvent), OnEvent);
        OnEvent(this, event);
    }
};

struct Keyframe
{
public:
    CLASS("UnityEngine", "Keyframe");

    MEMBER(float, m_Time);
    MEMBER(float, m_Value);

    MEMBER(float, time);
    MEMBER(float, value);
};

class AnimationCurve
{
public:
    CLASS("UnityEngine", "AnimationCurve");

    MEMBER(int, length);
    MEMBER(Keyframe, Item);
    //Keyframe[] set_keys
};

struct WeaponSwaySettings
{
public:
    CLASS("CombatMaster.GDI", "WeaponSwaySettings");

    MEMBER(float, AngleRotation);
    MEMBER(float, AngleRotationAds);
    MEMBER(float, MaxAngleRotation);
    MEMBER(float, MaxAngleRotationAds);

    MEMBER(float, HorMoveRotation);
    MEMBER(float, HorMovePosOffset);
    MEMBER(float, ForwardMoveOffset);
    MEMBER(float, HorMoveRotationAds);
    MEMBER(float, HorMovePosOffsetAds);
    MEMBER(float, ForwardMoveOffsetAds);

    MEMBER(AnimationCurve, VerticalLiftCurve);
    MEMBER(Vector3D, RecoilKick);
    MEMBER(Vector3D, RecoilKickAds);
    MEMBER(float, RecoilKickBackLerpSpeed);
    MEMBER(float, RecoilKickHorLerpSpeed);
    MEMBER(Vector3D, RecoilRotationAds);
    MEMBER(float, RecoilRotationLerpSpeed);
};

class WeaponInfo
{
public:
    CLASS("CombatMaster.GDI", "WeaponInfo");

    MEMBER(AnimationCurve*, Damage);
    MEMBER(float, DamageHeadMultiplier);
    MEMBER(int, BashDamage);
    MEMBER(int, BashRange);
    MEMBER(int, BashRPM);
    MEMBER(int, AmmoAmount);

    MEMBER(float, AdsLerpSpeed);
    MEMBER(float, AdsEnterAnimTime);
    MEMBER(float, AdsEnterMultiplier);
    MEMBER(float, AdsExitAnimTime);
    MEMBER(float, AdsExitMultiplier);

    MEMBER(float, MovementSpeedMultiplier);
    MEMBER(float, MovementAdsSpeedMultiplier);
    MEMBER(WeaponSwaySettings, SwaySettings);

    bool GetIsShootingWeapon()
    {
        METHOD(bool(**)(WeaponInfo*), get_IsShootingWeapon);
        return get_IsShootingWeapon(this);
    }

    bool GetIsKnife()
    {
        METHOD(bool(**)(WeaponInfo*), get_IsKnife);
        return get_IsKnife(this);
    }

    bool GetIsMeleeWeapon()
    {
        METHOD(bool(**)(WeaponInfo*), get_IsMeleeWeapon);
        return get_IsMeleeWeapon(this);
    }

    bool GetIsExplosive()
    {
        METHOD(bool(**)(WeaponInfo*), get_IsExplosive);
        return get_IsExplosive(this);
    }

    BYTE GetMaxLevel()
    {
        METHOD(BYTE(**)(WeaponInfo*), get_MaxLevel);
        return get_MaxLevel(this);
    }

    int GetDefaultMagCapacity()
    {
        METHOD(int(**)(WeaponInfo*), get_DefaultMagCapacity);
        return get_DefaultMagCapacity(this);
    }

    bool GetIsShooting()
    {
        METHOD(bool(**)(WeaponInfo*), get_IsShootingWeapon);
        return get_IsShootingWeapon(this);
    }
};

class WeaponBase
{
public:
    CLASS("CombatMaster.View.Battle", "WeaponBase");

    WeaponInfo* GetWeaponInfo()
    {
        METHOD(WeaponInfo*(**)(WeaponBase*), get_Info);
        return get_Info(this);
    }

    int GetChargedAmmo()
    {
        METHOD(int(**)(WeaponBase*), get_ChargedAmmoLeft);
        return get_ChargedAmmoLeft(this);
    }

    int GetUnchargedAmmo()
    {
        METHOD(int(**)(WeaponBase*), get_UnChargedAmmoLeft);
        return get_UnChargedAmmoLeft(this);
    }

    bool GetIsReloading()
    {
        METHOD(bool(**)(WeaponBase*), get_IsReloading);
        return get_IsReloading(this);
    }

    WeaponView* GetWeaponView()
    {
        METHOD(WeaponView*(**)(WeaponBase*), get_WeaponView);
        return get_WeaponView(this);
    }
};

class PlayerArming
{
public:
    CLASS("CombatMaster.Battle.Gameplay.Player", "PlayerArming");
    static inline void(*oEvent)(PlayerArming*, WeaponShootEntityEvent) = nullptr;

    WeaponBase* GetMainSlotsActiveWeapon()
    {
        METHOD(WeaponBase*(**)(PlayerArming*), get_MainSlotsActiveWeapo);
        return get_MainSlotsActiveWeapo(this);
    }

    WeaponBase* GetActiveWeapon()
    {
        METHOD(WeaponBase*(**)(PlayerArming*), get_ActiveWeapon);
        return get_ActiveWeapon(this);
    }

    float GetPlantOrDefuseBombTimer()
    {
        METHOD(float(**)(PlayerArming*), get_PlantOrDefuseBombTimer);
        return get_PlantOrDefuseBombTimer(this);
    }

    bool GetIsBombPlantingOrDefusing()
    {
        METHOD(bool(**)(PlayerArming*), get_IsBombPlantingOrDefusing);
        return get_IsBombPlantingOrDefusing(this);
    }

    void ExecuteCommand(Command cmd, bool unkBool)
    {
        METHOD(void(**)(PlayerArming*, Command, bool), ExecuteCommand);
        ExecuteCommand(this, cmd, unkBool);
    }

    bool GetIsAds()
    {
        METHOD(bool(**)(PlayerArming*), get_IsAds);
        return get_IsAds(this);
    }

    int GetArmorCount()
    {
        METHOD(int(**)(PlayerArming*), get_ArmorCount);
        return get_ArmorCount(this);
    }

    bool GetIsReloading()
    {
        METHOD(bool(**)(PlayerArming*), get_IsReloading);
        return get_IsReloading(this);
    }

    void SimulateInput(IPlayerCommandInput input)
    {
        METHOD(void(**)(PlayerArming*, IPlayerCommandInput), SimulateInput);
        SimulateInput(this, input);
    }

    void OnEvent(WeaponShootEntityEvent event)
    {
        METHOD(void(**)(PlayerArming*, WeaponShootEntityEvent), OnEvent);
        OnEvent(this, event);
    }
};

class Bullet
{
public:
    CLASS("CombatMaster.Battle.Gameplay", "Bullet");
    static inline void(*oUpdate)(Bullet*) = nullptr;

    MEMBER(float, _speed);
};

class ShootUseTypeInfoExt
{
public:
    CLASS("CombatMaster.GDI", "ShootUseTypeInfoExt");
};

class ShootingWeaponView : public WeaponView
{
public:
    CLASS("CombatMaster.Battle.Gameplay.Weapon", "ShootingWeaponView");

    MEMBER(UnityEngine::Transform, _firePoint);
};

class ShootWeapon : public WeaponBase
{
public:
    CLASS("CombatMaster.View.Battle", "ShootWeapon");
    static inline void(*oUpdate)(ShootWeapon*) = nullptr;

    ShootUseTypeInfoExt* GetShootUseInfo()
    {
        METHOD(ShootUseTypeInfoExt*(**)(ShootWeapon*), get_UseInfoExt);
        return get_UseInfoExt(this);
    }

    ShootingWeaponView* GetWeaponView()
    {
        METHOD(ShootingWeaponView * (**)(ShootWeapon*), get_WeaponView);
        return get_WeaponView(this);
    }
};

struct DeltaProp
{
public:
    CLASS("Flexy.Binding", "DeltaProp");

    MEMBER(float, CurValue);
    MEMBER(float, GlobalMaximum);
    MEMBER(float, DefaultValue);
    MEMBER(float, Delta);
    MEMBER(float, MaxValue);
    MEMBER(bool, RevertDeltas);
    MEMBER(float, NewValue);

    float GetNewValue()
    {
        METHOD(float(**)(DeltaProp*), get_NewValue);
        return get_NewValue(this);
    }

    void SetNewValue(float value)
    {
        METHOD(float*(**)(DeltaProp*, float), set_NewValue);
        set_NewValue(this, value);
    }
};

class WeaponStatsViewModel
{
public:
    CLASS("CombatMaster.View.UI.ViewModels", "WeaponStatsViewModel");

    MEMBER(DeltaProp, Damage);
    MEMBER(DeltaProp, FireRate);
    MEMBER(DeltaProp, Spread);
    MEMBER(DeltaProp, Range);
    MEMBER(DeltaProp, Control);
    MEMBER(DeltaProp, Mobility);
};

//@TODO

//// Namespace: CombatMaster.GDI
//public class WeaponsGdInfoSection : GdInfoSection, IDynamicSource // TypeDefIndex: 1620
//{
//    // Fields
//    public float CamoGrindMultiplier; // 0x28
//    public float DetailColorGrindMultiplier; // 0x2C
//    [Header("Constants")]
//    public float DamageGlobalMaximum; // 0x30
//    public float RPMGlobalMaximum; // 0x34
//    public float SpreadGlobalMaximum; // 0x38
//    public float RangeGlobalMaximum; // 0x3C
//    public float MobilityGlobalMaximum; // 0x40
//    public float ControlGlobalMaximum; // 0x44
//    public ushort AttachmentsMaximum; // 0x48
//    public float LongShotDistance; // 0x4C
//    [Header("Recoil")]
//    public float RecoilKickPowerDuration; // 0x50
//    public Ease RecoilKickPowerDumpEase; // 0x54
//    public float RecoilRisingSpeed; // 0x58
//    public float RecoilDumpingSpeed; // 0x5C
//    [Header("Sway")]
//    public float RotationToSwayAngleCoefficient; // 0x60
//    public ItemWithChance<WeaponDropRandomizer> PrimaryWeaponForBots; // 0x68
//    public ItemWithChance<WeaponDropRandomizer> SecondaryWeaponForBots; // 0x90
//    public ItemWithChance<WeaponDropRandomizer> LethalWeaponForBots; // 0xB8
//    public EntityType FistsWeaponId; // 0xE0
//    public EntityType ParachuteWeaponId; // 0xE4
//    public EntityType ArmorPlateWeaponId; // 0xE8
//    public EntityType SndBombWeaponId; // 0xEC
//    public EntityType MinigunId; // 0xF0

class MakeDamageGlobalEvent
{
public:
    CLASS("Photon.Bolt", "MakeDamageGlobalEvent");
    static inline void(*oSetDamage)(Bullet*) = nullptr;
    //@TODO: hook SetDamage and override dmg amount

    MEMBER(int, Damage);
};