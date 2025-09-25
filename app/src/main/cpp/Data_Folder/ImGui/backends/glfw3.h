// GLFW 3.3.8
// This file is part of the GLFW library and is licensed under the zlib/libpng license.

#ifndef GLFW_INCLUDE_NONE
#define GLFW_INCLUDE_NONE
#endif

#include <stddef.h> // For size_t, NULL
#include <stdint.h> // For int32_t, uint32_t
#include <stdbool.h> // For bool, true, false

// Platform-specific defines
#if defined(_WIN32)
    #define GLFW_EXPOSE_NATIVE_WIN32
    #define GLFW_EXPOSE_NATIVE_WGL
    #define GLFW_EXPOSE_NATIVE_CD
#elif defined(__APPLE__)
    #include <TargetConditionals.h>
    #if TARGET_OS_MAC
        #define GLFW_EXPOSE_NATIVE_COCOA
        #define GLFW_EXPOSE_NATIVE_NSGL
    #endif
#elif defined(__linux__)
    #define GLFW_EXPOSE_NATIVE_X11
    #define GLFW_EXPOSE_NATIVE_GLX
#endif

// Define GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, and GLFW_VERSION_REVISION
#define GLFW_VERSION_MAJOR 3
#define GLFW_VERSION_MINOR 3
#define GLFW_VERSION_REVISION 8

// GLFW window handle
typedef struct GLFWwindow GLFWwindow;

// Define GLFW types
typedef void (*GLFWerrorfun)(int, const char*);
typedef void (*GLFWwindowposfun)(GLFWwindow*, int, int);
typedef void (*GLFWwindowsizefun)(GLFWwindow*, int, int);
typedef void (*GLFWwindowclosefun)(GLFWwindow*);
typedef void (*GLFWwindowrefreshfun)(GLFWwindow*);
typedef void (*GLFWwindowfocusfun)(GLFWwindow*, int);
typedef void (*GLFWwindowiconifyfun)(GLFWwindow*, int);
typedef void (*GLFWframebuffersizefun)(GLFWwindow*, int, int);
typedef void (*GLFWmousebuttonfun)(GLFWwindow*, int, int, int);
typedef void (*GLFWcursorposfun)(GLFWwindow*, double, double);
typedef void (*GLFWcursorenterfun)(GLFWwindow*, int);
typedef void (*GLFWscrollfun)(GLFWwindow*, double, double);
typedef void (*GLFWkeyfun)(GLFWwindow*, int, int, int, int);
typedef void (*GLFWcharfun)(GLFWwindow*, unsigned int);

// Function declarations
GLFWAPI int glfwInit(void);
GLFWAPI void glfwTerminate(void);
GLFWAPI GLFWwindow* glfwCreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
GLFWAPI void glfwDestroyWindow(GLFWwindow* window);
GLFWAPI void glfwSetWindowShouldClose(GLFWwindow* window, int value);
GLFWAPI int glfwWindowShouldClose(GLFWwindow* window);
GLFWAPI void glfwPollEvents(void);
GLFWAPI void glfwWaitEvents(void);
GLFWAPI void glfwSwapBuffers(GLFWwindow* window);
GLFWAPI void glfwSetErrorCallback(GLFWerrorfun cbfun);
GLFWAPI GLFWmonitor* glfwGetPrimaryMonitor(void);
GLFWAPI const GLFWvidmode* glfwGetVideoMode(GLFWmonitor* monitor);
GLFWAPI GLFWmonitor* glfwGetMonitorUserPointer(GLFWmonitor* monitor);
GLFWAPI const char* glfwGetVersionString(void);

// Add other function declarations as needed...

#endif // _GLFW3_H_
