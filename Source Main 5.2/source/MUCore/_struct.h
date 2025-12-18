#ifndef ___STRUCT_H__
#define ___STRUCT_H__

#pragma once

#include <cstdint>
#include <vector>

#include "_define.h"
#include "w_Buff.h"

#include "w_ObjectInfo.h"
class OBJECT;
#include "w_CharacterInfo.h"
class CHARACTER;

namespace SEASON3B
{
    class CNewUIItemMng;
}

#define MAX_MONSTERSKILL_NUM	10

namespace info
{
    struct Script_Item
    {
        wchar_t Name[30];
        bool TwoHand;
        std::uint16_t Level;
        std::uint8_t m_byItemSlot;
        std::uint8_t m_bySkillIndex;
        std::uint8_t Width;
        std::uint8_t Height;
        std::uint8_t DamageMin;
        std::uint8_t DamageMax;
        std::uint8_t SuccessfulBlocking;
        std::uint8_t Defense;
        std::uint8_t MagicDefense;
        std::uint8_t WeaponSpeed;
        std::uint8_t WalkSpeed;
        std::uint8_t Durability;
        std::uint8_t MagicDur;
        std::uint8_t MagicPower;
        std::uint16_t RequireStrength;
        std::uint16_t RequireDexterity;
        std::uint16_t RequireEnergy;
        std::uint16_t RequireVitality;
        std::uint16_t RequireCharisma;
        std::uint16_t RequireLevel;
        std::uint8_t Value;
        int  iZen;
        std::uint8_t  AttType;
        std::uint8_t RequireClass[MAX_CLASS];
        std::uint8_t Resistance[MAX_RESISTANCE];
    };

    struct Script_Silde
    {
        typedef std::vector<wchar_t*>     SildeVECTOR;
        SildeVECTOR					   Sildelist;
    };

    struct Script_Dialog
    {
        wchar_t m_lpszText[MAX_LENGTH_DIALOG];
        int m_iNumAnswer;
        int m_iLinkForAnswer[MAX_ANSWER_FOR_DIALOG];
        int m_iReturnForAnswer[MAX_ANSWER_FOR_DIALOG];
        wchar_t m_lpszAnswer[MAX_ANSWER_FOR_DIALOG][MAX_LENGTH_ANSWER];
    };

    struct Script_Credit
    {
        std::uint8_t	byClass;
        wchar_t	szName[32];
    };

    struct Script_Movereq
    {
        int index;
        wchar_t szMainMapName[32];
        wchar_t szSubMapName[32];
        int	iReqLevel;
        int iReqZen;
        int iGateNum;
    };

    struct Script_Quest_Class_Act
    {
        std::uint8_t    chLive;
        std::uint8_t    byQuestType;
        std::uint16_t    wItemType;
        std::uint8_t    byItemSubType;
        std::uint8_t	byItemLevel;
        std::uint8_t    byItemNum;
        std::uint8_t    byRequestType;
        std::uint8_t    byRequestClass[MAX_CLASS];
        short   shQuestStartText[4];
    };

    struct Script_Quest_Class_Request
    {
        std::uint8_t    byLive;
        std::uint8_t    byType;
        std::uint16_t    wCompleteQuestIndex;
        std::uint16_t    wLevelMin;
        std::uint16_t    wLevelMax;
        std::uint16_t	wRequestStrength;
        std::uint32_t   dwZen;
        short   shErrorText;
    };

    struct Script_Quest
    {
        short   shQuestConditionNum;
        short   shQuestRequestNum;
        std::uint16_t    wNpcType;
        char    strQuestName[32];

        Script_Quest_Class_Act     QuestAct[MAX_QUEST_CONDITION];
        Script_Quest_Class_Request QuestRequest[MAX_QUEST_REQUEST];
    };
};

//infomation start
typedef struct
{
    std::uint8_t Flag;
    std::uint8_t Map;
    std::uint8_t x1;
    std::uint8_t y1;
    std::uint8_t x2;
    std::uint8_t y2;
    std::uint16_t Target;
    std::uint8_t Angle;
    std::uint16_t Level;
    std::uint16_t m_wMaxLevel;
} GATE_ATTRIBUTE;

