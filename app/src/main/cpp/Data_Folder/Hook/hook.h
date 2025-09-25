#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <jni.h>
#include <thread>
#include <future>
#include <unordered_map>

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dlfcn.h>

#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include <android/log.h>

#include "elfImg.h"
#include "utils.h"

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, "HookApplication", __VA_ARGS__)

#define apk_asset_path "SignatureKiller/origin.apk" // assets/original.apk
#define apk_fake_name "SignatureKiller/origin.apk" // /data/data/<package_name>/cache/original.apk.

//std::vector<std::vector<uint8_t>> apk_signatures{{0x30,0x82,0x03,0x7D,0x30,0x82,0x02,0x65,0xA0,0x03,0x02,0x01,0x02,0x02,0x04,0x1D,0xCE,0x86,0xA4,0x30,0x0D,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x0B,0x05,0x00,0x30,0x6E,0x31,0x0B,0x30,0x09,0x06,0x03,0x55,0x04,0x06,0x13,0x02,0x38,0x36,0x31,0x13,0x30,0x11,0x06,0x03,0x55,0x04,0x08,0x13,0x0A,0x47,0x75,0x61,0x6E,0x67,0x20,0x44,0x6F,0x6E,0x67,0x31,0x12,0x30,0x10,0x06,0x03,0x55,0x04,0x07,0x13,0x09,0x53,0x68,0x65,0x6E,0x20,0x5A,0x68,0x65,0x6E,0x31,0x10,0x30,0x0E,0x06,0x03,0x55,0x04,0x0A,0x13,0x07,0x54,0x65,0x6E,0x63,0x65,0x6E,0x74,0x31,0x10,0x30,0x0E,0x06,0x03,0x55,0x04,0x0B,0x13,0x07,0x54,0x65,0x6E,0x63,0x65,0x6E,0x74,0x31,0x12,0x30,0x10,0x06,0x03,0x55,0x04,0x03,0x13,0x09,0x48,0x65,0x63,0x74,0x6F,0x72,0x20,0x4C,0x75,0x30,0x20,0x17,0x0D,0x31,0x37,0x31,0x32,0x32,0x38,0x31,0x31,0x33,0x37,0x30,0x37,0x5A,0x18,0x0F,0x32,0x31,0x31,0x37,0x31,0x32,0x30,0x34,0x31,0x31,0x33,0x37,0x30,0x37,0x5A,0x30,0x6E,0x31,0x0B,0x30,0x09,0x06,0x03,0x55,0x04,0x06,0x13,0x02,0x38,0x36,0x31,0x13,0x30,0x11,0x06,0x03,0x55,0x04,0x08,0x13,0x0A,0x47,0x75,0x61,0x6E,0x67,0x20,0x44,0x6F,0x6E,0x67,0x31,0x12,0x30,0x10,0x06,0x03,0x55,0x04,0x07,0x13,0x09,0x53,0x68,0x65,0x6E,0x20,0x5A,0x68,0x65,0x6E,0x31,0x10,0x30,0x0E,0x06,0x03,0x55,0x04,0x0A,0x13,0x07,0x54,0x65,0x6E,0x63,0x65,0x6E,0x74,0x31,0x10,0x30,0x0E,0x06,0x03,0x55,0x04,0x0B,0x13,0x07,0x54,0x65,0x6E,0x63,0x65,0x6E,0x74,0x31,0x12,0x30,0x10,0x06,0x03,0x55,0x04,0x03,0x13,0x09,0x48,0x65,0x63,0x74,0x6F,0x72,0x20,0x4C,0x75,0x30,0x82,0x01,0x22,0x30,0x0D,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x01,0x05,0x00,0x03,0x82,0x01,0x0F,0x00,0x30,0x82,0x01,0x0A,0x02,0x82,0x01,0x01,0x00,0xA0,0xB5,0x24,0x12,0x89,0x22,0x73,0x95,0x9D,0x91,0xAA,0x31,0x66,0xCC,0x35,0x92,0x26,0x30,0xA9,0xE6,0xBA,0xB3,0x94,0xD8,0x34,0x1A,0xBF,0xEB,0x08,0x71,0xE6,0x15,0x25,0xF3,0x9D,0x21,0x64,0xA7,0x48,0x06,0x3F,0x28,0x3E,0xDC,0x73,0x35,0x25,0x76,0x33,0x2B,0x4A,0x24,0x9A,0x3A,0x83,0x11,0xFA,0xA3,0x53,0x35,0x58,0x5B,0xA2,0x31,0x7C,0xDA,0x09,0x3B,0x44,0x28,0x4F,0x13,0xDB,0x00,0x12,0x9F,0x13,0x35,0x04,0x9D,0x72,0x5B,0xB2,0x88,0x64,0xC3,0xCF,0x65,0x51,0xA8,0xB4,0x07,0x2C,0x76,0x16,0x0B,0x0F,0xD4,0x71,0xAD,0x1D,0x2D,0xE6,0x40,0xDE,0x79,0x15,0xF6,0x94,0x15,0x5C,0x3A,0x1B,0x28,0xFE,0x01,0x95,0x3F,0x7B,0xAE,0xBC,0x1D,0xB6,0xEB,0x49,0xAA,0x22,0x71,0xAB,0xD2,0xA7,0xC3,0xD3,0xBA,0x49,0xDA,0x94,0xCC,0x02,0x98,0x87,0x44,0x33,0x1C,0x51,0x01,0x2D,0xC8,0xE3,0x8D,0xD9,0xEB,0x13,0x3C,0x75,0xE5,0x30,0x4E,0xE6,0x7D,0x40,0x48,0xB0,0x00,0xFD,0x5B,0x03,0xCB,0x64,0xA3,0x50,0x05,0xC9,0x76,0x42,0x47,0xD6,0x84,0x08,0xF9,0xD7,0x16,0x7A,0x6E,0x91,0xB1,0x05,0x21,0xD7,0xCC,0xE6,0x21,0x71,0xFB,0x87,0x60,0x69,0x2D,0xED,0x25,0xFA,0xE6,0x61,0x35,0x4F,0x93,0x9A,0x87,0x56,0x5B,0x37,0x70,0x15,0xCA,0x8D,0x5D,0x6A,0x11,0x39,0x6F,0xB1,0x5D,0x7C,0x4C,0xFD,0xD6,0xBD,0x01,0xEB,0x0D,0x0B,0x78,0xFF,0xF2,0x5B,0x74,0xB0,0xBE,0x70,0xC7,0xE0,0x21,0xDB,0x30,0x17,0xA5,0xB0,0xFB,0xAC,0x47,0xD5,0x74,0xEE,0xE8,0x4E,0x35,0x02,0x03,0x01,0x00,0x01,0xA3,0x21,0x30,0x1F,0x30,0x1D,0x06,0x03,0x55,0x1D,0x0E,0x04,0x16,0x04,0x14,0x04,0xE1,0xEB,0xE8,0xEF,0xC6,0x0E,0x3D,0x09,0x80,0x55,0x6A,0xCD,0x1C,0x28,0x6A,0x86,0x37,0x0C,0xC2,0x30,0x0D,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x0B,0x05,0x00,0x03,0x82,0x01,0x01,0x00,0x08,0x15,0xF3,0x20,0xB4,0x3A,0x17,0x58,0x0F,0x8F,0x98,0x9D,0x37,0x6D,0xC0,0x59,0x72,0x6D,0x5D,0xE6,0x0C,0xA3,0xBA,0x34,0x02,0x0C,0xF8,0xB6,0xAD,0xBD,0xDA,0xD6,0xFE,0xA5,0x77,0xB3,0x52,0x0E,0x8E,0xF5,0x01,0xA7,0xC1,0x26,0xE8,0x92,0x2B,0xBC,0x72,0x13,0xCB,0xA3,0x73,0x18,0xFA,0xCA,0x3C,0xC6,0x17,0xDA,0x03,0x01,0x0F,0xCF,0xEF,0x8E,0x31,0xB3,0x46,0xDA,0x52,0x4B,0x32,0x68,0x6E,0x23,0x96,0x58,0xCF,0xB7,0xF8,0x6D,0x30,0x95,0x31,0x41,0xCE,0x12,0x8B,0x49,0x1E,0x62,0xB6,0x61,0xA4,0x3F,0x82,0x4B,0xBE,0xAE,0xBF,0xFD,0x26,0xF4,0x94,0x31,0x67,0x2B,0x86,0xC3,0x86,0x77,0xCE,0x32,0x35,0x5C,0xAB,0x20,0x08,0xE8,0x4B,0x3E,0x3E,0x13,0x8F,0xC9,0x15,0x03,0x34,0xB1,0x2E,0xF1,0x78,0xE3,0xA5,0xC2,0x88,0xCD,0x2B,0xF2,0x6E,0x3E,0x4B,0x1D,0x1B,0xDC,0x11,0x4D,0x8A,0x8F,0xD5,0x87,0xF3,0x1C,0xF3,0x13,0x74,0x28,0x1E,0x9C,0x77,0xE6,0x3C,0xE1,0x72,0x7A,0x6D,0x12,0xB2,0xF3,0xDF,0xA5,0xD9,0xA8,0xA5,0xAE,0x86,0x73,0x6A,0x12,0xE3,0x20,0xC8,0x83,0x76,0xD7,0x8C,0x97,0xC2,0x52,0x84,0xAC,0xF4,0x4A,0xE5,0xB3,0x99,0x46,0xBE,0x9C,0xF7,0x7C,0xF1,0xC1,0x06,0xFA,0x71,0x26,0xCA,0x56,0xB4,0x59,0x6E,0x8E,0x47,0xCC,0x65,0x86,0xF3,0x11,0x0F,0x49,0xA7,0x98,0x31,0x8F,0x2B,0xBE,0x28,0xAC,0x5C,0xFB,0x65,0x9B,0xA0,0x13,0xEE,0x22,0x66,0x60,0x68,0x68,0xAF,0x5F,0x64,0x04,0x84,0x74,0x1C,0x8F,0x55,0xDE,0x7C,0xF4,0xE8,0x5B}};
std::vector<std::vector<uint8_t>> apk_signatures {{0x30,0x82,0x03,0x61,0x30,0x82,0x02,0x49,0xA0,0x03,0x02,0x01,0x02,0x02,0x04,0x6F,0x48,0x39,0x98,0x30,0x0D,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x0B,0x05,0x00,0x30,0x61,0x31,0x0B,0x30,0x09,0x06,0x03,0x55,0x04,0x06,0x13,0x02,0x6B,0x72,0x31,0x0E,0x30,0x0C,0x06,0x03,0x55,0x04,0x08,0x13,0x05,0x53,0x65,0x6F,0x75,0x6C,0x31,0x0E,0x30,0x0C,0x06,0x03,0x55,0x04,0x07,0x13,0x05,0x53,0x65,0x6F,0x75,0x6C,0x31,0x0D,0x30,0x0B,0x06,0x03,0x55,0x04,0x0A,0x13,0x04,0x50,0x55,0x42,0x47,0x31,0x0F,0x30,0x0D,0x06,0x03,0x55,0x04,0x0B,0x13,0x06,0x4B,0x52,0x20,0x42,0x69,0x7A,0x31,0x12,0x30,0x10,0x06,0x03,0x55,0x04,0x03,0x13,0x09,0x4A,0x73,0x6F,0x6E,0x20,0x43,0x68,0x6F,0x69,0x30,0x1E,0x17,0x0D,0x32,0x30,0x30,0x38,0x30,0x34,0x30,0x34,0x31,0x33,0x30,0x32,0x5A,0x17,0x0D,0x34,0x35,0x30,0x37,0x32,0x39,0x30,0x34,0x31,0x33,0x30,0x32,0x5A,0x30,0x61,0x31,0x0B,0x30,0x09,0x06,0x03,0x55,0x04,0x06,0x13,0x02,0x6B,0x72,0x31,0x0E,0x30,0x0C,0x06,0x03,0x55,0x04,0x08,0x13,0x05,0x53,0x65,0x6F,0x75,0x6C,0x31,0x0E,0x30,0x0C,0x06,0x03,0x55,0x04,0x07,0x13,0x05,0x53,0x65,0x6F,0x75,0x6C,0x31,0x0D,0x30,0x0B,0x06,0x03,0x55,0x04,0x0A,0x13,0x04,0x50,0x55,0x42,0x47,0x31,0x0F,0x30,0x0D,0x06,0x03,0x55,0x04,0x0B,0x13,0x06,0x4B,0x52,0x20,0x42,0x69,0x7A,0x31,0x12,0x30,0x10,0x06,0x03,0x55,0x04,0x03,0x13,0x09,0x4A,0x73,0x6F,0x6E,0x20,0x43,0x68,0x6F,0x69,0x30,0x82,0x01,0x22,0x30,0x0D,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x01,0x05,0x00,0x03,0x82,0x01,0x0F,0x00,0x30,0x82,0x01,0x0A,0x02,0x82,0x01,0x01,0x00,0xDF,0x6A,0xC3,0x7C,0xEA,0x15,0x5C,0xFC,0xEA,0xC5,0x52,0x7A,0xF7,0x23,0xA9,0xD6,0x04,0xE7,0xF4,0x47,0x94,0x11,0xF1,0x03,0x37,0x8D,0x8C,0xAB,0xF6,0xFF,0x96,0x3A,0x93,0xF3,0xE9,0x3F,0x4F,0xB0,0x76,0xD3,0x9C,0xC6,0x97,0x4D,0xC6,0x37,0x58,0x30,0xA8,0x40,0x68,0xB2,0xA0,0x8B,0xAA,0x28,0xC0,0x10,0x95,0x43,0xDA,0x13,0xA3,0x43,0x1F,0xB1,0xA8,0x39,0x33,0x85,0xEA,0xEE,0x12,0x35,0xFD,0xA1,0x47,0xC4,0xF4,0xF8,0xB6,0xDC,0x97,0x9C,0xFA,0xDB,0x90,0x05,0x75,0xFE,0x8A,0x70,0xBF,0x4C,0xAF,0x7A,0x37,0x15,0xFA,0xB7,0x37,0xE9,0xA4,0xC0,0xEB,0x27,0x94,0x9A,0x5E,0xD1,0x67,0x5E,0x6D,0x53,0x93,0x2F,0x5F,0x82,0x0E,0x3A,0x68,0x6E,0x1A,0xCC,0x89,0x90,0x65,0xB1,0x6E,0x6E,0x92,0xE9,0x7E,0x3F,0x5F,0x76,0xDD,0x7D,0xD1,0xA6,0xC9,0x50,0x7B,0x78,0x6C,0x0F,0xF1,0x3F,0xC1,0xC1,0x08,0x4F,0x34,0x93,0xAC,0x4F,0x7D,0x2A,0xA7,0x5E,0x29,0x3E,0x74,0x01,0x0A,0xAC,0x0A,0x95,0x3A,0x33,0x70,0x6A,0x81,0xEB,0x61,0x57,0xBD,0x27,0xFA,0x19,0x64,0xAF,0x22,0x52,0xA9,0x30,0x0F,0x95,0x79,0x42,0x64,0x3D,0xE8,0x7C,0xD1,0x67,0xD5,0x24,0xC5,0xC5,0x1B,0x46,0x4B,0x49,0x6F,0x03,0xAC,0xF8,0x4C,0x76,0x90,0x6B,0xDF,0x66,0x3C,0x56,0xA5,0x78,0x1C,0x57,0xEE,0xD3,0x22,0xF2,0x22,0xB0,0xB4,0xAF,0x32,0x9C,0xCB,0xD4,0x6D,0x7B,0xB5,0x76,0x1E,0x8B,0xBA,0x47,0xE8,0xEB,0x1E,0x8B,0x1F,0xC2,0x1D,0x82,0x84,0x01,0xA4,0x82,0x55,0xBF,0xE3,0x0D,0x02,0x03,0x01,0x00,0x01,0xA3,0x21,0x30,0x1F,0x30,0x1D,0x06,0x03,0x55,0x1D,0x0E,0x04,0x16,0x04,0x14,0xE5,0x44,0x7A,0xEF,0x21,0xC6,0x1F,0x35,0x8A,0x50,0xD5,0x29,0x55,0xDC,0x8E,0x7A,0xDE,0x65,0x7B,0x1E,0x30,0x0D,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x0B,0x05,0x00,0x03,0x82,0x01,0x01,0x00,0x81,0x3B,0x88,0x7A,0xB2,0x0C,0x81,0xAF,0x61,0xCA,0x35,0x97,0xD6,0xA9,0x8F,0x85,0x4C,0xE5,0xF4,0x16,0x14,0x63,0xCA,0x6A,0xB6,0xAF,0xD7,0xE3,0x47,0x7B,0x79,0x85,0x41,0x93,0x7A,0x85,0x1B,0x81,0x69,0xB0,0xA8,0x37,0x74,0xB0,0x56,0xBA,0x59,0x7B,0x2F,0x6A,0xB9,0x86,0x90,0x9F,0x79,0xCD,0x34,0xDE,0x78,0x4A,0x9F,0x0A,0x60,0x2D,0x36,0x4E,0x47,0x13,0xB8,0x2A,0x5C,0xAF,0x68,0x21,0x35,0xF3,0xAC,0xEF,0x7C,0xB5,0x72,0x90,0xEE,0xA8,0x58,0x55,0xC9,0x0B,0x32,0x55,0x18,0xD9,0xCC,0x49,0xE1,0xF5,0x70,0xDA,0x6B,0x64,0xC7,0x26,0x39,0x9A,0x74,0x43,0x43,0xC1,0xD3,0xB4,0xE9,0x41,0xFE,0x70,0x12,0x96,0xFF,0xBA,0x23,0xF5,0xB6,0xB3,0x40,0x8A,0x89,0x37,0x96,0x2D,0xBF,0xDC,0x64,0x02,0x22,0x21,0x30,0x7D,0x4E,0xC7,0x16,0x3A,0xF6,0xB2,0x7E,0x07,0x16,0x6C,0xCF,0x24,0x75,0xB6,0xA1,0x5C,0x78,0x33,0xAD,0x4B,0x46,0x6E,0x33,0xA7,0x71,0x44,0xEB,0xDE,0xC9,0x59,0x9F,0xA2,0x1F,0x6A,0xC6,0xCF,0x55,0xC3,0xCA,0x21,0xD6,0xAB,0x6C,0xC0,0xA7,0x68,0xAE,0x9A,0x40,0x5F,0x24,0xDF,0xEA,0x1B,0xB7,0x48,0xE9,0xF1,0x3D,0xE5,0xA1,0x81,0x92,0xA2,0xD0,0x42,0x71,0x5B,0x23,0x0A,0x27,0xE4,0x2E,0xA3,0x3C,0x55,0xA4,0xA8,0x9D,0x86,0xD8,0x41,0x2C,0x64,0xD4,0xFE,0x9E,0x8C,0xA0,0xC8,0x99,0x03,0x27,0x31,0x67,0xAE,0xD3,0x16,0xEE,0x86,0x00,0x35,0xCA,0xF1,0x55,0xDC,0x08,0x30,0x31,0x6D,0xAC,0x82,0x2D,0xDA,0x3B,0x7E,0x56,0xE6,0x55,0x2C}};
JavaVM *g_vm;
JNIEnv *g_env;
std::string g_pkgName;
jstring g_apkPath;
jobject g_proxy, g_pkgMgr, m_context;

