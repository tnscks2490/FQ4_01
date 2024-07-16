#pragma once

#include "UIManagement.h"

class PlayMenuUI : public UIManagement
{
public:

	PlayMenuUI();
	~PlayMenuUI();

	virtual bool Is마우스가내안에(int mouse_x, int mouse_y) override;
	virtual int GetPosX() override;
	virtual int GetPosY() override;

	//bool Is마우스가내안에(int mouse_x, int mouse_y);
	void OnMouseMove(int mouse_x, int mouse_y);
	bool OnMouseDown(int mouse_x, int mouse_y, int left_right);
	//void MoveScreen();

	virtual void Draw(HDC hdc) override;


public:
	int Size_x = 256;
	int Size_y = 256;

	MenuIcon* mIcon;
	CScreen* pScreen = nullptr;
	HFONT hFont;

	// 현재 사용, 사용 대기 중인 아이콘
	int CurIcon = SelectNothing;
};