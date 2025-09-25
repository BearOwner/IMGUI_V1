#include "Helper/Includes.h"


#include "obfuscate.h"
#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Tools.h"
#include "Helper/fake_dlfcn.h"
#include "Iconcpp.h"
#include "NIKE.h"
#include "Icon.h"
#include "enc.h"
#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_android.h"
#include "imgui/backends/imgui_impl_opengl3.h"
#include "StrEnc.h"
#include "Spoof.h"
#include "Helper/plthook.h"
#include "Helper/Items.h"
#include "Helper/json.hpp"
using json = nlohmann::json;
#include "SDK.hpp"
using namespace SDK;
#include <curl/curl.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include "base64/base64.h"
#include "Font.h"

#include "zygisk.hpp"

#include "define.h"
#include "Rect.h"
#include "KittyMemory/MemoryPatch.h"

//GL
#define GNames_Offset 0x6F7A8C0
#define GUObject_Offset 0xC2BF460
#define GNativeAndroidApp_Offset 0xc05a0b8
#define ProcessEvent_Offset 0x71d9d50
#define Actors_Offset 0xA0
/*
//BGIM
#define GNames_Offset 0x6e069c0
#define GUObject_Offset 0xbdb91e0
#define ProcessEvent_Offset 0x7065d3c
#define GNativeAndroidApp_Offset 0xbb53e38
#define Actors_Offset 0xA0
*/
/*
struct TextureInfo {
    ImTextureID textureId;
    int width;
    int height;
};

TextureInfo imageButton;

static TextureInfo textureInfo;

TextureInfo createTexture(const string &ImagePath) {
    int w, h, n;
    stbi_uc *data = stbi_load(ImagePath.c_str(), &w, &h, &n, 0);
    GLuint texture;
    glGenTextures(1, &texture);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    
    stbi_image_free(data);
    
    textureInfo.textureId = texture;
    textureInfo.width = w;
    textureInfo.height = h;
    return textureInfo;
}

*/
#define Class_Input__get_touchCount (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Input"), OBFUSCATE("get_touchCount"))
//string logoDataBase64 = "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";
char extra[64];

uintptr_t UE4;
uintptr_t anogs;
uintptr_t anort;
uintptr_t gcloud;

json items_data;
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
                    

android_app *g_App = 0;
ASTExtraPlayerCharacter *g_LocalPlayer = 0;
ASTExtraPlayerController *g_LocalController = 0;

FCameraCacheEntry  CameraCache = FCameraCacheEntry();

static float isAutoSlider = -0.20;
static bool MainUiMenu = false;

static std::string EXP = " ";
static std::string SLOT = " ";
static std::string modname = " ";
static std::string mod_status = " ";
static std::string credit = " ";
static std::string key = " ";
bool 绘制初始化 = false;
bool initImGui = false;
int screenWidth = -1, glWidth, screenHeight = -1, glHeight;
float density = -1;

int SizeXx = 0;
int SizeYy = 0;

int ScreenWidthNrg6 =0;
int ScreenHeightNrg6 = 0;

int currentLang = 1;//0
#define SelectLanguage(ch, en) currentLang == 1 ? (ch) : (en)
bool WriteAddr(void *addr, void *buffer, size_t length) {
    unsigned long page_size = sysconf(_SC_PAGESIZE);
    unsigned long size = page_size * sizeof(uintptr_t);
    return mprotect((void *) ((uintptr_t) addr - ((uintptr_t) addr % page_size) - page_size), (size_t) size, PROT_EXEC | PROT_READ | PROT_WRITE) == 0 && memcpy(addr, buffer, length) != 0;
}


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
template <class T>
void GetAllActors(std::vector<T *> &Actors) {
    UGameplayStatics *gGameplayStatics = (UGameplayStatics *)gGameplayStatics->StaticClass();
    auto GWorld = GetWorld();
    if (GWorld) {
        TArray<AActor *> Actors2;
        gGameplayStatics->GetAllActorsOfClass((UObject *)GWorld, T::StaticClass(), &Actors2);
        for (int i = 0; i < Actors2.Num(); i++) {
            Actors.push_back((T *)Actors2[i]);
        }
    }
}
TNameEntryArray *GetGNames()
{
	return ((TNameEntryArray * (*)())(UE4 + GNames_Offset))();
}
FVector GetBoneLocationByName(ASTExtraPlayerCharacter *Actor, const char *BoneName) {
    return Actor->GetBonePos(BoneName, FVector());
}
std::vector<AActor *> getActors()
{
	auto World = GetWorld();
	if (!World)
		return std::vector<AActor *>();

	auto PersistentLevel = World->PersistentLevel;
	if (!PersistentLevel)
		return std::vector<AActor *>();

	auto Actors = *(TArray<AActor *> *)((uintptr_t)PersistentLevel + Actors_Offset);

	std::vector<AActor *> actors;
	for (int i = 0; i < Actors.Num(); i++)
	{
		auto Actor = Actors[i];
		if (Actor)
		{
			actors.push_back(Actor);
		}
	}
	return actors;
}






bool BypassLogo2_2 = true; //AUTO BYPASS



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
int NRGtrigger;
int AimEnable;
int AimSizeMm;
int EnemieCount;
int FPSControl;
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
bool InstantHit;
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
bool Box;
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
EAimBy AimBy;
EAimTarget Target;
EAimTrigger Trigger;
bool IgnoreBot;
bool IgnoreKnocked;
bool Lessmmm;
bool VisCheck;
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



struct sTeamNrg {   
MemoryPatch
//////2.2.0 64bit BYPASS buy -: @TEAMNRG1 /////
BypassLogo,
BypassLogo1,
BypassLogo2,
BypassLogo3,
BypassLogo4,
BypassLogo5,
BypassLogo6,
BypassLogo7,
BypassLogo8,
BypassLogo9,
BypassLogo10,
BypassLogo11,
BypassLogo12,
BypassLogo13,
BypassLogo14,
BypassLogo15,
BypassLogo16,
BypassLogo17,
BypassLogo18,
BypassLogo19,
BypassLogo20,
BypassLogo21,
BypassLogo22,
BypassLogo23;
};
sTeamNrg TeamNrg; 



using zygisk::Api;
using zygisk::AppSpecializeArgs;
using zygisk::ServerSpecializeArgs;

//== это вызов хука 
void hack();
//====

class MyModule : public zygisk::ModuleBase {
 public:
  void onLoad(Api *api, JNIEnv *env) override {
    this->api_ = api;
    this->env_ = env;
  }

  void preAppSpecialize(AppSpecializeArgs *args) override {
    static constexpr const char *packages[] = {
     "com.tencent.ig", "com.pubg.krmobile", "com.vng.pubgmobile", "com.rekoo.pubgm"
   //   "com.pubg.imobile"
    };
    const char *process = env_->GetStringUTFChars(args->nice_name, nullptr);
    for (const auto *package: packages) {
      is_game_ = (strcmp(process, package) == 0);
      if (is_game_) {
        break;
      }
    }
    env_->ReleaseStringUTFChars(args->nice_name, process);
  }

  void postAppSpecialize(const AppSpecializeArgs *args) override {
    if (is_game_) {
      std::thread{hack}.detach();
    }
  }

 private:
  Api *api_ = nullptr;
  JNIEnv *env_ = nullptr;
  bool is_game_ = false;
};



ImFont* flamee;

void DrawESP(ImDrawList *draw) {

    
    
std::string credit = OBFUSCATE("LV MOD");
auto textSize = ImGui::CalcTextSize(credit.c_str(), 0, ((float) density / 11.5f));
draw->AddText2(flamee, ((float) density / 11.5f), {((float) glWidth / 2) - (textSize.x / 2), 10}, IM_COL32(255, 0, 0, 255), credit.c_str());

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
struct MemoryStruct
{
	char *memory;
	size_t size;
};

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
	size_t realsize = size * nmemb;
	struct MemoryStruct *mem = (struct MemoryStruct *)userp;

	mem->memory = (char *)realloc(mem->memory, mem->size + realsize + 1);
	if (mem->memory == NULL)
	{
		return 0;
	}

	memcpy(&(mem->memory[mem->size]), contents, realsize);
	mem->size += realsize;
	mem->memory[mem->size] = 0;

	return realsize;
}



std::string Login(const char *user_key) {
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
        curl_easy_setopt(curl, CURLOPT_URL, _enc_("https://nrgvipmod.xyz/public/connect"));

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
                        auth += _enc_("TEAMNRGOFFICIAL");
                        std::string outputAuth = Tools::CalcMD5(auth);

                        g_Token = token;
                        g_Auth = outputAuth;
EXP = result ["data"]["EXP"];       
                        bValid = g_Token == g_Auth;

                    }
                } else {
                    errMsg = result[(_enc_("reason"))].get<std::string>();
                }
            } catch (json::exception &e) {
                errMsg = e.what();
            }
        } else {
            errMsg = curl_easy_strerror(res);
        }
    }
    curl_easy_cleanup(curl);
    return bValid ? "OK" : errMsg;
}









// ======================================================================== //

std::string GetPackageName() {
    FILE *f = fopen("/proc/self/cmdline", "rb");
    if (f) {
        char *buf = new char[64];
        fread(buf, sizeof(char), 64, f);
        fclose(f);
        return buf;
    }
    return 0;
}

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


#include "timer.h"
timer RenderingFPS;


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
bool ModeSelector(const char *label, int *currentMode, const std::vector < std::string > &modes, bool horizontal = false);
bool ModeSelector(const char*label, int *currentMode, const std::vector<std::string> &modes, bool horizontal) {
    bool changed = false;
  //  TextSeparator(label);
    ImGui::Text(label);
    
    for (std::size_t i = 0; i < modes.size(); ++i) {
        if (ImGui::RadioButton(modes[i].c_str(), (std::size_t)*currentMode == i)) {
            *currentMode = i;
            changed      = true;
          //  ImGui::SameLine();
        }
        
   //     ImGui::SameLine();
        if (horizontal && i + 1 != modes.size())
            ImGui::SameLine();
    }
    return changed;
}

