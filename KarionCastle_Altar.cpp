#include "pch.h"
#include "CMap.h"
#include "GUI.h"
#include "CTileMap.h"
#include "CScreen.h"
#include "CGameFQ4.h"
#include "CameraManagement.h"
#include "KarionCastle_Altar.h"

extern CGameFQ4 game;

KarionCastle_Altar::KarionCastle_Altar()
{
	KC_AL = new CMap(RESOURCE_NAME(IDB_KARIONCASTLE_ALTAR));

	UI = new GUI(L"KarionCastle_Altar");
	mTileMap = new CTileMap(KC_AL->BackGroundMap->Width() / 16,
		KC_AL->BackGroundMap->Height() / 16, KC_AL);

	mTileMap->PlayUnit = new CTileUnit();
	ares = new ARES;
	mTileMap->CreateTileUnit(ares, 19, 49, A_SOLDIER, PLAYER);
	mTileMap->PlayUnit = mTileMap->mTileUnits[0];

	ares->ChangeAnimation(L"Char_FSUS");
	KC_AL->CM->CameraPosSet(19, 49);
    mTileMap->LoadFromFile(L"MapData\\KarionCastle_Altar.bin");
}

KarionCastle_Altar::~KarionCastle_Altar()
{
	delete KC_AL;
	delete ares;
	delete UI;
	delete mTileMap;
}

bool KarionCastle_Altar::IsFinished()
{
	return false;
}

void KarionCastle_Altar::onFrameMove()
{
}

void KarionCastle_Altar::onDraw(HDC hdc)
{
	CScreen PlayScreen(hdc, 640, 336);
	UI->UIDraw(hdc);

	KC_AL->mScreen.mdestX = 16;
	KC_AL->mScreen.mdestY = 16;
	KC_AL->Draw(PlayScreen.m_HDC);

	mTileMap->PlayUnitDraw(PlayScreen.m_HDC, KC_AL);

	if (TileDrawON) mTileMap->TileDraw(PlayScreen.m_HDC, KC_AL);

	UI->PlayScreenUIDraw(PlayScreen.m_HDC);

	PlayScreen.Draw(hdc, 0, 32, 640, 336);
}

void KarionCastle_Altar::onMouseDown(UINT x, UINT y, UINT left_right)
{
	int xx = (KC_AL->CameraX / 16);
	int yy = (KC_AL->CameraY / 16);

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

void KarionCastle_Altar::onMouseMove(UINT x, UINT y)
{
}

void KarionCastle_Altar::onKeyDown(KeyInput* virtual_key)
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
			mTileMap->SaveToFile(L"MapData\\KarionCastle_Altar.bin");
		}
		else
		{
			TileDrawON = true;
			mTileMap->LoadFromFile(L"MapData\\KarionCastle_Altar.bin");
		}
		break;
	default:
		break;
	}
	// 직접 조종하는 플레이어블 캐릭터의 위치가 다른 맵으로 이동하는 곳일 경우 !!


	POS UnitPos(mTileMap->PlayUnit->mPosition.x, mTileMap->PlayUnit->mPosition.y);

	if (mTileMap->GetTile(UnitPos.x, UnitPos.y).EventTrigger == 3)
	{
		for (int i = 0; i < 20; i++)
		{
			if (UnitPos.x == KarionAltar[i].x and UnitPos.y == KarionAltar[i].y)
				MoveMap(KarionAltar[i].MoveMapName);
		}

	}
}

void KarionCastle_Altar::MoveMap(std::wstring mapName)
{
	if (mapName == L"KarionCastle_KingRoom")
	{
		CTileUnit* PlayTUnit = CApplication::pGame->mKarionCastle_KingRoom->mTileMap->PlayUnit;
		CApplication::pGame->NextScene = CApplication::pGame->mKarionCastle_KingRoom;
		CApplication::pGame->mKarionCastle_KingRoom->SendPosInfo(PlayTUnit, 27, 9);
	}
}

void KarionCastle_Altar::SendPosInfo(CTileUnit* PlayTUnit, int x, int y)
{
}


