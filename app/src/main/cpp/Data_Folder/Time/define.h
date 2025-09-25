#pragma once
#include <cstdarg> // va_list
#include <stdio.h>

#define S_PRA_VERSION "1.16"

#ifndef S_PRA_API
    #define S_PRA_API
#endif

#ifndef S_PRA_STATIC
    #define S_PRA_STATIC static
#endif

#ifndef S_PRA_EXTERN
    #define S_PRA_EXTERN extern
#endif

#ifndef S_PRA_INLINE
    #define S_PRA_INLINE inline
#endif

#ifndef S_PRA_FORCEINLINE
    #define S_PRA_FORCEINLINE __forceinline
#endif

#ifndef S_PRA_NOINLINE
    #define S_PRA_NOINLINE __declspec(noinline)
#endif

#ifndef S_PRA_ASSERT
    #include <cassert>
    #define S_PRA_ASSERT(e) assert(e)
#endif

#ifndef S_PRA_VERTEX_ALIGNMENT
    #define S_PRA_VERTEX_ALIGNMENT 4
#endif

#define BEGIN namespace SPra {
#define END } // namespace SPra

#define CEK_STR(xxx) (!xxx.empty() || xxx.size() != 0)
#define CEK_CHAR(xxx) (xxx != "" || strlen(xxx) != 0)
#define CEK_NUMBER(xxx) (xxx != 0 || xxx != NULL || xxx != -1)
#define CEK_POINTER(xxx) (xxx != 0 || xxx != NULL || xxx != nullptr)
#define CEK_CLASS(xxx) (xxx != 0 || xxx != NULL || xxx != nullptr || xxx)

#define CEK_AND_STR(xxx) (!xxx.empty() && xxx.size() != 0)
#define CEK_AND_CHAR(xxx) (xxx != "" && strlen(xxx) != 0)
#define CEK_AND_NUMBER(xxx) (xxx != 0 && xxx != NULL && xxx != -1)
#define CEK_AND_POINTER(xxx) (xxx != 0 && xxx != NULL && xxx != nullptr)
#define CEK_AND_CLASS(xxx) (xxx != 0 && xxx != NULL && xxx != nullptr && xxx)

//S_PRA_INLINE bool g_display = true;
#define GL_DISPLAY if (g_display == false) return;

#if defined(__LP64__)
#define ALIG 0x8
#else
#define ALIG 0x4
#endif

typedef int8_t BYTE;
typedef double DOUBLE;
typedef uint32_t DWORD;
typedef uint64_t QWORD;
typedef int16_t WORD;
typedef uintptr_t PTR;
typedef uintptr_t PTR;
typedef char UTF8;
typedef unsigned short UTF16;
typedef unsigned int UTF32;
typedef float FLOAT;
typedef long int ADDRESS;