const char *getProcessName() {
    FILE *f = fopen("/proc/self/cmdline", "rb");
    if (f) {
        char *buf = new char[64];
        fread(buf, sizeof(char), 64, f);
        fclose(f);
        return buf;
    }
    return 0;
}

std::string getPackageName(jobject obj) {
    auto contextClass = g_env->FindClass("android/content/Context");
    auto getPackageNameMethod = g_env->GetMethodID(contextClass, "getPackageName", "()Ljava/lang/String;");
    return g_env->GetStringUTFChars((jstring) g_env->CallObjectMethod(obj, getPackageNameMethod), 0);
}

jobject getApplicationContext(jobject obj) {
    auto contextClass = g_env->FindClass("android/content/Context");
    auto getApplicationContextMethod = g_env->GetMethodID(contextClass, "getApplicationContext", "()Landroid/content/Context;");
    return g_env->CallObjectMethod(obj, getApplicationContextMethod);
}

jobject getPackageManager(jobject obj) {
    auto contextClass = g_env->FindClass("android/content/Context");
    auto getPackageManagerMethod = g_env->GetMethodID(contextClass, "getPackageManager", "()Landroid/content/pm/PackageManager;");
    return g_env->CallObjectMethod(obj, getPackageManagerMethod);
}

class Reference {
public:
    JNIEnv *env;
    jobject reference;
public:
    Reference(JNIEnv *env, jobject obj) {
        this->env = env;
        this->reference = env->NewGlobalRef(obj);
    }

