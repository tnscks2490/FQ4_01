#pragma once

#include "UIManagement.h"

class ActionMenuUI : public UIManagement
{
public:
	ActionMenuUI();
	~ActionMenuUI();

	virtual bool Is���콺�����ȿ�(int mouse_x, int mouse_y) override;
	virtual int GetPosX() override;
	virtual int GetPosY() override;

	void OnMouseMove(int mouse_x, int mouse_y);
	bool OnMouseDown(int mouse_x, int mouse_y, int left_right);
	void MoveScreen();

	void CVIcon_PMUIToAMUI(int SelectAct);

	virtual void Draw(HDC hdc) override;


public:
	int Size_x = 256;
	int Size_y = 256;

	AMenuIcon* mIcon;
	AMenu* mMenu;

	CScreen* pScreen = nullptr;
	HFONT hFont;

	int CurIcon = SelectNothing;
	int CurAction = um;
	// ���� ���, ��� ��� ���� ������
	//int CurIcon = Noicon;
};