template<typename T> static inline T ImLerp(T a, T b, float t)                  { return (T)(a + (b - a) * t); }
static inline ImVec2 ImLerp(const ImVec2& a, const ImVec2& b, float t)          { return ImVec2(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t); }
static inline ImVec2 ImLerp(const ImVec2& a, const ImVec2& b, const ImVec2& t)  { return ImVec2(a.x + (b.x - a.x) * t.x, a.y + (b.y - a.y) * t.y); }
static inline ImVec4 ImLerp(const ImVec4& a, const ImVec4& b, float t)          { return ImVec4(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t, a.z + (b.z - a.z) * t, a.w + (b.w - a.w) * t); }











EGLBoolean (*orig_eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface);

EGLBoolean _eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
    eglQuerySurface(dpy, surface, EGL_WIDTH, &glWidth);
    eglQuerySurface(dpy, surface, EGL_HEIGHT, &glHeight);
    if (glWidth <= 0 || glHeight <= 0)
        return orig_eglSwapBuffers(dpy, surface);

    if (!g_App)
        return orig_eglSwapBuffers(dpy, surface);

    screenWidth = ANativeWindow_getWidth(g_App->window);
    screenHeight = ANativeWindow_getHeight(g_App->window);
    density = AConfiguration_getDensity(g_App->config);
/*
// ======================================================================== //
    EGLBoolean (*old_eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface);
EGLBoolean hook_eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
    
    */
        if (!initImGui) {
            

            IMGUI_CHECKVERSION();
     ImGui::CreateContext();
     
     ImGuiStyle* style = &ImGui::GetStyle();
       auto Color = style->Colors;
       
            style->WindowPadding = ImVec2(4, 3);
            style->WindowRounding = 0.0f;
            style->FramePadding = ImVec2(5, 5);
            style->FrameRounding = 4.0f;
            style->FrameBorderSize = 0.0f;
            style->WindowBorderSize = 0.0f;
            style->TabRounding = 2.0f;
            style->WindowTitleAlign = ImVec2(0.5, 0.5);
        
            style->Colors[ImGuiCol_WindowBg] = ImColor(0, 0, 0, 170);
    style->Colors[ImGuiCol_Border] = ImColor(50, 50, 50, 255);
    style->Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 1.0f);
    style->Colors[ImGuiCol_FrameBg] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_FrameBgHovered] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_FrameBgActive] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_TitleBg] = ImColor(66, 66, 66, 255);
    style->Colors[ImGuiCol_TitleBgCollapsed] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_TitleBgActive] = ImColor(66, 66, 66, 255);
    style->Colors[ImGuiCol_CheckMark] = ImColor(255, 255, 255, 255);
    style->Colors[ImGuiCol_MenuBarBg] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_SliderGrab] = ImColor(61, 133, 224, 250);
    style->Colors[ImGuiCol_SliderGrabActive] = ImColor(61, 133, 224, 250);
    style->Colors[ImGuiCol_Text] = ImVec4(0.98f, 0.97f, 0.93f, 1.00f);
    style->Colors[ImGuiCol_Header] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_HeaderHovered] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_HeaderActive] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_TabHovered] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_SliderGrabActive] = ImColor(61, 133, 224, 250);
    style->Colors[ImGuiCol_Button] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_ButtonHovered] = ImColor(158, 158, 158, 250);
    style->Colors[ImGuiCol_ButtonActive] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_Header] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_HeaderHovered] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_HeaderActive] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_SeparatorHovered] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_SeparatorActive] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_ResizeGrip] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_ResizeGripHovered] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_ResizeGripActive] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_PlotHistogram] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_PlotHistogramHovered] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_PlotLinesHovered] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_PlotLines] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_PlotHistogram] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_PlotHistogramHovered] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_PlotLinesHovered] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_PlotLines] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_Tab] = ImColor(33, 33, 33, 255);
    style->Colors[ImGuiCol_TabHovered] = ImColor(66, 66, 66, 255);
    style->Colors[ImGuiCol_TabActive] = ImColor(66, 66, 66, 255);
    style->Colors[ImGuiCol_TabUnfocusedActive] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.98f, 0.26f, 0.26f, 0.35f);
	style->Colors[ImGuiCol_NavHighlight] = ImColor(66, 66, 66, 250);
            /*
        style->Colors[ImGuiCol_WindowBg]              = ImColor(0, 0, 0, 190);
        
        style->Colors[ImGuiCol_FrameBg]               = ImColor(0, 0, 0, 255);
        style->Colors[ImGuiCol_FrameBgActive]               = ImColor(0, 0, 0, 255);
        style->Colors[ImGuiCol_FrameBgHovered]               = ImColor(0, 0, 0, 255);
        
        style->Colors[ImGuiCol_PopupBg]               = ImColor(0, 0, 0, 255);
        
        style->Colors[ImGuiCol_Button]                   = ImColor(148, 3, 5, 255);
        style->Colors[ImGuiCol_ButtonActive]             = ImColor(59, 59, 59, 255);
        style->Colors[ImGuiCol_ButtonHovered]            = ImColor(148, 3, 5, 255);
        
        style->Colors[ImGuiCol_TitleBg]               = ImColor(123, 42, 41, 255);
        style->Colors[ImGuiCol_TitleBgActive]         = ImColor(123, 42, 41, 255);
        style->Colors[ImGuiCol_TitleBgCollapsed]      = ImColor(123, 42, 41, 255);
        
        style->Colors[ImGuiCol_CheckMark]             = ImColor(18, 255, 22, 255);
    
   
            style->Colors[ImGuiCol_SliderGrab]             = ImColor(120, 40, 43, 255);
    style->Colors[ImGuiCol_SliderGrabActive]       = ImColor(200, 41, 1, 255);
     
    */
    //ImGui_ImplAndroid_Init(native_window);
    ImGui_ImplAndroid_Init();
ImGui_ImplOpenGL3_Init("#version 300 es");
   RenderingFPS.SetFps(Config.FPSControlSize);
    RenderingFPS.AotuFPS_init();
    RenderingFPS.setAffinity();
	
           ImGuiIO &io = ImGui::GetIO();
           
           
           struct timespec current_timespec;
    static double g_Time = 0.0;
    clock_gettime(CLOCK_MONOTONIC, &current_timespec);
    double current_time = (double)(current_timespec.tv_sec) + (current_timespec.tv_nsec / 1000000000.0);
    ImGui::GetIO().DeltaTime = g_Time > 0.0 ? (float)(current_time - g_Time) : (float)(1.0f / Config.FPSControlSize);
    g_Time = current_time;
    
           
        io.ConfigWindowsMoveFromTitleBarOnly = true;
            io.IniFilename = nullptr;
      //  io.IniFilename = NULL;
     // io.DeltaTime = 20 / 120;/*float(preferredFramesPerSecond ?: 65)*/
    
        static const ImWchar icons_ranges[] = {
            0xf000, 0xf3ff, 
            0x0020, 0x00FF, 
       0x0100, 0x017F,
       0xe000, 0xf538, 
       0xf7f9, 0xf8ff,
            0};
ImFontConfig icons_config;

ImFontConfig CustomFont;
CustomFont.FontDataOwnedByAtlas = true;

icons_config.MergeMode = true;
icons_config.PixelSnapH = true;
icons_config.OversampleH = 2.5;
icons_config.OversampleV = 2.5;




io.Fonts->AddFontFromMemoryTTF((void *)NIKE_data, NIKE_size, 25.0f, NULL, io.Fonts->GetGlyphRangesChineseFull());
 //flamee = io.Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(Custom), sizeof(Custom), 25.f, &CustomFont);

io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 25.0f, &icons_config, icons_ranges);

        flamee = io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 25.0f, &icons_config, icons_ranges);


        ImFontConfig cfg;
    //    cfg.SizePixels = ((float) density / 60.0f);
        cfg.SizePixels = ((float) density / 40.0f);
        io.Fonts->AddFontDefault(&cfg);
        memset(&Config, 0, sizeof(sConfig));
        
// ==========================ESPCOLOR ================================== //
        Config.AimEnable = 0;
        Config.NRGtrigger = 0;
        Config.EnemieCount = 0;
        Config.AimSizeMm = 0;
            Config.FPSControl = 2;
            Config.EspLinetow = 1;
            
           
                      Config.FPSControlSize = 120;
                      
        Config.AimBot.Cross = 80;
        Config.AimBot.Meter = 100;
        Config.AimBot.Recc = 1;
        Config.AimBot.Position = 10;
        Config.AimBot.CrossAimLock = 190;
        Config.XXY = 4.0f;
        //Config.No_move = true;
        Config.NrgAutoBypass = true;
        //Config.GameInfo= true;
