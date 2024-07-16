#pragma once

class CGameFQ4;

class CApplication
{
public:
	CApplication();

	void 화면갱신();
public:
	static CApplication* theApp;
	static CGameFQ4* pGame;
	// 외부에 선언한것과 같고 extern으로 선언하여 외부변수처리함
	// 이걸 스태틱으로 편하게 가져올수있음
	
	int Frame = 60;

	bool IsChangedFrame = false;
	HINSTANCE mhInst;
	HWND	  mhWnd;
	HDC       sHDC;
};