typedef struct
{
    char m_lpszText[MAX_LENGTH_DIALOG];
    int m_iNumAnswer;
    int m_iLinkForAnswer[MAX_ANSWER_FOR_DIALOG];
    int m_iReturnForAnswer[MAX_ANSWER_FOR_DIALOG];
    char m_lpszAnswer[MAX_ANSWER_FOR_DIALOG][MAX_LENGTH_ANSWER];
} DIALOG_SCRIPT;//Script_Dialog

typedef struct
{
    char Name[MAX_ITEM_NAME];
    bool TwoHand;
    std::uint16_t Level;
    std::uint8_t m_byItemSlot;
    std::uint16_t m_wSkillIndex;
    std::uint8_t Width;
    std::uint8_t Height;
    std::uint8_t DamageMin;
    std::uint8_t DamageMax;
    std::uint8_t SuccessfulBlocking;
    std::uint8_t Defense;
    std::uint8_t MagicDefense;
    std::uint8_t WeaponSpeed;
    std::uint8_t WalkSpeed;
    std::uint8_t Durability;
    std::uint8_t MagicDur;
    std::uint8_t MagicPower;
    std::uint16_t RequireStrength;
    std::uint16_t RequireDexterity;
    std::uint16_t RequireEnergy;
    std::uint16_t RequireVitality;
    std::uint16_t RequireCharisma;
    std::uint16_t RequireLevel;
    std::uint8_t Value;
    int  iZen;
    std::uint8_t  AttType;
    std::uint8_t RequireClass[MAX_CLASS];
    std::uint8_t Resistance[MAX_RESISTANCE + 1];
} ITEM_ATTRIBUTE_FILE;

typedef struct
{
    wchar_t Name[MAX_ITEM_NAME];
    bool TwoHand;
    std::uint16_t Level;
    std::uint8_t m_byItemSlot;
    std::uint16_t m_wSkillIndex;
    std::uint8_t Width;
    std::uint8_t Height;
    std::uint8_t DamageMin;
    std::uint8_t DamageMax;
    std::uint8_t SuccessfulBlocking;
    std::uint8_t Defense;
    std::uint8_t MagicDefense;
    std::uint8_t WeaponSpeed;
    std::uint8_t WalkSpeed;
    std::uint8_t Durability;
    std::uint8_t MagicDur;
    std::uint8_t MagicPower;
    std::uint16_t RequireStrength;
    std::uint16_t RequireDexterity;
    std::uint16_t RequireEnergy;
    std::uint16_t RequireVitality;
    std::uint16_t RequireCharisma;
    std::uint16_t RequireLevel;
    std::uint8_t Value;
    int  iZen;
    std::uint8_t  AttType;
    std::uint8_t RequireClass[MAX_CLASS];
    std::uint8_t Resistance[MAX_RESISTANCE + 1];
} ITEM_ATTRIBUTE;

typedef struct _MASTER_LEVEL_DATA
{
    std::uint8_t Width;
    int Ability[8][4];
}MASTER_LEVEL_DATA;

typedef struct
{
    std::uint8_t Kind;
    int	 Location[2];
    int  Rotation;
    char Name[MAX_MINIMAP_NAME];
}MINI_MAP_FILE;

typedef struct
{
    std::uint8_t Kind;
    int	 Location[2];
    int  Rotation;
    wchar_t Name[MAX_MINIMAP_NAME];
} MINI_MAP;