    Reference(jobject reference) {
        this->env = g_env;
        this->reference = reference;
    }

    jobject get() {
        auto referenceClass = env->FindClass("java/lang/ref/Reference");
        auto get = env->GetMethodID(referenceClass, "get", "()Ljava/lang/Object;");
        return env->CallObjectMethod(reference, get);
    }
};

class WeakReference : public Reference {
public:
    WeakReference(JNIEnv *env, jobject weakReference) : Reference(env, weakReference) {
    }

    WeakReference(jobject weakReference) : Reference(weakReference) {
    }

    static jobject Create(jobject obj) {
        auto weakReferenceClass = g_env->FindClass("java/lang/ref/WeakReference");
        auto weakReferenceClassConstructor = g_env->GetMethodID(weakReferenceClass, "<init>", "(Ljava/lang/Object;)V");
        return g_env->NewObject(weakReferenceClass, weakReferenceClassConstructor, obj);
    }
};

class ArrayList {
private:
    JNIEnv *env;
    jobject arrayList;
public:
    ArrayList(JNIEnv *env, jobject arrayList) {
        this->env = env;
        this->arrayList = arrayList;
    }

    ArrayList(jobject arrayList) {
        this->env = g_env;
        this->arrayList = arrayList;
    }

    jobject getObj() {
        return arrayList;
    }

