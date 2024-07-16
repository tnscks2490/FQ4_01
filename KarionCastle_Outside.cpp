#include "pch.h"
#include "CMap.h"
#include "GUI.h"
#include "CTileMap.h"
#include "CScreen.h"
#include "CGameFQ4.h"
#include "CameraManagement.h"
#include "KarionCastle_Outside.h"

extern CGameFQ4 game;

KarionCastle_Outside::KarionCastle_Outside()
{
 	KC_OS = new CMap(RESOURCE_NAME(IDB_KARIONCASTLE_OUTSIDE));
	KC_OS->mScreen.mdestX = 16;
	KC_OS->mScreen.mdestY = 16;
	UI = new GUI(L"KarionCastle_OutSide");
	mTileMap = new CTileMap(KC_OS->BackGroundMap->Width() / 16,
		KC_OS->BackGroundMap->Height() / 16, KC_OS);

	mTileMap->PlayUnit = new CTileUnit();
	ares = new ARES;
	mTileMap->CreateTileUnit(ares, 10, 10, A_SOLDIER, PLAYER);
	mTileMap->PlayUnit = mTileMap->mTileUnits[0];

	ares->ChangeAnimation(L"Char_FSUS");
	KC_OS->CM->CameraPosSet(10, 10);
	mTileMap->LoadFromFile(L"MapData\\KarionCastle_Outside.bin");
}

KarionCastle_Outside::~KarionCastle_Outside()
{
	delete KC_OS;
	delete ares;
	delete UI;
	delete mTileMap;
}

void KarionCastle_Outside::MoveMap(std::wstring mapName)
{
	if (mapName == L"KarionCastle_AresRoom")
	{
		CTileUnit* PlayTUnit = CApplication::pGame->mKarionCastle_AresRoom->mTileMap->PlayUnit;
		CApplication::pGame->NextScene = CApplication::pGame->mKarionCastle_AresRoom;
		CApplication::pGame->mKarionCastle_AresRoom->SendPosInfo(PlayTUnit, 19, 27);
	}
	if (mapName == L"KarionCastle_Hall")
	{
		CTileUnit* PlayTUnit = CApplication::pGame->mKarionCastle_Hall->mTileMap->PlayUnit;
		CApplication::pGame->NextScene = CApplication::pGame->mKarionCastle_Hall;
		CApplication::pGame->mKarionCastle_Hall->SendPosInfo(PlayTUnit, 19,28);
	}
}

void KarionCastle_Outside::SendPosInfo(CTileUnit* PlayTUnit, int x, int y)
{
	this->KC_OS->CM->CameraPosSet(x, y);
	mTileMap->SetTUnit(PlayTUnit, POS(x, y));
	PlayTUnit->unit->ChangeAnimation(L"Char_FSUS");
}


bool KarionCastle_Outside::IsFinished()
{
	return false;
}

void KarionCastle_Outside::onFrameMove()
{
}

void KarionCastle_Outside::onDraw(HDC hdc)
{
	CScreen PlayScreen(hdc, 640, 336);
	UI->UIDraw(hdc);
	KC_OS->Draw(PlayScreen.m_HDC);
	
	mTileMap->PlayUnitDraw(PlayScreen.m_HDC, KC_OS);

	if (TileDrawON) mTileMap->TileDraw(PlayScreen.m_HDC, KC_OS);

	UI->PlayScreenUIDraw(PlayScreen.m_HDC);

	if (IsOutMap) UI->LocationDraw(PlayScreen.m_HDC, L"... 주둔합니다 ...");

	PlayScreen.Draw(hdc, 0, 32, 640, 336);
}

void KarionCastle_Outside::onMouseDown(UINT x, UINT y, UINT left_right)
{
	int xx = (KC_OS->CameraX / 16);
	int yy = (KC_OS->CameraY / 16);

	int sx = KC_OS->mScreen.mdestX / 16;
	int sy = KC_OS->mScreen.mdestY / 16;

	if (TileDrawON)
	{
		if (left_right == 1)
		{
			if (mTileMap->GetTile(xx + ((x) / 16) - sx, yy + ((y) / 16) - sy-2).isMove)
				mTileMap->GetTile(xx + ((x) / 16) - sx, yy + ((y) / 16) - sy -2).isMove = false;
			else if (mTileMap->GetTile(xx + ((x) / 16) - sx, yy + ((y) / 16) -sy -2 ).isMove == false)
				mTileMap->GetTile(xx + ((x) / 16) - sx, yy + ((y) / 16) - sy-2).isMove = true;
		}
		else if (left_right == 2)
		{
			mTileMap->GetTile(xx + (x / 16) - sx, yy + (y / 16) - sy-2).EventTrigger++;
			mTileMap->GetTile(xx + (x / 16) - sx, yy + (y / 16) - sy-2).EventTrigger %= 4;
		}
	}

	if (IsOutMap)
	{
		IsOutMap = false;
		CApplication::pGame->NextScene = CApplication::pGame->mPlayMain;
	}

	char str[100];
	sprintf_s(str, 100, "Tile Pos : %d, %d \n Tile Move : %d \n Tile Event : %d\n",
		xx + (x / 16) - sx, yy + (y / 16) - sy - 2, mTileMap->GetTile(xx + (x / 16) - sx, yy + (y / 16) - sy - 2).isMove, mTileMap->GetTile(xx + (x / 16) - sx, yy + (y / 16) - sy - 2).EventTrigger);
	OutputDebugStringA(str);
}

void KarionCastle_Outside::onMouseMove(UINT x, UINT y)
{
}

void KarionCastle_Outside::onKeyDown(KeyInput* virtual_key)
{
	if (!IsOutMap)
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
				mTileMap->SaveToFile(L"MapData\\KarionCastle_Outside.bin");
			}
			else
			{
				TileDrawON = true;
				mTileMap->LoadFromFile(L"MapData\\KarionCastle_Outside.bin");
			}
			break;
		default:
			break;
		}
	}
	// 직접 조종하는 플레이어블 캐릭터의 위치가 다른 맵으로 이동하는 곳일 경우 !!


	POS UnitPos(mTileMap->PlayUnit->mPosition.x, mTileMap->PlayUnit->mPosition.y);

	if (mTileMap->GetTile(UnitPos.x, UnitPos.y).EventTrigger == 3)
	{
		if (UnitPos.y == 0)
		{
			IsOutMap = true;
		}
		else
		{
			for (int i = 0; i < 20; i++)
			{
				if (UnitPos.x == KarionOutSide[i].x and UnitPos.y == KarionOutSide[i].y)
					MoveMap(KarionOutSide[i].MoveMapName);
			}
		}
	}
}


