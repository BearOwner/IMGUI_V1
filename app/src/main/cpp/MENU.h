
#include <jni.h>


// Global variables for JNI
JavaVM* g_JavaVM = nullptr;
jobject g_Activity = nullptr;

extern "C" JNIEXPORT void JNICALL Java_com_bearmod_ImGui(JNIEnv* env, jobject activity) {
    g_Activity = env->NewGlobalRef(activity);
    env->GetJavaVM(&g_JavaVM);
}


void EnableSecureFlag() {
    if (!g_JavaVM || !g_Activity) return;

    JNIEnv* env;
    g_JavaVM->AttachCurrentThread(&env, nullptr);

    jclass activityClass = env->GetObjectClass(g_Activity);
    jmethodID enableFlagMethod = env->GetMethodID(activityClass, "enableSecureFlag", "()V");

    if (enableFlagMethod) {
        env->CallVoidMethod(g_Activity, enableFlagMethod);
    }

    g_JavaVM->DetachCurrentThread();
}

void DisableSecureFlag() {
    if (!g_JavaVM || !g_Activity) return;

    JNIEnv* env;
    g_JavaVM->AttachCurrentThread(&env, nullptr);

    jclass activityClass = env->GetObjectClass(g_Activity);
    jmethodID disableFlagMethod = env->GetMethodID(activityClass, "disableSecureFlag", "()V");

    if (disableFlagMethod) {
        env->CallVoidMethod(g_Activity, disableFlagMethod);
    }

    g_JavaVM->DetachCurrentThread();
}

//  #include <imgui.h>

// Global flag to toggle secure mode
bool isSecureModeEnabled = false;

void UpdateSecureMode() {
    if (isSecureModeEnabled) {
        EnableSecureFlag();
    } else {
        DisableSecureFlag();
    }
}



static int AllSkinEnable = 0;
static bool openFlag;


static bool ERROR;//用于初始化窗口位置

void ShowErrorMessage(const char* errorMessage)
{
    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));

    // Create a new ImGui window
    ImGui::Begin("Error", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar/*ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar*/);
//auto Pos = ImGui::GetWindowPos();
    //    Window = ImGui::GetCurrentWindow();
    g_window =  ImGui::GetCurrentWindow();
    // Set window size and position
    //ImGui::SetWindowSize({ 430, 220 });//600.0f,400.0f
    // Set the error message text
    ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "%s", errorMessage); // Red text
    ImGui::SetCursorPos({ 105.0f,130.0f });
    // Add a close button
    if (ImGui::Button("No"))
    {
        ShowMainMenu = true;
        ERROR = false;
        // Code to close the error window
        ImGui::End(); // End the window
        return;
    }
    ImGui::SameLine();
    if (ImGui::Button("Yes"))
    {
        exit(0);
        // Code to close the error window
        ImGui::End(); // End the window
        return;
    }

    ImGui::End(); // End the window
}

#include <android/native_window.h>
#include <android/native_window_jni.h>
#include <android/native_activity.h>
ImFont* Font_Big;

ImFont* TestFont;

extern "C" {
JNIEXPORT void JNICALL Java_com_bearmod_GLES3JNIView_init(JNIEnv* env, jclass cls);
JNIEXPORT void JNICALL Java_com_bearmod_GLES3JNIView_resize(JNIEnv* env, jclass obj, jint width, jint height);
JNIEXPORT void JNICALL Java_com_bearmod_GLES3JNIView_step(JNIEnv* env, jclass obj);
JNIEXPORT void JNICALL Java_com_bearmod_GLES3JNIView_imgui_Shutdown(JNIEnv* env, jobject obj);
JNIEXPORT void JNICALL Java_com_bearmod_GLES3JNIView_MotionEventClick(JNIEnv* env, jclass obj,jboolean down,jfloat PosX,jfloat PosY);
JNIEXPORT jstring JNICALL Java_com_bearmod_GLES3JNIView_getWindowRect(JNIEnv *env, jclass thiz);
JNIEXPORT void JNICALL Java_com_bearmod_GLES3JNIView_real(JNIEnv* env, jobject obj, jint width, jint height);
JNIEXPORT void JNICALL Java_com_bearmod_GLES3JNIView_ScreenSize(JNIEnv * env, jobject obj, jint width, jint theight);
};


extern "C" JNIEXPORT void JNICALL
Java_com_bearmod_GLES3JNIView_ScreenSize(JNIEnv* env,jobject obj, jint px,jint py) {
    ScreenX = px;
    ScreenY = py;
}


extern "C"


/*
std::string base64Image = "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";

 std::string countData4Base64 = "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";
 std::string countData5Base64= "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";

 std::string countData1Base64= "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";
*/