#pragma pack(push, 1)
typedef struct tagITEM
{
    short Type;
    int   Level;
    std::uint8_t  Durability;
    std::uint8_t OptionLevel;
    std::uint8_t OptionType;
    std::uint8_t ExcellentFlags;
    std::uint8_t AncientDiscriminator; // 0 = no ancient;
    std::uint8_t AncientBonusOption;
    std::uint16_t  Jewel_Of_Harmony_Option;
    std::uint16_t  Jewel_Of_Harmony_OptionLevel;
    bool HasSkill;
    bool HasLuck;
    std::uint8_t  Part;
    std::uint8_t  Class;
    bool  TwoHand;
    std::uint16_t  DamageMin;
    std::uint16_t  DamageMax;
    std::uint8_t  SuccessfulBlocking;
    std::uint16_t  Defense;
    std::uint16_t  MagicDefense;
    std::uint8_t  MagicPower;
    std::uint8_t  WeaponSpeed;
    std::uint16_t  WalkSpeed;

    std::uint16_t  RequireStrength;
    std::uint16_t  RequireDexterity;
    std::uint16_t  RequireEnergy;
    std::uint16_t  RequireVitality;
    std::uint16_t  RequireCharisma;
    std::uint16_t  RequireLevel;
    std::uint8_t  SpecialNum;
    std::uint16_t  Special[MAX_ITEM_SPECIAL];
    std::uint8_t  SpecialValue[MAX_ITEM_SPECIAL];
    std::uint32_t Key;	//client olny

    std::uint8_t bySelectedSlotIndex;

    union
    {
        std::uint8_t  x;    //client olny
        std::uint8_t  lineal_pos;
    };
    union
    {
        std::uint8_t  y;    //client olny
        std::uint8_t  ex_src_type;
    };
    bool option_380;

    std::uint8_t SocketCount;
    std::uint8_t bySocketOption[MAX_SOCKETS];
    std::uint8_t SocketSeedID[MAX_SOCKETS];
    std::uint8_t SocketSphereLv[MAX_SOCKETS];
    std::uint8_t SocketSeedSetOption;

    int   Number;
    std::uint8_t  Color;

    std::uint8_t byColorState;

    bool	bPeriodItem;
    bool	bExpiredPeriod;
    long	lExpireTime;

private:
    friend class SEASON3B::CNewUIItemMng;
    int   RefCount;
} ITEM;
#pragma pack(pop)

typedef struct
{
    std::uint16_t Life;
    std::uint16_t MoveSpeed;
    std::uint16_t AttackSpeed;
    std::uint16_t AttackDamageMin;
    std::uint16_t AttackDamageMax;
    std::uint16_t Defense;
    std::uint16_t MagicDefense;
    std::uint16_t AttackRating;
    std::uint16_t SuccessfulBlocking;
} MONSTER_ATTRIBUTE;

typedef struct
{
    std::uint16_t				Type;
    wchar_t				Name[MAX_MONSTER_NAME];
    std::uint16_t				Level;
    MONSTER_ATTRIBUTE	Attribute;
} MONSTER_SCRIPT;

typedef struct
{
    short             Type;
    std::uint8_t              Level;
    int               Experince;
    MONSTER_ATTRIBUTE Attribute;
} MONSTER;

typedef struct
{
    /*+00*/	char Name[MAX_SKILL_NAME];
    /*+32*/	std::uint16_t Level;
    /*+34*/	std::uint16_t Damage;
    /*+36*/	std::uint16_t Mana;
    /*+38*/	std::uint16_t AbilityGuage;
    /*+40*/	std::uint32_t Distance;
    /*+44*/	int Delay;
    /*+48*/	int Energy;
    /*+52*/	std::uint16_t Charisma;
    /*+54*/	std::uint8_t MasteryType;
    /*+55*/	std::uint8_t SkillUseType;
    /*+56*/	std::uint32_t SkillBrand;
    /*+60*/	std::uint8_t KillCount;
    /*+61*/	std::uint8_t RequireDutyClass[MAX_DUTY_CLASS];
    /*+64*/	std::uint8_t RequireClass[MAX_CLASS];
    /*+71*/	std::uint8_t SkillRank;
    /*+72*/	std::uint16_t Magic_Icon;
    /*+74*/	std::uint8_t TypeSkill;
    /*+76*/	int Strength;
    /*+80*/	int Dexterity;
    /*+84*/	std::uint8_t ItemSkill;
    /*+85*/	std::uint8_t IsDamage;
    /*+86*/	std::uint16_t Effect;
} SKILL_ATTRIBUTE_FILE;

