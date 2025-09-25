cmake_minimum_required(VERSION 3.22.1)
project(IMGUI_T2)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
set(SOURCES
    app/src/main/cpp/main.cpp
    app/src/main/cpp/Data_Folder/patch/KittyMemory.cpp
    app/src/main/cpp/Data_Folder/patch/MemoryPatch.cpp
    app/src/main/cpp/Data_Folder/patch/MemoryBackup.cpp
    app/src/main/cpp/Data_Folder/patch/KittyUtils.cpp
    app/src/main/cpp/Data_Folder/Substrate/hde64.c
    app/src/main/cpp/Data_Folder/Substrate/SubstrateDebug.cpp
    app/src/main/cpp/Data_Folder/Substrate/SubstrateHook.cpp
    app/src/main/cpp/Data_Folder/Substrate/SubstratePosixMemory.cpp
    app/src/main/cpp/Data_Folder/Substrate/And64InlineHook.cpp
    app/src/main/cpp/Data_Folder/base64/base64.cpp
    app/src/main/cpp/Data_Folder/Time/Time.cpp
    app/src/main/cpp/Data_Folder/ImGui/imgui.cpp
    app/src/main/cpp/Data_Folder/ImGui/imgui_draw.cpp
    app/src/main/cpp/Data_Folder/ImGui/imgui_demo.cpp
    app/src/main/cpp/Data_Folder/ImGui/imgui_tables.cpp
    app/src/main/cpp/Data_Folder/ImGui/imgui_widgets.cpp
    app/src/main/cpp/Data_Folder/ImGui/imgui_impl_android.cpp
    app/src/main/cpp/Data_Folder/ImGui/imgui_impl_opengl3.cpp
    app/src/main/cpp/Data_Folder/ImGui/stb_image.cpp
    app/src/main/cpp/nrg_hook/xhook.c
    app/src/main/cpp/nrg_hook/xh_core.c
    app/src/main/cpp/nrg_hook/xh_elf.c
    app/src/main/cpp/nrg_hook/xh_jni.c
    app/src/main/cpp/nrg_hook/xh_log.c
    app/src/main/cpp/nrg_hook/xh_util.c
)

# Create executable for CodeQL analysis
add_executable(${PROJECT_NAME} ${SOURCES})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    app/src/main/cpp
    app/src/main/cpp/Data_Folder/curl/curl-android-x86_64/include
    app/src/main/cpp/Data_Folder/curl/openssl-android-x86_64/include
    app/src/main/cpp/Data_Folder/ImGui
    app/src/main/cpp/Data_Folder/Includes
    app/src/main/cpp/Data_Folder/patch
    app/src/main/cpp/Data_Folder/Substrate
    app/src/main/cpp/Data_Folder/Time
    app/src/main/cpp/nrg_hook
    app/src/main/cpp/SDK
)

# Compiler flags for security and analysis
target_compile_options(${PROJECT_NAME} PRIVATE
    -Wall
    -Wextra
    -Werror=format-security
    -fvisibility=hidden
    -ffunction-sections
    -fdata-sections
    -fno-rtti
    -fno-exceptions
    -fpermissive
    -std=c++17
)

# Linker flags
set_target_properties(${PROJECT_NAME} PROPERTIES
    LINK_FLAGS "-Wl,--gc-sections,--strip-all"
)

# For Android builds (if needed)
if(ANDROID)
    set(CMAKE_TOOLCHAIN_FILE $ENV{ANDROID_NDK}/build/cmake/android.toolchain.cmake)
    set(CMAKE_ANDROID_NDK $ENV{ANDROID_NDK})
endif()