Config.MemoryWideViewSize = 80;
Config.AimBot.AimBotSpeed = 5;
//Config.MemoryWideViewSize = 360;
                preferredFramesPerSecond = 60;
             //  getEspFramerate = 60;
        initImGui = true;
        Config.Logo = true;
      //  Config.Fps90 = true;
      
      Config.RadarXx = 10;
      Config.RadarYy = 5;
      Config.RadarSize = 200;
      Config.AimDistance = 150;
    }
    
    ImGuiIO &io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls

  
   static bool WantTextInputLast = false;
   if (io.WantTextInput && !WantTextInputLast){
        DisplayKeyboard(true);
    }
    WantTextInputLast = io.WantTextInput;
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame(glWidth, glHeight);
    ImGui::NewFrame();
    
    io.KeysDown[io.KeyMap[ImGuiKey_UpArrow]] = false;
    io.KeysDown[io.KeyMap[ImGuiKey_DownArrow]] = false;
    io.KeysDown[io.KeyMap[ImGuiKey_LeftArrow]] = false;
    io.KeysDown[io.KeyMap[ImGuiKey_RightArrow]] = false;
    io.KeysDown[io.KeyMap[ImGuiKey_Tab]] = false;
    io.KeysDown[io.KeyMap[ImGuiKey_Enter]] = false;
    io.KeysDown[io.KeyMap[ImGuiKey_Backspace]] = false;
    io.KeysDown[io.KeyMap[ImGuiKey_PageUp]] = false;
    io.KeysDown[io.KeyMap[ImGuiKey_PageDown]] = false;
    io.KeysDown[io.KeyMap[ImGuiKey_Escape]] = false;
    io.KeysDown[io.KeyMap[ImGuiKey_Delete]] = false;
    io.KeysDown[io.KeyMap[ImGuiKey_Home]] = false;
    io.KeysDown[io.KeyMap[ImGuiKey_End]] = false;
    io.KeysDown[io.KeyMap[ImGuiKey_Insert]] = false;
    
    DrawESP(ImGui::GetForegroundDrawList());
    
    m_fps.Update();
        std::string sggFPS = OBFUSCATE("Mod FPS: ");
    sggFPS += std::to_string(m_fps.get());

    
        static bool p_off = false;
        static bool p_open = true;

              if (!g_Token.empty() && !g_Auth.empty() && g_Token == g_Auth) {
            //  if (isLogin) {
        for (int i = 0; i < IM_ARRAYSIZE(io.KeysDown); i++) 
           if (ImGui::IsKeyDown(i)) { //IsKeyPressed //IsKeyDown
                p_open = true;
                }
                }
                    
                
                    if (!p_off) {
                loadCFG();
               // removeCFG();
             //   Antiban();
                }
                    if (p_open) {
                      ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    
                      ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
 
                if (!p_off) {
        ImGui::Begin(OBFUSCATE("NRG MOD Login Page"), 0, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoSavedSettings);
                }
     std::string PackName2m;
PackName2m += "/data/data/";
PackName2m += GetPackageName().c_str();
PackName2m += "/files/Nrg2.ini";
          
const char* filePath = PackName2m.c_str();  // Replace with actual file path




   std::ifstream inputFile(filePath);
    
      
                 //   static bool isLogin= false;
                    static std::string err;
                       if (!isLogin) {
                
                ImGui::Text(SelectLanguage(OBFUSCATE("请登录! (将密钥复制到剪贴板)"), OBFUSCATE("Please Login! (Copy Key to Clipboard)")));

                //
   ImGui::PushItemWidth(-1);
           ImGui::InputTextWithHint("##key", user_keys, user_keys, IM_ARRAYSIZE(user_keys));
        
            ImGui::PopItemWidth();
    std::string fileContent((std::istreambuf_iterator<char>(inputFile)),
                                (std::istreambuf_iterator<char>()));
                                inputFile.close();
                                auto key = fileContent;
            if (ImGui::Button(SelectLanguage(OBFUSCATE("粘贴键"),OBFUSCATE("Paste Key")), ImVec2(ImGui::GetContentRegionAvailWidth(), 0))) {
                auto key = getClipboardText();
                strncpy(user_keys, key.c_str(), sizeof user_keys);
            }

            static std::string err;
            if (ImGui::Button(SelectLanguage(OBFUSCATE("登录"), OBFUSCATE("Login")), ImVec2(ImGui::GetContentRegionAvailWidth(), 0))) {
              err = Login(user_keys);
               if (err == "OK") {
                  isLogin = bValid && g_Auth == g_Token;
                      //  if (strcmp(user_keys, _enc_("Nrg-Module-Telegram@TeamNRG_MOD")) == 0) {
     //  isLogin = true;
                }
            }
            
                    
            
            
              if (ImGui::Button(OBFUSCATE("Join Telegram Channel"), ImVec2(ImGui::GetContentRegionAvailWidth(), 0))) {

                           const char* url = OBFUSCATE("https://t.me/TeamNRG_MOD");
                        // const char* url = OBFUSCATE("https://t.me/TeamVip56");
                            int result = OpenURL(url);
                        }
                                  if (ImGui::Button(OBFUSCATE("Feedback"), ImVec2(ImGui::GetContentRegionAvailWidth(), 0))) {
                           const char* url = OBFUSCATE("https://t.me/TMNrgOwnerBot");
                        
                    //    const char* url = OBFUSCATE("https://t.me/TITAN_FEEDBACK_bot");
                            int result = OpenURL(url);
                        }
                                
                        
                    //    ImGui::Checkbox(SelectLanguage(OBFUSCATE("闪回修复"), OBFUSCATE("Crash Fix")), &Config.CrashFix);

                    /*
                                    
            if(ImGui::Button(OBFUSCATE("Logs Data Delete"),{250,50}))
                       {
                           Antiban();
                           }
    
              */
                        ImGui::RadioButton(OBFUSCATE("English"), &currentLang, 0);
              ImGui::SameLine();
              ImGui::RadioButton(OBFUSCATE("中国"), &currentLang, 1); 
          //    ImGui::SameLine();
              
              
                            
              
              /*
              static const char* engch[]{"English", "中国"};
                            ImGui::Combo("##engch", (int*)&currentLang, engch, IM_ARRAYSIZE(engch), 5);
                            
                        */
            if (!err.empty() && err != "OK") {
               
                if(ImGui::Button(OBFUSCATE("JOIN / 加入"),{150,50}))
                       {
                         const char* url = OBFUSCATE("https://t.me/TeamNRG_MOD");
                    //      const char* url = OBFUSCATE("https://t.me/TeamVip56");
                            int result = OpenURL(url);
                            
                           }
                           
                        
                ImGui::Text("%s", err.c_str());
            }
            
            } else{
                        
                
                /*
        // Color buttons, demonstrate using PushID() to add unique identifier in the ID stack, and changing style.
        for (int i = 0; i < 7; i++)
        {
            if (i > 0)
                
            ImGui::PushID(i);
            ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(i / 7.0f, 0.6f, 0.6f));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(i / 7.0f, 0.7f, 0.7f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(i / 7.0f, 0.8f, 0.8f));
            ImGui::Button("Click");
            ImGui::PopStyleColor(3);
            ImGui::PopID();
        }
                */
                
                 if (!g_Token.empty() && !g_Auth.empty() && g_Token == g_Auth) {
                               //if (isLogin) {
                      
                      static float LogoSize = 100;

        //    ImGui::Image(imageButton.textureId, ImVec2{LogoSize, LogoSize}, ImVec2{0, 0}, ImVec2{1, 1});

     p_off = true;              
     //ImGui::SetNextWindowSize(ImVec2((float) glWidth * 0.67f, (float) glHeight * 0.84f), ImGuiCond_Once);//0.81f
  // ImGui::SetNextWindowSize(ImVec2((float) glWidth * 0.54f, (float) glHeight * 0.75f), ImGuiCond_Once);//0.81f
ImGui::SetNextWindowSize({757, 510}, ImGuiCond_FirstUseEver);
   // ImGui::SetNextWindowPos({1, 1}, ImGuiCond_FirstUseEver); //NRG Android (PUBGM 64bit)
     
        //  std::string modnameu = OBFUSCATE("NRG TEST Version | 64bit");
                ImGui::Begin(OBFUSCATE("LV MOD TEST Version | 64bit"), &p_open, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
           //     ImGui::Begin(modnameu.c_str(), &p_open, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
                       ImGui::Separator();
                       
                       
  
                       
/*
                ImGui::Separator();
                
                ImGui::Spacing();
                */
                
                
              ImGui::Columns(2);
            ImGui::SetColumnOffset(1, 160);
                    
                    {
                    /*
                                           // Color buttons, demonstrate using PushID() to add unique identifier in the ID stack, and changing style.
        for (int i = 0; i < 1; i++)
        {
            if (i > 0)
                
            ImGui::PushID(i);
            ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor(120, 40, 43, 255));
           // ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(i / 7.0f, 0.6f, 0.6f));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor(151, 43, 77, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor(151, 43, 77, 255));
            */
            
            
    if(ImGui::Button(ICON_FA_HOME"Mainpage", ImVec2(150, 40)))
                {
                    Settings::Tab = 1;
                     
                }
            //    ImGui::SameLine();
                if(ImGui::Button(ICON_FA_EYE"ESP", ImVec2(150, 40)))
                {
                    
                    
                    Settings::Tab = 2;
                    
                
                }
            //    ImGui::SameLine();
                if(ImGui::Button(ICON_FA_EDIT"Items", ImVec2(150, 40)))
                {
                    
                    
                    Settings::Tab = 3;
                    
                    
                }
                
            //    ImGui::SameLine();
                if(ImGui::Button(ICON_FA_CROSSHAIRS"AimBot", ImVec2(150, 40)))
                {
                    Settings::Tab = 4;
                
                }
//ImGui::SameLine();
                if(ImGui::Button(ICON_FA_COG"Settings", ImVec2(150, 40)))
                {
                    Settings::Tab = 5;
                
                }
/*
            
            ImGui::PopStyleColor(3);
            ImGui::PopID();
        }*/
                        }
                        
                        
                        ImGui::NextColumn();
                        
							
                

                if (Settings::Tab == 1)
                {
                    
                    ImGui::BulletColorText(ImColor(97, 167, 217, 255).Value, OBFUSCATE("Main Menu"));
    
                    ImGui::Separator();
                       ImGui::BulletColorText(ImColor(97, 167, 217, 255).Value, OBFUSCATE("FPSControl"));
    
                    
               
               ImGui::RadioButton(OBFUSCATE("60FPS"), &Config.FPSControl, 0);
               ImGui::SameLine();
              ImGui::RadioButton(OBFUSCATE("90FPS"), &Config.FPSControl, 1);
              ImGui::SameLine();
              ImGui::RadioButton(OBFUSCATE("120FPS"), &Config.FPSControl, 2);

              
                  if (Config.FPSControl == 0) {
                      Config.FPSControlSize = 60;
                      
                      }
                      
                  if (Config.FPSControl == 1) {
                      Config.FPSControlSize = 90;
                      }
                      
                  if (Config.FPSControl == 2) {
                      Config.FPSControlSize = 120;
                      }
                      
                 
                              /*
                    ImGui::BulletColorText(ImColor(97, 167, 217, 255).Value, OBFUSCATE("EnableCheats"));
    
              ImGui::Checkbox(OBFUSCATE("Player ESP"), &Config.ESPEnable);
ImGui::SameLine();
      ImGui::Checkbox(OBFUSCATE("Items ESP"), &Config.PlayerESP.EspInfo);
ImGui::SameLine();
    //  ImGui::Checkbox(OBFUSCATE("Aimbot"), &Config.PlayerESP.EspInfo);
      
ImGui::SameLine();
      ImGui::Checkbox(OBFUSCATE("DeadBox"), &Config.PlayerESP.EspInfo);
ImGui::Checkbox(OBFUSCATE("Handcam Mode"), &Config.PlayerESP.EspInfo);
*/
ImGui::BulletColorText(ImColor(97, 167, 217, 255).Value, OBFUSCATE("AntiBan"));
   // ImGui::Text(OBFUSCATE("Island Bypass Report Block (please don't stop )"));
             
ImGui::Checkbox(OBFUSCATE("Auto Island (Game Lobby: You (internet/Wifi) Off/On)"), &ConfigNrg.Bypassisland);

//ImGui::Checkbox(OBFUSCATE("Don't Use Auto Island (Stop)"), &ConfigNrg.DontUseIsland);
/*
ImGui::Text(SelectLanguage(OBFUSCATE("该模块不包含反禁止。"),  OBFUSCATE("The module is not include antiban.")));
               ImGui::Text(SelectLanguage(OBFUSCATE("考虑使用您自己的反禁令。"),  OBFUSCATE("Consider using your own antiban.")));
               */
              ImGui::BulletColorText(ImColor(97, 167, 217, 255).Value, OBFUSCATE("You Pubg Package Name"));
    ImGui::Text(GetPackageName().c_str());
    
    ImGui::BulletColorText(ImColor(97, 167, 217, 255).Value, OBFUSCATE("Reset Data"));
    
    
    /*
      for (int i = 0; i < 1; i++)
        {
            if (i > 0)
                
            ImGui::PushID(i);
            ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor(120, 40, 43, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor(200, 41, 1, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor(200, 41, 1, 255));
            */
            
     if (ImGui::Button("Reset(1)",ImVec2(120, 32))) {
                        
                            
std::string DeleData;
DeleData += "rm -rf /storage/emulated/0/Android/data/";
DeleData += GetPackageName().c_str();
DeleData += "/cache";
system(DeleData.c_str());
                  }
    ImGui::SameLine();
                      if (ImGui::Button("Reset(2)",ImVec2(120, 32))) {
                        std::string DeleData;
DeleData += "rm -rf /storage/emulated/0/Android/data/";
DeleData += GetPackageName().c_str();
DeleData += "/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs";
system(DeleData.c_str());
std::string DeleData2;
DeleData2 += "rm -rf /storage/emulated/0/Android/data/";
DeleData2 += GetPackageName().c_str();
DeleData2 += "/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/LightData";
system(DeleData2.c_str());
                    }
                    
                   /*
    ImGui::SameLine();
        if (ImGui::Button("Reset Device",ImVec2(155, 32))) {
    
                    }
                    
                    */
                    


                    
                    /*
            ImGui::PopStyleColor(3);
            ImGui::PopID();
        }
                       
    */
    ImGui::BulletColorText(ImColor(97, 167, 217, 255).Value, OBFUSCATE("ExportDate"));
 
                    
                    ImGui::Text(EXP.c_str());
    
                    
                    
                 }
                 
                 
                    if (Settings::Tab == 2)
                {
                 
                 
                 ImGui::BulletColorText(ImColor(97, 167, 217, 255).Value, OBFUSCATE("PlayerESP"));
 
                 
ImGui::Separator();
ImGui::Checkbox( OBFUSCATE("Info"), &Config.PlayerESP.EspInfo);
ImGui::SameLine();
ImGui::Checkbox(OBFUSCATE("Line"), &Config.PlayerESP.Line);
//ImGui::SameLine();
ImGui::TableNextColumn();   

ImGui::Checkbox(OBFUSCATE("Bone"), &Config.PlayerESP.Skeleton);
ImGui::SameLine();
//ImGui::TableNextColumn();   
ImGui::Checkbox(OBFUSCATE("Weapon"), &Config.Weapon);
//ImGui::SameLine();
ImGui::TableNextColumn();   

ImGui::Checkbox(OBFUSCATE("360° Alert"), &Config.PlayerESP.Alert);
ImGui::SameLine();
ImGui::Checkbox(OBFUSCATE("Grenade"), &Config.PlayerESP.Grenade);
//ImGui::SameLine();
ImGui::TableNextColumn();  

ImGui::Checkbox(OBFUSCATE("Show Game Info"), &Config.GameInfo);
//ImGui::SameLine();
ImGui::SameLine();
ImGui::Checkbox(OBFUSCATE("Ignore Bot(Esp+Aim)"), &Config.Hidebot);

                 ImGui::BulletColorText(ImColor(97, 167, 217, 255).Value, OBFUSCATE("Memory"));
 
                 ImGui::Checkbox(OBFUSCATE("Small Crosshair"), &Config.SmallCrosshair);
               ImGui::SameLine();
               ImGui::Checkbox(OBFUSCATE("X Hit Effect"), &Config.XHitEffect);
               ImGui::SameLine();
               ImGui::Checkbox(OBFUSCATE("View"), &Config.MemoryWideView);
               
                   if (Config.MemoryWideView) {
                       
               ImGui::Text( OBFUSCATE("View Size:"));
               ImGui::SameLine();
               ImGui::SliderFloat(OBFUSCATE("##ViewSize"),&Config.MemoryWideViewSize, 80.0f, 150.0f);
               }
                 }
                 
                 
                 
                     if (Settings::Tab == 3)
                {
                 ImGui::BulletColorText(ImColor(97, 167, 217, 255).Value, OBFUSCATE("ItemsESP"));
                 ImGui::Separator();
 ImGui::Checkbox(OBFUSCATE("Car"), &Config.PlayerESP.Vehicle);
ImGui::SameLine();
ImGui::Checkbox( OBFUSCATE("DeadBox"), &Config.PlayerESP.LootBox);



                 }
                 
             if (Settings::Tab == 4)
                {
                    
                    ImGui::BulletColorText(ImColor(97, 167, 217, 255).Value, OBFUSCATE("AimBot"));
                    ImGui::Separator();
                    
                    
                    
                    /*
                    
                    
                        if (ConfigAim.AimBot.Enable) {
                               for (int i = 0; i < 1; i++)
        {
            if (i > 0)
                
            ImGui::PushID(i);
                          ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor(18, 255, 22, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor(18, 255, 22, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor(200, 41, 1, 255));
            
                         if (ImGui::Button("AimBot",ImVec2(120, 40))) {
                  ConfigAim.AimBot.Enable = false;
                   }
                   
            ImGui::PopStyleColor(3);
            ImGui::PopID();
                   }
                   }
                    
                    if (!ConfigAim.AimBot.Enable) {
                           for (int i = 0; i < 1; i++)
        {
            if (i > 0)
                
            ImGui::PushID(i);
                        ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor(200, 41, 1, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor(200, 41, 1, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor(18, 255, 22, 255));
            
                         if (ImGui::Button("AimBot",ImVec2(120, 40))) {
                  ConfigAim.AimBot.Enable = true;
                   }
                   
            ImGui::PopStyleColor(3);
            ImGui::PopID();
                   }
                   }
                   
                   
                   ImGui::SameLine();
                  
                        if (Config.AimTargetLine) {
                               for (int i = 0; i < 1; i++)
        {
            if (i > 0)
                
            ImGui::PushID(i);
                          ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor(18, 255, 22, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor(18, 255, 22, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor(200, 41, 1, 255));
            
                         if (ImGui::Button("AimLine",ImVec2(120, 40))) {
                  Config.AimTargetLine = false;
                   }
                   
            ImGui::PopStyleColor(3);
            ImGui::PopID();
                   }
                   }
                    
                    if (!Config.AimTargetLine) {
                           for (int i = 0; i < 1; i++)
        {
            if (i > 0)
                
            ImGui::PushID(i);
                        ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor(200, 41, 1, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor(200, 41, 1, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor(18, 255, 22, 255));
            
                         if (ImGui::Button("AimLine",ImVec2(120, 40))) {
                  Config.AimTargetLine = true;
                   }
                   
            ImGui::PopStyleColor(3);
            ImGui::PopID();
                   }
                   }
                           ImGui::SameLine();
                  
                        if (Config.AimBot.Lessmmm) {
                               for (int i = 0; i < 1; i++)
        {
            if (i > 0)
                
            ImGui::PushID(i);
                          ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor(18, 255, 22, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor(18, 255, 22, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor(200, 41, 1, 255));
            
                         if (ImGui::Button("AimBot Control Recoil",ImVec2(260, 40))) {
                  Config.AimBot.Lessmmm = false;
                   }
                   
            ImGui::PopStyleColor(3);
            ImGui::PopID();
                   }
                   }
                    
                    if (!Config.AimBot.Lessmmm) {
                           for (int i = 0; i < 1; i++)
        {
            if (i > 0)
                
            ImGui::PushID(i);
                        ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor(200, 41, 1, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor(200, 41, 1, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor(18, 255, 22, 255));
            
                         if (ImGui::Button("AimBot Control Recoil",ImVec2(260, 40))) {
                  Config.AimBot.Lessmmm = true;
                   }
                   
            ImGui::PopStyleColor(3);
            ImGui::PopID();
                   }
                   }
                   
                          if (Config.AimBot.IgnoreKnocked) {
                               for (int i = 0; i < 1; i++)
        {
            if (i > 0)
                
            ImGui::PushID(i);
                          ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor(18, 255, 22, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor(18, 255, 22, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor(200, 41, 1, 255));
            
                         if (ImGui::Button("Ignore Knocked",ImVec2(210, 40))) {
                  Config.AimBot.IgnoreKnocked = false;
                   }
                   
            ImGui::PopStyleColor(3);
            ImGui::PopID();
                   }
                   }
                    
                    if (!Config.AimBot.IgnoreKnocked) {
                           for (int i = 0; i < 1; i++)
        {
            if (i > 0)
                
            ImGui::PushID(i);
                        ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor(200, 41, 1, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor(200, 41, 1, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor(18, 255, 22, 255));
            
                         if (ImGui::Button("Ignore Knocked",ImVec2(210, 40))) {
                  Config.AimBot.IgnoreKnocked = true;
                   }
                   
            ImGui::PopStyleColor(3);
            ImGui::PopID();
                   }
                   }
                   
                   
                   
                   
                   ImGui::SameLine();
                   
                   ////
                          if (Config.AimBot.VisCheck) {
                               for (int i = 0; i < 1; i++)
        {
            if (i > 0)
                
            ImGui::PushID(i);
                          ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor(18, 255, 22, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor(18, 255, 22, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor(200, 41, 1, 255));
            
                         if (ImGui::Button("Vis Check",ImVec2(180, 40))) {
                  Config.AimBot.VisCheck = false;
                   }
                   
            ImGui::PopStyleColor(3);
            ImGui::PopID();
                   }
                   }
                    
                    if (!Config.AimBot.VisCheck) {
                           for (int i = 0; i < 1; i++)
        {
            if (i > 0)
                
            ImGui::PushID(i);
                        ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor(200, 41, 1, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor(200, 41, 1, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor(18, 255, 22, 255));
            
                         if (ImGui::Button("Vis Check",ImVec2(180, 40))) {
                  Config.AimBot.VisCheck = true;
                   }
                   
            ImGui::PopStyleColor(3);
            ImGui::PopID();
                   }
                   }
                   
                   
                   */
               
                   
                   
                  
                    ImGui::Checkbox( OBFUSCATE("AimBot"), &ConfigAim.AimBot.Enable);
   
                    
                    
                    
                    
        
        
    
                    
               ImGui::Checkbox( OBFUSCATE("Hide Fov"), &Config.HideFov);
               ImGui::SameLine();

   
  
               ImGui::Checkbox(OBFUSCATE("Aim Line"), &Config.AimTargetLine);
         
                                ImGui::SameLine();
   ImGui::Checkbox(OBFUSCATE("AimBot Control Recoil"), &Config.AimBot.Lessmmm);

   
     ImGui::BulletColorText(ImColor(97, 167, 217, 255).Value, OBFUSCATE("AimBot Control Recoil Size"));
      
             ImGui::SliderFloat(OBFUSCATE("##AimBotControl"),&Config.AimBot.Recc, 0.3f, 2.0f, "%.1f");
  

           
              ImGui::BulletColorText(ImColor(97, 167, 217, 255).Value, OBFUSCATE("Aim Fov"));
      
                ImGui::SliderFloat(OBFUSCATE("##FOV"),&Config.AimBot.Cross, 0, 300, "%.0f");

        ImGui::BulletColorText(ImColor(97, 167, 217, 255).Value, OBFUSCATE("Distance"));
      
        ImGui::SliderFloat(OBFUSCATE("##AimDistance"),&Config.AimDistance, 10, 500, "%.0fM");
  
              ImGui::BulletColorText(ImColor(97, 167, 217, 255).Value, OBFUSCATE("Trigger"));
      
              ImGui::RadioButton( OBFUSCATE("Fire"), &Config.NRGtrigger, 0);
              ImGui::SameLine();
              ImGui::RadioButton( OBFUSCATE("Scope"), &Config.NRGtrigger, 1);             
              ImGui::SameLine();
              ImGui::RadioButton( OBFUSCATE("Fire / Scope"), &Config.NRGtrigger, 2);

              ImGui::Checkbox( OBFUSCATE("Ignore Knocked"), &Config.AimBot.IgnoreKnocked);
              ImGui::SameLine();
              ImGui::Checkbox( OBFUSCATE("Vis Check"), &Config.AimBot.VisCheck);
                  
                 }
                 
                 
                      if (Settings::Tab == 5)
                {
                    
                    
                    
                    
                    ImGui::BulletColorText(ImColor(97, 167, 217, 255).Value, OBFUSCATE("Settings"));
                    
                   ImGui::Separator();
                 ImGui::BulletColorText(ImColor(97, 167, 217, 255).Value, OBFUSCATE("Esp Line 360° & 180°:"));
      
              ImGui::RadioButton(OBFUSCATE("360° Line"), &Config.EspLinetow, 0);
              ImGui::SameLine();
              ImGui::RadioButton(OBFUSCATE("180° Line"), &Config.EspLinetow, 1);   
              
              
                 ImGui::BulletColorText(ImColor(97, 167, 217, 255).Value, OBFUSCATE("Enemie Count:"));
      
              ImGui::RadioButton(OBFUSCATE("[ALERT] 1 Enemies in Area"), &Config.EnemieCount, 0);
              ImGui::SameLine();
              ImGui::RadioButton(OBFUSCATE("P:1  B:1"), &Config.EnemieCount, 1);   
              
              ImGui::RadioButton(OBFUSCATE("1"), &Config.EnemieCount, 2);   
              ImGui::SameLine();
              ImGui::RadioButton(OBFUSCATE("EnemieCount Hide"), &Config.EnemieCount, 3);   
        
              ImGui::BulletColorText(ImColor(97, 167, 217, 255).Value, OBFUSCATE("Sytem FPS:"));
                 ImGui::BulletColorText(ImColor(1, 243, 255, 255), OBFUSCATE("Ms/Framerate: %.1f"), 1000 / ImGui::GetIO().Framerate);
             
              ImGui::BulletColorText(ImColor(255, 246, 2, 255), OBFUSCATE("You Device Hz: %.2f"), ImGui::GetIO().Framerate);
              ImGui::BulletColorText(ImColor(255, 225, 6, 255), sggFPS.c_str());
    
              
                          if(ImGui::Button(SelectLanguage(OBFUSCATE("节省"), OBFUSCATE("Save")),{150,50}))
                       {
                           saveCFG();
                           }
                          ImGui::SameLine();
                          ImGui::Text("  ");
                            ImGui::SameLine();
               if(ImGui::Button(SelectLanguage(OBFUSCATE("删除"), OBFUSCATE("Delete")),{150,50})){removeCFG();}
                
                   if (ImGui::Button(OBFUSCATE(" Join Telegram Channel ")))
                        {
                      const char* url = OBFUSCATE("https://t.me/TeamNRG_MOD");
                         //  const char* url = OBFUSCATE("https://t.me/TeamVip56");
                            int result = OpenURL(url);
                        }
                        ImGui::SameLine();
                        ImGui::Text(" ");
ImGui::SameLine();
                  if (ImGui::Button(OBFUSCATE(" Feedback ")))
                        {
                          const char* url = OBFUSCATE("https://t.me/TMNrgOwnerBot");
                        //   const char* url = OBFUSCATE("https://t.me/TITAN_FEEDBACK_bot");
                            int result = OpenURL(url);
                        }
          
                 }
   
        }
        }
      }
        
        
      // ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 5.0f);          
         ImGui::End();
    
    ImGui::GetIO().DeltaTime = 1 / Config.FPSControlSize;
    ImGui::Render();
    
    
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
//return old_eglSwapBuffers(dpy, surface);
   return orig_eglSwapBuffers(dpy, surface);
          }


