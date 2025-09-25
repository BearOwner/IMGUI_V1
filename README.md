# IMGUI_V1

A customizable overlay and mod interface built with C++ and Dear ImGui, designed for enhancing graphical user interfaces in applications or games. This project provides a flexible framework for rendering ESP (Extra Sensory Perception) elements, menu systems, skin customization, and performance optimizations, with a focus on modding and overlay functionalities.

## Project Description

IMGUI_V1 is a C++ application that leverages Dear ImGui to create interactive overlays and mods. Originally developed as a mod interface (e.g., for games like PUBG Mobile), it includes components for rendering ESP, handling user inputs via menus, and customizing skins. The project emphasizes performance and stability, with recent commits addressing overheating and crash issues through code analysis of core files (SKIN.h, main.cpp, MENU.h, ESP.h).

Key highlights:
- **Modular Design**: Separates rendering (ESP.h), UI (MENU.h), skins (SKIN.h), and initialization (main.cpp).
- **Performance Focus**: Optimized for mobile and desktop environments to reduce overheating and crashes.
- **Version Control**: Backed up to GitHub for collaborative development.

Recent Git History:
- **Initial Commit**: "Backup before fixing overheating and crashes - analyzed SKIN.h, main.cpp, MENU.h, ESP.h" – Committed after analyzing core files for performance bottlenecks and stability issues.
- **Git Setup**: Initialized repository with `git init`, added remote origin (`https://github.com/BearOwner/IMGUI_V1.git`), configured user (BearOwner, bearowner@example.com), staged all files with `git add .`, committed, and pushed to master branch using `git push -u origin master`.
- **Todo Completion**: Marked "Backup project to GitHub" as completed (ID: 7a976c12b1777421da721b7c0afbe45f).

## Features

- **ESP Rendering**: Real-time overlay for game elements (e.g., player positions, health bars, distances) in ESP.h.
- **Menu System**: Interactive UI for configuration and controls via MENU.h, using ImGui widgets.
- **Skin Customization**: Dynamic skin changes and avatar modifications in SKIN.h.
- **Performance Optimizations**: Distance-based culling, frame limiting, and null checks to prevent overheating.
- **Cross-Platform Support**: Android and desktop compatibility with JNI and OpenGL.
- **Hooks and Mods**: Integration with game engines for anti-cheat bypass and enhancements (use responsibly).
- **Extensibility**: Modular code for adding new features like aimbot or radar.

## Installation

### Prerequisites
- **C++ Compiler**: GCC/Clang (for Linux/Android) or MSVC (for Windows).
- **Dependencies**:
  - Dear ImGui (included in Data_Folder/ImGui).
  - OpenGL (for rendering).
  - JNI (for Android integration).
  - CMake or Android NDK for building.
- **Tools**: Git, Android Studio (for APK builds), or Visual Studio.

### Build Steps
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/BearOwner/IMGUI_V1.git
   cd IMGUI_V1
   ```

2. **Install Dependencies**:
   - Ensure OpenGL and JNI are available.
   - For Android: Set up Android NDK and SDK.

3. **Build with CMake** (Desktop Example):
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```

4. **Android Build**:
   - Use Android Studio to open the project.
   - Build APK via Gradle: `./gradlew assembleDebug`.

5. **Run**:
   - Desktop: Execute the binary.
   - Android: Install APK and launch.

## Usage

### Running the Application
- Launch the app; it initializes ImGui and hooks into the target application/game.
- Use the menu (MENU.h) to toggle features like ESP, skins, and performance settings.

### Configuration
- Edit config variables in main.cpp (e.g., `Config.EspEnable` for ESP toggling).
- Customize skins in SKIN.h by modifying `updateSkin()`.

### Extending the Project
- Add new ESP elements in ESP.h:
  ```cpp
  void DrawESP(ImDrawList *draw) {
      // Custom rendering logic
      draw->AddCircle(ImVec2(100, 100), 50, IM_COL32(255, 0, 0, 255));
  }
  ```
- Integrate new menus in MENU.h using ImGui functions.

### Troubleshooting
Use the decision tree below for common issues:

```
Overheating/Crashes?
├── Check SKIN.h rendering efficiency (e.g., reduce loops in updateSkin())
├── Optimize main.cpp loops (e.g., add distance culling in RenderESP)
├── Verify MENU.h event handling (e.g., null checks in JNI calls)
├── Profile ESP.h calculations (e.g., cache bone positions)
└── Log errors and report via GitHub Issues
```

## Contributing

We welcome contributions! Follow these guidelines:

1. **Fork and Clone**: Fork the repo and create a feature branch.
2. **Code Standards**: Use C++11+, add comments, and follow modular design. Run static analysis.
3. **Pull Requests**: Provide clear descriptions, reference issues, and ensure tests pass.
4. **Issue Reporting**: Use templates below. Include logs, screenshots, and affected files.

### Issue Templates

#### Bug Report
- **Title**: [Bug] Brief description
- **Description**: Detailed steps to reproduce.
- **Affected Files**: e.g., ESP.h, main.cpp
- **Logs**: Crash logs or overheating metrics.
- **Environment**: OS, compiler, device.

#### Feature Request
- **Title**: [Feature] New functionality
- **Description**: Why it's needed, proposed implementation.
- **Priority**: Low/Medium/High.

### Architectural Diagram
Simple Flowchart of Main Loop:

```
main.cpp (Init)
    ├── Load ImGui (MENU.h)
    ├── Hook Game (ESP.h)
    └── Render Loop
        ├── Update Skins (SKIN.h)
        ├── Draw ESP (ESP.h)
        └── Handle Input (MENU.h)
```

## License

This project is licensed under the MIT License. See LICENSE for details.

Attribution: Developed by BearOwner (bearowner@example.com). Contributions welcome!