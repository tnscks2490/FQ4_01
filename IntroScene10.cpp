#include "pch.h"
#include "IntroScene10.h"
#include "CImagefile.h"
#include "IntroText.h"
#include "resource.h"
#include "CGameFQ4.h"


IntroScene10::IntroScene10()
{
	Introfile = CImagefile::New(MAKEINTRESOURCE(IDB_INTRO10),L"IDB_INTRO10");
	Blackfile = CImagefile::New(MAKEINTRESOURCE(IDB_BLACK),L"IDB_BLACK");
	delta = 0, second = -1, endLine = 0, DeltaFirst = 0, DeltaLast = 0;
	FinishedCheck = false;
	checkend = false;
	//멤버 변수 초기화

	mBG.setSprite(0, 0, 0, 0, Csprite::DrawType_Draw, 0, Introfile);
	BlackBG.setSprite(0, 0, 0, 0, Csprite::DrawType_AlphaBlend, 0, Blackfile);
	BlackBG.mAlpha = 255;
	hFont = CreateFontW(20, 0, 0, 0, 700, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT("궁서"));

}

IntroScene10::~IntroScene10()
{
	CImagefile::Delete(Introfile);
	CImagefile::Delete(Blackfile);

	DeleteObject(hFont);
}

bool IntroScene10::IsFinished()
{
	return FinishedCheck;
}

void IntroScene10::onFrameMove()
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

void IntroScene10::onDraw(HDC hdc)
{
	mBG.Draw(hdc);
	HFONT oldFont;
	oldFont = (HFONT)SelectObject(hdc, hFont);
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

bool IntroScene10::DelayFirst()
{
	DeltaFirst++;
	if (BlackBG.mAlpha > 0)BlackBG.mAlpha--;
	if (DeltaFirst > 300)
	{
		return true;
	}
	return false;
}

bool IntroScene10::DelayLast()
{
	DeltaLast++;
	if (DeltaLast > 500)
	{
		return true;
	}
	return false;
}
