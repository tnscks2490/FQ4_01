#pragma once
#include "Csprite.h"
#include "CImagefile.h"
#include "CameraManagement.h"
#include "resource.h"



class CMap
{
public:
	CMap(const WCHAR* MapName, const WCHAR* name);
	CMap(const WCHAR* MapName, const WCHAR* name, Csprite::TDrawType Dt);
	CMap(const WCHAR* MapName, const WCHAR* name, bool InS);
	~CMap();

	void CameraMove(int x, int y);

	void ColorChange(UINT color);
	void Draw(HDC hdc);

	void CameraPosSetting(int x, int y);
	void PosSet(int x, int y);
	
	
	bool InScreen;
	bool Visible = true;
	
	CImagefile* BackGroundMap;
	Csprite mScreen;
	CameraManagement* CM;
	int CameraX;
	int CameraY;

};

