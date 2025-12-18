// MUCore/Local.cpp: implementation of the Local
//////////////////////////////////////////////////////////////////////

#include "MUMain/stdafx.h"
#include "Local.h"

bool CheckSpecialText(const wchar_t* text)
{
    if (text == nullptr)
    {
        return false;
    }

    for (const wchar_t* current = text; *current; ++current)
    {
        const wchar_t ch = *current;
        const bool isDigit = (L'0' <= ch && ch <= L'9');
        const bool isUpper = (L'A' <= ch && ch <= L'Z');
        const bool isLower = (L'a' <= ch && ch <= L'z');
        if (!(isDigit || isUpper || isLower))
        {
            return true;
        }
    }

    return false;
}