extern "C" JNIEXPORT void JNICALL
Java_com_bearmod_GLES3JNIView_init(JNIEnv* env, jclass cls) {


    if(g_Initialized) return ;
    IMGUI_CHECKVERSION();
    LoadWeaponsphoto();
    LoadWeaponsphoto2();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    ImGui::StyleColorsDark();
    ImGui_ImplAndroid_Init();

    ImGui_ImplOpenGL3_Init("#version 300 es");
    ImGui::GetStyle().ScaleAllSizes(3.0f);
    io.ConfigWindowsMoveFromTitleBarOnly = true;
    io.IniFilename = NULL;

    static const ImWchar icons_ranges[] = { 0xf000, 0xf3ff, 0x0900, 0x097F, 0,};
    ImFontConfig font_config;
    ImFontConfig icons_config;
    ImFontConfig CustomFont;
    CustomFont.FontDataOwnedByAtlas = false;
    icons_config.MergeMode = true;
    icons_config.PixelSnapH = true;
    icons_config.OversampleH = 2.5;
    icons_config.OversampleV = 2.5;

    ImFontConfig icons_config2;
    icons_config2.MergeMode = true;
    //=====================================| 𝗙𝗢𝗡𝗧𝗦
    io.Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(Custom), sizeof(Custom), 30.f, &CustomFont);
    io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 30.0f, &icons_config, icons_ranges);
    Chinese = io.Fonts->AddFontFromMemoryTTF((void*)OPPOSans_H, OPPOSans_H_size, 30.0f, &icons_config2, io.Fonts->GetGlyphRangesChineseFull());



    // Step 1: Decode Base64
    // std::vector<unsigned char> imageData = decodeBase64(base64Image);
    std::vector<unsigned char> imageplayerDataBase64 = decodeBase64(playerDataBase64);
    std::vector<unsigned char> imagerobotDataBase64 = decodeBase64(robotDataBase64);
    std::vector<unsigned char> imagecountData1Base64 = decodeBase64(countData1Base64);
    std::vector<unsigned char> imagecountData3Base64 = decodeBase64(countData3Base64);
    std::vector<unsigned char> imagecountData2Base64 = decodeBase64(countData2Base64);

    //   Base64Image[0] = ImAgeHeadBase64(imageData);
    Base64Image[1] = ImAgeHeadBase64(imageplayerDataBase64);
    Base64Image[2] = ImAgeHeadBase64(imagerobotDataBase64);
    Base64Image[3] = ImAgeHeadBase64(imagecountData1Base64);
    Base64Image[4] = ImAgeHeadBase64(imagecountData3Base64);
    Base64Image[5] = ImAgeHeadBase64(imagecountData2Base64);

    //GUN
    std::vector<unsigned char> imagequanBase64 = decodeBase64(quanBase64);
    WeaponImage[0] = ImAgeHeadBase64(imagequanBase64);
    /////
    std::vector<unsigned char> imageDP28Base64 = decodeBase64(DP28Base64);
    WeaponImage[1] = ImAgeHeadBase64(imageDP28Base64);
    /////
    std::vector<unsigned char> imageM249Base64 = decodeBase64(M249Base64);
    WeaponImage[2] = ImAgeHeadBase64(imageM249Base64);
    /////
    std::vector<unsigned char> imagemg3Base64 = decodeBase64(mg3Base64);
    WeaponImage[3] = ImAgeHeadBase64(imagemg3Base64);
    /////
    std::vector<unsigned char> imageS686Base64 = decodeBase64(S686Base64);
    WeaponImage[4] = ImAgeHeadBase64(imageS686Base64);
    /////
    std::vector<unsigned char> imageDBSBase64 = decodeBase64(DBSBase64);
    WeaponImage[5] = ImAgeHeadBase64(imageDBSBase64);
    /////
    std::vector<unsigned char> imageS12KBase64 = decodeBase64(S12KBase64);
    WeaponImage[6] = ImAgeHeadBase64(imageS12KBase64);
    /////
    std::vector<unsigned char> imageYNBase64 = decodeBase64(YNBase64);
    WeaponImage[7] = ImAgeHeadBase64(imageYNBase64);
    /////
    std::vector<unsigned char> imageQBZBase64 = decodeBase64(QBZBase64);
    WeaponImage[8] = ImAgeHeadBase64(imageQBZBase64);
    /////
    std::vector<unsigned char> imageM416Base64 = decodeBase64(M416Base64);
    WeaponImage[9] = ImAgeHeadBase64(imageM416Base64);
    /////
    std::vector<unsigned char> imageQBUBase64 = decodeBase64(QBUBase64);
    WeaponImage[10] = ImAgeHeadBase64(imageQBUBase64);
    /////
    std::vector<unsigned char> imageSLRBase64 = decodeBase64(SLRBase64);
    WeaponImage[11] = ImAgeHeadBase64(imageSLRBase64);
    /////
    std::vector<unsigned char> imageSKSBase64 = decodeBase64(SKSBase64);
    WeaponImage[12] = ImAgeHeadBase64(imageSKSBase64);
    /////
    std::vector<unsigned char> imageMINIBase64 = decodeBase64(MINIBase64);
    WeaponImage[13] = ImAgeHeadBase64(imageMINIBase64);
    /////
    std::vector<unsigned char> imageM24Base64 = decodeBase64(M24Base64);
    WeaponImage[14] = ImAgeHeadBase64(imageM24Base64);
    /////
    std::vector<unsigned char> imagek98Base64 = decodeBase64(k98Base64);
    WeaponImage[15] = ImAgeHeadBase64(imagek98Base64);
    /////
    std::vector<unsigned char> imageawmBase64 = decodeBase64(awmBase64);
    WeaponImage[16] = ImAgeHeadBase64(imageawmBase64);
    /////
    std::vector<unsigned char> imagemk14Base64 = decodeBase64(mk14Base64);
    WeaponImage[17] = ImAgeHeadBase64(imagemk14Base64);
    /////
    std::vector<unsigned char> imageMOBase64 = decodeBase64(MOBase64);
    WeaponImage[18] = ImAgeHeadBase64(imageMOBase64);
    /////
    std::vector<unsigned char> imagevssBase64 = decodeBase64(vssBase64);
    WeaponImage[19] = ImAgeHeadBase64(imagevssBase64);
    /////
    std::vector<unsigned char> imageM762Base64 = decodeBase64(M762Base64);
    WeaponImage[20] = ImAgeHeadBase64(imageM762Base64);
    /////
    std::vector<unsigned char> imageSCARBase64 = decodeBase64(SCARBase64);
    WeaponImage[21] = ImAgeHeadBase64(imageSCARBase64);
    /////
    std::vector<unsigned char> imageM16Base64 = decodeBase64(M16Base64);
    WeaponImage[22] = ImAgeHeadBase64(imageM16Base64);
    /////
    std::vector<unsigned char> imageMK47Base64 = decodeBase64(MK47Base64);
    WeaponImage[23] = ImAgeHeadBase64(imageMK47Base64);
    /////
    std::vector<unsigned char> imagegrozaBase64 = decodeBase64(grozaBase64);
    WeaponImage[24] = ImAgeHeadBase64(imagegrozaBase64);
    /////
    std::vector<unsigned char> imageaugBase64 = decodeBase64(augBase64);
    WeaponImage[25] = ImAgeHeadBase64(imageaugBase64);
    /////
    std::vector<unsigned char> imageAkmBase64 = decodeBase64(AkmBase64);
    WeaponImage[26] = ImAgeHeadBase64(imageAkmBase64);
    /////
    std::vector<unsigned char> imageleiBase64 = decodeBase64(leiBase64);
    WeaponImage[27] = ImAgeHeadBase64(imageleiBase64);
    /////
    std::vector<unsigned char> imageyanBase64 = decodeBase64(yanBase64);
    WeaponImage[28] = ImAgeHeadBase64(imageyanBase64);
    /////
    std::vector<unsigned char> imagethuoBase64 = decodeBase64(thuoBase64);
    WeaponImage[29] = ImAgeHeadBase64(imagethuoBase64);
    /////
    std::vector<unsigned char> imageGUOBase64 = decodeBase64(GUOBase64);
    WeaponImage[30] = ImAgeHeadBase64(imageGUOBase64);
    /////
    std::vector<unsigned char> imageLIANBase64 = decodeBase64(LIANBase64);
    WeaponImage[31] = ImAgeHeadBase64(imageLIANBase64);
    /////
    std::vector<unsigned char> imageDAOBase64 = decodeBase64(DAOBase64);
    WeaponImage[32] = ImAgeHeadBase64(imageDAOBase64);
    /////
    std::vector<unsigned char> imageGUNBase64 = decodeBase64(GUNBase64);
    WeaponImage[33] = ImAgeHeadBase64(imageGUNBase64);
    /////
    std::vector<unsigned char> imageMP5KBase64 = decodeBase64(MP5KBase64);
    WeaponImage[34] = ImAgeHeadBase64(imageMP5KBase64);
    /////
    std::vector<unsigned char> imageTANGBase64 = decodeBase64(TANGBase64);
    WeaponImage[35] = ImAgeHeadBase64(imageTANGBase64);
    /////
    std::vector<unsigned char> imageUMP9Base64 = decodeBase64(UMP9Base64);
    WeaponImage[36] = ImAgeHeadBase64(imageUMP9Base64);
    /////
    std::vector<unsigned char> imageUZIBase64 = decodeBase64(UZIBase64);
    WeaponImage[37] = ImAgeHeadBase64(imageUZIBase64);
    /////
    std::vector<unsigned char> imageVKTBase64 = decodeBase64(VKTBase64);
    WeaponImage[38] = ImAgeHeadBase64(imageVKTBase64);
    /////
    std::vector<unsigned char> imageP92Base64 = decodeBase64(P92Base64);
    WeaponImage[39] = ImAgeHeadBase64(imageP92Base64);
    /////
    std::vector<unsigned char> imageP1911Base64 = decodeBase64(P1911Base64);
    WeaponImage[40] = ImAgeHeadBase64(imageP1911Base64);
    /////
    std::vector<unsigned char> imageR1895Base64 = decodeBase64(R1895Base64);
    WeaponImage[41] = ImAgeHeadBase64(imageR1895Base64);
    /////
    std::vector<unsigned char> imageP18CBase64 = decodeBase64(P18CBase64);
    WeaponImage[42] = ImAgeHeadBase64(imageP18CBase64);
    /////
    std::vector<unsigned char> imageR45Base64 = decodeBase64(R45Base64);
    WeaponImage[43] = ImAgeHeadBase64(imageR45Base64);
    //////
    std::vector<unsigned char> imageDaggerBase64 = decodeBase64(DaggerBase64);
    WeaponImage[44] = ImAgeHeadBase64(imageDaggerBase64);


    RenderImage[0] = ImAgeHeadFile(ICON, sizeof(ICON));
    RenderImage[1] = ImAgeHeadFile(SafeHEX, sizeof(SafeHEX));
    RenderImage[2] = ImAgeHeadFile(ShowHEX, sizeof(ShowHEX));



    //Font_Big = io.Fonts->AddFontFromMemoryTTF((void*)Font_data, Font_size, 24.0f, &Font_cfg, io.Fonts->GetGlyphRangesChineseFull());
    g_Initialized=true;



}

extern "C" JNIEXPORT void JNICALL
Java_com_bearmod_GLES3JNIView_resize(JNIEnv* env, jclass obj, jint width, jint height) {
    glWidth = (int) width;
    glHeight = (int) height;

    glViewport(0, 0, width, height);
    ImGuiIO &io = ImGui::GetIO();
    io.ConfigWindowsMoveFromTitleBarOnly = false;
    io.IniFilename = NULL;

    ImGui::GetIO().DisplaySize = ImVec2((float)width, (float)height);
}