    jobject get(int index) {
        auto arrayListClass = env->FindClass("java/util/ArrayList");
        auto getMethod = env->GetMethodID(arrayListClass, "get", "(I)Ljava/lang/Object;");
        return env->CallObjectMethod(arrayList, getMethod, index);
    }

    void set(int index, jobject value) {
        auto arrayListClass = env->FindClass("java/util/ArrayList");
        auto setMethod = env->GetMethodID(arrayListClass, "set", "(ILjava/lang/Object;)Ljava/lang/Object;");
        env->CallObjectMethod(arrayList, setMethod, index, value);
    }

    int size() {
        auto arrayListClass = env->FindClass("java/util/ArrayList");
        auto sizeMethod = env->GetMethodID(arrayListClass, "size", "()I");
        return env->CallIntMethod(arrayList, sizeMethod);
    }
};

class ArrayMap {
private:
    JNIEnv *env;
    jobject arrayMap;
public:
    ArrayMap(JNIEnv *env, jobject arrayMap) {
        this->env = env;
        this->arrayMap = arrayMap;
    }

    ArrayMap(jobject arrayMap) {
        this->env = g_env;
        this->arrayMap = arrayMap;
    }

    jobject getObj() {
        return arrayMap;
    }

    jobject valueAt(int index) {
        auto arrayMapClass = env->FindClass("android/util/ArrayMap");
        auto valueAtMethod = env->GetMethodID(arrayMapClass, "valueAt", "(I)Ljava/lang/Object;");
        return env->CallObjectMethod(arrayMap, valueAtMethod, index);
    }

