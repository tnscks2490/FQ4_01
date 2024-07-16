#include "pch.h"
#include "IntroScene4.h"
#include "CImagefile.h"
#include "IntroText.h"
#include "resource.h"
#include "CGameFQ4.h"

IntroScene4::IntroScene4()
{
	Introfile = CImagefile::New(MAKEINTRESOURCE(IDB_INTRO4),L"IDB_INTRO4");
	Blackfile = CImagefile::New(MAKEINTRESOURCE(IDB_BLACK),L"IDB_BLACK");
	delta = 0, second = -1, endLine = 0, DeltaFirst = 0, DeltaLast = 0;
	FinishedCheck = false;
	checkend = false;
	//��� ���� �ʱ�ȭ

	mBG.setSprite(0, 0, 0, 0, Csprite::DrawType_Draw, 0, Introfile);
	BlackBG.setSprite(0, 0, 0, 0, Csprite::DrawType_AlphaBlend, 0, Blackfile);
	BlackBG.mAlpha = 255;

	hFont = CreateFontW(20, 0, 0, 0, 700, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT("�ü�"));

}

IntroScene4::~IntroScene4()
{
	CImagefile::Delete(Introfile);
	CImagefile::Delete(Blackfile);

	DeleteObject(hFont);
}

bool IntroScene4::IsFinished()
{
	return FinishedCheck;
}

void IntroScene4::onFrameMove()
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

void IntroScene4::onDraw(HDC hdc)
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
	// ������ ��ο� ������ ��ο� �������̱⶧����
	// �����ӿ��� ī�����Ѱ��� �Ѱ��༭ �ؾ��Ѵ�
}

bool IntroScene4::DelayFirst()
{
	DeltaFirst++;
	if (BlackBG.mAlpha > 0)BlackBG.mAlpha--;
	if (DeltaFirst > 300)
	{
		return true;
	}

	return false;
}

bool IntroScene4::DelayLast()
{

	DeltaLast++;
	if (DeltaLast > 200)
		if (BlackBG.mAlpha < 254)
			BlackBG.mAlpha += 2;
	if (DeltaLast > 500)
	{
		return true;
	}


	return false;
}
