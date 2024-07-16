#include "pch.h"
#include "CMap.h"
#include "GUI.h"
#include "CTileMap.h"
#include "CScreen.h"
#include "CGameFQ4.h"
#include "CameraManagement.h"
#include "KarionCastle_Hall.h"

extern CGameFQ4 game;

KarionCastle_Hall::KarionCastle_Hall()
{
	KC_Hall = new CMap(RESOURCE_NAME(IDB_KARIONCASTLE_HALL));
	KC_Hall->mScreen.mdestX = 16;
	KC_Hall->mScreen.mdestY = 16;
 	UI = new GUI(L"KarionCastle_Hall");
	mTileMap = new CTileMap(KC_Hall->BackGroundMap->Width()/16, 
		KC_Hall->BackGroundMap->Height()/16, KC_Hall);

	mTileMap->PlayUnit = new CTileUnit();
	ares = new ARES;
	mTileMap->CreateTileUnit(ares,10, 10, A_SOLDIER,PLAYER);
	mTileMap->PlayUnit = mTileMap->mTileUnits[0];

	ares->ChangeAnimation(L"Char_FSUS");
	KC_Hall->CM->CameraPosSet(10, 10);
	mTileMap->LoadFromFile(L"MapData\\KarionCastle_Hall.bin");
 }

KarionCastle_Hall::~KarionCastle_Hall()
{
	delete KC_Hall;
	delete ares;
	delete UI;
	delete mTileMap;

}

bool KarionCastle_Hall::IsFinished()
{
	return false;
}

void KarionCastle_Hall::onFrameMove()
{
}

void KarionCastle_Hall::onDraw(HDC hdc)
{
	CScreen PlayScreen(hdc,640,336);
	UI->UIDraw(hdc);


	KC_Hall->Draw(PlayScreen.m_HDC);

	mTileMap->PlayUnitDraw(PlayScreen.m_HDC,KC_Hall);

	if(TileDrawON) mTileMap->TileDraw(PlayScreen.m_HDC,KC_Hall);

	UI->PlayScreenUIDraw(PlayScreen.m_HDC);

	PlayScreen.Draw(hdc, 0, 32, 640, 336);
}

void KarionCastle_Hall::onMouseDown(UINT x, UINT y, UINT left_right)
{
	int xx = (KC_Hall->CameraX /16) ;
	int yy = (KC_Hall->CameraY /16) ;

	if (TileDrawON)
	{
		if (left_right == 1)
		{
			if (mTileMap->GetTile(xx + ((x) / 16) - 1, yy + ((y) / 16) - 3).isMove)
				mTileMap->GetTile(xx + ((x) / 16) - 1, yy + ((y) / 16) - 3).isMove = false;
			else if (mTileMap->GetTile(xx + ((x) / 16) - 1, yy + ((y) / 16) - 3).isMove == false)
				mTileMap->GetTile(xx + ((x) / 16) - 1, yy + ((y) / 16) - 3).isMove = true;
		}
		else if (left_right == 2)
		{
			mTileMap->GetTile(xx + (x / 16) - 1, yy + (y / 16) - 3).EventTrigger++;
			mTileMap->GetTile(xx + (x / 16) - 1, yy + (y / 16) - 3).EventTrigger %= 4;
		}
	}


	char str[100];
	sprintf_s(str, 100, "Tile Pos : %d, %d \n Tile Move : %d \n Tile Event : %d\n", 
		xx + (x / 16) - 1, yy + (y / 16) - 3,mTileMap->GetTile(xx + (x / 16) - 1, yy + (y / 16) - 3).isMove, mTileMap->GetTile(xx + (x / 16) - 1, yy + (y / 16) - 3).EventTrigger);
	OutputDebugStringA(str);

}

void KarionCastle_Hall::onMouseMove(UINT x, UINT y)
{

}