void Helpmarker(const char* Text, ImVec4 Color)
{
    ImGui::TextColored(Color, u8"(?)");
    if (ImGui::IsItemHovered())
    {
        ImGui::SetTooltip(Text);
    }
}



static float g_FPS = 0.0f;
static float g_LastTime = 0.0f;
void UpdateFPS() {
    static auto lastFrameTime = std::chrono::high_resolution_clock::now();
    auto currentTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> deltaTime = currentTime - lastFrameTime;
    lastFrameTime = currentTime;
    float dt = deltaTime.count();
    if (dt > 0.0f) {
        g_FPS = 1.0f / dt;
    }
}




#include <fstream>
#include <sstream>
#include <string>
#include <android/log.h>

#define LOG_TAG "MemoryInfo"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

float GetMemoryUsage22() {
    std::ifstream meminfo("/proc/meminfo");
    std::string line;
    unsigned long total_memory = 0;
    unsigned long free_memory = 0;

    while (std::getline(meminfo, line)) {
        if (line.find("MemTotal:") != std::string::npos) {
            std::stringstream ss(line);
            std::string label;
            ss >> label >> total_memory;
        } else if (line.find("MemFree:") != std::string::npos) {
            std::stringstream ss(line);
            std::string label;
            ss >> label >> free_memory;
        }
    }

    float used_memory = total_memory - free_memory;
    float used_memory_mb = used_memory / 1024.0f;
    float used_memory_gb = used_memory_mb / 1024.0f;

    LOGI("Used Memory: %.2f MB (%.2f GB)", used_memory_mb, used_memory_gb);
    return used_memory_mb;
}


static int m_Width = 1250;
static int m_Height = 770;



static int languageIndex = 0;

const char* languageText(const char* engText, const char* cnText, const char* krText, const char*arText) {
    switch (languageIndex) {
        case 0:
            return engText;
        case 1:
            return cnText;
        case 2:
            return krText;
        case 3:
            return arText;
        default:
            return engText;
    }
}

ImFont* fontText() {
    switch (languageIndex) {
        case 0:
            return Chinese;
        case 1:
            return Chinese;
        case 2:
            return Chinese;//Kr
        case 3:
            return Chinese;//th
        default:
            return Chinese;
    }
}
bool MemuSwitch = true;
bool BallSwitch = true;
ImGuiWindow *Window;

int MenuTab = 1;
bool  IsDown2 = false, IsWin = true;
ImVec2 ImagePos = {0, 0};
static int MENULANGUAGE = 0;



void loadConfig()
{
    std::string PackName;
    PackName += "/storage/emulated/0/Android/data/";
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
    PackName2 += "/storage/emulated/0/Android/data/";
    PackName2 += GetPackageName().c_str();
    PackName2 += "/files/Nrg.ini";
    std::string PackName3;
    PackName3 += "chmod 777 /storage/emulated/0/Android/data/";
    PackName3 += GetPackageName().c_str();
    PackName3 += "/files/Nrg.ini";
    int fd = open(PackName2.c_str(), O_WRONLY | O_CREAT, 0644);
    system(PackName3.c_str());
    write(fd, &Config, sizeof(Config));
    write(fd, &s, sizeof(s));
    close(fd);
}

// ======================================================================== //
void DeleteConfig()
{
    std::string PackName4;
    PackName4 += "/storage/emulated/0/Android/data/";
    PackName4 += GetPackageName().c_str();
    PackName4 += "/files/Nrg.ini";
    int fd = remove(PackName4.c_str());
    close(fd);
}

