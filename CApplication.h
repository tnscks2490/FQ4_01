#pragma once

class CGameFQ4;

class CApplication
{
public:
	CApplication();

	void ȭ�鰻��();
public:
	static CApplication* theApp;
	static CGameFQ4* pGame;
	// �ܺο� �����ѰͰ� ���� extern���� �����Ͽ� �ܺκ���ó����
	// �̰� ����ƽ���� ���ϰ� �����ü�����
	
	int Frame = 60;

	bool IsChangedFrame = false;
	HINSTANCE mhInst;
	HWND	  mhWnd;
	HDC       sHDC;
};

