#include "pch.h"
#include "resource.h"
#include "PlayMenuUI.h"


PlayMenuUI::PlayMenuUI()
{
	mIcon = new MenuIcon[9];


	mIcon[0].Img = CImagefile::New(RESOURCE_NAME(IDB_PLAYMENU));
	mIcon[0].sprite.setSprite(0, 0, 0, 0, Csprite::DrawType_Draw, RGB(255, 0, 255), mIcon[0].Img);
	mIcon[0].text = L"None";

	mIcon[1].Img = CImagefile::New(RESOURCE_NAME(IDB_PLAYMENU_TIMELAPSE));
	mIcon[1].sprite.setSprite(64, 64, 0, 0, Csprite::DrawType_Draw, RGB(255, 0, 255), mIcon[1].Img);
	mIcon[1].text = L"시간경과";

	mIcon[2].Img = CImagefile::New(RESOURCE_NAME(IDB_PLAYMENU_UNITMOVE));
	mIcon[2].sprite.setSprite(96, 64, 0, 0, Csprite::DrawType_Draw, RGB(255, 0, 255), mIcon[2].Img);
	mIcon[2].text = L"부대이동";

	mIcon[3].Img = CImagefile::New(RESOURCE_NAME(IDB_PLAYMENU_SEARCH));
	mIcon[3].sprite.setSprite(128, 64, 0, 0, Csprite::DrawType_Draw, RGB(255, 0, 255), mIcon[3].Img);
	mIcon[3].text = L"탐색";

	mIcon[4].Img = CImagefile::New(RESOURCE_NAME(IDB_PLAYMENU_DIPLOMACY));
	mIcon[4].sprite.setSprite(160, 64, 0, 0, Csprite::DrawType_Draw, RGB(255, 0, 255), mIcon[4].Img);
	mIcon[4].text = L"외교";

	mIcon[5].Img = CImagefile::New(RESOURCE_NAME(IDB_PLAYMENU_ORGANIZATION));
	mIcon[5].sprite.setSprite(64, 96, 0, 0, Csprite::DrawType_Draw, RGB(255, 0, 255), mIcon[5].Img);
	mIcon[5].text = L"편성";

	mIcon[6].Img = CImagefile::New(RESOURCE_NAME(IDB_PLAYMENU_INFO));
	mIcon[6].sprite.setSprite(96, 96, 0, 0, Csprite::DrawType_Draw, RGB(255, 0, 255), mIcon[6].Img);
	mIcon[6].text = L"정보";

	mIcon[7].Img = CImagefile::New(RESOURCE_NAME(IDB_PLAYMENU_METHOD));
	mIcon[7].sprite.setSprite(128, 96, 0, 0, Csprite::DrawType_Draw, RGB(255, 0, 255), mIcon[7].Img);
	mIcon[7].text = L"표기방식";

	mIcon[8].Img = CImagefile::New(RESOURCE_NAME(IDB_PLAYMENU_RECORD));
	mIcon[8].sprite.setSprite(160, 96, 0, 0, Csprite::DrawType_Draw, RGB(255, 0, 255), mIcon[8].Img);
	mIcon[8].text = L"기록";

	for (int i = 1;i < 9;i++)
		mIcon[i].sprite.IconChange(1);


	
}

PlayMenuUI::~PlayMenuUI()
{

}

bool PlayMenuUI::Is마우스가내안에(int mouse_x, int mouse_y)
{
	if (GetPosX() <= mouse_x && mouse_x <= GetPosX() + Size_x
		&& GetPosY() <= mouse_y && mouse_y <= GetPosY() + Size_y)
	{
		return true;
	}
	return false;
}
int PlayMenuUI::GetPosX()
{
	return pScreen->posX;
}
int PlayMenuUI::GetPosY()
{
	return pScreen->posY;
}
//
//bool PlayMenuUI::Is마우스가내안에(int mouse_x, int mouse_y)
//{
//	if (GetPosX() <= mouse_x and mouse_x <= GetPosX() + Size_x 
//		and GetPosY() <= mouse_y and mouse_y <= GetPosY()+Size_y)
//	{
//		return true;
//	}
//	return false;
//}

void PlayMenuUI::OnMouseMove(int mouse_x, int mouse_y)
{
	int sx = mouse_x - GetPosX();
	int sy = mouse_y - GetPosY();

	if (CurIcon != SelectNothing) mIcon[CurIcon].sprite.IconChange(1);
	if (sy > 63 && sy < 96)
	{
		if (sx > 63 && sx < 96) CurIcon = Timelapse;
		else if (sx >= 96 && sx < 128) CurIcon = Unitmove;
		else if (sx >= 128 && sx < 160)
		{
			CurIcon = Search;
			OutputDebugStringW(L"탐색\n");
		}
		else if (sx >= 160 && sx < 192)
		{
			CurIcon = Diplomacy;
			OutputDebugStringW(L"외교\n");
		}
		else CurIcon = SelectNothing;
	}
	else if (sy >= 96 && sy < 128)
	{
		if (sx > 63 && sx < 96) CurIcon = Organization;
		else if (sx >= 96 && sx < 128) CurIcon = Info;
		else if (sx >= 128 && sx < 160) CurIcon = Method;
		else if (sx >= 160 && sx < 192) CurIcon = Record;
		else CurIcon = SelectNothing;
	}
	else 
		CurIcon = SelectNothing;

	if (CurIcon != SelectNothing) mIcon[CurIcon].sprite.IconChange(2);
}

bool PlayMenuUI::OnMouseDown(int mouse_x, int mouse_y, int left_right)
{
	int sx = mouse_x - GetPosX();
	int sy = mouse_y - GetPosY();
	if (CurIcon != SelectNothing && left_right == 1)
	{
		mIcon[CurIcon].sprite.IconChange(3);
		return true;
	}
	return false;
}

//void PlayMenuUI::MoveScreen()
//{
//
//}

void PlayMenuUI::Draw(HDC hdc)
{
	for (int i = 0;i < 9;i++)
		mIcon[i].sprite.Draw(hdc);
	if (CurIcon != SelectNothing)
		TextOutW(hdc, 128, 190, mIcon[CurIcon].text, wcslen(mIcon[CurIcon].text));
}
 