void KarionCastle_Hall::onKeyDown(KeyInput* virtual_key)
{
	switch (virtual_key->KeyDownkey)
	{
	case VK_SPACE:
		break;
	case 98:
		mTileMap->MoveTUnit(mTileMap->PlayUnit, DOWN);
		break;
	case 100:
		mTileMap->MoveTUnit(mTileMap->PlayUnit, LEFT);
		break;
	case 102:
		mTileMap->MoveTUnit(mTileMap->PlayUnit, RIGHT);
		break;
	case 104:
		mTileMap->MoveTUnit(mTileMap->PlayUnit, UP);
		break;
	case 80:
		if (TileDrawON)
		{
			TileDrawON = false;
			mTileMap->SaveToFile(L"MapData\\KarionCastle_Hall.bin");
		}
		else
		{
			TileDrawON = true;
			mTileMap->LoadFromFile(L"MapData\\KarionCastle_Hall.bin");
		}
		break;
	default:
		break;
	}
	// 직접 조종하는 플레이어블 캐릭터의 위치가 다른 맵으로 이동하는 곳일 경우 !!


	//InputKey = virtual_key;

	POS UnitPos(mTileMap->PlayUnit->mPosition.x, mTileMap->PlayUnit->mPosition.y);

	if (mTileMap->GetTile(UnitPos.x, UnitPos.y).EventTrigger == 3)
	{
		for (int i = 0; i < 20; i++)
		{
			if (UnitPos.x == KarionHall[i].x and UnitPos.y == KarionHall[i].y)
				MoveMap(KarionHall[i].MoveMapName);
		}
		
	}	
}

void KarionCastle_Hall::MoveMap(std::wstring mapName)
{
	if (mapName == L"KarionCastle_MeetingRoom")
	{
		CTileUnit* PlayTUnit = CApplication::pGame->mKarionCastle_MeetingRoom->mTileMap->PlayUnit;
		CApplication::pGame->NextScene = CApplication::pGame->mKarionCastle_MeetingRoom;
		CApplication::pGame->mKarionCastle_MeetingRoom->SendPosInfo(PlayTUnit, 19, 28);
	}
	else if (mapName == L"KarionCastle_Lab")
	{
		CTileUnit* PlayTUnit = CApplication::pGame->mKarionCastle_Lab->mTileMap->PlayUnit;
		CApplication::pGame->NextScene = CApplication::pGame->mKarionCastle_Lab;
		CApplication::pGame->mKarionCastle_Lab->SendPosInfo(PlayTUnit, 19, 28);
	}
	else if (mapName == L"KarionCastle_KingRoom")
	{
		CTileUnit* PlayTUnit = CApplication::pGame->mKarionCastle_KingRoom->mTileMap->PlayUnit;
		CApplication::pGame->NextScene = CApplication::pGame->mKarionCastle_KingRoom;
		CApplication::pGame->mKarionCastle_KingRoom->SendPosInfo(PlayTUnit, 19, 28);

	}
	else if (mapName == L"KarionCastle_AresRoom")
	{
		CTileUnit* PlayTUnit = CApplication::pGame->mKarionCastle_AresRoom->mTileMap->PlayUnit;
		CApplication::pGame->NextScene = CApplication::pGame->mKarionCastle_AresRoom;
		CApplication::pGame->mKarionCastle_AresRoom->SendPosInfo(PlayTUnit, 10, 8);

	}
	else if (mapName == L"KarionCastle_Armory")
	{
		CTileUnit* PlayTUnit = CApplication::pGame->mKarionCastle_Armory->mTileMap->PlayUnit;
		CApplication::pGame->NextScene = CApplication::pGame->mKarionCastle_Armory;
		CApplication::pGame->mKarionCastle_Armory->SendPosInfo(PlayTUnit, 19, 28);

	}
	else if (mapName == L"KarionCastle_Outside")
	{
		CTileUnit* PlayTUnit = CApplication::pGame->mKarionCastle_Outside->mTileMap->PlayUnit;
		CApplication::pGame->NextScene = CApplication::pGame->mKarionCastle_Outside;
		CApplication::pGame->mKarionCastle_Outside->SendPosInfo(PlayTUnit, 44, 96);
	}
	
}

void KarionCastle_Hall::SendPosInfo(CTileUnit* PlayTUnit, int x, int y)
{
	this->KC_Hall->CM->CameraPosSet(x, y);
	mTileMap->SetTUnit(PlayTUnit, POS(x,y));
	PlayTUnit->unit->ChangeAnimation(L"Char_FSUS");
}
