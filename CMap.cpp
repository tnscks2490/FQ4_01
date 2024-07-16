#include "pch.h"
#include "CMap.h"

CMap::CMap(const WCHAR* MapName, const WCHAR*name)
{
 	BackGroundMap = CImagefile::New(MapName, name);
	mScreen.setSprite(16, 47, 0, 0, Csprite::DrawType_Draw, 0, BackGroundMap);
	InScreen = false;
	CameraX = 0;
	CameraY = 0;
	CM = new CameraManagement(this);
}

CMap::CMap(const WCHAR* MapName, const WCHAR* name, Csprite::TDrawType Dt)
{
	switch (Dt)
	{
	case Csprite::DrawType_Transparent:
		BackGroundMap = CImagefile::New(MapName, name);
		mScreen.setSprite(16, 47, 0, 0, Csprite::DrawType_Transparent, RGB(255,0,255), BackGroundMap);
		InScreen = false;
		break;
	case Csprite::DrawType_Draw:
		BackGroundMap = CImagefile::New(MapName, name);
		mScreen.setSprite(16, 47, 0, 0, Csprite::DrawType_Draw, 0, BackGroundMap);
		InScreen = false;
		break;
	case Csprite::DrawType_FadeInOut:
		BackGroundMap = CImagefile::New(MapName, name);
		mScreen.setSprite(16, 47, 0, 0, Csprite::DrawType_FadeInOut, 0, BackGroundMap);
		InScreen = false;
		break;
	case Csprite::DrawType_AlphaBlend:
		BackGroundMap = CImagefile::New(MapName, name);
		mScreen.setSprite(16, 47, 0, 0, Csprite::DrawType_AlphaBlend, 0, BackGroundMap);
		mScreen.mAlpha = 0;
		InScreen = false;
		break;
	case Csprite::DrawType_OverLay:
		BackGroundMap = CImagefile::New(MapName, name);
		mScreen.setSprite(16, 47, 0, 0, Csprite::DrawType_OverLay, 0, BackGroundMap);
		mScreen.mAlpha = 0;
		InScreen = false;
		break;
	default:
		break;
	}
	CameraX = 0;
	CameraY = 0;
	CM = new CameraManagement(this);
}

CMap::CMap(const WCHAR* MapName, const WCHAR* name, bool InS)
{
	BackGroundMap = CImagefile::New(MapName, name);
	mScreen.setSprite(15, 15, 0, 0, Csprite::DrawType_Draw, 0, BackGroundMap);
	InScreen = InS;
	CameraX = 0;
	CameraY = 0;
	CM = new CameraManagement(this);
}
//하다 만건데 프레임 안에 하나의 CMap 넣기 하는중이었음

CMap::~CMap()
{
	CImagefile::Delete(BackGroundMap);
}


//끄트머리면 안움직이는거 구현하기
void CMap::CameraMove(int x, int y)
{
	CameraX += x;
	CameraY += y;
}

void CMap::ColorChange(UINT color)
{
	mScreen.mTransColor = color;
}

void CMap::Draw(HDC hdc)
{
	mScreen.mSrcX = CameraX;
	mScreen.mSrcY = CameraY;

	if(Visible) mScreen.Draw(hdc);
}

void CMap::CameraPosSetting(int x, int y)
{
	CameraX = x;
	CameraY = y;
}

void CMap::PosSet(int x, int y)
{
	mScreen.mdestX = x;
	mScreen.mdestY = y;
}
