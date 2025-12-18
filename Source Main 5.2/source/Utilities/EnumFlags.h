#pragma once

#include <type_traits>

// Fallback definition for Windows-style flag operators when the platform
// headers do not provide DEFINE_ENUM_FLAG_OPERATORS (e.g., Linux).
#ifndef DEFINE_ENUM_FLAG_OPERATORS
#define DEFINE_ENUM_FLAG_OPERATORS(ENUMTYPE) \
extern "C++" { \
    inline ENUMTYPE operator |(ENUMTYPE a, ENUMTYPE b) \
    { \
        using T = std::underlying_type<ENUMTYPE>::type; \
        return static_cast<ENUMTYPE>(static_cast<T>(a) | static_cast<T>(b)); \
    } \
    inline ENUMTYPE operator &(ENUMTYPE a, ENUMTYPE b) \
    { \
        using T = std::underlying_type<ENUMTYPE>::type; \
        return static_cast<ENUMTYPE>(static_cast<T>(a) & static_cast<T>(b)); \
    } \
    inline ENUMTYPE operator ^(ENUMTYPE a, ENUMTYPE b) \
    { \
        using T = std::underlying_type<ENUMTYPE>::type; \
        return static_cast<ENUMTYPE>(static_cast<T>(a) ^ static_cast<T>(b)); \
    } \
    inline ENUMTYPE operator ~(ENUMTYPE a) \
    { \
        using T = std::underlying_type<ENUMTYPE>::type; \
        return static_cast<ENUMTYPE>(~static_cast<T>(a)); \
    } \
    inline ENUMTYPE& operator |=(ENUMTYPE& a, ENUMTYPE b) \
    { \
        a = a | b; \
        return a; \
    } \
    inline ENUMTYPE& operator &=(ENUMTYPE& a, ENUMTYPE b) \
    { \
        a = a & b; \
        return a; \
    } \
    inline ENUMTYPE& operator ^=(ENUMTYPE& a, ENUMTYPE b) \
    { \
        a = a ^ b; \
        return a; \
    } \
}
#endif
