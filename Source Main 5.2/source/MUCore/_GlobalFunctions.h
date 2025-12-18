#pragma once

#include <array>
#include <cassert>
#include <cstdarg>
#include <cstdint>
#include <cstdio>
#include <cwchar>

#include "ZzzScene.h"
#include "w_BuffStateSystem.h"

#ifndef TEXT
#ifdef _UNICODE
#define TEXT(str) L##str
#else
#define TEXT(str) str
#endif
#endif

class BuffStateSystem;
class BuffScriptLoader;
class BuffTimeControl;
class BuffStateValueControl;

extern BuffStateSystemPtr			g_BuffSystem;

BuffScriptLoader& TheBuffInfo();

BuffStateSystem& TheBuffStateSystem();

BuffTimeControl& TheBuffTimeControl();

BuffStateValueControl& TheBuffStateValueControl();

//Character Buff
#define g_isNotCharacterBuff( o ) \
	o->m_BuffMap.isBuff()

#define g_isCharacterBuff( o, bufftype ) \
	o->m_BuffMap.isBuff( bufftype )

#define g_isCharacterBufflist( o, bufftypelist ) \
	o->m_BuffMap.isBuff( bufftypelist )

#define g_TokenCharacterBuff( o, bufftype ) \
	o->m_BuffMap.TokenBuff( bufftype )

#define g_CharacterBuffCount( o, bufftype ) \
	o->m_BuffMap.GetBuffCount( bufftype )

#define g_CharacterBuffSize( o ) \
	o->m_BuffMap.GetBuffSize()

#define g_CharacterBuff( o, iterindex ) \
	o->m_BuffMap.GetBuff( iterindex )

#define g_CharacterRegisterBuff( o, bufftype ) \
	o->m_BuffMap.RegisterBuff( bufftype )

#define g_CharacterRegisterBufflist( o, bufftypelist ) \
	o->m_BuffMap.RegisterBuff( bufftypelist )

#define g_CharacterUnRegisterBuff( o, bufftype ) \
	o->m_BuffMap.UnRegisterBuff( bufftype )

#define g_CharacterUnRegisterBuffList( o, bufftypelist ) \
	o->m_BuffMap.UnRegisterBuff( bufftypelist )

#define g_CharacterCopyBuff( outObj, inObj ) \
	outObj->m_BuffMap.m_Buff = inObj->m_BuffMap.m_Buff

#define g_CharacterClearBuff( o ) \
	o->m_BuffMap.ClearBuff()

//TheBuffInfo
#define g_BuffInfo( buff ) \
	TheBuffInfo().GetBuffinfo( buff )

#define g_IsBuffClass( buff ) \
	TheBuffInfo().IsBuffClass( buff )

//TheBuffTimeControl
#define g_RegisterBuffTime( bufftype, curbufftime ) \
	TheBuffTimeControl().RegisterBuffTime( bufftype, curbufftime )

#define g_UnRegisterBuffTime( bufftype ) \
	TheBuffTimeControl().UnRegisterBuffTime( bufftype )

#define g_BuffStringTime( bufftype, timeText ) \
	TheBuffTimeControl().GetBuffStringTime( bufftype, timeText )

#define g_StringTime( time, timeText, issecond ) \
	TheBuffTimeControl().GetStringTime( time, timeText, issecond )

//TheBuffStateValueControl
#define g_BuffStateValue( type ) \
	TheBuffStateValueControl().GetValue( type )

#define g_BuffToolTipString( outstr, type ) \
	TheBuffStateValueControl().GetBuffInfoString( outstr, type )

#define g_BuffStateValueString( outstr, type ) \
	TheBuffStateValueControl().GetBuffValueString( outstr, type )

inline constexpr std::uint32_t RGBA(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a)
{
    return static_cast<std::uint32_t>(r)
        | (static_cast<std::uint32_t>(g) << 8)
        | (static_cast<std::uint32_t>(b) << 16)
        | (static_cast<std::uint32_t>(a) << 24);
}
inline constexpr std::uint8_t GetAlpha(std::uint32_t rgba)
{
    return static_cast<std::uint8_t>(rgba >> 24);
}
inline constexpr std::uint8_t GetRed(std::uint32_t rgba)
{
    return static_cast<std::uint8_t>(rgba & 0xff);
}
inline constexpr std::uint8_t GetGreen(std::uint32_t rgba)
{
    return static_cast<std::uint8_t>((rgba >> 8) & 0xff);
}
inline constexpr std::uint8_t GetBlue(std::uint32_t rgba)
{
    return static_cast<std::uint8_t>((rgba >> 16) & 0xff);
}

#ifdef CSK_DEBUG_RENDER_BOUNDINGBOX
extern bool g_bRenderBoundingBox;
#endif // CSK_DEBUG_RENDER_BOUNDINGBOX

inline void __TraceF(const char* pFmt, ...)
{
#ifdef _DEBUG
    std::array<char, 1024> buffer = {};
    va_list argList;
    va_start(argList, pFmt);
    std::vsnprintf(buffer.data(), buffer.size(), pFmt, argList);
    va_end(argList);
    std::fputs(buffer.data(), stderr);
#endif // _DEBUG
}

inline void __TraceF(const wchar_t* pFmt, ...)
{
#ifdef _DEBUG
    std::array<wchar_t, 1024> buffer = {};
    va_list argList;
    va_start(argList, pFmt);
    std::vswprintf(buffer.data(), buffer.size(), pFmt, argList);
    va_end(argList);
    std::fputws(buffer.data(), stderr);
#endif // _DEBUG
}
