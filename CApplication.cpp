#include "pch.h"
#include "CApplication.h"
#include "CGameFQ4.h"


CApplication* CApplication::theApp = NULL;  
CGameFQ4* CApplication::pGame = NULL;

// static���� ����� Ŭ������ ��� ������ �ƴϴ�.
// �ݷ����� �������

CApplication app;
CGameFQ4 game;

CApplication::CApplication()
{
	theApp = this;
}


void CApplication::ȭ�鰻��()
{
	InvalidateRect(mhWnd, NULL, TRUE);
}
// this�� �ڱ��ڽ��� ������