#include "pch.h"
#include "CMap.h"
#include "GUI.h"
#include "CTileMap.h"
#include "CScreen.h"
#include "CGameFQ4.h"
#include "CameraManagement.h"
#include "KarionCastle_AresRoom.h"

extern CGameFQ4 game;

KarionCastle_AresRoom::KarionCastle_AresRoom()
{
	KC_AR = new CMap(RESOURCE_NAME(IDB_KARIONCASTLE_ARESROOM));
	UI = new GUI(L"KarionCastle_AresRoom");
	KC_AR->mScreen.mdestX = 16;
	KC_AR->mScreen.mdestY = 16;
	mTileMap = new CTileMap(KC_AR->BackGroundMap->Width() /
		16, KC_AR->BackGroundMap->Height() / 16, KC_AR);

	mTileMap->PlayUnit = new CTileUnit();
	ares = new ARES;
	mTileMap->CreateTileUnit(ares, 10, 8, A_SOLDIER, PLAYER);
	mTileMap->PlayUnit = mTileMap->mTileUnits[0];

	ares->ChangeAnimation(L"Char_FSUS");
	KC_AR->CM->CameraPosSet(10, 8);
	mTileMap->LoadFromFile(L"MapData\\KarionCastle_AresRoom.bin");
}

KarionCastle_AresRoom::~KarionCastle_AresRoom()
{
	delete KC_AR;
	delete ares;
	delete UI;
	delete mTileMap;
}

bool KarionCastle_AresRoom::IsFinished()
{
    return false;
}

void KarionCastle_AresRoom::onFrameMove()
{
}

void KarionCastle_AresRoom::onDraw(HDC hdc)
{
	CScreen PlayScreen(hdc, 640, 336);
	UI->UIDraw(hdc);

	KC_AR->Draw(PlayScreen.m_HDC);

	mTileMap->PlayUnitDraw(PlayScreen.m_HDC, KC_AR);

	if (TileDrawON) mTileMap->TileDraw(PlayScreen.m_HDC, KC_AR);

	UI->PlayScreenUIDraw(PlayScreen.m_HDC);

	PlayScreen.Draw(hdc, 0, 32, 640, 336);
}

void KarionCastle_AresRoom::onMouseDown(UINT x, UINT y, UINT left_right)
{
	int xx = (KC_AR->CameraX / 16);
	int yy = (KC_AR->CameraY / 16);

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
		xx + (x / 16) - 1, yy + (y / 16) - 3, mTileMap->GetTile(xx + (x / 16) - 1, yy + (y / 16) - 3).isMove, mTileMap->GetTile(xx + (x / 16) - 1, yy + (y / 16) - 3).EventTrigger);
	OutputDebugStringA(str);
}

void KarionCastle_AresRoom::onMouseMove(UINT x, UINT y)
{
}

void KarionCastle_AresRoom::onKeyDown(KeyInput* virtual_key)
{
	switch (virtual_key->KeyDownkey)
	{
	case 32:
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
			mTileMap->SaveToFile(L"MapData\\KarionCastle_AresRoom.bin");
			 
		}
		else
		{
			TileDrawON = true;
			mTileMap->LoadFromFile(L"MapData\\KarionCastle_AresRoom.bin");
		}
		break;
	default:
		break;
	}
	// 직접 조종하는 플레이어블 캐릭터의 위치가 다른 맵으로 이동하는 곳일 경우 !!
	POS UnitPos(mTileMap->PlayUnit->mPosition.x, mTileMap->PlayUnit->mPosition.y);

	if (mTileMap->GetTile(UnitPos.x, UnitPos.y).EventTrigger == 3)
	{
		for (int i = 0; i < 8; i++)
		{
			if (UnitPos.x == KarionAresRoom[i].x && UnitPos.y == KarionAresRoom[i].y)
				MoveMap(KarionAresRoom[i].MoveMapName);
		}
	}
}

void KarionCastle_AresRoom::MoveMap(std::wstring mapName)
{
	if (mapName == L"KarionCastle_Hall")
	{
		CTileUnit* PlayTUnit = CApplication::pGame->mKarionCastle_Hall->mTileMap->PlayUnit;
		CApplication::pGame->NextScene = CApplication::pGame->mKarionCastle_Hall;
		CApplication::pGame->mKarionCastle_Hall->SendPosInfo(PlayTUnit, 67, 9);
	}
	else if (mapName == L"KarionCastle_Outside")
	{
		CTileUnit* PlayTUnit = CApplication::pGame->mKarionCastle_Outside->mTileMap->PlayUnit;
		CApplication::pGame->NextScene = CApplication::pGame->mKarionCastle_Outside;
		CApplication::pGame->mKarionCastle_Outside->SendPosInfo(PlayTUnit, 56, 73);
	}
	//바깥으로 나가는 코드 추가할것!
}

void KarionCastle_AresRoom::SendPosInfo(CTileUnit* PlayTUnit, int x, int y)
{
	this->KC_AR->CM->CameraPosSet(x, y);
	mTileMap->SetTUnit(PlayTUnit, POS(x, y));
	PlayTUnit->unit->ChangeAnimation(L"Char_FSUS");
}


