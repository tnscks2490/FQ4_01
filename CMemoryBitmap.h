#pragma once

struct ARGB {

	BYTE alpha, red, green, blue;
};
//저장할때 빠른거 부터 저장됨
// 따라서 blue, green, red, alpha 순이 되어야한다

//union ARGBColor
//{
//	UINT32 c;
//	ARGB argb;
//};
//
//UINT getRed(UINT32 color)
//{
//	UINT alpha = (color & 0xFF000000) >> 24;
//	UINT red = (color & 0x00FF0000) >> 16;
//	UINT green = (color & 0x0000FF00) >> 8;
//	UINT blue = (color & 0x000000FF);
//
//	ARGBColor cc;
//	cc.c = color;
//	UINT a = cc.argb.red;
//
//	return a;
//
//}

class CMemoryBitmap
{
	HBITMAP m_Old;

public:
	HBITMAP m_hBitmap;
	HDC     m_HDC;

	UINT32* m_Colors;
	BITMAPINFO m_BMI;        // bitmap header

public:
	CMemoryBitmap(HDC hdcWnd, int width, int height);
	~CMemoryBitmap();

	UINT32 getColor(int x, int y)			{ return m_Colors[y * m_BMI.bmiHeader.biWidth + x]; }
	void setColor(int x, int y, UINT32 c)	{ m_Colors[y * m_BMI.bmiHeader.biWidth + x] = c; }

	int getWidth()							{ return m_BMI.bmiHeader.biWidth; }
	int getHeight()							{ return m_BMI.bmiHeader.biHeight; }

	void Clear(UINT32 color = 0xFF000000);
};