int32_t (*orig_onInputEvent)(struct android_app *app, AInputEvent *inputEvent);
int32_t onInputEvent(struct android_app *app, AInputEvent *inputEvent)
{
	if (initImGui)
	{
		ImGui_ImplAndroid_HandleInputEventNrg(inputEvent, {(float)screenWidth / (float)glWidth, (float)screenHeight / (float)glHeight});
	}
	return orig_onInputEvent(app, inputEvent);
}




void* (*o__memcpy_chk)(void* dest, const void* src, size_t count, size_t dest_size);
extern "C" void* h__memcpy_chk(void* dest, const void* src, size_t count, size_t dest_size) {
    if (count > dest_size) {
    uint8_t* dest_ptr = static_cast<uint8_t*>(dest);
        for (size_t i = 0; i < count; ++i) {
    dest_ptr[i] = (dest_ptr[i] == 0x00) ? 0x00 : 0x00;
        }
       } else if (count < dest_size) {
        uint8_t* dest_ptr = static_cast<uint8_t*>(dest);
        for (size_t i = 0; i < count; ++i) {
            dest_ptr[i] = (dest_ptr[i] == 0x00) ? 0x00 : 0x00;
        }
           } else {

        memset(dest, 0x00, count);
    }
    return dest;
}


int (*sub_8E5F6)(int a1, unsigned char* a2, size_t a3);
int __fastcall hsub_8E5F6(int a1, unsigned char* a2, size_t a3) {
    unsigned int v7; // r0
    while (true) {
        if (a2 && !((a3 - 1) >> 10)) {
            if ((unsigned int) ((*(unsigned int *) (a1 + 4) - *(unsigned int *) a1) >> 2) > 0x400)
                return 0;
            v7 = *a2;

            if (v7 >= 0x11) {
                LOGI("Case 35 0x11 Blocked");
                return 0;
            }
        }
    }
    return sub_8E5F6(a1, a2, a3);
}