void DeleDataConfig()
{
    std::string DeleData;
    DeleData += "rm -rf /storage/emulated/0/Android/data/";
    DeleData += GetPackageName().c_str();
    DeleData += "/cache";
    system(DeleData.c_str());
//close(fd);
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

void DeleteCFG(){
    DeleDataConfig();
}

void DrawLogo(ImVec2 center, float size) {

    ImGui::SetCursorPos({127, 118});
    ImDrawList *draw_list = ImGui::GetWindowDrawList();//0
    draw_list->AddImage(RenderImage[0].textureId, {center.x - size / 2, center.y - size /  2},{center.x + size / 2, center.y + size / 2});


}
bool TestJavAcpp = true;


bool Cshzt=false;


//static bool GL_AIM_BLOCK = false;
void MenuDraw(bool MenuOnOff) {
// if (!g_Token.empty() && !g_Auth.empty() && g_Token == g_Auth) {

//  int AddGetGameFps = GetGameFps();


    static bool IsBall = true;

    if (IsBall){
        ImGui::SetWindowSize("BEAR", {0, 0},ImGuiCond_FirstUseEver );
    } else{
        ImGui::SetWindowSize("BEAR", {m_Width, m_Height},ImGuiCond_FirstUseEver );
        BallSwitch = true;
    }

    if (BallSwitch)
    {
        //Style.WindowRounding = 80.0f;
        if (ImGui::Begin("Ball", &BallSwitch,  ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar))
        {
            auto Pos = ImGui::GetWindowPos();
            Window = ImGui::GetCurrentWindow();
            g_window =  ImGui::GetCurrentWindow();
            if (!Config.Handcam){
                DrawLogo({Pos.x + 80, Pos.y + 80}, 120);
            }



            if (ImGui::IsItemActive()) {
                if (!IsDown2) {
                    IsDown2 = true;
                    ImagePos = ImGui::GetWindowPos();
                }
            } else if (IsDown2) {
                IsDown2 = false;
                if(ImagePos.x == ImGui::GetWindowPos().x && ImagePos.y == ImGui::GetWindowPos().y) {
                    IsBall = true;
                    ShowMainMenu = true;
                    BallSwitch = false;
                    //  ImGui::SetWindowPos("MOMO", Pos, ImGuiCond_Always);
                }

            }

        }
        ImGui::End();
    }
    if (ERROR) {
        ShowErrorMessage("Are you going to exit the game?");
    }
    if (MenuOnOff) {

        ImGuiStyle& Style = ImGui::GetStyle();

        auto Color = Style.Colors;
        static bool MenuLock;

        static bool WinPos = true;//用于初始化窗口位置

        static bool CheckBox_1 = false, CheckBox_2 = true;
        static int InputInt = 0;
        static int Comb = 0;
        static float InputFloat = 0;
        static char InputString[80] = { '?' };
        const char* hhhhhhh = "/storage/emulated/0/DCIM/IMGUI/NRG_TEST.png";

        static int Tab = 0;


        enum Tab
        {



            Panel,
            Button,
            Input,
            CheckBox
        };

        static int Color_ = 0;
        enum Color_
        {
            Red,
            Green,
            Blue,
            Orange
        };

        if (WinPos)//初始化窗口
        {

            ImVec2 center = ImGui::GetMainViewport()->GetCenter();
            ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
            WinPos = false;//初始化完毕
        }

        if (MenuLock) {
            ImGui::Begin(u8"BEAR", &ShowMainMenu, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings);//开始绘制窗口

        } else {
            ImGui::Begin(u8"BEAR", &ShowMainMenu, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings);//开始绘制窗口

        }


//auto Pos = ImGui::GetWindowPos();
        auto Pos = ImGui::GetWindowPos();
        Window = ImGui::GetCurrentWindow();
        g_window =  ImGui::GetCurrentWindow();


        {
            //   ImGui::GetWindowDrawList()->AddLine({ ImGui::GetWindowPos().x + 980.0f,ImGui::GetWindowPos().y + 10.0f }, { ImGui::GetWindowPos().x + 980.0f,ImGui::GetWindowPos().y + 460.0f }, ImColor(255, 255, 255, 255));

            ImGui::SetCursorPos({ 980.0f,20.0f });
            // ImGui::PushFont(Chinese);

            ImGui::PushFont(Chinese);
            //ImGui::TextColored(Color[ImGuiCol_Button], u8"BEAR-MOD");
            ImGui::Text("BEAR-MOD");
            ImGui::PopFont();

            ImGui::SetCursorPos({ 930.0f,65.0f });

            //   ImGui::PushStyleColor(ImGuiCol_Button, Tab == Tab::Panel ? Color[ImGuiCol_Button] : ImVec4(0.18f, 0.18f, 0.18f, 1.00f));
            ImGui::PushStyleColor(ImGuiCol_Button, Tab == Tab::Panel ? Color[ImGuiCol_Button] : ImVec4(0.80f, 0.80f, 0.83f, 0.31f));
            if (ImGui::Button(u8"Esp", { 310.0f,50.0f }))
            {
                Tab = Tab::Panel;
            }
            ImGui::PopStyleColor();

            ImGui::PushStyleColor(ImGuiCol_Button, Tab == Tab::Button ? Color[ImGuiCol_Button] : ImVec4(0.80f, 0.80f, 0.83f, 0.31f));
            ImGui::SetCursorPos({ 930.0f,125.0f });
            if (ImGui::Button(u8"Items", { 310.0f,50.0f }))
            {
                Tab = Tab::Button;
            }
            ImGui::PopStyleColor();

            ImGui::PushStyleColor(ImGuiCol_Button, Tab == Tab::Input ? Color[ImGuiCol_Button] : ImVec4(0.80f, 0.80f, 0.83f, 0.31f));
            ImGui::SetCursorPos({ 930.0f,185.0f });
            if (ImGui::Button(u8"Skin", { 310.0f,50.0f }))
            {
                Tab = Tab::Input;
            }
            ImGui::PopStyleColor();

            ImGui::PushStyleColor(ImGuiCol_Button, Tab == Tab::CheckBox ? Color[ImGuiCol_Button] : ImVec4(0.80f, 0.80f, 0.83f, 0.31f));
            ImGui::SetCursorPos({ 930.0f,245.0f });
            if (ImGui::Button(u8"Aim", { 310.0f,50.0f }))
            {
                Tab = Tab::CheckBox;
            }

            ImGui::PopStyleColor();

            ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.80f, 0.80f, 0.83f, 0.31f));
            ImGui::SetCursorPos({ 930.0f,305.0f });
            //   ImGui::SetCursorPos({ 920.0f,245.0f });
            if (ImGui::Button(u8"Close", { 310.0f,50.0f }))
            {
                IsBall = false;
                ShowMainMenu = false;
                // ShowMainMenu = false;
                // ERROR = true;
            }
            ImGui::PopStyleColor();

            ImGui::SetCursorPos({ 930.0f,370.0f });
            ImGui::SetNextItemWidth(310.0f);
            const char* Language[] = {
                    "English",//Off
                    "中国"};//11
            ImGui::Combo(u8" ", &languageIndex, Language, IM_ARRAYSIZE(Language)); //u8"English\0中国"/*\0蓝色\0橙色"*/);


            S_PRA_STATIC ImColor col;
            std::string exp = GetExpired(&col);

            ImGui::SetCursorPos({ 920.0f,440.0f });
            ImGui::Text(u8"KeyTime:");

            ImGui::SetCursorPos({ 930.0f,470.0f });
            ImGui::TextColored(col, exp.c_str());


            ImGui::SetCursorPos({ 930.0f,510.0f });
            ImGui::Text(u8"UserKey:");
            ImGui::SetCursorPos({ 920.0f,540.8f });
            ImGui::TextColored(Color[ImGuiCol_Button], USERKEY.c_str());

            ImGui::SetCursorPos({ 930.0f,580.0f });
            if (!strcmp(GetPackageName().c_str(), "com.bearmod")) {
                ImGui::Text(" ");
                //   GL_AIM_BLOCK = false;
            }

            if (!strcmp(GetPackageName().c_str(), "com.tencent.ig")) {
                ImGui::Text("Game: PUBGM GL");
               // GL_AIM_BLOCK = false;
            }

            if (!strcmp(GetPackageName().c_str(), "com.pubg.krmobile")) {
                ImGui::Text("Game: PUBGM KR");
            }

            if (!strcmp(GetPackageName().c_str(), "com.vng.pubgmobile")) {
                ImGui::Text("Game: PUBGM VNG");
            }

            if (!strcmp(GetPackageName().c_str(), "com.rekoo.pubgm")) {
                ImGui::Text("Game: PUBGM TW");
            }
            ImGui::SetCursorPos({ 930.0f,620.0f });
            //   std::string sFPS = "";
            //   g_FPS += std::to_string(GetGameFps());


            ImGui::Text("Version: 10 - 64Bit\nFPS: %.1f", g_FPS);

            ImGui::SetCursorPos({ 930.0f,695.0f });
            ImGui::TextColored(Color[ImGuiCol_Button], u8"@Bearfeedbackbot");

        }


        ImGui::SetCursorPos({ 10.0f,10.0f });
        ImGui::BeginChild(u8"Fucking", { 890.0f,745.0f }, true);



        switch (Tab)
        {
            case Tab::Panel:
                ImGui::PushFont(Chinese);
                ImGui::BulletText(u8"ESP");
                ImGui::PopFont();
              
                ImGui::Separator();

                //   ImGui::Separator();
                if (ImGui::BeginTable("split", 2)) {
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(languageText(u8"Box",u8"盒子","",""), &Config.Box);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(languageText(u8"Bone",u8"骨骼","",""), &Config.EspBone);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(languageText(u8"Line",u8"线","",""), &Config.EspLine);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(languageText(u8"Distance",u8"距离","",""), &Config.Distance);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(languageText(u8"Weapon",u8"武器","",""), &Config.Weapon);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(languageText(u8"Health",u8"健康","",""), &Config.Health);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(languageText(u8"TeamId",u8"队编Id","",""), &Config.TeamId);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(languageText(u8"Name",u8"姓名","",""), &Config.Name);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(languageText(u8"360° Alert",u8"360° 警报","",""), &Config.Alert);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(languageText(u8"Grenade",u8"手雷预警","",""), &Config.GrenadeW);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(languageText(u8"RadarMap",u8"雷达地图","",""), &Config.RadarMap);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(languageText(u8"IgnoreBot",u8"忽略机器人","",""), &Config.EspHideBot);
                    ImGui::TableNextColumn();
                    ImGui::EndTable();

                }
                ImGui::Separator();

                ImGui::RadioButton("60FPS", &Config.RunFPS, 60.0f);
                ImGui::SameLine();
                ImGui::RadioButton("90FPS", &Config.RunFPS, 90.0f);
                ImGui::SameLine();
                ImGui::RadioButton("120FPS", &Config.RunFPS, 120.0f);
                ImGui::SameLine();
                ImGui::RadioButton("144FPS", &Config.RunFPS, 144.0f);

                ImGui::Checkbox(languageText("WideView","试图","",""), &Config.MemoryWideView);
                ImGui::SameLine();
                ImGui::Checkbox(languageText( "Handcam ","手持摄像机-隐藏","",""), &Config.Handcam);
                //Handcam &
                ImGui::SameLine();
                ImGui::Checkbox(MenuLock? "MenuMove-UnLock" : "MenuMove-Lock", &MenuLock);

                ImGui::Separator();
                //     ImGui::Spacing();

                ImGui::SliderFloat(languageText("View Size","绘图大小调节","",""),&Config.MemoryWideViewSize, 90, 140, "%.0f");



                break;
            case Tab::Button:
                ImGui::PushFont(Chinese);
                ImGui::BulletText(u8"ITEMS");
                ImGui::PopFont();
                //   ImGui::SameLine();
                //    Helpmarker(u8"按钮示例", Color[ImGuiCol_Button]);
                ImGui::Separator();


                ImGui::Text(OBFUSCATE("Rifle"));
                if (ImGui::BeginTable("split", 3)) {
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(OBFUSCATE("M416"), &Config.M416);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox( OBFUSCATE("AKM"), &Config.AKM);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox( OBFUSCATE("SCAR-L"), &Config.SCARL);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(OBFUSCATE("ACE32"), &Config.ACE32);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox( OBFUSCATE("Groza"), &Config.Groza);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox( OBFUSCATE("AUG"), &Config.AUG);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(OBFUSCATE("QBZ"), &Config.QBZ);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox( OBFUSCATE("M762"), &Config.M762);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox( OBFUSCATE("G36C"), &Config.G36C);
                    ImGui::TableNextColumn();
                    ImGui::EndTable();
                }

                ImGui::Text(OBFUSCATE("Smg"));
                if (ImGui::BeginTable("split", 3)) {
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(OBFUSCATE("UMP-45"), &Config.UMP45);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox( OBFUSCATE("UZI"), &Config.UZI);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox( OBFUSCATE("Vector"), &Config.Vector);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(OBFUSCATE("TommyGun"), &Config.TommyGun);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox( OBFUSCATE("PP-19 Bizon"), &Config.PP19Bizon);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox( OBFUSCATE("P90"), &Config.P90);
                    ImGui::TableNextColumn();
                    ImGui::EndTable();
                }

                ImGui::Text(OBFUSCATE("Sniper"));
                if (ImGui::BeginTable("split", 3)) {
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(OBFUSCATE("Kar98K"), &Config.Kar98K);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox( OBFUSCATE("M24"), &Config.M24);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(OBFUSCATE("Car"), &Config.EspCar);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox( OBFUSCATE("AWM"), &Config.AWM);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(OBFUSCATE("AMR"), &Config.AMR);
                    ImGui::TableNextColumn();
                    ImGui::Checkbox(OBFUSCATE("Box"), &Config.EspLootBox);
                    ImGui::TableNextColumn();
                    ImGui::EndTable();
                }
/*
ImGui::Text(OBFUSCATE("Ammor(IFLE)"));
if (ImGui::BeginTable("split", 2)) {
ImGui::TableNextColumn();
ImGui::Checkbox(OBFUSCATE("5.56mm"), &Config.mm556);
ImGui::TableNextColumn();
ImGui::Checkbox( OBFUSCATE("7.62mm"), &Config.mm762);
ImGui::TableNextColumn();
ImGui::EndTable();
}

ImGui::Text(OBFUSCATE("Ammor(Smg)"));
if (ImGui::BeginTable("split", 2)) {
ImGui::TableNextColumn();
ImGui::Checkbox( OBFUSCATE("9mm"), &Config.mm9);
ImGui::TableNextColumn();
ImGui::Checkbox( OBFUSCATE(".45 ACP"), &Config.ACP45);
ImGui::TableNextColumn();
ImGui::EndTable();
}
ImGui::Text(OBFUSCATE("Bag/Armor/Helmet"));
if (ImGui::BeginTable("split", 3)) {
ImGui::TableNextColumn();
ImGui::Checkbox( OBFUSCATE("Bag"), &Config.Bag);
ImGui::TableNextColumn();
ImGui::Checkbox( OBFUSCATE("Armor"), &Config.Armor);
ImGui::TableNextColumn();
ImGui::Checkbox( OBFUSCATE("Helmet"), &Config.Helmet);
ImGui::TableNextColumn();
ImGui::EndTable();
        }
            */

                break;


            case Tab::Input:
                ImGui::PushFont(Chinese);
                ImGui::BulletText(u8"Skin");
                ImGui::PopFont();
                ImGui::Separator();

                ImGui::Spacing();
                //ImGui::Checkbox("OutfitSkin(In Game)", &Config.OutfitEnable);
               // ImGui::SameLine();
                ImGui::Checkbox("WeaponSkin", &Config.SkinEnable);
                ImGui::SameLine();
                ImGui::Checkbox("WeaponDeadBox", &Config.BoxEffect);
              //  ImGui::SameLine();
              //  ImGui::Checkbox("VehicleSkin", &Config.CarMod);
                ImGui::Separator();

                ImGui::Spacing();

                if (ImGui::CollapsingHeader("Backpack:", ImGuiTreeNodeFlags_Bullet | ImGuiTreeNodeFlags_None)) if (ImGui::CollapsingHeader("Bag:", ImGuiTreeNodeFlags_Bullet | ImGuiTreeNodeFlags_None)) if (ImGui::CollapsingHeader("Armor / Helmet:", ImGuiTreeNodeFlags_Bullet | ImGuiTreeNodeFlags_None)) {
                }
/*
                // Skin data organized into constants
                static const std::vector<std::string> xSuitSkins = {
                    "Default",
                    "Blood Raven X-Suit (6-Star)",
                    "Golden Pharaoh X-Suit (6-Star)",
                    "Golden Pharaoh X-Suit (7-Star)",
                    "Avalanche X-Suit (6-Star)",
                    "Iridescence X-Suit (6-Star)",
                    "Poseidon X-Suit (6-Star)",
                    "Arcane Jester X-Suit (6-Star)",
                    "Silvanus X-Suit (6-Star)",
                    "Marmoris X-Suit (7-Star)",
                    "Fiore X-Suit (7-Star)",
                    "Ignis X-Suit (7-Star)",
                    "Stygian Liege X-Suit (6-Star)",
                    "Galadria X-Suit (7-Star)"
                };

                static const std::vector<std::string> set1Skins = {
                    "Default",
                    "Glacier -outfit Set",
                    "Wanderer Outfit",
                    "Dream Striker Set",
                    "Magick Delight Set",
                    "The Fool - Set",
                    "Smooth Hitman Set",
                    "Anniversary Set",
                    "Dazzling Youth Set",
                    "Red Commander Set",
                    "Dark Widow - Set",
                    "Violet Halo - Set",
                    "Yellow Mummy Set",
                    "White Mummy Set",
                    "Psychophage Set",
                    "Golden Trigge Set",
                    "Flamewraith - Set",
                    "Silver Guru Set",
                    "City Casual Set",
                    "Dragon Emperor Set",
                    "Killua Character Set"
                };

                static const std::vector<std::string> set2Skins = {
                    "Default",
                    "Sweet Bunny Set",
                    "Forest Elf Outfit Set",
                    "Friends Raincoat Set",
                    "LINE FRIENDS Dress",
                    "Sushi Fantasy Outfit",
                    "BAPE X PUBGM Set",
                    "BAPE CAMO HOODIE",
                    "Impossible Fallout Set",
                    "Masked Psychic Set",
                    "Arts Gentleman Set",
                    "Leopard Suit Outfit",
                    "Dark Gold Top Set",
                    "Temperance's Virtue Set",
                    "The Lover's Grace Set"
                };
*/
                static const std::vector<std::string> backpackSkins = {
                    "Default",
                    "Blood Raven Bag",
                    "Pharaoh's Regalia",
                    "Poseidon Backpack",
                    "Luminous Backpack",
                    "The Fool Backpack",
                    "Godzilla Backpack",
                    "Frosty Snowglobe",
                    "Ebil Bunny Backpack",
                    "Monster Backpack",
                    "Shinobi Spirit Backpack",
                    "BAPE X PUBGM CAMO",
                    "King Ghidorah Backpack",
                    "Flamewraith Backpack",
                    "Deluxe Treasure Backpack",
                    "Bramble Overlord Backpack"
                };

                static const std::vector<std::string> helmetSkins = {
                    "Default",
                    "Scarlet Beast (Helmet)",
                    "Inferno Rider (Helmet)",
                    "Glacier (Helmet)",
                    "Moon Bunny (Helmet)",
                    "Mutated (Helmet)",
                    "Intergalactic (Helmet)",
                    "Masked Psychic (Helmet)",
                    "Atlantic Tech (Helmet)",
                    "Mystic Battle (Helmet)",
                    "Godzilla (Helmet)"
                };

                {
                    // Reusable function for rendering skin selectors
                    auto RenderSkinSelector = [](const std::vector<std::string>& skins, int& value, const char* label) {
                        ImGui::Text("%s", label);  // Use label directly instead of OBFUSCATE for runtime strings
                        if (ImGui::BeginTable("split", 2)) {
                            ImGui::TableNextColumn();
                            size_t clampedIndex = std::clamp(value, 0, (int)skins.size() - 1);
                            ImGui::Text(skins[clampedIndex].c_str());
                            ImGui::TableNextColumn();
                            ImGui::InputInt("##Skin", &value);
                            ImGui::EndTable();
                        }
                        value = std::clamp(value, 0, (int)skins.size() - 1);
                    };

                 ///   RenderSkinSelector(xSuitSkins, SuitSkinHackHudSdk, "X-Suit");
                    //RenderSkinSelector(set1Skins, SpSuitSkinHackHudSdk, "Set(1)");
                  //  RenderSkinSelector(set2Skins, TdmSuitSkinHackHudSdk, "Set(2)");

                    ImGui::Checkbox("Backpack & Helmet Skin", &Config.HelmetlAndBag);
                    RenderSkinSelector(backpackSkins, bagSkinHackHudSdk, "Backpack");
                    RenderSkinSelector(helmetSkins, helmetSkinHackHudSdk, "Helmet");

                    ImGui::Separator();
                    ImGui::RadioButton("    AR  ", &AllSkinEnable, 0);
                    ImGui::SameLine();
                    ImGui::RadioButton("   SMG ", &AllSkinEnable, 1);
                    ImGui::SameLine();
                    ImGui::RadioButton(" SNIPER", &AllSkinEnable, 2);
                    ImGui::SameLine();
                    ImGui::RadioButton("VEHICLE", &AllSkinEnable, 3);

                    ImGui::Separator();

                    // AR skins
                    static const std::vector<std::string> m416Skins = {
                        "Default",
                        "Glacier M416 (Lv. 7)",
                        "The Fool M416 (Lv. 7)",
                        "Wanderer M416 (Lv. 7)",
                        "Lizard Roar M416 (Lv. 7)",
                        "Call of M416 (Lv. 7)",
                        "TechnoCore M416 (Lv. 7)",
                        "Imperial M416 (Lv. 8)",
                        "Silver M416 (Lv. 8)",
                        "Embrace M416 (Lv. 8)",
                        "Shinobi M416 (Lv. 8)",
                        "Sealed M416 (Lv. 8)"
                    };

                    static const std::vector<std::string> akmSkins = {
                        "Default",
                        "Glacier - AKM (Lv. 7)",
                        "Desert Fossil - AKM (Lv. 7)",
                        "Jack-o'-lantern - (Lv. 7)",
                        "Ghillie Dragon -  (Lv. 7)",
                        "Gold Pirate - AKM (Lv. 7)",
                        "Codebreaker - AKM (Lv. 7)",
                        "Wandering Tyrant - (Lv. 8)",
                        "Starsea Admiral -  (Lv. 8)",
                        "Bunny Munchkin - (Lv. 7)",
                        "Decisive Day - AKM (Lv. 8)"
                    };

                    static const std::vector<std::string> scarLSkins = {
                        "Default",
                        "Water Blaster - SCAR-L (Lv. 7)",
                        "Enchanted Pumpkin - SCAR-L (Lv. 7)",
                        "Operation Tomorrow - SCAR-L (Lv. 7)",
                        "Hextech Crystal - SCAR-L (Lv. 7)",
                        "Thorn of Malice - SCAR-L (Lv. 8)",
                        "Bloodstained Nemesis - SCAR-L (Lv. 8)",
                        "Folly's Clasp - SCAR-L (Lv. 7)"
                    };

                    static const std::vector<std::string> m762Skins = {
                        "Default",
                        "8-bit Unicorn - M762 (Lv. 5)",
                        "Concerto of Love - M762 (Lv. 7)",
                        "Deadly Precision - M762 (Lv. 7)",
                        "Stray Rebellion - M762 (Lv. 8)",
                        "Starcore - M762 (Lv. 8)",
                        "Messi Football Icon - M762 (Lv. 7)",
                        "Noctum Sunder - M762 (Lv. 7)",
                        "Moonsaga - M762 (Lv. 7)"
                    };

                    static const std::vector<std::string> m16a4Skins = {
                        "Default",
                        "Blood & Bones - M16A4 (Lv. 7)",
                        "Aurora Pulse - M16A4 (Lv. 7)",
                        "Radiant Edge - M16A4 (Lv. 5)",
                        "Skeletal Core - M16A4 (Lv. 7)",
                        "Dracoguard - M16A4 (Lv. 5)"
                    };

                    static const std::vector<std::string> augSkins = {
                        "Default",
                        "Wandering Circus - AUG (Lv. 5)",
                        "Evangelion 4th Angel - (Lv. 5)",
                        "Forsaken Glace - AUG (Lv. 8)"
                    };

                    static const std::vector<std::string> grozaSkins = {
                        "Default",
                        "Forest Raider - Groza (Lv. 5)",
                        "Eventide Aria - Groza (Lv. 5)",
                        "Ryomen Sukuna - Groza (Lv. 7)",
                        "Splendid Battle - Groza (Lv. 5)",
                        "River Styx - Groza (Lv. 7)",
                        "Pumpkin Carol - Groza (Lv. 5)"
                    };

                    static const std::vector<std::string> dp28Skins = {
                        "Default",
                        "Enigmatic Hunter - DP-28 (Lv. 5)",
                        "Gilded Jade Dragon - DP-28 (Lv. 5)",
                        "Nautical Warrior - DP-28 (Lv. 5)",
                        "Shenron - DP-28 (Lv. 5)"
                    };

                    static const std::vector<std::string> m249Skins = {
                        "Default",
                        "Winter Queen M249 (Lv. 5)",
                        "Party Parcel - M249 (Lv. 7)",
                        "Moondrop Eterna - M249 (Lv. 7)",
                        "Stargaze Fury - M249 (Lv. 5)"
                    };

                    static const std::vector<std::string> ace32Skins = {
                        "Default",
                        "Beam Blast - ACE32 (Lv. 7)",
                        "Icicle Spike - ACE32 (Lv. 7)"
                    };

                    static const std::vector<std::string> mg3Skins = {
                        "Default",
                        "Soaring Dragon - MG3 (Lv. 5)"
                    };

                    // SMG skins
                    static const std::vector<std::string> uziSkins = {
                        "Default",
                        "Savagery - UZI (Lv. 6)",
                        "Ethereal Emblem - UZI (Lv. 5)",
                        "Romantic Moments - (Lv. 5)",
                        "Shimmer Power - UZI (Lv. 5)",
                        "Mystech - UZI (Lv. 5)",
                        "Juicer - UZI (Lv. 5)"
                    };

                    static const std::vector<std::string> ump45Skins = {
                        "Default",
                        "Dragonfire - UMP45 (Lv. 7)",
                        "Outlawed Fantasy - UMP45 (Lv. 7)",
                        "8-Bit Blast - UMP45 (Lv. 5)",
                        "Rainbow Stinger - UMP45 (Lv. 5)",
                        "Marine Evolution - UMP45 (Lv. 3)",
                        "Carnival Waves - UMP45 (Lv. 5)",
                        "Cryofrost Shard - UMP45 (Lv. 7)"
                    };

                    static const std::vector<std::string> vectorSkins = {
                        "Default",
                        "Blood Tooth - Vector (Lv. 5)",
                        "Midnight Rose - Vector (Lv. 5)",
                        "Gilded Reaper - Vector (Lv. 5)",
                        "Mecha Drake - Vector (Lv. 7)"
                    };

                    static const std::vector<std::string> thompsonSkins = {
                        "Default",
                        "Candy Cane (Lv. 5)",
                        "Steampunk (Lv. 5)"
                    };

                    // Sniper skins
                    static const std::vector<std::string> m24Skins = {
                        "Default",
                        "The Seven Seas - M24 (Lv. 5)",
                        "Pharaoh's Might - M24 (Lv. 7)",
                        "Lady Butterfly - M24 (Lv. 5)",
                        "Circle of Life - M24 (Lv. 7)",
                        "Cadence Maestro - (Lv. 7)"
                    };

                    static const std::vector<std::string> kar98kSkins = {
                        "Default",
                        "Terror Fang - Kar98K (Lv. 7)",
                        "Kukulkan Fury - Kar98K (Lv. 7)",
                        "Moonlit Grace - Kar98K (Lv. 7)",
                        "Titanium Shark - Kar98K (Lv. 7)",
                        "Nebula Hunter - Kar98K (Lv. 5)",
                        "Violet Volt - Kar98K (Lv. 7)"
                    };

                    static const std::vector<std::string> awmSkins = {
                        "Default",
                        "Mauve Avenger - AWM (Lv. 7)",
                        "Field Commander - AWM (Lv. 7)",
                        "Godzilla - AWM (Lv. 7)",
                        "Rainbow Drake - AWM (Lv. 7)",
                        "Flamewave - AWM (Lv. 7)",
                        "Serpengleam - AWM (Lv. 7)"
                    };

                    static const std::vector<std::string> amrSkins = {
                        "Default",
                        "Crimson Ephialtes - AMR (Lv. 8)",
                        "Scorching Blessing - AMR (Lv. 7)"
                    };

                    static const std::vector<std::string> mk14Skins = {
                        "Default",
                        "Gilded Galaxy - Mk14 (Lv. 5)",
                        "Drakreign - Mk14 (Lv. 8)"
                    };

                    // Vehicle skins
                    static const std::vector<std::string> daciaSkins = {
                        "Default",
                        "Koenigsegg Gemera (Rainbow)",
                        "Koenigsegg Gemera (Silver Grey)",
                        "Koenigsegg Gemera (Drawn)",
                        "Tesla (Digital Water) (DACIA)",
                        "Koenigsegg Gemera (DACIA)",
                        "Koenigsegg (Rainbow) (DACIA)",
                        "Lamborghini Metal Grey (DACIA)",
                        "Tesla Roadster (Diamond) (DACIA)",
                        "Lamborghini Estoque Metal Grey",
                        "Lamborghini Estoque Oro",
                        "GHOST Rosa DACIA SPEED Car",
                        "GHOST Violet DACIA SPEED Car",
                        "GHOST Gleam DACIA SPEED Car",
                        "Bentley Flying Spur Mulliner (Nebula)",
                        "Bentley Flying Spur Mulliner (Silver Storm)",
                        "Pumpkin Dacia (Lv. 3)",
                        "Castle Dacia (Lv. 3)",
                        "Speedy Reindeer Dacia (Lv. 3)",
                        "Zombie Mess Dacia (Lv. 4)",
                        "Dodge Charger SRT Fuchsia",
                        "Dodge Charger-Tuscan Torque",
                        "Dodge Charger SRT Violet Venom",
                        "Midknight Dacia (Lv. 4)"
                    };

                    static const std::vector<std::string> coupeRPSkins = {
                        "Default",
                        "Lamborghini Aventador SVJ",
                        "Lamborghini Centenario Galassia",
                        "Lamborghini Aventador SVJ Blue",
                        "Lamborghini Centenario Carbon Fiber",
                        "Koenigsegg One:1 Gilt",
                        "Koenigsegg One:1 Cyber Nebula",
                        "Koenigsegg One:1 Jade",
                        "Koenigsegg One:1 Phoenix",
                        "PUBG Supper Warp Green",
                        "PUBG Supper Warp Dawn",
                        "PUBG Supper Warp Universe",
                        "Pagani Zonda R (Tricolore Carbon)",
                        "Pagani Zonda R (Bianco Benny)",
                        "Pagani Zonda R (Melodic Midnight)",
                        "Pagani Imola (Grigio Montecarlo)",
                        "Pagani Imola (Crystal Clear Carbon)",
                        "Pagani Imola (Nebula Dream)",
                        "Pagani Imola (Arctic Aegis)",
                        "Dodge Challenger SRT Hellcat",
                        "Bentley Batur (Holoprism)",
                        "Bentley Batur (Solar Pulse)",
                        "Bonneville Pearlescent Silver",
                        "SSC Tuatara Rose Phantom",
                        "SSC Tuatara Sky Crane",
                        "SSC Tuatara Striker Dawn's Edge",
                        "SSC Tuatara Striker Blue Nightscape",
                        "Dodge Hellcat Jailbreak - Hellfire",
                        "Bugatti Veyron 16.4 (Gold)",
                        "Bugatti Veyron 16.4",
                        "Bugatti La Voiture Noire",
                        "Bugatti La Voiture Noire (Alloy)",
                        "Bugatti La Voiture Noire (Warrior)",
                        "Bugatti La Voiture Noire (Nebula)",
                        "McLaren P1 (Starry Sky)",
                        "McLaren P1 (Fantasy Pink)",
                        "McLaren P1 (Volcano Yellow)"
                    };

                    static const std::vector<std::string> uazSkins = {
                        "Default",
                        "Robust Universe",
                        "Maserati Levante Neon Urbano",
                        "Maserati Levante Firmamento",
                        "Maserati Luce Arancione",
                        "Maserati Levante Blu Emozione",
                        "Lamborghini Urus Gialla Inti",
                        "Aston Martin DBX707 (Quasar Blue)",
                        "Bentley Bentayga Azure (Galaxy Glitter)",
                        "Bentley Bentayga Azure (Magnetic)",
                        "Dodge Hornet GLH Concept - Redline",
                        "Dodge Hornet - Sunburst",
                        "Lamborghini Urus Pink",
                        "Robust Night City"
                    };

                    static const std::vector<std::string> motoSkins = {
                        "Default",
                        "DUCATI Panigale V4S",
                        "Ducati Panigale V4S Phantom",
                        "Ducati Panigale V4S Storm",
                        "Ducati Panigale V4S Mirage",
                        "Phantom Motorcycle (Lv. 7)",
                        "LINE FRIENDS Lovey Dovey",
                        "Roaring Tiger Motorcycle",
                        "Skeleton Chariot Motorcycle"
                    };

                    if (AllSkinEnable == 0) {
                        ImGui::BulletColorText(ImColor(97, 167, 217, 255).Value, OBFUSCATE("Gun:"));
                        RenderSkinSelector(m416Skins, m4SkinHackHudSdk, "M416");
                        RenderSkinSelector(akmSkins, akmSkinHackHudSdk, "AKM");
                        RenderSkinSelector(scarLSkins, scarSkinHackHudSdk, "SCAR-L");
                        RenderSkinSelector(m762Skins, m762SkinHackHudSdk, "M762");
                        RenderSkinSelector(m16a4Skins, m16a4SkinHackHudSdk, "M16A4");
                        RenderSkinSelector(augSkins, augSkinHackHudSdk, "AUG");
                        RenderSkinSelector(grozaSkins, grozaSkinHackHudSdk, "Groza");
                        RenderSkinSelector(dp28Skins, dp28SkinHackHudSdk, "DP-28");
                        RenderSkinSelector(m249Skins, m249SkinHackHudSdk, "M249");
                        RenderSkinSelector(ace32Skins, ace32SkinHackHudSdk, "ACE32");
                        RenderSkinSelector(mg3Skins, MG3SkinHackHudSdk, "MG3");
                    }

                    if (AllSkinEnable == 1) {
                        ImGui::BulletColorText(ImColor(97, 167, 217, 255).Value, OBFUSCATE("Gun:"));
                        RenderSkinSelector(uziSkins, uziSkinHackHudSdk, "UZI");
                        RenderSkinSelector(ump45Skins, ump45SkinHackHudSdk, "UMP45");
                        RenderSkinSelector(vectorSkins, vectorSkinHackHudSdk, "Vector");
                        RenderSkinSelector(thompsonSkins, thompsonSkinHackHudSdk, "Thompson");
                    }

                    if (AllSkinEnable == 2) {
                        ImGui::BulletColorText(ImColor(97, 167, 217, 255).Value, OBFUSCATE("Gun:"));
                        RenderSkinSelector(m24Skins, m24SkinHackHudSdk, "M24");
                        RenderSkinSelector(kar98kSkins, kerSkinHackHudSdk, "Kar98K");
                        RenderSkinSelector(awmSkins, awmSkinHackHudSdk, "AWM");
                        RenderSkinSelector(amrSkins, amrSkinHackHudSdk, "AMR");
                        RenderSkinSelector(mk14Skins, mk14SkinHackHudSdk, "Mk14");
                    }

                    if (AllSkinEnable == 3) {
                        ImGui::BulletColorText(ImColor(97, 167, 217, 255).Value, OBFUSCATE("CarMod"));
                        RenderSkinSelector(daciaSkins, DaciaSkinHackSdk, "Dacia");
                        RenderSkinSelector(coupeRPSkins, CoupeRPSkinHackSdk, "CoupeRP");
                        RenderSkinSelector(uazSkins, UAZSkinHackSdk, "UAZ");
                        RenderSkinSelector(motoSkins, MotoSkinHackSdk, "Moto");
                    }
                }

                break;

            case Tab::CheckBox:
                ImGui::PushFont(Chinese);
                ImGui::BulletText(u8"Aim");
                ImGui::PopFont();
                //   ImGui::SameLine();
                // Helpmarker(u8"复选框示例", Color[ImGuiCol_Button]);
                ImGui::Separator();


            //    if (GL_AIM_BLOCK) {

                    //Tab1::AimMod1
                    ImGui::Checkbox(languageText(u8"AimEnable",u8"瞄准启用","",""), &Config.AimEnable);
                    ImGui::SameLine();
                    ImGui::Checkbox(languageText(u8"Hide-Fov",u8"隐藏-Fov","",""), &Config.HideFov);
                    ImGui::SameLine();
                    ImGui::Checkbox(languageText(u8"IgnoreBot(Aim)",u8"忽略机器人","",""), &Config.Hidebot);

                    ImGui::Checkbox(languageText(u8"AimKnocked",u8"瞄准击倒","",""), &Config.IgnoreKnocked);
                    ImGui::SameLine();
                    ImGui::Checkbox(languageText(u8"VisCheck",u8"掩体预判","",""), &Config.VisCheck);

                    if (ImGui::Button(languageText(u8"Save Settings", u8"保存设置", "",""), { 210.0f,50.0f }))
                    {
                        saveCFG();
                    }
                    ImGui::SameLine();
                    if (ImGui::Button(languageText(u8"Load Settings", u8"加载设置", "",""), { 210.0f,50.0f }))
                    {
                        loadCFG();
                    }
                    ImGui::SameLine();
                    if (ImGui::Button(languageText(u8"Delete Settings", u8"删除设置", "", ""),{ 210.0f,50.0f }))
                    {
                        removeCFG();
                    }

                    //    ImGui::Checkbox(languageText(u8"IgnoreBot(Aim)",u8"忽略机器人","",""), &Config.Hidebot);
                    ImGui::Separator();

                    ImGui::PushStyleColor(ImGuiCol_Button, Tab2 == Tab2::AimMod1 ? Color[ImGuiCol_Button] : ImVec4(0.18f, 0.18f, 0.18f, 1.00f));
                    if (ImGui::Button(languageText(u8"AimBot", u8"自瞄", "",""), { 185.0f,50.0f }))
                    {
                        Tab2 = Tab2::AimMod1;
                        //      Config.NRGtrigger == 0;
                    }
                    ImGui::PopStyleColor();

                    ImGui::PushStyleColor(ImGuiCol_Button, Tab2 == Tab2::AimMod2 ? Color[ImGuiCol_Button] : ImVec4(0.18f, 0.18f, 0.18f, 1.00f));
                    ImGui::SameLine();
                    if (ImGui::Button(languageText(u8"BulletTrack", u8"子弹轨迹", "",""), { 185.0f,50.0f }))
                    {
                        Tab2 = Tab2::AimMod2;
                        //    Config.NRGtrigger == 1;
                    }
                    ImGui::PopStyleColor();


                    //  ImGui::SameLine();
                    //  ImGui::Spacing();
                    if (Tab2 == Tab2::AimMod1) {
                        ImGui::SliderFloat(languageText(u8"Recoil Size", u8"自瞄控制后坐力大小", "",""),&Config.RecoilSize, 0.3f, 2.0f, "%.1f%");
                    }
                    ImGui::SliderFloat(languageText(u8"Aim-Fov", u8"瞄准范围","",""),&Config.AimFov, 0, 200, "%.0f");
                    ImGui::SliderFloat(languageText(u8"Distance", u8"距离","",""),&Config.AimDistance, 10, 150, "%.0f");

                    //  ImGui::Spacing();



                    ImGui::PushStyleColor(ImGuiCol_Button, Tab1 == Tab1::Aim1 ? Color[ImGuiCol_Button] : ImVec4(0.18f, 0.18f, 0.18f, 1.00f));
                    if (ImGui::Button(languageText(u8"Shoot", u8"射击", "",""), { 185.0f,50.0f }))
                    {
                        Tab1 = Tab1::Aim1;
                        //      Config.NRGtrigger == 0;
                    }
                    ImGui::PopStyleColor();

                    ImGui::PushStyleColor(ImGuiCol_Button, Tab1 == Tab1::Aim2 ? Color[ImGuiCol_Button] : ImVec4(0.18f, 0.18f, 0.18f, 1.00f));
                    ImGui::SameLine();
                    if (ImGui::Button(languageText(u8"Scope", u8"开镜", "",""), { 185.0f,50.0f }))
                    {
                        Tab1 = Tab1::Aim2;
                        //    Config.NRGtrigger == 1;
                    }
                    ImGui::PopStyleColor();

                    ImGui::PushStyleColor(ImGuiCol_Button, Tab1 == Tab1::Aim3 ? Color[ImGuiCol_Button] : ImVec4(0.18f, 0.18f, 0.18f, 1.00f));
                    ImGui::SameLine();
                    if (ImGui::Button(languageText(u8"Both", u8"两个都", "", ""),{ 185.0f,50.0f }))
                    {
                        Tab1 = Tab1::Aim3;
                        //   Config.NRGtrigger == 2;
                    }
                    ImGui::PopStyleColor();

                break;
        }
        ImGui::EndChild();


        ImGui::End();

        //  }
    }

}

