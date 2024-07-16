#pragma once
#include "CMemoryBitmap.h"

class CScreen
	: public CMemoryBitmap
{
public:
	CScreen(HDC hdcWnd, int width, int height)
		: CMemoryBitmap(hdcWnd, width, height) {}

	void Draw(HDC hdc);
	void TransDraw(HDC hdc);
	void Draw(HDC hdc, int x, int y, int width, int height);
	void SetPos(int x, int y);
	void ChoiceDraw(HDC hdc,UINT x, UINT y);
	void MoveScreen(int x, int y);

	int posX = 0;
	int posY = 0;

	
};