#define _WORD  uint16_t
 _WORD *__fastcall (*osub_60AC8)(int a1, const void *a2, size_t a3);
_WORD *__fastcall sub_60AC8(int a1, const void *a2, size_t a3)
{
   if (a1 == 0x80){return (_WORD*)0;}
   if (a3 == 0x81){return (_WORD*)0;}
   return osub_60AC8(a1,a2,a3);
}
    
int (*osub_60A34)(const char *a1, unsigned int a2);
int hsub_60A34(const char *a1, unsigned int a2)
{
    while(true)
    {
        sleep(10000);
    }
    return osub_60A34(a1,a2);
}
    /*
void (*orig_nativeVirtualKeyboardChanged)(JNIEnv *env, jobject clazz, jstring str);
void nativeVirtualKeyboardChanged(JNIEnv *env, jobject clazz, jstring str) {
    auto s = env->GetStringUTFChars(str, 0);
    LOGI("s: %s", s);
    return orig_nativeVirtualKeyboardChanged(env, clazz, str);
}
*/


int (*osub_1B99A4)(const char *a1, unsigned int a2);
int hsub_1B99A4(const char *a1, unsigned int a2)
{
    while(true)
    {
        sleep(10000);
    }
    return osub_1B99A4(a1,a2);
}

        
        
