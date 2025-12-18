//*****************************************************************************
// File: MUCore/UsefulDef.cpp
//
// Desc: ������ ���� ����.
//
// producer: Ahn Sang-Kyu
//*****************************************************************************

#include "UsefulDef.h"

#include <algorithm>
#include <cwchar>
#include <string>
#include <utility>
#include <vector>

namespace
{
    TextExtentFunction g_TextExtentFunction{};

    int DefaultTextExtent(const wchar_t* text)
    {
        if (text == nullptr)
        {
            return 0;
        }

        const size_t length = std::wcslen(text);
        return static_cast<int>(length);
    }

    int MeasureText(const std::wstring& text)
    {
        const TextExtentFunction extent = g_TextExtentFunction ? g_TextExtentFunction : DefaultTextExtent;
        return extent(text.c_str());
    }

    std::wstring TrimToPixel(const std::wstring& text, int maxPixel)
    {
        if (maxPixel <= 0)
        {
            return std::wstring();
        }

        int low = 0;
        int high = static_cast<int>(text.size());
        std::wstring result;

        while (low <= high)
        {
            const int mid = low + (high - low) / 2;
            const std::wstring candidate = text.substr(0, static_cast<size_t>(mid));
            if (MeasureText(candidate) <= maxPixel)
            {
                result = candidate;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return result;
    }

    std::vector<std::wstring> WrapByPixel(const std::wstring& text, int maxPixelPerLine, int maxLines)
    {
        std::vector<std::wstring> lines;
        if (maxPixelPerLine <= 0 || maxLines <= 0)
        {
            return lines;
        }

        std::wstring currentLine;
        for (wchar_t ch : text)
        {
            const std::wstring nextLine = currentLine + ch;
            if (MeasureText(nextLine) <= maxPixelPerLine || currentLine.empty())
            {
                currentLine = nextLine;
                continue;
            }

            lines.push_back(currentLine);
            if (static_cast<int>(lines.size()) >= maxLines)
            {
                return lines;
            }

            currentLine = std::wstring(1, ch);
        }

        if (!currentLine.empty() && static_cast<int>(lines.size()) < maxLines)
        {
            lines.push_back(currentLine);
        }

        return lines;
    }

    void WriteLinesToBuffer(const std::vector<std::wstring>& lines, wchar_t* destination, int rowCount, int columnCount)
    {
        const int clampedRows = std::min<int>(rowCount, static_cast<int>(lines.size()));
        for (int row = 0; row < clampedRows; ++row)
        {
            const std::wstring& line = lines[static_cast<size_t>(row)];
            const size_t copyLength = std::min<std::size_t>(static_cast<std::size_t>(columnCount - 1), line.size());
            std::wcsncpy(destination + row * columnCount, line.c_str(), copyLength);
            destination[row * columnCount + copyLength] = L'\0';
        }
    }
}

void SetTextExtentFunction(TextExtentFunction textExtentFunction)
{
    g_TextExtentFunction = std::move(textExtentFunction);
}

bool ReduceStringByPixel(wchar_t* lpszDst, int nDstSize, const wchar_t* lpszSrc, int nPixel)
{
    if (lpszDst == nullptr || lpszSrc == nullptr || nDstSize <= 0 || nPixel <= 0)
    {
        return false;
    }

    const std::wstring source(lpszSrc);
    const int sourceWidth = MeasureText(source);
    if (sourceWidth <= nPixel)
    {
        std::wcsncpy(lpszDst, source.c_str(), static_cast<std::size_t>(nDstSize - 1));
        lpszDst[nDstSize - 1] = L'\0';
        return false;
    }

    const std::wstring ellipsis = L"...";
    const int ellipsisWidth = MeasureText(ellipsis);
    const int availablePixels = std::max(0, nPixel - ellipsisWidth);
    const std::wstring trimmed = TrimToPixel(source, availablePixels);
    const std::wstring reduced = trimmed + ellipsis;

    std::wcsncpy(lpszDst, reduced.c_str(), static_cast<std::size_t>(nDstSize - 1));
    lpszDst[nDstSize - 1] = L'\0';
    return true;
}

int DivideStringByPixel(wchar_t* alpszDst, int nDstRow, int nDstColumn, const wchar_t* lpszSrc, int nPixelPerLine, bool bSpaceInsert, const wchar_t szNewlineChar)
{
    if (alpszDst == nullptr || lpszSrc == nullptr || nDstRow <= 0 || nDstColumn <= 0 || nPixelPerLine < 16)
    {
        return 0;
    }

    std::fill(alpszDst, alpszDst + static_cast<std::size_t>(nDstRow * nDstColumn), L'\0');

    const std::wstring source(lpszSrc);
    std::vector<std::wstring> lines;

    std::wstring token;
    for (wchar_t ch : source)
    {
        if (ch == szNewlineChar)
        {
            const std::wstring workToken = bSpaceInsert ? (L" " + token) : token;
            const std::vector<std::wstring> wrapped = WrapByPixel(workToken, nPixelPerLine, nDstRow - static_cast<int>(lines.size()));
            lines.insert(lines.end(), wrapped.begin(), wrapped.end());
            token.clear();
            if (static_cast<int>(lines.size()) >= nDstRow)
            {
                break;
            }
            continue;
        }

        token.push_back(ch);
    }

    if (!token.empty() && static_cast<int>(lines.size()) < nDstRow)
    {
        const std::wstring workToken = bSpaceInsert ? (L" " + token) : token;
        const std::vector<std::wstring> wrapped = WrapByPixel(workToken, nPixelPerLine, nDstRow - static_cast<int>(lines.size()));
        lines.insert(lines.end(), wrapped.begin(), wrapped.end());
    }

    WriteLinesToBuffer(lines, alpszDst, nDstRow, nDstColumn);
    return static_cast<int>(lines.size());
}

int DivideString(wchar_t* alpszDst, int nDstRow, int nDstColumn, const wchar_t* lpszSrc)
{
    if (alpszDst == nullptr || lpszSrc == nullptr || nDstRow <= 0 || nDstColumn <= 0)
    {
        return 0;
    }

    const int nSrcLen = static_cast<int>(std::wcslen(lpszSrc));
    if (nSrcLen == 0)
    {
        return 0;
    }

    int nSrcPos = 0;
    int nDstStart = 0;
    int nDstLen = 1;
    int nLineCount = 0;

    while (true)
    {
        if (0x80 & lpszSrc[nSrcPos])
        {
            ++nSrcPos;
            ++nDstLen;
        }

        if (L'/' == lpszSrc[nSrcPos])
        {
            std::wcsncpy(alpszDst + nLineCount * nDstColumn, lpszSrc + nDstStart, static_cast<std::size_t>(nDstLen - 1));
            ++nLineCount;
            nDstStart = nSrcPos + 1;
            nDstLen = 0;
        }
        else if (nDstLen >= nDstColumn)
        {
            nSrcPos -= 2;
            nDstLen -= 2;
            std::wcsncpy(alpszDst + nLineCount * nDstColumn, lpszSrc + nDstStart, static_cast<std::size_t>(nDstLen));
            ++nLineCount;
            nDstStart = nSrcPos + 1;
            nDstLen = 0;
        }
        else if (nSrcPos == nSrcLen - 1)
        {
            std::wcsncpy(alpszDst + nLineCount * nDstColumn, lpszSrc + nDstStart, static_cast<std::size_t>(nDstLen));
            break;
        }
        else if (nDstLen == nDstColumn - 1)
        {
            std::wcsncpy(alpszDst + nLineCount * nDstColumn, lpszSrc + nDstStart, static_cast<std::size_t>(nDstLen));
            ++nLineCount;
            nDstStart = nSrcPos + 1;
            nDstLen = 0;
        }

        if (nDstRow == nLineCount)
        {
            break;
        }

        ++nSrcPos;
        ++nDstLen;
    }

    return nLineCount + 1;
}

bool CheckErrString(wchar_t* lpszTarget)
{
    if (lpszTarget == nullptr)
    {
        return false;
    }

    int i = 0;
    const int nLen = static_cast<int>(std::wcslen(lpszTarget));
    while (i < nLen)
    {
        if (0x80 & lpszTarget[i])
        {
            if (i == nLen - 1)
            {
                lpszTarget[i] = L'\0';
                return false;
            }
            else
            {
                ++i;
            }
        }
        ++i;
    }

    return true;
}