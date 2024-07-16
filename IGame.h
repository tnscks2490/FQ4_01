#pragma once
#include "CApplication.h"
#include "IScene.h"
#include "CScreen.h"
#include "KeyInput.h"

class IScene;


// 부모 클래스가 virtual 선언을 하는 경우
// 자식이 해당 함수를 입맛대로 바꾸고싶다!! 하는 경우 사용
// 자식이 부모클래스를 가져다쓰는게 낫다 그러면 일반 선언


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

	// 가상함수는 함수포인터를 보기 편하게 구현한 것
	// 버츄얼을 선언하면 그 클래스에서 해당 함수의 포인터를 저장할 공간을 생성
	// 만약 부모와 자식 모드 같은 이름으로 함수를 구현한다면 마지막으로 구현한(자식) 함수의 포인터를 덮어씌운다
	// 클래스는 덮어씌우기가 불가능함 하면 불편해짐!!

public:

	IScene* mCurrent;
};


//OutputDebugStringW(L"문장");
//유니티 debug.log랑 같은 표현 디버깅할때 유용하게 사용가능!!

