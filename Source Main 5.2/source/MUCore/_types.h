#pragma once

#include <algorithm>
#include <cstdint>
#include <map>
#include <string>

#include "_enum.h"

// Windows-style annotation fallbacks for non-Windows toolchains or headers.
#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

// Scalar and legacy vector aliases used across the client.
using vec_t = float;
using vec2_t = vec_t[2];
using vec3_t = vec_t[3];
using vec4_t = vec_t[4];
using vec34_t = vec_t[3][4];

template <typename T>
inline void InitVector(T* vect, int size)
{
    std::fill_n(vect, size, static_cast<T>(0));
}

template <typename T>
inline void IdentityMatrix(T (*mat)[4])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            mat[i][j] = static_cast<T>(0);
        }
    }
}

template <typename T>
inline void IdentityVector2D(T* vect)
{
    InitVector(vect, 2);
}

template <typename T>
inline void IdentityVector3D(T* vect)
{
    InitVector(vect, 3);
}

using PCHAR = char*;
using CHAR = char;
using STRING = std::string;

using PWCHAR = wchar_t*;
using WCHAR = wchar_t;
using WSTRING = std::wstring;
#if !defined(_WINDOWS_) && !defined(_WINDEF_) && !defined(_MINWINDEF_) && !defined(BASETYPES)
using DWORD = unsigned long;
using BYTE = unsigned char;
using SHORT = short;
using WORD = unsigned short;
using UINT = unsigned int;
using BOOL = int;
#endif

// Buff state lookup helper.
using BuffStateMap = std::map<eBuffState, std::uint32_t>;
