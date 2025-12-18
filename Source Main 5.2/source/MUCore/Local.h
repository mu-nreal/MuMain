// MUCore/Local.h: interface for the Local
//////////////////////////////////////////////////////////////////////
#pragma once

bool CheckSpecialText(const wchar_t* text);
inline bool CheckSpecialText(wchar_t* text)
{
    return CheckSpecialText(static_cast<const wchar_t*>(text));
}