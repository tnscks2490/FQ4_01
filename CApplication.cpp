#include "pch.h"
#include "CApplication.h"
#include "CGameFQ4.h"


CApplication* CApplication::theApp = NULL;  
CGameFQ4* CApplication::pGame = NULL;

// static으로 만들면 클래스의 멤버 변수가 아니다.
// 콜론으로 만들어줌

CApplication app;
CGameFQ4 game;

CApplication::CApplication()
{
	theApp = this;
}


void CApplication::화면갱신()
{
	InvalidateRect(mhWnd, NULL, TRUE);
}
// this는 자기자신의 포인터