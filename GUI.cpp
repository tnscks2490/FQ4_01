#include "pch.h"
#include "GUI.h"
#include "resource.h"

#define RESOURCE_NAME(x) MAKEINTRESOURCE(x),L#x

GUI::GUI(std::wstring CurScene)
{
	mBgUi = new BGUI;
	mPlayScreenUI = new BGUI;
	mTextBox = new TEXTBOX;
	mLocation_Box = new LOCATION_BOX;

	mBgUi->BgUi = CImagefile::New(MAKEINTRESOURCE(IDB_UIFRAME), L"IDB_UIFRAME");
	mBgUi->bgui.setSprite(0, 0, 0, 0, Csprite::DrawType_Draw, RGB(255, 0, 255), mBgUi->BgUi);

	mPlayScreenUI->BgUi = CImagefile::New(MAKEINTRESOURCE(IDB_PLAYSCREEN), L"IDB_PLAYSCREEN");
	mPlayScreenUI->bgui.setSprite(0, 0, 0, 0, Csprite::DrawType_Transparent, RGB(255, 0, 255), mPlayScreenUI->BgUi);


	mTextBox->TextBox = CImagefile::New(MAKEINTRESOURCE(IDB_NPC_TEXT_BOX4), L"IDB_NPC_TEXT_BOX4");
	mTextBox->textbox.setSprite(80, 175, 0, 0, Csprite::DrawType_Transparent, RGB(255, 0, 255), mTextBox->TextBox);

	mLocation_Box->Location_Box = CImagefile::New(MAKEINTRESOURCE(IDB_TEXTBOX1), L"IDB_TEXTBOX1");
	mLocation_Box->location_box.setSprite(140, 170, 0, 0, Csprite::DrawType_Draw, 0, mLocation_Box->Location_Box);

	CurruntScene = CurScene;

	TextBox1 = CImagefile::New(MAKEINTRESOURCE(IDB_NPC_TEXT_BOX1), L"IDB_NPC_TEXT_BOX1");
	TextBox2 = CImagefile::New(MAKEINTRESOURCE(IDB_NPC_TEXT_BOX2), L"IDB_NPC_TEXT_BOX2");
	TextBox3 = CImagefile::New(MAKEINTRESOURCE(IDB_NPC_TEXT_BOX3), L"IDB_NPC_TEXT_BOX3");
	TextBox4 = CImagefile::New(MAKEINTRESOURCE(IDB_NPC_TEXT_BOX4), L"IDB_NPC_TEXT_BOX4");

	textbox1.setSprite(80, 175, 0, 0, Csprite::DrawType_Transparent, RGB(255, 0, 255), TextBox1);
	textbox2.setSprite(80, 175, 0, 0, Csprite::DrawType_Transparent, RGB(255, 0, 255), TextBox2);
	textbox3.setSprite(80, 175, 0, 0, Csprite::DrawType_Transparent, RGB(255, 0, 255), TextBox3);
	textbox4.setSprite(80, 175, 0, 0, Csprite::DrawType_Transparent, RGB(255, 0, 255), TextBox4);
}

GUI::~GUI()
{
	CImagefile::Delete(mBgUi->BgUi);
	CImagefile::Delete(mTextBox->TextBox);
	CImagefile::Delete(mLocation_Box->Location_Box);
	// TODO: 여기 삭제할때 문제있음 꼭 확인할것!
}

void GUI::UIDraw(HDC hdc)
{
	mBgUi->bgui.Draw(hdc);
}

void GUI::PlayScreenUIDraw(HDC hdc)
{
	mPlayScreenUI->bgui.Draw(hdc);
}

void GUI::LocationDraw(HDC hdc, const WCHAR* location)
{
	mLocation_Box->location_box.Draw(hdc);
	TextOutW(hdc, 250, 185, location, 8);
}
//TODO: 줄의 갯수를 넘겨받아서 줄 갯수만큼 박스의 크기를 유동적으로 조절할것
void GUI::TextBoxDraw(HDC hdc)
{
	mTextBox->textbox.Draw(hdc);
}

void GUI::ScriptDraw(HDC hdc, int idx, ScriptZip Sczip)
{
	if(TextUnit == nullptr or TextUnit->Id != Sczip.scriptchar) 
		SetScriptUnit(Sczip.scriptchar);
	TextUnit->SetPosition(95, 190);
	TextUnit->ChangeAnimation(Sczip.script[4]);
	ChangeTextBox(Sczip);
	mTextBox->textbox.Draw(hdc);
	TextUnit->Draw(hdc);
	for (int i = 0; i < 4; i++)
	{
		TextOutW(hdc, 155, 189 + (i * 18), Sczip.script[i], 30);
	}
}

void GUI::ChangeTextBox(ScriptZip Sczip)
{
	int index = 0;
	for (int i = 0; i < 4; i++)
	{
		if (wcscmp(Sczip.script[i], Empty) == 0)
		{
			index = i;
			break;
		}
	}
	switch (index)
	{
	case 0:
		mTextBox->textbox = textbox4;
		break;
	case 1:
		mTextBox->textbox = textbox1;
		break;
	case 2:
		mTextBox->textbox = textbox2;
		break;
	case 3:
		mTextBox->textbox = textbox3;
		break;
	default:
		break;
	}
}
//TODO: 모든 등장인물을 넣을것(텍스트 대사를 치는)
void GUI::SetScriptUnit(int id)
{
	switch (id)
	{
	case IDB_ARES:
		TextUnit = new ARES;
		break;
	case IDB_AEKTER:
		TextUnit = new AEKTER;
		break;
	case IDB_AERAIN:
		TextUnit = new AERAIN;
		break;
	case IDB_GENELU:
		TextUnit = new GENELU;
		break;
	case IDB_GONRAD:
		TextUnit = new GONRAD;
		break;
	case IDB_GABI:
		TextUnit = new GABI;
		break;
	case IDB_KECK:
		TextUnit = new KECK;
		break;
	case IDB_SARK:
		TextUnit = new SARK;
		break;
	case IDB_ORASON:
		TextUnit = new ORASON;
		break;
	case IDB_LAIOS:
		TextUnit = new LAIOS;
		break;
	case IDB_MYSOLEN:
		TextUnit = new MYSOLEN;
		break;
	case IDB_MOLDRED:
		TextUnit = new MOLDRED;
		break;
	case IDB_MACGAIA:
		TextUnit = new MACGAIA;
		break;
	case IDB_OGG:
		TextUnit = new OGG;
		break;
	case IDB_MAREAM:
		TextUnit = new MAREAM;
		break;
	case IDB_THYHOOT:
		TextUnit = new THYHOOT;
		break;
	case IDB_ARCHBISHOP:
		TextUnit = new ARCHBISHOP;
		break;
	case IDB_GENERAL:
		TextUnit = new GENERAL;
		break;
	case IDB_HORSE_GENERAL:
		TextUnit = new HORSE_GENERAL;
		break;
	case IDB_HORSE_AEKTER:
		TextUnit = new HORSE_AEKTER;
		break;
	case IDB_SOLDIER5:
		TextUnit = new SOLDIER5;
		break;
	case IDB_SOLDIER2:
		TextUnit = new SOLDIER2;
		break;
	case IDB_GARRARD:
		TextUnit = new GARRARD;
		break;
	case IDB_RADINKAL:
		TextUnit = new RADINKAL;
		break;
	case IDB_ALFRED:
		TextUnit = new ALFRED;
		break;
	default:
		break;
	}
	
}


