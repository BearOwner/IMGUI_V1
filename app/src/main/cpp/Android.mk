LOCAL_PATH := $(call my-dir)
MAIN_LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := libcurl
LOCAL_SRC_FILES := Data_Folder/curl/curl-android-$(TARGET_ARCH_ABI)/lib/libcurl.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libdobby
LOCAL_SRC_FILES := Data_Folder/Helper/Dobby/libraries/$(TARGET_ARCH_ABI)/libdobby.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/Dobby/libraries/
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libssl
LOCAL_SRC_FILES := Data_Folder/curl/openssl-android-$(TARGET_ARCH_ABI)/lib/libssl.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libcrypto
LOCAL_SRC_FILES := Data_Folder/curl/openssl-android-$(TARGET_ARCH_ABI)/lib/libcrypto.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := bearmod

LOCAL_CFLAGS := -Wno-error=format-security -fvisibility=hidden -ffunction-sections -fdata-sections -w
LOCAL_CFLAGS += -fno-rtti -fno-exceptions -fpermissive
LOCAL_CPPFLAGS := -Wno-error=format-security -fvisibility=hidden -ffunction-sections -fdata-sections -w -Werror -s -std=c++17
LOCAL_CPPFLAGS += -Wno-error=c++11-narrowing -fms-extensions -fno-rtti -fno-exceptions -fpermissive
LOCAL_LDFLAGS += -Wl,--gc-sections,--strip-all, -llog
LOCAL_ARM_MODE := arm

LOCAL_C_INCLUDES += $(MAIN_LOCAL_PATH)

LOCAL_SRC_FILES 		:=  main.cpp \
 	Data_Folder/patch/KittyMemory.cpp \
 	Data_Folder/patch/MemoryPatch.cpp \
     Data_Folder/patch/MemoryBackup.cpp \
     Data_Folder/patch/KittyUtils.cpp \
     Data_Folder/Substrate/hde64.c \
     Data_Folder/Substrate/SubstrateDebug.cpp \
     Data_Folder/Substrate/SubstrateHook.cpp \
     Data_Folder/Substrate/SubstratePosixMemory.cpp \
     Data_Folder/Substrate/And64InlineHook.cpp \
     Data_Folder/base64/base64.cpp\
 	Data_Folder/Time/Time.cpp \
         Data_Folder/Helper/Tools.cpp \
         Data_Folder/Helper/ElfImg.cpp \
        Data_Folder/Helper/fake_dlfcn.cpp \
        Data_Folder/Helper/plthook_elf.cpp  \
        Data_Folder/Helper/ImguiPP.cpp  \
        Data_Folder/Helper/android_native_app_glue.c \
        Data_Folder/ImGui/imgui.cpp    \
        Data_Folder/ImGui/imgui_draw.cpp\
        Data_Folder/ImGui/imgui_demo.cpp \
        Data_Folder/ImGui/imgui_tables.cpp \
        Data_Folder/ImGui/imgui_widgets.cpp \
        Data_Folder/ImGui/imgui_impl_android.cpp \
        Data_Folder/ImGui/imgui_impl_opengl3.cpp \
        Data_Folder/ImGui/stb_image.cpp \
        nrg_hook/xhook.c \
        nrg_hook/xh_core.c \
        nrg_hook/xh_elf.c \
        nrg_hook/xh_jni.c \
        nrg_hook/xh_log.c \
        nrg_hook/xh_util.c \
        nrg_hook/xh_version.c \
        SDK/NRG_Basic.cpp \
        SDK/NRG_Basic_functions.cpp \
        SDK/NRG_CoreUObject_functions.cpp \
        SDK/NRG_Engine_functions.cpp \
        SDK/NRG_ShadowTrackerExtra_functions.cpp \
        SDK/NRG_Client_functions.cpp
        
LOCAL_C_INCLUDES := $(LOCAL_PATH)/Data_Folder/curl/curl-android-$(TARGET_ARCH_ABI)/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/Data_Folder/curl/openssl-android-$(TARGET_ARCH_ABI)/include

LOCAL_CPP_FEATURES                      := exceptions
LOCAL_LDLIBS                            := -llog -landroid -lEGL -lGLESv2 -lGLESv3 -lGLESv1_CM -lz
LOCAL_STATIC_LIBRARIES					:= libcurl libssl libcrypto libdobby
include $(BUILD_SHARED_LIBRARY)

# include $(LOCAL_PATH)/BYPASS/Bypass.mk
# include $(CLEAR_VARS)
