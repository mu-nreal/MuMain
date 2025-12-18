#pragma once

#include <cstdint>
#include <functional>

#define MIN(a, b)			(((a) < (b)) ? (a) : (b))
#define MAX(a, b)			(((a) > (b)) ? (a) : (b))
#define LIMIT(val, l, h)	((val) < (l) ? (l) : (val) > (h) ? (h) : (val))
#define SWAP(a, b)			{ (a) ^= (b) ^= (a) ^= (b); }
#define	ARGB(a,r,g,b)	(static_cast<std::uint32_t>(a)<<24 | static_cast<std::uint32_t>(r) | (static_cast<std::uint32_t>(g)<<8) | (static_cast<std::uint32_t>(b)<<16))

using TextExtentFunction = std::function<int(const wchar_t*)>;

bool ReduceStringByPixel(wchar_t* lpszDst, int nDstSize, const wchar_t* lpszSrc, int nPixel);
#if defined KJH_ADD_INGAMESHOP_UI_SYSTEM || defined LJH_MOD_TO_USE_DIVIDESTRINGBYPIXEL_FUNC
int DivideStringByPixel(wchar_t* alpszDst, int nDstRow, int nDstColumn, const wchar_t* lpszSrc,
    int nPixelPerLine, bool bSpaceInsert = true, const wchar_t szNewLineChar = L';');
#else // define KJH_ADD_INGAMESHOP_UI_SYSTEM || define LJH_MOD_TO_USE_DIVIDESTRINGBYPIXEL_FUNC
int DivideStringByPixel(wchar_t* alpszDst, int nDstRow, int nDstColumn, const wchar_t* lpszSrc,
    int nPixelPerLine, bool bSpaceInsert = true);
#endif // define KJH_ADD_INGAMESHOP_UI_SYSTEM || define LJH_MOD_TO_USE_DIVIDESTRINGBYPIXEL_FUNC
int DivideString(wchar_t* alpszDst, int nDstRow, int nDstColumn, const wchar_t* lpszSrc);

bool CheckErrString(wchar_t* lpszTarget);

void SetTextExtentFunction(TextExtentFunction textExtentFunction);
