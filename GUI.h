#pragma once
#include "CImagefile.h"
#include "Csprite.h"
#include "CUnit.h"
#include "Script.h"

// 어지간하면 그냥
// 생성 시점을 정해야 할 경우 포인터 (특정 조건)

struct BGUI {
	CImagefile* BgUi = nullptr;
	Csprite bgui;
};

struct TEXTBOX {
	CImagefile* TextBox = nullptr;
	Csprite textbox;
};

struct LOCATION_BOX {
	CImagefile* Location_Box = nullptr;
	Csprite location_box;
};


class GUI
{
public:
	GUI(std::wstring CurScene);
	~GUI();


	void UIDraw(HDC hdc);
	void PlayScreenUIDraw(HDC hdc);
	void LocationDraw(HDC hdc,const WCHAR* location);
	void TextBoxDraw(HDC hdc);
	void ScriptDraw(HDC hdc, int idx, ScriptZip Sczip);
	void SetScriptUnit(int id);
	void ChangeTextBox(ScriptZip Sczip);


	CUnit* TextUnit = nullptr;
	BGUI* mBgUi = nullptr;
	BGUI* mPlayScreenUI = nullptr;

	LOCATION_BOX* mLocation_Box = nullptr;
	TEXTBOX* mTextBox = nullptr;

	CImagefile* TextBox1 = nullptr;
	CImagefile* TextBox2 = nullptr;
	CImagefile* TextBox3 = nullptr;
	CImagefile* TextBox4 = nullptr;

	Csprite textbox1;
	Csprite textbox2;
	Csprite textbox3;
	Csprite textbox4;
	std::wstring CurruntScene;

};