typedef struct
{
    wchar_t Name[MAX_SKILL_NAME];
    std::uint16_t Level;
    std::uint16_t Damage;
    std::uint16_t Mana;
    std::uint16_t AbilityGuage;
    std::uint32_t Distance;
    int Delay;
    int Energy;
    std::uint16_t Charisma;
    std::uint8_t MasteryType;
    std::uint8_t SkillUseType;
    std::uint32_t SkillBrand;
    std::uint8_t KillCount;
    std::uint8_t RequireDutyClass[MAX_DUTY_CLASS];
    std::uint8_t RequireClass[MAX_CLASS];
    std::uint8_t SkillRank;
    std::uint16_t Magic_Icon;
    std::uint8_t TypeSkill;
    int Strength;
    int Dexterity;
    std::uint8_t ItemSkill;
    std::uint8_t IsDamage;
    std::uint16_t Effect;
} SKILL_ATTRIBUTE;
/*
typedef struct
{
    wchar_t Name[32];
    std::uint8_t Level;
    std::uint16_t Damage;
    std::uint16_t Mana;
    std::uint16_t AbilityGuage;
    std::uint8_t Distance;
    int  Delay;

    int Energy;

    std::uint16_t Charisma;
    std::uint8_t MasteryType;
    std::uint8_t SkillUseType;
    std::uint8_t SkillBrand;
    std::uint8_t KillCount;
    std::uint8_t RequireDutyClass[MAX_DUTY_CLASS];
    std::uint8_t RequireClass[MAX_CLASS];
    std::uint16_t Magic_Icon;

    std::uint8_t TypeSkill;

    int Strength;
    int Dexterity;
} SKILL_ATTRIBUTE;
*/

typedef struct
{
    std::uint16_t Strength;
    std::uint16_t Dexterity;
    std::uint16_t Vitality;
    std::uint16_t Energy;
    std::uint16_t Life;
    std::uint16_t Mana;
    std::uint16_t Shield;
    std::uint8_t LevelLife;
    std::uint8_t LevelMana;
    std::uint8_t VitalityToLife;
    std::uint8_t EnergyToMana;
    std::uint8_t ClassSkill[MAX_SKILLS];
} CLASS_ATTRIBUTE;

class CSkillTreeInfo
{
public:
    CSkillTreeInfo()
    {
        this->skillLevel = 0;
        this->skillValue = 0.0f;
        this->skillNextValue = 0.0f;
    }

    CSkillTreeInfo(std::uint8_t point, float value, float nextValue)
    {
        this->skillLevel = point;
        this->skillValue = value;
        this->skillNextValue = nextValue;
    }

    ~CSkillTreeInfo() = default;

    std::uint8_t GetSkillLevel() const { return this->skillLevel; }
    float GetSkillValue() const { return this->skillValue; }
    float GetSkillNextValue() const { return this->skillNextValue; }
private:
    std::uint8_t skillLevel;
    float skillValue;
    float skillNextValue;
};

typedef struct
{
    wchar_t Name[MAX_ID_SIZE + 1];
    CLASS_TYPE Class;
    std::uint8_t Skin;
    std::uint8_t InventoryExtensions;
    std::uint8_t IsVaultExtended;
    std::uint16_t Level;

    std::uint16_t Strength;
    std::uint16_t Dexterity;
    std::uint16_t Vitality;
    std::uint16_t Energy;
    std::uint16_t Charisma;
    std::uint32_t Life;
    std::uint32_t Mana;
    std::uint32_t LifeMax;
    std::uint32_t ManaMax;
    std::uint32_t Shield;
    std::uint32_t ShieldMax;
    std::uint32_t SkillMana;
    std::uint32_t SkillManaMax;
    std::uint16_t AttackRatingPK;
    std::uint16_t SuccessfulBlockingPK;
    std::uint16_t AddStrength;
    std::uint16_t AddDexterity;
    std::uint16_t AddVitality;
    std::uint16_t AddEnergy;
    std::uint16_t AddLifeMax;
    std::uint16_t AddManaMax;
    std::uint16_t AddCharisma;
    std::uint8_t Ability;
    float AbilityTime[3]; // Number of reference frames

    short AddPoint;
    short MaxAddPoint;
    std::uint16_t wMinusPoint;
    std::uint16_t wMaxMinusPoint;
    std::uint16_t AttackSpeed;
    std::uint16_t MaxAttackSpeed; // Maximum attack speed which can be reached on the server.
    std::uint16_t AttackRating;
    std::uint16_t AttackDamageMinRight;
    std::uint16_t AttackDamageMaxRight;
    std::uint16_t AttackDamageMinLeft;
    std::uint16_t AttackDamageMaxLeft;
    std::uint16_t MagicSpeed;
    std::uint16_t MagicDamageMin;
    std::uint16_t MagicDamageMax;
    std::uint16_t CurseDamageMin;
    std::uint16_t CurseDamageMax;
    std::uint16_t CriticalDamage;
    std::uint16_t SuccessfulBlocking;
    std::uint16_t Defense;
    std::uint16_t MagicDefense;
    std::uint16_t WalkSpeed;
    std::uint16_t LevelUpPoint;
    std::uint8_t SkillNumber;
    std::uint8_t SkillMasterNumber;

    uint64_t Experience;
    uint64_t NextExperience;

    ActionSkillType Skill[MAX_SKILLS];
    int  SkillDelay[MAX_SKILLS];
    std::uint8_t SkillLevel[MAX_SKILLS]; // Do we even need this array when we have the map of CSkillTreeInfo?

    CSkillTreeInfo MasterSkillInfo[AT_SKILL_MASTER_END + 1]; // Index = ActionSkillType
    
} CHARACTER_ATTRIBUTE;

