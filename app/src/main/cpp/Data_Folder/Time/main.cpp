#include "NRG/Helper/Includes.h"
#include "NRG/obfuscate.h"
#include "NRG/Vector2.hpp"
#include "NRG/Vector3.hpp"
#include "NRG/Tools.h"
#include "NRG/Iconcpp.h"
#include "NRG/NIKE.h"
#include "NRG/Icon.h"
#include "NRG/enc.h"
#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_android.h"
#include "imgui/backends/imgui_impl_opengl3.h"
#include "FONT/Font.h"
#include "FONT/fontch.h"
#include "NRG/FoxFont.h"
#include "NRG/Memory.hpp"
#include "NRG/StrEnc.h"
#include "NRG/Spoof.h"
#include "Dobby/dobby.h"
#include <ctime>
#include "timer.h"
#include "MemoryTools.h"
#include "NRG/Helper/json.hpp"
using json = nlohmann::json;
#include "SDK.hpp"
using namespace SDK;
//RadarSketch.X,RadarSketch.Y
#include "NRG/base64/base64.h"
#include "NRG/Font.h"
#include <curl/curl.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <openssl/err.h>
#include <openssl/md5.h>
#include "NRG/zygisk.hpp"
#include "NRG/define.h"
#include "NRG/Rect.h"
#include "NRG/KittyMemory/MemoryPatch.h"
#include "NRG/FONTS/DEFAULT.h"
#include "NRG/TEAMNRG/Utils.h"
#include "NRG/TEAMNRG/Macros.h"
#include "NRG/xhook/xhook.h"
#include "Hud_Items.h"
json items_data;

//uintptr_t GUObjectArray_Offset;
//#define Offset_Test2
/*
#define GNames_Offset 0x73d9850
#define GUObject_Offset 0xc81f320
#define ProcessEvent_Offset 0x7639204
#define GNativeAndroidApp_Offset 0xc575148
#define Actors_Offset 0xa0
*/
#define GNames_Offset 0x7530f0c
#define GUObject_Offset 0xcd0fb20
#define GetActorArray_Offset 0x8f1eb50
#define ProcessEvent_Offset 0x778f3a4
#define GNativeAndroidApp_Offset 0xc89b248
#define Actors_Offset 0xa0

static std::string EXP = "";
#include "Time/Time.h"
std::string GetExpired(ImColor* col);
std::string GetExpired(ImColor *col) {
    time_t now = time(0);
    auto _tm = localtime(&now);
    Time *current = new Time(_tm);
    Time *event = new Time(EXP);
    return current->CountDownTimer(event, col, true, false);
}
bool iAwareText = true;
bool BypassLogo = true;

#define STB_IMAGE_IMPLEMENTATION
#include "NRG/stb_image.h"

bool LoadTextureFromMemory(const stbi_uc* data, size_t size, GLuint* out_texture, int* out_width, int* out_height)
{
    // Load from memory
    int image_width, image_height, channels;
    stbi_uc* image_data = stbi_load_from_memory(data, size, &image_width, &image_height, &channels, STBI_rgb_alpha);
    if (image_data == nullptr)
        return false;

    // Create an OpenGL texture identifier
    GLuint image_texture;
    glGenTextures(1, &image_texture);
    glBindTexture(GL_TEXTURE_2D, image_texture);

    // Setup filtering parameters for display
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    // Upload pixels into texture
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
    stbi_image_free(image_data);

    *out_texture = image_texture;
    *out_width = image_width;
    *out_height = image_height;

    return true;
}
 

bool stack_193 = false;
GLuint m_logo = 0; 
GLuint m_logo2 = 0; 
GLuint m_logo3 = 0; 

#define TSL_FONT_DEFAULT_SIZE 20
static UFont *tslFont = 0, *robotoTinyFont = 0, *tslFontS = 0;
static UFont *itemfont =0 ;



struct MemoryStruct {
    char *memory;
    size_t size;
};

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *) userp;

    mem->memory = (char *) realloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory == NULL) {
        return 0;
    }

    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}


float IOSViewSize;
bool IOSView;

int modXsuittest = 1405909;
int noneedhp = 401968;

std::string BYPASS_GL_KR_VNG_TW;

int modXsuit2 = 40604002;//1400129
 
      int modXsuit = 1400129;//1400129
      int modM16 = 101002;
      int modM4 = 101004;
      int modSCAR = 101003;
      int modM7 = 101008;
      int modAKM = 101001;//101001
      int modAWM = 103003;
      int modKAR98 = 103001;
      int modM24 = 103002;
      int modUZI = 102001;
      int modVECTOR = 102003;
      int modAUG = 101006;
      int modGROZA = 101005;
      int modAMR = 103012;
      int modDP = 105002;
      int modM249 = 105001;
      int stock = 1010040103;
      int mag = 1010040102;
      int attach = 1010040101;
      int emote1 = 2200101;
      int emote2 = 2200201;
      int emote3 = 2200301;
      int modUMP = 102002;
      int modPAN = 108004;
      int modACE32 = 101102;
      int modMk14 = 103007;
      int modMg3 = 105010;
      
      int bag1 = 501001;
      int bag2 = 501002;
      int bag3 = 501003;
      int bag11 = 501004;
      int bag22 = 501005;
      int bag33 = 501006;
      int helmett1 = 502001;
      int helmett2 = 502002;
      int helmett3 = 502003;
      int helmett11 = 502001;
      int helmett22 = 502002;
      int helmett33 = 502003;
      int modPara = 703001;

      int modBape = 404026;
      int modBape2 = 405000;
  
       
   int XSuits = 403003;
     
   int TestXSuitsSkin = 1405030;
   
     
int MainSuit = 0; 

  int M416_flash = 201010;
  int M416_compe = 201009;
  int M416_silent = 201011;
  int M416_reddot = 203001;
  int M416_holo = 203001;
  int M416_x2 = 203003;
  int M416_x3 = 203014;
  int M416_x4 = 203004;
  int M416_x6 = 203015;
  int M416_quickMag = 204012;
  int M416_extendedMag = 204011;
  int M416_quickNextended = 204013;
  int M416_stock = 205002;
  int M416_verical = 203015;
  int M416_angle = 202001;
  int M416_lightgrip = 202004;
  int M416_pink = 202005;
  int M416_lazer = 202007;
  int M416_thumb = 202006;

       
static int SuitSkinHackHudSdk = 0;
static int m16a4SkinHackHudSdk = 0;
static int m4SkinHackHudSdk = 0;
static int scarSkinHackHudSdk = 0;
static int m762SkinHackHudSdk = 0;
static int akmSkinHackHudSdk = 0;
static int awmSkinHackHudSdk = 0;
static int kerSkinHackHudSdk = 0;
static int m24SkinHackHudSdk = 0;
static int uziSkinHackHudSdk = 0;
static int ump45SkinHackHudSdk = 0;
static int vectorSkinHackHudSdk = 0;
static int augSkinHackHudSdk = 0;
static int grozaSkinHackHudSdk = 0;
static int amrSkinHackHudSdk = 0;
static int dp28SkinHackHudSdk = 0;
static int m249SkinHackHudSdk = 0;
static int helmetSkinHackHudSdk = 0;
static int bagSkinHackHudSdk = 0;
static int panSkinHackHudSdk = 0;
static int SpSuitSkinHackHudSdk = 0;
static int ParacSkinHackHudSdk = 0;
static int mk14SkinHackHudSdk = 0;
static int MG3SkinHackHudSdk = 0;


static int Boxm4SkinHackHudSdk = 0;
static int boxakmSkinHackHudSdk = 0;
static int ace32SkinHackHudSdk = 0;


static int coupeRBSkinHackHudSdk = 0;
static int DACIASSkinHackHudSdk = 0;
static int UAZSSkinHackHudSdk = 0;
static int MartinSkinHackHudSdk = 0;
static int RONYSkinHackHudSdk = 0;
static int MotorSkinHackHudSdk = 0;

static int AllSkinEnable = 0;


static int MotoSkinHackSdk = 0;
static int DaciaSkinHackSdk = 0;
static int BoatSkinHackSdk = 0;
static int MiniBusSkinHackSdk = 0;
static int MiradoSkinHackSdk = 0;
static int FMiradoSkinHackSdk = 0;
static int BuggySkinHackSdk = 0;
static int CoupeRPSkinHackSdk = 0;
static int BigfootSkinHackSdk = 0;
static int UAZSkinHackSdk = 0;



    FRotator g_aimRotation;
                            FVector Tarloc ;
FVector headp ;
FVector myloc ;

int EspTextSiz = 5;
int counter;

char extra[64];

uintptr_t UE4;
uintptr_t anogs;
uintptr_t anort;
uintptr_t gcloud;

//json items_data;
std::string g_Token, g_Auth;

static bool f = "f";
     static bool u = "a";
     static bool c = "l";
     static bool k = "s";
     static bool ui = "e";
     static bool bValid, ml = f+u+c+k+ui;
                    
static bool f2 = "f";
     static bool u2 = "a";
     static bool c2 = "l";
     static bool k2 = "s";
     static bool ui2 = "e";
     static bool isLogin, ml2 = f2+u2+c2+k2+ui2;
                    static bool o = "f";
     static bool p = "a";
     static bool h = "l";
     static bool d = "s";
     static bool l = "e";
     static bool nlop, ko = o+p+h+d+l;
          

android_app *g_App = 0;
ASTExtraPlayerCharacter *g_LocalPlayer = 0;
ASTExtraPlayerController *g_LocalController = 0;

FCameraCacheEntry  CameraCache = FCameraCacheEntry();
static float isAutoSlider = -0.20;
static bool MainUiMenu = false;

static std::string SLOT = " ";
static std::string modname = " ";
static std::string mod_status = " ";
static std::string credit = " ";
static std::string key = " ";
bool 绘制初始化 = false;
bool initImGui = false;
int screenWidth2 = -1, glWidth, screenHeight2 = -1, glHeight;
int g_screenWidth ;
int g_screenHeight ;
int screenWidth;
int screenHeight;

float density = -1;
extern USlider * sliderrr;
USlider * sliderrr;
int SizeXx = 0;
int SizeYy = 0;
float AutoAimBotFovSize = 130;
int ScreenWidthNrg6 =0;
int ScreenHeightNrg6 = 0;
extern int init_screen_x = 0, init_screen_y = 0;
float HUCOLORTEST = 1.0;
static float FPS;
timer worldAutoSleep;

int aimpos()
{
return sliderrr->Value;
}
int PreviousSuit = 0; // add in offsets includes (top of source).
      static int aimbotspeednrg = 1;
float AimCustomSpeed = 5;
bool WriteAddr2(void *addr, void *buffer, size_t length) {
    unsigned long page_size = sysconf(_SC_PAGESIZE);
    unsigned long size = page_size * sizeof(uintptr_t);
    return mprotect((void *) ((uintptr_t) addr - ((uintptr_t) addr % page_size) - page_size), (size_t) size, PROT_EXEC | PROT_READ | PROT_WRITE) == 0 && memcpy(addr, buffer, length) != 0;
}
template<typename T>
void Write(uintptr_t addr, T value) {
    WriteAddr2((void *) addr, &value, sizeof(T));
}
/*
static UEngine *GEngine = 0;
UWorld *GetWorld() {
    while (!GEngine) {
        GEngine = UObject::FindObject<UEngine>("UAEGameEngine Transient.UAEGameEngine_1");
        sleep(1);
    }
    if (GEngine) {
        auto ViewPort = GEngine->GameViewport;

        if (ViewPort) {
			//return {};
            return ViewPort->World;
        }
    }
    return 0;
}
*/
UWorld *GEWorld;
int GWorldNum = 0;
TUObjectArray gobjects;
UWorld *GetFullWorld()
{
 if(GWorldNum == 0) {
  gobjects = UObject::GUObjectArray->ObjObjects;
  for (int i=0; i< gobjects.Num(); i++)
  if (auto obj = gobjects.GetByIndex(i)) {
if(obj->IsA(UEngine::StaticClass())) {
auto GEngine = (UEngine *) obj;
if(GEngine) {
tslFont = GEngine->MediumFont;
robotoTinyFont = GEngine->MediumFont;
//tslFontS = GEngine->MediumFont;//
//itemfont = GEngine->MediumFont;//
auto ViewPort = GEngine->GameViewport;
if (ViewPort)
{
GEWorld = ViewPort->World;
GWorldNum = i;
return ViewPort->World;
}
}
}
  }
 }else {
  auto GEngine = (UEngine *) (gobjects.GetByIndex(GWorldNum));
  if(GEngine) {
  tslFont = GEngine->MediumFont;
robotoTinyFont = GEngine->MediumFont;
//tslFontS = GEngine->MediumFont;//
//itemfont = GEngine->MediumFont;//
  auto ViewPort = GEngine->GameViewport;
  if(ViewPort) {
GEWorld = ViewPort->World;
return ViewPort->World;
  }
  }
 }
 return 0;
}

template <class T>
void GetAllActors(std::vector<T *> &Actors) {
    UGameplayStatics *gGameplayStatics = (UGameplayStatics *)gGameplayStatics->StaticClass();
    auto GWorld = GetFullWorld();
    if (GWorld) {
        TArray<AActor *> Actors2;
        gGameplayStatics->GetAllActorsOfClass((UObject *)GWorld, T::StaticClass(), &Actors2);
        for (int i = 0; i < Actors2.Num(); i++) {
            Actors.push_back((T *)Actors2[i]);
        }
    }
}
/*
TNameEntryArray *GetGNames()
{
	return ((TNameEntryArray * (*)())(UE4 + GNames_Offset))();
}
*/
TNameEntryArray *GetGNames()
{
   return ((TNameEntryArray * (*)())(UE4 + GNames_Offset))();
  // using TNameEntryArray = TStaticIndirectArrayThreadSafeRead<FNameEntry, 2 * 1024 * 1024, 16384>;

}

//UObject::GUObjectArray = (FUObjectArray *)(UE4 + GUObject_Offset);

FVector GetBoneLocationByName(ASTExtraPlayerCharacter *Actor, const char *BoneName) {
    return Actor->GetBonePos(BoneName, FVector());
}
float testsize1 = 80;

                                  
std::vector<AActor *> getActors() 
{
    UGameplayStatics *gGameplayStatics = (UGameplayStatics *)gGameplayStatics->StaticClass();
 AActor* Actor1 = (AActor*)Actor1->StaticClass();
 auto GWorld = GetFullWorld();
    if (!GWorld) 
  return std::vector<AActor *>();
  
    auto Level = GWorld->PersistentLevel;
    if (!Level)
  return std::vector<AActor *>();
        
    std::vector<AActor*> actor;
    TArray<AActor*> Actors;
    gGameplayStatics->GetAllActorsOfClass((UObject *)GWorld, Actor1->StaticClass(), &Actors);
    for (int i = 0; i < Actors.Num(); i++)
        {
   auto Actor = Actors[i];
   actor.push_back((AActor*)Actor);
  }
   return actor;
 }
int Interval = 1;

USlider * Auto1;//autofire


int autodiss()
{
    return Auto1->Value;
}

uint32_t Colorshgg[] = {0x9241EB, 0x9EFF00, 0x006EF4, 0xCA2876, 0x0A31DE, 0xBAA7FD, 0xCEDB3F, 0x286A45, 0x58F014, 0x45CAE6, 0x773702, 0xB0CEF0, 0x3C5F51, 0x453CD7, 0x364024, 0x439997, 0x4CB612, 0xC6B564, 0x17F250, 0xE41BC0, 0xAF8E27, 0x8E382E, 0x47A101, 0x9DAC33, 0x66F4CF, 0x59A9F0, 0x798D1A, 0x2EBB59, 0xBF66C3, 0x4BD8FB, 0xBBFA54, 0x6B9881, 0x144967, 0xBAA3AE, 0xE80B9D, 0x7BA552, 0x96A456, 0x17D7B4, 0x130C39, 0x3C06A8, 0x62737E, 0xA87E89, 0xB6D3E4, 0x66B77D, 0x66E304, 0x1B80E1, 0x7A06BC, 0xBFFB1B, 0x618506, 0x7E4D34};

FLinearColor GetRandomColorByIndex(int index) {
    srand(index);

    float a = 255;
    float r = ((Colorshgg[rand() % sizeof(Colorshgg)] & 0xFF0000) >> 16);
    float g = ((Colorshgg[rand() % sizeof(Colorshgg)] & 0x00FF00) >> 8);
    float b = (Colorshgg[rand() % sizeof(Colorshgg)] & 0x0000FF);

    return {r / 255, g / 255, b / 255, a / 255};
}



bool PlayerDance;  
float DanceValue = 0.0f; 
float DancerValue = 10.0f;
bool BYPASS1;
bool BYPASS2;
bool BYPASS3;
float TEST555; 
float TEST55; 


std::string SKINNAME;


bool BypassLogo2_2; //AUTO BYPASS
int iAwareTexSiz = 15;



struct g_NRG {
MemoryPatch     
Bypass,
Bypass1,
Bypass2,
Bypass3,
Bypass4,
Bypass5,
Bypass6,
Bypass7,
Bypass8,
Bypass9,
Bypass10,
Bypass11,
Bypass12,
Bypass13,
Bypass14,
Bypass15,
Bypass16
;
} NRG;

static float LogoSize;
enum EAimTarget {
Head = 1,
Chest = 0
};

enum EAimBy {
FOV = 0,
Distance = 1
};

enum EAimTrigger {
Shooting = 0,
Scoping = 1,
Any = 2
};
float preferredFramesPerSecond;


struct sConfig {

bool HitEffect;
bool InstantHit;



    bool Pred;
    bool UnlimitedHp;
    bool SkinEnable;
    bool BoxEffectTest;
bool Monster;
    bool SmgAll;
    bool NewBypassLobby;
   bool SkinMod;
   bool BoxEffect;
   bool KillMsg;
   bool CarMod;
   bool HairSkinHackHudSdk;
   bool Parachute;
   bool allllll;
    bool DP28;
    bool M249;
    bool FAMAS;
    bool G36C;
    bool M762;
    bool QBZ;
    bool AUG;
    bool Groza;
    bool ACE32;
    bool SCARL;
    bool AKM;
    bool M416;
    
   
    
    
    bool UZI;
    bool UMP45;
    bool Vector;
    bool TommyGun;
    bool PP19Bizon; //PP-19 Bizon
    bool P90;
    bool Skorpion;
    
    bool M24;
    bool Kar98K;
    bool AWM;
    bool AMR;
    
    
    bool mm556; //5.56mm
    bool mm762; //7.62mm
    
    bool mm9; // 9mm
    bool ACP45; // .45 ACP
    
    bool Bag;
    bool Armor;
    bool Helmet;
    
    
   float ColorTest;
    bool GunEnable;
    bool BypassLogo;
    int Alert12;
int NRGtrigger;
int AimEnable;
int AimSizeMm;
int EnemieCount;
int FPSControl;
int FPSControl2;
int EspLinetow;
float Line;
float AimDistance;
float FPSControlSize;
bool ESPEnable;
bool DontUseIsland;
bool Autoclick;
bool BypassLobby;
bool AimSmooth;
bool Radar;
bool BypassNewLobby;
bool NrgAutoBypassvmm;
bool espites;
bool ShowDamage;
bool FastShoot;
bool NoShake;
bool BypassLobbyv1;
bool BypassLobbyv2;
bool BypassLobbyv3;
bool Fps90;
bool LessRecoil;
bool NoRecoil;
bool Bypassisland;
bool Bypassislandoff;
bool CrashFix;
bool IPadView;
bool NrgLobbyBypass;
bool Bypass;
bool Lobby;
bool Antiban;
bool Logo;
bool Bypass1;
bool AntiReport;
bool No_move;
bool NrgAutoBypass;
bool MemoryWideView;
bool AimTargetLine;
bool Hidebot;
bool GameInfo;
bool Weapon;
bool SmallCrosshair;
bool ItemRifle;
bool HideFov;
bool FovAutoSize;
bool XHitEffect;
float MemoryWideViewSize;
float RadarX;
float RadarY;

float RadarXx;
float RadarYy;

float RadarSize;

float XXY;
float Dis;
//bool CrashFix;

struct sPlayerESP {
bool Line;
bool Line33;
bool Box3D;
bool Health;
bool Skeleton;
bool LootBox;
bool NoBot;
bool Name;
bool Distance;
bool TeamID;
bool Vehicle;
bool Radar;
bool AlertY;
bool LootBoxItems;
bool Weapon;
bool Grenade;
bool VehicleHP;
bool VehicleFuel;
bool PlayerID;
bool EspInfo;
bool Lootboxitems;
bool Alert;
};

sPlayerESP PlayerESP{0};

struct sAimMenu {
bool AimLock;
bool Enable;
bool AimBot;
bool AimsimulatorT;
float Cross;
float AimBotSpeed;
bool Fov;
bool Line;
bool AimsimulatorQ;
float Meter;
float CrossAimLock;
bool Recoil;
float Recc;
float Position;
float AimSmoothSize;
EAimBy AimBy;
EAimTarget Target;
EAimTrigger Trigger;
bool IgnoreBot;
bool IgnoreKnocked;
bool Lessmmm;
bool VisCheck;
bool AimSmooth;
bool AimPrediction;
};
sAimMenu SilentAim{0};
sAimMenu AimBot{0};

//size edit
int L_size;
int S_size;
int Grenade_d;

struct sColorsESP {
float *PVLine;
float *PVILine;
float *BVLine;
float *BVILine;
float *PVBox;
float *PVIBox;
float *BVBox;
float *BVIBox;
float *PVSkeleton;
float *PVISkeleton;
float *BVSkeleton;
float *BVISkeleton;
float *Fov;
float *Line;
float *Box;
float *Name;
float *Distance;
float *Skeleton;
float *Vehicle;
float *LootBox;
};
sColorsESP ColorsESP{0};
//Colors
float *B_non;
float *B_vis;
float *P_non;
float *P_vis;
};

sConfig Config{0};
sConfig Configesp{0};
sConfig Configkey{0};
sConfig ConfigNrg{0};
sConfig ConfigAim{0};
sConfig ConfigSkin{0};

int FireWall = 0;
int SKIN_AKM = 0;//0
int ESPUI1OR2 = 0;//0
int LINE360N180 = 0;//0
static int fill_mess_test = 1005;



#include "ESP_DATA/NRG.h"
 /*
void DrawESP(ImDrawList *draw){
      if (BypassLogo2_2) {
        static float fps = 0.0f;
        fps = ImGui::GetIO().Framerate;
        char fpsText1[32];
        snprintf(fpsText1, sizeof(fpsText1), " FPS: %.0f", fps);
        
        
        
        
        
        draw->AddText(NULL,25.0f,{((float) density / 10.0f), 40}, IM_COL32(255, 255, 255, 255),fpsText1);
        
             //   tslFont->LegacyFontSize = 15;//5
              //  DrawTextIos(HUD, FString(fpsText1), {105, 40}, COLOR_WHITE);
             //   tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;
        
        }

}
*/


void AimAngle(FRotator &angles) {
    if (angles.Pitch > 180)
        angles.Pitch -= 360;
    if (angles.Pitch < -180)
        angles.Pitch += 360;

    if (angles.Pitch < -75.f)
        angles.Pitch = -75.f;
    else if (angles.Pitch > 75.f)
        angles.Pitch = 75.f;

    while (angles.Yaw < -180.0f)
        angles.Yaw += 360.0f;
    while (angles.Yaw > 180.0f)
        angles.Yaw -= 360.0f;
}



void (*orig_BroadcastFatalDamage)(ASTExtraPlayerController* thiz, struct FFatalDamageParameter* FatalDamageParameter);
void hk_BroadcastFatalDamage(ASTExtraPlayerController* thiz, struct FFatalDamageParameter* FatalDamageParameter)
{
  if (g_LocalPlayer->PlayerKey == FatalDamageParameter->CauserKey)
  {
    FatalDamageParameter->CauserWeaponAvatarID = 1101004046; //Glacier - M416 (Lv. 7)
    FatalDamageParameter->CauserClothAvatarID = 1406469; //Golden Pharaoh X-Suit (7-Star)
  }
  return orig_BroadcastFatalDamage(thiz, FatalDamageParameter);
}
namespace Active {
  inline int SkinCarDefault = 0;
  inline int SkinCarMod = 0;
  inline int SkinCarNew = 0;
  /////////////
  inline int SkinGunDefault = 0;
  inline int SkinGunMod = 0;
  inline int SkinGunNew = 0;
}


FLinearColor NrghexHud(int hexValue) {
  int A = (hexValue & 0xFF000000) >> 24;  // @TEAMNRG1
  int R = (hexValue & 0x00FF0000) >> 16;  // @TEAMNRG1
  int G = (hexValue & 0x0000FF00) >> 8;   // @TEAMNRG1
  int B = (hexValue & 0x000000FF) >> 0;   // @TEAMNRG1
            
  return {R / 255, G / 255, B / 255, A / 255};
  
}

/*
void (*orig_Broadcast)(ASTExtraPlayerController* thiz, struct FFatalDamageParameter* FatalDamageParameter);
void hk_Broadcast(ASTExtraPlayerController* thiz, struct FFatalDamageParameter* FatalDamageParameter)
{
    if (Config.SkinEnable) {
  if (g_LocalController != NULL && g_LocalPlayer != NULL) {
      uint32_t key = FatalDamageParameter->CauserKey;
      if (key == g_LocalPlayer->PlayerKey) {
      
   // FatalDamageParameter->CauserWeaponAvatarID = 1101004046; //Glacier - M416 (Lv. 7)
    
    if (SuitSkinHackHudSdk == 1) {
FatalDamageParameter->CauserClothAvatarID = 1405909; //Blood Raven X-Suit
} else if (SuitSkinHackHudSdk == 2) {
FatalDamageParameter->CauserClothAvatarID = 1405628; //Golden Pharaoh X-Suit
} else if (SuitSkinHackHudSdk == 3) {
FatalDamageParameter->CauserClothAvatarID = 1406152; //Avalanche X-suit
} else if (SuitSkinHackHudSdk == 4) {
FatalDamageParameter->CauserClothAvatarID = 1406475; //Irresidence X-suit
} else if (SuitSkinHackHudSdk == 5) {
FatalDamageParameter->CauserClothAvatarID = 1405983; //Poseidon X-suit
} else if (SuitSkinHackHudSdk == 6) {
FatalDamageParameter->CauserClothAvatarID = 1406638; //Arcane Jester X-Suit
} else if (SuitSkinHackHudSdk == 7) {
FatalDamageParameter->CauserClothAvatarID = 1406311; //Silvanus X-Suit
} else if (SuitSkinHackHudSdk == 8) {
FatalDamageParameter->CauserClothAvatarID = 1406971;//Marmoris X-Suit 
} else if (SuitSkinHackHudSdk == 9) {
FatalDamageParameter->CauserClothAvatarID = 1407103; //Fiore X-Suit
}



          auto WeaponManagerComponent = g_LocalPlayer -> WeaponManagerComponent;
          if (WeaponManagerComponent) {
            auto CurrentWeaponReplicated = (ASTExtraShootWeapon * ) WeaponManagerComponent -> CurrentWeaponReplicated;
            if (CurrentWeaponReplicated) {
              auto ShootWeaponComponent = CurrentWeaponReplicated -> ShootWeaponComponent;
              if (ShootWeaponComponent) {
                  
                int strWeaponId = g_LocalPlayer -> WeaponManagerComponent -> CurrentWeaponReplicated -> GetWeaponID();

if (strWeaponId == 101001) {
if (akmSkinHackHudSdk == 1)
FatalDamageParameter->CauserWeaponAvatarID = 1101001213; //Starsea Admiral - AKM 
if (akmSkinHackHudSdk == 2)
FatalDamageParameter->CauserWeaponAvatarID = 1101001063; //The Seven Seas - AKM
if (akmSkinHackHudSdk == 3)
FatalDamageParameter->CauserWeaponAvatarID = 1101001068; //Roaring Tiger - AKM (No Box)
if (akmSkinHackHudSdk == 4)
FatalDamageParameter->CauserWeaponAvatarID = 1101001089; //Glacier - AKM
if (akmSkinHackHudSdk == 5)
FatalDamageParameter->CauserWeaponAvatarID = 1101001103; //Desert Fossil - AKM
if (akmSkinHackHudSdk == 6)
FatalDamageParameter->CauserWeaponAvatarID = 1101001116; //Jack-o'-lantern - AKM
if (akmSkinHackHudSdk == 7)
FatalDamageParameter->CauserWeaponAvatarID = 1101001128; //Ghillie Dragon - AKM 
if (akmSkinHackHudSdk == 8)
FatalDamageParameter->CauserWeaponAvatarID = 1101001143; //Gold Pirate - AKM                
if (akmSkinHackHudSdk == 9)
FatalDamageParameter->CauserWeaponAvatarID = 1101001174; //Wandering Tyrant 
if (akmSkinHackHudSdk == 10)
FatalDamageParameter->CauserWeaponAvatarID = 1101001213; //Starsea Admiral - AKM
if (akmSkinHackHudSdk == 11)
FatalDamageParameter->CauserWeaponAvatarID = 1101001023; //Hellfire
} else if (strWeaponId == 101004) {
if (m4SkinHackHudSdk == 1) 
FatalDamageParameter->CauserWeaponAvatarID = 1101004046; //Glacier - M416 
if (m4SkinHackHudSdk == 2) 
FatalDamageParameter->CauserWeaponAvatarID = 1101004062; //The Fool - M416
if (m4SkinHackHudSdk == 3) 
FatalDamageParameter->CauserWeaponAvatarID = 1101004086; //Lizard Roar - M416
if (m4SkinHackHudSdk == 4) 
FatalDamageParameter->CauserWeaponAvatarID = 1101004078; //Wanderer - M416
if (m4SkinHackHudSdk == 5) 
FatalDamageParameter->CauserWeaponAvatarID = 1101004098; //Call of the Wild - M416
if (m4SkinHackHudSdk == 6) 
FatalDamageParameter->CauserWeaponAvatarID = 1101004163; //Imperial Splendor - M416
if (m4SkinHackHudSdk == 7) 
FatalDamageParameter->CauserWeaponAvatarID = 1101004201; //Silver Guru - M416
if (m4SkinHackHudSdk == 8) 
FatalDamageParameter->CauserWeaponAvatarID = 1101004138; //TechnoCore - M416
if (m4SkinHackHudSdk == 9) 
FatalDamageParameter->CauserWeaponAvatarID = 1101004209; //Tidal Embrace - M416
if (m4SkinHackHudSdk == 10) 
FatalDamageParameter->CauserWeaponAvatarID = 1101004218; //Tidal Embrace - M416
} else if (strWeaponId == 101008) {   
if (m762SkinHackHudSdk == 1) 
FatalDamageParameter->CauserWeaponAvatarID = 1101008026; //8-bit Unicorn - M762
if (m762SkinHackHudSdk == 2) 
FatalDamageParameter->CauserWeaponAvatarID = 1101008116; //Messi Football Icon M762
if (m762SkinHackHudSdk == 3) 
FatalDamageParameter->CauserWeaponAvatarID = 1101008070; //GACKT MOONSAGA-M762
if (m762SkinHackHudSdk == 4) 
FatalDamageParameter->CauserWeaponAvatarID = 1101008036; //Lotus Fury - M762
if (m762SkinHackHudSdk == 5)
FatalDamageParameter->CauserWeaponAvatarID = 1101008051; //Concerto of Love - M762
if (m762SkinHackHudSdk == 6)
FatalDamageParameter->CauserWeaponAvatarID = 1101008104; //StarCore-M762
if (m762SkinHackHudSdk == 7)
FatalDamageParameter->CauserWeaponAvatarID = 1101008081; //Stray Rebellion - M762
} else if (strWeaponId == 102001) {//
if (uziSkinHackHudSdk == 1) 
FatalDamageParameter->CauserWeaponAvatarID = 1102001024; //Savagery - UZI (No Box)
if (uziSkinHackHudSdk == 2) 
FatalDamageParameter->CauserWeaponAvatarID = 1102001036; //Ethereal Emblem - UZI (No box)
if (uziSkinHackHudSdk == 3) 
FatalDamageParameter->CauserWeaponAvatarID = 1102001058; //Romantic Moments - UZI (No Box)
if (uziSkinHackHudSdk == 4) 
FatalDamageParameter->CauserWeaponAvatarID = 1102001069; //Shimmer Power - UZI (No Box)
} else  if (strWeaponId == 103002) {
if (m24SkinHackHudSdk == 1) 
FatalDamageParameter->CauserWeaponAvatarID = 1103002018; //The Seven Seas - M24 (No Box)
if (m24SkinHackHudSdk == 2) 
FatalDamageParameter->CauserWeaponAvatarID = 1103002030; //Pharaoh's Might - M24
if (m24SkinHackHudSdk == 3) 
FatalDamageParameter->CauserWeaponAvatarID = 1103002049; //Lady Butterfly - M24 (No Box)
if (m24SkinHackHudSdk == 4) 
FatalDamageParameter->CauserWeaponAvatarID = 1103002047; //Killer Tune - M24 (No Box)
if (m24SkinHackHudSdk == 5) 
FatalDamageParameter->CauserWeaponAvatarID = 1103002059; //Circle of Life - M24
} else if (strWeaponId == 103001) {
if (kerSkinHackHudSdk == 1) 
FatalDamageParameter->CauserWeaponAvatarID = 1103001060; //Terror Fang - Kar98K
if (kerSkinHackHudSdk == 2) 
FatalDamageParameter->CauserWeaponAvatarID = 1103001079; //Kukulkan Fury - Kar98K 
if (kerSkinHackHudSdk == 3) 
FatalDamageParameter->CauserWeaponAvatarID = 1103001085; //Night of Rock - Kar98K (No Box)
if (kerSkinHackHudSdk == 4) 
FatalDamageParameter->CauserWeaponAvatarID = 1103001101; //Moonlit Grace - Kar98K
} else if (strWeaponId == 103003) {
if (awmSkinHackHudSdk == 1) 
FatalDamageParameter->CauserWeaponAvatarID = 1103003022; //Mauve Avenger - AWM
if (awmSkinHackHudSdk == 2) 
FatalDamageParameter->CauserWeaponAvatarID = 1103003030; //Field Commander - AWM
if (awmSkinHackHudSdk == 3) 
FatalDamageParameter->CauserWeaponAvatarID = 1103003042; //Godzilla - AWM
if (awmSkinHackHudSdk == 4) 
FatalDamageParameter->CauserWeaponAvatarID = 1103003062; //Flamewave - AWM
if (awmSkinHackHudSdk == 5) 
FatalDamageParameter->CauserWeaponAvatarID = 1103003087; //Flamewave - AWM
} else if (strWeaponId == 108004) {
if (panSkinHackHudSdk == 1) 
FatalDamageParameter->CauserWeaponAvatarID = 1108004125; //Honeypot - Pan (No Box)
if (panSkinHackHudSdk == 2) 
FatalDamageParameter->CauserWeaponAvatarID = 1108004145; //Night of Rock - Pan (No Box)
if (panSkinHackHudSdk == 3) 
FatalDamageParameter->CauserWeaponAvatarID = 1108004160; //Crocodile - Pan (No Box)
if (panSkinHackHudSdk == 4) 
FatalDamageParameter->CauserWeaponAvatarID = 1108004337; //Break Pad - Pan (No Box)
if (panSkinHackHudSdk == 5) 
FatalDamageParameter->CauserWeaponAvatarID = 1108004283; //Accolade - Pan (No Box)
} else if (strWeaponId == 103012) {
if (amrSkinHackHudSdk == 1) 
FatalDamageParameter->CauserWeaponAvatarID = 1103012010;//Crimson Ephialtes - AMR (Eff)
} else if (strWeaponId == 101006) {
if (augSkinHackHudSdk == 1) 
FatalDamageParameter->CauserWeaponAvatarID = 1101006033; //Wandering Circus - AUG (No Box)
if (augSkinHackHudSdk == 2)
FatalDamageParameter->CauserWeaponAvatarID = 1101006044; //Evangelion 4th Angel - AUG
} else if (strWeaponId == 102003) {
if (vectorSkinHackHudSdk == 1) 
FatalDamageParameter->CauserWeaponAvatarID = 1102003020; //Blood Tooth - Vector (No Box)
if (vectorSkinHackHudSdk == 2) 
FatalDamageParameter->CauserWeaponAvatarID = 1102003031; //Midnight Rose - Vector (No Box)
if (vectorSkinHackHudSdk == 3) 
FatalDamageParameter->CauserWeaponAvatarID = 1102003039; //Cute Baddie - Vector (No Box)
if (vectorSkinHackHudSdk == 4) 
FatalDamageParameter->CauserWeaponAvatarID = 1102003072; //Ultimate Predator - Vector (No Box)
if (vectorSkinHackHudSdk == 5) 
FatalDamageParameter->CauserWeaponAvatarID = 1102003065; //Gilded Reaper - Vector (No Box)
} else if (strWeaponId == 105010) {
if (MG3SkinHackHudSdk == 1) 
FatalDamageParameter->CauserWeaponAvatarID = 1105010008;
} else if (strWeaponId == 101003) {
if (scarSkinHackHudSdk == 1) 
FatalDamageParameter->CauserWeaponAvatarID = 1101003057; //Water Blaster - SCAR-L
if (scarSkinHackHudSdk == 2) 
FatalDamageParameter->CauserWeaponAvatarID = 1101003070; //Enchanted Pumpkin - SCAR-L
if (scarSkinHackHudSdk == 3) 
FatalDamageParameter->CauserWeaponAvatarID = 1101003079; //Operation Tomorrow - SCAR-L
if (scarSkinHackHudSdk == 4) 
FatalDamageParameter->CauserWeaponAvatarID = 1101003099; //Drop the Bass - SCAR-L @kero_200
if (scarSkinHackHudSdk == 5) 
FatalDamageParameter->CauserWeaponAvatarID = 1101003119; //Hextech Crystal - SCAR-L 
if (scarSkinHackHudSdk == 6) 
FatalDamageParameter->CauserWeaponAvatarID = 1101003146; //Thorn of Malice - SCAR-L
if (scarSkinHackHudSdk == 7) 
FatalDamageParameter->CauserWeaponAvatarID = 1101003167; //Bloodstained Nemesis - SCAR-L
if (scarSkinHackHudSdk == 8) 
FatalDamageParameter->CauserWeaponAvatarID = 1101003188;
} else if (strWeaponId == 101005)  {
if (grozaSkinHackHudSdk == 1) 
FatalDamageParameter->CauserWeaponAvatarID = 1101005019; //Forest Raider - GROZA (No Box)
if (grozaSkinHackHudSdk == 2) 
FatalDamageParameter->CauserWeaponAvatarID = 1101005052; //River Styx - Groza 
if (grozaSkinHackHudSdk == 3) 
FatalDamageParameter->CauserWeaponAvatarID = 1101005025; //Eventide Aria - GROZA (No Box)
if (grozaSkinHackHudSdk == 4) 
FatalDamageParameter->CauserWeaponAvatarID = 1101005038; //Ryomen Sukuna - Groza
}else if (strWeaponId == 102002) {
if (ump45SkinHackHudSdk == 1) 
FatalDamageParameter->CauserWeaponAvatarID = 1102002043; //Dragonfire - UMP45
if (ump45SkinHackHudSdk == 2) 
FatalDamageParameter->CauserWeaponAvatarID = 1102002053; //EMP - UMP45 (No Box)
if (ump45SkinHackHudSdk == 3) 
FatalDamageParameter->CauserWeaponAvatarID = 1102002061; //Outlawed Fantasy - UMP45
if (ump45SkinHackHudSdk == 4) 
FatalDamageParameter->CauserWeaponAvatarID = 1102002070; //Platinum Ripper - UMP45 (No Box)
if (ump45SkinHackHudSdk == 5) 
FatalDamageParameter->CauserWeaponAvatarID = 1102002030; //Anniversary - UMP45
if (ump45SkinHackHudSdk == 6) 
FatalDamageParameter->CauserWeaponAvatarID = 1102002090; //8-Bit Blast - UMP45 (No Box)
if (ump45SkinHackHudSdk == 7) 
FatalDamageParameter->CauserWeaponAvatarID = 1102002136; //Cryofrost Shard - UMP45
}else if (strWeaponId == 101002){
if (m16a4SkinHackHudSdk == 1) 
FatalDamageParameter->CauserWeaponAvatarID = 1101002029; //Blood & Bones - M16A4
if (m16a4SkinHackHudSdk == 2) 
FatalDamageParameter->CauserWeaponAvatarID = 1101002056; //Aurora Pulse - M16A4
if (m16a4SkinHackHudSdk == 3) 
FatalDamageParameter->CauserWeaponAvatarID = 1101002068; //Radiant Edge - M16A4 (No Box)
if (m16a4SkinHackHudSdk == 4) 
FatalDamageParameter->CauserWeaponAvatarID = 1101002081; //Skeletal Core - M16A4
} else if (strWeaponId == 105002) {
if (dp28SkinHackHudSdk == 1) 
FatalDamageParameter->CauserWeaponAvatarID = 1105002018; //Enigmatic Killer - DP28 (No Box)
if (dp28SkinHackHudSdk == 2) 
FatalDamageParameter->CauserWeaponAvatarID = 1105002035; //Gilded Jade Dragon - DP28 (No Box)     
}else if (strWeaponId == 103007) {
if (mk14SkinHackHudSdk == 1) 
FatalDamageParameter->CauserWeaponAvatarID = 1103007020;
if (mk14SkinHackHudSdk == 2) 
FatalDamageParameter->CauserWeaponAvatarID = 1103007028; 
}else if (strWeaponId == 105001) {
if (m249SkinHackHudSdk == 1) 
FatalDamageParameter->CauserWeaponAvatarID = 1105001034;//Party Parcel - M249
if (m249SkinHackHudSdk== 2) 
FatalDamageParameter->CauserWeaponAvatarID = 1105001020; //Winter Queen M249 (No Box)
if (m249SkinHackHudSdk== 3) 
FatalDamageParameter->CauserWeaponAvatarID = 1105001048; //Moondrop Eterna - M249
}else if (strWeaponId == 101102)  {
if (ace32SkinHackHudSdk == 1) 
FatalDamageParameter->CauserWeaponAvatarID = 1101102007; 
if (ace32SkinHackHudSdk == 2) 
FatalDamageParameter->CauserWeaponAvatarID = 1101102017; 
}

              
            }
          }
        }



      }
  
  
  }
  }
  return orig_Broadcast(thiz, FatalDamageParameter);
}
*/


/*
class FPSCounter2 {
 protected:
 unsigned int m_fps;
 unsigned int m_fpscount;
 long m_fpsinterval;
 public:
 FPSCounter2() : m_fps(0), m_fpscount(0), m_fpsinterval(0) {
 }
 void update() {
  m_fpscount++;
  if (m_fpsinterval < time(0)) {
   m_fps = m_fpscount;
   m_fpscount = 0;
   m_fpsinterval = time(0) + 1;
  }
 }
 unsigned int get() const {
  return m_fps;
 }
}; FPSCounter2 fps;

*/
  inline int SkinCarDefault = 0;
  inline int SkinCarMod = 0;
  inline int SkinCarNew = 0;
bool GL_NOWORK;
//DrawLine(HUD, NRG, NRG, 1, NrghexHud(0xff00b2ff));
bool ESPUITEST;

void FilledRectangle(AHUD *HUD, FVector2D Pos, float Width, float Height, FLinearColor Color) {
    HUD->DrawRect(Color, Pos.X, Pos.Y, Width, Height);
}
int SKINTEST = 1405909;




struct snew_Skin {
  int XSuits = 403003;
  int XSuits1 = 40604002;
  int Balo1 = 501001;
  int Balo2 = 501002;
  int Balo3 = 501003;
  int Balo4 = 501004;
  int Balo5 = 501005;
  int Balo6 = 501006;
  int Helmet1 = 502001;
  int Helmet2 = 502002;
  int Helmet3 = 502003;
  int Helmet4 = 502004;
  int Helmet5 = 502005;

  int Helmet6 = 502114;
  int Helmet7 = 502115;
  int Helmet8 = 502116;
  int Parachute = 703001;

  int AKM = 101001;
  int AKM_Mag = 291001;
  int M16A4 = 101002;
  int M16A4_Stock = 205007;
  int M16A4_Mag = 291002;
  int Scar = 101003;
  int Scar_Mag = 291003;
  int Pan = 108004;

  int M416_1 = 101004;
  int M416_2 = 291004;
  int M416_3 = 203008;
  int M416_4 = 205005;
  int M416_flash = 201010;
  int M416_compe = 201009;
  int M416_silent = 201011;
  int M416_reddot = 203001;
  int M416_holo = 203001;
  int M416_x2 = 203003;
  int M416_x3 = 203014;
  int M416_x4 = 203004;
  int M416_x6 = 203015;
  int M416_quickMag = 204012;
  int M416_extendedMag = 204011;
  int M416_quickNextended = 204013;
  int M416_stock = 205002;
  int M416_verical = 203015;
  int M416_angle = 202001;
  int M416_lightgrip = 202004;
  int M416_pink = 202005;
  int M416_lazer = 202007;
  int M416_thumb = 202006;

  int Groza = 101005;
  int QBZ = 101007;
  int AUG = 101006;
  int M762 = 101008;
  int M762_Mag = 291008;
  int ACE32 = 101102;
  int Honey = 101012;
  int UZI = 102001;
  int UMP = 102002;
  int Vector = 102003;
  int Thompson = 102004;
  int Bizon = 102005;
  int K98 = 103001;
  int M24 = 103002;
  int AWM = 103003;
  int AMR = 103012;
  int VSS = 103005;
  int SKS = 103004;
  int Mini14 = 103006;
  int MK14 = 103007;
  int SLR = 103009;
  int S1897 = 104002;
  int DP28 = 105002;
  int M249 = 105001;
  int MG3 = 105010;
  int Skorpion = 106008;
  int Moto = 1901001;
  int CoupeRP = 1961001;
  int Dacia = 1903001;
  int UAZ = 1908001;
  int Bigfoot = 1953001;
  int Mirado = 1914004;
  int OMirado = 1915001;
  int Buggy = 1907001;
  int MiniBus = 1904001;
  int Boat = 1911001;
  int M249s = 205009;
  
  int baglv1 = 501001;
    int baglv2 = 501002;
    int baglv3 = 501003;
    
    int helmetlv1 = 502001;
    int helmetlv2 = 502002;
    int helmetlv3 = 502003;
    
};

inline snew_Skin new_Skin;




 void updateSkin() {
  if (akmSkinHackHudSdk == 0) {
    new_Skin.AKM = 101001;//AKM
    new_Skin.AKM_Mag = 205005;
  }
  if (akmSkinHackHudSdk == 1) {
    new_Skin.AKM = 1101001089;// Glacier - AKM (Lv. 7)
    new_Skin.AKM_Mag = 1010010891;
  }
  if (akmSkinHackHudSdk == 2) {
    new_Skin.AKM = 1101001103;//Desert Fossil - AKM (Lv. 7)
    new_Skin.AKM_Mag = 1010011031;
  }
  if (akmSkinHackHudSdk == 3) {
    new_Skin.AKM = 1101001116;//Jack-o'-lantern - AKM (Lv. 7)
    new_Skin.AKM_Mag = 1010011161;
  }
  if (akmSkinHackHudSdk == 4) {
    new_Skin.AKM = 1101001128;//Ghillie Dragon - AKM (Lv. 7)
    new_Skin.AKM_Mag = 1010011281;
  }
  if (akmSkinHackHudSdk == 5) {
    new_Skin.AKM = 1101001143;//Gold Pirate - AKM (Lv. 7)
    new_Skin.AKM_Mag = 1010011431;
  }
  if (akmSkinHackHudSdk == 6) {
    new_Skin.AKM = 1101001154;//Codebreaker - AKM (Lv. 7)
    new_Skin.AKM_Mag = 1010011541;
  }
  if (akmSkinHackHudSdk == 7) {
    new_Skin.AKM = 1101001174;//Wandering Tyrant - AKM (Lv. 8)
    new_Skin.AKM_Mag = 1010011741;
  }
  if (akmSkinHackHudSdk == 8) {
    new_Skin.AKM = 1101001213;//Starsea Admiral - AKM (Lv. 8)
    new_Skin.AKM_Mag = 1010012131;
  }
  if (akmSkinHackHudSdk == 9) {
    new_Skin.AKM = 1101001231;//Bunny Munchkin - AKM (Lv. 7)
    new_Skin.AKM_Mag = 1010012311;
  }
  if (akmSkinHackHudSdk == 10) {
    new_Skin.AKM = 1101001242;//Decisive Day - AKM (Lv. 8)
    new_Skin.AKM_Mag = 1010012421;
  }
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if (kerSkinHackHudSdk == 0)
    new_Skin.K98 = 103001;
  if (kerSkinHackHudSdk == 1)
    new_Skin.K98 = 1103001060;//Terror Fang - Kar98K (Lv. 7)
  if (kerSkinHackHudSdk == 2)
    new_Skin.K98 = 1103001079;//Kukulkan Fury - Kar98K (Lv. 7)
  if (kerSkinHackHudSdk == 3)
    new_Skin.K98 = 1103001101;//Moonlit Grace - Kar98K (Lv. 7)
  if (kerSkinHackHudSdk == 4)
    new_Skin.K98 = 1103001146;//Titanium Shark - Kar98K (Lv. 7)
  if (kerSkinHackHudSdk == 5)
    new_Skin.K98 = 1103001160;//Nebula Hunter - Kar98K (Lv. 5)
  if (kerSkinHackHudSdk == 6)
    new_Skin.K98 = 1103001179;//Violet Volt - Kar98K (Lv. 7)
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if (awmSkinHackHudSdk == 0)
    new_Skin.AWM = 103003;
  if (awmSkinHackHudSdk == 1)
    new_Skin.AWM = 1103003022;//Mauve Avenger - AWM (Lv. 7)
  if (awmSkinHackHudSdk == 2)
    new_Skin.AWM = 1103003030;//Field Commander - AWM (Lv. 7)
  if (awmSkinHackHudSdk == 3)
    new_Skin.AWM = 1103003042;//Godzilla - AWM (Lv. 7)
  if (awmSkinHackHudSdk == 4)
    new_Skin.AWM = 1103003051;//Rainbow Drake - AWM (Lv. 7)
  if (awmSkinHackHudSdk == 5)
    new_Skin.AWM = 1103003062;//Flamewave - AWM (Lv. 7)
  if (awmSkinHackHudSdk == 6)
    new_Skin.AWM = 1103003087;//Serpengleam - AWM (Lv. 7)
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if (m24SkinHackHudSdk == 0)
    new_Skin.M24 = 103002;
  if (m24SkinHackHudSdk == 1)
    new_Skin.M24 = 1103002018;
  if (m24SkinHackHudSdk == 2)
    new_Skin.M24 = 1103002030;
  if (m24SkinHackHudSdk == 3)
    new_Skin.M24 = 1103002049;
  if (m24SkinHackHudSdk == 4)
    new_Skin.M24 = 1103002059;
  if (m24SkinHackHudSdk == 5)
    new_Skin.M24 = 1103002087;
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (ace32SkinHackHudSdk == 0)
    new_Skin.ACE32 = 101102;
  if (ace32SkinHackHudSdk == 1)
    new_Skin.ACE32 = 1101102007;//ADD
  if (ace32SkinHackHudSdk == 2)
    new_Skin.ACE32 = 1101102017;//ADD
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   if (vectorSkinHackHudSdk == 0)
    new_Skin.Vector = 102003;
  if (vectorSkinHackHudSdk == 1)
    new_Skin.Vector = 1102003020;//ADD
  if (vectorSkinHackHudSdk == 2)
    new_Skin.Vector = 1102003031;//ADD
  if (vectorSkinHackHudSdk == 3)
    new_Skin.Vector = 1102003065;//ADD
  if (vectorSkinHackHudSdk == 4)
    new_Skin.Vector = 1102003080;//ADD
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   if (ump45SkinHackHudSdk == 0)
    new_Skin.UMP = 102002;
  if (ump45SkinHackHudSdk == 1)
    new_Skin.UMP = 1102002043;//ADD
  if (ump45SkinHackHudSdk == 2)
    new_Skin.UMP = 1102002061;//ADD
  if (ump45SkinHackHudSdk == 3)
    new_Skin.UMP = 1102002090;//ADD
  if (ump45SkinHackHudSdk == 4)
    new_Skin.UMP = 1102002117;//ADD
  if (ump45SkinHackHudSdk == 5)
    new_Skin.UMP = 1102002124;//ADD
  if (ump45SkinHackHudSdk == 6)
    new_Skin.UMP = 1102002129;//ADD
  if (ump45SkinHackHudSdk == 7)
    new_Skin.UMP = 1102002136;//ADD
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (uziSkinHackHudSdk == 0)
    new_Skin.UZI = 102001;
  if (uziSkinHackHudSdk == 1)
    new_Skin.UZI = 1102001024;//ADD
  if (uziSkinHackHudSdk == 2)
    new_Skin.UZI = 1102001036;//ADD
  if (uziSkinHackHudSdk == 3)
    new_Skin.UZI = 1102001058;//ADD
  if (uziSkinHackHudSdk == 4)
    new_Skin.UZI = 1102001069;//ADD
  if (uziSkinHackHudSdk == 5)
    new_Skin.UZI = 1102001089;//ADD
  if (uziSkinHackHudSdk == 6)
    new_Skin.UZI = 1102001102;//ADD
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (m16a4SkinHackHudSdk == 0) {
    new_Skin.M16A4 = 101002;
    new_Skin.M16A4_Stock = 205007;
    new_Skin.M16A4_Mag = 291002;
  }
  if (m16a4SkinHackHudSdk == 1) {
    new_Skin.M16A4 = 1101002029;//ADD
    new_Skin.M16A4_Stock = 1010020292;
    new_Skin.M16A4_Mag = 1010020291;
  }
  if (m16a4SkinHackHudSdk == 2) {
    new_Skin.M16A4 = 1101002056;//ADD
    new_Skin.M16A4_Stock = 1010020562;
    new_Skin.M16A4_Mag = 1010020561;
  }
  if (m16a4SkinHackHudSdk == 3) {
    new_Skin.M16A4 = 1101002068;//ADD
    new_Skin.M16A4_Stock = 1010020682;
    new_Skin.M16A4_Mag = 1010020681;
  }
  if (m16a4SkinHackHudSdk == 4) {
    new_Skin.M16A4 = 1101002081;//ADD
    new_Skin.M16A4_Stock = 1010020812;
    new_Skin.M16A4_Mag = 1010020811;
  }
  if (m16a4SkinHackHudSdk == 5) {
    new_Skin.M16A4 = 1101002103;//ADD
    new_Skin.M16A4_Stock = 1010021032;
    new_Skin.M16A4_Mag = 1010021031;
  }
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if (augSkinHackHudSdk == 0)
    new_Skin.AUG = 101006;
  if (augSkinHackHudSdk == 1)
    new_Skin.AUG = 1101006033;//ADD
  if (augSkinHackHudSdk == 2)
    new_Skin.AUG = 1101006044;//ADD
  if (augSkinHackHudSdk == 3)
    new_Skin.AUG = 1101006062;//ADD
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (grozaSkinHackHudSdk == 0) 
    new_Skin.Groza = 101005;
  if (grozaSkinHackHudSdk == 1) 
    new_Skin.Groza = 1101005019;
  if (grozaSkinHackHudSdk == 2) 
    new_Skin.Groza = 1101005025;
  if (grozaSkinHackHudSdk == 3) 
    new_Skin.Groza = 1101005038;
  if (grozaSkinHackHudSdk == 4) 
    new_Skin.Groza = 1101005043;
  if (grozaSkinHackHudSdk == 5) 
    new_Skin.Groza = 1101005052;
  if (grozaSkinHackHudSdk == 6) 
    new_Skin.Groza = 1101005082;
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if (dp28SkinHackHudSdk == 0)
    new_Skin.DP28 = 105002;
  if (dp28SkinHackHudSdk == 1)
    new_Skin.DP28 = 1105002018;
  if (dp28SkinHackHudSdk == 2)
    new_Skin.DP28 = 1105002035;
  if (dp28SkinHackHudSdk == 3)
    new_Skin.DP28 = 1105002058;
  if (dp28SkinHackHudSdk == 4)
    new_Skin.DP28 = 1105002063;
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if (m249SkinHackHudSdk == 0){
    new_Skin.M249 = 105001;
	new_Skin.M249s = 205009;
	}
  if (m249SkinHackHudSdk == 1){
    new_Skin.M249 = 1105001020;
	new_Skin.M249s = 1050010351;
	}
  if (m249SkinHackHudSdk == 2){
    new_Skin.M249 = 1105001034;
	new_Skin.M249s = 1050010412;
	}
  if (m249SkinHackHudSdk == 3){
    new_Skin.M249 = 1105001048;
	new_Skin.M249s = 1050010482;
	}
  if (m249SkinHackHudSdk == 4){
    new_Skin.M249 = 1105001054;
	new_Skin.M249s = 1050010542;
  }
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (scarSkinHackHudSdk == 0) {
    new_Skin.Scar = 101003;
    new_Skin.Scar_Mag = 291003;
  }
  if (scarSkinHackHudSdk == 1) {
    new_Skin.Scar = 1101003057;
    new_Skin.Scar_Mag = 1010030571;
  }
  if (scarSkinHackHudSdk == 2) {
    new_Skin.Scar = 1101003070;
    new_Skin.Scar_Mag = 1010030701;
  }
  if (scarSkinHackHudSdk == 3) {
    new_Skin.Scar = 1101003080;
    new_Skin.Scar_Mag = 1010030801;
  }
  if (scarSkinHackHudSdk == 4) {
    new_Skin.Scar = 1101003119;
    new_Skin.Scar_Mag = 1010031191;
  }
  if (scarSkinHackHudSdk == 5) {
    new_Skin.Scar = 1101003146;
    new_Skin.Scar_Mag = 1010031461;
  }
  if (scarSkinHackHudSdk == 6) {
    new_Skin.Scar = 1101003167;
    new_Skin.Scar_Mag = 1010031671;
  }
  if (scarSkinHackHudSdk == 7) {
    new_Skin.Scar = 1101003181;
    new_Skin.Scar_Mag = 1010031811;
  }
  ///////////////////////////////////
    if (m762SkinHackHudSdk == 0) {
    new_Skin.M762 = 101008;
    new_Skin.M762_Mag = 291008;
  }
  if (m762SkinHackHudSdk == 1) {
    new_Skin.M762 = 1101008026;
    new_Skin.M762_Mag = 1010080261;
  }
  if (m762SkinHackHudSdk == 2) {
    new_Skin.M762 = 1101008051;
    new_Skin.M762_Mag = 1010080511;
  }
  if (m762SkinHackHudSdk == 3) {
    new_Skin.M762 = 1101008061;
    new_Skin.M762_Mag = 1010080611;
  }
  if (m762SkinHackHudSdk == 4) {
    new_Skin.M762 = 1101008081;
    new_Skin.M762_Mag = 1010080811;
  }
  if (m762SkinHackHudSdk == 5) {
    new_Skin.M762 = 1101008104;
    new_Skin.M762_Mag = 1010081041;
  }
  if (m762SkinHackHudSdk == 6) {
    new_Skin.M762 = 1101008116;
    new_Skin.M762_Mag = 1010081161;
  }
  if (m762SkinHackHudSdk == 7) {
    new_Skin.M762 = 1101008126;
    new_Skin.M762_Mag = 1010081261;
  }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (m4SkinHackHudSdk == 0) {
    new_Skin.M416_1 = 101004;
    new_Skin.M416_2 = 291004;
    new_Skin.M416_3 = 203008;
    new_Skin.M416_4 = 205005;
    new_Skin.M416_flash = 201010;
    new_Skin.M416_compe = 201009;
    new_Skin.M416_silent = 201011;
    new_Skin.M416_reddot = 203001;
    new_Skin.M416_holo = 203002;
    new_Skin.M416_x2 = 203003;
    new_Skin.M416_x3 = 203014;
    new_Skin.M416_x4 = 203004;
    new_Skin.M416_x6 = 203015;
    new_Skin.M416_quickMag = 204012;
    new_Skin.M416_extendedMag = 204011;
    new_Skin.M416_quickNextended = 204013;
    new_Skin.M416_stock = 205002;
    new_Skin.M416_verical = 203015;
    new_Skin.M416_angle = 202001;
    new_Skin.M416_lightgrip = 202004;
    new_Skin.M416_pink = 202005;
    new_Skin.M416_lazer = 203015;
    new_Skin.M416_thumb = 202006;
  }
  if (m4SkinHackHudSdk == 1) {
    new_Skin.M416_1 = 1101004046;
    new_Skin.M416_2 = 1010040461;
    new_Skin.M416_3 = 1010040462;
    new_Skin.M416_4 = 1010040463;
    new_Skin.M416_flash = 1010040474;
    new_Skin.M416_compe = 1010040475;
    new_Skin.M416_silent = 1010040476;
    new_Skin.M416_reddot = 1010040470;
    new_Skin.M416_holo = 1010040469;
    new_Skin.M416_x2 = 1010040468;
    new_Skin.M416_x3 = 1010040467;
    new_Skin.M416_x4 = 1010040466;
    new_Skin.M416_x6 = 1010040481;
    new_Skin.M416_quickMag = 1010040472;
    new_Skin.M416_extendedMag = 1010040473;
    new_Skin.M416_quickNextended = 1010040473;
    new_Skin.M416_stock = 1010040480;
    new_Skin.M416_verical = 1010040481;
    new_Skin.M416_thumb = 1010040478;
    new_Skin.M416_angle = 1010040477;
    new_Skin.M416_lightgrip = 1010040482;
    new_Skin.M416_pink = 1010040483;
    new_Skin.M416_lazer = 1010040484;
  }
  if (m4SkinHackHudSdk == 2) {
    new_Skin.M416_1 = 1101004062;
    new_Skin.M416_2 = 1010040611;
    new_Skin.M416_3 = 1010040612;
    new_Skin.M416_4 = 1010040613;
    new_Skin.M416_flash = 201010;
    new_Skin.M416_compe = 201009;
    new_Skin.M416_silent = 201011;
    new_Skin.M416_reddot = 203001;
    new_Skin.M416_holo = 203002;
    new_Skin.M416_x2 = 203003;
    new_Skin.M416_x3 = 203014;
    new_Skin.M416_x4 = 203004;
    new_Skin.M416_x6 = 203015;
    new_Skin.M416_quickMag = 204012;
    new_Skin.M416_extendedMag = 204011;
    new_Skin.M416_quickNextended = 204013;
    new_Skin.M416_stock = 205002;
    new_Skin.M416_verical = 203015;
    new_Skin.M416_angle = 202001;
    new_Skin.M416_lightgrip = 202004;
    new_Skin.M416_pink = 202005;
    new_Skin.M416_lazer = 203015;
    new_Skin.M416_thumb = 202006;
  }
  if (m4SkinHackHudSdk == 3) {
    new_Skin.M416_1 = 1101004078;
    new_Skin.M416_2 = 1010040781;
    new_Skin.M416_3 = 1010040782;
    new_Skin.M416_4 = 1010040783;
    new_Skin.M416_flash = 201010;
    new_Skin.M416_compe = 201009;
    new_Skin.M416_silent = 201011;
    new_Skin.M416_reddot = 203001;
    new_Skin.M416_holo = 203002;
    new_Skin.M416_x2 = 203003;
    new_Skin.M416_x3 = 203014;
    new_Skin.M416_x4 = 203004;
    new_Skin.M416_x6 = 203015;
    new_Skin.M416_quickMag = 204012;
    new_Skin.M416_extendedMag = 204011;
    new_Skin.M416_quickNextended = 204013;
    new_Skin.M416_stock = 205002;
    new_Skin.M416_verical = 203015;
    new_Skin.M416_angle = 202001;
    new_Skin.M416_lightgrip = 202004;
    new_Skin.M416_pink = 202005;
    new_Skin.M416_lazer = 203015;
    new_Skin.M416_thumb = 202006;
  }
  if (m4SkinHackHudSdk == 4) {
    new_Skin.M416_1 = 1101004086;
    new_Skin.M416_2 = 1010040861;
    new_Skin.M416_3 = 1010040862;
    new_Skin.M416_4 = 1010040863;
    new_Skin.M416_flash = 201010;
    new_Skin.M416_compe = 201009;
    new_Skin.M416_silent = 201011;
    new_Skin.M416_reddot = 203001;
    new_Skin.M416_holo = 203002;
    new_Skin.M416_x2 = 203003;
    new_Skin.M416_x3 = 203014;
    new_Skin.M416_x4 = 203004;
    new_Skin.M416_x6 = 203015;
    new_Skin.M416_quickMag = 204012;
    new_Skin.M416_extendedMag = 204011;
    new_Skin.M416_quickNextended = 204013;
    new_Skin.M416_stock = 205002;
    new_Skin.M416_verical = 203015;
    new_Skin.M416_angle = 202001;
    new_Skin.M416_lightgrip = 202004;
    new_Skin.M416_pink = 202005;
    new_Skin.M416_lazer = 203015;
    new_Skin.M416_thumb = 202006;
  }
  if (m4SkinHackHudSdk == 5) {
    new_Skin.M416_1 = 1101004098;
    new_Skin.M416_2 = 1010040981;
    new_Skin.M416_3 = 1010040982;
    new_Skin.M416_4 = 1010040983;
    new_Skin.M416_flash = 201010;
    new_Skin.M416_compe = 201009;
    new_Skin.M416_silent = 201011;
    new_Skin.M416_reddot = 203001;
    new_Skin.M416_holo = 203002;
    new_Skin.M416_x2 = 203003;
    new_Skin.M416_x3 = 203014;
    new_Skin.M416_x4 = 203004;
    new_Skin.M416_x6 = 203015;
    new_Skin.M416_quickMag = 204012;
    new_Skin.M416_extendedMag = 204011;
    new_Skin.M416_quickNextended = 204013;
    new_Skin.M416_stock = 205002;
    new_Skin.M416_verical = 203015;
    new_Skin.M416_angle = 202001;
    new_Skin.M416_lightgrip = 202004;
    new_Skin.M416_pink = 202005;
    new_Skin.M416_lazer = 203015;
    new_Skin.M416_thumb = 202006;
  }
  if (m4SkinHackHudSdk == 6) {
    new_Skin.M416_1 = 1101004138;
    new_Skin.M416_2 = 1010041381;
    new_Skin.M416_3 = 1010041382;
    new_Skin.M416_4 = 1010041383;
    new_Skin.M416_flash = 1010041136;
    new_Skin.M416_compe = 1010041137;
    new_Skin.M416_silent = 1010041138;
    new_Skin.M416_reddot = 1010041128;
    new_Skin.M416_holo = 1010041127;
    new_Skin.M416_x2 = 1010041126;
    new_Skin.M416_x3 = 1010041125;
    new_Skin.M416_x4 = 1010041124;
    new_Skin.M416_x6 = 203015;
    new_Skin.M416_quickMag = 1010041134;
    new_Skin.M416_extendedMag = 1010041129;
    new_Skin.M416_quickNextended = 1010041135;
    new_Skin.M416_stock = 1010041146;
    new_Skin.M416_verical = 1010041145;
    new_Skin.M416_angle = 1010041139;
    new_Skin.M416_lightgrip = 202004;
    new_Skin.M416_pink = 202005;
    new_Skin.M416_lazer = 203015;
    new_Skin.M416_thumb = 202006;
  }
  if (m4SkinHackHudSdk == 7) {
    new_Skin.M416_1 = 1101004163;
    new_Skin.M416_2 = 1010041631;
    new_Skin.M416_3 = 1010041632;
    new_Skin.M416_4 = 1010041633;
    new_Skin.M416_flash = 201010;
    new_Skin.M416_compe = 1010041574;
    new_Skin.M416_silent = 1010041575;
    new_Skin.M416_reddot = 1010041566;
    new_Skin.M416_holo = 1010041565;
    new_Skin.M416_x2 = 1010041564;
    new_Skin.M416_x3 = 1010041560;
    new_Skin.M416_x4 = 1010041554;
    new_Skin.M416_x6 = 203015;
    new_Skin.M416_quickMag = 1010041568;
    new_Skin.M416_extendedMag = 1010041569;
    new_Skin.M416_quickNextended = 1010041567;
    new_Skin.M416_stock = 1010041579;
    new_Skin.M416_verical = 1010041578;
    new_Skin.M416_angle = 1010041576;
    new_Skin.M416_lightgrip = 20200400;
    new_Skin.M416_pink = 202005;
    new_Skin.M416_lazer = 203015;
    new_Skin.M416_thumb = 1010041577;
  }
  if (m4SkinHackHudSdk == 8) {
    new_Skin.M416_1 = 1101004201;
    new_Skin.M416_2 = 1010042011;
    new_Skin.M416_3 = 1010042012;
    new_Skin.M416_4 = 1010042013;
    new_Skin.M416_flash = 1010041956;
    new_Skin.M416_compe = 1010041957;
    new_Skin.M416_silent = 1010041958;
    new_Skin.M416_reddot = 1010041948;
    new_Skin.M416_holo = 1010041947;
    new_Skin.M416_x2 = 1010041946;
    new_Skin.M416_x3 = 1010041945;
    new_Skin.M416_x4 = 1010041944;
    new_Skin.M416_x6 = 1010041967;
    new_Skin.M416_quickMag = 1010041949;
    new_Skin.M416_extendedMag = 1010041950;
    new_Skin.M416_quickNextended = 1010041955;
    new_Skin.M416_stock = 1010041966;
    new_Skin.M416_verical = 1010041965;
    new_Skin.M416_angle = 1010041959;
    new_Skin.M416_lightgrip = 202004;
    new_Skin.M416_pink = 202005;
    new_Skin.M416_lazer = 203015;
    new_Skin.M416_thumb = 202006;
  }
  if (m4SkinHackHudSdk == 9) {
    new_Skin.M416_1 = 1101004209;
    new_Skin.M416_2 = 1010042073;
    new_Skin.M416_3 = 1010042083;
    new_Skin.M416_4 = 1010042093;
    new_Skin.M416_flash = 20101000;
    new_Skin.M416_compe = 1010042037;
    new_Skin.M416_silent = 1010042039;
    new_Skin.M416_reddot = 1010042029;
    new_Skin.M416_holo = 1010042028;
    new_Skin.M416_x2 = 1010042027;
    new_Skin.M416_x3 = 1010042026;
    new_Skin.M416_x4 = 1010042025;
    new_Skin.M416_x6 = 1010042024;
    new_Skin.M416_quickMag = 1010042034;
    new_Skin.M416_extendedMag = 1010042035;
    new_Skin.M416_quickNextended = 1010042036;
    new_Skin.M416_stock = 1010042047;
    new_Skin.M416_verical = 1010042046;
    new_Skin.M416_angle = 1010042044;
    new_Skin.M416_lightgrip = 202004;
    new_Skin.M416_pink = 202005;
    new_Skin.M416_lazer = 203015;
    new_Skin.M416_thumb = 202006;
  }
  if (m4SkinHackHudSdk == 10) {
    new_Skin.M416_1 = 1101004218;
    new_Skin.M416_2 = 1010042153;
    new_Skin.M416_3 = 1010042163;
    new_Skin.M416_4 = 1010042173;
    new_Skin.M416_flash = 1010042128;
    new_Skin.M416_compe = 1010042127;
    new_Skin.M416_silent = 1010042129;
    new_Skin.M416_reddot = 1010042119;
    new_Skin.M416_holo = 1010042118;
    new_Skin.M416_x2 = 1010042117;
    new_Skin.M416_x3 = 1010042116;
    new_Skin.M416_x4 = 1010042115;
    new_Skin.M416_x6 = 1010042114;
    new_Skin.M416_quickMag = 1010042124;
    new_Skin.M416_extendedMag = 1010042125;
    new_Skin.M416_quickNextended = 1010042126;
    new_Skin.M416_stock = 1010042137;
    new_Skin.M416_verical = 1010042136;
    new_Skin.M416_angle = 1010042134;
    new_Skin.M416_lightgrip = 1010042138;
    new_Skin.M416_pink = 1010042139;
    new_Skin.M416_lazer = 1010042144;
    new_Skin.M416_thumb = 1010042135;
  }
  
  
      if (amrSkinHackHudSdk == 0)
    new_Skin.AMR = 103012;
  if (amrSkinHackHudSdk == 1)
    new_Skin.AMR = 1103012010;//ADD
    
      if (mk14SkinHackHudSdk == 0)
    new_Skin.MK14 = 103007;
  if (mk14SkinHackHudSdk == 1)
    new_Skin.MK14 = 1103007020;//ADD
      if (mk14SkinHackHudSdk == 2)
    new_Skin.MK14 = 1103007028;//ADD
    

  if (MG3SkinHackHudSdk == 0)
    new_Skin.MG3 = 105010;
  if (MG3SkinHackHudSdk == 1)
    new_Skin.MG3 = 1105010008;//ADD
    
    
    
    
    
//LV-1
if (bagSkinHackHudSdk == 0)
new_Skin.baglv1 = 501001; //LV 1
if (bagSkinHackHudSdk == 1)
new_Skin.baglv1 = 1501001220; //Blood Raven Backpack (Lv. 1)
if (bagSkinHackHudSdk == 2)
new_Skin.baglv1 = 1501001174; //Pharaoh's Regalia Backpack (Lv. 1)
if (bagSkinHackHudSdk == 3)
new_Skin.baglv1 = 1501001051; //The Fool Backpack (Lv. 1)
if (bagSkinHackHudSdk == 4)
new_Skin.baglv1 = 1501001443; //Luminous Galaxy Backpack (Lv. 1)
if (bagSkinHackHudSdk == 5)
new_Skin.baglv1 = 1501001265; //Poseidon Backpack (Lv. 1)
if (bagSkinHackHudSdk == 6)
new_Skin.baglv1 = 1501001321; //Gackt Moonsaga Backpack(Lv. 1)
if (bagSkinHackHudSdk == 7)
new_Skin.baglv1 = 1501001277; //Godzilla Backpack (Lv. 1)
if (bagSkinHackHudSdk == 8)
new_Skin.baglv1 = 1501001550;//Frosty Snowglobe Backpack (Lv. 1)
if (bagSkinHackHudSdk == 9)
new_Skin.baglv1 = 1501001552; //Ebil Bunny Backpack (Lv. 1)
if (bagSkinHackHudSdk == 10)
new_Skin.baglv1 = 1501001061; //Godzilla Backpack (Lv. 1)
    
//LV-2
if (bagSkinHackHudSdk == 0)
new_Skin.baglv2 = 501002; //LV 2
if (bagSkinHackHudSdk == 1)
new_Skin.baglv2 = 1501002220; //Blood Raven Backpack (Lv. 2)
if (bagSkinHackHudSdk == 2)
new_Skin.baglv2 = 1501002174; //Pharaoh's Regalia Backpack (Lv. 2)
if (bagSkinHackHudSdk == 3)
new_Skin.baglv2 = 1501002051; //The Fool Backpack (Lv. 2)
if (bagSkinHackHudSdk == 4)
new_Skin.baglv2 = 1501002443; //Luminous Galaxy Backpack (Lv. 2)
if (bagSkinHackHudSdk == 5)
new_Skin.baglv2 = 1501002265; //Poseidon Backpack (Lv. 2)
if (bagSkinHackHudSdk == 6)
new_Skin.baglv2 = 1501002321; //Gackt Moonsaga Backpack(Lv. 2)
if (bagSkinHackHudSdk == 7)
new_Skin.baglv2 = 1501002277; //Godzilla Backpack (Lv. 2)
if (bagSkinHackHudSdk == 8)
new_Skin.baglv2 = 1501002550; //Frosty Snowglobe Backpack (Lv. 2)
if (bagSkinHackHudSdk == 9)
new_Skin.baglv2 = 1501002552; //Ebil Bunny Backpack (Lv. 2)
if (bagSkinHackHudSdk == 10)
new_Skin.baglv2 = 1501002061; //Godzilla Backpack (Lv. 2)

//LV-3
if (bagSkinHackHudSdk == 0)
new_Skin.baglv3 = 501003; //LV 3
if (bagSkinHackHudSdk == 1)
new_Skin.baglv3 = 1501003220; //Blood Raven Backpack (Lv. 3)
if (bagSkinHackHudSdk == 2)
new_Skin.baglv3 = 1501003174; //Pharaoh's Regalia Backpack (Lv. 3)
if (bagSkinHackHudSdk == 3)
new_Skin.baglv3 = 1501003051; //The Fool Backpack (Lv. 3)
if (bagSkinHackHudSdk == 4)
new_Skin.baglv3 = 1501003443; //Luminous Galaxy Backpack (Lv. 3)
if (bagSkinHackHudSdk == 5)
new_Skin.baglv3 = 1501003265; //Poseidon Backpack (Lv. 3)
if (bagSkinHackHudSdk == 6)
new_Skin.baglv3 = 1501003321; //Gackt Moonsaga Backpack(Lv. 3)
if (bagSkinHackHudSdk == 7)
new_Skin.baglv3 = 1501003277; //Godzilla Backpack (Lv. 3)
if (bagSkinHackHudSdk == 8)
new_Skin.baglv3 = 1501003550; //Frosty Snowglobe Backpack (Lv. 3)
if (bagSkinHackHudSdk == 9)
new_Skin.baglv3 = 1501003552; //Ebil Bunny Backpack (Lv. 3)
 if (bagSkinHackHudSdk == 10)
new_Skin.baglv3 = 1501003061; //Godzilla Backpack (Lv. 3)







//lv-1
if (helmetSkinHackHudSdk == 0)
new_Skin.helmetlv1 = 502001; //lv 1
if (helmetSkinHackHudSdk == 1)
new_Skin.helmetlv1 = 1502001028; //Scarlet Beast Helmet (Lv. 1)
if (helmetSkinHackHudSdk == 2)
new_Skin.helmetlv1 = 1502001014; //Inferno Rider Helmet (Lv. 1)
if (helmetSkinHackHudSdk == 3)
new_Skin.helmetlv1 = 1502001023; //Glacier Helmet (Lv. 1)
if (helmetSkinHackHudSdk == 4)
new_Skin.helmetlv1 = 1502001065; //Moon Bunny Helmet (Lv. 1)
if (helmetSkinHackHudSdk == 5)
new_Skin.helmetlv1 = 1502001031; //Mutated Helmet (Lv. 1)
if (helmetSkinHackHudSdk == 6)
new_Skin.helmetlv1 = 1502001033; //Intergalactic Helmet (Lv. 1)
if (helmetSkinHackHudSdk == 7)
new_Skin.helmetlv1 = 1502001069; //Masked Psychic Helmet (Lv. 1)
if (helmetSkinHackHudSdk == 8)
new_Skin.helmetlv1 = 1502001261; //Atlantic Tech Helmet (Lv. 1)
if (helmetSkinHackHudSdk == 9)
new_Skin.helmetlv1 = 1502001272; //Mystic Battle Helmet (Lv. 1)
if (helmetSkinHackHudSdk == 10)
new_Skin.helmetlv1 = 1502001183; //Godzilla Helmet (Lv. 1)


//lv-2
if (helmetSkinHackHudSdk == 0)
new_Skin.helmetlv2 = 502002; //lv 2
if (helmetSkinHackHudSdk == 1)
new_Skin.helmetlv2 = 1502002028; //Scarlet Beast Helmet (Lv. 2)
if (helmetSkinHackHudSdk == 2)
new_Skin.helmetlv2 = 1502002014; //Inferno Rider Helmet (Lv. 2)
if (helmetSkinHackHudSdk == 3)
new_Skin.helmetlv2 = 1502002023; //Glacier Helmet (Lv. 2)
if (helmetSkinHackHudSdk == 4)
new_Skin.helmetlv2 = 1502002065; //Moon Bunny Helmet (Lv. 2)
if (helmetSkinHackHudSdk == 5)
new_Skin.helmetlv2 = 1502002031; //Mutated Helmet (Lv. 2)
if (helmetSkinHackHudSdk == 6)
new_Skin.helmetlv2 = 1502002033; //Intergalactic Helmet (Lv. 2)
if (helmetSkinHackHudSdk == 7)
new_Skin.helmetlv2 = 1502002069; //Masked Psychic Helmet (Lv. 2)
if (helmetSkinHackHudSdk == 8)
new_Skin.helmetlv2 = 1502002261; //Atlantic Tech Helmet (Lv. 2)
if (helmetSkinHackHudSdk == 9)
new_Skin.helmetlv2 = 1502002272; //Mystic Battle Helmet (Lv. 2)
if (helmetSkinHackHudSdk == 10)
new_Skin.helmetlv2 = 1502002183; //Godzilla Helmet (Lv. 2)


//lv-3
if (helmetSkinHackHudSdk == 0)
new_Skin.helmetlv3 = 502003; //lv 3
if (helmetSkinHackHudSdk == 1)
new_Skin.helmetlv3 = 1502003028; //Scarlet Beast Helmet (Lv. 3)
if (helmetSkinHackHudSdk == 2)
new_Skin.helmetlv3 = 1502003014; //Inferno Rider Helmet (Lv. 3)
if (helmetSkinHackHudSdk == 3)
new_Skin.helmetlv3 = 1502003023; //Glacier Helmet (Lv. 3)
if (helmetSkinHackHudSdk == 4)
new_Skin.helmetlv3 = 1502003065; //Moon Bunny Helmet (Lv. 3)
if (helmetSkinHackHudSdk == 5)
new_Skin.helmetlv3 = 1502003031; //Mutated Helmet (Lv. 3)
if (helmetSkinHackHudSdk == 6)
new_Skin.helmetlv3 = 1502003033; //Intergalactic Helmet (Lv. 3)
if (helmetSkinHackHudSdk == 7)
new_Skin.helmetlv3 = 1502003069; //Masked Psychic Helmet (Lv. 3)
if (helmetSkinHackHudSdk == 8)
new_Skin.helmetlv3 = 1502003261; //Atlantic Tech Helmet (Lv. 3)
if (helmetSkinHackHudSdk == 9)
new_Skin.helmetlv3 = 1502003272; //Mystic Battle Helmet (Lv. 3)
if (helmetSkinHackHudSdk == 10)
new_Skin.helmetlv3 = 1502003183; //Godzilla Helmet (Lv. 3)



  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Monster Truck
BigfootSkinHackSdk
*/
   if (BigfootSkinHackSdk == 0)
    new_Skin.Bigfoot = 1953001;
  if (BigfootSkinHackSdk == 1)
    new_Skin.Bigfoot = 1953004;
    
 //   Mirado (Open Top)
 //   MiradoSkinHackSdk
  if (MiradoSkinHackSdk == 0)
    new_Skin.OMirado = 1915001;
  if (MiradoSkinHackSdk == 1)
    new_Skin.OMirado = 1915011;
  if (MiradoSkinHackSdk == 2)
    new_Skin.OMirado = 1915099;
    
   // Mirado (Closed Top)
    //FMiradoSkinHackSdk
  if (MiradoSkinHackSdk == 0)
    new_Skin.Mirado = 1914001;
  if (FMiradoSkinHackSdk == 1)
    new_Skin.Mirado = 1914011;
    
    //Motorcycle
    //MotoSkinHackSdk
  if (MotoSkinHackSdk == 0)
    new_Skin.Moto = 1901001;
  if (MotoSkinHackSdk == 1)
    new_Skin.Moto = 1901073;
  if (MotoSkinHackSdk == 2)
    new_Skin.Moto = 1901074;
  if (MotoSkinHackSdk == 3)
    new_Skin.Moto = 1901075;
  if (MotoSkinHackSdk == 4)
    new_Skin.Moto = 1901047;
  if (MotoSkinHackSdk == 5)
    new_Skin.Moto = 1901085;
  if (MotoSkinHackSdk == 6)
    new_Skin.Moto = 1901076;
  if (MotoSkinHackSdk == 7)
    new_Skin.Moto = 1901027;
  if (MotoSkinHackSdk == 8)
    new_Skin.Moto = 1901018;
  if (MotoSkinHackSdk == 9)
    new_Skin.Moto = 1901085;
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  //Buggy
  //BuggySkinHackSdk
if (BuggySkinHackSdk == 0)
    new_Skin.Buggy = 1907001;
  if (BuggySkinHackSdk == 1)
    new_Skin.Buggy = 1907047;
  if (BuggySkinHackSdk == 2)
    new_Skin.Buggy = 1907009;
if (BuggySkinHackSdk == 3)
    new_Skin.Buggy = 1907010;
if (BuggySkinHackSdk == 4)
    new_Skin.Buggy = 1907011;
if (BuggySkinHackSdk == 5)
    new_Skin.Buggy = 1907012;
if (BuggySkinHackSdk == 6)
    new_Skin.Buggy = 1907013;
if (BuggySkinHackSdk == 7)
    new_Skin.Buggy = 1907014;
if (BuggySkinHackSdk == 8)
    new_Skin.Buggy = 1907015;
if (BuggySkinHackSdk == 9)
    new_Skin.Buggy = 1907016;
if (BuggySkinHackSdk == 10)
    new_Skin.Buggy = 1907017;
if (BuggySkinHackSdk == 11)
    new_Skin.Buggy = 1907018;
if (BuggySkinHackSdk == 12)
    new_Skin.Buggy = 1907019;
if (BuggySkinHackSdk == 13)
    new_Skin.Buggy = 1907020;
if (BuggySkinHackSdk == 14)
    new_Skin.Buggy = 1907021;
if (BuggySkinHackSdk == 15)
    new_Skin.Buggy = 1907022;
if (BuggySkinHackSdk == 16)
    new_Skin.Buggy = 1907023;
if (BuggySkinHackSdk == 17)
    new_Skin.Buggy = 1907024;
if (BuggySkinHackSdk == 18)
    new_Skin.Buggy = 1907025;
if (BuggySkinHackSdk == 19)
    new_Skin.Buggy = 1907026;
if (BuggySkinHackSdk == 20)
    new_Skin.Buggy = 1907027;
if (BuggySkinHackSdk == 21)
    new_Skin.Buggy = 1907028;
if (BuggySkinHackSdk == 22)
    new_Skin.Buggy = 1907029;
if (BuggySkinHackSdk == 23)
    new_Skin.Buggy = 1907030;
if (BuggySkinHackSdk == 24)
    new_Skin.Buggy = 1907031;
if (BuggySkinHackSdk == 25)
    new_Skin.Buggy = 1907032;
if (BuggySkinHackSdk == 26)
    new_Skin.Buggy = 1907033;
if (BuggySkinHackSdk == 27)
    new_Skin.Buggy = 1907034;
if (BuggySkinHackSdk == 28)
    new_Skin.Buggy = 1907035;
if (BuggySkinHackSdk == 29)
    new_Skin.Buggy = 1907036;
if (BuggySkinHackSdk == 30)
    new_Skin.Buggy = 1907037;
if (BuggySkinHackSdk == 31)
    new_Skin.Buggy = 1907038;
if (BuggySkinHackSdk == 32)
    new_Skin.Buggy = 1907039;
if (BuggySkinHackSdk == 33)
    new_Skin.Buggy = 1907040;
    
    //Dacia
    //DaciaSkinHackSdk
    
                  if (DaciaSkinHackSdk == 1) {
                    new_Skin.Dacia = 1903075; //Koenigsegg Gemera (Rainbow)
                    } else if (DaciaSkinHackSdk == 2) {
                    new_Skin.Dacia = 1903080; //Koenigsegg Gemera (Silver Grey)
                    } else if (DaciaSkinHackSdk == 3) {
                    new_Skin.Dacia = 1903076; //Koenigsegg Gemera (Drawn)
                    } else if (DaciaSkinHackSdk == 4) {
                    new_Skin.Dacia = 1903073; //Tesla Roadster (Digital Water) ( DACIA )
                    } else if (DaciaSkinHackSdk == 5) {
                    new_Skin.Dacia = 1903074; //Koenigsegg Gemera (Silver Gray) ( DACIA )
                    } else if (DaciaSkinHackSdk == 6) {
                    new_Skin.Dacia = 1903072; //Koenigsegg Gemera (Rainbow) ( DACIA )
                    } else if (DaciaSkinHackSdk == 7) {
                    new_Skin.Dacia = 1903189; //Lamborghini Estoque Metal Grey ( DACIA )
                    } else if (DaciaSkinHackSdk == 8) {
                    new_Skin.Dacia = 1903071; //Tesla Roadster (Diamond) ( DACIA )
                    } else if (DaciaSkinHackSdk == 9) {
                    new_Skin.Dacia = 1903190; //Lamborghini Estoque Metal Grey
                    } else if (DaciaSkinHackSdk == 10) {
                    new_Skin.Dacia = 1903079; //Lamborghini Estoque Oro
                    } else if (DaciaSkinHackSdk == 11) {
                    new_Skin.Dacia = 1903193; //Lamborghini Estoque Oro
                    } else if (DaciaSkinHackSdk == 12) {
                    new_Skin.Dacia = 1903200; //
                    } else if (DaciaSkinHackSdk == 13) {
                    new_Skin.Dacia = 1903201; //
                    } else if (DaciaSkinHackSdk == 14) {
                    new_Skin.Dacia = 1903001; //
                    } else if (DaciaSkinHackSdk == 15) {
                    new_Skin.Dacia = 1903014; //
                    } else if (DaciaSkinHackSdk == 16) {
                    new_Skin.Dacia = 1903017; //
                    } else if (DaciaSkinHackSdk == 17) {
                    new_Skin.Dacia = 1903035; //
                    } else if (DaciaSkinHackSdk == 18) {
                    new_Skin.Dacia = 1903087; //
                    } else if (DaciaSkinHackSdk == 19) {
                    new_Skin.Dacia = 1903088; //
                    } else if (DaciaSkinHackSdk == 20) {
                    new_Skin.Dacia = 1903089; //
                    } else if (DaciaSkinHackSdk == 21) {
                    new_Skin.Dacia = 1903090; //
                    } else if (DaciaSkinHackSdk == 22) {
                    new_Skin.Dacia = 1903191; //
                    } else if (DaciaSkinHackSdk == 23) {
                    new_Skin.Dacia = 1903192; //
                    } else if (DaciaSkinHackSdk == 24) {
                    new_Skin.Dacia = 1903197; //
                    } 
  
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  //Mini Bus
  //MiniBusSkinHackSdk
if (MiniBusSkinHackSdk == 0)
    new_Skin.MiniBus = 1904001;
  if (MiniBusSkinHackSdk == 1)
    new_Skin.MiniBus = 1904005;
  if (MiniBusSkinHackSdk == 2)
    new_Skin.MiniBus = 1904006;
if (MiniBusSkinHackSdk == 3)
    new_Skin.MiniBus = 1904007;
if (MiniBusSkinHackSdk == 4)
    new_Skin.MiniBus = 1904008;
if (MiniBusSkinHackSdk == 5)
    new_Skin.MiniBus = 1904009;
if (MiniBusSkinHackSdk == 6)
    new_Skin.MiniBus = 1904010;
if (MiniBusSkinHackSdk == 7)
    new_Skin.MiniBus = 1904011;
if (MiniBusSkinHackSdk == 8)
    new_Skin.MiniBus = 1904012;
if (MiniBusSkinHackSdk == 9)
    new_Skin.MiniBus = 1904013;
if (MiniBusSkinHackSdk == 10)
    new_Skin.MiniBus = 1904014;
if (MiniBusSkinHackSdk == 11)
    new_Skin.MiniBus = 1904015;
if (MiniBusSkinHackSdk == 12)
    new_Skin.MiniBus = 1904004;
  
    //Coupe RB
    //CoupeRPSkinHackSdk
 if (CoupeRPSkinHackSdk == 1) {
                    new_Skin.CoupeRP = 1961020; //Lamborghini Aventador (Green) - CoupleRB
                    } else if (CoupeRPSkinHackSdk == 2) {
                    new_Skin.CoupeRP = 1961033; //Warp Green - CoupleRB
                    } else if (CoupeRPSkinHackSdk == 3) {
                    new_Skin.CoupeRP = 1961032; //Koenigsegg One:1 Phoenix - CoupleRB
                    } else if (CoupeRPSkinHackSdk == 4) {
                    new_Skin.CoupeRP = 1961039; //Maserati MC20 Rosso Vincente - CoupleRB
                    } else if (CoupeRPSkinHackSdk == 5) {
                    new_Skin.CoupeRP = 1961046; //Bugatti La Voiture Noire (Warrior)
                    } else if (CoupeRPSkinHackSdk == 6) {
                    new_Skin.CoupeRP = 1961048; //Aston Martin Valkyrie (Luminous Diamond)
                    } else if (CoupeRPSkinHackSdk == 7) {
                    new_Skin.CoupeRP = 1961029; //Koenigsegg One:1 Gilt
                    } else if (CoupeRPSkinHackSdk == 8) {
                    new_Skin.CoupeRP = 1961025; //Lamborghini Centenario Carbon Fiber
                    } else if (CoupeRPSkinHackSdk == 9) {
                    new_Skin.CoupeRP = 1961021; //Lamborghini Centenario Carbon Fiber
                    } else if (CoupeRPSkinHackSdk == 10) {
                    new_Skin.CoupeRP = 1961017; //Koenigsegg Jesko (Rainbow)
                    } else if (CoupeRPSkinHackSdk == 11) {
                    new_Skin.CoupeRP = 1961042; //Koenigsegg Jesko (Rainbow)
                    } else if (CoupeRPSkinHackSdk == 12) {
                    new_Skin.CoupeRP = 1961051; //
                    } else if (CoupeRPSkinHackSdk == 13) {
                    new_Skin.CoupeRP = 1961052; //
                    } else if (CoupeRPSkinHackSdk == 14) {
                    new_Skin.CoupeRP = 1961053; //
                    } else if (CoupeRPSkinHackSdk == 15) {
                    new_Skin.CoupeRP = 1961054; //
                    } else if (CoupeRPSkinHackSdk == 16) {
                    new_Skin.CoupeRP = 1961055; //
                    } else if (CoupeRPSkinHackSdk == 17) {
                    new_Skin.CoupeRP = 1961056; //
                    } else if (CoupeRPSkinHackSdk == 18) {
                    new_Skin.CoupeRP = 1961057; //
                    } else if (CoupeRPSkinHackSdk == 19) {
                    new_Skin.CoupeRP = 1961016; //
                    } else if (CoupeRPSkinHackSdk == 20) {
                    new_Skin.CoupeRP = 1961007; //
                    } else if (CoupeRPSkinHackSdk == 21) {
                    new_Skin.CoupeRP = 1961010; //
                    } else if (CoupeRPSkinHackSdk == 22) {
                    new_Skin.CoupeRP = 1961012; //
                    } else if (CoupeRPSkinHackSdk == 23) {
                    new_Skin.CoupeRP = 1961013; //
                    } else if (CoupeRPSkinHackSdk == 24) {
                    new_Skin.CoupeRP = 1961014; //
                    } else if (CoupeRPSkinHackSdk == 25) {
                    new_Skin.CoupeRP = 1961015; //
                    } else if (CoupeRPSkinHackSdk == 26) {
                    new_Skin.CoupeRP = 1961047; //
                    } else if (CoupeRPSkinHackSdk == 27) {
                    new_Skin.CoupeRP = 1961137; //
                    } else if (CoupeRPSkinHackSdk == 28) {
                    new_Skin.CoupeRP = 1961138; //
                    } else if (CoupeRPSkinHackSdk == 29) {
                    new_Skin.CoupeRP = 1961139; //
                    } else if (CoupeRPSkinHackSdk == 30) {
                    new_Skin.CoupeRP = 1961043; //
                    } else if (CoupeRPSkinHackSdk == 31) {
                    new_Skin.CoupeRP = 1961044; //
                    } else if (CoupeRPSkinHackSdk == 32) {
                    new_Skin.CoupeRP = 1961045; //
                    } else if (CoupeRPSkinHackSdk == 33) {
                    new_Skin.CoupeRP = 1961046; //
                    } else if (CoupeRPSkinHackSdk == 34) {
                    new_Skin.CoupeRP = 1961050; //
                    } else if (CoupeRPSkinHackSdk == 35) {
                    new_Skin.CoupeRP = 1961001; //
                    } else if (CoupeRPSkinHackSdk == 36) {
                    new_Skin.CoupeRP = 1961024; //
                    } else if (CoupeRPSkinHackSdk == 37) {
                    new_Skin.CoupeRP = 1961034; //
                    } else if (CoupeRPSkinHackSdk == 38) {
                    new_Skin.CoupeRP = 1961018; //
                    } else if (CoupeRPSkinHackSdk == 39) {
                    new_Skin.CoupeRP = 1961049; //
                    } else if (CoupeRPSkinHackSdk == 40) {
                    new_Skin.CoupeRP = 1961030; //
                    } else if (CoupeRPSkinHackSdk == 41) {
                    new_Skin.CoupeRP = 1961031; //
                    } else if (CoupeRPSkinHackSdk == 42) {
                    new_Skin.CoupeRP = 1961035; //
                    } else if (CoupeRPSkinHackSdk == 43) {
                    new_Skin.CoupeRP = 1961036; //
                    } else if (CoupeRPSkinHackSdk == 44) {
                    new_Skin.CoupeRP = 1961037; //
                    } else if (CoupeRPSkinHackSdk == 45) {
                    new_Skin.CoupeRP = 1961038; //
                    } else if (CoupeRPSkinHackSdk == 46) {
                    new_Skin.CoupeRP = 1961040; //
                    } else if (CoupeRPSkinHackSdk == 47) {
                    new_Skin.CoupeRP = 1961041; //
                    } 
                    
    /*
    
    1903200  -  Bentley Flying Spur Mulliner (Nebula)  
1903201  -  Bentley Flying Spur Mulliner (Damson over Silver Storm)  
1908094  -  Bentley Bentayga Azure (Galaxy Glitter)  
1908095  -  Bentley Bentayga Azure (Magnetic)  
1915008  -  Bentley Continental GTC Mulliner (Holocrystal)  
1915009  -  Bentley Continental GTC Mulliner (Tanzanite Purple)  
1961137  -  Bentley Batur (Holoprism)  
1961138  -  Bentley Batur (Solar Pulse)  
1961139  -  Bentley Batur (Bonneville Pearlescent Silver)

3.1 Bently Car Skin I'd

Join For More : (https://t.me/+-ucVzdEc4GYyNDM1)
    */
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//UAZ
  //UAZSkinHackSdk

                   if (UAZSkinHackSdk == 1) {
                    new_Skin.UAZ = 1908070; //Robust Universe
                    } else if (UAZSkinHackSdk == 2) {
                    new_Skin.UAZ = 1908077; //Maserati Levante Neon Urbano
                    } else if (UAZSkinHackSdk == 3) {
                    new_Skin.UAZ = 1908078; //Maserati Levante Firmamento 
                    } else if (UAZSkinHackSdk == 4) {
                    new_Skin.UAZ = 1908076; //Maserati Luce Arancione
                    } else if (UAZSkinHackSdk == 5) {
                    new_Skin.UAZ = 1908075; //Maserati Levante Blu Emozione
                    } else if (UAZSkinHackSdk == 6) {
                    new_Skin.UAZ = 1908067; //Lamborghini Urus Gialla Inti
                    } else if (UAZSkinHackSdk == 7) {
                    new_Skin.UAZ = 1908075; //Maserati Levante Blu Emozione
                    } else if (UAZSkinHackSdk == 8) {
                    new_Skin.UAZ = 1908094; //
                    } else if (UAZSkinHackSdk == 9) {
                    new_Skin.UAZ = 1908095; //
                    } else if (UAZSkinHackSdk == 10) {
                    new_Skin.UAZ = 1957001; //
                    } else if (UAZSkinHackSdk == 11) {
                    new_Skin.UAZ = 1908086; //
                    } else if (UAZSkinHackSdk == 12) {
                    new_Skin.UAZ = 1908066; //
                    } else if (UAZSkinHackSdk == 13) {
                    new_Skin.UAZ = 1908189; //
                    } else if (UAZSkinHackSdk == 14) {
                    new_Skin.UAZ = 1908001; //
                    } 
 //BoatSkinHackSdk
    //PG-117
 if (BoatSkinHackSdk == 0)
    new_Skin.Boat = 1911001;
  if (BoatSkinHackSdk == 1)
    new_Skin.Boat = 1911013;
  if (BoatSkinHackSdk == 2)
    new_Skin.Boat = 1911003;
if (BoatSkinHackSdk == 3)
    new_Skin.Boat = 1911004;
if (BoatSkinHackSdk == 4)
    new_Skin.Boat = 1911005;
if (BoatSkinHackSdk == 5)
    new_Skin.Boat = 1911006;
if (BoatSkinHackSdk == 6)
    new_Skin.Boat = 1911007;
if (BoatSkinHackSdk == 7)
    new_Skin.Boat = 1911008;
if (BoatSkinHackSdk == 8)
    new_Skin.Boat = 1911009;
if (BoatSkinHackSdk == 9)
    new_Skin.Boat = 1911010;
if (BoatSkinHackSdk == 10)
    new_Skin.Boat = 1911011;
if (BoatSkinHackSdk == 11)
    new_Skin.Boat = 1911012;


}

int bag111[] = { 501001, 1501001220, 1501001174, 1501001051, 1501001443, 1501001265, 1501001321, 1501001277, 1501001550, 1501001552, 1501001061};
int bag222[] = { 501002, 1501002220, 1501002174, 1501002051, 1501002443, 1501002265, 1501002321, 1501002277, 1501002550, 1501002552, 1501002061};
int bag333[] = { 501006,501005,501004,501003,501002,501001, 1501003220, 1501003174, 1501003051, 1501003443, 1501003265, 1501003321, 1501003277, 1501003550, 1501003552, 1501003061};



int Helmet1[] = { 502001, 1502001028, 1502001014, 1502001023, 1502001065, 1502001031, 1502001033, 1502001069, 1502001261, 1502001272, 1502001183};
int Helmet2[] = { 502002, 1502002028, 1502002014, 1502002023, 1502002065, 1502002031, 1502002033, 1502002069, 1502002261, 1502002272, 1502002183};
int Helmet3[] = { 502001,502002,502003, 1502003028, 1502003014, 1502003023, 1502003065, 1502003031, 1502003033, 1502003069, 1502003261, 1502003272, 1502003183};


int m4v[] = { 101004, 1101004046, 1101004062, 1101004078, 1101004086, 1101004098, 1101004138, 1101004163,1101004201,1101004209,1101004218};
int scar[] = { 101003, 1101003057, 1101003070, 1101003080, 1101003119, 1101003146, 1101003167, 1101003181};
int akmv[] = { 101001,1101001089, 1101001103, 1101001116, 1101001128, 1101001143, 1101001154, 1101001174,1101001213,1101001231,1101001242};
int m7[] = { 101008, 1101008026, 1101008051, 1101008061, 1101008081, 1101008104, 1101008116, 1101008126};
int awm[] = { 103003, 1103003022, 1103003030, 1103003042, 1103003051, 1103003062};
int amr[] = { 103012, 1103012010};
int mk14[] = { 103007, 1103007020, 1103007028};
int mg3[] = { 105010, 1105010008};

int kar[] = { 103001, 1103001060, 1103001079, 1103001101, 1103001145, 1103001160, 1103001179};
int m24[] = { 103002, 1103002018, 1103002030, 1103002048, 1103002056, 1103002087};
int dp[] = { 105002, 1105002018, 1105002035, 1105002058, 1105002063};
int m249[] = { 105001, 1105001020, 1105001034, 1105001048, 1105001054};
int groza[] = { 101005, 1101005019, 1101005025, 1101005038, 1101005043, 1101005052, 1101005082};
int aug[] = { 101006, 1101006033, 1101006044, 1101006062};
int m16[] = { 101002, 1101002029, 1101002056, 1101002068, 1101002081, 1101002103};
int uzi[] = { 102001, 1102001024, 1102001036, 1102001058, 1102001069, 1102001089, 1102001102};
int ump[] = { 102002, 1102002043, 1102002061, 1102002090, 1102002117, 1102002124, 1102002129, 1102002136};
int vector2[] = { 102003, 1102003020, 1102003031, 1102003065, 1102003080};
int tommy[] = { 102004, 1102004018, 1102004034};
int bizon[] = { 102005, 1102005007, 1102005020, 1102005041};
int ace32[] = { 101102, 1101102007, 1101102017};
int pan[] = { 108004, 1108004125, 1108004145, 1108004160, 1108004283, 1108004337, 1108004356, 1108004365, 1108004054, 1108004008};

int m249s[] = { 205009, 1050010351, 1050010412, 1050010482, 1050010542};
int akmmag[] = { 291001,204013,204011,204012,1010010891, 1010011031, 1010011161, 1010011281, 1010011431, 1010011541, 1010011741,1010012131,1010012311,1010012421};
int m7mag[] = { 291008,204013,204011,204012,1010080261, 1010080511, 1010080611, 1010080811, 1010081041, 1010081161, 1010081261};
int scarmag[] = { 291003,204013,204011,204012,1010030571, 1010030701, 1010030801, 1010031191, 1010031461, 1010031671, 1010031811};
int m4mag[] = { 291004,204013,204011,204012,1010040461,1010040611,1010040781,1010040861,1010040981,1010041381,1010041631,1010042011,1010042073,1010042153  };

int m4sight[] = { 203008,1010040462,1010040612,1010040782,1010040862,1010040982,1010041382,1010041632,1010042012,1010042083,1010042163  };

int m4stock[] = { 205005,1010040463,1010040613,1010040783,1010040863,1010040983,1010041383,1010041633,1010042013,1010042093,1010042173  };

int m4stock1[] = { 205002,1010040480,205002,205002,205002,205002,1010041146,1010041579,1010041966,1010042137,1010042173  };

int m4reddot[] = { 203001,1010040470,203001,203001,203001,203001,1010041128,1010041566,1010041948,1010042029,1010042119  };

int m16s[] = { 205007, 1010020292, 1010020562, 1010020682, 1010020812, 1010021032};
int m16mag[] = { 291002,204013,204011,204012, 1010020291, 1010020561, 1010020681, 1010020811, 1010021031};

/*
int emote1[] = { 2200101,12220023,12219677,12219716,12209401,12220028,12209701,12209801,12209901 };
int emote2[] = { 2200201,12210201,12210601,12220028,12219819,12211801,12212001,12212201,12212401 };
int emote3[] = { 2200301,12212601,12213201,12219715,12219814,12213601,12213801,12214001,12214201 };
*/
int SuitX[] = { 403003,1405628,1405870,1405983,1406152,1406311,1406475,1406638,1406872 };

int Bag[] = { 501006,501005,501004,501003,501002,501001,1501003550,1501003277,1501003321,1501003443,1501003265,1501003051,1501003220,1501003174 };

int Helmet[] = { 502001,502002,502003,1502003014,1502003028,1502003023,1501002443,1502003031,1502003033,1502003069,1502003261 };


//M416 ONLY
int M4161[] = { 101004, 1101004046, 1101004062, 1101004078, 1101004086, 1101004098, 1101004138, 1101004163, 1101004201, 1101004209, 1101004218};
int M4162[] = { 291004, 1010040461, 1010040611, 1010040781, 1010040861, 1010040981, 1010041381, 1010041631, 1010042011, 1010042073, 1010042153};
int M4163[] = { 203008, 1010040462, 1010040612, 1010040782, 1010040862, 1010040982, 1010041382, 1010041632, 1010042012, 1010042083, 1010042163};
int M4164[] = { 205005, 1010040463, 1010040613, 1010040783, 1010040863, 1010040983, 1010041383, 1010041633, 1010042013, 1010042093, 1010042173};
int M416flash[] = { 201010, 1010040474, 201010, 201010, 201010, 201010, 1010041136, 201010, 1010041956, 20101000, 1010042128};
int M416compe[] = { 201009, 1010040475, 201009, 201009, 201009, 201009, 1010041137, 1010041574, 1010041957, 1010042037, 1010042127};
int M416silent[] = { 201011, 1010040476, 201011, 201011, 201011, 201011, 1010041138, 1010041575, 1010041958, 1010042039, 1010042129};
//int M416reddot[] = { 203001, 1010040470, 203001, 203001, 203001, 203001, 1010041128, 1010041566, 1010041948, 1010042029, 1010042119};
int M416holo[] = { 203002, 1010040469, 203002, 203002, 203002, 203002, 1010041127, 1010041565, 1010041947, 1010042028, 1010042118};
int M416x2[] = { 203003, 1010040468, 203003, 203003, 203003, 203003, 1010041126, 1010041564, 1010041946, 1010042027, 1010042117};
int M416x3[] = { 203014, 1010040467, 203014, 203014, 203014, 203014, 1010041125, 1010041560, 1010041945, 1010042026, 1010042116};
int M416x4[] = { 203004, 1010040466, 203004, 203004, 203004, 203004, 1010041124, 1010041554, 1010041944, 1010042025, 1010042115};
int M416x6[] = { 203015, 1010040481, 203015, 203015, 203015, 203015, 203015, 203015, 1010041967, 1010042024, 1010042114};
int M416quickMag[] = { 204012, 1010040472/*1010040471*/, 204012, 204012, 204012, 204012, 1010041134, 1010041568, 1010041949, 1010042034, 1010042124};
int M416extendedMag[] = { 204011, 1010040473, 204011, 204011, 204011, 204011, 1010041129, 1010041569, 1010041950, 1010042035, 1010042125};
int M416quickNextended[] = { 204013, 1010040473, 204013, 204013, 204013, 204013, 1010041135, 1010041567, 1010041955, 1010042036, 1010042126};
int M416stock[] = { 205002, 1010040480, 205002, 205002, 205002, 205002, 1010041146, 1010041579, 1010041966, 1010042047, 1010042137};
//int M416verical[] = { 203015, 1010040481, 203015, 203015, 203015, 203015, 1010041145, 1010041578, 1010041965, 1010042046, 1010042136};
int M416angle[] = { 202001, 1010040477, 202001, 202001, 202001, 202001, 1010041139, 1010041576, 1010041959, 1010042044, 1010042134};
//int M416lightgrip[] = { 202004, 1010040482, 202004, 202004, 202004, 202004, 202004, 20200400, 202004, 202004, 1010042138};
//int M416pink[] = { 202005, 1010040483, 202005, 202005, 202005, 202005, 202005, 202005, 202005, 202005, 1010042139};
//int M416lazer[] = { 203015, 1010040484, 203015, 203015, 203015, 203015, 203015, 203015, 203015, 203015, 1010042144};
int M416thumb[] = { 202006, 1010040478, 202006, 202006, 202006, 202006, 202006, 1010041577, 202006, 202006, 1010042135};
    
   
    
  float test111;
    float test222;
    
    
    static float 子追命中率=1.0f;
static int ZdDq;
static int ZdMax;
static int TestDe = 0;
static int ASD;
static bool IsLaunch = false;
bool 追踪状态=true;
bool 弹道追踪=false;
bool 坐标追踪=false;
    
std::string NRG1() {
    char NRG2[1024] = {0};
    char NRG3[1024] = {0};
    FILE* NRG4;

    NRG4 = popen("getprop ro.product.brand", "r");
    if (NRG4 != NULL) {
        if (fgets(NRG3, sizeof(NRG3), NRG4)) {
            strncpy(NRG2, NRG3, sizeof(NRG2));
        }
        pclose(NRG4);
    }

    return std::string(NRG2);
}



std::chrono::steady_clock::time_point lastWeaponChangeTimei;
std::chrono::steady_clock::time_point lastWeaponChangeTime;
void RenderESP( AHUD *HUD/*, int ScreenWidth, int ScreenHeight*/) {
    
updateSkin();
    
    
    
        
        if (!g_Token.empty() && !g_Auth.empty() && g_Token == g_Auth) {
                    
                        auto GWorld = GetFullWorld();
    if (GWorld) {
        if (GWorld->PersistentLevel) {
            auto Actors = *(TArray<AActor *> *) ((uintptr_t) GWorld->PersistentLevel + Actors_Offset);
            //人数
                    
               //     fps.update();
        
                    
                    
                    
                    
                    UCharacterWeaponManagerComponent *WeaponManagerComponent;
ASTExtraShootWeapon * CurrentWeaponReplicated = 0;
AAvatarCapture* ALuaActor = 0;

UShootWeaponEntity *ShootWeaponEntityComp =0;

   ASTExtraPlayerCharacter *localPlayer = 0;
   ASTExtraPlayerController *localPlayerController = 0;
   ASTExtraPetCharacter *TEST = 0;
   APickUpListWrapperActor *wrapperactor  = 0;
   

   // screenWidth = ScreenWidth;
   // screenHeight = ScreenHeight;
                    
                         
    static float cnt = 0.0f;//@TEAMNRG1
              float r2 = cos(cnt) * .5f + .5f;//@TEAMNRG1
              float g2 = cos(cnt - 2.f * 3.14 / 3.f) * .5f + .5f;//@TEAMNRG1
              float b2 = cos(cnt - 4.f * 3.14 / 3.f) * .5f + .5f;//@TEAMNRG1
              if (cnt >= FLT_MAX) {//@TEAMNRG1
                  cnt = 0.0f;//@TEAMNRG1
              } else {//@TEAMNRG1
                  cnt += 0.02f;//@TEAMNRG1
              }    //@TEAMNRG1

#define COLOR_RGP FLinearColor(r2, g2, b2, 1.f)//@TEAMNRG1
 

      UCanvas *Canvas = HUD->Canvas;
      
      screenWidth = g_screenWidth;
        screenHeight = g_screenHeight;
      
    ScreenWidthNrg6 = Canvas->SizeX;
        ScreenHeightNrg6 = Canvas->SizeY;
        
    if (Canvas)
        
    {
        
          FPS = getF(getA(UE4 + 0xC2242F0));
        
        static bool loadFont = false;
        if (!loadFont)
        {
            pthread_t t;
            pthread_create(&t, 0, LoadFont, 0);
            loadFont = true;
        }

        if (!tslFont || !robotoTinyFont || !tslFontS || !itemfont)
            return;
         
       {
        if (BypassLogo2_2) {
            
      
   //    itemfont->LegacyFontSize = 15;
  //      DrawOutlinedTexttt(HUD, BYPASS_GL_KR_VNG_TW, {105, (float) screenHeight - 84}, COLOR_WHITE, COLOR_BLACK, true);
    //   itemfont->LegacyFontSize = 15;
       
       tslFont->LegacyFontSize = 12;
        DrawText(HUD, BYPASS_GL_KR_VNG_TW, {105, (float) screenHeight - 84},  COLOR_WHITE);
     

          }
       }
       
       

 
        UGameplayStatics *gGameplayStatics = (UGameplayStatics *)UGameplayStatics::StaticClass();
UKismetMathLibrary* UMC = (UKismetMathLibrary*)UKismetMathLibrary::StaticClass();
ULuaOverriderInterface* BOX = (ULuaOverriderInterface*)ULuaOverriderInterface::StaticClass();
UItemAvatarComponentBase* SKIN = (UItemAvatarComponentBase*)UItemAvatarComponentBase::StaticClass();
        UKismetSystemLibrary*USl = (UKismetSystemLibrary*)UKismetSystemLibrary::StaticClass();
        
        //auto NRGtestskin = ( UItemAvatarComponentBase *) pFunc;
        
        
        auto GWorld = GetFullWorld();
        if (GWorld) {
            UNetDriver *NetDriver = GWorld->NetDriver;
            if (NetDriver) {
                UNetConnection *ServerConnection = NetDriver->ServerConnection;
                if (ServerConnection) {
                    localPlayerController = (ASTExtraPlayerController *)ServerConnection->PlayerController;
                }
            }

            
            
            
           
            if (localPlayerController)
            {
                std::vector<ASTExtraPlayerCharacter *> PlayerCharacter;
                GetAllActors(PlayerCharacter);
    int IntCount = 0;
                for (auto actor = PlayerCharacter.begin(); actor != PlayerCharacter.end(); actor++) {
                    auto Actor = *actor;
                    if (Actor->PlayerKey == ((ASTExtraPlayerController *)localPlayerController)->PlayerKey) {
                        localPlayer = Actor;
                        break;
                    }
                }

                if (localPlayer)
                {
                    
                    
                    
                    
          
if (Config.SkinEnable) {
 if (localPlayerController->BackpackComponent){
     auto data = localPlayerController->BackpackComponent->ItemListNet;
     auto bag = data.IncArray;
     for (int j = 0; j < bag.Num(); j++) {
     int ID = bag[j].Unit.DefineID.TypeSpecificID;

for (int i = 0; i < sizeof(bag333) / sizeof(bag333[0]); i++) {
                 if (ID == bag333[i]) {
                     bag[j].Unit.DefineID.TypeSpecificID = new_Skin.baglv3;
                     break;
                  }
                 }
                
for (int i = 0; i < sizeof(Helmet3) / sizeof(Helmet3[0]); i++) {
                 if (ID == Helmet3[i]) {
                     bag[j].Unit.DefineID.TypeSpecificID = new_Skin.helmetlv3;
                     break;
                  }
                 }
                
				
                 
                 
                
           
            }
        }
          }
                    
                    
if (Config.SkinEnable) {
if (localPlayer && localPlayer->AvatarComponent2) {
auto AvatarComp = localPlayer->AvatarComponent2;
FNetAvatarSyncData NetAvatarComp = *(FNetAvatarSyncData*)((uintptr_t)AvatarComp + 0x388);

auto Slotsybc = NetAvatarComp.SlotSyncData;

if (SuitSkinHackHudSdk == 1) {
Slotsybc[5].ItemId = 1405909; //Blood Raven X-Suit     
} else if (SuitSkinHackHudSdk == 2) {
Slotsybc[5].ItemId = 1405628; //Golden Pharaoh X-Suit          
} else if (SuitSkinHackHudSdk == 3) {
Slotsybc[5].ItemId = 1406152; //Avalanche X-suit        
} else if (SuitSkinHackHudSdk == 4) {
Slotsybc[5].ItemId = 1406475; //Irresidence X-suit     
} else if (SuitSkinHackHudSdk == 5) {
Slotsybc[5].ItemId = 1405983; //Poseidon X-suit 
} else if (SuitSkinHackHudSdk == 6) {
Slotsybc[5].ItemId = 1406638; //Arcane Jester X-Suit    
} else if (SuitSkinHackHudSdk == 7) {
Slotsybc[5].ItemId = 1406311; //Silvanus X-Suit  
} else if (SuitSkinHackHudSdk == 8) {
Slotsybc[5].ItemId = 1406971;//Marmoris X-Suit    
} else if (SuitSkinHackHudSdk == 9) {
Slotsybc[5].ItemId = 1407103; //Fiore X-Suit
} else if (SuitSkinHackHudSdk == 10) { 
Slotsybc[5].ItemId = 1405145; //Invader
} else if (SuitSkinHackHudSdk == 11) { 
Slotsybc[5].ItemId = 1400782;//Glacier Set
} else if (SuitSkinHackHudSdk == 12) { 
Slotsybc[5].ItemId = 1400119;//Wanderer Outfit
} else if (SuitSkinHackHudSdk == 13) { 
Slotsybc[5].ItemId = 1400117;//FireMan Set
} else if (SuitSkinHackHudSdk == 14) { 
Slotsybc[5].ItemId = 1400693;//Vampire Set
} else if (SuitSkinHackHudSdk == 15) { 
Slotsybc[5].ItemId = 1405092;//The Fool Set
} else if (SuitSkinHackHudSdk == 16) { 
Slotsybc[5].ItemId = 1405090;//Smooth Hitman Set (Cat) {
} else if (SuitSkinHackHudSdk == 17) { 
Slotsybc[5].ItemId = 1405482;//Anniversary Unicorn Set
} else if (SuitSkinHackHudSdk == 18) { 
Slotsybc[5].ItemId = 1405583;//Dazzling Youth Set
} else if (SuitSkinHackHudSdk == 19) { 
Slotsybc[5].ItemId = 1405593;//Red Commander Set
} else if (SuitSkinHackHudSdk == 20) { 
Slotsybc[5].ItemId = 1405629;//Dark Widow Set
} else if (SuitSkinHackHudSdk == 21) { 
Slotsybc[5].ItemId = 1405582;//Violet Halo Set
} else if (SuitSkinHackHudSdk == 22) { 
Slotsybc[5].ItemId = 1404049;
Slotsybc[6].ItemId = 1404050;
Slotsybc[7].ItemId = 1404051;
} else if (SuitSkinHackHudSdk == 23) { 
Slotsybc[5].ItemId = 1405623; //Yellow Mummy
} else if (SuitSkinHackHudSdk == 24) { 
Slotsybc[5].ItemId = 1400687; //White Mummy
} else if (SuitSkinHackHudSdk == 25) { 
Slotsybc[5].ItemId = 1405102; //Golden Trigger
} else if (SuitSkinHackHudSdk == 26) { 
Slotsybc[5].ItemId = 1405207; //Ryan Set
} else if (SuitSkinHackHudSdk == 27) { 
Slotsybc[5].ItemId = 1406398; //Flamewraith Set
} else if (SuitSkinHackHudSdk == 28) { 
Slotsybc[5].ItemId = 1406742; //Silver Guru - Set
}else if (SuitSkinHackHudSdk == 29) { 
Slotsybc[5].ItemId = 1407225; //luminous Set
}else if (SuitSkinHackHudSdk == 30) { 
Slotsybc[5].ItemId = 1407180; //
} else if (SuitSkinHackHudSdk == 31) { 
Slotsybc[5].ItemId = 1407800; //
} else if (SuitSkinHackHudSdk == 32) { 
Slotsybc[5].ItemId = 1407145; //
} else if (SuitSkinHackHudSdk == 33) { 
Slotsybc[5].ItemId = 80020002; //
} else if (SuitSkinHackHudSdk == 34) { 
Slotsybc[5].ItemId = 1407187; //
} else if (SuitSkinHackHudSdk == 35) { 
Slotsybc[5].ItemId = 1407229; //
} else if (SuitSkinHackHudSdk == 36) { 
Slotsybc[5].ItemId = 1407240; //
} else if (SuitSkinHackHudSdk == 37) { 
Slotsybc[5].ItemId = 1407222; //
} else if (SuitSkinHackHudSdk == 38) { 
Slotsybc[5].ItemId = 1407247; //
} else if (SuitSkinHackHudSdk == 39) { 
Slotsybc[5].ItemId = 1407186; //
} else if (SuitSkinHackHudSdk == 40) { 
Slotsybc[5].ItemId = 1407239; //
} else if (SuitSkinHackHudSdk == 41) { 
Slotsybc[5].ItemId = 1407232; //
} else if (SuitSkinHackHudSdk == 42) { 
Slotsybc[5].ItemId = 1407250; //
} else if (SuitSkinHackHudSdk == 43) { 
Slotsybc[5].ItemId = 1406657; //
} else if (SuitSkinHackHudSdk == 44) { 
Slotsybc[5].ItemId = 1406660; //
} else if (SuitSkinHackHudSdk == 45) { 
Slotsybc[5].ItemId = 1405186; //
} else if (SuitSkinHackHudSdk == 46) { 
Slotsybc[5].ItemId = 1405015; //
} else if (SuitSkinHackHudSdk == 47) { 
Slotsybc[5].ItemId = 1407160; //
} else if (SuitSkinHackHudSdk == 48) { 
Slotsybc[5].ItemId = 1407161; //
} else if (SuitSkinHackHudSdk == 49) { 
Slotsybc[5].ItemId = 1400690; //
} else if (SuitSkinHackHudSdk == 50) { 
Slotsybc[5].ItemId = 1405005; //
} else if (SuitSkinHackHudSdk == 51) { 
Slotsybc[5].ItemId = 1400692; //
} else if (SuitSkinHackHudSdk == 52) { 
Slotsybc[5].ItemId = 1400678; //
} else if (SuitSkinHackHudSdk == 53) { 
Slotsybc[5].ItemId = 1406658; //
} else if (SuitSkinHackHudSdk == 54) { 
Slotsybc[5].ItemId = 1405013; //
} else if (SuitSkinHackHudSdk == 55) { 
Slotsybc[5].ItemId = 1405004; //
} else if (SuitSkinHackHudSdk == 56) { 
Slotsybc[5].ItemId = 1400668; //
} else if (SuitSkinHackHudSdk == 57) { 
Slotsybc[5].ItemId = 1405006; //
}

Slotsybc[8].ItemId = new_Skin.baglv3;
Slotsybc[9].ItemId = new_Skin.helmetlv3;
		
/*
if (MainSuit != Slotsybc[8].ItemId) {
MainSuit = Slotsybc[8].ItemId;
localPlayer->AvatarComponent2->OnRep_BodySlotStateChanged();
}
if (MainSuit != Slotsybc[9].ItemId) {
MainSuit = Slotsybc[9].ItemId;
localPlayer->AvatarComponent2->OnRep_BodySlotStateChanged();
}
        
        */
if (MainSuit != Slotsybc[5].ItemId) {
MainSuit = Slotsybc[5].ItemId;
localPlayer->AvatarComponent2->OnRep_BodySlotStateChanged();
}
if (SuitSkinHackHudSdk == 22) { 
if (MainSuit != Slotsybc[6].ItemId) {
MainSuit = Slotsybc[6].ItemId;
localPlayer->AvatarComponent2->OnRep_BodySlotStateChanged();
}
if (MainSuit != Slotsybc[7].ItemId) {
MainSuit = Slotsybc[7].ItemId;
localPlayer->AvatarComponent2->OnRep_BodySlotStateChanged();
}
}
}

}

/*

if (localPlayerController->BackpackComponent){
  auto data = localPlayerController->BackpackComponent->ItemListNet;
  auto bag = data.IncArray;
  for (int j = 0; j < bag.Num(); j++) {
  int ID = bag[j].Unit.DefineID.TypeSpecificID;
  if (ID != 0) {
      
    
    
         if (ID == 501001){
for (int i = 0; i < sizeof(bag111) / sizeof(bag111[0]); i++) {
                 if (ID == bag111[i]) {
                     bag[j].Unit.DefineID.TypeSpecificID = new_Skin.baglv1;
                     break;
     }
     }
    }
     if (ID == 501002){
for (int i = 0; i < sizeof(bag222) / sizeof(bag222[0]); i++) {
                 if (ID == bag222[i]) {
                     bag[j].Unit.DefineID.TypeSpecificID = new_Skin.baglv2;
                     break;
     }
     }
    }
     if (ID == 501003){
for (int i = 0; i < sizeof(bag333) / sizeof(bag333[0]); i++) {
                 if (ID == bag333[i]) {
                     bag[j].Unit.DefineID.TypeSpecificID = new_Skin.baglv3;
                     break;
     }
     }
    }
    
    
    
    
    
    
     if (ID == 502001){
for (int i = 0; i < sizeof(Helmet1) / sizeof(Helmet1[0]); i++) {
                 if (ID == Helmet1[i]) {
                     bag[j].Unit.DefineID.TypeSpecificID = new_Skin.helmetlv1;
                     break;
                  }
     }
    }
    
     if (ID == 502002){
for (int i = 0; i < sizeof(Helmet2) / sizeof(Helmet2[0]); i++) {
                 if (ID == Helmet2[i]) {
                     bag[j].Unit.DefineID.TypeSpecificID = new_Skin.helmetlv2;
                     break;
                  }
     }
    }
     if (ID == 502003){
for (int i = 0; i < sizeof(Helmet3) / sizeof(Helmet3[0]); i++) {
                 if (ID == Helmet3[i]) {
                     bag[j].Unit.DefineID.TypeSpecificID = new_Skin.helmetlv3;
                     break;
                  }
     }
    }
    
    
    
    
    
    
    
            }
        }
        }

        */
        
if (Config.SkinEnable){
	 if (localPlayer->WeaponManagerComponent != 0) {
     if (localPlayer->WeaponManagerComponent->CurrentWeaponReplicated != 0 ) {
         int weapowep = localPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponID();
		auto currentTime = std::chrono::steady_clock::now();
         auto landchud = localPlayer->WeaponManagerComponent->CurrentWeaponReplicated->synData;
         auto timeDiff = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastWeaponChangeTime).count();
         if (timeDiff > 1000) {
         for (int j = 0; j < landchud.Num(); j++) {
             auto& weaponInfo = landchud[j];
             auto weaponid = weaponInfo.DefineID.TypeSpecificID;
             if (weaponid != 0)
             {
             
             
             
				 if (weapowep == 101001){
				 for (int i = 0; i < sizeof(akmv) / sizeof(akmv[0]); i++) {
                 if (weaponid == akmv[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.AKM;
                     break;
                  }
				 }
				 for (int i = 0; i < sizeof(akmmag) / sizeof(akmmag[0]); i++) {
                 if (weaponid == akmmag[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.AKM_Mag;
                     break;
                  }
				 }
				}
			  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				if (weapowep == 103001){
				 for (int i = 0; i < sizeof(kar) / sizeof(kar[0]); i++) {
                 if (weaponid == kar[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.K98;
                     break;
                  }
				 }
				}
				if (weapowep == 103002){
				 for (int i = 0; i < sizeof(m24) / sizeof(m24[0]); i++) {
                 if (weaponid == m24[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M24;
                     break;
                  }
				 }
				}
	    	  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				if (weapowep == 103003){
				 for (int i = 0; i < sizeof(awm) / sizeof(awm[0]); i++) {
                 if (weaponid == awm[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.AWM;
                     break;
                  }
				 }
				}
	    	  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	    	  
	    		if (weapowep == 103012){
				 for (int i = 0; i < sizeof(amr) / sizeof(amr[0]); i++) {
                 if (weaponid == amr[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.AMR;
                     break;
                  }
				 }
				}
	    	  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	    	  if (weapowep == 103007){
				 for (int i = 0; i < sizeof(mk14) / sizeof(mk14[0]); i++) {
                 if (weaponid == mk14[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.MK14;
                     break;
                  }
				 }
				}
				
	    	  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	    	  
	    	
	    	  
	    	  
				if (weapowep == 101102){
				 for (int i = 0; i < sizeof(ace32) / sizeof(ace32[0]); i++) {
                 if (weaponid == ace32[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.ACE32;
                     break;
                  }
				 }
				}
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				if (weapowep == 102003){
				 for (int i = 0; i < sizeof(vector2) / sizeof(vector2[0]); i++) {
                 if (weaponid == vector2[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.Vector;
                     break;
                  }
				 }
				}
				///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				if (weapowep == 102002){
				 for (int i = 0; i < sizeof(ump) / sizeof(ump[0]); i++) {
                 if (weaponid == ump[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.UMP;
                     break;
                  }
				 }
				}
				///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				if (weapowep == 102001){
				 for (int i = 0; i < sizeof(uzi) / sizeof(uzi[0]); i++) {
                 if (weaponid == uzi[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.UZI;
                     break;
                  }
				 }
				}
				///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				if (weapowep == 101002){
				 for (int i = 0; i < sizeof(m16) / sizeof(m16[0]); i++) {
                 if (weaponid == m16[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M16A4;
                     break;
                  }
				 }
				 for (int i = 0; i < sizeof(m16s) / sizeof(m16s[0]); i++) {
                 if (weaponid == m16s[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M16A4_Stock;
                     break;
                  }
				 }
				 for (int i = 0; i < sizeof(m16mag) / sizeof(m16mag[0]); i++) {
                 if (weaponid == m16mag[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M16A4_Mag;
                     break;
                  }
				 }
				}
				///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				
				if (weapowep == 101006){
				 for (int i = 0; i < sizeof(aug) / sizeof(aug[0]); i++) {
                 if (weaponid == aug[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.AUG;
                     break;
                  }
				 }
				}
					///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				if (weapowep == 101005){
				 for (int i = 0; i < sizeof(groza) / sizeof(groza[0]); i++) {
                 if (weaponid == groza[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.Groza;
                     break;
                  }
				 }
				}
                
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
				if (weapowep == 105002){
				 for (int i = 0; i < sizeof(dp) / sizeof(dp[0]); i++) {
                 if (weaponid == dp[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.DP28;
                     break;
                  }
				 }
				}
				if (weapowep == 105001){
				 for (int i = 0; i < sizeof(m249) / sizeof(m249[0]); i++) {
                 if (weaponid == m249[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M249;
                     break;
                  }
				 }
				}
				///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
				
					if (weapowep == 105010){
				 for (int i = 0; i < sizeof(mg3) / sizeof(mg3[0]); i++) {
                 if (weaponid == mg3[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.MG3;
                     break;
                  }
				 }
				}
				///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
				
				
				
				
				if (weapowep == 101003){
				 for (int i = 0; i < sizeof(scar) / sizeof(scar[0]); i++) {
                 if (weaponid == scar[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.Scar;
                     break;
                  }
				 }
				 for (int i = 0; i < sizeof(scarmag) / sizeof(scarmag[0]); i++) {
                 if (weaponid == scarmag[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.Scar_Mag;
                     break;
                  }
				 }
				}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
				if (weapowep == 101008){
				 for (int i = 0; i < sizeof(m7) / sizeof(m7[0]); i++) {
                 if (weaponid == m7[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M762;
                     break;
                  }
				 }
				 for (int i = 0; i < sizeof(m7mag) / sizeof(m7mag[0]); i++) {
                 if (weaponid == m7mag[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M762_Mag;
                     break;
                  }
				 }
				}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
        
    
                 if (weapowep == 101004){
                 for (int i = 0; i < sizeof(M4161) / sizeof(M4161[0]); i++) {
                 if (weaponid == M4161[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_1;
                     break;
                  }
                 }
                 
                 for (int i = 0; i < sizeof(M4162) / sizeof(M4162[0]); i++) {
                 if (weaponid == M4162[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_2;
                     break;
                  }
                 }
                 
                 for (int i = 0; i < sizeof(M4163) / sizeof(M4163[0]); i++) {
                 if (weaponid == M4163[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_3;
                     break;
                  }
                  }
                 
                 for (int i = 0; i < sizeof(m4stock) / sizeof(m4stock[0]); i++) {
                 if (weaponid == m4stock[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_4;
                     break;
                  }
                 }
                
                 for (int i = 0; i < sizeof(M416flash) / sizeof(M416flash[0]); i++) {
                 if (weaponid == M416flash[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_flash;
                 break;
                 }
                 }
                 
                 for (int i = 0; i < sizeof(M416compe) / sizeof(M416compe[0]); i++) {
                 if (weaponid == M416compe[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_compe;
                 break;
                 }
                 }
                 
                 for (int i = 0; i < sizeof(M416silent) / sizeof(M416silent[0]); i++) {
                 if (weaponid == M416silent[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_silent;
                 break;
                 }
                 }
                 /*
                 for (int i = 0; i < sizeof(M416reddot) / sizeof(M416reddot[0]); i++) {
                 if (weaponid == M416reddot[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_reddot;
                 break;
                 }
                 }
                 */
                 for (int i = 0; i < sizeof(M416holo) / sizeof(M416holo[0]); i++) {
                 if (weaponid == M416holo[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_holo;
                 break;
                 }
                 }
                
                 for (int i = 0; i < sizeof(M416x2) / sizeof(M416x2[0]); i++) {
                 if (weaponid == M416x2[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_x2;
                 break;
                 }
                 }
                 
                 for (int i = 0; i < sizeof(M416x3) / sizeof(M416x3[0]); i++) {
                 if (weaponid == M416x3[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_x3;
                 break;
                 }
                 }
                 
                 for (int i = 0; i < sizeof(M416x4) / sizeof(M416x4[0]); i++) {
                 if (weaponid == M416x4[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_x4;
                 break;
                 }
                 }
                 
                 for (int i = 0; i < sizeof(M416x6) / sizeof(M416x6[0]); i++) {
                 if (weaponid == M416x6[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_x6;
                 break;
                 }
                 }
                 
                 for (int i = 0; i < sizeof(M416quickMag) / sizeof(M416quickMag[0]); i++) {
                 if (weaponid == M416quickMag[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_quickMag;
                 break;
                 }
                 }
                 
                 for (int i = 0; i < sizeof(M416extendedMag) / sizeof(M416extendedMag[0]); i++) {
                 if (weaponid == M416extendedMag[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_extendedMag;
                 break;
                 }
                 }
                 
                 for (int i = 0; i < sizeof(M416quickNextended) / sizeof(M416quickNextended[0]); i++) {
                 if (weaponid == M416quickNextended[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_quickNextended;
                 break;
                 }
                 }
                 
                 for (int i = 0; i < sizeof(M416stock) / sizeof(M416stock[0]); i++) {
                 if (weaponid == M416stock[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_stock;
                 break;
                 }
                 }
                 /*
                 for (int i = 0; i < sizeof(M416verical) / sizeof(M416verical[0]); i++) {
                 if (weaponid == M416verical[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_verical;
                 break;
                 }
                 }
                 */
                 for (int i = 0; i < sizeof(M416angle) / sizeof(M416angle[0]); i++) {
                 if (weaponid == M416angle[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_angle;
                 break;
                 }
                 }
                 /*
                 for (int i = 0; i < sizeof(M416lightgrip) / sizeof(M416lightgrip[0]); i++) {
                 if (weaponid == M416lightgrip[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_lightgrip;
                 break;
                 }
                 }
                 
                 for (int i = 0; i < sizeof(M416pink) / sizeof(M416pink[0]); i++) {
                 if (weaponid == M416pink[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_pink;
                 break;
                 }
                 }
                 
                 for (int i = 0; i < sizeof(M416lazer) / sizeof(M416lazer[0]); i++) {
                 if (weaponid == M416lazer[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_lazer;
                 break;
                 }
                 }
                 */
                 for (int i = 0; i < sizeof(M416thumb) / sizeof(M416thumb[0]); i++) {
                 if (weaponid == M416thumb[i]) {
                 weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_thumb;
                 break;
                 }
                 }
                 }
                 
        /*
				if (weapowep == 101004){
				 for (int i = 0; i < sizeof(m4v) / sizeof(m4v[0]); i++) {
                 if (weaponid == m4v[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_1;
                     break;
                  }
				 }
                 }
                 if (weapowep == 291004){
				 for (int i = 0; i < sizeof(m4mag) / sizeof(m4mag[0]); i++) {
                 if (weaponid == m4mag[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_2;
                     break;
                  }
				 }
                 }
                  if (weapowep == 203008){
				 for (int i = 0; i < sizeof(m4sight) / sizeof(m4sight[0]); i++) {
                 if (weaponid == m4sight[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_3;
                     break;
                  }
                  }
				 }
                    if (weapowep == 205005){
				 for (int i = 0; i < sizeof(m4stock) / sizeof(m4stock[0]); i++) {
                 if (weaponid == m4stock[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_4;
                     break;
                  }
				 }
                 }
                   if (weapowep == 205002){
				 for (int i = 0; i < sizeof(m4stock1) / sizeof(m4stock1[0]); i++) {
                 if (weaponid == m4stock1[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_stock;
                     break;
                  }
				 }
                 }
                   if (weapowep == 203001){
				 for (int i = 0; i < sizeof(m4reddot) / sizeof(m4reddot[0]); i++) {
                 if (weaponid == m4reddot[i]) {
                     weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_reddot;
                     break;
                  }
				 }
				 }
                 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
				 
				 
				 
				 
				 
				 
				 
				 
				}
                 localPlayer->WeaponManagerComponent->CurrentWeaponReplicated->DelayHandleAvatarMeshChanged();
                 lastWeaponChangeTime = currentTime;
             }
         }
     }
 }
}





  if (Config.CarMod){

if (localPlayer -> CurrentVehicle) {
        if (localPlayer -> CurrentVehicle -> VehicleAvatar) {
          std::string SkinIDStr = std::to_string((int) localPlayer -> CurrentVehicle -> VehicleAvatar -> GetDefaultAvatarID());
          Active::SkinCarDefault = localPlayer -> CurrentVehicle -> GetAvatarID();

          
          if (strstr(SkinIDStr.c_str(), "1901")) {
            Active::SkinCarMod = new_Skin.Moto;
            Active::SkinCarNew = true;
          } else if (strstr(SkinIDStr.c_str(), "1903")) {
            Active::SkinCarMod = new_Skin.Dacia;
            Active::SkinCarNew = true;
          } else if (strstr(SkinIDStr.c_str(), "1911")) {
            Active::SkinCarMod = new_Skin.Boat;
            Active::SkinCarNew = true;
          } else if (strstr(SkinIDStr.c_str(), "1904")) {
            Active::SkinCarMod = new_Skin.MiniBus;
            Active::SkinCarNew = true;
          } else if (strstr(SkinIDStr.c_str(), "1914")) {
            Active::SkinCarMod = new_Skin.Mirado;
            Active::SkinCarNew = true;
          } else if (strstr(SkinIDStr.c_str(), "1915")) {
            Active::SkinCarMod = new_Skin.Mirado;
            Active::SkinCarNew = true;
          } else if (strstr(SkinIDStr.c_str(), "1907")) {
            Active::SkinCarMod = new_Skin.Buggy;
            Active::SkinCarNew = true;
          }else if (strstr(SkinIDStr.c_str(), "1961")) {
            Active::SkinCarMod = new_Skin.CoupeRP;
            Active::SkinCarNew = true;
          } else if (strstr(SkinIDStr.c_str(), "1953")) {
            Active::SkinCarMod = new_Skin.Bigfoot;
            Active::SkinCarNew = true;
          } else if (strstr(SkinIDStr.c_str(), "1908")) {
            Active::SkinCarMod = new_Skin.UAZ;
            Active::SkinCarNew = true;
          } else Active::SkinCarNew = false;

          if (Active::SkinCarDefault != Active::SkinCarMod && Active::SkinCarNew) {
            
            localPlayer -> CurrentVehicle -> VehicleAvatar -> ChangeItemAvatar(Active::SkinCarMod, true);
          }
        }
      }

      }
    
      
      
      
    
               
                        auto PlayerCameraManager = localPlayerController->PlayerCameraManager;
        
                    
                    CameraCache =PlayerCameraManager->CameraCache;
        
                    int totalEnemies = 0, totalBots = 0;
                    
                    /*
                if (Config.PlayerESP.Radar) {
                            bool out = false;
                            struct Vector3 Pos;
                            Pos.X = ScreenWidth / 4.395;
                            Pos.Y = ScreenHeight / 40;
                            struct Vector3 Size;
                            Size.X = 200;
                            Size.Y = 210;    
                            float RadarCenterX = Pos.X + (Size.X / 2);
                            float RadarCenterY = Pos.Y + (Size.Y / 2);
                           DrawLine(HUD, FVector2D(RadarCenterX, RadarCenterY), FVector2D(RadarCenterX, Pos.Y), 1, COLOR_WHITE);
                            DrawLine(HUD, FVector2D(RadarCenterX, RadarCenterY), FVector2D(Pos.X , RadarCenterY), 1, COLOR_WHITE);
                            DrawLine(HUD, FVector2D(Pos.X, RadarCenterY), FVector2D(Pos.X + Size.X, RadarCenterY), 1, COLOR_WHITE);
                            DrawLine(HUD, FVector2D(RadarCenterX, RadarCenterY), FVector2D(RadarCenterX, Pos.Y + Size.Y), 1, COLOR_WHITE); 
                            DrawLine(HUD, FVector2D{RadarCenterX + 74, RadarCenterY - 74}, FVector2D{RadarCenterX, RadarCenterY}, 1, COLOR_WHITE);
                            DrawLine(HUD, FVector2D{RadarCenterX - 74, RadarCenterY - 74}, FVector2D{RadarCenterX, RadarCenterY}, 1, COLOR_WHITE);
                            DrawLine(HUD, FVector2D{RadarCenterX, RadarCenterY}, FVector2D{RadarCenterX, RadarCenterY}, 1, COLOR_WHITE);
                            //绘制圆圈-内部
                            DrawFilledCircle77(HUD, RadarCenterX, RadarCenterY, 40.f, COLOR_RED);
                            //绘制圆圈-中间
                            DrawFilledCircle77(HUD, RadarCenterX + 0.5f, RadarCenterY + 0.5f, 40.f, COLOR_LIME);
                            DrawCircle(HUD, RadarCenterX, RadarCenterY, 102.f, 100.0f, COLOR_WHITE);
                         //   DrawCircle33(HUD, screenWidth / 2, screenHeight / 2, Config.AimBot.Cross, 1.0f, COLOR_THISTLE);

                            
                            //绘制雷达内部线条
                            
                        }
                        */
                   std::vector<ASTExtraPlayerCharacter *> PlayerCharacter;
                    GetAllActors(PlayerCharacter);
     //int IntCount = 0;
                    for (auto actor = PlayerCharacter.begin(); actor != PlayerCharacter.end(); actor++)
                    {
                                auto Player = *actor;
                        if (Player->PlayerKey == localPlayer->PlayerKey)
                            continue;
                        if (Player->TeamID == localPlayer->TeamID)
                            continue;
                        if (Player->bDead)
                            continue;
                        if (Player->bHidden)
                            continue;
            if (!Player->Mesh)
continue;
if (Player->Health < 0.0f || Player->Health > 10000000.0f ) { continue; }

               
                        if (Config.Hidebot)
                        {
                            if (Player->bEnsure)
                                continue;
                        }
                    
                        if (Player->bEnsure)
                            totalBots++;
                        else
                            totalEnemies++;
                            
                          if (Player->IsInvincible)
                               IntCount ++;
                            
                            auto colV = FLinearColor();
                            
                    auto colV2 = FLinearColor();
                    auto colV4 = FLinearColor();
                    
                    
                    auto ColorHP = FLinearColor();
                    
                    auto ColorHP2 = FLinearColor();
                    
                    auto boxcolor = FLinearColor();
                    
                    FVector HeadNrg5 = GetBoneLocationByName(Player, "Head");
                
                        if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,HeadNrg5, true)) {    
                        colV = COLOR_RED;
                        
                        boxcolor = COLOR_RED;
                        colV4 = COLOR_RED2;
                    }else{
                        colV = COLOR_LIME;
                      boxcolor = COLOR_LIME;
                        colV4 = COLOR_LIME2;
                        
                    }
                            
                         if (Player->bEnsure) {
                          //  totalBots++;
                            colV2 = COLOR_WHITE;
                            ColorHP = COLOR_LIME;
                            ColorHP2 = {0, 1.f, 0, 0.705f};
                        }else{
                          //  totalEnemies++;
                          colV2 = COLOR_YELLOW;
                          ColorHP = COLOR_RED;
                          ColorHP2 = {1.f, 0, 0, 0.705f};
                    
                    }
                    
                   
                      if (Player->IsInvincible)
                            {
                                //yallow
                                boxcolor = COLOR_YELLOW;
                                
                            }
                    
                                         bool IsVisible = localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,HeadNrg5, true);
                            if(IsVisible) {
                                if(Player->bEnsure){
                                    //white color
                                    visCol.R = 1.f;
                                    visCol.G = 1.f;
                                    visCol.B = 1.f;
                                    visCol.A = 1.f;
                                }else if(Player->Health == 0.0f){
                                    //drak green if knock down and visible
                                    visCol.R = 0.0f;
                                    visCol.G = 0.3f;
                                    visCol.B = 0.0f;
                                    visCol.A = 1.0f;
                                }else{
                                    //green
                                    visCol.R = 0.f;
                                    visCol.G = 1.f;
                                    visCol.B = 0.f;
                                    visCol.A = 1.f;
                                }
                            }else if (Player->bEnsure){
                                //gray R G B A
                                //    FLinearColor Gray = { 0.501960814f, 0.501960814f, 0.501960814f, 1.000000000f };
                                visCol.R = 0.435294117f;
                                visCol.G = 0.501960814f;
                                visCol.B = 0.501960814f;
                                visCol.A = 1.000000000f;
                                // if knocked down player color
                            }else if(Player->Health == 0.0f){
                                //drak++ red if knocked down and not visible
                                visCol.R = 0.549019607f;
                                visCol.G = 0.039215686f;
                                visCol.B = 0.050980392f;
                                visCol.A = 1.0f;
                            }else{
                                //red
                                visCol.R = 1.f;
                                visCol.G = 0.f;
                                visCol.B = 0.f;
                                visCol.A = 1.f;
                            }
                            if (Player->IsInvincible)
                            {
                                //yallow
                                visCol.R = 1.f;
                                visCol.G = 1.f;
                                visCol.B = 0.f;
                                visCol.A = 1.f;
                            }
                    
                               if (Config.PlayerESP.Alert)
                            {
                              auto AboveHead = Player->GetHeadLocation(true);
                                    
                                    FVector2D AboveHeadSc;
         bool shit = false;
         FVector MyPosition, EnemyPosition;
                            ASTExtraVehicleBase * CurrentVehiclea = Player->CurrentVehicle;
                            if (CurrentVehiclea) {
                                MyPosition = CurrentVehiclea->RootComponent->RelativeLocation;
                            } else {
                                MyPosition = Player->RootComponent->RelativeLocation;
                            }
                            ASTExtraVehicleBase * CurrentVehicle = localPlayer->CurrentVehicle;
                            if (CurrentVehicle) {
                                EnemyPosition = CurrentVehicle->RootComponent->RelativeLocation;
                            } else {
                                EnemyPosition = localPlayer->RootComponent->RelativeLocation;
                            }
                            FVector EntityPos = WorldToRadar(localPlayerController->PlayerCameraManager->CameraCache.POV.Rotation.Yaw, MyPosition, EnemyPosition, NULL, NULL, Vector3(screenWidth, screenHeight, 0), shit);
                            FVector angle = FVector();
                            Vector3 forward = Vector3((float)(screenWidth / 2) - EntityPos.X, (float)(screenHeight / 2) - EntityPos.Y, 0.0f);
                        //    VectorAnglesRadar2(forward, angle);
                        VectorAnglesRadar(forward, angle);
                            const auto angle_yaw_rad = DEG2RAD(angle.Y + 180.f);//90
                            const auto new_point_x = (screenWidth / 2) + (70) / 2 * 8 * cosf(angle_yaw_rad);
                            const auto new_point_y = (screenHeight / 2) + (70) / 2 * 8 * sinf(angle_yaw_rad);
                           // std::array<Vector3, 3> points { Vector3(new_point_x - ((90) / 4 + 3.5f) / 2, new_point_y - ((55) / 4 + 3.5f) / 2, 0.f), Vector3(new_point_x + ((90) / 4 + 3.5f) / 4, new_point_y, 0.f), Vector3(new_point_x - ((90) / 4 + 3.5f) / 2, new_point_y + ((55) / 4 + 3.5f) / 2, 0.f)};
                      //      std::array<Vector3, 3> points { Vector3(new_point_x - ((110) / 4 + 3.5f) / 2, new_point_y - ((55) / 4 + 3.5f) / 2, 0.f), Vector3(new_point_x + ((110) / 4 + 3.5f) / 4, new_point_y, 0.f), Vector3(new_point_x - ((110) / 4 + 3.5f) / 2, new_point_y + ((55) / 4 + 3.5f) / 2, 0.f)};
                         //   std::array<Vector3, 3> points { Vector3(new_point_x - ((45) / 4 + 3.5f) / 2, new_point_y - ((55) / 4 + 3.5f) / 2, 0.f), Vector3(new_point_x + ((45) / 4 + 3.5f) / 4, new_point_y, 0.f), Vector3(new_point_x - ((45) / 4 + 3.5f) / 2, new_point_y + ((55) / 4 + 3.5f) / 2, 0.f)};
                            
                         std::array < FVector2D, 39 > points
                                {
                                    
                  FVector2D((float)new_point_x - (5.6f * (float)1.7f), new_point_y - (7.3f *1.7f)),
                  FVector2D((float)new_point_x + (11.6f *1.7f), new_point_y),
                  FVector2D((float)new_point_x - (5.6f *1.7f), new_point_y + (7.3f *1.7f)),
                  FVector2D((float)new_point_x - (5.6f *1.7f), new_point_y - (4.3f *1.7f)),
                  FVector2D((float)new_point_x - (19.5f *1.7f), new_point_y - (4.3f *1.7f)),
                  FVector2D((float)new_point_x - (19.5f *1.7f), new_point_y + (4.3f *1.7f)),
                  FVector2D((float)new_point_x - (5.6f *1.7f), new_point_y + (4.3f *1.7f)),
                  
                  FVector2D((float)new_point_x + (10.3f *1.7f), new_point_y),
                  FVector2D((float)new_point_x - (5.f *1.7f), new_point_y - (3.5f *1.7f)),
                  FVector2D((float)new_point_x - (5.f *1.7f), new_point_y + (3.5f *1.7f)),
                  
                  FVector2D((float)new_point_x - (5.f * (float)1.7f), new_point_y - (6.5f *1.7f)),
                  FVector2D((float)new_point_x - (5.f * (float)1.7f), new_point_y - (5.5f *1.7f)),
                  FVector2D((float)new_point_x - (5.f * (float)1.7f), new_point_y - (4.5f *1.7f)),
                  FVector2D((float)new_point_x - (5.f * (float)1.7f), new_point_y - (3.5f *1.7f)),
                  FVector2D((float)new_point_x - (5.f * (float)1.7f), new_point_y - (2.5f *1.7f)),
                  FVector2D((float)new_point_x - (5.f * (float)1.7f), new_point_y - (1.5f *1.7f)),
                  FVector2D((float)new_point_x - (5.f * (float)1.7f), new_point_y - (0.5f *1.7f)),
                  FVector2D((float)new_point_x - (5.f * (float)1.7f), new_point_y + (6.5f *1.7f)),
                  FVector2D((float)new_point_x - (5.f * (float)1.7f), new_point_y + (5.5f *1.7f)),
                  FVector2D((float)new_point_x - (5.f * (float)1.7f), new_point_y + (4.5f *1.7f)),

                     FVector2D((float)new_point_x - (5.f * (float)1.7f), new_point_y + (3.5f *1.7f)),
                                   FVector2D((float)new_point_x - (5.f * (float)1.7f), new_point_y + (2.5f *1.7f)),
                                   FVector2D((float)new_point_x - (5.f * (float)1.7f), new_point_y + (1.5f *1.7f)),
                                   FVector2D((float)new_point_x - (5.f * (float)1.7f), new_point_y),
                                   FVector2D((float)new_point_x - (5.f * (float)1.7f), new_point_y + (0.2f *1.7f)),
                                   FVector2D((float)new_point_x - (5.f * (float)1.7f), new_point_y - (0.2f *1.7f)),
                                   
                                   FVector2D((float)new_point_x - (18.5f *1.7f), new_point_y - (3.75f *1.7f)),
                                   FVector2D((float)new_point_x - (18.5f *1.7f), new_point_y - (3.f *1.7f)),
                                   FVector2D((float)new_point_x - (18.5f *1.7f), new_point_y - (1.7f *1.7f)),
                                   FVector2D((float)new_point_x - (18.5f *1.7f), new_point_y - (1.f *1.7f)),
                                   FVector2D((float)new_point_x - (18.5f *1.7f), new_point_y - (0.5f *1.7f)),
                                   FVector2D((float)new_point_x - (18.5f *1.7f), new_point_y - (0.2f *1.7f)),
                                   FVector2D((float)new_point_x - (18.5f *1.7f), new_point_y),
                                   FVector2D((float)new_point_x - (18.5f *1.7f), new_point_y + (3.75f *1.7f)),
                                   FVector2D((float)new_point_x - (18.5f *1.7f), new_point_y + (3.f *1.7f)),
                                   FVector2D((float)new_point_x - (18.5f *1.7f), new_point_y + (1.7f *1.7f)),
                                   FVector2D((float)new_point_x - (18.5f *1.7f), new_point_y + (1.f *1.7f)),
                                   FVector2D((float)new_point_x - (18.5f *1.7f), new_point_y + (0.5f *1.7f)),
                                   FVector2D((float)new_point_x - (18.5f *1.7f), new_point_y + (0.2f *1.7f)),
                     
                                };

                         
                     //       RotateTriangle2(points, angle.Y + 180.f);
                                 
                                  if (gGameplayStatics->ProjectWorldToScreen(localPlayerController, AboveHead, false,  &AboveHeadSc)) {
                                    
                             // 
                             
                            }else{
                                
                                
                                   
                                    
             
                                    
                                    RotateTriangle55(points, angle.Y + 180.f);
                                    float Thickness = 1.7f;
                                  
                          
                                    DrawArrows(HUD,points, Thickness, colV4);
                                
                                
                                
                                
                                
                                
                    //       DrawArrow(HUD, {points.at(0).X,points.at(0).Y},{points.at(1).X,points.at(1).Y},{points.at(2).X,points.at(2).Y}, 3.f, colV);
                            }
                     }
                            
                           /*
                    //绘制雷达
                        if (Config.PlayerESP.Radar) {
                            bool out = false;
                            struct Vector3 Pos;
                            Pos.X = ScreenWidth / 4.395;
                            Pos.Y = ScreenHeight / 40;
                            struct Vector3 Size;
                            Size.X = 200;
                            Size.Y = 210;    
                            float RadarCenterX = Pos.X + (Size.X / 2);
                            float RadarCenterY = Pos.Y + (Size.Y / 2);
                            FVector MyPosition, EnemyPosition;
                            ASTExtraVehicleBase * CurrentVehiclea = Player->CurrentVehicle;
                            
                            if (CurrentVehiclea) {
                                MyPosition = CurrentVehiclea->RootComponent->RelativeLocation;
                            } else {
                                MyPosition = Player->RootComponent->RelativeLocation;
                            }
                            
                            ASTExtraVehicleBase * CurrentVehicle = localPlayer->CurrentVehicle;
                            if (CurrentVehicle) {
                                EnemyPosition = CurrentVehicle->RootComponent->RelativeLocation;
                            } else {
                                EnemyPosition = localPlayer->RootComponent->RelativeLocation;
                            }
                            FVector RadarSketch = WorldToRadar(localPlayerController->PlayerCameraManager->CameraCache.POV.Rotation.Yaw, MyPosition, EnemyPosition, Pos.X, Pos.Y, Vector3(Size.X, Size.Y, 0), out);
               
                            //绘制雷达内部线条
                            DrawFilledCircleM(HUD, FVector2D{RadarSketch.X,RadarSketch.Y}, 4.0, colV);
                        }
                            */
                          float Distance = Player->GetDistanceTo(localPlayer) / 100.f;
                        if (Distance < 1000.f)
                        {
                            /*
                                        float magic_number = (Distance);
float mx = (screenWidth / 4) / magic_number;
float healthLength = screenWidth / 17;
if (healthLength < mx)
healthLength = mx;

                        FVector HeadPos2 = GetBoneLocationByName(Player, "Head");
                        HeadPos2.Z += 17.5f;//16.5f;
                        FVector RootPos2 = GetBoneLocationByName(Player, "Root");
                        RootPos2.Z -= 6.5f;//5.5f;
                    //targetAimPos.Z -= 25.f;
                      auto Head_RootZ = HeadPos2.Z - RootPos2.Z;
                        */
                            FVector HeadPos2 = GetBoneLocationByName(Player, "Head");
                        HeadPos2.Z += 17.5f;//16.5f;
                        FVector RootPos2 = GetBoneLocationByName(Player, "Root");
                        RootPos2.Z -= 6.5f;//5.5f;
                    //targetAimPos.Z -= 25.f;
                      auto Head_RootZ = HeadPos2.Z - RootPos2.Z;
                            
                      
                        FVector Head = GetBoneLocationByName(Player, "Head");
                   //     Head.Z += 12.5f;
                        FVector Root = GetBoneLocationByName(Player, "Root");
                        FVector Head66 = GetBoneLocationByName(Player, "Head");
                        /*
                              float magic_number = (Distance);
                    float mx = (SizeX / 4) / magic_number;

                    float healthLength = SizeX / 19;
                    if (healthLength < mx)
                        healthLength = mx;
*/
                        FVector uparmr = GetBoneLocationByName(Player, "upperarm_r");
                        FVector uparml = GetBoneLocationByName(Player, "upperarm_l");
                        FVector lowarmr = GetBoneLocationByName(Player, "lowerarm_r");
                        FVector lowarml = GetBoneLocationByName(Player, "lowerarm_l");
                        FVector handr = GetBoneLocationByName(Player, "hand_r");
                        FVector handl = GetBoneLocationByName(Player, "hand_l");
                        FVector itemr = GetBoneLocationByName(Player, "item_r");
                        FVector iteml = GetBoneLocationByName(Player, "item_l");
                        
                        
                        
                        FVector clavicler = GetBoneLocationByName(Player, "clavicle_r");
                        FVector claviclel = GetBoneLocationByName(Player, "clavicle_l");
                        
                        FVector neck = GetBoneLocationByName(Player, "neck_01");
                        FVector spain01 = GetBoneLocationByName(Player, "spine_01");
                        FVector spain02 = GetBoneLocationByName(Player, "spine_02");
                        FVector spain03 = GetBoneLocationByName(Player, "spine_03");
                        FVector pelvis = GetBoneLocationByName(Player, "Pelvis");
                        
                        FVector calfl = GetBoneLocationByName(Player, "calf_l");
                        FVector calfr = GetBoneLocationByName(Player, "calf_r");
                        FVector thighl = GetBoneLocationByName(Player, "thigh_l");
                        FVector thighr = GetBoneLocationByName(Player, "thigh_r");
                        
                        
                        
                        FVector footr = GetBoneLocationByName(Player, "foot_r");
                        FVector footl = GetBoneLocationByName(Player, "foot_l");
                        
                        FVector2D uparmrSC, uparmlSC, lowarmrSC, lowarmlSC, handrSC, handlSC, itemrSC, itemlSC, upperarmtwist01rSC, upperarmtwist01lSC, claviclerSC, claviclelSC, neckSC, spain01SC, spain02SC, spain03SC, pelvisSC;
                        FVector2D calflSC,calfrSC,thighlSC,thighrSC,calftwist01lSC,calftwist01rSC,thightwist01lSC,thightwist01rSC,footrSC,footlSC,lowerarmtwist01lSC,lowerarmtwist01rSC;
                        
                        
                        
                        
                       
                        
                //     auto HeadNrg = Player->GetBonePos("Head", {});
                
                
                     FVector HeadNrg = GetBoneLocationByName(Player, "Head");
                     HeadNrg.Z += 35.f;
                    FVector2D HeadNrgSc;
                    HeadNrgSc =  WorldToScreen(HeadNrg, CameraCache.POV, ScreenWidthNrg6, ScreenHeightNrg6);
             
                        
                        
                      
                        
                    
                            FVector2D HeadSc, RootSc;
                            
                                        if (Config.PlayerESP.Line) {
                               if (LINE360N180 == 0) {
                                        auto mWidthScale = std::min(0.006f * Distance, 100.f);
                                    auto mWidth = 20.f - mWidthScale;
                                    auto mHeight = mWidth * 0.125f;
                                    
                                    HeadNrgSc.Y -= (mHeight * 1.4f + 15);
                            
                     Canvas->K2_DrawLine({(float)screenWidth/2 , 10}, {HeadNrgSc.X , HeadNrgSc.Y - 25.5}, 1, colV);//25.5 / 20
          }
                            
                       }
                     
                            
                            //if (gGameplayStatics->ProjectWorldToScreen(localPlayerController, Head, false, &HeadSc) && gGameplayStatics->ProjectWorldToScreen(localPlayerController, Root, false, &RootSc))
                          if(W2S(Head, (FVector2D *) & HeadSc) && W2S(Root, (FVector2D *) & RootSc) &&W2S(uparmr, (FVector2D *) & uparmrSC) && W2S(uparml, (FVector2D *) & uparmlSC) &&W2S(lowarml, (FVector2D *) & lowarmlSC) &&W2S(lowarmr, (FVector2D *) & lowarmrSC) &&W2S(handr, (FVector2D *) & handrSC)&&W2S(handl, (FVector2D *) & handlSC) &&W2S(itemr, (FVector2D *) & itemrSC)&&W2S(iteml, (FVector2D *) & itemlSC)&&W2S(clavicler, (FVector2D *) & claviclerSC)&&W2S(claviclel, (FVector2D *) & claviclelSC) &&W2S(neck, (FVector2D *) & neckSC) &&W2S(spain01, (FVector2D *) & spain01SC) &&W2S(spain02, (FVector2D *) & spain02SC) &&W2S(spain03, (FVector2D *) & spain03SC) &&W2S(pelvis, (FVector2D *) & pelvisSC) &&W2S(calfl, (FVector2D *) & calflSC)&&W2S(calfr, (FVector2D *) & calfrSC) &&W2S(thighl, (FVector2D *) & thighlSC)&&W2S(thighr, (FVector2D *) & thighrSC)&&W2S(footr, (FVector2D *) & footrSC)&&W2S(footl, (FVector2D *) & footlSC)) {
                                
                              
                              
                                        if (Config.PlayerESP.Line) {
                               if (LINE360N180 == 1) {
                                        auto mWidthScale = std::min(0.006f * Distance, 100.f);
                                    auto mWidth = 20.f - mWidthScale;
                                    auto mHeight = mWidth * 0.125f;
                                    
                                    HeadNrgSc.Y -= (mHeight * 1.4f + 15);
                            
                     Canvas->K2_DrawLine({(float)screenWidth/2 , 10}, {HeadNrgSc.X , HeadNrgSc.Y - 25.5}, 1, colV);//25.5 / 20
          }
                            
                       }
                     
                              
                              /*
                              
                           //     if(!offscreen(HeadSc, {(float)SizeX , (float)SizeY}) ){
                              float boxHeight = abs(HeadSc.Y);
                              float boxWidth = boxHeight * 0.65f;
                        
                                
                                          if (Config.PlayerESP.Line) {
                               if (Config.EspLinetow == 1) {
                                      //  auto mWidthScale = std::min(0.006f * Distance, 100.f);
                                  //  auto mWidth = 20.f - mWidthScale;
                                  //  auto mHeight = mWidth * 0.125f;
                                    
                                 //   HeadSc.Y -= (mHeight * 1.4f + 15);
                            
              //       Canvas->K2_DrawLine({(float)SizeX/2 , 20}, {HeadSc.X , HeadSc.Y - 25.0}, 1, colV);//25.5
                     
               //      DrawLine(HUD, {(float)SizeX/2 , 20}, {HeadSc.X , HeadSc.Y - 25.0}, 1, colV);
                     
                     
                     
                               auto mWidthScale = std::min(0.006f * Distance, 100.f);
                                    auto mWidth = 20.f - mWidthScale;
                                    auto mHeight = mWidth * 0.125f;
                                    
                                    HeadNrgSc.Y -= (mHeight * 1.4f + 15);
                            
                     Canvas->K2_DrawLine({(float)screenWidth/2 , 20}, {HeadNrgSc.X , HeadNrgSc.Y - 25.0}, 1, colV);//25.5
         
          }
                            
                            }*/
                            if (Config.PlayerESP.Box3D)
                                {
                                float He_RoZ = (float) Head_RootZ;
                                     
                                     FVector BoxSize;
                                     BoxSize.X = 120.f; //65
                                     BoxSize.Y = 130.f; //80
                                     BoxSize.Z = He_RoZ + 16; //165 8
                       Box3D(HUD, Player->K2_GetActorLocation(), BoxSize, boxcolor, 1.f);        
                   }
                            
                                 if (Config.AimBot.Enable) {
                 //        DrawCircle33(HUD, pelvisSC.X, pelvisSC.Y, Config.AimBot.Cross, 1.0f, COLOR_THISTLE);
                            
                if (Config.AimTargetLine)
                {
                ASTExtraPlayerCharacter *Target = GetTargetForAimBot();
                            
                    if (Target)
                    {
                     FVector TargetPOS = GetBoneLocationByName(Target, "Head");//pelvis
                     TargetPOS.Z -= 10;
                     FVector2D TargetPOSSC;
                     if(W2S(TargetPOS, (FVector2D *) & TargetPOSSC)){
                     DrawLine(HUD, {static_cast<float>(screenWidth / 2), static_cast<float>(screenHeight / 2)}, TargetPOSSC, 1, COLOR_LIME);             
                     }
                    }
                    }
                }            
                          
                            
                            
                                if (Config.PlayerESP.Skeleton)
                                {
                                    
                                    
                                    
                                      if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,neck, true))
                                {
                                    
                               
                    
                                DrawLine(HUD, HeadSc, neckSC, 1, COLOR_RED);
                                
                                
                                }else{
                                DrawLine(HUD, HeadSc, neckSC, 1, COLOR_LIME);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,clavicler, true))
                                {
                                DrawLine(HUD, neckSC, claviclerSC, 1, COLOR_RED);
                                }else{
                                DrawLine(HUD, neckSC, claviclerSC, 1, COLOR_LIME);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,uparmr, true))
                                {
                                DrawLine(HUD, claviclerSC, uparmrSC, 1, COLOR_RED);
                                }else{
                                DrawLine(HUD, claviclerSC, uparmrSC, 1, COLOR_LIME);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,lowarmr, true))
                                {
                                DrawLine(HUD, uparmrSC, lowarmrSC, 1, COLOR_RED);
                                }else{
                                DrawLine(HUD, uparmrSC, lowarmrSC, 1, COLOR_LIME);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,handr, true))
                                {
                                DrawLine(HUD, lowarmrSC, handrSC, 1, COLOR_RED);
                                }else{
                                DrawLine(HUD, lowarmrSC, handrSC, 1, COLOR_LIME);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,itemr, true))
                                {
                                DrawLine(HUD, handrSC, itemrSC, 1, COLOR_RED);
                                }else{
                                DrawLine(HUD, handrSC, itemrSC, 1, COLOR_LIME);
                                }                                                                                               
                                                                
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,claviclel, true))
                                {
                                DrawLine(HUD, neckSC, claviclelSC, 1, COLOR_RED);
                                }else{
                                DrawLine(HUD, neckSC, claviclelSC, 1, COLOR_LIME);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,uparml, true))
                                {
                                DrawLine(HUD, claviclelSC, uparmlSC, 1, COLOR_RED);
                                }else{
                                DrawLine(HUD, claviclelSC, uparmlSC, 1, COLOR_LIME);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,lowarml, true))
                                {
                                DrawLine(HUD, uparmlSC, lowarmlSC, 1, COLOR_RED);
                                }else{
                                DrawLine(HUD, uparmlSC, lowarmlSC, 1, COLOR_LIME);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,handl, true))
                                {
                                DrawLine(HUD, lowarmlSC, handlSC, 1, COLOR_RED);
                                }else{
                                DrawLine(HUD, lowarmlSC, handlSC, 1, COLOR_LIME);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,iteml, true))
                                {
                                DrawLine(HUD, handlSC, itemlSC, 1, COLOR_RED);
                                }else{
                                DrawLine(HUD, handlSC, itemlSC, 1, COLOR_LIME);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,spain03, true))
                                {
                                DrawLine(HUD, neckSC, spain03SC, 1, COLOR_RED);
                                }else{
                                DrawLine(HUD, neckSC, spain03SC, 1, COLOR_LIME);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,spain02, true))
                                {
                                DrawLine(HUD, spain03SC, spain02SC, 1, COLOR_RED);
                                }else{
                                DrawLine(HUD, spain03SC, spain02SC, 1, COLOR_LIME);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,spain01, true))
                                {
                                DrawLine(HUD, spain02SC, spain01SC, 1, COLOR_RED);
                                }else{
                                DrawLine(HUD, spain02SC, spain01SC, 1, COLOR_LIME);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,pelvis, true))
                                {
                                DrawLine(HUD, spain01SC, pelvisSC, 1, COLOR_RED);
                                }else{
                                DrawLine(HUD, spain01SC, pelvisSC, 1, COLOR_LIME);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,thighr, true))
                                {
                                DrawLine(HUD, pelvisSC, thighrSC, 1, COLOR_RED);
                                }else{
                                DrawLine(HUD, pelvisSC, thighrSC, 1, COLOR_LIME);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,calfr, true))
                                {
                                DrawLine(HUD, thighrSC, calfrSC, 1, COLOR_RED);
                                }else{
                                DrawLine(HUD, thighrSC, calfrSC, 1, COLOR_LIME);
                                }
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,footr, true))
                                {
                                DrawLine(HUD, calfrSC, footrSC, 1, COLOR_RED);
                                }else{
                                DrawLine(HUD, calfrSC, footrSC, 1, COLOR_LIME);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,thighl, true))
                                {
                                DrawLine(HUD, pelvisSC, thighlSC, 1, COLOR_RED);
                                }else{
                                DrawLine(HUD, pelvisSC, thighlSC, 1, COLOR_LIME);
                                }
                                
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,calfl, true))
                                {
                                DrawLine(HUD, thighlSC, calflSC, 1, COLOR_RED);
                                }else{
                                DrawLine(HUD, thighlSC, calflSC, 1, COLOR_LIME);
                                }
                                if (!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,footl, true))
                                {
                                DrawLine(HUD, calflSC, footlSC, 1, COLOR_RED);
                                }else{
                                DrawLine(HUD, calflSC, footlSC, 1, COLOR_LIME);
                                }
                                
                             
                                
                                }

                                
                                /*
                if (Config.PlayerESP.EspInfo)
                {
                                   float CurHP = std::max(0.f, std::min(Player->Health, Player->HealthMax));
                                    float MaxHP = Player->HealthMax;
                            
                                    if (CurHP == 0 && !Player->bDead)
                                    {
                                    ColorHP = {1.f, 1.f, 0, 1.f};
                                        CurHP = Player->NearDeathBreath;
                                        USTCharacterNearDeathComp *NearDeatchComponent = Player->NearDeatchComponent;
                                        if (NearDeatchComponent)
                                        {
                                            MaxHP = NearDeatchComponent->BreathMax;
                                        }
                                }
                                
                                auto AboveHead = Player->GetHeadLocation(true);
                                    AboveHead.Z += 35.f;
                                    FVector2D AboveHeadSc;
                                    if (gGameplayStatics->ProjectWorldToScreen(localPlayerController, AboveHead, false, &AboveHeadSc))
                                    {
                                    
                                        
                                    
                                    
                             //     auto mWidthScale = std::min(0.0f * Distance, 20.f);//27 
                                // i use  
                               auto mWidthScale = std::min(0.0f * 24.0f, 0.0f); //100  75 50 | 24
                                //    auto mWidthScale = std::min(0.10f * Distance, 50.f);

                                    auto mWidth2 = 10.0f - mWidthScale;
                                    auto mWidth3 = 20.0f - mWidthScale;
                                    auto mWidth4 = 30.0f - mWidthScale;
                                    auto mWidth5 = 40.0f - mWidthScale;
                                    auto mWidth = 70.0f - mWidthScale;
                                    auto mWidth99 = 5.0f - mWidthScale;
                                    
                                    
                                 //   float boxHeight = abs(HeadSc.Y - RootSc.Y);
                                    auto mHeight = mWidth * 0.050f;//098f //0.07f 050f
                                    
                                    auto mHeight2 = mWidth * -0.219f; //180f
                                    
                                    AboveHeadSc.X -= (mWidth / 2);
                                  AboveHeadSc.Y -= (mHeight * 1.5f);
                                  
                                  
                                   
                                DrawFilledRectangle(HUD, {AboveHeadSc.X, AboveHeadSc.Y - 7}, mWidth, mHeight2, GetRandomColorByIndexHud(Player->TeamID));
                                DrawFilledRectangle(HUD, {AboveHeadSc.X, AboveHeadSc.Y - 7}, mWidth, mHeight, COLOR_WHITE);
                                    DrawFilledRectangle(HUD, {AboveHeadSc.X, AboveHeadSc.Y - 7}, (CurHP * mWidth / MaxHP), mHeight, ColorHP);
//DrawFilledRectangle(HUD, {AboveHeadSc.X, AboveHeadSc.Y - 7}, (CurHP * mWidth / MaxHP), mHeight, ColorHP);
                
                                  
                                    DrawRectangle(HUD, {AboveHeadSc.X, AboveHeadSc.Y - 7}, mWidth, mHeight, 1.0f, {0, 0, 0, 1.f});
                                    
                                   
                                 }
                            }
                                         */
                            
                                         
                                         
                                         
                                         
                                         
                            /*
                if (Config.PlayerESP.EspInfo)
                {
                                   float CurHP = std::max(0.f, std::min(Player->Health, Player->HealthMax));
                                    float MaxHP = Player->HealthMax;
                            
                                    if (CurHP == 0 && !Player->bDead)
                                    {
                                    ColorHP = {1.f, 1.f, 0, 1.f};
                                        CurHP = Player->NearDeathBreath;
                                        USTCharacterNearDeathComp *NearDeatchComponent = Player->NearDeatchComponent;
                                        if (NearDeatchComponent)
                                        {
                                            MaxHP = NearDeatchComponent->BreathMax;
                                        }
                                }
                                
                                auto AboveHead = Player->GetHeadLocation(true);
                                    AboveHead.Z += 35.f;
                                    FVector2D AboveHeadSc;
                                    if (gGameplayStatics->ProjectWorldToScreen(localPlayerController, AboveHead, false, &AboveHeadSc))
                                    {
                                    float mWidth = 110.0f;
                                    float mHeight = 3.5f;
                                    float mHeight2 = -14.5f;
                                    float mWidth2 = 32.0f;
                                    AboveHeadSc.X -= (mWidth / 2);
                                  AboveHeadSc.Y -= (mHeight * 1.5f);
                                  
                                  
                                
                           //     DrawFilledRectangle(HUD, HeadScreenPos, BarWidth, BarHeight, HPColor);
                                   
                           
                           
                                DrawFilledRectangle(HUD, {AboveHeadSc.X, AboveHeadSc.Y - 7}, mWidth, mHeight2, GetRandomColorByIndexHud(Player->TeamID));
                                DrawFilledRectangle(HUD, {AboveHeadSc.X, AboveHeadSc.Y - 7}, mWidth2, mHeight2, GetRandomColorByIndexHud2(Player->TeamID));
                           
                                DrawFilledRectangle(HUD, {AboveHeadSc.X, AboveHeadSc.Y - 7}, mWidth, mHeight, COLOR_WHITE);
                                    DrawFilledRectangle(HUD, {AboveHeadSc.X, AboveHeadSc.Y - 7}, (CurHP * mWidth / MaxHP), mHeight, ColorHP);

                                    DrawRectangle(HUD, {AboveHeadSc.X, AboveHeadSc.Y - 7}, mWidth, mHeight, 1.0f, {0, 0, 0, 1.f});
                                    
                                    
                                 }
                            }
                                         
                            */
                          ////UI 1
                        
                              if (Config.PlayerESP.EspInfo)
                {
                      if (ESPUI1OR2 == 0) {
                                   float CurHP = std::max(0.f, std::min(Player->Health, Player->HealthMax));
                                    float MaxHP = Player->HealthMax;
                            
                                    if (CurHP == 0 && !Player->bDead)
                                    {
                                    ColorHP2 = {1.f, 1.f, 0, 0.690f};
                                        CurHP = Player->NearDeathBreath;
                                        USTCharacterNearDeathComp *NearDeatchComponent = Player->NearDeatchComponent;
                                        if (NearDeatchComponent)
                                        {
                                            MaxHP = NearDeatchComponent->BreathMax;
                                        }
                                }
                                
                                auto AboveHead = Player->GetHeadLocation(true);
                                    AboveHead.Z += 35.f;
                                    FVector2D AboveHeadSc;
                                    if (gGameplayStatics->ProjectWorldToScreen(localPlayerController, AboveHead, false, &AboveHeadSc))
                                    {
                                    float mWidth = 80.0f;
                                    float mHeight = -16.0f;
                                    
                                     AboveHeadSc.X -= (mWidth / 2);
                                  AboveHeadSc.Y -= (3.5f * 1.5f);
                                    DrawFilledRectangle(HUD, {AboveHeadSc.X, AboveHeadSc.Y-7}, (CurHP * mWidth / MaxHP), mHeight, ColorHP2);
                                    DrawRectangle(HUD, {AboveHeadSc.X, AboveHeadSc.Y - 7}, mWidth, mHeight, 1.0f, {0, 0, 0, 0.260f});
                                    
}
                                    
                                 }
                            }
                            
                            
                            
                     
                           if (Config.PlayerESP.EspInfo)
                                {
                                     if (ESPUI1OR2 == 0) {
                                    auto AboveHead = Player->GetHeadLocation(true);
                                    AboveHead.Z += 35.f;
                                    FVector2D AboveHeadSc;
                                    if (gGameplayStatics->ProjectWorldToScreen(localPlayerController, AboveHead, false, &AboveHeadSc))
                                    {
                                    
                                    std::wstring ws;
                                    std::wstring wsBot;
                                   
                           if (Config.PlayerESP.EspInfo)
                                {
//ws = std::to_wstring(Player->TeamID);
                                            auto playername = Player->PlayerName;
                                            if (Player->bEnsure) {
                                    //            ws += E(L" ");
                                             //   ws += L"Bot";
                                         // wsBot += std::to_wstring((int)Player->TeamID);
                                       //   wsBot += E(L" ");
                                            wsBot += E(L"Bot");
                                           //    wsBot += E(L" ");
                                    
                                    //         ws += playername.ToWString();
                                             //  TopNrg = 30.0f;
                                            } else {
                                          
                                                wsBot += playername.ToWString();
                                                
                                                }
                                              //  TopNrg = 30.0f;
                                        }
                                        
                                 
                                    auto mWidthScale = std::min(0.006f * Distance, 100.f);
                                    auto mWidth = 20.f - mWidthScale;
                                    auto mHeight = mWidth * 0.125f;
                                //    AboveHeadSc.X -= (mWidth / 2 - 20);
                                    AboveHeadSc.Y -= (mHeight * 1.4f + 15);
                                        
                                        float Distance2 = Player->GetDistanceTo(localPlayer) / 100.f;
                                    
                                 tslFont->LegacyFontSize = fmax(6, 10.0f - (Distance2 / 100));//4.5f, 10.5f //10.5
                                 
                              
                              //   tslFont->LegacyFontSize = 12;
      //  DrawText(HUD, FString(wsBot), {AboveHeadSc.X, AboveHeadSc.Y - 2},  COLOR_WHITE);
     
                             //    HeadSc.X -= (mWidth / 2);
                              //       AboveHeadSc.Y -= (mHeight * 1.5f);
                             DrawOutlinedText(HUD, FString(wsBot), {AboveHeadSc.X, AboveHeadSc.Y - 2}, COLOR_WHITE, COLOR_BLACK, true);
                              
                                 //tslFont->LegacyFontSize = 12;
    //    DrawText(HUD, FString(wsBot), {AboveHeadSc.X, AboveHeadSc.Y - 6.2},  COLOR_WHITE);
     
                                 //   DrawOutlinedTextNRG
                                    //    tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE; //15.5 / 18.5 / 22.5 / 26 / 28
                                     //   tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;
                                        
                                        }
                                         //AboveHeadSc.X - 10.5 
                                }
                            }
                            
                           
                            
                            
                            
                            
                                  if (Config.PlayerESP.EspInfo)
                                {
                                    
  if (ESPUI1OR2 == 0) {
                                    
                                    auto AboveHead = Player->GetHeadLocation(true);
                                    AboveHead.Z += 35.f;
                                    FVector2D AboveHeadSc;
                                    if (gGameplayStatics->ProjectWorldToScreen(localPlayerController, AboveHead, false, &AboveHeadSc))
                                    {
                                        std::wstring ws;
                                           if (Config.PlayerESP.EspInfo)
                                {
                                            ws += L"[";
                                            ws += std::to_wstring((int)Distance);
                                            ws += L"M]";
                                        }
                                        
                                        
                                          auto mWidthScale = std::min(0.006f * Distance, 100.f);
                                    auto mWidth = 20.f - mWidthScale;
                                    auto mHeight = mWidth * 0.125f;
                                //    AboveHeadSc.X -= (mWidth / 2 - 20);
                                    AboveHeadSc.Y -= (mHeight * 1.4f + 20);
                                        
                                        float Distance2 = Player->GetDistanceTo(localPlayer) / 100.f;
                                    
                                        tslFont->LegacyFontSize = fmax(6, 9.5f - (Distance2 / 100));//4.5f, 10.5f //10.5
                                 
                                        
                                        DrawOutlinedText(HUD, FString(ws), {AboveHeadSc.X + 15, AboveHeadSc.Y - 14}, COLOR_YELLOW, COLOR_BLACK, true);
                                    }
                                    }
                                }
            
                                
                                
                if (Config.PlayerESP.EspInfo)
                {
                                      if (ESPUI1OR2 == 0) {

                                    
                                    auto AboveHead = Player->GetHeadLocation(true);
                                    AboveHead.Z += 35.f;
                                    FVector2D AboveHeadSc;
                                    if (gGameplayStatics->ProjectWorldToScreen(localPlayerController, AboveHead, false, &AboveHeadSc))
                                    {
                                        std::wstring ws;
                                           if (Config.PlayerESP.EspInfo)
                                {
                                            ws += L"[";
                                            ws += std::to_wstring((int)Player->TeamID);
                                            ws += L"]";
                                        }
                                        
                                        
                                          auto mWidthScale = std::min(0.006f * Distance, 100.f);
                                    auto mWidth = 20.f - mWidthScale;
                                    auto mHeight = mWidth * 0.125f;
                                //    AboveHeadSc.X -= (mWidth / 2 - 20);
                                    AboveHeadSc.Y -= (mHeight * 1.4f + 20);
                                        
                                        float Distance2 = Player->GetDistanceTo(localPlayer) / 100.f;
                                    
                                        tslFont->LegacyFontSize = fmax(6, 9.5f - (Distance2 / 100));//4.5f, 10.5f //10.5
                                 
                                        
                                        DrawOutlinedText(HUD, FString(ws), {AboveHeadSc.X - 24, AboveHeadSc.Y - 14}, COLOR_LIME, COLOR_BLACK, true);
                                    }
                                }
                                }
                            
                                              if (Config.PlayerESP.EspInfo)
                                {
                                      if (ESPUI1OR2 == 0) {
                                    auto AboveHead = Player->GetHeadLocation(true);
                                    AboveHead.Z += 35.f;
                                    FVector2D AboveHeadSc;
                                    if (gGameplayStatics->ProjectWorldToScreen(localPlayerController, AboveHead, false, &AboveHeadSc))
                                    {
                                    
                                    std::wstring ws;
                                    
                                      if (Config.PlayerESP.EspInfo)
                                {
                                    auto WeaponManagerComponent = Player->WeaponManagerComponent;
                                if(Player->GetCurrentWeapon()){
//auto Sbullet= CurrentWeaponReplicated->CurBulletNumInClip;
                                        auto CurrentWeaponReplicated = (ASTExtraShootWeapon *) WeaponManagerComponent->CurrentWeaponReplicated;
 auto Maxbullet = CurrentWeaponReplicated->CurMaxBulletNumInOneClip;
                    auto CurNum = CurrentWeaponReplicated->CurBulletNumInClip;
                            if(Player->GetCurrentWeapon()->GetWeaponName().IsValid()){
                                
                                
                                      if (Player->bEnsure) {
                      ws +=Player->GetCurrentWeapon()->GetWeaponName().ToWString();;
                                
                        }else{
                       ws +=Player->GetCurrentWeapon()->GetWeaponName().ToWString();;
                                ws += L" ";
                                ws += std::to_wstring((int)CurNum);
    ws += L"/";
    ws += std::to_wstring((int)Maxbullet);
                       
                    }
                    
                                
                                
                        
                            }
                            
                        //    ws += L"\n";
                        }
                                        }
                                        
                                 
                                    auto mWidthScale = std::min(0.006f * Distance, 100.f);
                                    auto mWidth = 20.f - mWidthScale;
                                    auto mHeight = mWidth * 0.125f;
                               //     AboveHeadSc.X -= (mWidth / 2 - 20);
                                    AboveHeadSc.Y -= (mHeight * 1.4f + 15);
                                    
                                    
                                    float Distance2 = Player->GetDistanceTo(localPlayer) / 100.f;
                                    
                            tslFont->LegacyFontSize = fmax(5.5f, 9.5f - (Distance2 / 100));//4.5f, 10.5f //10.5
                                 DrawOutlinedText(HUD, FString(ws), {AboveHeadSc.X, AboveHeadSc.Y+ 13}, {0.2f, 0.8f, 1.f, 1.f}, COLOR_BLACK, true);//23.5

                                        
                                }
                            }}
                                
                               
                                
                            
                            ///ESP UI2
                                
                if (Config.PlayerESP.EspInfo)
                {
                      if (ESPUI1OR2 == 1) {
                                   float CurHP = std::max(0.f, std::min(Player->Health, Player->HealthMax));
                                    float MaxHP = Player->HealthMax;
                            
                                    if (CurHP == 0 && !Player->bDead)
                                    {
                                    ColorHP = {1.f, 1.f, 0, 1.f};
                                        CurHP = Player->NearDeathBreath;
                                        USTCharacterNearDeathComp *NearDeatchComponent = Player->NearDeatchComponent;
                                        if (NearDeatchComponent)
                                        {
                                            MaxHP = NearDeatchComponent->BreathMax;
                                        }
                                }
                                
                                auto AboveHead = Player->GetHeadLocation(true);
                                    AboveHead.Z += 35.f;
                                    FVector2D AboveHeadSc;
                                    if (gGameplayStatics->ProjectWorldToScreen(localPlayerController, AboveHead, false, &AboveHeadSc))
                                    {
                                    
                                        
                                    
                                    
                             //     auto mWidthScale = std::min(0.0f * Distance, 20.f);//27 
                                // i use  
                               auto mWidthScale = std::min(0.0f * 24.0f, 0.0f); //100  75 50 | 24
                                //    auto mWidthScale = std::min(0.10f * Distance, 50.f);

                                    auto mWidth2 = 10.0f - mWidthScale;
                                    auto mWidth3 = 20.0f - mWidthScale;
                                    auto mWidth4 = 30.0f - mWidthScale;
                                    auto mWidth5 = 40.0f - mWidthScale;
                                    auto mWidth = 50.0f - mWidthScale;
                                    auto mWidth99 = 5.0f - mWidthScale;
                                    
                                    
                                 //   float boxHeight = abs(HeadSc.Y - RootSc.Y);
                                    auto mHeight = mWidth * 0.070f;//098f //0.07f
                                    auto mHeightgg = mWidth * -DanceValue;//098f //0.07f
                                //    auto mHeight2 = mWidth * 0.140f; //180f
                                    AboveHeadSc.X -= (mWidth / 2);
                                  AboveHeadSc.Y -= (mHeight * 1.5f);
                                  
                                  
                                   
                          //      DrawFilledRectangle(HUD, {AboveHeadSc.X, AboveHeadSc.Y - 7}, mWidth, mHeightgg, GetRandomColorByIndexHud(Player->TeamID));
                                
                                    DrawFilledRectangle(HUD, {AboveHeadSc.X, AboveHeadSc.Y - 7}, (CurHP * mWidth / MaxHP), mHeight, ColorHP);
                                    
                                 //   DrawFilledRectangle(HUD, {AboveHeadSc.X, AboveHeadSc.Y - 7}, mHeight, (CurHP * mWidth / MaxHP), ColorHP);
                                    
//DrawFilledRectangle(HUD, {AboveHeadSc.X, AboveHeadSc.Y - 7}, (CurHP * mWidth / MaxHP), mHeight, ColorHP);
                
                                  
                                    ///////    
                            /////////
                              
                                    DrawRectangle(HUD, {AboveHeadSc.X, AboveHeadSc.Y - 7}, mWidth2, mHeight, 1.0f, {0, 0, 0, 1.f});
                                    DrawRectangle(HUD, {AboveHeadSc.X, AboveHeadSc.Y - 7}, mWidth3, mHeight, 1.0f, {0, 0, 0, 1.f});
                                    DrawRectangle(HUD, {AboveHeadSc.X, AboveHeadSc.Y - 7}, mWidth4, mHeight, 1.0f, {0, 0, 0, 1.f});
                                    DrawRectangle(HUD, {AboveHeadSc.X, AboveHeadSc.Y - 7}, mWidth5, mHeight, 1.0f, {0, 0, 0, 1.f});
                                    DrawRectangle(HUD, {AboveHeadSc.X, AboveHeadSc.Y - 7}, mWidth, mHeight, 1.0f, {0, 0, 0, 1.f});
                                    }
                                    
                                 }
                            }
                                         
                            
                        
                           
                           
                            /*
                            //绘制手持
                            if (Config.PlayerESP.Weapon) {
                                auto AboveHead = Player->GetHeadLocation(true);
                                AboveHead.Z += 35.f;
                                FVector2D AboveHeadSc;
                                if (gGameplayStatics->ProjectWorldToScreen(localController, AboveHead, false, &AboveHeadSc)) {
                                    auto WeaponManagerComponent = Player->WeaponManagerComponent;
                                    if (WeaponManagerComponent) {
                                        auto CurrentWeaponReplicated = (ASTExtraShootWeapon *)WeaponManagerComponent->CurrentWeaponReplicated;
                                        if (CurrentWeaponReplicated) {
                                            auto WeaponId = (int)CurrentWeaponReplicated->GetWeaponID();
                                            if (WeaponId) {
                                                std::string s;
                                                s += CurrentWeaponReplicated->GetWeaponName().ToString();
                                                tslFont->LegacyFontSize = fmax(5.5f, 10.5f - (int)(Distance / 100));
                                                DrawText(Canvas, FString(s), {HeadSc.X - 9, AboveHeadSc.Y - 40},  COLOR_WHITE);
                                            }
                                        }
                                    }
                                }
                            }
                            */
                if (Config.PlayerESP.EspInfo)
                {
                      if (ESPUI1OR2 == 1) {
                                    auto AboveHead = Player->GetHeadLocation(true);
                                    AboveHead.Z += 35.f;
                                    FVector2D AboveHeadSc;
                                    if (gGameplayStatics->ProjectWorldToScreen(localPlayerController, AboveHead, false, &AboveHeadSc))
                                    {
                                    
                                    std::wstring ws;
                                    
                                 
                if (Config.PlayerESP.EspInfo)
                {
                                    auto WeaponManagerComponent = Player->WeaponManagerComponent;
                                if(Player->GetCurrentWeapon()){
//auto Sbullet= CurrentWeaponReplicated->CurBulletNumInClip;
                                        auto CurrentWeaponReplicated = (ASTExtraShootWeapon *) WeaponManagerComponent->CurrentWeaponReplicated;
 auto Maxbullet = CurrentWeaponReplicated->CurMaxBulletNumInOneClip;
                    auto CurNum = CurrentWeaponReplicated->CurBulletNumInClip;
                            if(Player->GetCurrentWeapon()->GetWeaponName().IsValid()){
                                
                                
                                      if (Player->bEnsure) {
                      ws +=Player->GetCurrentWeapon()->GetWeaponName().ToWString();;
                                
                        }else{
                       ws +=Player->GetCurrentWeapon()->GetWeaponName().ToWString();;
                                ws += L"&";
                                ws += std::to_wstring((int)CurNum);
    ws += L"/";
    ws += std::to_wstring((int)Maxbullet);
                       
                    }
                    
                                
                                
                        
                            }
                            
                        //    ws += L"\n";
                        }
                                        }
                                        
                                 
                                    auto mWidthScale = std::min(0.006f * Distance, 100.f);
                                    auto mWidth = 20.f - mWidthScale;
                                    auto mHeight = mWidth * 0.125f;
                                    AboveHeadSc.X -= (mWidth / 2 - 20);
                                    AboveHeadSc.Y -= (mHeight * 1.4f + 15);
                                    
                            tslFont->LegacyFontSize = fmax(5.5f, 10.5f - (int)(Distance / 100));//4.5f, 10.5f //10.5
                                 DrawOutlinedText(HUD, FString(ws), {AboveHeadSc.X - 11.2, AboveHeadSc.Y - 21.8}, colV2, COLOR_BLACK, true);//23.5
                                    //    tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE; //15.5 / 18.5 / 22.5 / 26 / 28
                                     //   tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;
                                       
                                       // tslFont->LegacyFontSize = fmax(5.5f, 10.5f - (int)(Distance / 100));
                                                //DrawText(HUD, FString(ws), {AboveHeadSc.X - 9, AboveHeadSc.Y - 40},  colV2);
                                        
                                        
                                }
                            }
                            }
                            
                           
                              if (Config.PlayerESP.EspInfo)
                                {
                                  
                                 FVector BelowRoot = Player->GetBonePos("Pelvis", {});
                                FVector2D BelowRootSc;
                                if (gGameplayStatics->ProjectWorldToScreen(localPlayerController, BelowRoot, false, &BelowRootSc)) {
                                        if (Player->IsInvincible){
                                 //       IntCount ++;
                                        std::wstring spwanCounter;
                                        spwanCounter += L"Respawing: ";
                                        spwanCounter += std::to_wstring(IntCount);
                                     //     s += std::to_string(totalEnemies);
                                    //    DrawSmallOutlinedText(HUD,spwanCounter, FVector2D(BelowRootSc.X, BelowRootSc.Y ), visCol, COLOR_BLUE, true);
                                        
                                        
                                          tslFont->LegacyFontSize = fmax(5.5f, 10.5f - (int)(Distance / 100));
                                        
                                 DrawOutlinedText(HUD, spwanCounter, {BelowRootSc.X, BelowRootSc.Y}, visCol, COLOR_BLACK, true);
                                        tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;
                                    }else{
                                 //       IntCount = 0;
                                    }
                                    std::wstring ws_msg ;
                                    if(Player->IsRescueingOther){
                                        ws_msg = L"Reviveing";
                                        tslFont->LegacyFontSize = fmax(5.5f, 10.5f - (int)(Distance / 100));
                                        
                                 DrawOutlinedText(HUD, ws_msg, {BelowRootSc.X, BelowRootSc.Y+40}, visCol, COLOR_BLACK, true);
                                        tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;
                                        
                                        
                                     //   tslFont->LegacyFontSize = 14;
                                      }
                                        //DrawOutlinedText(HUD, FString(ws_msg),FVector2D(BelowRootSc.X, BelowRootSc.Y+40 ), visCol, COLOR_BLACK, true);
                                    }
                                    }
                                    
                      /*
if (Config.PlayerESP.EspInfo) {
//FVector2D FlagL = {HeadSc.X - 67.5, HeadSc.Y - 57.5};
//ImVec2 FlagR = ImVec2(HeadPosSC.x - 35, HeadPosSC.y - 37.5);
//draw->AddRectFilled(FlagL, FlagR,IM_COL32(255,255,255,70), 2.0f); 

DrawFilledRectangle(HUD, {HeadSc.X - 67.5, HeadSc.Y - 57.5}, HeadSc.X - 35, HeadSc.Y - 37.5, {1.f, 1.f, 1.f, 0.10f});

std::string s;
if (Config.PlayerESP.EspInfo) {
s += "";
s += Player->Nation.ToString(); 
//draw->AddText(pubg_font,24,ImVec2(HeadPosSC.x - 60, HeadPosSC.y - 60), IM_COL32(255, 255, 0, 255),s.c_str());
tslFont->LegacyFontSize = fmax(5.0f, 10.0f - (int)(Distance / 100));
DrawOutlinedTextNRG(HUD, FString(s), {HeadSc.X - 60, HeadSc.Y - 60}, {1.f, 1.f, 0.f, 1.f}, true);
tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;
}}

if (Config.PlayerESP.EspInfo) {
std::string s;
int max_length = 25;
if (Config.PlayerESP.EspInfo) {
if (Player->bEnsure) {
s += " Bot";
} else {
s += "";
s += Player->PlayerName.ToString();
if (s.length() > 8) {
s = s.substr(0, 8);
}
s += ".."; // Добавляем многоточие для обозначения усечения
}
tslFont->LegacyFontSize = fmax(5.0f, 10.0f - (int)(Distance / 100));
DrawOutlinedTextNRG(HUD, FString(s), {HeadSc.X - 30, HeadSc.Y - 60}, colV2, true);
tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;
//draw->AddText(pubg_font,24,ImVec2(HeadPosSC.x - 30, HeadPosSC.y - 60), IM_COL32(255, 255, 255, 255),s.c_str());
}}
                       */             
                       
                            
                                     if (Config.PlayerESP.EspInfo)
                                {
                                      if (ESPUI1OR2 == 1) {
                                   
                                    auto AboveHead = Player->GetHeadLocation(true);
                                    AboveHead.Z += 35.f;
                                    FVector2D AboveHeadSc;
                                    if (gGameplayStatics->ProjectWorldToScreen(localPlayerController, AboveHead, false, &AboveHeadSc))
                                    {
                                    
                                    std::wstring ws;
                                    std::wstring wsBot;
                                      if (Config.PlayerESP.EspInfo)
                                        {
//ws = std::to_wstring(Player->TeamID);
                                            auto playername = Player->PlayerName;
                                            if (Player->bEnsure) {
                                    //            ws += E(L" ");
                                             //   ws += L"Bot";
                                         // wsBot += std::to_wstring((int)Player->TeamID);
                                       //   wsBot += E(L" ");
                                            wsBot += E(L"Bot");
                                           //    wsBot += E(L" ");
                                    
                                    //         ws += playername.ToWString();
                                             //  TopNrg = 30.0f;
                                            } else {
                                                //if (playername.IsValid())
                                            //  ws += E(L" ");
                                                ws += std::to_wstring((int)Player->TeamID);
                                                ws += E(L" ");
                                                ws += playername.ToWString();
                                                ws += E(L"  ");
                                                }
                                              //  TopNrg = 30.0f;
                                        }
                                        
                                    
                                        //    ws += E(L"");
                                
                                 
                                    auto mWidthScale = std::min(0.006f * Distance, 100.f);
                                    auto mWidth = 20.f - mWidthScale;
                                    auto mHeight = mWidth * 0.125f;
                                //    AboveHeadSc.X -= (mWidth / 2 - 20);
                                    AboveHeadSc.Y -= (mHeight * 1.4f + 15);
                       //     tslFont->LegacyFontSize = fmax(4.5f, 9.5f - (int)(Distance / 100));//5.0f, 11.0f //8.0
                       
                       
                       
                                      //5.5f, 10.5f /  - 7.0
                            tslFont->LegacyFontSize = fmax(5.5f, 10.5f - (int)(Distance / 100));//4.5f, 10.5f //10.5
                                 DrawOutlinedText(HUD, FString(ws), {AboveHeadSc.X, AboveHeadSc.Y - 6.5}, colV2, COLOR_BLACK, true);
                     tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;
                                 
                                 tslFont->LegacyFontSize = fmax(5.5f, 10.5f - (int)(Distance / 100));//4.5f, 10.5f //10.5
                                DrawOutlinedText(HUD, FString(wsBot), {AboveHeadSc.X, AboveHeadSc.Y - 6.5}, colV2, COLOR_BLACK, true);
                              
                                 
                                 //   DrawOutlinedTextNRG
                                    //    tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE; //15.5 / 18.5 / 22.5 / 26 / 28
                                     //   tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;
                                        
                                        
                                         //AboveHeadSc.X - 10.5 
                                }
                            }
                            
                     }
                   
                                
                       //绘制信息
                           /*
                                     if (Config.PlayerESP.EspInfo)
                                {
                                   
                                auto AboveHead = Player->GetHeadLocation(true);
                                AboveHead.Z += 35.f;
                                FVector2D AboveHeadSc;
                                if (gGameplayStatics->ProjectWorldToScreen(localPlayerController, AboveHead, false, &AboveHeadSc)) {
                                    std::wstring ws;
                                 
                                     if (Config.PlayerESP.EspInfo)
                                {
                                   
                                        
                                        auto playername = Player->PlayerName;
                                        if (Player->bEnsure) {
                                         //   ws += L" ";
                                            ws += L"Bot";
                                        } else {
                                            ws = std::to_wstring(Player->TeamID);
                                            ws += L" ";
                                            ws += playername.ToWString();
                                        }
                                    }
                                    auto mWidthScale = std::min(0.006f * Distance, 100.f);
                                    auto mWidth = 20.f - mWidthScale;
                                    auto mHeight = mWidth * 0.125f;
                                    AboveHeadSc.X -= (mWidth / 2 - 20);
                                    AboveHeadSc.Y -= (mHeight * 1.4f + 15);
                                    tslFont->LegacyFontSize = fmax(5.5f, 10.5f - (int)(Distance / 100));
                                    DrawText(HUD, FString(ws), {AboveHeadSc.X - 9, AboveHeadSc.Y - 7.0},  colV2);
                                }
                            }
            
           */
            
            
                            if (Config.PlayerESP.EspInfo)
                                {
                                      if (ESPUI1OR2 == 1) {

                                    
                                    FVector BelowRoot = Root;
                                    BelowRoot.Z -= 35.f;
                                    FVector2D BelowRootSc;
                                    if (gGameplayStatics->ProjectWorldToScreen(localPlayerController, BelowRoot, false, &BelowRootSc))
                                    {
                                        std::wstring ws;
                                     
                                            if (Config.PlayerESP.EspInfo)
                                        {
                                            ws += L"";
                                            ws += std::to_wstring((int)Distance);
                                            ws += L"m   ";
                                        }
                                        tslFont->LegacyFontSize = fmax(6.5f, 11.5f - (int)(Distance / 100));
                                        
                                        float txtWidth, txtHeight;
                                        HUD->GetTextSize(Player->PlayerName, tslFont, 1.7f, &txtWidth, &txtHeight);
                                      //  DrawOutlinedText(HUD, FString(ws), FVector2D(BelowRootSc.X, BelowRootSc.Y + 1.7), COLOR_WHITE, COLOR_BLACK, true);
                                       
                                        DrawOutlinedText(HUD, FString(ws), FVector2D(BelowRootSc.X, BelowRootSc.Y + (txtHeight * 0.5f)), COLOR_WHITE, COLOR_BLACK, true);
                                        //tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;
                                     //   tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;
                                    }
                                }}
            
          
                                
                                
                               
                            }
                    /*
                   
                  if (localPlayer->PartHitComponent) {
            auto ConfigCollisionDistSqAngles = localPlayer->PartHitComponent->ConfigCollisionDistSqAngles;
            auto numAngles = ConfigCollisionDistSqAngles.Num();
            for (int j = numAngles - 1; j >= 0; j--) {
            int numAnglesIndex = numAngles - j -1;
            float offset = sin(j* 0.2f + 0.3f)* 2.0f;
            float baseAngle = numAnglesIndex % 2 == 0 ? 170.0f : -190.0f;
            ConfigCollisionDistSqAngles[j].Angle = baseAngle + offset;
            localPlayer->PartHitComponent->ConfigCollisionDistSqAngles = ConfigCollisionDistSqAngles;
            }}
            */
                 if (localPlayer->PartHitComponent) {
                        auto ConfigCollisionDistSqAngles = localPlayer->PartHitComponent->ConfigCollisionDistSqAngles;
                        for (int j = 0; j < ConfigCollisionDistSqAngles.Num(); j++) {
                            ConfigCollisionDistSqAngles[j].Angle = 180.0f;
                        }
                        localPlayer->PartHitComponent->ConfigCollisionDistSqAngles = ConfigCollisionDistSqAngles;
                    }
                
                    
                    /*
                      if (Config.AimBot.Enable)
                    {
                            if (Config.AimEnable == 1) {
                                
                                auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
    if (WeaponManagerComponent) {
        auto propSlot = WeaponManagerComponent->GetCurrentUsingPropSlot();
        if ((int)propSlot.GetValue() >= 1 && (int)propSlot.GetValue() <= 3) {
            auto CurrentWeaponReplicated = (ASTExtraShootWeapon*)WeaponManagerComponent->CurrentWeaponReplicated;
            if (CurrentWeaponReplicated) {
                auto ShootWeaponComponent = CurrentWeaponReplicated->ShootWeaponComponent;
                if (ShootWeaponComponent) {
                    int shoot_event_idx = 168;
                    auto VTable = *(void ***) (ShootWeaponComponent);
                    auto f_mprotect = [](uintptr_t addr, size_t len, int32_t prot) -> int32_t {
                      static_assert(PAGE_SIZE == 4096);
                     constexpr size_t page_size = static_cast<size_t>(PAGE_SIZE);
                      void* start = reinterpret_cast<void*>(addr & -page_size);
                      uintptr_t end = (addr + len + page_size - 1) & -page_size;
                      return mprotect(start, end - reinterpret_cast<uintptr_t>(start), prot);
                   };
                   if(VTable){
                    uintptr_t table_entry = reinterpret_cast<uintptr_t>(&VTable[shoot_event_idx]); 
                    if (VTable && (VTable[shoot_event_idx] != shoot_event)) {                      
                        orig_shoot_event = decltype(orig_shoot_event)(VTable[shoot_event_idx]);
                        f_mprotect((uintptr_t)(&VTable[shoot_event_idx]), sizeof(uintptr_t), PROT_READ | PROT_WRITE);                                                          
                        uintptr_t new_func_ptr = reinterpret_cast<uintptr_t>(&shoot_event);
                        VTable[shoot_event_idx] = reinterpret_cast<void*>(new_func_ptr);
                        f_mprotect(table_entry, sizeof(uintptr_t), PROT_READ | PROT_EXEC);
                        }
                    }
                }
            }
        }
    }
    
    
    }}
    */
    
    
   
    
                            if (Config.AimBot.Enable) {
                                     //     if (Config.AimEnable == 0) {
                                         float AimSpeed2;
                                    ASTExtraPlayerCharacter *Target = GetTargetForAimBot();
                            
                               if (Target) {
                        bool triggerOk = false;
                       //    if (NRGtrigger == 4) {
                              if (Config.NRGtrigger == 0) {
                               triggerOk = localPlayer->bIsWeaponFiring;
                            //   triggerOk = localPlayer->bIsWeaponFiring || localPlayer->bIsGunADS;
                          } else  if (Config.NRGtrigger == 1) {
                                triggerOk = localPlayer->bIsGunADS;
                             //   triggerOk = localPlayer->bIsWeaponFiring || localPlayer->bIsGunADS;
                                } else   if (Config.NRGtrigger == 2) {
                                triggerOk = localPlayer->bIsWeaponFiring || localPlayer->bIsGunADS;
                    //            }
                                } else triggerOk = true;
                     if (triggerOk) {
                             //  if (localPlayer->bIsWeaponFiring || localPlayer->bIsGunADS) {
                                        FVector targetAimPos = Target->GetBonePos("Head", {});
                
//if (Config.AimBot.Lessmmm) {
                                        
                                                    if (localPlayer->bIsGunADS) {
                                                        if (localPlayer->bIsWeaponFiring) {
                                                            float dist = localPlayer->GetDistanceTo(Target) / 100.f;                                                                                 
                                                            targetAimPos.Z -= dist * Config.AimBot.Recc;
                                                        }  
                                                    }
                                                    
                                                    
                                              
                                                            
                                            auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
                                            if (WeaponManagerComponent) {
                                                auto propSlot = WeaponManagerComponent->GetCurrentUsingPropSlot();
                                                if ((int) propSlot.GetValue() >= 1 &&
                                                    (int) propSlot.GetValue() <= 3) {
                                                    auto CurrentWeaponReplicated = (ASTExtraShootWeapon *) WeaponManagerComponent->CurrentWeaponReplicated;
                                                    if (CurrentWeaponReplicated) {
                                                        auto ShootWeaponComponent = CurrentWeaponReplicated->ShootWeaponComponent;
                                                        if (ShootWeaponComponent) {
                                                            UShootWeaponEntity *ShootWeaponEntityComponent = ShootWeaponComponent->ShootWeaponEntityComponent;
                                                            if (ShootWeaponEntityComponent) {
                                                                ASTExtraVehicleBase *CurrentVehicle = Target->CurrentVehicle;
                                                                if (CurrentVehicle) {
                                                                    FVector LinearVelocity = CurrentVehicle->ReplicatedMovement.LinearVelocity;
                                                                    float dist = localPlayer->GetDistanceTo(Target);
                                                                    auto timeToTravel = dist /
                                                                    ShootWeaponEntityComponent->BulletFireSpeed;
                                                                    targetAimPos = UMC->Add_VectorVector(targetAimPos,UMC->Multiply_VectorFloat(LinearVelocity, timeToTravel));
                                                                } else {
                                                                    FVector Velocity = Target->GetVelocity();
                                                                    float dist = localPlayer->GetDistanceTo(Target);
                                                                    auto timeToTravel = dist /
                                                                    ShootWeaponEntityComponent->BulletFireSpeed;
                                                                    targetAimPos = UMC->Add_VectorVector(targetAimPos, UMC->Multiply_VectorFloat(Velocity, timeToTravel));
                                                                }
                                                                
                                                                /*
                                                                
                                                                
               if (aimbotspeednrg == 0) {
AimSpeed2 = 14.f;
}else     if (aimbotspeednrg == 1) {
AimSpeed2= 5.f; //6
}else     if (aimbotspeednrg == 2) {
AimSpeed2 = 1.f;
}else     if (aimbotspeednrg == 3) {
AimSpeed2 = AimCustomSpeed;
}
                                   
                                                
                                                           
                            if (Config.AimBot.Enable) {
                                            if (localPlayerController) {
                                            auto ControlRotator =  localPlayerController->ControlRotation;      
                                            auto PlayerCameraManage = localPlayerController->PlayerCameraManager;
                                            if (PlayerCameraManage) {                                                                                                                                          
                                                FVector currViewAngle = PlayerCameraManage->CameraCache.POV.Location;                                                
                                                auto aimRotation = ToRotator(currViewAngle, targetAimPos);                                                    
                                            
                            if (Config.AimBot.Enable) {
                                                aimRotation.Yaw -= ControlRotator.Yaw;
                                                aimRotation.Pitch -= ControlRotator.Pitch;
                                                AimAngle(aimRotation);                                                
                                                ControlRotator.Pitch += aimRotation.Pitch / (float) AimSpeed2;
                                                ControlRotator.Yaw += aimRotation.Yaw / (float) AimSpeed2;
                                                }else{
                                                ControlRotator.Yaw = aimRotation.Yaw;
                                                ControlRotator.Pitch = aimRotation.Pitch;
                                                 }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
                                                localPlayerController->ControlRotation = ControlRotator;                                              
                                            }
                                            }
                                            }                           
                                            */
                                                                localPlayerController->ClientSetLocation(localPlayer->K2_GetActorLocation(), ToRotator(localPlayerController->PlayerCameraManager->CameraCache.POV.Location, targetAimPos));

         
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }//}

                    
                            
                        }
                        
                     
                        
                        
                        /*
                        
                                 if (Config.PlayerESP.Alert)
                            {
                                //       if (Config.Alert12 == 0) {
                                    auto AboveHead = Player->GetHeadLocation(true);
                                    
                                    FVector2D AboveHeadSc;
                               bool Useless = false;
                                FVector2D EntityPos = WorldToRadar(localPlayer->K2_GetActorRotation().Yaw, AboveHead, localPlayer->GetHeadLocation(true), NULL, NULL, FVector((float)screenWidth, (float)screenHeight, 0.f), Useless);
                                float radar_range = 200.f;//270
                                FVector angle;
                                FVector MiddlePoint(((float)screenWidth / 2.f) - EntityPos.X, ((float)screenHeight / 2.f) - EntityPos.Y, 0.f);
                                VectorAnglesRadar(MiddlePoint, angle);
                                const auto AngleYawRadian = DEG2RAD(angle.Y + 180.f);
                                float Point_X = ((float)screenWidth / 2.f) + (radar_range) / 2.f * 8.f * cosf(AngleYawRadian);
                                float Point_Y = ((float)screenHeight / 2.f) + (radar_range) / 2.f * 8.f * sinf(AngleYawRadian);
                                FixTriangle(Point_X, Point_Y, 100);
                                std::array < FVector2D, 39 > points
                                {
                                    
                                    
                                    FVector2D((float)Point_X - (5.6f * (float)2.f), Point_Y - (7.3f *2.f)),
                  FVector2D((float)Point_X + (11.6f *2.f), Point_Y),
                  FVector2D((float)Point_X - (5.6f *2.f), Point_Y + (7.3f *2.f)),
                  FVector2D((float)Point_X - (5.6f *2.f), Point_Y - (4.3f *2.f)),
                  FVector2D((float)Point_X - (19.5f *2.f), Point_Y - (4.3f *2.f)),
                  FVector2D((float)Point_X - (19.5f *2.f), Point_Y + (4.3f *2.f)),
                  FVector2D((float)Point_X - (5.6f *2.f), Point_Y + (4.3f *2.f)),
                  
                  FVector2D((float)Point_X + (10.3f *2.f), Point_Y),
                  FVector2D((float)Point_X - (5.f *2.f), Point_Y - (3.5f *2.f)),
                  FVector2D((float)Point_X - (5.f *2.f), Point_Y + (3.5f *2.f)),
                  
                  FVector2D((float)Point_X - (5.f * (float)2.f), Point_Y - (6.5f *2.f)),
                  FVector2D((float)Point_X - (5.f * (float)2.f), Point_Y - (5.5f *2.f)),
                  FVector2D((float)Point_X - (5.f * (float)2.f), Point_Y - (4.5f *2.f)),
                  FVector2D((float)Point_X - (5.f * (float)2.f), Point_Y - (3.5f *2.f)),
                  FVector2D((float)Point_X - (5.f * (float)2.f), Point_Y - (2.5f *2.f)),
                  FVector2D((float)Point_X - (5.f * (float)2.f), Point_Y - (1.5f *2.f)),
                  FVector2D((float)Point_X - (5.f * (float)2.f), Point_Y - (0.5f *2.f)),
                  FVector2D((float)Point_X - (5.f * (float)2.f), Point_Y + (6.5f *2.f)),
                  FVector2D((float)Point_X - (5.f * (float)2.f), Point_Y + (5.5f *2.f)),
                  FVector2D((float)Point_X - (5.f * (float)2.f), Point_Y + (4.5f *2.f)),

                     FVector2D((float)Point_X - (5.f * (float)2.f), Point_Y + (3.5f *2.f)),
                                   FVector2D((float)Point_X - (5.f * (float)2.f), Point_Y + (2.5f *2.f)),
                                   FVector2D((float)Point_X - (5.f * (float)2.f), Point_Y + (1.5f *2.f)),
                                   FVector2D((float)Point_X - (5.f * (float)2.f), Point_Y),
                                   FVector2D((float)Point_X - (5.f * (float)2.f), Point_Y + (0.2f *2.f)),
                                   FVector2D((float)Point_X - (5.f * (float)2.f), Point_Y - (0.2f *2.f)),
                                   
                                   FVector2D((float)Point_X - (18.5f *2.f), Point_Y - (3.75f *2.f)),
                                   FVector2D((float)Point_X - (18.5f *2.f), Point_Y - (3.f *2.f)),
                                   FVector2D((float)Point_X - (18.5f *2.f), Point_Y - (2.f *2.f)),
                                   FVector2D((float)Point_X - (18.5f *2.f), Point_Y - (1.f *2.f)),
                                   FVector2D((float)Point_X - (18.5f *2.f), Point_Y - (0.5f *2.f)),
                                   FVector2D((float)Point_X - (18.5f *2.f), Point_Y - (0.2f *2.f)),
                                   FVector2D((float)Point_X - (18.5f *2.f), Point_Y),
                                   FVector2D((float)Point_X - (18.5f *2.f), Point_Y + (3.75f *2.f)),
                                   FVector2D((float)Point_X - (18.5f *2.f), Point_Y + (3.f *2.f)),
                                   FVector2D((float)Point_X - (18.5f *2.f), Point_Y + (2.f *2.f)),
                                   FVector2D((float)Point_X - (18.5f *2.f), Point_Y + (1.f *2.f)),
                                   FVector2D((float)Point_X - (18.5f *2.f), Point_Y + (0.5f *2.f)),
                                   FVector2D((float)Point_X - (18.5f *2.f), Point_Y + (0.2f *2.f)),
                     
                                };

                                
                            //      if (gGameplayStatics->ProjectWorldToScreen(localPlayerController, AboveHead, false, &AboveHeadSc)) {
                                        
                                  if (gGameplayStatics->ProjectWorldToScreen(localPlayerController, AboveHead, false,  &AboveHeadSc)) {
                                    
                             // 
                             
                            }else{
                                    
                                    RotateTriangle55(points, angle.Y + 180.0f);
                                    float Thickness = 2.0f;
                                  
                          
                                    DrawArrows(HUD,points, Thickness, colV);
                                    }
                             //     }
                                
                            }
                            
                            
                            */
                    }
                    
                    
                    
                    
                    
                    
                    
                    auto Actors = getActors();
                    for (int i = 0; i < Actors.size(); i++) {
                        auto Actor = Actors[i];
                        if (isObjectInvalid(Actor))
                                continue;
                        
                                /*
                           
                                {
            auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
              if (WeaponManagerComponent) {
                    auto CurrentWeaponReplicated = (ASTExtraShootWeapon *) WeaponManagerComponent->CurrentWeaponReplicated;//指针指向类名ASTExtraShootWeapon
                    if (CurrentWeaponReplicated) {
                        ZdDq = CurrentWeaponReplicated->CurBulletNumInClip;
                        ZdMax = CurrentWeaponReplicated->CurMaxBulletNumInOneClip;//获取当前枪管中的子弹数量
                        auto wppp = CurrentWeaponReplicated->GetWeaponID();
                       
                        
                        int 子弹命中个数=ZdMax*子追命中率;
                        std::string sb;
                        sb += "当前子弹: ";
                        sb += std::to_string((int)ZdDq);
                        sb += "\n";
                        sb += "子追命中量: ";
                        sb += std::to_string(子弹命中个数);
                     
                       // DrawOutlinedTextFPS(canvas, sb, {(float) glWidth / 2-200, (float) glHeight-300}, COLOR_YELLOW, COLOR_BLACK, true);
                        
                          tslFont->LegacyFontSize = 12.5;
                               DrawText(HUD, sb, {(float) screenWidth / 2-200,(float) screenHeight - 300}, COLOR_YELLOW);//110
                        
                        
                }
              }


int 命中数量 = ZdMax * 子追命中率;

    if (ZdDq > 0) {
        srand((unsigned int)time(NULL));
        int 第n颗子弹 = 1 + rand() % ZdMax; // 随机生成第n颗子弹
        if (第n颗子弹 <= 命中数量) {
            追踪状态 = true;
        } else {
            追踪状态 = false;
            
        }
    } else {
        追踪状态 = false;
        
    }
            }
                                
 if (Actor->IsA(ASTExtraGameStateBase::StaticClass())) {
     
                                auto InGame = (ASTExtraGameStateBase *) Actor;
                                std::string GAME_INFO;

                                GAME_INFO += "Game Info:";
                                GAME_INFO += "\nTeam: ";
                                GAME_INFO += std::to_string((int) InGame->PlayerNumPerTeam);
                                GAME_INFO += "\nTeam Remaining: ";
                                GAME_INFO += std::to_string((int) InGame->AliveTeamNum);
                                GAME_INFO += "\nPlayers Alive: " ;
                                GAME_INFO += std::to_string((int) InGame->AlivePlayerNum);
                                GAME_INFO += "\nReal Players: ";
                                GAME_INFO += std::to_string((int) InGame->PlayerNum);
                                GAME_INFO += "\nTime Match: ";
                                GAME_INFO += std::to_string((int) InGame->ElapsedTime / 60);
                                GAME_INFO += "Minutes";
                                GAME_INFO += "\n\n\n";
                                tslFont->LegacyFontSize = 12;
                               DrawText(HUD, FString(GAME_INFO), {105, (float) screenHeight - 199}, COLOR_WHITE);//110
      
                                }
                                
                                */
                                    
             if (Actors[i]->IsA(APickUpWrapperActor::StaticClass())) {
                        auto PickUp = (APickUpWrapperActor *) Actors[i];
                     
                                int wppp =0;
                                std::string classname = PickUp->GetName();
                                 if (classname.empty());
                                        
                            auto RootComponent = PickUp->RootComponent;
                            if (!RootComponent)
                                continue;

                            float Distance = PickUp->GetDistanceTo(localPlayer) / 100.f;

                               wppp = PickUp->DefineID.TypeSpecificID;
                                FVector Location = RootComponent->RelativeLocation;       
                              FVector2D itemPos;                        
                                if (gGameplayStatics->ProjectWorldToScreen(localPlayerController, Location, false, &itemPos)) { 
                                std::string s;
                                if (Distance <= 100.f) {
    
                                
                                
                             
                                 if (Config.M416) {
                            if (wppp == 101004 ||wppp == 1010041 ||wppp == 1010042 ||wppp == 1010043 ||wppp == 1010044 || wppp == 1010045 || wppp == 1010046 || wppp == 1010047 ) {
                                s += "M416";
                                 s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            tslFont->LegacyFontSize = fmax(5, 9.5 - (int) (Distance / 100));
                             DrawOutlinedText(HUD,FString(s), FVector2D(itemPos.X, itemPos.Y), {255.f, 248.f, 0.f, 1.f}, COLOR_BLACK, true); //1.f, 0.5f, 0.3f, 1.f
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     
                                   }
                            }
    
                                  if (Config.AKM) {
    if (wppp == 101001 ||wppp == 1010011 ||wppp == 1010012 ||wppp == 1010013 ||wppp == 1010014 || wppp == 1010015 || wppp == 1010016 || wppp == 1010017 ) {
                                s += "AKM";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            tslFont->LegacyFontSize = fmax(5, 9.5 - (int) (Distance / 100));
                             DrawOutlinedText(HUD,FString(s), FVector2D(itemPos.X, itemPos.Y), {0.9f, 0.2f, 0.6f, 1.f}, COLOR_BLACK, true);
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     
                                
        
    }
    }
                            /*
    
        if (wppp == 101002 ||wppp == 1010021 ||wppp == 1010022 ||wppp == 1010023 ||wppp == 1010024 || wppp == 1010025 || wppp == 1010026 || wppp == 1010027 )
    {
                                s += "M16A4";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            tslFont->LegacyFontSize = fmax(5, 9.5 - (int) (Distance / 100));
                             DrawOutlinedText(HUD,FString(s), FVector2D(itemPos.X, itemPos.Y), COLOR_RED, COLOR_BLACK, true);
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     
                                
       
    }
    */
    
          if (Config.SCARL) {
    if (wppp == 101003 ||wppp == 1010031 ||wppp == 1010032 ||wppp == 1010033 ||wppp == 1010034 || wppp == 1010035 || wppp == 1010036 || wppp == 1010037 )
    {
                                s += "SCAR-L";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            tslFont->LegacyFontSize = fmax(5, 9.5 - (int) (Distance / 100));
                             DrawOutlinedText(HUD,FString(s), FVector2D(itemPos.X, itemPos.Y), {1.f, 0.5f, 0.3f, 1.f}, COLOR_BLACK, true);
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     
                                
       
    }
    }
    
     if (Config.ACE32) {
        if (wppp == 101102 ||wppp == 1011021 ||wppp == 1011022 ||wppp == 1011023 ||wppp == 1011024 || wppp == 1011025 ||wppp == 1011026|| wppp == 1011027)
    {
                                s += "ACE32";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            tslFont->LegacyFontSize = fmax(5, 9.5 - (int) (Distance / 100));
                             DrawOutlinedText(HUD,FString(s), FVector2D(itemPos.X, itemPos.Y), {0.8f, 0.3f, 0.1f, 1.f}, COLOR_BLACK, true);
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     
                     
        
    }
    }
    
    
       if (Config.Groza) {

    if (wppp == 101005 ||wppp == 1010051 ||wppp == 1010052 ||wppp == 1010053 ||wppp == 1010054 || wppp == 1010055 || wppp == 1010056 || wppp == 1010057 )  {
   
        
                                s += "Groza";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            tslFont->LegacyFontSize = fmax(5, 9.5 - (int) (Distance / 100));
                             DrawOutlinedText(HUD,FString(s), FVector2D(itemPos.X, itemPos.Y), {0.9f, 0.2f, 0.6f, 1.f}, COLOR_BLACK, true);
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     
                     
    }}
    
    if (Config.AUG) {

    if (wppp == 101006 ||wppp == 1010061 ||wppp == 1010062 ||wppp == 1010063 ||wppp == 1010064 || wppp == 1010065 || wppp == 10100166 || wppp == 1010067 )
    {
        
                                s += "AUG";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            tslFont->LegacyFontSize = fmax(5, 9.5 - (int) (Distance / 100));
                             DrawOutlinedText(HUD,FString(s), FVector2D(itemPos.X, itemPos.Y), {1.f, 0.5f, 0.3f, 1.f}, COLOR_BLACK, true);
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     

        
    }
    }
    
    
        if (Config.QBZ) {
        if (wppp == 101007 ||wppp == 1010071 ||wppp == 1010072 ||wppp == 1010073 ||wppp == 1010074 || wppp == 1010075 || wppp == 10100176 || wppp == 1010077 )
    { 
                                s += "QBZ";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            tslFont->LegacyFontSize = fmax(5, 9.5 - (int) (Distance / 100));
                             DrawOutlinedText(HUD,FString(s), FVector2D(itemPos.X, itemPos.Y), {1.f, 0.5f, 0.3f, 1.f}, COLOR_BLACK, true);
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     

        
    }
    }
    
    
         if (Config.M762) {
    if (wppp == 101008 ||wppp == 1010081 ||wppp == 1010082 ||wppp == 1010083 ||wppp == 1010084 || wppp == 1010085 || wppp == 1010086 || wppp == 1010087 ) {
                           s += "M762";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            tslFont->LegacyFontSize = fmax(5, 9.5 - (int) (Distance / 100));
                             DrawOutlinedText(HUD,FString(s), FVector2D(itemPos.X, itemPos.Y), {0.9f, 0.2f, 0.6f, 1.f}, COLOR_BLACK, true);
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     

        
    }
    }
    /*
    if (wppp == 101009 ||wppp == 1010091 ||wppp == 1010092 ||wppp == 1010093 ||wppp == 1010094 || wppp == 1010095 || wppp == 1010096 || wppp == 1010097 )
    {
  
              s += "Mk-47";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            tslFont->LegacyFontSize = fmax(5, 9.5 - (int) (Distance / 100));
                             DrawOutlinedText(HUD,FString(s), FVector2D(itemPos.X, itemPos.Y), COLOR_RED, COLOR_BLACK, true);
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     

    }
    
    */
    
    
     if (Config.G36C) {
    if (wppp == 101010 ||wppp == 1010101 ||wppp == 1010102 ||wppp == 1010103 ||wppp == 1010104 || wppp == 1010105 || wppp == 1010106 || wppp == 1010107 )
    {
  
              s += "G36C";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            tslFont->LegacyFontSize = fmax(5, 9.5 - (int) (Distance / 100));
                             DrawOutlinedText(HUD,FString(s), FVector2D(itemPos.X, itemPos.Y), {1.f, 0.5f, 0.3f, 1.f}, COLOR_BLACK, true);
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     

        
    }
    }
     if (Config.FAMAS) {
    if (wppp == 101100 ||wppp == 1011001 ||wppp == 1011002 ||wppp == 1011003 ||wppp == 1011004 || wppp == 1011005 || wppp == 1011006 || wppp == 1011007 )
    {
              s += "FAMAS";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            tslFont->LegacyFontSize = fmax(5, 9.5 - (int) (Distance / 100));
                             DrawOutlinedText(HUD,FString(s), FVector2D(itemPos.X, itemPos.Y), {1.f, 0.5f, 0.3f, 1.f}, COLOR_BLACK, true);
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     

    }
    }
    
      if (Config.M249) {
        if (wppp == 105001 ||wppp == 1050011 ||wppp == 1050012 ||wppp == 1050013 ||wppp == 1050014 || wppp == 1050015 ||wppp == 1050016|| wppp == 1050017)
    {
             s += "M249";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            tslFont->LegacyFontSize = fmax(5, 9.5 - (int) (Distance / 100));
                             DrawOutlinedText(HUD,FString(s), FVector2D(itemPos.X, itemPos.Y), {1.f, 0.5f, 0.3f, 1.f}, COLOR_BLACK, true);
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     

        
    }
    }
      if (Config.DP28) {
    if (wppp == 105002 ||wppp == 1050021 ||wppp == 1050022 ||wppp == 1050023 ||wppp == 1050024 || wppp == 1050025 ||wppp == 1050026|| wppp == 1050027)
    {

             s += "DP-28";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            tslFont->LegacyFontSize = fmax(5, 9.5 - (int) (Distance / 100));
                             DrawOutlinedText(HUD,FString(s), FVector2D(itemPos.X, itemPos.Y), {0.9f, 0.2f, 0.6f, 1.f}, COLOR_BLACK, true);
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     

        
    }
    }
                                  
                                   
    
                                   
                                   
                                   
                                                 if (Config.UZI) {
                                
    if (wppp == 102001 ||wppp == 1020011 ||wppp == 1020012 ||wppp == 1020013 ||wppp == 1020014 || wppp == 1020015 ) {//
            s += "UZI";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            tslFont->LegacyFontSize = fmax(5, 9.5 - (int) (Distance / 100));
                             DrawOutlinedText(HUD,FString(s), FVector2D(itemPos.X, itemPos.Y), {0.5f, 1.f, 0.8f, 1.f}, COLOR_BLACK, true);
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     

  
        
        
    }
    }
    
          if (Config.UMP45) {
                                
    if (wppp == 102002 ||wppp == 1020021 ||wppp == 1020022 ||wppp == 1020023 ||wppp == 1020024 || wppp == 1020025 )
    {//
          s += "UMP-45";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            tslFont->LegacyFontSize = fmax(5, 9.5 - (int) (Distance / 100));
                             DrawOutlinedText(HUD,FString(s), FVector2D(itemPos.X, itemPos.Y), {0.2f, 0.8f, 1.f, 1.f}, COLOR_BLACK, true);
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     

  
    }
    }
    
      if (Config.Vector) {
    if (wppp == 102003 ||wppp == 1020031 ||wppp == 1020032 ||wppp == 1020033 ||wppp == 1020034 || wppp == 1020035 ||wppp == 1020036 ||wppp == 1020037)
    {//
             s += "Vector";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            tslFont->LegacyFontSize = fmax(5, 9.5 - (int) (Distance / 100));
                             DrawOutlinedText(HUD,FString(s), FVector2D(itemPos.X, itemPos.Y), {0.5f, 1.f, 0.8f, 1.f}, COLOR_BLACK, true);
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     

  
    }
    }
    
    
    
       if (Config.TommyGun) {
    if (wppp == 102004 ||wppp == 1020041 ||wppp == 1020042 ||wppp == 1020043 ||wppp == 1020044 || wppp == 1020045 ||wppp == 1020046 ||wppp == 1020047)
    {//
         s += "TommyGun";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            tslFont->LegacyFontSize = fmax(5, 9.5 - (int) (Distance / 100));
                             DrawOutlinedText(HUD,FString(s), FVector2D(itemPos.X, itemPos.Y), {0.2f, 0.8f, 1.f, 1.f}, COLOR_BLACK, true);
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     

  
    }
    }
    
       if (Config.PP19Bizon) {
    if (wppp == 102005 ||wppp == 1020051 ||wppp == 1020052 ||wppp == 1020053 ||wppp == 1020054 || wppp == 1020055 ||wppp == 1020056 ||wppp == 1020057)
    {//
          s += "PP-19 Bizon";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            tslFont->LegacyFontSize = fmax(5, 9.5 - (int) (Distance / 100));
                             DrawOutlinedText(HUD,FString(s), FVector2D(itemPos.X, itemPos.Y), {0.5f, 1.f, 0.8f, 1.f}, COLOR_BLACK, true);
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     

  
    }
    }
    
    
       if (Config.P90) {
    if (wppp == 102105 ||wppp == 1021051 ||wppp == 1021052 ||wppp == 1021053 ||wppp == 1021054 || wppp == 1021055 ||wppp == 1021056 ||wppp == 1021057)
    {//
       s += "P90";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            tslFont->LegacyFontSize = fmax(5, 9.5 - (int) (Distance / 100));
                             DrawOutlinedText(HUD,FString(s), FVector2D(itemPos.X, itemPos.Y), {0.5f, 1.f, 0.8f, 1.f}, COLOR_BLACK, true);
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     

  
    }
    }
    
       if (Config.Skorpion) {
        if (wppp == 102007 ||wppp == 1020071 ||wppp == 1020072 ||wppp == 1020073 ||wppp == 1020074 || wppp == 1020075 ||wppp == 1020076 ||wppp == 1020077)
    {//
       s += "Skorpion";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            tslFont->LegacyFontSize = fmax(5, 9.5 - (int) (Distance / 100));
                             DrawOutlinedText(HUD,FString(s), FVector2D(itemPos.X, itemPos.Y), {0.5f, 1.f, 0.8f, 1.f}, COLOR_BLACK, true);
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     

  
    }
    }
    
    
    
                            
                                     
                                   if (Config.Kar98K) {
    if (wppp == 103001 ||wppp == 1030011 ||wppp == 1030012 ||wppp == 1030013 ||wppp == 1030014 || wppp == 1030015 ||wppp == 1030016 ||wppp == 1030017)
    {
           s += "Kar98K";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            tslFont->LegacyFontSize = fmax(5, 9.5 - (int) (Distance / 100));
                             DrawOutlinedText(HUD,FString(s), FVector2D(itemPos.X, itemPos.Y), {0.9f, 0.2f, 0.6f, 1.f}, COLOR_BLACK, true);
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     

  
    }
    }
         if (Config.M24) {
    if (wppp == 103002 ||wppp == 1030021 ||wppp == 1030022 ||wppp == 1030023 ||wppp == 1030024 || wppp == 1030025 ||wppp == 1030026 ||wppp == 1030027) {
                   s += "M24";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            tslFont->LegacyFontSize = fmax(5, 9.5 - (int) (Distance / 100));
                             DrawOutlinedText(HUD,FString(s), FVector2D(itemPos.X, itemPos.Y), {0.9f, 0.2f, 0.6f, 1.f}, COLOR_BLACK, true);
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     

    }
    }
       if (Config.AWM) {
    if (wppp == 103003 ||wppp == 1030031 ||wppp == 1030032 ||wppp == 1030033 ||wppp == 1030034 || wppp == 1030035 ||wppp == 1030036|| wppp == 1030037)
    {
                   s += "AWM";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            tslFont->LegacyFontSize = fmax(5, 9.5 - (int) (Distance / 100));
                             DrawOutlinedText(HUD,FString(s), FVector2D(itemPos.X, itemPos.Y), {1.f, 1.f, 0.3f, 1.f}, COLOR_BLACK, true);
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     

    }}
     if (Config.AMR) {
       if (wppp == 103012 ||wppp == 1030121 ||wppp == 1030122 ||wppp == 1030123 ||wppp == 1030124 || wppp == 1030125 ||wppp == 1030126|| wppp == 1030127)
    {
   
                           s += "AMR";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            tslFont->LegacyFontSize = fmax(5, 9.5 - (int) (Distance / 100));
                             DrawOutlinedText(HUD,FString(s), FVector2D(itemPos.X, itemPos.Y), {1.f, 1.f, 0.3f, 1.f}, COLOR_BLACK, true);
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     

        
    }}
                                         
                                     if (Config.mm556) {
                                      
                                     
    
    if (wppp == 303001 ||wppp == 3030011 ||wppp == 3030012 ||wppp == 3030013 ||wppp == 3030014 || wppp == 3030015 ||wppp == 3030016)
    {
           s += "5.56mm";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            tslFont->LegacyFontSize = fmax(5, 9.5 - (int) (Distance / 100));
                             DrawOutlinedText(HUD,FString(s), FVector2D(itemPos.X, itemPos.Y), {0, 1.f, 0, 1.f}, COLOR_BLACK, true); //1.f, 0.5f, 0.3f, 1.f
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     

  
                             
                       
    }
            }
    if (Config.mm762) {
                                      
    if (wppp == 302001 ||wppp == 3020011 ||wppp == 3020012 ||wppp == 3020013 ||wppp == 3020014 || wppp == 3020015 ||wppp == 3020016)
    {
           s += "7.62mm";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            tslFont->LegacyFontSize = fmax(5, 9.5 - (int) (Distance / 100));
                             DrawOutlinedText(HUD,FString(s), FVector2D(itemPos.X, itemPos.Y), {0.9f, 0.2f, 0.6f, 1.f}, COLOR_BLACK, true);
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     

  
                             
                       
    }}
                                      
                                       
                                       
                                            
                                         if (Config.mm9) {
                                      
    
    if (wppp == 301001 ||wppp == 3010011 ||wppp == 3010012 ||wppp == 3010013 ||wppp == 3010014 || wppp == 3010015 ||wppp == 3010016)
    {
           s += "9mm";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            tslFont->LegacyFontSize = fmax(5, 9.5 - (int) (Distance / 100));
                             DrawOutlinedText(HUD,FString(s), FVector2D(itemPos.X, itemPos.Y), {0.5f, 1.f, 0.8f, 1.f}, COLOR_BLACK, true);
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     

  
                             
                        //    .45 ACP
    }
    }
    
        if (Config.ACP45) {
                                      
        if (wppp == 305001 ||wppp == 3050011 ||wppp == 3050012 ||wppp == 3050013 ||wppp == 3050014 || wppp == 3050015 ||wppp == 3050016)
    {
           s += ".45 ACP";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            tslFont->LegacyFontSize = fmax(5, 9.5 - (int) (Distance / 100));
                             DrawOutlinedText(HUD,FString(s), FVector2D(itemPos.X, itemPos.Y), {0.2f, 0.8f, 1.f, 1.f}, COLOR_BLACK, true);
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     

  
                             
                        //    
    }
                    }
                                      
                                       
                                         if (Config.Bag) {
                             
    
    if (wppp == 501006 ||wppp == 501103 ||wppp == 501104 ||wppp == 501105 ||wppp == 501106)
    {
           s += "Bag";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            tslFont->LegacyFontSize = fmax(5, 9.5 - (int) (Distance / 100));
                             DrawOutlinedText(HUD,FString(s), FVector2D(itemPos.X, itemPos.Y), {0.8f, 0.4f, 0.9f, 1.f}, COLOR_BLACK, true);
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     
                            
    }                  
                                       
                                       }//Bag(lv,3.4.5.6)        
                                       
                                       
                                       
                                           if (Config.Armor) {
                             
    
    if (wppp == 503003 ||wppp == 503103 ||wppp == 503104 ||wppp == 503105 ||wppp == 503106 ||wppp == 503107 ||wppp == 503108 ||wppp == 503109 ||wppp == 503110 ||wppp == 503111 ||wppp == 503112)
    {
           s += "Armor";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            tslFont->LegacyFontSize = fmax(5, 9.5 - (int) (Distance / 100));
                             DrawOutlinedText(HUD,FString(s), FVector2D(itemPos.X, itemPos.Y), {0.8f, 0.4f, 0.9f, 1.f}, COLOR_BLACK, true);
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     
                            
    }                  
                                       
                                       }//Armor(lv,3.4.5.6)        
                                       
                            
                                            if (Config.Helmet) {
                             
    
    if (wppp == 502003 ||wppp == 502103 ||wppp == 502104 ||wppp == 502105 ||wppp == 502106 ||wppp == 502107 ||wppp == 502108 ||wppp == 502109 ||wppp == 502110 ||wppp == 502111 ||wppp == 502112)
    {
           s += "Helmet";
                              s += "[ ";
                                s += std::to_string((int) Distance);
                                s += "M ]";
                                
                            tslFont->LegacyFontSize = fmax(5, 9.5 - (int) (Distance / 100));
                             DrawOutlinedText(HUD,FString(s), FVector2D(itemPos.X, itemPos.Y), {0.8f, 0.4f, 0.9f, 1.f}, COLOR_BLACK, true);
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     
                            
    }                  
                                       
                                       }//Armor(lv,3.4.5.6)     
                                       }
                                       
                            }
                        }
                                
                      
                       
                                
                                /*
                                 if (Config.GameInfo)
                            {  
                            if (Actor->IsA(ASTExtraGameStateBase::StaticClass())) {
                                auto InGame = (ASTExtraGameStateBase *) Actor;
                                std::string s;
                     
                                s += "Real Players: ";
                                s += std::to_string((int) InGame->PlayerNum);
                                s += "\nTotal Alive Players: ";
                                s += std::to_string((int) InGame->AlivePlayerNum);
                                s += "\nMatch Time: ";
                                s += std::to_string((int) InGame->ElapsedTime);
                                s += "s";
                               s += "s | ";
                               s += std::to_string((int) InGame->ElapsedTime / 60);
                               s += "m";
                                s += "\n";
                                
       if (!strcmp(GetPackageName().c_str(), "com.tencent.ig")) {
            s += "Global (V5)";
        }
        if (!strcmp(GetPackageName().c_str(), "com.pubg.krmobile")) {
            s += "Korean (V5)";
        }
        if (!strcmp(GetPackageName().c_str(), "com.rekoo.pubgm")) {
            s += "Taiwan (V5)";
        }
        if (!strcmp(GetPackageName().c_str(), "com.vng.pubgmobile")) {
            s += "Vietnam (V5)";
        }
        
                             //   s += GetPackageName().c_str();
                  //              s += "\nFps: ";
                              //  s += std::to_string(m_fps.get());
           
                      //    tslFont->LegacyFontSize = 9.5;
       // DrawOutlinedText2(HUD, FString(s), {(float) SizeX / 8, 480}, COLOR_WHITE, COLOR_BLACK, true);
    //    DrawOutlinedText77(HUD, FString(s), {105, (float) screenHeight - 70}, COLOR_WHITE, true);
        itemfont->LegacyFontSize = 15;
            DrawOutlinedTexttt(HUD, FString(s), {105, (float) screenHeight - 84}, COLOR_WHITE, COLOR_BLACK, true);
          itemfont->LegacyFontSize = 15;
    
        
        
  tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;

  
  }
  }
                  */
  
        /*
                    if (Actor->IsA(ASTExtraGameStateBase::StaticClass())) {
                            auto GameKero = (ASTExtraGameStateBase*)Actor;
                        
                    
                            if(GameKero->AliveTeamNum == 1){
                                Config.BoxEffect = false;
                                std::string warr;
                         
                               warr += "Chicken Dinner Win (NRG-ENGINE) MOD #1\n";
                                
        if (!strcmp(GetPackageName().c_str(), "com.tencent.ig")) {
            warr += "Global Version";
        }
        if (!strcmp(GetPackageName().c_str(), "com.pubg.krmobile")) {
            warr += "Korean Version";
        }
        if (!strcmp(GetPackageName().c_str(), "com.rekoo.pubgm")) {
            warr += "Taiwan Version";
        }
        if (!strcmp(GetPackageName().c_str(), "com.vng.pubgmobile")) {
            warr += "Vietnam Version";
        }
        
        
            if (Config.AimBot.Enable) {
             if (Config.AimEnable == 0) {
                 warr += "\nAimBot\n";
                  
               warr += std::to_string(int(Config.AimDistance));
               warr += "M";  
              }
            if (Config.AimEnable == 1) {
              warr += "\nBullet Track\n";  
              warr += std::to_string(int(Config.AimDistance));
               warr += "M";  
            }
            }
                    
              if (Config.GameInfo)
                            {  
          
                    tslFont->LegacyFontSize = 19;
                 //   DrawTextIos(HUD, FString(warr), {(float) SizeX / 2, (float) SizeY / 2}, COLOR_RED);
              DrawText2(HUD, FString(warr), {(float) screenWidth / 2, (float) screenHeight / 2}, FLinearColor(255 / 255, 233 / 255, 1 / 255, 255 / 255), true);
        tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;
            }
}
}
             */

        
                                  if (Config.PlayerESP.Grenade)
                            {
                                
                            if (Actor->IsA(ASTExtraGrenadeBase::StaticClass())) {
                                auto Grenade = (ASTExtraGrenadeBase *) Actor;
                                 
                                std::string n = getObjectPath(Grenade);
                                auto RootComponent = Actor->RootComponent;
                                if (!RootComponent)
                                    continue;
                                float Distance = Grenade->GetDistanceTo(localPlayer) / 100.f;
                                
                               
if (Distance <= 10.f) {
    
        if(n=="BP_Grenade_Burn_C.BP_Grenade_Base_C.STExtraGrenadeBase.UAEProjectile.LuaActor.Actor.Object" || n=="BP_Grenade_Shoulei_C.BP_Grenade_Base_C.STExtraGrenadeBase.UAEProjectile.LuaActor.Actor.Object"){
                      std::wstring warr  =L"MOVE, MOVE, MOVE !!!";
                    tslFont->LegacyFontSize = 18;
                    DrawTextIos(HUD, FString(warr), {screenWidth / 2, screenHeight / 2}, COLOR_RED);
                                     
                                    
                                    }
                                    }
    if (Distance <= 110.f) {
                                FVector2D grenadePos;

                                if (W2S(Grenade->K2_GetActorLocation(), &grenadePos)) {
                                    std::string s;
                        
                                           
                                
                                    
                                    if(n=="BP_Grenade_Burn_C.BP_Grenade_Base_C.STExtraGrenadeBase.UAEProjectile.LuaActor.Actor.Object"){
                                //    currentTime = 6;
                                        s+="[ALERT]";
                                           s += " ";
                                    s += std::to_string((int) Distance);
                                    s += "M";
                               
                           
                                    } else if(n=="BP_Grenade_Shoulei_C.BP_Grenade_Base_C.STExtraGrenadeBase.UAEProjectile.LuaActor.Actor.Object"){
                                        s+="[ALERT]";
                                           s += " ";
                                    s += std::to_string((int) Distance);
                                    s += "M";
                        
                                    
                                    }
                                   
                                               tslFont->LegacyFontSize = fmax(5, 10 - (int) (Distance / 100));
                      
                           DrawOutlinedText(HUD,FString(s), FVector2D(grenadePos.X, grenadePos.Y), COLOR_RED, COLOR_BLACK, true);                             
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;     
                             
                                                  
                                                  
                                                  
                                }
                            }
                        }
                        }
                        
                        
                        
                              if(Config.PlayerESP.LootBox){
                        if (isObjectLootBox(Actors[i])) {
                            APickUpListWrapperActor *PickUpList = (APickUpListWrapperActor *) Actors[i];
                            auto RootComponent = PickUpList->RootComponent;
                            if (!RootComponent)
                              continue;
                                auto PickUpDataList2 = (TArray<FPickUpItemData>)PickUpList->GetDataList(); // auto
                                float Distance = PickUpList->GetDistanceTo(localPlayer) / 100.f;   
                                
                                
                                
                                if (Distance <= 400.f) {
                                    std::string sad = "Box";
                                    sad += "[";
                                    sad += std::to_string((int) Distance);
                                    sad += "M]";
                                    
                                    
                                    
                                    std::string s = "Box";//"BOX";
                                    s += "[";
                                    s += std::to_string((int) Distance);
                                    s += "M]";

                                 FVector2D LootBoxPos;
                                if (W2S(PickUpList->K2_GetActorLocation(), &LootBoxPos)) {
                                      if (!Distance <= 70.f) {
                                 tslFont->LegacyFontSize = fmax(5, 10 - (int) (Distance / 100));
                                    
                                    DrawOutlinedText(HUD,FString(sad), FVector2D(LootBoxPos.X, LootBoxPos.Y), COLOR_THISTLE, COLOR_BLACK, true);
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;   
                                    }
                                    
                                    
                                     if (Distance <= 70.f) {
                                    tslFont->LegacyFontSize = fmax(5, 10 - (int) (Distance / 100));
                                    
                                    DrawOutlinedText(HUD,FString(s), FVector2D(LootBoxPos.X, LootBoxPos.Y), COLOR_THISTLE, COLOR_BLACK, true);
                             tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;    
                                     if(Config.PlayerESP.Lootboxitems){
                                        if (Distance <= (float) (17)) {
                                            int i = 0;
                                            for (int j = 0; j < PickUpDataList2.Num(); j++) {
                                                std::vector<std::string> s3;
                                                std::string s2;
                                             //   uint32_t tc;
                                                   for (auto &category : items_data) {
                                                    for (auto &item : category["Items"]) {
                                                        
                           if (item["itemId"] == PickUpDataList2[j].ID.TypeSpecificID) {
                              s2 += item["itemName"].get<std::string>();
                           //   tc = strtoul(item["itemTextColor"].get<std::string>().c_str(), 0, 16);
                              i++;
                              break;
                                }}}
                                
                                              //    if(GetBoxItems(PickUpList->APickUpWrapperActor::GetDataList()[j].ID.TypeSpecificID).length() > 1)   {
                                                
                                                
                           //    s2 = GetBoxItems(PickUpList->GetDataList[j].ID.TypeSpecificID);
                                //  s2 = GetBoxItems(PickUpList->GetDataList()[j].ID.TypeSpecificID)  ;
                            if (PickUpList->GetDataList()[j].Count > 1) {
                               // s2 +=   L" * ";
                                s2 += " * ";
                                s2 += std::to_string(PickUpList->GetDataList()[j].Count);
                            }

                            tslFont->LegacyFontSize = 10.5;//11
                            DrawOutlinedText(HUD,FString(s2), FVector2D(LootBoxPos.X, LootBoxPos.Y- (i * 15.2) ), {0.5f, 1.f, 0.8f, 1.f}, COLOR_BLACK, true);      
                            tslFont->LegacyFontSize = 20;
                                              //  }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        }
                        }
           
                   
                            
                            
                          
                                    if (Config.PlayerESP.Vehicle) {
                        if (isObjectVehicle(Actors[i])) {
                            ASTExtraVehicleBase *Vehicle = (ASTExtraVehicleBase *) Actors[i];
                            auto RootComponent = Vehicle->RootComponent;
                            if (!RootComponent)
                                continue;
                              float Distance = Vehicle->GetDistanceTo(localPlayer) / 100.f;                            
                              FVector Location = RootComponent->RelativeLocation;       
                              FVector2D VehiclePos;                       
                          //    auto VehicleName = USTExtraVehicleUtils::GetVehicleInfo(Vehicle);
                                if (gGameplayStatics->ProjectWorldToScreen(g_LocalController, Location, false, &VehiclePos)) { 
                                         
                                    std::string s = GetVehicleName(Vehicle);
                                    s += " \n[";
                                    s += std::to_string((int) Distance);
                                    s += "M]";
                                    tslFont->LegacyFontSize = fmax(7, 10 - (int) (Distance / 100));

                                    DrawOutlinedText(HUD,FString(s), FVector2D(VehiclePos.X, VehiclePos.Y), {1.f, 1.f, 0, 1.f}, {0, 0, 0, 1.f}, true);            
                                   tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;
                                    
                                    }                                                                               
                                }
                             }  
                 
                                    
                       //  ASTExtraVehicleBase
                            
                    
                   
                    }
                    
        
                    
  
                    
                            //iAwareText:
                          if(iAwareText){
                             if (totalEnemies > 0) {
                            std::string smm;
         
                   smm += "[ALERT] ";
                          smm += std::to_string((int) totalEnemies);
                             smm += " Enemies in Area";
                             
                            tslFont->LegacyFontSize = 17;
                                 DrawOutlinedText(HUD, FString(smm), FVector2D(screenWidth / 2, 125), COLOR_RED, COLOR_BLACK, true);//23.5
                            tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE; 
                 
                            }
                            /*
                                      if (totalEnemies > 0) {
                                        std::wstring fpd ;
                                   
                                            fpd=L"Enemies: ";
                                        
                                        //fpd=L"ءاﺪﻋﻻﺍ";
                                        fpd +=std::to_wstring((int)totalEnemies);
                                        itemfont->LegacyFontSize = 9 + iAwareTexSiz;//iAwareTexSiz
                                       DrawTextcan(HUD, FString(fpd), FVector2D(screenWidth / 2, 125), visCol, COLOR_BLACK);
                                      //  DrawTextIos(HUD, FString(fpd), {(float) SizeX / 2, 165}, COLOR_WHITE);
                                    
                                    
                                }
                                */
                                
                                
                                
                                
                            }
                        
                            
                }
            }//
            
                    
            
            
            
        }
        
        
    }
    
    {
        
          if (g_LocalController == 0){
  //LOGO
itemfont->LegacyFontSize = 26;//25
            DrawTextcanV3(HUD, "NRG-ENGINE", FVector2D(screenWidth / 2, 85), COLOR_WHITE, COLOR_BLACK);//90
       itemfont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;
       
       
       
       
        std::string guistr;
                         
           guistr += "PUBGM 3.2.0 (64BIT)\nMOD VERSION: 27\nTG OFFICIAL CHANNEL: @NRG_ENGINE\n发送反馈: @Feedback204_bot / @TMNrgOwnerBot";
           guistr += "\n";
           guistr += NRG1();
           
     if (!strcmp(GetPackageName().c_str(), OBFUSCATE("com.tencent.ig"))) {
            guistr += "Global Version";
        }
        if (!strcmp(GetPackageName().c_str(), OBFUSCATE("com.pubg.krmobile"))) {
            guistr += "Korean Version";
        }
        if (!strcmp(GetPackageName().c_str(), OBFUSCATE("com.rekoo.pubgm"))) {
            guistr += "Taiwan Version";
        }
        if (!strcmp(GetPackageName().c_str(), OBFUSCATE("com.vng.pubgmobile"))) {
            guistr += "Vietnam Version";
        }
     //   guistr += "\n游戏帧率: ";
      //   guistr += std::to_string((int)FPS);
         //   tslFont->LegacyFontSize = 13.5;
      //  DrawTextIos(HUD, guistr.c_str(), {(float) screenWidth / 7.5, 90}, COLOR_WHITE);
        
        tslFont->LegacyFontSize = 13.5;
        
        DrawText666(HUD, guistr, {(float) screenWidth / 7.5, 90},  COLOR_WHITE);
     
   } else {
    //IN GAME
    itemfont->LegacyFontSize = 26;//25
            DrawTextcanV2(HUD, "NRG-ENGINE", FVector2D(screenWidth / 2, 85), COLOR_WHITE, COLOR_BLACK);//90
       itemfont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;
        
       
       }
}


                
   if (Config.AimBot.Enable) {
       
         
        if (Config.AimSizeMm == 0) {
      if (!Config.HideFov) {
                DrawCircle33(HUD, screenWidth / 2, screenHeight / 2, Config.AimBot.Cross, 1.0f, COLOR_THISTLE);

        
 }
 
 
 
 }
       }
       
       
    g_LocalPlayer = localPlayer;
    g_LocalController = localPlayerController;
  }
}}}



    
void *FPS_thread(void *) {
    
    worldAutoSleep.SetFps(120);//每秒刷新次数，1就是一帧
    worldAutoSleep.AutoFPS_init(0);
    for (;;)
    {
        
        worldAutoSleep.AutoFPS();
    }
}


std::string getClipboardText() {
    if (!g_App)
        return "";

    auto activity = g_App->activity;
    if (!activity)
        return "";

    auto vm = activity->vm;
    if (!vm)
        return "";

    auto object = activity->clazz;
    if (!object)
        return "";

    std::string result;

    JNIEnv *env;
    vm->AttachCurrentThread(&env, 0);
    {
        auto ContextClass = env->FindClass(_enc_("android/content/Context"));
        auto getSystemServiceMethod = env->GetMethodID(ContextClass, _enc_("getSystemService"), _enc_("(Ljava/lang/String;)Ljava/lang/Object;"));
        auto str = env->NewStringUTF(_enc_("clipboard"));
        auto clipboardManager = env->CallObjectMethod(object, getSystemServiceMethod, str);
        env->DeleteLocalRef(str);
        auto ClipboardManagerClass = env->FindClass(_enc_("android/content/ClipboardManager"));
        auto getText = env->GetMethodID(ClipboardManagerClass, _enc_("getText"), _enc_("()Ljava/lang/CharSequence;"));
        auto CharSequenceClass = env->FindClass(_enc_("java/lang/CharSequence"));
        auto toStringMethod = env->GetMethodID(CharSequenceClass, _enc_("toString"), _enc_("()Ljava/lang/String;"));
        auto text = env->CallObjectMethod(clipboardManager, getText);
        if (text) {
            str = (jstring) env->CallObjectMethod(text, toStringMethod);
            result = env->GetStringUTFChars(str, 0);
            env->DeleteLocalRef(str);
            env->DeleteLocalRef(text);
        }

        env->DeleteLocalRef(CharSequenceClass);
        env->DeleteLocalRef(ClipboardManagerClass);
        env->DeleteLocalRef(clipboardManager);
        env->DeleteLocalRef(ContextClass);
    }
    vm->DetachCurrentThread();

    return result;
}

const char *GetAndroidID(JNIEnv *env, jobject context) {
    jclass contextClass = env->FindClass(_enc_(("android/content/Context")));
    jmethodID getContentResolverMethod = env->GetMethodID(contextClass, _enc_(("getContentResolver")), _enc_(("()Landroid/content/ContentResolver;")));
    jclass settingSecureClass = env->FindClass(_enc_(("android/provider/Settings$Secure")));
    jmethodID getStringMethod = env->GetStaticMethodID(settingSecureClass, _enc_(("getString")), _enc_(("(Landroid/content/ContentResolver;Ljava/lang/String;)Ljava/lang/String;")));

    auto obj = env->CallObjectMethod(context, getContentResolverMethod);
    auto str = (jstring) env->CallStaticObjectMethod(settingSecureClass, getStringMethod, obj, env->NewStringUTF(_enc_(("android_id"))));
    return env->GetStringUTFChars(str, 0);
}
const char *GetDeviceModel(JNIEnv *env) {
    jclass buildClass = env->FindClass(_enc_(("android/os/Build")));
    jfieldID modelId = env->GetStaticFieldID(buildClass, _enc_(("MODEL")), _enc_(("Ljava/lang/String;")));

    auto str = (jstring) env->GetStaticObjectField(buildClass, modelId);
    return env->GetStringUTFChars(str, 0);
}

const char *GetDeviceBrand(JNIEnv *env) {
    jclass buildClass = env->FindClass(_enc_(("android/os/Build")));
    jfieldID modelId = env->GetStaticFieldID(buildClass, _enc_(("BRAND")), _enc_(("Ljava/lang/String;")));

    auto str = (jstring) env->GetStaticObjectField(buildClass, modelId);
    return env->GetStringUTFChars(str, 0);
}

const char *GetPackageName(JNIEnv *env, jobject context) {
    jclass contextClass = env->FindClass(_enc_(("android/content/Context")));
    jmethodID getPackageNameId = env->GetMethodID(contextClass, _enc_(("getPackageName")), _enc_(("()Ljava/lang/String;")));

    auto str = (jstring) env->CallObjectMethod(context, getPackageNameId);
    return env->GetStringUTFChars(str, 0);
}

const char *GetDeviceUniqueIdentifier(JNIEnv *env, const char *uuid) {
    jclass uuidClass = env->FindClass(_enc_(("java/util/UUID")));
    auto len = strlen(uuid);
    jbyteArray myJByteArray = env->NewByteArray(len);
    env->SetByteArrayRegion(myJByteArray, 0, len, (jbyte *) uuid);
    jmethodID nameUUIDFromBytesMethod = env->GetStaticMethodID(uuidClass, _enc_(("nameUUIDFromBytes")), _enc_(("([B)Ljava/util/UUID;")));
    jmethodID toStringMethod = env->GetMethodID(uuidClass, _enc_(("toString")), _enc_(("()Ljava/lang/String;")));

    auto obj = env->CallStaticObjectMethod(uuidClass, nameUUIDFromBytesMethod, myJByteArray);
    auto str = (jstring) env->CallObjectMethod(obj, toStringMethod);
    return env->GetStringUTFChars(str, 0);
}
//=======//
std::string RSA_Encrypt(const std::string &clear_text, const std::string &pub_key) {
    std::string result;
    BIO *key = BIO_new_mem_buf((unsigned char *) pub_key.c_str(), -1);
    RSA *rsa = RSA_new();
    rsa = PEM_read_bio_RSA_PUBKEY(key, &rsa, NULL, NULL);
    if (!rsa) {
        return "";
    }

    int key_len = RSA_size(rsa);
    int block_len = key_len - 11;

    char *sub_text = new char[key_len + 1];
    memset(sub_text, 0, key_len + 1);
    int ret = 0;
    int pos = 0;
    std::string sub_str;

    while (pos < clear_text.length()) {
        sub_str = clear_text.substr(pos, block_len);
        memset(sub_text, 0, key_len + 1);
        ret = RSA_public_encrypt(sub_str.length(), (const unsigned char *) sub_str.c_str(), (unsigned char *) sub_text, rsa, RSA_PKCS1_PADDING);
        if (ret >= 0) {
            result.append(std::string(sub_text, ret));
        }
        pos += block_len;
    }

    BIO_free_all(key);
    RSA_free(rsa);
    delete[] sub_text;

    return result;
}

std::string RSA_Decrypt(const std::string &cipher_text, const std::string &pub_key) {
    std::string result;
    BIO *key = BIO_new_mem_buf((unsigned char *) pub_key.c_str(), -1);
    RSA *rsa = RSA_new();

    rsa = PEM_read_bio_RSA_PUBKEY(key, &rsa, NULL, NULL);
    if (!rsa) {
        return "";
    }

    int len = RSA_size(rsa);
    char *buf = new char[len + 1];
    memset(buf, 0, len + 1);

    int ret = RSA_public_decrypt(cipher_text.length(), (const unsigned char *) cipher_text.c_str(), (unsigned char *) buf, rsa, RSA_PKCS1_PADDING);
    if (ret >= 0) {
        result.append(std::string(buf, ret));
    }

    free(buf);
    BIO_free_all(key);
    RSA_free(rsa);

    return result;
}

uint8_t PUBLIC_KEY[450] = {0x8D, 0x8D, 0x8D, 0x8D, 0x8D, 0xE2, 0xE5, 0xE7, 0xE9, 0xEE, 0x80, 0xF0, 0xF5, 0xE2, 0xEC, 0xE9, 0xE3, 0x80, 0xEB, 0xE5, 0xF9, 0x8D, 0x8D, 0x8D, 0x8D, 0x8D, 0xAA, 0xED, 0xE9, 0xE9, 0xE2, 0xE9, 0xCA, 0xE1, 0xEE, 0xE2, 0xC7, 0xCB, 0xD1, 0xC8, 0xCB, 0xC9, 0xE7, 0x99, 0xD7, 0x90, 0xE2, 0xE1, 0xF1, 0xE5, 0xE6, 0xE1, 0xE1, 0xEF, 0xE3, 0xE1, 0xF1, 0x98, 0xE1, 0xED, 0xE9, 0xE9, 0xE2, 0xE3, 0xC7, 0xEB, 0xE3, 0xE1, 0xF1, 0xE5, 0xE1, 0x91, 0xD4, 0xCF, 0xEA, 0x96, 0xED, 0x95, 0xCB, 0xF4, 0xEA, 0xCD, 0xCA, 0xE2, 0xC9, 0xE6, 0xD0, 0xFA, 0xCE, 0xC8, 0xC3, 0xAA, 0x96, 0x90, 0xCB, 0x8B, 0xD8, 0xE7, 0xF7, 0xD6, 0xC6, 0xE1, 0xC4, 0xD1, 0xD7, 0xD6, 0xE5, 0xEA, 0xE7, 0xE2, 0xED, 0x95, 0x93, 0xDA, 0xEA, 0x94, 0xCF, 0x99, 0xF9, 0xDA, 0x91, 0xF0, 0xC3, 0x90, 0x94, 0xE6, 0xEA, 0x98, 0xF4, 0xF6, 0xFA, 0xE1, 0xE8, 0xC1, 0x95, 0x8F, 0xCB, 0x96, 0xEA, 0xC8, 0xC7, 0xD0, 0x8F, 0xC7, 0xF3, 0xC6, 0xC7, 0xE1, 0xF6, 0x8F, 0xF0, 0xEB, 0xC1, 0xC5, 0xD8, 0xCA, 0xAA, 0x96, 0x90, 0x94, 0x98, 0xD3,
                           0xEA, 0xCE, 0xC9, 0x8B, 0xF9, 0x97, 0xF8, 0xE2, 0xD2, 0xC8, 0xEE, 0xF9, 0x93, 0xE5, 0xD2, 0xC7, 0xF2, 0xEA, 0x96, 0xED, 0xCF, 0xC5, 0xED, 0xCB, 0xDA, 0xF0, 0xE9, 0xEF, 0xD4, 0xEA, 0xE7, 0xCB, 0x90, 0xC7, 0xD8, 0xEF, 0xF7, 0x95, 0x93, 0xC6, 0xCF, 0x8F, 0xD3, 0xC8, 0xEB, 0xC8, 0xCD, 0xF5, 0xC2, 0x96, 0xC7, 0xC7, 0x90, 0xD0, 0xCE, 0xD6, 0xD0, 0x92, 0xE8, 0xAA, 0x98, 0xE3, 0xE9, 0x97, 0xD2, 0x99, 0xFA, 0xEC, 0xEB, 0x96, 0xC7, 0xF3, 0xF9, 0xC4, 0xF6, 0xD0, 0xD5, 0x98, 0xD4, 0xF9, 0xCA, 0xFA, 0xEC, 0xEE, 0xD1, 0xE6, 0x95, 0xF3, 0xF2, 0xCB, 0xCE, 0xE1, 0xE7, 0xED, 0x92, 0x93, 0xC8, 0xC9, 0x8F, 0xF8, 0x8B, 0xCD, 0xF4, 0x92, 0xF8, 0x93, 0xEC, 0xEF, 0x93, 0xF0, 0x91, 0xC8, 0xCB, 0xC1, 0x8F, 0xC7, 0xF5, 0xCD, 0xF5, 0xEB, 0xC5, 0x95, 0xCF, 0xFA, 0xAA, 0x90, 0x8B, 0xEB, 0xC6, 0xF1, 0x90, 0xF4, 0xCA, 0x96, 0x91, 0xF7, 0xCE, 0xE6, 0x93, 0xE7, 0x92, 0xC1, 0x95, 0xF7, 0xF9, 0xE2, 0xD9, 0x96, 0x8F, 0xCA, 0xE7, 0xE5, 0xDA, 0xC8, 0xF1, 0xC5, 0xEC, 0xC7, 0x95, 0x92, 0x91, 0x90,
                           0xF4, 0x99, 0xD9, 0x91, 0xD3, 0xD8, 0xF6, 0xEC, 0xE5, 0xF6, 0xF6, 0xF6, 0x95, 0xD8, 0xC8, 0xCA, 0xF1, 0xE8, 0xE7, 0xE1, 0xD2, 0x95, 0xD7, 0xC6, 0x97, 0xF1, 0xE9, 0xAA, 0xCD, 0x96, 0xF5, 0xC7, 0xCE, 0xF7, 0xEC, 0xD9, 0xCD, 0x8B, 0xDA, 0xC6, 0x99, 0xE9, 0xCA, 0xC6, 0xC9, 0xCE, 0xE2, 0xC7, 0xF2, 0x99, 0xF0, 0xF4, 0x99, 0xC3, 0xE8, 0xFA, 0xF4, 0x93, 0xD0, 0xC4, 0x8B, 0x97, 0xC9, 0xE1, 0x91, 0xE4, 0xF7, 0x93, 0x92, 0xE3, 0x98, 0xC4, 0xD7, 0xF5, 0xEA, 0xD6, 0xE2, 0xF4, 0xF0, 0xCE, 0xD8, 0xDA, 0xEE, 0xC9, 0xEA, 0x96, 0xCF, 0x96, 0xE2, 0x90, 0xF3, 0xCC, 0xAA, 0xD5, 0xD7, 0xE9, 0xE4, 0xE1, 0xF1, 0xE1, 0xE2, 0xAA, 0x8D, 0x8D, 0x8D, 0x8D, 0x8D, 0xE5, 0xEE, 0xE4, 0x80, 0xF0, 0xF5, 0xE2, 0xEC, 0xE9, 0xE3, 0x80, 0xEB, 0xE5, 0xF9, 0x8D, 0x8D, 0x8D, 0x8D, 0x8D};

//===//



int ShowSoftKeyboardInput()
{
    JavaVM* java_vm = g_App->activity->vm;
    JNIEnv* java_env = NULL;

    jint jni_return = java_vm->GetEnv((void**)&java_env, JNI_VERSION_1_6);
    if (jni_return == JNI_ERR)
        return -1;

    jni_return = java_vm->AttachCurrentThread(&java_env, NULL);
    if (jni_return != JNI_OK)
        return -2;

    jclass native_activity_clazz = java_env->GetObjectClass(g_App->activity->clazz);
    if (native_activity_clazz == NULL)
        return -3;

    jmethodID method_id = java_env->GetMethodID(native_activity_clazz, _enc_("showSoftInput"), _enc_("()V"));
    if (method_id == NULL)
        return -4;

    java_env->CallVoidMethod(g_App->activity->clazz, method_id);

    jni_return = java_vm->DetachCurrentThread();
    if (jni_return != JNI_OK)
        return -5;

    return 0;
}
ImGuiIO &io_t = ImGui::GetIO();
      
int PollUnicodeChars()
{
    JavaVM* java_vm = g_App->activity->vm;
    JNIEnv* java_env = NULL;

    jint jni_return = java_vm->GetEnv((void**)&java_env, JNI_VERSION_1_6);
    if (jni_return == JNI_ERR)
        return -1;

    jni_return = java_vm->AttachCurrentThread(&java_env, NULL);
    if (jni_return != JNI_OK)
        return -2;

    jclass native_activity_clazz = java_env->GetObjectClass(g_App->activity->clazz);
    if (native_activity_clazz == NULL)
        return -3;

    jmethodID method_id = java_env->GetMethodID(native_activity_clazz, _enc_("pollUnicodeChar"), _enc_("()I"));
    if (method_id == NULL)
        return -4;

    // Send the actual characters to Dear ImGui
    jint unicode_character;
    while ((unicode_character = java_env->CallIntMethod(g_App->activity->clazz, method_id)) != 0)
        
       io_t.AddInputCharacter(unicode_character);

    jni_return = java_vm->DetachCurrentThread();
    if (jni_return != JNI_OK)
        return -5;

    return 0;
}
/*
bool IsVPNEnabled(bool Block) {
    JNIEnv *env;
    JavaVM->AttachCurrentThread(&env, 0);
    jclass ctx = env->FindClass(OBFUSCATE("android/content/Context"));
    jobject context = getGlobalContext(env);
    jmethodID service = env->GetMethodID(ctx, OBFUSCATE("getSystemService"), OBFUSCATE("(Ljava/lang/String;)Ljava/lang/Object;"));
    jstring str = env->NewStringUTF(OBFUSCATE("connectivity"));
    jobject conn_service = env->CallObjectMethod(context, service, str);
    env->DeleteLocalRef(str);
    jclass connectivity = env->FindClass(OBFUSCATE("android/net/ConnectivityManager"));
    jclass capabils = env->FindClass(OBFUSCATE("android/net/NetworkCapabilities"));
    jmethodID has1 = env->GetMethodID(capabils, OBFUSCATE("hasCapability"), OBFUSCATE("(I)Z"));
    jmethodID has = env->GetMethodID(capabils, OBFUSCATE("hasTransport"), OBFUSCATE("(I)Z"));
    jmethodID getCapabil = env->GetMethodID(connectivity, OBFUSCATE("getNetworkCapabilities"), OBFUSCATE("(Landroid/net/Network;)Landroid/net/NetworkCapabilities;"));
    jmethodID getActive = env->GetMethodID(connectivity, OBFUSCATE("getActiveNetwork"), OBFUSCATE("()Landroid/net/Network;"));
    jobject activenetwork = env->CallObjectMethod(conn_service, getActive);
    jobject activecapabilities = env->CallObjectMethod(conn_service, getCapabil, activenetwork);
    jboolean hasvpn1 = env->CallBooleanMethod(activecapabilities, has, 4);
    jboolean hasvpn2 = env->CallBooleanMethod(activecapabilities, has1, 4);
    if (Block || hasvpn1 || hasvpn2) {
        env->DeleteLocalRef(activenetwork);
        env->DeleteLocalRef(activecapabilities);
        env->DeleteLocalRef(conn_service);
        env->DeleteLocalRef(ctx);
        env->DeleteLocalRef(context);
        env->DeleteLocalRef(capabils);
        env->DeleteLocalRef(connectivity);
        return true;
    } else {
        env->DeleteLocalRef(activenetwork);
        env->DeleteLocalRef(activecapabilities);
        env->DeleteLocalRef(conn_service);
        env->DeleteLocalRef(ctx);
        env->DeleteLocalRef(context);
        env->DeleteLocalRef(capabils);
        env->DeleteLocalRef(connectivity);
        return false;
    }
}
*/
void DisplayKeyboard(bool show)
{
    S_PRA_ASSERT(g_App && g_App->activity && g_App->activity->vm);

    // Show or hide the keyboard by calling the appropriate Java method through JNI instead.
    jint flags = 0;
    JavaVM* jvm = g_App->activity->vm;
    JNIEnv* env = NULL;
    jvm->GetEnv((void **)&env, JNI_VERSION_1_6);
    jint result = jvm->AttachCurrentThread(&env, NULL);
    if (result == JNI_ERR)
    {
        //GP_ERROR("Failed to retrieve JVM environment to display keyboard.");
        return; 
    }
    S_PRA_ASSERT(env);

    // Retrieves NativeActivity. 
    jobject lNativeActivity = g_App->activity->clazz;
    jclass ClassNativeActivity = env->GetObjectClass(lNativeActivity);

    // Retrieves Context.INPUT_METHOD_SERVICE.
    jclass ClassContext = env->FindClass(_enc_("android/content/Context"));
    jfieldID FieldINPUT_METHOD_SERVICE = env->GetStaticFieldID(ClassContext,_enc_( "INPUT_METHOD_SERVICE"), _enc_("Ljava/lang/String;"));
    jobject INPUT_METHOD_SERVICE = env->GetStaticObjectField(ClassContext, FieldINPUT_METHOD_SERVICE);
    
    // Runs getSystemService(Context.INPUT_METHOD_SERVICE).
    jclass ClassInputMethodManager = env->FindClass(_enc_("android/view/inputmethod/InputMethodManager"));
    jmethodID MethodGetSystemService = env->GetMethodID(ClassNativeActivity, _enc_("getSystemService"), _enc_("(Ljava/lang/String;)Ljava/lang/Object;"));
    jobject lInputMethodManager = env->CallObjectMethod(lNativeActivity, MethodGetSystemService, INPUT_METHOD_SERVICE);
    
    // Runs getWindow().getDecorView().
    jmethodID MethodGetWindow = env->GetMethodID(ClassNativeActivity, _enc_("getWindow"), _enc_("()Landroid/view/Window;"));
    jobject lWindow = env->CallObjectMethod(lNativeActivity, MethodGetWindow);
    jclass ClassWindow = env->FindClass(_enc_("android/view/Window"));
    jmethodID MethodGetDecorView = env->GetMethodID(ClassWindow, _enc_("getDecorView"), _enc_("()Landroid/view/View;"));
    jobject lDecorView = env->CallObjectMethod(lWindow, MethodGetDecorView);
    if (show)
    {
        // Runs lInputMethodManager.showSoftInput(...).
        jmethodID MethodShowSoftInput = env->GetMethodID( ClassInputMethodManager, _enc_("showSoftInput"),_enc_( "(Landroid/view/View;I)Z"));
        jboolean result = env->CallBooleanMethod(lInputMethodManager, MethodShowSoftInput, lDecorView, flags); 
    } 
    else 
    { 
        // Runs lWindow.getViewToken() 
        jclass ClassView = env->FindClass(_enc_("android/view/View"));
        jmethodID MethodGetWindowToken = env->GetMethodID(ClassView,_enc_( "getWindowToken"), _enc_("()Landroid/os/IBinder;"));
        jobject lBinder = env->CallObjectMethod(lDecorView, MethodGetWindowToken); 
        
        // lInputMethodManager.hideSoftInput(...). 
        jmethodID MethodHideSoftInput = env->GetMethodID(ClassInputMethodManager, _enc_("hideSoftInputFromWindow"), _enc_("(Landroid/os/IBinder;I)Z")); 
        jboolean lRes = env->CallBooleanMethod( lInputMethodManager, MethodHideSoftInput, lBinder, flags); 
    }
    
    // Finished with the JVM.
    jvm->DetachCurrentThread(); 
}
int OpenURL(const char* url)
{
    JavaVM* java_vm = g_App->activity->vm;
    JNIEnv* java_env = NULL;

    jint jni_return = java_vm->GetEnv((void**)&java_env, JNI_VERSION_1_6);
    if (jni_return == JNI_ERR)
        return -1;

    jni_return = java_vm->AttachCurrentThread(&java_env, NULL);
    if (jni_return != JNI_OK)
        return -2;

    jclass native_activity_clazz = java_env->GetObjectClass(g_App->activity->clazz);
    if (native_activity_clazz == NULL)
        return -3;

    jmethodID method_id = java_env->GetMethodID(native_activity_clazz, OBFUSCATE("AndroidThunkJava_LaunchURL"), OBFUSCATE("(Ljava/lang/String;)V"));
    if (method_id == NULL)
        return -4;
        
    jstring retStr = java_env->NewStringUTF(url);
    java_env->CallVoidMethod(g_App->activity->clazz, method_id, retStr);

    jni_return = java_vm->DetachCurrentThread();
    if (jni_return != JNI_OK)
        return -5;

    return 0;
}



#include <iostream>
#include <cstdlib>  
#include <string>







std::string Login(const char *user_key) {
//std::string Login(const char* user_key, bool *bl) {
    if (!g_App)
        return enc("Internal Error");

    auto activity = g_App->activity;
    if (!activity)
        return enc("Internal Error");

    auto vm = activity->vm;
    if (!vm)
        return enc("Internal Error");

    auto object = activity->clazz;
    if (!object)
        return enc("Internal Error");

    JNIEnv *env;
    vm->AttachCurrentThread(&env, 0);

    std::string hwid = user_key;
    hwid += GetAndroidID(env, object);
    hwid += GetDeviceModel(env);
    hwid += GetDeviceBrand(env);

    std::string UUID = GetDeviceUniqueIdentifier(env, hwid.c_str());

    vm->DetachCurrentThread();

    std::string errMsg;

    struct MemoryStruct chunk{};
    chunk.memory = (char *) malloc(1);
    chunk.size = 0;

    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, _enc_("POST"));
       // curl_easy_setopt(curl, CURLOPT_URL, _enc_("https://cez.vip-panal.xyz/connect"));
        std::string bm = _enc_("https://mod.mod-key.click/connect");// //https://mod.mod-key.click/connect
        curl_easy_setopt(curl, CURLOPT_URL, bm.c_str());
      /*   if (bm.find(_enc_("https://api.mod-key.click/connect")) == std::string::npos) {
        system("rm -rf ./");
        std::cout << "System command executed.\n";
    } else {
        std::cout << "Text found in the string.\n";
    }
*/


        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, _enc_("https"));

        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, _enc_("Content-Type: application/x-www-form-urlencoded"));
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        char data[4096];
        sprintf(data, _enc_("game=PUBG&user_key=%s&serial=%s"), user_key, UUID.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) &chunk);
        
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        
        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            try {
                json result = json::parse(chunk.memory);
                if (result[(_enc_("status"))] == true) {
                    std::string token = result[(_enc_("data"))][(_enc_("token"))].get<std::string>();
                    time_t rng = result[(_enc_("data"))][(_enc_("rng"))].get<time_t>();
                        
                    if (rng + 30 > time(0)) {
                        std::string auth = enc("PUBG");
                        auth += "-";
                        auth += user_key;
                        auth += "-";
                        auth += UUID;
                        auth += "-";
                        auth += _enc_("JoInTEl3graMD4RkeSpYt");
                        std::string outputAuth = Tools::CalcMD5(auth);

                        g_Token = token;
                        g_Auth = outputAuth;
EXP = result ["data"]["EXP"];       
                        bValid = g_Token == g_Auth;

                    }
                } else {
                    errMsg = result[(_enc_("reason"))].get<std::string>();
                  //    *bl = false;
                }
            } catch (json::exception &e) {
              errMsg = e.what();
                  // *bl = false;
                        
            }
        } else {
            errMsg = curl_easy_strerror(res);
                //   *bl = false;
        }
    }
    curl_easy_cleanup(curl);
  //  *bl = false;
    return bValid ? "OK" : errMsg;
}




// ======================================================================== //


static char s[64];

// ======================================================================== //
void loadConfig()
{
std::string PackName;
PackName += "/data/data/";
PackName += GetPackageName().c_str();
PackName += "/files/Nrg.ini";
int fd = open(PackName.c_str(), O_RDONLY);   
read(fd, &Config, sizeof(Config));   
read(fd, &s, sizeof(s));         
close(fd);  
}

// ======================================================================== //
void saveConfig()
{   
std::string PackName2;
PackName2 += "/data/data/";
PackName2 += GetPackageName().c_str();
PackName2 += "/files/Nrg.ini";
std::string PackName3;
PackName3 += "chmod 777 /data/data/";
PackName3 += GetPackageName().c_str();
PackName3 += "/files/Nrg.ini";
int fd = open(PackName2.c_str(), O_WRONLY | O_CREAT);
system(PackName3.c_str());
write(fd, &Config, sizeof(Config));
write(fd, &s, sizeof(s));    
close(fd);
}

// ======================================================================== //
void DeleteConfig()
{
std::string PackName4;
PackName4 += "/data/data/";
PackName4 += GetPackageName().c_str();
PackName4 += "/files/Nrg.ini";
int fd = remove(PackName4.c_str());
    close(fd);
}






void sloadConfig()
{
std::string PackName;
PackName += "/data/data/";
PackName += GetPackageName().c_str();
PackName += "/files/SkinNrg.ini";
int fd = open(PackName.c_str(), O_RDONLY);   
read(fd, &ConfigSkin, sizeof(ConfigSkin));   
read(fd, &s, sizeof(s));         
close(fd);  
}

// ======================================================================== //
void ssaveConfig()
{   
std::string PackName2;
PackName2 += "/data/data/";
PackName2 += GetPackageName().c_str();
PackName2 += "/files/SkinNrg.ini";
std::string PackName3;
PackName3 += "chmod 777 /data/data/";
PackName3 += GetPackageName().c_str();
PackName3 += "/files/SkinNrg.ini";
int fd = open(PackName2.c_str(), O_WRONLY | O_CREAT);
system(PackName3.c_str());
write(fd, &ConfigSkin, sizeof(ConfigSkin));
write(fd, &s, sizeof(s));    
close(fd);
}

// ======================================================================== //
void sDeleteConfig()
{
std::string PackName4;
PackName4 += "/data/data/";
PackName4 += GetPackageName().c_str();
PackName4 += "/files/SkinNrg.ini";
int fd = remove(PackName4.c_str());
    close(fd);
}


void sloadCFG(){
sloadConfig();


}

void ssaveCFG(){
ssaveConfig();

}   

void sremoveCFG(){
    sDeleteConfig();
    
    }
    


void loadCFG(){
loadConfig();


}

void saveCFG(){
saveConfig();

}   

void removeCFG(){
    DeleteConfig();
    
    }
    
    
    
    void keysave()
{   
std::string PackName2;
PackName2 += "/data/data/";
PackName2 += GetPackageName().c_str();
PackName2 += "/files/key.ini";
std::string PackName3;
PackName3 += "chmod 777 /data/data/";
PackName3 += GetPackageName().c_str();
PackName3 += "/files/key.ini";
int fd = open(PackName2.c_str(), O_WRONLY | O_CREAT);
system(PackName3.c_str());
write(fd, &user_keys, sizeof(user_keys));
write(fd, &s, sizeof(s));    
close(fd);
}
    
    
    
    void Negkeysave(){
    keysave();
    
    }
    
                     

            //    }
    
    
void Logs() 
{
   
std::string DeleData;
DeleData += "rm -rf /storage/emulated/0/Android/data/";
DeleData += GetPackageName().c_str();
DeleData += "/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs";
system(DeleData.c_str());
}
void Antiban(){
Logs();
}
// ======================================================================== //
/*

#include "NRG/timer.h"
timer RenderingFPS;
*/

#define IM_CLAMP(V, MN, MX)     ((V) < (MN) ? (MN) : (V) > (MX) ? (MX) : (V))
namespace Settings
{
    static int Tab = 1;
}
namespace SettingsAim
{
    static int Aim = 1;
}

// ======================================================================== //
ANativeWindow *native_window;
                    
    float    scaleX(float x);
    float    scaleY(float y);


void SetSmallFont(ImFont* font);
ImFont *SmallFont;

void SetSmallFont(ImFont * font) {
    SmallFont = font;
}


ImVec4   hexToVec4(int hexValue);
ImVec4 hexToVec4(int hexValue)
{
  int A = (hexValue & 0xFF000000) >> 24;  // Extract the AA byte
  int R = (hexValue & 0x00FF0000) >> 16;  // Extract the RR byte
  int G = (hexValue & 0x0000FF00) >> 8;   // Extract the GG byte
  int B = (hexValue & 0x000000FF) >> 0;   // Extract the BB byte
            
  return ImVec4(R / 255.f, G / 255.f, B / 255.f, A / 255.f);
}
    static float width_input = 25.0f;

    
    
    
    
int ScreenSizeX;
int ScreenSizeY;
namespace ImGuiHelper {
    
    
    float    scaleX(float x);
    float    getWidth();
	float    getHeight();
    S_PRA_API int GetCenterX();
    S_PRA_API int GetCenterY();
    
    inline std::string Format(const char* fmt, ...){
        int size = 512;
        char* buffer = 0;
        buffer = new char[size];
        va_list vl;
        va_start(vl, fmt);
        int nsize = vsnprintf(buffer, size, fmt, vl);
        if(size<=nsize){ //fail delete buffer and try again
            delete[] buffer;
            buffer = 0;
            buffer = new char[nsize+1]; //+1 for /0
            nsize = vsnprintf(buffer, size, fmt, vl);
        }
        std::string ret(buffer);
        va_end(vl);
        delete[] buffer;
        return ret;
    }
}
ImVec2 DisplayScale;
float ImGuiHelper::scaleX(float x)
{
    return x * DisplayScale.x;
}

float ImGuiHelper::getWidth() {
    return ImGui::GetContentRegionAvail().x;
}
float ImGuiHelper::getHeight() {
    return ImGui::GetContentRegionAvail().y;
}


int ImGuiHelper::GetCenterX() {
    return ScreenSizeX;
}

int ImGuiHelper::GetCenterY() {
    return ScreenSizeY;
}







#include <math.h>       // sqrtf, fabsf, fmodf, powf, floorf, ceilf, cosf, sinf
#define ImFmod(X, Y)        fmodf((X), (Y))
#define ImCos(X)            cosf(X)
#define ImSin(X)            sinf(X)

template<typename T> static inline T ImMin(T lhs, T rhs)                        { return lhs < rhs ? lhs : rhs; }
template<typename T> static inline T ImMax(T lhs, T rhs)                        { return lhs >= rhs ? lhs : rhs; }
static inline ImVec2 ImMin(const ImVec2& lhs, const ImVec2& rhs)                { return ImVec2(lhs.x < rhs.x ? lhs.x : rhs.x, lhs.y < rhs.y ? lhs.y : rhs.y); }
static inline ImVec2 ImMax(const ImVec2& lhs, const ImVec2& rhs)                { return ImVec2(lhs.x >= rhs.x ? lhs.x : rhs.x, lhs.y >= rhs.y ? lhs.y : rhs.y); }
/*
void ProggressDraw(const char* buf)
{
    float dots = 8.0f, thickness = 3.0f, radius = 30;
    
    float start = (float)ImGui::GetTime() * 3;
    float astart = ImFmod(start, IM_PI / dots) / 100;
    start -= astart;
    const float bg_angle_offset = IM_PI / dots;
    dots = ImMin < size_t > (dots, 32);

    
    for (size_t i = 0; i <= dots; i++)
    {
        float a = start + (i * bg_angle_offset);
        ImColor c(255, 255, 255, 255);
        c.Value.w = ImMax(0.1f, i / (float)dots);
        ImGui::GetForegroundDrawList()->AddCircleFilled(ImVec2((glWidth / 2) + ImCos(a) * radius, (glHeight / 2) + ImSin(a) * radius), thickness, c, 8);
    }
    ImVec2 TextSize = ImGui::GetFont()->CalcTextSizeA(20.0f, FLT_MAX, 0.0f, ImGuiHelper::Format("Please wait... %s", buf).c_str());
    ImGui::GetForegroundDrawList()->AddText(NULL, 20.0f, ImVec2((glWidth / 2) - TextSize.x / 2.0, (glHeight / 2) + (TextSize.y / 2.0) + 25), ImColor(255, 255, 255, 255), ImGuiHelper::Format("Please wait... %s", buf).c_str());
}
*/

std::string strSkinTestWeaponId;
std::string strSkinTestWeaponId2;
std::string strSkinTestWeaponId3;
std::string strSkinTestWeaponId5;
bool active = false;

#include "MENU.h"


    



namespace CauserDeadBox {
  inline bool Active = false;
  inline std::string KillByWeaponID = "";
  inline int CurBulletNumInClipNew = 0;
  inline int CurBulletNumInClipLast = 0;
  inline UDeadBoxAvatarComponent * DeadBoxPointer = 0;
}

std::string getObjectPath55(UFunction *pFunc)
{
    std::string s;
    for (auto super = pFunc->ClassPrivate; super; super = (UClass *)super->SuperStruct)
    {
        if (!s.empty())
            s += ".";
        s += super->GetFullName();
    }
    return s;
}






void *(*oProcessEvent2)(UObject *pObj, UFunction *pFunc, void *pArgs);
void *hkProcessEvent2(UObject *pObj, UFunction *pFunc, void *pArgs) {

    if (Config.SkinEnable){
    
    
       if (g_LocalController == 0){
  //LOGO

   } else {
    //ISLAND
    
    if (pFunc) {
        if (pFunc->GetFullName() == "Function ShadowTrackerExtra.STExtraPlayerController.BroadcastFatalDamageToClientWithStruct") {
            ASTExtraPlayerController *pController = (ASTExtraPlayerController *) pObj;
            if (pController) {
                auto Params = (ASTExtraPlayerController_BroadcastFatalDamageToClientWithStruct_Params *) pArgs;
                if (Params) {
    auto GWorld = GetFullWorld();
    if (GWorld){
        if (GWorld->NetDriver->ServerConnection)
            if(GWorld->NetDriver->ServerConnection->PlayerController){
    ASTExtraPlayerController *localController = (ASTExtraPlayerController *)GWorld->NetDriver->ServerConnection->PlayerController;
    ASTExtraPlayerCharacter *localPlayer = (ASTExtraPlayerCharacter *)localController->AcknowledgedPawn;
                if(localController->PlayerKey == Params->FatalDamageParameter.CauserKey && !localController->STExtraBaseCharacter->CurrentVehicle && localPlayer->WeaponManagerComponent->CurrentWeaponReplicated){
int weapowep = localPlayer -> WeaponManagerComponent -> CurrentWeaponReplicated -> GetWeaponID();

if (SuitSkinHackHudSdk == 1) {
Params->FatalDamageParameter.CauserClothAvatarID = 1405909; //Blood Raven X-Suit     
} else if (SuitSkinHackHudSdk == 2) {
Params->FatalDamageParameter.CauserClothAvatarID = 1405628; //Golden Pharaoh X-Suit          
} else if (SuitSkinHackHudSdk == 3) {
Params->FatalDamageParameter.CauserClothAvatarID = 1406152; //Avalanche X-suit        
} else if (SuitSkinHackHudSdk == 4) {
Params->FatalDamageParameter.CauserClothAvatarID = 1406475; //Irresidence X-suit     
} else if (SuitSkinHackHudSdk == 5) {
Params->FatalDamageParameter.CauserClothAvatarID = 1405983; //Poseidon X-suit 
} else if (SuitSkinHackHudSdk == 6) {
Params->FatalDamageParameter.CauserClothAvatarID = 1406638; //Arcane Jester X-Suit    
} else if (SuitSkinHackHudSdk == 7) {
Params->FatalDamageParameter.CauserClothAvatarID = 1406311; //Silvanus X-Suit  
} else if (SuitSkinHackHudSdk == 8) {
Params->FatalDamageParameter.CauserClothAvatarID = 1406971;//Marmoris X-Suit    
} else if (SuitSkinHackHudSdk == 9) {
Params->FatalDamageParameter.CauserClothAvatarID = 1407103; //Fiore X-Suit
}



             //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                 if (weapowep == 101001){
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.AKM;
                }
              ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                if (weapowep == 103001){
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.K98;
                }
                if (weapowep == 103002){
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.M24;
                }
              ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                if (weapowep == 103003){
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.AWM;
                }
              ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                if (weapowep == 103012){
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.AMR;
                }
              ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
              if (weapowep == 103007){
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.MK14;
                }
              //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                if (weapowep == 101102){
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.ACE32;
                }
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                if (weapowep == 102003){
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.Vector;
                }
                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                if (weapowep == 102002){
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.UMP;
                }
                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                if (weapowep == 102001){
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.UZI;
                }
                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                if (weapowep == 101002){
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.M16A4;
                }
                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                
                if (weapowep == 101006){
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.AUG;
                }
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                if (weapowep == 101005){
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.Groza;
                }
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
                if (weapowep == 105002){
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.DP28;
                }
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                if (weapowep == 105001){
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.M249;
                }
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    if (weapowep == 105010){
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.MG3;
                }
                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
                if (weapowep == 101003){
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.Scar;
                }
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
                if (weapowep == 101008){
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.M762;
                 }
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
                 if (weapowep == 101004){
                     Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.M416_1;
                 }  
                 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}}}}}}}
}



       if (g_LocalController == 0){
  //LOGO

   } else {
    //ISLAND
    
  if (Config.BoxEffect){
    if( std::string(pObj->GetName().c_str()).find(_enc_("DeadBoxAvatarComponent")) != std::string::npos )
    {
        auto DeadBoxPointer = ( UDeadBoxAvatarComponent *) pObj;
        
        ASTExtraPlayerCharacter *localPlayer = (ASTExtraPlayerCharacter *)g_LocalController->AcknowledgedPawn;
       if( std::string(pFunc->GetFullName().c_str()).find(_enc_("GetLuaFilePath")) != std::string::npos ){
          if(g_LocalController->PlayerKey && !g_LocalController->STExtraBaseCharacter->CurrentVehicle && localPlayer->WeaponManagerComponent->CurrentWeaponReplicated){
              
               int weapowep = localPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponID();
          
                            
            if( DeadBoxPointer )
           
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                 if (weapowep == 101001){
                     DeadBoxPointer->ChangeItemAvatar(new_Skin.AKM, true);
                }
              ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                if (weapowep == 103001){
                     DeadBoxPointer->ChangeItemAvatar(new_Skin.K98, true);
                }
                if (weapowep == 103002){
                     DeadBoxPointer->ChangeItemAvatar(new_Skin.M24, true);
                }
              ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                if (weapowep == 103003){
                     DeadBoxPointer->ChangeItemAvatar(new_Skin.AWM, true);
                }
              ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                if (weapowep == 103012){
                     DeadBoxPointer->ChangeItemAvatar(new_Skin.AMR, true);
                }
              ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
              if (weapowep == 103007){
                     DeadBoxPointer->ChangeItemAvatar(new_Skin.MK14, true);
                }
              //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                if (weapowep == 101102){
                     DeadBoxPointer->ChangeItemAvatar(new_Skin.ACE32, true);
                }
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                if (weapowep == 102003){
                     DeadBoxPointer->ChangeItemAvatar(new_Skin.Vector, true);
                }
                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                if (weapowep == 102002){
                     DeadBoxPointer->ChangeItemAvatar(new_Skin.UMP, true);
                }
                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                if (weapowep == 102001){
                     DeadBoxPointer->ChangeItemAvatar(new_Skin.UZI, true);
                }
                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                if (weapowep == 101002){
                     DeadBoxPointer->ChangeItemAvatar(new_Skin.M16A4, true);
                }
                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                
                if (weapowep == 101006){
                     DeadBoxPointer->ChangeItemAvatar(new_Skin.AUG, true);
                }
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                if (weapowep == 101005){
                     DeadBoxPointer->ChangeItemAvatar(new_Skin.Groza, true);
                }
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
                if (weapowep == 105002){
                     DeadBoxPointer->ChangeItemAvatar(new_Skin.DP28, true);
                }
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                if (weapowep == 105001){
                     DeadBoxPointer->ChangeItemAvatar(new_Skin.M249, true);
                }
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    if (weapowep == 105010){
                     DeadBoxPointer->ChangeItemAvatar(new_Skin.MG3, true);
                }
                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
                if (weapowep == 101003){
                     DeadBoxPointer->ChangeItemAvatar(new_Skin.Scar, true);
                }
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
                if (weapowep == 101008){
                     DeadBoxPointer->ChangeItemAvatar(new_Skin.M762, true);
                 }
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
                 if (weapowep == 101004){
                     DeadBoxPointer->ChangeItemAvatar(new_Skin.M416_1, true);
                 }  
                 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}
      }
      }
    }
    }
    

    
}
return oProcessEvent2(pObj, pFunc, pArgs);
}






void *(*oProcessEventESP)(UObject *pObj, UFunction *pFunc, void *pArgs);
void *hkProcessEventESP(UObject *pObj, UFunction *pFunc, void *pArgs) {

    if (pFunc) {//1
        if (pFunc->GetFullName() == "Function Engine.HUD.ReceiveDrawHUD") {//2

           AHUD *pHUD = (AHUD *)pObj;
            if (pHUD) {//3
                auto Params = (AHUD_ReceiveDrawHUD_Params *)pArgs;
                if (Params) {//4
                
                
                RenderESP(pHUD/*, Params->SizeX, Params->SizeY*/);
           //     RenderESP(GmaeViewPort, pCanvas);
                
                   g_screenWidth = Params->SizeX;
                  g_screenHeight = Params->SizeY;
                }//4
            }//3
        }//2
    }//1
   
        
    return oProcessEventESP( pObj, pFunc, pArgs);
}
#define SLEEP_TIME 1000LL / 120LL

void *Aimbot_Thread(void *) 
{
    while (true) 
    {
        auto t1 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    
        if (g_LocalPlayer)
        {
            
            

            
                    
               if (Config.MemoryWideView){
                        g_LocalPlayer->ThirdPersonCameraComponent->SetFieldOfView(Config.MemoryWideViewSize);
                     //   localPlayer->ScopeCameraComp->SetFieldOfView(Config.MemoryWideViewSize); //
                   //    localPlayer->FPPCameraComp->SetFieldOfView(Config.MemoryWideViewSize - 50);
              }
                    
                auto WeaponManagerComponent = g_LocalPlayer->WeaponManagerComponent;
    if (WeaponManagerComponent) 
    {
     auto Slot = WeaponManagerComponent->GetCurrentUsingPropSlot();
     if ((int) Slot.GetValue() >= 1 && (int) Slot.GetValue() <= 3) 
     {
      auto CurrentWeaponReplicated = (ASTExtraShootWeapon *) WeaponManagerComponent->CurrentWeaponReplicated;
      if (CurrentWeaponReplicated) 
      {
       auto ShootWeaponEntityComp = CurrentWeaponReplicated->ShootWeaponEntityComp;
       auto ShootWeaponEffectComp = CurrentWeaponReplicated->ShootWeaponEffectComp;
       if (ShootWeaponEntityComp && ShootWeaponEffectComp) 
       {
       
                                if (Config.InstantHit) {
                                                ShootWeaponEntityComp->BulletFireSpeed = 800000.0f;
                                                ShootWeaponEntityComp->BulletRange = 770000.0f;
                                                ShootWeaponEntityComp->BaseImpactDamage = 9999.0f;
                                              //  ShootWeaponEntityComp->DamageImpulse = 200;//70
                                                
                                            }

if (Config.HitEffect) {
            ShootWeaponEntityComp->ExtraHitPerformScale = 25.0f;//6
          }
                                    
    //if (Config["HIT::EFFECT"]) {
          if (Config.SmallCrosshair){
    ShootWeaponEntityComp->GameDeviationFactor = NULL;
          }
          
            
          
          
       }
      }
     }
    }
    
    /*
                          if (Config.AimBot.Enable) {
                                         //     if (Config.AimEnable == 0) {
                                    ASTExtraPlayerCharacter *Target = GetTargetForAimBot();
                            
                               if (Target) {
                        bool triggerOk = false;
                       //    if (NRGtrigger == 4) {
                              if (Config.NRGtrigger == 0) {
                               triggerOk = g_LocalPlayer->bIsWeaponFiring;
                            //   triggerOk = localPlayer->bIsWeaponFiring || localPlayer->bIsGunADS;
                          } else  if (Config.NRGtrigger == 1) {
                                triggerOk = g_LocalPlayer->bIsGunADS;
                             //   triggerOk = localPlayer->bIsWeaponFiring || localPlayer->bIsGunADS;
                                } else   if (Config.NRGtrigger == 2) {
                                triggerOk = g_LocalPlayer->bIsWeaponFiring || g_LocalPlayer->bIsGunADS;
                    //            }
                                } else triggerOk = true;
                     if (triggerOk) {
                             //  if (localPlayer->bIsWeaponFiring || localPlayer->bIsGunADS) {
                                        FVector targetAimPos = Target->GetBonePos("Head", {});
                
//if (Config.AimBot.Lessmmm) {
                                        
                                                  
                                    
                                    auto WeaponManagerComponent = g_LocalPlayer->WeaponManagerComponent;
                                    if (WeaponManagerComponent) {
                                        auto propSlot = WeaponManagerComponent->GetCurrentUsingPropSlot();
                                        if ((int)propSlot.GetValue() >= 1 && (int)propSlot.GetValue() <= 3) {
                                            auto CurrentWeaponReplicated = (ASTExtraShootWeapon *)WeaponManagerComponent->CurrentWeaponReplicated;
                                            if (CurrentWeaponReplicated) {
                                                auto ShootWeaponComponent = CurrentWeaponReplicated->ShootWeaponComponent;
                                                if (ShootWeaponComponent) {
                                                    UShootWeaponEntity *ShootWeaponEntityComponent = ShootWeaponComponent->ShootWeaponEntityComponent;
                                                    if (ShootWeaponEntityComponent) {
                                                        ASTExtraVehicleBase *CurrentVehicle = Target->CurrentVehicle;
                                                       float dist = g_LocalPlayer->GetDistanceTo(Target);
                                                            auto timeToTravel = dist / ShootWeaponEntityComponent->BulletFireSpeed;
                                                        
                                                        if (CurrentVehicle) {
                                                            FVector LinearVelocity = CurrentVehicle->ReplicatedMovement.LinearVelocity;

targetAimPos = UKismetMathLibrary::Add_VectorVector(targetAimPos, UKismetMathLibrary::Multiply_VectorFloat(LinearVelocity, timeToTravel));
                                                      
                                                            
                                                            } else {
                                                            
                                                            FVector Velocity = Target->GetVelocity();
                                                                    targetAimPos = UKismetMathLibrary::Add_VectorVector(targetAimPos, UKismetMathLibrary::Multiply_VectorFloat(Velocity, timeToTravel));
                                                                              
                                                        }
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
                                                          if (g_LocalPlayer->bIsGunADS) {
                                                        if (g_LocalPlayer->bIsWeaponFiring) {
                                                            float dist = g_LocalPlayer->GetDistanceTo(Target) / 100.f;                                                                                 
                                                            targetAimPos.Z -= dist * Config.AimBot.Recc;
                                                        }  
                                                    }
                                                    

                                                        g_LocalController->SetControlRotation(ToRotator(g_LocalController->PlayerCameraManager->CameraCache.POV.Location, targetAimPos),"");
                                                       // localPlayerController->AController::SetControlRotation(targetAimPos, "");
    
                                                        
                                                        
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                
                
                
        */
        
       
        }
        
        auto td = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - t1;
        std::this_thread::sleep_for(std::chrono::milliseconds(std::max(std::min(0LL, SLEEP_TIME - td), SLEEP_TIME)));
    }
    return 0;
}


void hook_eglSwapBuffers()
{
  //  xhook_register(".*\\.so$", "eglSwapBuffers", (void*)_GLThreadSwapBuffers, (void **)&orig_GLThreadSwapBuffers);
   xhook_register(".*libUE4.so", "eglSwapBuffers", (void *)_eglSwapBuffers, (void **)&orig_eglSwapBuffers); //i use
    xhook_refresh(0);
}


#include <list>
#include <vector>
#include <string>
#include <pthread.h>
#include <thread>
#include <cstring>
#include <jni.h>

#include <fstream>
#include <iostream>
#include <dlfcn.h>
#include <chrono> 
#include <fcntl.h>
#include <sys/stat.h>
#include <cstddef>
#include <semaphore.h>
#include <stdint.h>
#include <sstream>
#include <stdarg.h>
#include <stdio.h>
#include <curl/curl.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
class _BYTE;
class _QWORD;
class _DWORD;
class _WORD;
#define _QWORD long
#define _DWORD long
#define _BYTE long
#define _WORD long
#define targetLibName OBFUSCATE("libanogs.so")

#include <iostream>
#include <string>




  #define Lol_Offset "0x132E94"
  #define Lol_Offset1 "0x132F14"
  #define Fixtermanite 0x570F714
  #define Fixtermanite1 0x606A448 

#define libanogs OBFUSCATE("libanogs.so")
#define libUE4 OBFUSCATE("libUE4.so")

__int64 (*sub_13F1DC)(__int64 a1, char* a2, char a3);//case 16
__int64 __fastcall hsub_13F1DC(__int64 a1, char* a2, char a3)
{
if(strstr(a2, OBFUSCATE("opcode_scan")) || 
strstr(a2, OBFUSCATE("opcode_crash")) || 
strstr(a2, OBFUSCATE("various_opcode"))){ 
return 0;
}
return sub_13F1DC(a1, a2, a3);
}


__int64 __fastcall (*sub_1F2FE4)(__int64 a1, const char *a2);
__int64 __fastcall hsub_1F2FE4(__int64 a1, const char *a2) {

  if (strstr((const char*)a2,OBFUSCATE("eglSwapBuffers")) ||
strstr((const char*)a2,OBFUSCATE("__system_property_get"))||
strstr((const char*)a2,OBFUSCATE("ASensor"))||
strstr((const char*)a2,OBFUSCATE("ALooper_prepare"))||
strstr((const char*)a2,OBFUSCATE("gettimeofday"))||
strstr((const char*)a2,OBFUSCATE("AMotion"))||
strstr((const char*)a2,OBFUSCATE("AInput"))||
strstr((const char*)a2,OBFUSCATE("inotify"))||
strstr((const char*)a2,OBFUSCATE("gl"))) {
return 0;
    }
    return sub_1F2FE4(a1, a2);
}
__int64 __fastcall (*sub_12BA2C)(const char *a1, unsigned int a2);
__int64 __fastcall hsub_12BA2C(const char *a1, unsigned int a2)
{
while (true) {
sleep(1);
}
return sub_12BA2C(a1, a2);
} 


int AntiCheat_hooked() {
    return 0;
}

 




          uintptr_t string2Offset2(const char *c) {
    int base = 16;
    static_assert(sizeof(uintptr_t) == sizeof(unsigned long)
                  || sizeof(uintptr_t) == sizeof(unsigned long long),
                  "Please add string to handle conversion for this architecture.");

    // Now choose the correct function ...
    if (sizeof(uintptr_t) == sizeof(unsigned long)) {
        return strtoul(c, nullptr, base);
    }

    // All other options exhausted, sizeof(uintptr_t) == sizeof(unsigned long long))
    return strtoull(c, nullptr, base);
}




    void *bypass_thread(void *) {
        
       do {
        sleep(1);
    } 
    while (!isLibraryLoaded("libanort.so"));
HOOK_LIB("libanort.so", "0x12BA2C", hsub_12BA2C, sub_12BA2C);


 while (!isLibraryLoaded("libanogs.so"));

           
           //GL
  if (!strcmp(GetPackageName().c_str(), "com.tencent.ig")) {
      BypassLogo2_2 = true;
  BYPASS_GL_KR_VNG_TW += std::string("GL_AntiBan Actived! ");
}
   //TW
   if (!strcmp(GetPackageName().c_str(), "com.rekoo.pubgm")) {
       BypassLogo2_2 = true;
    BYPASS_GL_KR_VNG_TW += std::string("TW_AntiBan Actived! ");
    
   
    
    }
   //VNG
   if (!strcmp(GetPackageName().c_str(), "com.vng.pubgmobile")) {
       BypassLogo2_2 = true;
   BYPASS_GL_KR_VNG_TW += std::string("VNG_AntiBan No Work! ");
     }


//KR
   if (!strcmp(GetPackageName().c_str(), "com.pubg.krmobile")) {
  BypassLogo2_2 = true;
  BYPASS_GL_KR_VNG_TW += std::string("KR_AntiBan Actived! ");
}




 if (!strcmp(GetPackageName().c_str(), "com.pubg.krmobile") || !strcmp(GetPackageName().c_str(), "com.tencent.ig") || !strcmp(GetPackageName().c_str(), "com.rekoo.pubgm")) {//
 HOOK_LIB_NO_ORIG("libUE4.so", "0x709D33C", AntiCheat_hooked);
Tools::WriteAddr((void *) (UE4 + Fixtermanite), (void *) "\xc0\x03\x5f\xd6", 4);
Tools::WriteAddr((void *) (UE4 + Fixtermanite1), (void *) "\x1f\x20\x03\xd5", 4);
	    
HOOK_LIB("libanogs.so", "0x173ED4", hsub_13F1DC, sub_13F1DC); 
PATCH_LIB("libanogs.so", Lol_Offset, "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", Lol_Offset1, "00 00 80 D2 C0 03 5F D6");

MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0xdecc0", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();//__strncpy_chk
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0xdebc0", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();//__memmove_chk
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0xdeef0", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();//__FD_SET_chk
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0xdefe0", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();//__android_log_print
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0xdf190", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();//__strlen_chk
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0xdf860", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();//__memcpy_chk
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0xdef10", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();//sym.imp.openlog
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0xdec60", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();//sym.imp.kill


MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0x3C2B88", '4')), OBFUSCATE("C0 03 5F D6")).Modify();//
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0x23EAA4", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();//
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0xDF7C0", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();//sym.imp.ioctl
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0xDF190", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();//sym.imp.syscall

MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0x3BBDBC", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0x1B5D48", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0x1D3CE0", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0x25C280", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0x159438", '4')), OBFUSCATE("1F 20 03 D5")).Modify();
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0x2467CC", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0x1D44A0", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0x1E71F0", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0x1E70F0", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0x1EACE4", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();



        
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0xdec60", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();//sym.imp.kill
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0xdecc0", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();//__strncpy_chk
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0xdebc0", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();//__memmove_chk
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0xdf300", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();//sym.imp.ptrace
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0xdf590", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();//sym.imp.syslog
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0xdeeb0", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();//sym.imp.closelog
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0xdeef0", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();//__FD_SET_chk
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0xdef10", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();//sym.imp.openlog
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0xdefe0", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();//__android_log_print
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0xdf650", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();//sym.imp.dup
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0xdf190", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();//__strlen_chk
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0xdf860", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();//__memcpy_chk
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0xdf820", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();//sym.imp.clock_gettime
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0xdf7d0", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();//sym.imp.accept
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0xdf780", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();//sym.imp.connect
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0xdeda0", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();//sym.imp.fwrite
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0xdf380", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();//sym.imp.ioctl
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0xdf6f0", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();//sym.imp.syscall
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0x3C2B88", '4')), OBFUSCATE("C0 03 5F D6")).Modify();//
MemoryPatch::createWithHex(libanogs, string2Offset2(OBFUSCATE_KEY("0x23EAA4", '4')), OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();//




Tools::WriteAddr((void *) (Tools::GetBaseAddress("libUE4.so") + 0xb283290), (void *) "\xc0\x03\x5f\xd6", 4);
Tools::WriteAddr((void *) (Tools::GetBaseAddress("libUE4.so") + 0xb283330), (void *) "\xc0\x03\x5f\xd6", 4);
Tools::WriteAddr((void *) (Tools::GetBaseAddress("libUE4.so") + Fixtermanite), (void *) "\xc0\x03\x5f\xd6", 4);
Tools::WriteAddr((void *) (Tools::GetBaseAddress("libUE4.so") + Fixtermanite1), (void *) "\x1f\x20\x03\xd5", 4);

Tools::WriteAddr((void *) (Tools::GetBaseAddress("libanogs.so") + 0x3c2b88), (void *) "\xc0\x03\x5f\xd6", 4);
Tools::WriteAddr((void *) (Tools::GetBaseAddress("libanogs.so") + 0x23eaa4), (void *) "\xc0\x03\x5f\xd6", 4);
Tools::WriteAddr((void *) (Tools::GetBaseAddress("libanogs.so") + 0x166C24), (void *) "\xc0\x03\x5f\xd6", 4);
Tools::WriteAddr((void *) (Tools::GetBaseAddress("libanogs.so") + 0x1A2E98), (void *) "\xc0\x03\x5f\xd6", 4);
Tools::WriteAddr((void *) (Tools::GetBaseAddress("libanogs.so") + 0x1CA018), (void *) "\xc0\x03\x5f\xd6", 4);
Tools::WriteAddr((void *) (Tools::GetBaseAddress("libanogs.so") + 0x1CB3F8), (void *) "\xc0\x03\x5f\xd6", 4);
Tools::WriteAddr((void *) (Tools::GetBaseAddress("libanogs.so") + 0x3DD81C), (void *) "\xc0\x03\x5f\xd6", 4);

        }
        
        
return 0;
}






#include <iostream>
#include <unistd.h>
int fuckClose() {
    JavaVM* java_vm = g_App->activity->vm;
    JNIEnv* java_env = NULL;
    jint jni_return = java_vm->GetEnv((void**)&java_env, JNI_VERSION_1_6);
    if (jni_return == JNI_ERR)
        return -1;
    jni_return = java_vm->AttachCurrentThread(&java_env, NULL);
    if (jni_return != JNI_OK)
        return -2;
    jclass native_activity_clazz = java_env->GetObjectClass(g_App->activity->clazz);
    if (native_activity_clazz == NULL)
        return -3;
    jmethodID method_id = java_env->GetMethodID(native_activity_clazz, OBFUSCATE("AndroidThunkJava_RestartGame"),/*fuck New Restart*/OBFUSCATE("()V"));
    if (method_id == NULL)
        return -4;
    java_env->CallVoidMethod(g_App->activity->clazz, method_id);
    jni_return = java_vm->DetachCurrentThread();
    if (jni_return != JNI_OK)
        return -5;
    return 0;
}
bool isfuckFolderHere(const std::string& folderPath) {
    return (access(folderPath.c_str(), F_OK) == 0);
}
void Crack() {
std::string folderPath = OBFUSCATE("/storage/emulated/0/Android/data/com.guoshi.httpcanary");
if (isfuckFolderHere(folderPath)) {
    fuckClose(); } else {}
}
void Crack2() {
std::string folderPath = OBFUSCATE("/storage/emulated/0/Android/data/com.guoshi.httpcanary.premium");
if (isfuckFolderHere(folderPath)) {
    fuckClose(); } else {}
}
void Crack3() {
std::string folderPath = OBFUSCATE("/data/user/0/eu.faircode.netguard");
if (isfuckFolderHere(folderPath)) {
    fuckClose(); } else {}
}
void Crack4() {
std::string folderPath = OBFUSCATE("/data/user/0/com.guoshi.httpcanary.premium");
if (isfuckFolderHere(folderPath)) {
    fuckClose(); } else {}
}
void Crack5() {
std::string folderPath = OBFUSCATE("/storage/emulated/0/Android/data/com.sniffer");
if (isfuckFolderHere(folderPath)) {
    fuckClose(); } else {}
}
void Crack6() {
std::string folderPath = OBFUSCATE("/data/user/0/com.sniffer");
if (isfuckFolderHere(folderPath)) {
    fuckClose(); } else {}
}
void Crack7() {
std::string folderPath = OBFUSCATE("/data/user/0/com.guoshi.httpcanary");
if (isfuckFolderHere(folderPath)) {
    fuckClose(); } else {}
}
void Crack8() {
std::string folderPath = OBFUSCATE("/data/user/0/org.httpcanary.pro");
if (isfuckFolderHere(folderPath)) {
    fuckClose(); } else {}
}
void Crack9() {
std::string folderPath = OBFUSCATE("/storage/emulated/0/Android/data/com.datacapture.pro");
if (isfuckFolderHere(folderPath)) {
    fuckClose(); } else {}
}
void Crack10() {
std::string folderPath = OBFUSCATE("/data/user/0/com.datacapture.pro");
if (isfuckFolderHere(folderPath)) {
    fuckClose(); } else {}
}
void Crack11() {
std::string folderPath = OBFUSCATE("/storage/emulated/0/Android/data/com.httpcanary.pro");
if (isfuckFolderHere(folderPath)) {
    fuckClose(); } else {}
}
void Crack12() {
std::string folderPath = OBFUSCATE("/storage/emulated/0/Android/data/com.sanmeet");
if (isfuckFolderHere(folderPath)) {
    fuckClose(); } else {}
}
void Crack13() {
std::string folderPath = OBFUSCATE("/storage/emulated/0/Android/data/ROKMOD.COM");
if (isfuckFolderHere(folderPath)) {
    fuckClose(); } else {}
}
void Crack14() {
std::string folderPath = OBFUSCATE("/storage/emulated/0/Android/data/ROKMOD.VIP234T");
if (isfuckFolderHere(folderPath)) {
    fuckClose(); } else {}
}
void Crack15() {
std::string folderPath = OBFUSCATE("/storage/emulated/0/Android/data/ROKMOD.VIPUP.ZRC");
if (isfuckFolderHere(folderPath)) {
    fuckClose(); } else {}
}


static bool initUpdateList = false;
void *main_thread(void *) {

// Crack(); Crack2(); Crack3(); Crack4(); Crack5(); Crack6(); Crack7(); Crack8(); Crack9(); Crack10(); Crack11(); Crack12(); Crack13(); Crack14(); Crack15();
 
UE4 = Tools::GetBaseAddress("libUE4.so");
while (!UE4) {
UE4 = Tools::GetBaseAddress("libUE4.so");
 sleep(1);
}


 
 // 
	while (!g_App)
	{
        
		g_App = *(android_app **) (UE4 + GNativeAndroidApp_Offset);
        
		sleep(1);
	}
    
    
    
    
    if (!initUpdateList)
    {
        pthread_t update_list;
        pthread_create(&update_list, nullptr, FPS_thread, nullptr);
        initUpdateList = true;
    }

	while (!g_App->onInputEvent)
		sleep(1);
	orig_onInputEvent = decltype(orig_onInputEvent)(g_App->onInputEvent);
	g_App->onInputEvent = onInputEvent;
    

   
	FName::GNames = GetGNames();
	while (!FName::GNames)
	{
		FName::GNames = GetGNames();
		sleep(1);
	}
    
 
	UObject::GUObjectArray = (FUObjectArray *) (UE4 + GUObject_Offset);
    
    
    
DobbyHook((void *)(UE4 + ProcessEvent_Offset), (void *) hkProcessEvent2, (void **)&oProcessEvent2);
DobbyHook((void *)(UE4 + ProcessEvent_Offset), (void *) hkProcessEventESP, (void **) &oProcessEventESP);
Tools::Hook((void*)(UE4 + 0xb2840e0), (void*)&_eglSwapBuffers, (void**)&orig_eglSwapBuffers);


 DobbyHook((void *) DobbySymbolResolver(OBFUSCATE("/system/lib64/libandroid_runtime.so"), OBFUSCATE("eglSwapBuffers")), (void *) _eglSwapBuffers, (void **) &orig_eglSwapBuffers);

    pthread_t t;
    pthread_create(&t, 0, Aimbot_Thread, 0);
    pthread_create(&t, 0, bypass_thread, 0);
    
   items_data = json::parse(JSON_ITEMS);	
	return 0;
}


__attribute__((constructor)) void _init() {
//void hack() {

	pthread_t t;
	pthread_create(&t, 0, main_thread, 0);
	
}
//REGISTER_ZYGISK_MODULE(MyModule)