int (*hook_sub_3BB160)(int *a1);
int __fastcall sub_3BB160(int *a1)
{
    return 1;
}
int (*hook_sub_3BC5C8)(int *a1);
int __fastcall sub_3BC5C8(int *a1)
{
    return 1;
}


int (*hook_sub_12724C)(int *a1);
int __fastcall sub_12724C(int *a1)
{
    return 1;
}
int (*hook_sub_133210)(int *a1);
int __fastcall sub_133210(int *a1)
{
    return 1;
}
/*
int__fastcall (*sub_3A6D00)(int a1, _int a2, _int *a3, _int *a4, _int *a5);
int__fastcall (*hooksub_3A6D00)(int a1, _int a2, _int *a3, _int *a4, _int *a5)
{
   while (true)
   {
     sleep(100000);
   }
  return sub_3A6D00(a1,a2,a3,a4,a5);
 }  
*/


[[noreturn]] void *maps_thread(void *){
while (true) {
    sleep(5);
    
    
    
    



}
}




//int glHeightNrg, glWidthNrg;
bool setup;
uintptr_t address;

#define HOOKAF(ret, func, ...) \
    ret (*orig##func)(__VA_ARGS__); \
    ret my##func(__VA_ARGS__)



void SetupImgui() {
    /*
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();

    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();

    
    // Setup Dear ImGui style
    // Setup Platform/Renderer backends
    ImGui_ImplOpenGL3_Init("#version 100");

    // We load the default font with increased size to improve readability on many devices with "high" DPI.
    ImFontConfig font_cfg;
    font_cfg.SizePixels = 22.0f;
    io.Fonts->AddFontDefault(&font_cfg);

    // Arbitrary scale-up
    ImGui::GetStyle().ScaleAllSizes(3.0f);
    
    */
 
            IMGUI_CHECKVERSION();
     ImGui::CreateContext();
     
     ImGuiStyle* style = &ImGui::GetStyle();
       auto Color = style->Colors;
       
            style->WindowPadding = ImVec2(4, 3);
            style->WindowRounding = 0.0f;
            style->FramePadding = ImVec2(5, 5);
            style->FrameRounding = 4.0f;
            style->FrameBorderSize = 0.0f;
            style->WindowBorderSize = 0.0f;
            style->TabRounding = 2.0f;
            style->WindowTitleAlign = ImVec2(0.5, 0.5);
        
            style->Colors[ImGuiCol_WindowBg] = ImColor(0, 0, 0, 170);
    style->Colors[ImGuiCol_Border] = ImColor(50, 50, 50, 255);
    style->Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 1.0f);
    style->Colors[ImGuiCol_FrameBg] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_FrameBgHovered] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_FrameBgActive] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_TitleBg] = ImColor(66, 66, 66, 255);
    style->Colors[ImGuiCol_TitleBgCollapsed] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_TitleBgActive] = ImColor(66, 66, 66, 255);
    style->Colors[ImGuiCol_CheckMark] = ImColor(255, 255, 255, 255);
    style->Colors[ImGuiCol_MenuBarBg] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_SliderGrab] = ImColor(61, 133, 224, 250);
    style->Colors[ImGuiCol_SliderGrabActive] = ImColor(61, 133, 224, 250);
    style->Colors[ImGuiCol_Text] = ImVec4(0.98f, 0.97f, 0.93f, 1.00f);
    style->Colors[ImGuiCol_Header] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_HeaderHovered] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_HeaderActive] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_TabHovered] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_SliderGrabActive] = ImColor(61, 133, 224, 250);
    style->Colors[ImGuiCol_Button] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_ButtonHovered] = ImColor(158, 158, 158, 250);
    style->Colors[ImGuiCol_ButtonActive] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_Header] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_HeaderHovered] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_HeaderActive] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_SeparatorHovered] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_SeparatorActive] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_ResizeGrip] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_ResizeGripHovered] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_ResizeGripActive] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_PlotHistogram] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_PlotHistogramHovered] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_PlotLinesHovered] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_PlotLines] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_PlotHistogram] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_PlotHistogramHovered] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_PlotLinesHovered] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_PlotLines] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_Tab] = ImColor(33, 33, 33, 255);
    style->Colors[ImGuiCol_TabHovered] = ImColor(66, 66, 66, 255);
    style->Colors[ImGuiCol_TabActive] = ImColor(66, 66, 66, 255);
    style->Colors[ImGuiCol_TabUnfocusedActive] = ImColor(66, 66, 66, 250);
    style->Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.98f, 0.26f, 0.26f, 0.35f);
    style->Colors[ImGuiCol_NavHighlight] = ImColor(66, 66, 66, 250);
            /*
        style->Colors[ImGuiCol_WindowBg]              = ImColor(0, 0, 0, 190);
        
        style->Colors[ImGuiCol_FrameBg]               = ImColor(0, 0, 0, 255);
        style->Colors[ImGuiCol_FrameBgActive]               = ImColor(0, 0, 0, 255);
        style->Colors[ImGuiCol_FrameBgHovered]               = ImColor(0, 0, 0, 255);
        
        style->Colors[ImGuiCol_PopupBg]               = ImColor(0, 0, 0, 255);
        
        style->Colors[ImGuiCol_Button]                   = ImColor(148, 3, 5, 255);
        style->Colors[ImGuiCol_ButtonActive]             = ImColor(59, 59, 59, 255);
        style->Colors[ImGuiCol_ButtonHovered]            = ImColor(148, 3, 5, 255);
        
        style->Colors[ImGuiCol_TitleBg]               = ImColor(123, 42, 41, 255);
        style->Colors[ImGuiCol_TitleBgActive]         = ImColor(123, 42, 41, 255);
        style->Colors[ImGuiCol_TitleBgCollapsed]      = ImColor(123, 42, 41, 255);
        
        style->Colors[ImGuiCol_CheckMark]             = ImColor(18, 255, 22, 255);
    
   
            style->Colors[ImGuiCol_SliderGrab]             = ImColor(120, 40, 43, 255);
    style->Colors[ImGuiCol_SliderGrabActive]       = ImColor(200, 41, 1, 255);
     
    */
    //ImGui_ImplAndroid_Init(native_window);
    ImGui_ImplAndroid_Init();
ImGui_ImplOpenGL3_Init("#version 300 es");
   RenderingFPS.SetFps(Config.FPSControlSize);
    RenderingFPS.AotuFPS_init();
    RenderingFPS.setAffinity();
    
           ImGuiIO &io = ImGui::GetIO();
           
           
           struct timespec current_timespec;
    static double g_Time = 0.0;
    clock_gettime(CLOCK_MONOTONIC, &current_timespec);
    double current_time = (double)(current_timespec.tv_sec) + (current_timespec.tv_nsec / 1000000000.0);
    ImGui::GetIO().DeltaTime = g_Time > 0.0 ? (float)(current_time - g_Time) : (float)(1.0f / Config.FPSControlSize);
    g_Time = current_time;
    
           
        io.ConfigWindowsMoveFromTitleBarOnly = true;
            io.IniFilename = nullptr;
      //  io.IniFilename = NULL;
     // io.DeltaTime = 20 / 120;/*float(preferredFramesPerSecond ?: 65)*/
    
        static const ImWchar icons_ranges[] = {
            0xf000, 0xf3ff, 
            0x0020, 0x00FF, 
       0x0100, 0x017F,
       0xe000, 0xf538, 
       0xf7f9, 0xf8ff,
            0};
ImFontConfig icons_config;

ImFontConfig CustomFont;
CustomFont.FontDataOwnedByAtlas = true;

icons_config.MergeMode = true;
icons_config.PixelSnapH = true;
icons_config.OversampleH = 2.5;
icons_config.OversampleV = 2.5;




io.Fonts->AddFontFromMemoryTTF((void *)NIKE_data, NIKE_size, 25.0f, NULL, io.Fonts->GetGlyphRangesChineseFull());
 //flamee = io.Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(Custom), sizeof(Custom), 25.f, &CustomFont);

io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 25.0f, &icons_config, icons_ranges);

        flamee = io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 25.0f, &icons_config, icons_ranges);


        ImFontConfig cfg;
    //    cfg.SizePixels = ((float) density / 60.0f);
        cfg.SizePixels = ((float) density / 40.0f);
        io.Fonts->AddFontDefault(&cfg);
        memset(&Config, 0, sizeof(sConfig));
        
// ==========================ESPCOLOR ================================== //
        Config.AimEnable = 0;
        Config.NRGtrigger = 0;
        Config.EnemieCount = 0;
        Config.AimSizeMm = 0;
            Config.FPSControl = 2;
            Config.EspLinetow = 1;
            
           
                      Config.FPSControlSize = 120;
                      
        Config.AimBot.Cross = 80;
        Config.AimBot.Meter = 100;
        Config.AimBot.Recc = 1;
        Config.AimBot.Position = 10;
        Config.AimBot.CrossAimLock = 190;
        Config.XXY = 4.0f;
        //Config.No_move = true;
        Config.NrgAutoBypass = true;
        //Config.GameInfo= true;
Config.MemoryWideViewSize = 80;
Config.AimBot.AimBotSpeed = 5;
//Config.MemoryWideViewSize = 360;
                preferredFramesPerSecond = 60;
             //  getEspFramerate = 60;
        initImGui = true;
        Config.Logo = true;
      //  Config.Fps90 = true;
      
      Config.RadarXx = 10;
      Config.RadarYy = 5;
      Config.RadarSize = 200;
      Config.AimDistance = 150;
    
    
    
}

