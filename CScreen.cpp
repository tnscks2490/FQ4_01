#include "pch.h"
#include "framework.h"
#include "CScreen.h"

void CScreen::Draw(HDC hdc)
{
		BitBlt(hdc,posX, posY,getWidth(), getHeight(),m_HDC,0, 0, SRCCOPY);
}

void CScreen::TransDraw(HDC hdc)
{
	TransparentBlt(hdc, posX, posY, getWidth(), getHeight(), m_HDC, 0, 0, getWidth(), getHeight(), RGB(255, 0, 255));
}

void CScreen::Draw(HDC hdc, int x, int y, int width, int height)
{
		BitBlt(hdc,x, y,width, height,m_HDC,0, 0, SRCCOPY);
}

void CScreen::SetPos(int x, int y)
{
	posX = x;
	posY = y;
}

void CScreen::ChoiceDraw(HDC hdc,UINT x, UINT y)
{
	BitBlt(hdc,
		x, y,
		getWidth(), getHeight(),
		m_HDC,
		0, 0, SRCCOPY
	);
}

void CScreen::MoveScreen(int x, int y)
{
	posX += x;
	posY += y;
}
