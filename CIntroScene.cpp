#include "pch.h"
#include "CImagefile.h"
#include "CIntroScene.h"
#include "resource.h"


#define LINEEND 5

CIntroScene::CIntroScene()
{
	Introfiles[0] = new CImagefile(MAKEINTRESOURCE(IDB_INTRO1));


	delta = 0, second = -1, endLine = 0,introIndex=0;
	DeltaFirst = 0;
	DeltaLast = 0;
	mBG.setSprite(0, 0, 0, 0, Csprite::DrawType_Draw, 0, Introfiles[introIndex]);
}

CIntroScene::~CIntroScene()
{
	for (int i = 0; i < 10; i++)
	{
		delete Introfiles[i];
	}
}

bool CIntroScene::IsFinished()
{
	return false;
}

// ����� ���� ���� 5�� ���
// 500������
// 
// ���� ��� ���� 3�� ��� 
// 300������

void CIntroScene::onFrameMove()
{
	if (DelayFirst())
	{
		delta++;
		if (delta >= 1)
		{
			delta = 0;
			second++;
			if (second >= wcslen(text[introIndex][endLine]))
			{
				second = 0;
				endLine++;
			}
		}
		
	}
}

void CIntroScene::FontSetting(HDC hdc)
{
	HFONT hFont, oldFont;
	hFont = CreateFontW(20, 0, 0, 0, 700, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT("�ü�"));
	oldFont = (HFONT)SelectObject(hdc, hFont);
}

void CIntroScene::onDraw(HDC hdc)
{
	mBG.Draw(hdc);
	FontSetting(hdc);
	SetBkMode(hdc, TRANSPARENT);
	if (endLine < LINEEND)
	{
		for (int i = 0; i < endLine; i++)
		{
			SetTextColor(hdc, RGB(0, 0, 0));
			TextOutW(hdc, textPosition[introIndex][0]+2, textPosition[introIndex][1]+2 + (i * 20), text[introIndex][i], wcslen(text[introIndex][i]));
			SetTextColor(hdc, RGB(255, 255, 255));
			TextOutW(hdc, textPosition[introIndex][0], textPosition[introIndex][1] + (i * 20), text[introIndex][i], wcslen(text[introIndex][i]));
		}
		SetTextColor(hdc, RGB(0, 0, 0));
		TextOutW(hdc, textPosition[introIndex][0]+2, textPosition[introIndex][1]+2 + (endLine * 20), text[introIndex][endLine], second + 1);
		SetTextColor(hdc, RGB(255, 255, 255));
		TextOutW(hdc, textPosition[introIndex][0], textPosition[introIndex][1] + (endLine * 20), text[introIndex][endLine], second + 1);
	}
	else
	{
		for (int i = 0; i < LINEEND; i++)
		{
			SetTextColor(hdc, RGB(0, 0, 0));
			TextOutW(hdc, textPosition[introIndex][0]+2, textPosition[introIndex][1]+2 + (i * 20), text[introIndex][i], wcslen(text[introIndex][i]));
			SetTextColor(hdc, RGB(255, 255, 255));
			TextOutW(hdc, textPosition[introIndex][0], textPosition[introIndex][1] + (i * 20), text[introIndex][i], wcslen(text[introIndex][i]));
		}
	}
	

	// ������ ��ο� ������ ��ο� �������̱⶧����
	// �����ӿ��� ī�����Ѱ��� �Ѱ��༭ �ؾ��Ѵ�
}

bool CIntroScene::DelayFirst()
{
	DeltaFirst++;
	if (DeltaFirst > 300)
	{
		return true;
	}

	return false;
}

bool CIntroScene::DelayLast()
{
	DeltaLast++;
	if (DeltaLast > 500)
	{
		return true;
	}

	return false;
}