bool ThirdPerson;
float thirdfloat;

void R3nderMenu() {
    ImGui::SetNextWindowSize(ImVec2(1150, 650));
    ImGui::Begin("(NRG) Test No Need GNativeAndroidApp_Offset ", NULL, ImGuiWindowFlags_NoScrollbar);
    ImGui::Checkbox("test 1", &ThirdPerson);
    ImGui::SliderFloat("test 2", &thirdfloat, 0, 10, "%.1f");
    ImGui::End();
}


EGLBoolean (*old_eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface);
EGLBoolean hook_eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
    eglQuerySurface(dpy, surface, EGL_WIDTH, &glWidth);
    eglQuerySurface(dpy, surface, EGL_HEIGHT, &glHeight);
       if (glWidth <= 0 || glHeight <= 0)
        return old_eglSwapBuffers(dpy, surface);
    if (!setup) {
        SetupImgui();
        setup = true;
    }

    ImGuiIO &io = ImGui::GetIO();
//    io.DisplaySize = ImVec2((float)glWidth, (float)glHeight);

    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame(glWidth, glHeight);
    ImGui::NewFrame();
    // Render ImGui windows here.
    R3nderMenu();
    // Rendering
 //   ImGui::EndFrame();
    ImGui::Render();
    //glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
    
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());


    return old_eglSwapBuffers(dpy, surface);
}



void (*orig_onInputEvent3)(void *inputEvent, void *ex_ab, void *ex_ac);
void onInputEvent3(void *inputEvent, void *ex_ab, void *ex_ac) {
    orig_onInputEvent3(inputEvent, ex_ab, ex_ac);
    if (setup) {
        ImGui_ImplAndroid_HandleInputEventNrg((AInputEvent*)inputEvent, {(float) screenWidth / (float) glWidth, (float) screenHeight / (float) glHeight});
    }
}
HOOKAF(void, Input, void *thiz, void *ex_ab, void *ex_ac) {
    origInput(thiz, ex_ab, ex_ac);
      if (setup) {
   ImGui_ImplAndroid_HandleInputEvent((AInputEvent *)thiz);
    
//    ImGui_ImplAndroid_HandleInputEventNrg((AInputEvent *)thiz, {(float)screenWidth / (float)glWidth, (float)screenHeight / (float)glHeight});

    }
    return;
}

//Define under your main function thread