typedef struct _MASTER_LEVEL_VALUE
{
    short		 nMLevel;
    __int64		 lMasterLevel_Experince;
    __int64		 lNext_MasterLevel_Experince;

    short		nAddMPoint;
    short      	nMLevelUpMPoint;
    short		nTotalMPoint;
    short		nMaxPoint;
    std::uint32_t		wMaxLife;
    std::uint32_t		wMaxMana;
    std::uint32_t		wMaxShield;
    std::uint32_t		wMaxBP;
} MASTER_LEVEL_VALUE;

//infomation end

typedef struct _OBJECT_BLOCK
{
    unsigned char Index;
    OBJECT* Head;
    OBJECT* Tail;
    bool          Visible;

    _OBJECT_BLOCK()
    {
        Index = 0;
        Head = NULL;
        Tail = NULL;
        Visible = false;
    }
} OBJECT_BLOCK;

typedef struct
{
    bool   Live;
    int    Type;
    int    TexType;
    int    SubType;
    float  Scale;
    vec3_t Position;
    vec3_t Angle;
    vec3_t Light;
    float  Alpha;
    float  LifeTime;
    OBJECT* Target;
    float  Rotation;
    int    Frame;

    bool   bEnableMove;
    float  Gravity;
    vec3_t Velocity;
    vec3_t TurningForce;
    vec3_t StartPosition;
    int iNumBone;
    bool bRepeatedly;
    float fRepeatedlyHeight;
} PARTICLE;

typedef struct
{
    bool	 Live;
    int	     Type;
    OBJECT* Owner;
} OPERATE;

typedef struct
{
    short  Key;
    ITEM   Item;
    OBJECT Object;
} ITEM_t;

//object end

typedef struct Script_Skill
{
    int Skill_Num[MAX_MONSTERSKILL_NUM];
    int Slot;
} Script_Skill;

typedef struct
{
    bool		Live;
    int			Type;
    int         TexType;
    int			SubType;
    std::uint8_t        RenderType;
    std::uint8_t        RenderFace;
    float		Scale;
    vec3_t		Position;
    vec3_t      StartPosition;
    vec3_t		Angle;
    vec3_t		HeadAngle;
    vec3_t		Light;
    OBJECT* Target;
    vec3_t      TargetPosition;
    std::uint8_t        byOnlyOneRender;
    float  		LifeTime;
    bool        Collision;
    float		Velocity;
    vec3_t		Direction;
    short       PKKey;
    std::uint16_t		Skill;
    float		Weapon;
    float		MultiUse;
    bool        bTileMapping;
    std::uint8_t        m_byReverseUV;
    int			TargetIndex[5];
    std::uint8_t		m_bySkillSerialNum;
    int			m_iChaIndex;
    short int	m_sTargetIndex;

    // Fields about the "Tails" of effects:
    bool        m_bCreateTails; // Flag, if tails are created.
    int         NumTails; // The number of currently used tail entries. Usually this gets increased by one in every frame until the maximum is reached.
    int         MaxTails; // The maximum number of tail entries to use.
    vec3_t      Tails[MAX_TAILS][4]; // The tail entries, which are getting moved back by one in every frame.
} JOINT;
//character end

