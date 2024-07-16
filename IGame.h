#pragma once
#include "CApplication.h"
#include "IScene.h"
#include "CScreen.h"
#include "KeyInput.h"

class IScene;


// �θ� Ŭ������ virtual ������ �ϴ� ���
// �ڽ��� �ش� �Լ��� �Ը���� �ٲٰ�ʹ�!! �ϴ� ��� ���
// �ڽ��� �θ�Ŭ������ �����پ��°� ���� �׷��� �Ϲ� ����


class IGame
{
public:
	IGame() : mCurrent(NULL) {}
	virtual void onChangeScene() = 0;
	virtual void onFrameMove()
	{
		onChangeScene();
		if (mCurrent) mCurrent->onFrameMove();
		InvalidateRect(CApplication::theApp->mhWnd, NULL, FALSE);
	}
	virtual void onDraw(HDC hdcWnd)
	{
		if (mCurrent)
		{
			CScreen screen(hdcWnd, 660, 540);
			mCurrent->onDraw(screen.m_HDC);
			screen.Draw(hdcWnd);
		}
	}
	virtual void onKeyDown(KeyInput* virtual_key)
	{
		/*char str[100];
		sprintf_s(str, 100, "V_key : %d\n", virtual_key);
		OutputDebugStringA(str);*/
		if (mCurrent) mCurrent->onKeyDown(virtual_key);

	}
	virtual void onMouseMove(UINT x, UINT y) 
	{
		
		/*char str[100];
		sprintf_s(str, 100, "Mouse Move : %d,%d \n",x,y );
		OutputDebugStringA(str);*/
		if (mCurrent) mCurrent->onMouseMove(x,y);
	}
	virtual void onMouseDown(UINT x, UINT y,UINT left_right) 
	{
		char str[100];
		sprintf_s(str, 100, "Mouse pos : (%d) %d,%d \n",left_right, x, y);
		OutputDebugStringA(str);

		if (mCurrent) mCurrent->onMouseDown(x, y, left_right);
	}

	// �����Լ��� �Լ������͸� ���� ���ϰ� ������ ��
	// ������� �����ϸ� �� Ŭ�������� �ش� �Լ��� �����͸� ������ ������ ����
	// ���� �θ�� �ڽ� ��� ���� �̸����� �Լ��� �����Ѵٸ� ���������� ������(�ڽ�) �Լ��� �����͸� ������
	// Ŭ������ �����Ⱑ �Ұ����� �ϸ� ��������!!

public:

	IScene* mCurrent;
};


//OutputDebugStringW(L"����");
//����Ƽ debug.log�� ���� ǥ�� ������Ҷ� �����ϰ� ��밡��!!