void EndDraw()
{
    ImGuiWindow* window =  ImGui::GetCurrentWindow();
    window->DrawList->PushClipRectFullScreen();
    ImGui::End();
}
// Android data
static double g_Time = 0.0;
static EGLDisplay eglDisplay;
static EGLSurface eglSurface;
extern "C" JNIEXPORT void JNICALL
Java_com_bearmod_GLES3JNIView_step(JNIEnv* env, jclass obj) {
    //if (!bScanPatternCompleted)
    //  return;

    timer RenderingFPS;
    RenderingFPS.SetFps(Config.RunFPS);
    RenderingFPS.AotuFPS_init();
    RenderingFPS.setAffinity();


    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame();

    ImGui_ImplAndroid_NewFrame(glWidth, glHeight);


    ImGui::NewFrame();
    glViewport(0, 0, (int) ImGui::GetIO().DisplaySize.x, (int) ImGui::GetIO().DisplaySize.y);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);              // background color

    UpdateFPS();

    MenuDraw(ShowMainMenu);
    for (int i = 0; i < IM_ARRAYSIZE(ImGui::GetIO().KeysDown); i++)
        if (ImGui::IsKeyDown(i)) {
            ShowMainMenu = true;

        }

    DrawESP(ImGui::GetBackgroundDrawList());


    ImGui::End();
    ImGui::Render();
    glClear(GL_COLOR_BUFFER_BIT);
