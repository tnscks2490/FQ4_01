#pragma once
#include "CImagefile.h"



class Csprite
{
public:
	Csprite();
	~Csprite();
public:
	int mdestX;
	int mdestY;
	int mdestWidth;
	int mdestHeight;

	int mSrcX;
	int mSrcY;
	int mSrcWidth;
	int mSrcHeight;

	UINT mTransColor;
	BYTE mAlpha;
public:
	enum TDrawType {
		DrawType_Transparent,
		DrawType_Draw,
		DrawType_FadeInOut,
		DrawType_AlphaBlend,
		DrawType_OverLay,
	};


	TDrawType mDrawType;

	CImagefile* mImgFile;

	void setSprite(int dx, int dy, int srcx, int srcy, TDrawType Dt, UINT color, CImagefile* file)
	{
		mdestX = dx;
		mdestY = dy;
		mSrcX = srcx;
		mSrcY = srcy;
		mSrcWidth = file->Width();
		mSrcHeight = file->Height();
		mImgFile = file;
		mTransColor = color;
		mDrawType = Dt;
	}
	void Draw(HDC hdc);

	void IconChange(int idx);
	void AIconChange(int idx);

};

