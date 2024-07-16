#include "pch.h"
#include "CImagefile.h"
#include "Csprite.h"

Csprite::Csprite()
{
	mdestX=0;
	mdestY = 0;
	mdestWidth=0;
	mdestHeight=0;

	mSrcX=0;
	mSrcY=0;
	mSrcWidth=0;
	mSrcHeight=0;

	UINT mTransColor = 0;
	BYTE mAlpha = 0;
	TDrawType mDrawType = DrawType_Draw;
	CImagefile* mImgFile = nullptr;

}

Csprite::~Csprite()
{
}

void Csprite::Draw(HDC hdc)
{
	switch (mDrawType)
	{
	case DrawType_Draw:
		mImgFile->Draw(hdc,
			mdestX, mdestY,
			mSrcX, mSrcY,
			mSrcWidth, mSrcHeight);
			break;
	case DrawType_Transparent:
		mImgFile->transDraw(hdc, mdestX, mdestY, mSrcX, mSrcY, mSrcWidth, mSrcHeight,mTransColor);
		break;
	case DrawType_AlphaBlend:
		mImgFile->AlphaDraw(hdc, mdestX, mdestY,
			mSrcX, mSrcY, mSrcWidth, mSrcHeight,
			mAlpha);
		break;
	case(DrawType_FadeInOut):
		mImgFile->FadeInOut(hdc, mdestX, mdestY,
			mSrcX, mSrcY, mSrcWidth, mSrcHeight,
			mAlpha);
		break;
	}
}

void Csprite::IconChange(int idx)
{
	mSrcWidth = 32;
	mSrcHeight = 32;
	mSrcY = (32 * idx) - 32;
}

void Csprite::AIconChange(int idx)
{
	mSrcWidth = 32*5;
	mSrcHeight = 32;
	mSrcY = idx * 32;
}
