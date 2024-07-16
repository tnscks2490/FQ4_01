#include "pch.h"
#include "IntroScene1.h"
#include "CImagefile.h"
#include "IntroText.h"
#include "resource.h"
#include "CGameFQ4.h"

IntroLoby::IntroLoby()
{
	Introfile = CImagefile::New(MAKEINTRESOURCE(IDB_EMPTYLOBY),L"IDB_EMPTYLOBY");
	Blackfile = CImagefile::New(MAKEINTRESOURCE(IDB_BLACK),L"IDB_BLACK");
	Yellowfile = CImagefile::New(MAKEINTRESOURCE(IDB_YELLOW),L"IDB_YELLOW");

	delta = 0, second = -1, endLine = 0, DeltaFirst = 0, DeltaLast = 0;
	FinishedCheck = false;
	checkend = false;
	//멤버 변수 초기화

	

	mBG.setSprite(0, 0, 0, 0, Csprite::DrawType_Draw, 0, Introfile);
	BlackBG.setSprite(0, 0, 0, 0, Csprite::DrawType_AlphaBlend, 0, Blackfile);
	BlackBG.mAlpha = 255;
	//Yellowblock.setSprite(0, 0, 0, 0, Csprite::DrawType_AlphaBlend, 0, Yellowfile);
	Yellowblock.mAlpha = 250;
	hFont = CreateFontW(16, 0, 0, 0, 700, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT("궁서"));

	

}

IntroLoby::~IntroLoby()
{
	CImagefile::Delete(Introfile);
	CImagefile::Delete(Yellowfile);
	CImagefile::Delete(Blackfile);

	DeleteObject(hFont);
}

bool IntroLoby::IsFinished()
{
	return FinishedCheck;
}

void IntroLoby::onFrameMove()
{
	if (DelayFirst())
	{
		delta++;
		if (delta >= DELTAFRAME)
		{
			delta = 0;
			second++;
			if (second >= wcslen(text[IntroIndex][endLine]))
			{
				second = 0;
				endLine++;
			}
		}
	}
}

void IntroLoby::onMouseMove(UINT x, UINT y)
{
	xpos = x;
	ypos = y;
}




void IntroLoby::onDraw(HDC hdc)
{
	mBG.Draw(hdc);
	Cblock(hdc);

	HFONT oldFont;
	oldFont = (HFONT)SelectObject(hdc, hFont);
	(HFONT)SelectObject(hdc,hFont);
	SetBkMode(hdc, TRANSPARENT);
	SetTextColor(hdc, RGB(255, 0, 0));
	TextOutW(hdc, 220, 130, lobytext[0], wcslen(lobytext[0]));
	
	SetTextColor(hdc, RGB(0, 0, 0));


	TextOutW(hdc, 220, 160, lobytext[1], wcslen(lobytext[1]));
	TextOutW(hdc, 220, 177, lobytext[2], wcslen(lobytext[2]));
	TextOutW(hdc, 220, 194, lobytext[3], wcslen(lobytext[3]));
	TextOutW(hdc, 220, 211, lobytext[4], wcslen(lobytext[4]));
	TextOutW(hdc, 220, 240, lobytext[5], wcslen(lobytext[5]));
	
	SelectObject(hdc, oldFont);
	// 위 함수의 의미는 hdc에 내가 쓰려고한 폰트 hFont를 넣으면 기존 사용하던 폰트를 반환한다.
	// 플로피 디스크 생각하면 됩니다.~
	

	// 구조가 드로우 프레임이기때문에
	// 프레임에서 카운팅한값을 넘겨줘서 해야한다

}


void IntroLoby::onMouseDown(UINT x, UINT y, UINT left_right)
{

	if (ypos > 240 && ypos < 260)
	{
		FinishedCheck = true;
	}
}

void IntroLoby::onKeyDown(KeyInput* virtual_key)
{
	if (virtual_key->KeyDownkey == VK_UP)
	{
		CApplication::pGame->mCurrent = CApplication::pGame->tiletest;
	}

}


void IntroLoby::Cblock(HDC hdc)
{
	if (xpos > 215 && xpos < 430)
	{
		if (ypos > 150 && ypos < 170)
		{
			Yellowblock.setSprite(220, 160, 0, 0, Csprite::DrawType_AlphaBlend, 0, Yellowfile);
			Yellowblock.Draw(hdc);
		}
		else if (ypos > 170 && ypos < 190)
		{
			Yellowblock.setSprite(220, 177, 0, 0, Csprite::DrawType_AlphaBlend, 0, Yellowfile);
			Yellowblock.Draw(hdc);
		}
		else if (ypos > 190 && ypos < 210)
		{
			Yellowblock.setSprite(220, 194, 0, 0, Csprite::DrawType_AlphaBlend, 0, Yellowfile);
			Yellowblock.Draw(hdc);
		}
		else if (ypos > 210 && ypos < 230)
		{
			Yellowblock.setSprite(220, 210, 0, 0, Csprite::DrawType_AlphaBlend, 0, Yellowfile);
			Yellowblock.Draw(hdc);
		}
		else if (ypos > 240 && ypos < 260)
		{
			Yellowblock.setSprite(220, 240, 0, 0, Csprite::DrawType_AlphaBlend, 0, Yellowfile);
			Yellowblock.Draw(hdc);
		}
	}
}


bool IntroLoby::DelayFirst()
{
	DeltaFirst++;
	if (BlackBG.mAlpha > 0)BlackBG.mAlpha--;
	if (DeltaFirst > 300)
	{
		return true;
	}

	return false;
}

bool IntroLoby::DelayLast()
{

	DeltaLast++;
	if (DeltaLast > 200)
		if (BlackBG.mAlpha < 254)
			BlackBG.mAlpha += 2;
	if (DeltaLast > 500)
		return true;

	return false;
}
