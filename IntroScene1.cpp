#include "pch.h"
#include "IntroScene1.h"
#include "CImagefile.h"
#include "IntroText.h"
#include "resource.h"
#include "CGameFQ4.h"
#include "Canimation.h"

IntroScene1::IntroScene1()
{
	Introfile = CImagefile::New(MAKEINTRESOURCE(IDB_INTRO1),L"IDB_INTRO1");
	Blackfile = CImagefile::New(MAKEINTRESOURCE(IDB_BLACK),L"IDB_BLACK");
	delta = 0, second = -1, endLine = 0,DeltaFirst = 0,DeltaLast = 0;
	FinishedCheck = false;
	checkend = false;
	//멤버 변수 초기화
	mBG.setSprite(0, 0, 0, 0, Csprite::DrawType_Draw, 0, Introfile);
	BlackBG.setSprite(0, 0, 0, 0, Csprite::DrawType_AlphaBlend, 0, Blackfile);
	BlackBG.mAlpha = 255;
	hFont = CreateFontW(20, 0, 0, 0, 700, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT("궁서"));

}

IntroScene1::~IntroScene1()
{
	CImagefile::Delete(Introfile);
	CImagefile::Delete(Blackfile);
	// CImagefile::Delete(mChar.ani);
	
	DeleteObject(hFont);
}

bool IntroScene1::IsFinished()
{
	return FinishedCheck;
}

void IntroScene1::onFrameMove()
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

	if (checkend)
	{
		DelayLast();
		if (DelayLast())
		{
			FinishedCheck = true;
		}
	}	
}

void IntroScene1::onDraw(HDC hdc)
{
	mBG.Draw(hdc);
	//mCharSprite.Draw(hdc);


	HFONT oldFont;
	oldFont = (HFONT)SelectObject(hdc, hFont);
	// (HFONT)SelectObject(hdc,hFont);
	// 위 함수의 의미는 hdc에 내가 쓰려고한 폰트 hFont를 넣으면 기존 사용하던 폰트를 반환한다.
	// 플로피 디스크 생각하면 됩니다.~
	SetBkMode(hdc, TRANSPARENT);
	if (endLine < LINEEND)
	{
		for (int i = 0; i < endLine; i++)
		{
			SetTextColor(hdc, RGB(0, 0, 0));
			TextOutW(hdc, textPosition[IntroIndex][0] + 2, textPosition[IntroIndex][1] + 2 + (i * 20), text[IntroIndex][i], wcslen(text[IntroIndex][i]));
			SetTextColor(hdc, RGB(255, 255, 255));
			TextOutW(hdc, textPosition[IntroIndex][0], textPosition[IntroIndex][1] + (i * 20), text[IntroIndex][i], wcslen(text[IntroIndex][i]));
		}
		SetTextColor(hdc, RGB(0, 0, 0));
		TextOutW(hdc, textPosition[IntroIndex][0] + 2, textPosition[IntroIndex][1] + 2 + (endLine * 20), text[IntroIndex][endLine], second + 1);
		SetTextColor(hdc, RGB(255, 255, 255));
		TextOutW(hdc, textPosition[IntroIndex][0], textPosition[IntroIndex][1] + (endLine * 20), text[IntroIndex][endLine], second + 1);
	}
	else
	{
		for (int i = 0; i < LINEEND; i++)
		{
			SetTextColor(hdc, RGB(0, 0, 0));
			TextOutW(hdc, textPosition[IntroIndex][0] + 2, textPosition[IntroIndex][1] + 2 + (i * 20), text[IntroIndex][i], wcslen(text[IntroIndex][i]));
			SetTextColor(hdc, RGB(255, 255, 255));
			TextOutW(hdc, textPosition[IntroIndex][0], textPosition[IntroIndex][1] + (i * 20), text[IntroIndex][i], wcslen(text[IntroIndex][i]));
		}
		checkend = true;
	}
	SelectObject(hdc, oldFont);
	BlackBG.Draw(hdc);
	// 구조가 드로우 프레임 드로우 프레임이기때문에
	// 프레임에서 카운팅한값을 넘겨줘서 해야한다
}

void IntroScene1::onKeyDown(KeyInput* virtual_key)
{
	if(virtual_key->KeyDownkey == 32)
		CApplication::pGame->NextScene = CApplication::pGame->mIntroLoby;
}

bool IntroScene1::DelayFirst()
{
	DeltaFirst++;
	if(BlackBG.mAlpha > 0)BlackBG.mAlpha--;
	if (DeltaFirst > 300)
	{
		return true;
	}

	return false;
}

bool IntroScene1::DelayLast()
{

	DeltaLast++;
	if(DeltaLast >200)
		if (BlackBG.mAlpha < 254) 
			BlackBG.mAlpha+=2;
	if (DeltaLast > 500)
	{
		return true;
	}
	

	return false;
}
