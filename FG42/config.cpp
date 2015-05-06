#define private 0
#define protected   1
#define public  2

#define true    1
#define false   0

#define TEast   0
#define TWest   1
#define TGuerrila   2
#define TCivilian   3
#define TSideUnknown    4
#define TEnemy  5
#define TFriendly   6
#define TLogic  7


class CfgPatches 
{
         class SR_RF_FG42 
         {
                author[] = {"Sacher"};
                requiredaddons[] = {"A3_Weapons_F"};
                requiredversion = "0,1";
                units[] = {};
                weapons[] = {"SR_RF_FG42"};
                magazines[] = {"SR_20RND_FG42"};
         };
};
/*external*/ class Mode_FullAuto;
/*external*/ class Mode_SemiAuto;
/*external*/ class ItemCore;
 
class CfgWeapons 
{
    /*external*/ class EBR_base_F;
    class FG42_BASE :  EBR_base_F
    {
        /*extern*/ class Single;
        /*extern*/ class WeaponSlotsInfo;
        /*extern*/ class FullAuto;
        /*extern*/ class Gunparticles;
    };
    class SR_RF_FG42_base : FG42_BASE
    {
        author = "Sacher";     
        handanim[] = {"OFP2_ManSkeleton", "\A3\Weapons_F\LongRangeRifles\EBR\Data\Anim\ebr.rtm"};
        model =  "\FG42\FG42.p3d";
        dexterity = 1.68;
        initSpeed = -1;
        discretedistance[] = {200, 300, 400, 500, 600, 700, 800};
        discretedistanceinitindex = 1;
        descriptionshort = "Fallschirmjäger Gewehr 42<br />Caliber: 7.92x57mm";
        magazines[] = {"SR_20RND_FG42"};
        displayname = "Fallschirmjaeger Gewehr 42";
        displaynameshort = "FG42";
        modes[] = {"FullAuto","Single", "close", "short", "medium"};
        reloadaction = "GestureReloadM200";
        scope = 0;
        picture = "\FG42\ui\gear_SR_RF_FG42_x_ca.paa";
        uipicture = "\A3\weapons_f\data\UI\icon_regular_CA.paa";
        reloadmagazinesound[] = {"\FG42\Sound\FG42_reload_1p.wav", db, 1, 30};
        reloadtime = 0.3;
        class FullAuto: Mode_FullAuto 
        {
            sounds[] = {"StandardSound"};
            class BaseSoundModeType
            {
                weaponSoundEffect = "DefaultRifle";
            };
            class StandardSound: BaseSoundModeType
            {
                begin1[] = {"\FG42\Sound\FG42_1p_out.wav", db+1, 1, 1200};
                soundBegin[] = {"begin1",0.33};
            }; 
            reloadTime = 0.080000;
            recoil = "recoil_single_ebr";
            recoilProne = "recoil_single_prone_ebr";
            soundcontinuous = 0;
            soundburst = 0;
            dispersion = 0.00100;
            maxrange = 30;
            maxrangeprobab = 0.1;
            midrange = 15;
            midrangeprobab = 0.7;
            minrange = 0;
            minrangeprobab = 0.9;
            aiRateOfFire = 0,005;
            showtoplayer = 1;
        };
        class Single: Mode_SemiAuto 
        {
            sounds[] = {"StandardSound"};
            class BaseSoundModeType
            {
                weaponSoundEffect = "DefaultRifle";
            };
            class StandardSound: BaseSoundModeType
            {
                begin1[] = {"\FG42\Sound\FG42_1p_out.wav", db+1, 1, 1200};
                soundBegin[] = {"begin1",0.33};
            }; 
            reloadTime = 0.060000;
            recoil = "recoil_single_trg"
            recoilProne = "recoil_single_prone_trg"
            soundcontinuous = 0;
            soundburst = 0;
            dispersion = 0.00100;
            maxrange = 30;
            maxrangeprobab = 0.1;
            midrange = 15;
            midrangeprobab = 0.7;
            minrange = 0;
            minrangeprobab = 0.9;
            aiRateOfFire = 0,006;
            showtoplayer = 1;
        };
        class close: FullAuto 
        {
            airateoffire = 0.06;
            airateoffiredistance = 50;
            burst = 5;
            maxrange = 50;
            maxrangeprobab = 0.04;
            midrange = 30;
            midrangeprobab = 0.7;
            minrange = 0;
            minrangeprobab = 0.05;
            showtoplayer = 0;
        };
        class short: close 
        {
            airateoffire = 0.1;
            airateoffiredistance = 300;
            burst = 3;
            maxrange = 300;
            maxrangeprobab = 0.04;
            midrange = 150;
            midrangeprobab = 0.7;
            minrange = 50;
            minrangeprobab = 0.05;
        };
        class medium: close 
        {
            airateoffire = 0.5;
            airateoffiredistance = 1000;
            burst = 5;
            maxrange = 600;
            maxrangeprobab = 0.1;
            midrange = 400;
            midrangeprobab = 0.6;
            minrange = 200;
            minrangeprobab = 0.05;
        };
        class Library 
        {
                libtextdesc = "FG42 was used by the Paratroopers of the Wehrmacht.";
        };
        class WeaponSlotsInfo
        {
            mass = 90;
        };
        class GunParticles 
        {
            class FirstEffect 
            {
                directionname = "Konec hlavne";
                effectname = "RifleAssaultCloud";
                positionname = "Usti hlavne";
            };
        };
    }; 
    class SR_RF_FG42 : SR_RF_FG42_base 
    {
        scope = 2;
        displayName = "FG42";
    };    
};
class CfgMagazines 
{
        /*extern*/ class CA_Magazine;
        class SR_20RND_FG42: CA_Magazine 
        {
                ammo = "B_762x51_Ball";
                count = 20;
                descriptionshort = "Caliber: 7.92x57mm<br/>Rounds: 20 <br/>Used in: FG42";
                initspeed = 910;
                displayname = "20rnd FG42";
                displaynameshort = "7.92x57mm";
                picture = "\A3\weapons_f\data\ui\m_30stanag_caseless_red_CA.paa";
                tracersevery = 0;
                lastroundstracer = 1;
        };
};