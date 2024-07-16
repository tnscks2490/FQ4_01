#include "pch.h"
#include "ActionMenuUI.h"

ActionMenuUI::ActionMenuUI()
{
	
    mIcon = new AMenuIcon[3];
	
	mIcon[0].Img = CImagefile::New(RESOURCE_NAME(IDB_ACTION_MENU));
	mIcon[0].sprite.setSprite(0, 0, 0, 0, Csprite::DrawType_Transparent, RGB(255, 0, 255), mIcon[0].Img);

	mIcon[1].Img = CImagefile::New(RESOURCE_NAME(IDB_PLAYMENU_INFO));
	mIcon[1].sprite.setSprite(192, 0, 0, 0, Csprite::DrawType_Draw, RGB(255, 0, 255), mIcon[1].Img);

	mIcon[2].Img = CImagefile::New(RESOURCE_NAME(IDB_PLAYMENU_EXIT));
	mIcon[2].sprite.setSprite(224, 0, 0, 0, Csprite::DrawType_Draw, RGB(255, 0, 255), mIcon[2].Img);	
	
	for (int i = 1;i < 3;i++)
		mIcon[i].sprite.IconChange(1);

	//////////////////////////////////////////////////////////
	//     위는 상시 아이콘 아래는 해당 창에 관한 아이콘    //
	//////////////////////////////////////////////////////////
	
	CImagefile* img = CImagefile::New(RESOURCE_NAME(IDB_ACTION_MENU_ICON));

	mMenu = new AMenu[4];
	
	for (int i = 0;i < 4;i++)
	{
		mMenu[i].sprite.setSprite(0, 0, 0, 0,
			Csprite::DrawType_Draw, RGB(255, 0, 255), img);
		mMenu[i].sprite.AIconChange(i);
	}
    
	mMenu[0].text = L"이동부대를 일람표와";
	mMenu[0].text2 = L"맵에서 선택해 주세요";

	mMenu[1].text = L"부대를 일람표와 맵에서";
	mMenu[1].text2 = L"선택해 주세요";

	mMenu[2].text = L"외교부대를 일람표와";
	mMenu[2].text2 = L"맵에서 선택해 주세요";

	mMenu[3].text = L"부대를 일람표와 맵에서";
	mMenu[3].text2 = L"선택해 주세요";
}

ActionMenuUI::~ActionMenuUI()
{
}

bool ActionMenuUI::Is마우스가내안에(int mouse_x, int mouse_y)
{
	if (GetPosX() <= mouse_x and mouse_x <= GetPosX() + Size_x
		and GetPosY() <= mouse_y and mouse_y <= GetPosY() + Size_y)
	{
		return true;
	}
	return false;
}

int ActionMenuUI::GetPosX()
{
	return pScreen->posX;
}

int ActionMenuUI::GetPosY()
{
	return pScreen->posY;
}


void ActionMenuUI::OnMouseMove(int mouse_x, int mouse_y)
{
	int sx = mouse_x - GetPosX();
	int sy = mouse_y - GetPosY();

	if (CurIcon != SelectNothing) mIcon[CurIcon].sprite.IconChange(1);
	if (sy >= 0 and sy <= 32)
	{
		if (sx >= 192 and sx < 224) CurIcon = Info;
		else if (sx >= 224 and sx < 256) CurIcon = Exit;
		else CurIcon = SelectNothing;
	}
	else
		CurIcon = SelectNothing;
	
	switch (CurIcon)
	{
	case SelectNothing:
	{
		mIcon[1].sprite.IconChange(1);
		mIcon[2].sprite.IconChange(1);
	}
		break;
	case Info:
		mIcon[1].sprite.IconChange(2);
		mIcon[2].sprite.IconChange(1);
		break;
	case Exit:
		mIcon[1].sprite.IconChange(1);
		mIcon[2].sprite.IconChange(2);
		break;
	default:
		break;
	}

	
}

bool ActionMenuUI::OnMouseDown(int mouse_x, int mouse_y, int left_right)
{
	int sx = mouse_x - GetPosX();
	int sy = mouse_y - GetPosY();
	if (CurIcon != SelectNothing and left_right == 1)
	{
		mIcon[CurIcon].sprite.IconChange(2);
		return true;
	}
	return false;
}

void ActionMenuUI::MoveScreen()
{

}

void ActionMenuUI::CVIcon_PMUIToAMUI(int SelectAct)
{
	switch (SelectAct)
	{
	case SelectNothing:
		break;
	case Timelapse:
		break;
	case Unitmove:
		CurAction = um;
		break;
	case Search:
		CurAction = se;
		break;
	case Diplomacy:
		CurAction = di;
		break;
	case Organization:
		CurAction = oz;
		break;
	case Info:
		break;
	case Method:
		break;
	case Record:
		break;
	case Exit:
		break;
	default:
		break;
	}
}


void ActionMenuUI::Draw(HDC hdc)
{
	for (int i = 0;i < 3;i++)
		mIcon[i].sprite.Draw(hdc);

	mMenu[CurAction].sprite.Draw(hdc);
	TextOutW(hdc, 32, 45, mMenu[CurAction].text,
		wcslen(mMenu[CurAction].text));
	TextOutW(hdc, 32, 65, mMenu[CurAction].text2,
		wcslen(mMenu[CurAction].text2));
}