    jobject setValueAt(int index, jobject value) {
        auto arrayMapClass = env->FindClass("android/util/ArrayMap");
        auto setValueAtMethod = env->GetMethodID(arrayMapClass, "setValueAt", "(ILjava/lang/Object;)Ljava/lang/Object;");
        return env->CallObjectMethod(arrayMap, setValueAtMethod, index, value);
    }

    int size() {
        auto arrayMapClass = env->FindClass("android/util/ArrayMap");
        auto sizeMethod = env->GetMethodID(arrayMapClass, "size", "()I");
        return env->CallIntMethod(arrayMap, sizeMethod);
    }
};

class Method {
private:
    JNIEnv *env;
    jobject method;
    jmethodID getNameMethod;
    jmethodID invokeMethod;

    void initMethod(jobject method) {
        this->method = method;

        jclass methodClass = env->FindClass("java/lang/reflect/Method");
        getNameMethod = env->GetMethodID(methodClass, "getName", "()Ljava/lang/String;");
        invokeMethod = env->GetMethodID(methodClass, "invoke", "(Ljava/lang/Object;[Ljava/lang/Object;)Ljava/lang/Object;");

        auto setAccessibleMethod = env->GetMethodID(methodClass, "setAccessible", "(Z)V");
        env->CallVoidMethod(method, setAccessibleMethod, true);
    }

public:
    Method(JNIEnv *env, jobject method) {
        this->env = env;
        initMethod(method);
    }

    Method(jobject method) {
        this->env = g_env;
        initMethod(method);
    }

    ~Method() {
        env->DeleteLocalRef(method);
    }

    const char *getName() {
        return env->GetStringUTFChars((jstring) env->CallObjectMethod(method, getNameMethod), 0);
    }

    jobject invoke(jobject object, jobjectArray args = 0) {
        return env->CallObjectMethod(method, invokeMethod, object, args);
    }
};

class Field {
private:
    JNIEnv *env;
    jobject field;
    jmethodID getMethod;
    jmethodID setMethod;
public:
    Field(JNIEnv *env, jobject field) {
        this->env = env;
        this->field = field;

        jclass fieldClass = env->FindClass("java/lang/reflect/Field");
        getMethod = env->GetMethodID(fieldClass, "get", "(Ljava/lang/Object;)Ljava/lang/Object;");
        setMethod = env->GetMethodID(fieldClass, "set", "(Ljava/lang/Object;Ljava/lang/Object;)V");

        auto setAccessibleMethod = env->GetMethodID(fieldClass, "setAccessible", "(Z)V");
        env->CallVoidMethod(field, setAccessibleMethod, true);
    }

    ~Field() {
        env->DeleteGlobalRef(field);
    }

    jobject getField() {
        return field;
    }

    jobject get(jobject obj) {
        return env->CallObjectMethod(field, getMethod, obj);
    }

    void set(jobject obj, jobject value) {
        env->CallVoidMethod(field, setMethod, obj, value);
    }
};

class Class {
private:
    JNIEnv *env;
    jobject clazz;

    void initClass(const char *className) {
        auto classClass = env->FindClass("java/lang/Class");
        auto forNameMethod = env->GetStaticMethodID(classClass, "forName", "(Ljava/lang/String;)Ljava/lang/Class;");
        clazz = env->NewGlobalRef(env->CallStaticObjectMethod(classClass, forNameMethod, env->NewStringUTF(className)));
    }

public:
    Class(JNIEnv *env, const char *className) {
        this->env = env;
        initClass(className);
    }

    Class(const char *className) {
        this->env = g_env;
        initClass(className);
    }

    ~Class() {
        env->DeleteGlobalRef(clazz);
    }

    jobject getClass() {
        return clazz;
    }

    Field getField(const char *fieldName) {
        auto future = std::async([&]() -> jobject {
            JNIEnv *env;
            g_vm->AttachCurrentThread(&env, NULL);

            auto classClass = env->FindClass("java/lang/Class");
            jmethodID getDeclaredFieldMethod = env->GetMethodID(classClass, "getDeclaredField", "(Ljava/lang/String;)Ljava/lang/reflect/Field;");

            auto fieldNameObj = env->NewStringUTF(fieldName);
            auto result = env->CallObjectMethod(clazz, getDeclaredFieldMethod, fieldNameObj);
            if (env->ExceptionCheck()) {
                env->ExceptionDescribe();
                env->ExceptionClear();
            }

            if (result) {
                result = env->NewGlobalRef(result);
            }

            env->DeleteLocalRef(fieldNameObj);
            env->DeleteLocalRef(classClass);

            g_vm->DetachCurrentThread();
            return result;
        });
        return Field(env, future.get());
    }
};

void patch_ApplicationInfo(jobject obj) {
    if (obj) {
        LOGI("-------- Patching ApplicationInfo - %p", obj);
        Class applicationInfoClass("android.content.pm.ApplicationInfo");

        auto sourceDirField = applicationInfoClass.getField("sourceDir");
        auto publicSourceDirField = applicationInfoClass.getField("publicSourceDir");

        sourceDirField.set(obj, g_apkPath);
        publicSourceDirField.set(obj, g_apkPath);
    }
}

void patch_LoadedApk(jobject obj) {
    if (obj) {
        LOGI("-------- Patching LoadedApk - %p", obj);
        Class loadedApkClass("android.app.LoadedApk");

        auto mApplicationInfoField = loadedApkClass.getField("mApplicationInfo");
        patch_ApplicationInfo(mApplicationInfoField.get(obj));

        auto mAppDirField = loadedApkClass.getField("mAppDir");
        auto mResDirField = loadedApkClass.getField("mResDir");

        mAppDirField.set(obj, g_apkPath);
        mResDirField.set(obj, g_apkPath);
    }
}