//inventory start
typedef struct
{
    wchar_t Name[MAX_ID_SIZE + 1];
    std::uint8_t Number;
    std::uint8_t Server;
    std::uint8_t GuildStatus;
} GUILD_LIST_t;

typedef struct
{
    int  Key;
    wchar_t UnionName[8 + 1];
    wchar_t GuildName[8 + 1];
    std::uint8_t Mark[64];
} MARK_t;

typedef struct
{
    wchar_t    Name[MAX_ID_SIZE + 1];
    std::uint8_t    Number;
    std::uint8_t    Map;
    std::uint8_t    x;
    std::uint8_t    y;
    int     currHP;
    int     maxHP;
    std::uint8_t    stepHP;
    int     index;
} PARTY_t;
//inventory end

//interface start
typedef struct
{
    wchar_t      ID[MAX_ID_SIZE + 1];
    wchar_t      Text[256];
    int       Type;
    int       LifeTime;
    int       Width;
} WHISPER;

typedef struct
{
    bool m_bMagic;
    int m_iSkill; // When m_bMagic is true, it's the skill index, otherwise it's already the ActionSkillType. TODO: check all usages, refactor. This could be buggy as hell.
    int m_iTarget;
} MovementSkill;
//interface end

//matchevent start
typedef struct
{
    wchar_t	m_lpID[MAX_ID_SIZE];
    int		m_iScore;
    std::uint32_t	m_dwExp;
    int		m_iZen;
} DevilSquareRank;
//matchevent end

//gmhellas start
typedef struct
{
    wchar_t    m_strName[64];
    vec3_t  m_vPos;
}ObjectDescript;
//gmhellas end

//csquest start
typedef struct
{
    std::uint8_t    chLive;
    std::uint8_t    byQuestType;
    std::uint16_t    wItemType;
    std::uint8_t    byItemSubType;
    std::uint8_t	byItemLevel;
    std::uint8_t    byItemNum;
    std::uint8_t    byRequestType;
    std::uint8_t    byRequestClass[MAX_CLASS];
    short   shQuestStartText[4];
} QUEST_CLASS_ACT;

typedef struct
{
    std::uint8_t    byLive;
    std::uint8_t    byType;
    std::uint16_t    wCompleteQuestIndex;
    std::uint16_t    wLevelMin;
    std::uint16_t    wLevelMax;
    std::uint16_t	wRequestStrength;
    std::uint32_t   dwZen;
    short   shErrorText;
} QUEST_CLASS_REQUEST;

typedef struct
{
    short   shQuestConditionNum;
    short   shQuestRequestNum;
    std::uint16_t	wNpcType;

    wchar_t strQuestName[32];

    QUEST_CLASS_ACT     QuestAct[MAX_QUEST_CONDITION];
    QUEST_CLASS_REQUEST QuestRequest[MAX_QUEST_REQUEST];
} QUEST_ATTRIBUTE;

typedef struct
{
    std::uint8_t    byFlag;
    std::uint8_t    byCount;
} QUEST_FLAG_BUFFER;

typedef struct
{
    int iCrastGold;
    int iCrastSilver;
    int iCrastBronze;
} QUEST_CRAST;
//csquest end

//csmapinterface start
typedef struct
{
    std::uint8_t    bIndex;
    std::uint8_t    x;
    std::uint8_t    y;
}VisibleUnitLocation;

typedef struct
{
    std::uint8_t    byTeam;
    std::uint8_t    byX;
    std::uint8_t    byY;
    std::uint8_t    byCmd;
    std::uint8_t    byLifeTime;
}GuildCommander;
//csmapinterface end

//cseventmatch start
typedef struct
{
    std::uint8_t	m_lpID[MAX_ID_SIZE];
    std::uint32_t	m_iScore;
    std::uint32_t	m_dwExp;
    std::uint32_t	m_iZen;
}MatchResult;
//cseventmatch end

//cdirection start
struct DirectionMonster
{
    int		m_Index;
    int		m_iActionCheck;
    bool	m_bAngleCheck;
};
//cdirection end

#endif ___STRUCT_H__
