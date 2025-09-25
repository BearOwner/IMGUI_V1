#pragma once

//
// PlayerUnknown's Battlegrounds Mobile Lite (0.25.0 - 15130) SDK Generator by erroldecmod@gmail.com
// Generate on Tue Apr  4 13:03:13 2023
//

#include <cstddef>
#include <iostream>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <stdint.h>
#include <inttypes.h>
#include <vector>
#include <map>
#include <array>
#include <fstream>
#include <thread>
#include <pthread.h>
#include <dirent.h>
#include <libgen.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <jni.h>
#include <android/log.h>
#include <elf.h>
#include <dlfcn.h>
#include <sys/system_properties.h>
#include <codecvt>
#include <string>
#include <string.h>
#include <iterator>
#include <algorithm>

namespace itsArisu {

    inline std::string xor_(std::string s) {
        std::string out{};
        for (char& c : s) {
            out += c ^ (s.length() + 1) ^ 'f';
        }
        return out;
    }

    template<std::size_t S>
    struct Xor_String {
        std::array<char, S> charArr;

        inline auto operator()() {
            std::string str{};

            std::transform(charArr.begin(), charArr.end() - 1, std::back_inserter(str), [](auto const& c) {
                return c ^ S ^ 'f';
                });
            return str;
        }

        constexpr Xor_String(const char(&string)[S]) : charArr{} {
            auto it = charArr.begin();
            for (auto const& c : string) {
                *it = c ^ S ^ 'f';
                it++;
            }
        }
    };
}
#define enc(string) []() { static auto result = itsArisu::Xor_String<sizeof(string)/sizeof(char)>(string); return result(); }()
#define _enc_(string) []() { static auto result = itsArisu::Xor_String<sizeof(string)/sizeof(char)>(string); return result(); }().c_str()