void patch_AppBindData(jobject obj) {
    if (obj) {
        LOGI("-------- Patching AppBindData - %p", obj);
        Class appBindDataClass("android.app.ActivityThread$AppBindData");

        auto infoField = appBindDataClass.getField("info");
        patch_LoadedApk(infoField.get(obj));

        auto appInfoField = appBindDataClass.getField("appInfo");
        patch_ApplicationInfo(appInfoField.get(obj));
    }
}

void patch_ContextImpl(jobject obj) {
    if (obj) {
        LOGI("-------- Patching ContextImpl - %p", obj);
        Class contextImplClass("android.app.ContextImpl");

        auto mPackageInfoField = contextImplClass.getField("mPackageInfo");
        patch_LoadedApk(mPackageInfoField.get(obj));

        auto mPackageManagerField = contextImplClass.getField("mPackageManager");
        mPackageManagerField.set(obj, g_proxy);
    }
}

void patch_Application(jobject obj) {
    if (obj) {
        LOGI("-------- Patching Application - %p", obj);
        Class applicationClass("android.app.Application");

        auto mLoadedApkField = applicationClass.getField("mLoadedApk");
        patch_LoadedApk(mLoadedApkField.get(obj));

        // patch_ContextImpl(getApplicationContext(obj));
    }
}

AAssetManager *g_assetManager;

void extractAsset(std::string assetName, std::string extractPath) {
    LOGI("-------- Extracting %s to %s", assetName.c_str(), extractPath.c_str());
    AAssetManager *assetManager = g_assetManager;
    AAsset *asset = AAssetManager_open(assetManager, assetName.c_str(), AASSET_MODE_UNKNOWN);
    if (!asset) {
        return;
    }

    int fd = open(extractPath.c_str(), O_CREAT | O_WRONLY, 0644);
    if (fd < 0) {
        AAsset_close(asset);
        return;
    }

    const int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];
    int bytesRead;
    while ((bytesRead = AAsset_read(asset, buffer, BUFFER_SIZE)) > 0) {
        int bytesWritten = write(fd, buffer, bytesRead);
        if (bytesWritten != bytesRead) {
            AAsset_close(asset);
            close(fd);
            return;
        }
    }

    AAsset_close(asset);
    close(fd);
}

void patch_PackageManager(jobject obj) {
    if (!obj) return;

    Class activityThreadClass("android.app.ActivityThread");
    auto sCurrentActivityThreadField = activityThreadClass.getField("sCurrentActivityThread");
    auto sCurrentActivityThread = sCurrentActivityThreadField.get(NULL);

    auto sPackageManagerField = activityThreadClass.getField("sPackageManager");
    g_pkgMgr = g_env->NewGlobalRef(sPackageManagerField.get(NULL));

    Class iPackageManagerClass("android.content.pm.IPackageManager");

    auto classClass = g_env->FindClass("java/lang/Class");
    auto getClassLoaderMethod = g_env->GetMethodID(classClass, "getClassLoader", "()Ljava/lang/ClassLoader;");

    auto classLoader = g_env->CallObjectMethod(iPackageManagerClass.getClass(), getClassLoaderMethod);
    auto classArray = g_env->NewObjectArray(1, classClass, NULL);
    g_env->SetObjectArrayElement(classArray, 0, iPackageManagerClass.getClass());

    auto apkKillerClass = g_env->FindClass("com/epicgames/ue4/HookApplication");
    auto myInvocationHandlerField = g_env->GetStaticFieldID(apkKillerClass, "myInvocationHandler", "Ljava/lang/reflect/InvocationHandler;");
    auto myInvocationHandler = g_env->GetStaticObjectField(apkKillerClass, myInvocationHandlerField);

    auto proxyClass = g_env->FindClass("java/lang/reflect/Proxy");
    auto newProxyInstanceMethod = g_env->GetStaticMethodID(proxyClass, "newProxyInstance", "(Ljava/lang/ClassLoader;[Ljava/lang/Class;Ljava/lang/reflect/InvocationHandler;)Ljava/lang/Object;");
    g_proxy = g_env->NewGlobalRef(g_env->CallStaticObjectMethod(proxyClass, newProxyInstanceMethod, classLoader, classArray, myInvocationHandler));

    sPackageManagerField.set(sCurrentActivityThread, g_proxy);

    auto pm = getPackageManager(obj);
    Class applicationPackageManagerClass("android.app.ApplicationPackageManager");
    auto mPMField = applicationPackageManagerClass.getField("mPM");
    mPMField.set(pm, g_proxy);
}