//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}


extern "C" JNIEXPORT void JNICALL Java_com_bearmod_GLES3JNIView_imgui_Shutdown(JNIEnv* env, jobject obj){

    if (!g_Initialized)
    {
        return;
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplAndroid_Shutdown();

    ImGui::DestroyContext();

    g_Initialized=false;
}

extern "C" JNIEXPORT void JNICALL Java_com_bearmod_GLES3JNIView_MotionEventClick(JNIEnv* env,
                                                                                 jclass obj,jboolean down,jfloat PosX,jfloat PosY){
    ImGuiIO & io = ImGui::GetIO();
    io.MouseDown[0] = down;
    io.MousePos = ImVec2(PosX,PosY);

}


extern "C" JNIEXPORT jstring JNICALL Java_com_bearmod_GLES3JNIView_getWindowRect(JNIEnv *env,
                                                                                 jclass thiz) {
    // TODO: 实现 getWindowSizePos()
    char result[256]="0|0|0|0";
    if(g_window){
        sprintf(result,"%d|%d|%d|%d",(int)g_window->Pos.x,(int)g_window->Pos.y,(int)g_window->Size.x,(int)g_window->Size.y);
    }
    return env->NewStringUTF(result);
}



#include <thread>
#include <chrono>
#include <atomic>

// Frame timing
const int TARGET_FPS = 90;
const int FRAME_DURATION = 1000 / TARGET_FPS;

std::atomic<bool> running(true);
void renderLoop() {
    while (running) {
        auto frameStart = std::chrono::steady_clock::now();

        // Call the nativeRender function (ImGui rendering)
        //     nativeRender();

        // Calculate the frame time
        auto frameEnd = std::chrono::steady_clock::now();
        std::chrono::duration<float, std::milli> elapsed = frameEnd - frameStart;

        // Sleep for the remaining frame time
        int sleepDuration = FRAME_DURATION - elapsed.count();
        if (sleepDuration > 0) {
            std::this_thread::sleep_for(std::chrono::milliseconds(sleepDuration));
        }
    }
}

extern "C" JNIEXPORT void JNICALL
Java_com_bearmod_GLES3JNIView_startRendering(JNIEnv* env, jobject obj) {
    running = true;
    std::thread(renderLoop).detach();
}

extern "C" JNIEXPORT void JNICALL
Java_com_bearmod_GLES3JNIView_stopRendering(JNIEnv* env, jobject obj) {
    running = false;
}
