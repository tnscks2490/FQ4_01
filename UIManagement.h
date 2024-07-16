#pragma once

#include "CImagefile.h"
#include "Csprite.h"
#include "CScreen.h"

enum eMenuIcon {

	SelectNothing = 0,
	Timelapse = 1,
	Unitmove = 2,
	Search = 3,
	Diplomacy = 4,
	Organization = 5,
	Info = 6,
	Method = 7,
	Record = 8,
	Exit = 9,
};

enum aMenuIcon
{
	um = 0,
	se = 1,
	di = 2,
	oz = 3,
};



struct MenuIcon
{
	CImagefile* Img;
	Csprite sprite;
	LPCWSTR text;
};

struct AMenuIcon
{
	CImagefile* Img;
	Csprite sprite;
};


struct AMenu
{
	Csprite sprite;
	LPCWSTR text;
	LPCWSTR text2;
};


class UIManagement
{
public:
	UIManagement();
	~UIManagement();


	virtual void Draw(HDC hdc) = 0;

	virtual bool Is마우스가내안에(int mouse_x, int mouse_y) =0;
	virtual int GetPosX() = 0;
	virtual int GetPosY() = 0;

	int GetSizeX() { return Size_x; }

	int Size_x = 256;
	int Size_y = 256;

	HFONT hFont;
};