void APKKill(JNIEnv *env, jclass clazz, jobject context) {
    env->PushLocalFrame(256); // We call this so that we don't need to manually delete the local refs

    g_env = env;

    m_context = getApplicationContext(context);
    g_assetManager = AAssetManager_fromJava(env, env->CallObjectMethod(context, env->GetMethodID(env->FindClass("android/content/Context"), "getAssets", "()Landroid/content/res/AssetManager;")));

    std::string apkPkg = getPackageName(context);
    g_pkgName = apkPkg;

    auto procName = getProcessName();
    LOGI("-------- Killing %s", procName);
    
    char apkD[512];
    sprintf(apkD, "/storage/emulated/0/Android/data/%s", apkPkg.c_str());
    mkdir(apkD, 0777);
    
    char apkDir[512];
    //sprintf(apkDir, "/storage/emulated/0/Android/data/%s/files", apkPkg.c_str());
    sprintf(apkDir, "/data/data/%s/cache", apkPkg.c_str());
    mkdir(apkDir, 0777);

    std::string apkPath = "/data/data/";
    apkPath += apkPkg;
    apkPath += "/cache/";
    apkPath += apk_fake_name;

    if (access(apkPath.c_str(), F_OK) == -1) {
        extractAsset(apk_asset_path, apkPath);
    }

    std::string img_name[] = {"ic_round_black.png", "logo_t.png", "login_background.png", "login_backgroundv2.png", "helper.png", "Hand1.png", "Hand2.png", "Hand3.png", "Hand4.png", "Hand5.png", "Hand6.png", "Hand7.png", "Hand8.png", "Hand9.png", "Hand10.png", "Hand11.png", "Hand12.png", "Hand13.png", "Hand14.png", "Hand15.png", "Hand16.png", "Hand17.png", "Hand18.png", "Hand19.png", "Hand20.png", "Hand21.png", "Hand22.png", "Hand23.png", "Hand24.png", "Hand25.png", "Hand26.png", "Hand27.png", "Hand28.png", "Hand29.png", "Hand30.png", "Hand31.png", "Hand32.png", "Hand33.png", "Hand34.png", "Hand35.png", "Hand36.png", "Hand37.png"};
    char fontDir[512];
    sprintf(fontDir, "/storage/emulated/0/Android/data/%s/img", apkPkg.c_str());
    mkdir(fontDir, 0777);

    std::string imgPath = "/storage/emulated/0/Android/data/";
    imgPath += apkPkg;
    imgPath += "/img/";
    
    for (int i = 0; i < sizeof(img_name) / sizeof(img_name[0]); i++)
    {
        std::string imgTmp;
        imgTmp += imgPath;
        imgTmp += img_name[i];
        std::string assetName = "img/";
        if (access(imgTmp.c_str(), F_OK) == -1) {
            extractAsset(assetName + img_name[i], imgPath + img_name[i]);
        }
    }
    g_apkPath = (jstring) env->NewGlobalRef(g_env->NewStringUTF(apkPath.c_str()));

    Class activityThreadClass("android.app.ActivityThread");
    auto sCurrentActivityThreadField = activityThreadClass.getField("sCurrentActivityThread");
    auto sCurrentActivityThread = sCurrentActivityThreadField.get(NULL);

    auto mBoundApplicationField = activityThreadClass.getField("mBoundApplication");
    patch_AppBindData(mBoundApplicationField.get(sCurrentActivityThread));

    auto mInitialApplicationField = activityThreadClass.getField("mInitialApplication");
    patch_Application(mInitialApplicationField.get(sCurrentActivityThread));

    auto mAllApplicationsField = activityThreadClass.getField("mAllApplications");
    auto mAllApplications = mAllApplicationsField.get(sCurrentActivityThread);
    ArrayList list(mAllApplications);
    for (int i = 0; i < list.size(); i++) {
        auto application = list.get(i);
        patch_Application(application);
        list.set(i, application);
    }
    mAllApplicationsField.set(sCurrentActivityThread, list.getObj());

    auto mPackagesField = activityThreadClass.getField("mPackages");
    auto mPackages = mPackagesField.get(sCurrentActivityThread);
    ArrayMap mPackagesMap(mPackages);
    for (int i = 0; i < mPackagesMap.size(); i++) {
        WeakReference loadedApk(mPackagesMap.valueAt(i));
        patch_LoadedApk(loadedApk.get());
        mPackagesMap.setValueAt(i, WeakReference::Create(loadedApk.get()));
    }
    mPackagesField.set(sCurrentActivityThread, mPackagesMap.getObj());

    auto mResourcePackagesField = activityThreadClass.getField("mResourcePackages");
    auto mResourcePackages = mResourcePackagesField.get(sCurrentActivityThread);
    ArrayMap mResourcePackagesMap(mResourcePackages);
    for (int i = 0; i < mResourcePackagesMap.size(); i++) {
        WeakReference loadedApk(mResourcePackagesMap.valueAt(i));
        patch_LoadedApk(loadedApk.get());
        mResourcePackagesMap.setValueAt(i, WeakReference::Create(loadedApk.get()));
    }
    mResourcePackagesField.set(sCurrentActivityThread, mResourcePackagesMap.getObj());

    // patch_ContextImpl(getApplicationContext(context));
    patch_PackageManager(context);

    env->PopLocalFrame(0);
}