void *main_thread(void *) {
    
      
            /*
MemoryPatch::createWithHex("libanogs.so", 0x273d80, "C0 03 5F D6").Modify(); //TG : @TEAMNRG1
MemoryPatch::createWithHex("libanogs.so", 0x273db0, "C0 03 5F D6").Modify(); //TG : @TEAMNRG1
MemoryPatch::createWithHex("libanogs.so", 0x274f90, "C0 03 5F D6").Modify(); //TG : @TEAMNRG1
MemoryPatch::createWithHex("libanogs.so", 0x274fc0, "C0 03 5F D6").Modify(); //TG : @TEAMNRG1
MemoryPatch::createWithHex("libanogs.so", 0x274fac, "C0 03 5F D6").Modify(); //TG : @TEAMNRG1
MemoryPatch::createWithHex(OBFUSCATE("libgcloud.so"),0x46687c, OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();
MemoryPatch::createWithHex(OBFUSCATE("libgcloud.so"),0x4668b8, OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();
MemoryPatch::createWithHex(OBFUSCATE("libgcloud.so"),0x46cd98, OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();
MemoryPatch::createWithHex(OBFUSCATE("libgcloud.so"),0x46e364, OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();
MemoryPatch::createWithHex(OBFUSCATE("libgcloud.so"),0x46e3f8, OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();
MemoryPatch::createWithHex(OBFUSCATE("libgcloud.so"),0x46e5b4, OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();
MemoryPatch::createWithHex(OBFUSCATE("libgcloud.so"),0x4705ec, OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();
MemoryPatch::createWithHex(OBFUSCATE("libgcloud.so"),0x46e664, OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();
MemoryPatch::createWithHex(OBFUSCATE("libgcloud.so"),0x47061c, OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();
MemoryPatch::createWithHex(OBFUSCATE("libgcloud.so"),0x470744, OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();
MemoryPatch::createWithHex(OBFUSCATE("libgcloud.so"),0x480538, OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();
MemoryPatch::createWithHex(OBFUSCATE("libgcloud.so"),0x48784c, OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();
MemoryPatch::createWithHex(OBFUSCATE("libgcloud.so"),0x487878, OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();
MemoryPatch::createWithHex(OBFUSCATE("libgcloud.so"),0x4a3eb4, OBFUSCATE("00 00 80 D2 C0 03 5F D6")).Modify();
*/


UE4 = Tools::GetBaseAddress("libUE4.so");
while (!UE4) {
UE4 = Tools::GetBaseAddress("libUE4.so");
 sleep(1);
}

anogs = Tools::GetBaseAddress("libanogs.so");
while (!anogs) {
anogs = Tools::GetBaseAddress("libanogs.so");
 sleep(1);
}

anort = Tools::GetBaseAddress("libanort.so");
while (!anort) {
anort = Tools::GetBaseAddress("libanort.so");
 sleep(1);
}

gcloud = Tools::GetBaseAddress("libgcloud.so");
while (!gcloud) {
gcloud = Tools::GetBaseAddress("libgcloud.so");
 sleep(1);
}



	
	while (!g_App)
	{
        
		//g_App = *(android_app **)(UE4 + GNativeAndroidApp_Offset);
		sleep(1);
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
	UObject::GUObjectArray = (FUObjectArray *)(UE4 + GUObject_Offset);
    
    

//Tools::Hook((void *)(anogs + 0x3A6EA0), (void *)sub_3A6D00, (void **)&hooksub_3A6D00);//NRG


Tools::Hook((void *) (anogs + 0x8E5F6), (void *)hsub_8E5F6, (void **)&sub_8E5F6);//NRG
Tools::Hook((void *) (anogs + 0x60B20), (void *)hsub_60A34, (void **)&osub_60A34);//NRG
Tools::Hook((void *) (anogs + 0x60AC9), (void *)sub_60AC8, (void **)&osub_60AC8);//NRG
Tools::Hook((void *) (anogs + 0x3CD1AC + 0x178),(void *) hsub_1B99A4,(void **) &osub_1B99A4);
Tools::Hook((void *) (anogs + 0x3CD1AC + 0x18C),(void *) hsub_1B99A4,(void **) &osub_1B99A4);
Tools::Hook((void *) (anogs + 0x3CD1AC + 0x1CC),(void *) hsub_1B99A4,(void **) &osub_1B99A4);
Tools::Hook((void *) (anort + 0xc0c58),(void *) hsub_1B99A4,(void **) &osub_1B99A4);
Tools::Hook((void *) (anort + 0xc0a3c),(void *) hsub_1B99A4,(void **) &osub_1B99A4);
Tools::Hook((void *) (anort + 0x144a64),(void *) hsub_1B99A4,(void **) &osub_1B99A4);
Tools::Hook((void *) (anort + 0x12b54C),(void *) hsub_1B99A4,(void **) &osub_1B99A4);
Tools::Hook((void *) (anort + 0x12b3dc),(void *) hsub_1B99A4,(void **) &osub_1B99A4);



	void *egl = dlopen_ex("libEGL.so", 4);
	while (!egl)
	{
		egl = dlopen_ex("libEGL.so", 4);
		sleep(1);
	}
	void *addr = dlsym_ex(egl, "eglSwapBuffers");
	HOOK(addr, _eglSwapBuffers, &orig_eglSwapBuffers);
	dlclose_ex(egl);
    
   
    
    
    pthread_t t;
    
    
    
    
//    pthread_create(&t, 0, maps_thread, 0);
    
	return 0;
}
DWORD findLibrary(const char *library) {
    char filename[0xFF] = {0},
            buffer[1024] = {0};
    FILE *fp = NULL;
    DWORD address = 0;

    sprintf(filename, OBFUSCATE("/proc/self/maps"));

    fp = fopen(filename, OBFUSCATE("rt"));
    if (fp == NULL) {
        perror(OBFUSCATE("fopen"));
        goto done;
    }

    while (fgets(buffer, sizeof(buffer), fp)) {
        if (strstr(buffer, library)) {
            address = (DWORD) strtoul(buffer, NULL, 16);
            goto done;
        }
    }

    done:

    if (fp) {
        fclose(fp);
    }

    return address;
}

//#include "Dobby/Dobby.h"

void *imgui_go(void *) {
    /*
    address = findLibrary("libEGL.so");
    auto addr = (uintptr_t)dlsym(RTLD_NEXT, "eglSwapBuffers");
    DobbyHook((void *)addr, (void *)hook_eglSwapBuffers, (void **)&old_eglSwapBuffers);
    pthread_exit(nullptr);
    */
    
    
    
    void *egl = dlopen_ex("libEGL.so", 4);
    while (!egl)
    {
        egl = dlopen_ex("libEGL.so", 4);
        sleep(1);
    }
    void *addr = dlsym_ex(egl, "eglSwapBuffers");
    HOOK(addr, hook_eglSwapBuffers, &old_eglSwapBuffers);
    dlclose_ex(egl);
    
    return egl;
    
    
    
}

void *imgui_gol(void *) {
 /*
    void *egl = dlopen_ex("libinput.so", 4);
    while (!egl)
    {
        egl = dlopen_ex("libinput.so", 4);
        sleep(1);
    }
    void *addr = dlsym_ex(egl, "_ZN7android13InputConsumer21initializeMotionEventEPNS_11MotionEventEPKNS_12InputMessageE");
    HOOK(addr, myInput, &origInput);
    dlclose_ex(egl);
    
    return egl;
    */
    void *input = dlopen_ex(OBFUSCATE("libinput.so"), 4);
while (!input) {
    input = dlopen_ex(OBFUSCATE("libinput.so"), 4);
    sleep(1);
}

void *address = dlsym_ex(input, OBFUSCATE("_ZN7android13InputConsumer21initializeMotionEventEPNS_11MotionEventEPKNS_12InputMessageE"));
HOOK(address, onInputEvent3, &orig_onInputEvent3);
dlclose_ex(input);
return input;
    
    
}


__attribute__((constructor)) void _init() {
//void hack() {
    pthread_t ptid;
    pthread_create(&ptid, 0, imgui_go, 0);
    pthread_t ptidl;
    pthread_create(&ptidl, 0, imgui_gol, 0);
	pthread_t t;
	pthread_create(&t, 0, main_thread, 0);
}

/*
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void * reserved)
{
    JNIEnv *env;
    vm->GetEnv((void **) &env, JNI_VERSION_1_6);
    
    void *sym_input = DobbySymbolResolver(("/system/lib/libinput.so"), ("_ZN7android13InputConsumer21initializeMotionEventEPNS_11MotionEventEPKNS_12InputMessageE"));
    if (NULL != sym_input) {
        DobbyHook((void *)sym_input, (void *) myInput, (void **)&origInput);
    }
    
   //
    void *sym_input = DobbySymbolResolver("/system/lib/libinput.so", "_ZN7android13InputConsumer21initializeMotionEventEPNS_11MotionEventEPKNS_12InputMessageE");
    if (NULL != sym_input) {
  //  DobbyHook(sym_input, myInput, &origInput);
    
    HOOK(sym_input, myInput, &origInput);
}
    
    ////
    
    
    return JNI_VERSION_1_6;
}*/



//REGISTER_ZYGISK_MODULE(MyModule)

/*
Tools::Hook((void *)(anogs + 0x8E5F6), (void *)hsub_8E5F6, (void **)&sub_8E5F6);//NRG
Tools::Hook((void *)(anogs + 0x60B20), (void *)hsub_60A34, (void **)&osub_60A34);//NRG
Tools::Hook((void *)(anogs + 0x60AC9), (void *)sub_60AC8, (void **)&osub_60AC8);//NRG
Tools::Hook((void *) (anogs + 0x3CD1AC + 0x178),(void *) hsub_1B99A4,(void **) &osub_1B99A4);
Tools::Hook((void *) (anogs + 0x3CD1AC + 0x18C),(void *) hsub_1B99A4,(void **) &osub_1B99A4);
Tools::Hook((void *) (anogs + 0x3CD1AC + 0x1CC),(void *) hsub_1B99A4,(void **) &osub_1B99A4);
Tools::Hook((void *) (anort + 0xc0c58),(void *) hsub_1B99A4,(void **) &osub_1B99A4);
Tools::Hook((void *) (anort + 0xc0a3c),(void *) hsub_1B99A4,(void **) &osub_1B99A4);
Tools::Hook((void *) (anort + 0x144a64),(void *) hsub_1B99A4,(void **) &osub_1B99A4);
Tools::Hook((void *) (anort + 0x12b54C),(void *) hsub_1B99A4,(void **) &osub_1B99A4);
Tools::Hook((void *) (anort + 0x12b3dc),(void *) hsub_1B99A4,(void **) &osub_1B99A4);

//Tools::Hook((void *) (anort + 0x12b3dd),(void *) hsub_1B99A4,(void **) &osub_1B99A4);



MemoryPatch::createWithHex("libanogs.so", 0x3638, "C0 03 5F D6").Modify(); //TG : @TEAMNRG1
MemoryPatch::createWithHex("libanogs.so", 0x8768, "C0 03 5F D6").Modify(); //TG : @TEAMNRG1
MemoryPatch::createWithHex("libanogs.so", 0x91a0, "C0 03 5F D6").Modify(); //TG : @TEAMNRG1
MemoryPatch::createWithHex("libanogs.so", 0x4500a0, "C0 03 5F D6").Modify(); //TG : @TEAMNRG1
MemoryPatch::createWithHex("libanogs.so", 0x4500b8, "C0 03 5F D6").Modify(); //TG : @TEAMNRG1
MemoryPatch::createWithHex("libanogs.so", 0x4504fc, "C0 03 5F D6").Modify(); //TG : @TEAMNRG1
MemoryPatch::createWithHex("libanogs.so", 0x4a4598, "C0 03 5F D6").Modify(); //TG : @TEAMNRG1
MemoryPatch::createWithHex("libanogs.so", 0x4cfb04, "C0 03 5F D6").Modify(); //TG : @TEAMNRG1
MemoryPatch::createWithHex("libanogs.so", 0x4cfb1c, "C0 03 5F D6").Modify(); //TG : @TEAMNRG1
MemoryPatch::createWithHex("libanogs.so", 0x4cfb3c, "C0 03 5F D6").Modify(); //TG : @TEAMNRG1
MemoryPatch::createWithHex("libanogs.so", 0x4cfb54, "C0 03 5F D6").Modify(); //TG : @TEAMNRG1
MemoryPatch::createWithHex("libanogs.so", 0x4cfd44, "C0 03 5F D6").Modify(); //TG : @TEAMNRG1
MemoryPatch::createWithHex("libanogs.so", 0x58fa0c, "C0 03 5F D6").Modify(); //TG : @TEAMNRG1
MemoryPatch::createWithHex("libanogs.so", 0x58fc74, "C0 03 5F D6").Modify(); //TG : @TEAMNRG1
MemoryPatch::createWithHex("libanogs.so", 0x5900cc, "C0 03 5F D6").Modify(); //TG : @TEAMNRG1
MemoryPatch::createWithHex("libanogs.so", 0x591154, "C0 03 5F D6").Modify(); //TG : @TEAMNRG1
MemoryPatch::createWithHex("libanogs.so", 0x594340, "C0 03 5F D6").Modify(); //TG : @TEAMNRG1
MemoryPatch::createWithHex("libanogs.so", 0x595270, "C0 03 5F D6").Modify(); //TG : @TEAMNRG1
MemoryPatch::createWithHex("libanogs.so", 0x599cdc, "C0 03 5F D6").Modify(); //TG : @TEAMNRG1
MemoryPatch::createWithHex("libanogs.so", 0x59c688, "C0 03 5F D6").Modify(); //TG : @TEAMNRG1
MemoryPatch::createWithHex("libanogs.so", 0x5a3af4, "C0 03 5F D6").Modify(); //TG : @TEAMNRG1

MemoryPatch::createWithHex("libanogs.so", 0x387f50, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x387f7c, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x387fc0, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x387ff8, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x388074, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x3880e8, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x388120, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x38813c, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x388184, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x3881cc, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x388214, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x38825c, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x3882a4, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x3882ec, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x388334, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x388390, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x388468, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x3884b0, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x3884f8, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x388544, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x388568, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x3885b4, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x388640, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x3886fc, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x3887ec, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x388818, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x3888ac, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x3888d4, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x38896c, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x3889a8, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x388a90, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x388b20, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x388bb0, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x388c44, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x388d5c, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x388e64, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x388eec, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x388f6c, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x388ff0, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner
MemoryPatch::createWithHex("libanogs.so", 0x389028, "00 00 80 D2 C0 03 5F D6").Modify(); //By Nrg Owner

    ProcMap il2cppMap; do { il2cppMap = KittyMemory::getLibraryMap("libUE4.so");  sleep(1); } while(!il2cppMap.isValid());
TeamNrg.BypassLogo = MemoryPatch::createWithHex("libUE4.so", 0xD90B8 , "00 00 00 00");

TeamNrg.BypassLogo1 = MemoryPatch::createWithHex("libUE4.so", 0x1166BC , "00 00 00 00");
TeamNrg.BypassLogo2 = MemoryPatch::createWithHex("libUE4.so", 0x1166C0, "00 00 00 00");
TeamNrg.BypassLogo3 = MemoryPatch::createWithHex("libUE4.so", 0x18CAE0, "00 00 00 00");
TeamNrg.BypassLogo4 = MemoryPatch::createWithHex("libUE4.so", 0x1B0A4C, "00 00 00 00");
TeamNrg.BypassLogo5 = MemoryPatch::createWithHex("libUE4.so", 0x1CBF94, "00 00 00 00");
TeamNrg.BypassLogo6 = MemoryPatch::createWithHex("libUE4.so", 0x1CCF28, "00 00 00 00");
TeamNrg.BypassLogo7 = MemoryPatch::createWithHex("libUE4.so", 0x1DF658, "00 00 00 00");
TeamNrg.BypassLogo8 = MemoryPatch::createWithHex("libUE4.so", 0x1F26E8, "00 00 00 00");
TeamNrg.BypassLogo9 = MemoryPatch::createWithHex("libUE4.so", 0x1F503C, "00 00 00 00");

TeamNrg.BypassLogo10 = MemoryPatch::createWithHex("libUE4.so", 0x201A68, "00 00 00 00");
TeamNrg.BypassLogo11 = MemoryPatch::createWithHex("libUE4.so", 0x236618, "00 00 00 00");
TeamNrg.BypassLogo12 = MemoryPatch::createWithHex("libUE4.so", 0x236BA0, "00 00 00 00");
TeamNrg.BypassLogo13 = MemoryPatch::createWithHex("libUE4.so", 0x2CE784, "00 00 00 00");
TeamNrg.BypassLogo14 = MemoryPatch::createWithHex("libUE4.so", 0x2FBBC8, "00 00 00 00");
TeamNrg.BypassLogo15 = MemoryPatch::createWithHex("libUE4.so", 0x311610, "00 00 00 00");
TeamNrg.BypassLogo16 = MemoryPatch::createWithHex("libUE4.so", 0x399260, "00 00 00 00");
TeamNrg.BypassLogo17 = MemoryPatch::createWithHex("libUE4.so", 0x3A72CC, "00 00 00 00");
TeamNrg.BypassLogo18 = MemoryPatch::createWithHex("libUE4.so", 0x3A81BC, "00 00 00 00");



*/


