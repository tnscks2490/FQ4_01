#include "pch.h"
#include "CMap.h"
#include "GUI.h"
#include "CTileMap.h"
#include "CScreen.h"
#include "CGameFQ4.h"
#include "KarionCastle_KingRoom.h"

extern CGameFQ4 game;

KarionCastle_KingRoom::KarionCastle_KingRoom()
{
	KC_KR = new CMap(RESOURCE_NAME(IDB_KARIONCASTLE_KINGROOM));

	UI = new GUI(L"KarionCastle_KingRoom");
	mTileMap = new CTileMap(KC_KR->BackGroundMap->Width() / 
		16, KC_KR->BackGroundMap->Height() / 16, KC_KR);

	mTileMap->PlayUnit = new CTileUnit();
	ares = new ARES;
	mTileMap->CreateTileUnit(ares, 19, 28, A_SOLDIER, PLAYER);
	mTileMap->PlayUnit = mTileMap->mTileUnits[0];

	ares->ChangeAnimation(L"Char_FSUS");

	mTileMap->LoadFromFile(L"MapData\\KarionCastle_KingRoom.bin");
	KC_KR->CameraPosSetting(16, 208);
}

KarionCastle_KingRoom::~KarionCastle_KingRoom()
{
}


bool KarionCastle_KingRoom::IsFinished()
{
    return false;
}

void KarionCastle_KingRoom::onFrameMove()
{
}

void KarionCastle_KingRoom::onDraw(HDC hdc)
{
	CScreen PlayScreen(hdc, 640, 336);
	UI->UIDraw(hdc);

	KC_KR->mScreen.mdestX = 16;
	KC_KR->mScreen.mdestY = 16;
	KC_KR->Draw(PlayScreen.m_HDC);

	mTileMap->PlayUnitDraw(PlayScreen.m_HDC, KC_KR);

	if (TileDrawON) mTileMap->TileDraw(PlayScreen.m_HDC, KC_KR);

	UI->PlayScreenUIDraw(PlayScreen.m_HDC);

	PlayScreen.Draw(hdc, 0, 32, 640, 336);
}

void KarionCastle_KingRoom::onMouseDown(UINT x, UINT y, UINT left_right)
{
	int xx = (KC_KR->CameraX / 16);
	int yy = (KC_KR->CameraY / 16);

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

void KarionCastle_KingRoom::onMouseMove(UINT x, UINT y)
{
}

void KarionCastle_KingRoom::onKeyDown(KeyInput* virtual_key)
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
			mTileMap->SaveToFile(L"MapData\\KarionCastle_KingRoom.bin");
		}
		else
		{
			TileDrawON = true;
			mTileMap->LoadFromFile(L"MapData\\KarionCastle_KingRoom.bin");
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
			if (UnitPos.x == KarionKingRoom[i].x && UnitPos.y == KarionKingRoom[i].y)
				MoveMap(KarionKingRoom[i].MoveMapName);
		}
	}
}

void KarionCastle_KingRoom::MoveMap(std::wstring mapName)
{
	if (mapName == L"KarionCastle_Hall")
	{
		CTileUnit* PlayTUnit = CApplication::pGame->mKarionCastle_Hall->mTileMap->PlayUnit;
		CApplication::pGame->NextScene = CApplication::pGame->mKarionCastle_Hall;
		CApplication::pGame->mKarionCastle_Hall->SendPosInfo(PlayTUnit, 39, 9);

	}
	else if (mapName == L"KarionCastle_Altar")
	{
		CTileUnit* PlayTUnit = CApplication::pGame->mKarionCastle_Altar->mTileMap->PlayUnit;
		CApplication::pGame->NextScene = CApplication::pGame->mKarionCastle_Altar;
		CApplication::pGame->mKarionCastle_Altar->SendPosInfo(PlayTUnit, 67, 20);
	}
}

void KarionCastle_KingRoom::SendPosInfo(CTileUnit* PlayTUnit, int x, int y)
{
	this->KC_KR->CM->CameraPosSet(x, y);
	mTileMap->SetTUnit(PlayTUnit, POS(x, y));
	PlayTUnit->unit->ChangeAnimation(L"Char_FSUS");
}