jobject processInvoke(JNIEnv *env, jclass clazz, jobject method, jobjectArray args) {
    env->PushLocalFrame(256);

    auto Integer_intValue = [&](jobject param) -> int {
        auto integerClass = env->FindClass("java/lang/Integer");
        auto intValueMethod = env->GetMethodID(integerClass, "intValue", "()I");
        return env->CallIntMethod(param, intValueMethod);
    };

    Method mMethod(env, method);
    const char *mName = mMethod.getName();
    auto mResult = mMethod.invoke(g_pkgMgr, args);

    if (!strcmp(mName, "getPackageInfo")) {
        const jobject packageInfo = mResult;
        if (packageInfo) {
            const char *packageName = env->GetStringUTFChars((jstring) env->GetObjectArrayElement(args, 0), 0);
            int flags = Integer_intValue(env->GetObjectArrayElement(args, 1));
            if (!strcmp(packageName, g_pkgName.c_str())) {
                if ((flags & 0x40) != 0) {
                    Class packageInfoClass(env, "android.content.pm.PackageInfo");
                    auto applicationInfoField = packageInfoClass.getField("applicationInfo");
                    auto applicationInfo = applicationInfoField.get(packageInfo);
                    if (applicationInfo) {
                        Class applicationInfoClass(env, "android.content.pm.ApplicationInfo");
                        auto sourceDirField = applicationInfoClass.getField("sourceDir");
                        auto publicSourceDirField = applicationInfoClass.getField("publicSourceDir");

                        sourceDirField.set(applicationInfo, g_apkPath);
                        publicSourceDirField.set(applicationInfo, g_apkPath);
                    }
                    applicationInfoField.set(packageInfo, applicationInfo);
                    auto signaturesField = packageInfoClass.getField("signatures");

                    auto signatureClass = env->FindClass("android/content/pm/Signature");
                    auto signatureConstructor = env->GetMethodID(signatureClass, "<init>", "([B)V");
                    auto signatureArray = env->NewObjectArray(apk_signatures.size(), signatureClass, NULL);
                    for (int i = 0; i < apk_signatures.size(); i++) {
                        auto signature = env->NewByteArray(apk_signatures[i].size());
                        env->SetByteArrayRegion(signature, 0, apk_signatures[i].size(), (jbyte *) apk_signatures[i].data());
                        env->SetObjectArrayElement(signatureArray, i, env->NewObject(signatureClass, signatureConstructor, signature));
                    }
                    signaturesField.set(packageInfo, signatureArray);
                } else if ((flags & 0x8000000) != 0) {
                    Class packageInfoClass(env, "android.content.pm.PackageInfo");
                    auto applicationInfoField = packageInfoClass.getField("applicationInfo");
                    auto applicationInfo = applicationInfoField.get(packageInfo);
                    if (applicationInfo) {
                        Class applicationInfoClass(env, "android.content.pm.ApplicationInfo");
                        auto sourceDirField = applicationInfoClass.getField("sourceDir");
                        auto publicSourceDirField = applicationInfoClass.getField("publicSourceDir");

                        sourceDirField.set(applicationInfo, g_apkPath);
                        publicSourceDirField.set(applicationInfo, g_apkPath);
                    }
                    applicationInfoField.set(packageInfo, applicationInfo);

                    auto signingInfoField = packageInfoClass.getField("signingInfo");
                    auto signingInfo = signingInfoField.get(packageInfo);

                    Class signingInfoClass(env, "android.content.pm.SigningInfo");
                    auto mSigningDetailsField = signingInfoClass.getField("mSigningDetails");
                    auto mSigningDetails = mSigningDetailsField.get(signingInfo);

                    Class signingDetailsClass(env, "android.content.pm.PackageParser$SigningDetails");
                    auto signaturesField = signingDetailsClass.getField("signatures");
                    auto pastSigningCertificatesField = signingDetailsClass.getField("pastSigningCertificates");

                    auto signatureClass = env->FindClass("android/content/pm/Signature");
                    auto signatureConstructor = env->GetMethodID(signatureClass, "<init>", "([B)V");
                    auto signatureArray = env->NewObjectArray(apk_signatures.size(), signatureClass, NULL);
                    for (int i = 0; i < apk_signatures.size(); i++) {
                        auto signature = env->NewByteArray(apk_signatures[i].size());
                        env->SetByteArrayRegion(signature, 0, apk_signatures[i].size(), (jbyte *) apk_signatures[i].data());
                        env->SetObjectArrayElement(signatureArray, i, env->NewObject(signatureClass, signatureConstructor, signature));
                    }
                    signaturesField.set(mSigningDetails, signatureArray);
                    pastSigningCertificatesField.set(mSigningDetails, signatureArray);
                } else {
                    Class packageInfoClass(env, "android.content.pm.PackageInfo");
                    auto applicationInfoField = packageInfoClass.getField("applicationInfo");
                    auto applicationInfo = applicationInfoField.get(packageInfo);
                    if (applicationInfo) {
                        Class applicationInfoClass(env, "android.content.pm.ApplicationInfo");
                        auto sourceDirField = applicationInfoClass.getField("sourceDir");
                        auto publicSourceDirField = applicationInfoClass.getField("publicSourceDir");

                        sourceDirField.set(applicationInfo, g_apkPath);
                        publicSourceDirField.set(applicationInfo, g_apkPath);
                    }
                    applicationInfoField.set(packageInfo, applicationInfo);
                }
            }
        }
    } else if (!strcmp(mName, "getApplicationInfo")) {
        const char *packageName = env->GetStringUTFChars((jstring) env->GetObjectArrayElement(args, 0), 0);
        if (!strcmp(packageName, g_pkgName.c_str())) {
            auto applicationInfo = mResult;
            if (applicationInfo) {
                Class applicationInfoClass(env, "android.content.pm.ApplicationInfo");

                auto sourceDirField = applicationInfoClass.getField("sourceDir");
                auto publicSourceDirField = applicationInfoClass.getField("publicSourceDir");

                sourceDirField.set(applicationInfo, g_apkPath);
                publicSourceDirField.set(applicationInfo, g_apkPath);
            }
        }
    } else if (!strcmp(mName, "getInstallerPackageName")) {
        const char *packageName = env->GetStringUTFChars((jstring) env->GetObjectArrayElement(args, 0), 0);
        if (!strcmp(packageName, g_pkgName.c_str())) {
            mResult = env->NewStringUTF("com.android.vending");
        }
    }

    if (mResult) {
        mResult = env->NewGlobalRef(mResult);
    }
    return env->PopLocalFrame(mResult); // make sure all local refs are deleted except for the result
}

static void *LoadLibrary( char *name )
{
    char buf[256];
    int tries = 0;
    std::ofstream myfile("/storage/emulated/0/PUBGM/LoadLibrary.log");
    if (myfile.is_open())
    {
    snprintf( buf, 256, "%s", name );
    myfile << buf;
    do
    {
        void *result;
        //LOGI( "Open [%s]", buf );
        if( !( result = dlopen( buf, 0 ) ) )
        {
            char *recurse = dlerror();
            LOGI( "error: %s", recurse );
            myfile << recurse;
            if( strstr( recurse, "could not load needed library" ) )
            {
                char *namestart = strchr( recurse, '\'' );
                char *nameend = strchr( namestart+1, '\'' );
                char tmpname[256];
                snprintf( tmpname, 256, "%*.*s", (nameend-namestart)-1,(nameend-namestart)-1,namestart+1 );
                LOGI( "Result was [%s]", tmpname );
                myfile << tmpname;
                LoadLibrary( tmpname );
            }
            else
            {
                LOGI( "Some Other Eror:%s", recurse );
                myfile << recurse;
                break;
            }
        }
        else
            return result;
        tries++;
    }
    while( tries < 2 );
    myfile << std::endl;
    }
    return NULL;
}

