#include "pch.h"
#include "CTileMap.h"
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>

CTileMap::CTileMap(int x, int y)
{
	tileWidth = x;
	tileHeight = y;
	mTiles = new TILE[tileWidth * tileHeight];
}

CTileMap::CTileMap(int x, int y, CMap* cmap)
{
	tileWidth = x;
	tileHeight = y;
	mTiles = new TILE[tileWidth * tileHeight];
	mapInfo = cmap;
}

CTileMap::~CTileMap()
{
	for (int i = 0; i < mTileUnits.size(); i++)
		delete mTileUnits[i];

	std::vector<CTileUnit*>().swap(mTileUnits);
}
void CTileMap::MoveTileUnit(CTileUnit* tunit, int dir) // 움직이기 이미지 안사라지도록 확인함
{

	POS pos = tunit->mPosition;
	POS old = tunit->mPosition;
	CTileUnit* checkunit = new CTileUnit;

	switch (dir)
	{
	case UP:
		pos.y--;
		tunit->unit->ChangeAnimation(L"Char_B");
		tunit->dir = UP;
		break;
	case DOWN:
		pos.y++;
		tunit->unit->ChangeAnimation(L"Char_F");
		tunit->dir = DOWN;
		break;
	case LEFT:
		pos.x--;
		tunit->unit->ChangeAnimation(L"Char_L");
		tunit->dir = LEFT;
		break;
	case RIGHT:
		pos.x++;
		tunit->unit->ChangeAnimation(L"Char_R");
		tunit->dir = RIGHT;
		break;	
	default:
		break;
	}
	
	checkunit->mPosition = pos;
	if (!CheckMapEnd(checkunit))
	{
		delete checkunit;
		if (tunit->size == 9)
		{
			SetTileUnit3X3(nullptr, tunit->mPosition);
			tunit->mPosition = pos;
			SetTileUnit3X3(tunit, tunit->mPosition);
			tunit->unit->SetPosition(tunit->mPosition.x * 16, tunit->mPosition.y * 16);
		}
		else if (tunit->size == 4)
		{
			SetTileUnit2X2(nullptr, tunit->mPosition);
			tunit->mPosition = pos;
			SetTileUnit2X2(tunit, tunit->mPosition);
			tunit->unit->SetPosition(tunit->mPosition.x * 16, tunit->mPosition.y * 16);
		}
	}
}

struct distance
{
	int dist;
	int dir;
};

bool compare(distance d1, distance d2)
{
	return d1.dist < d2.dist;
}

void CTileMap::CreateTileUnit(CUnit* cunit, int x, int y, int rank,SIDE side)
{
	CTileUnit* tunit = new CTileUnit;
	tunit->unit = cunit;
	tunit->mPosition = POS(x, y);
	tunit->mTarget = POS(0, 0);
	tunit->mrank = rank;
	if (rank > 3) 
		tunit->size = 9;
	else 
		tunit->size = 4;
	tunit->Side = side;
	//tunit->unit->SetPosition(16 + (x * 16), 48 + (y * 16));
	tunit->unit->SetPosition(16 + (x * 16), 16 + (y * 16));
	tunit->mTilemap = this;
	tunit->FindTarget();
	mTileUnits.push_back(tunit);

	if (rank > 3) SetTileUnit3X3(tunit, tunit->mPosition);
	else SetTileUnit2X2(tunit, tunit->mPosition);
}

void CTileMap::SetTileUnit2X2(CTileUnit* tunit, POS Pos)
{
	GetTile(Pos.x, Pos.y).tunit = tunit;
	GetTile(Pos.x + 1, Pos.y).tunit = tunit;
	GetTile(Pos.x, Pos.y + 1).tunit = tunit;
	GetTile(Pos.x + 1, Pos.y + 1).tunit = tunit;
}

void CTileMap::SetTileUnit3X3(CTileUnit* tunit, POS Pos)
{
	GetTile(Pos.x, Pos.y).tunit = tunit;
	GetTile(Pos.x + 1, Pos.y).tunit = tunit;
	GetTile(Pos.x + 2, Pos.y).tunit = tunit;

	GetTile(Pos.x, Pos.y + 1).tunit = tunit;
	GetTile(Pos.x + 1, Pos.y + 1).tunit = tunit;
	GetTile(Pos.x + 2, Pos.y + 1).tunit = tunit;

	GetTile(Pos.x, Pos.y + 2).tunit = tunit;
	GetTile(Pos.x + 1, Pos.y + 2).tunit = tunit;
	GetTile(Pos.x + 2, Pos.y + 2).tunit = tunit;
}

bool CTileMap::CheckMapEnd(CTileUnit* tunit)
{
	if (tunit->mPosition.x < 0 || tunit->mPosition.x > tileWidth - 2)
		 return true;
	return false;
}

void CTileMap::FindDirection(CTileUnit* tunit)
{
	std::vector<distance> vdist;
	POS pos = tunit->mPosition;
	POS tar = tunit->mTarget;

	distance distdir;


	distdir.dist = abs(tar.x- pos.x) + abs(tar.y - (pos.y-1));
	distdir.dir = UP;
	vdist.push_back(distdir);

	distdir.dist = abs(tar.x - pos.x) + abs(tar.y - (pos.y + 1));
	distdir.dir = DOWN;
	vdist.push_back(distdir);

	distdir.dist = abs(tar.x - (pos.x-1)) + abs(tar.y - pos.y);
	distdir.dir = LEFT;
	vdist.push_back(distdir);

	distdir.dist = abs(tar.x - (pos.x + 1)) + abs(tar.y - pos.y);
	distdir.dir = RIGHT;
	vdist.push_back(distdir);
	
	std::sort(vdist.begin(), vdist.end(),compare);
	for (int i = 0; i < vdist.size(); i++)
	{
		if (Check4dir(tunit, vdist[i].dir))
		{
			MoveTileUnit(tunit, vdist[i].dir);
			EnemyCheck(tunit);
			return;
		}
	}
	tunit->MoveCount++;

}

void CTileMap::EnemyCheck(CTileUnit* tunit)
{

	POS pos = tunit->mPosition;
	CTileUnit* EnemyUnit;
	if (tunit->size == 4)
	{
		if (GetTile(pos.x, pos.y - 1).tunit)
		{
			EnemyUnit = GetTile(pos.x, pos.y - 1).tunit;
			if (GetTile(pos.x, pos.y - 1).tunit->Side != tunit->Side)
				tunit->State = STATE_ATTACK;
		}
		else if (GetTile(pos.x + 1, pos.y - 1).tunit)
		{
			EnemyUnit = GetTile(pos.x + 1, pos.y - 1).tunit;
			if (GetTile(pos.x + 1, pos.y - 1).tunit->Side != tunit->Side)
				tunit->State = STATE_ATTACK;
		}
		else if (GetTile(pos.x, pos.y + 2).tunit)
		{
			EnemyUnit = GetTile(pos.x, pos.y + 2).tunit;
			if (GetTile(pos.x, pos.y + 2).tunit->Side != tunit->Side)
				tunit->State = STATE_ATTACK;
		}
		else if (GetTile(pos.x+1, pos.y + 2).tunit)
		{
			EnemyUnit = GetTile(pos.x + 1, pos.y + 2).tunit;
			if (GetTile(pos.x + 1, pos.y + 2).tunit->Side != tunit->Side)
				tunit->State = STATE_ATTACK;
		}
		else if (GetTile(pos.x-1, pos.y).tunit)
		{
			EnemyUnit = GetTile(pos.x - 1, pos.y).tunit;
			if (GetTile(pos.x - 1, pos.y).tunit->Side != tunit->Side)
				tunit->State = STATE_ATTACK;
		}
		else if (GetTile(pos.x - 1, pos.y+1).tunit)
		{
			EnemyUnit = GetTile(pos.x - 1, pos.y + 1).tunit;
			if (GetTile(pos.x - 1, pos.y + 1).tunit->Side != tunit->Side)
				tunit->State = STATE_ATTACK;
		}
		else if (GetTile(pos.x + 2, pos.y).tunit)
		{
			EnemyUnit = GetTile(pos.x + 2, pos.y).tunit;
			if (GetTile(pos.x + 2, pos.y).tunit->Side != tunit->Side)
				tunit->State = STATE_ATTACK;
		}
		else if (GetTile(pos.x + 2, pos.y+1).tunit)
		{
			EnemyUnit = GetTile(pos.x + 2, pos.y + 1).tunit;
			if (GetTile(pos.x + 2, pos.y + 1).tunit->Side != tunit->Side)
				tunit->State = STATE_ATTACK;
		}
		return;
	}
	else if (tunit->size == 9)
	{
		if (GetTile(pos.x, pos.y - 1).tunit)
		{
			EnemyUnit = GetTile(pos.x, pos.y - 1).tunit;
			if (GetTile(pos.x, pos.y - 1).tunit->Side != tunit->Side)
				tunit->State = STATE_ATTACK;
		}
		else if (GetTile(pos.x + 1, pos.y - 1).tunit)
		{
			EnemyUnit = GetTile(pos.x + 1, pos.y - 1).tunit;
			if (GetTile(pos.x + 1, pos.y - 1).tunit->Side != tunit->Side)
				tunit->State = STATE_ATTACK;
		}
		else if (GetTile(pos.x + 2, pos.y - 1).tunit)
		{
			EnemyUnit = GetTile(pos.x + 2, pos.y - 1).tunit;
			if (GetTile(pos.x + 2, pos.y - 1).tunit->Side != tunit->Side)
				tunit->State = STATE_ATTACK;
		}
		else if (GetTile(pos.x, pos.y + 3).tunit)
		{
			EnemyUnit = GetTile(pos.x, pos.y + 3).tunit;
			if (GetTile(pos.x, pos.y + 3).tunit->Side != tunit->Side)
				tunit->State = STATE_ATTACK;
		}
		else if (GetTile(pos.x+1, pos.y + 3).tunit)
		{
			EnemyUnit = GetTile(pos.x+1, pos.y + 3).tunit;
			if (GetTile(pos.x+1, pos.y + 3).tunit->Side != tunit->Side)
				tunit->State = STATE_ATTACK;
		}
		else if (GetTile(pos.x + 2, pos.y + 3).tunit)
		{
			EnemyUnit = GetTile(pos.x + 2, pos.y + 3).tunit;
			if (GetTile(pos.x + 2, pos.y + 3).tunit->Side != tunit->Side)
				tunit->State = STATE_ATTACK;
		}
		else if (GetTile(pos.x - 1, pos.y).tunit)
		{
			EnemyUnit = GetTile(pos.x - 1, pos.y).tunit;
			if (GetTile(pos.x - 1, pos.y).tunit->Side != tunit->Side)
				tunit->State = STATE_ATTACK;
		}
		else if (GetTile(pos.x - 1, pos.y + 1).tunit)
		{
			EnemyUnit = GetTile(pos.x - 1, pos.y + 1).tunit;
			if (GetTile(pos.x - 1, pos.y + 1).tunit->Side != tunit->Side)
				tunit->State = STATE_ATTACK;
		}
		else if (GetTile(pos.x - 1, pos.y + 2).tunit)
		{
			EnemyUnit = GetTile(pos.x - 1, pos.y + 2).tunit;
			if (GetTile(pos.x - 1, pos.y + 2).tunit->Side != tunit->Side)
				tunit->State = STATE_ATTACK;
		}
		else if (GetTile(pos.x + 2, pos.y).tunit)
		{
			EnemyUnit = GetTile(pos.x + 2, pos.y).tunit;
			if (GetTile(pos.x + 2, pos.y).tunit->Side != tunit->Side)
				tunit->State = STATE_ATTACK;
		}
		else if (GetTile(pos.x + 2, pos.y + 1).tunit)
		{
			EnemyUnit = GetTile(pos.x + 2, pos.y - 1).tunit;
			if (GetTile(pos.x + 2, pos.y - 1).tunit->Side != tunit->Side)
				tunit->State = STATE_ATTACK;
		}
		else if (GetTile(pos.x + 2, pos.y + 2).tunit)
		{
			EnemyUnit = GetTile(pos.x + 2, pos.y - 1).tunit;
			if (GetTile(pos.x + 2, pos.y - 1).tunit->Side != tunit->Side)
				tunit->State = STATE_ATTACK;
		}
		return;
	}
}

void CTileMap::ATTACK(CTileUnit* tunit)
{
	POS pos = tunit->mPosition;
	CTileUnit* EnemyUnit;
	if (tunit->size == 4)
	{
		if (GetTile(pos.x, pos.y - 1).tunit)
		{
			EnemyUnit = GetTile(pos.x, pos.y - 1).tunit;
			if (GetTile(pos.x, pos.y - 1).tunit->Side != tunit->Side)
				EnemyUnit->HitStack++;
		}
		else if (GetTile(pos.x + 1, pos.y - 1).tunit)
		{
			EnemyUnit = GetTile(pos.x + 1, pos.y - 1).tunit;
			if (GetTile(pos.x + 1, pos.y - 1).tunit->Side != tunit->Side)
				EnemyUnit->HitStack++;
		}
		else if (GetTile(pos.x, pos.y + 2).tunit)
		{
			EnemyUnit = GetTile(pos.x, pos.y + 2).tunit;
			if (GetTile(pos.x, pos.y + 2).tunit->Side != tunit->Side)
				EnemyUnit->HitStack++;
		}
		else if (GetTile(pos.x + 1, pos.y + 2).tunit)
		{
			EnemyUnit = GetTile(pos.x + 1, pos.y + 2).tunit;
			if (GetTile(pos.x + 1, pos.y + 2).tunit->Side != tunit->Side)
				EnemyUnit->HitStack++;
		}
		else if (GetTile(pos.x - 1, pos.y).tunit)
		{
			EnemyUnit = GetTile(pos.x - 1, pos.y).tunit;
			if (GetTile(pos.x - 1, pos.y).tunit->Side != tunit->Side)
				EnemyUnit->HitStack++;
		}
		else if (GetTile(pos.x - 1, pos.y + 1).tunit)
		{
			EnemyUnit = GetTile(pos.x - 1, pos.y + 1).tunit;
			if (GetTile(pos.x - 1, pos.y + 1).tunit->Side != tunit->Side)
				EnemyUnit->HitStack++;
		}
		else if (GetTile(pos.x + 2, pos.y).tunit)
		{
			EnemyUnit = GetTile(pos.x + 2, pos.y).tunit;
			if (GetTile(pos.x + 2, pos.y).tunit->Side != tunit->Side)
				EnemyUnit->HitStack++;
		}
		else if (GetTile(pos.x + 2, pos.y + 1).tunit)
		{
			EnemyUnit = GetTile(pos.x + 2, pos.y + 1).tunit;
			if (GetTile(pos.x + 2, pos.y + 1).tunit->Side != tunit->Side)
				EnemyUnit->HitStack++;
		}
	}
	else if (tunit->size == 9)
	{
		if (GetTile(pos.x, pos.y - 1).tunit)
		{
			EnemyUnit = GetTile(pos.x, pos.y - 1).tunit;
			if (GetTile(pos.x, pos.y - 1).tunit->Side != tunit->Side)
				EnemyUnit->HitStack++;
		}
		else if (GetTile(pos.x + 1, pos.y - 1).tunit)
		{
			EnemyUnit = GetTile(pos.x + 1, pos.y - 1).tunit;
			if (GetTile(pos.x + 1, pos.y - 1).tunit->Side != tunit->Side)
				EnemyUnit->HitStack++;
		}
		else if (GetTile(pos.x + 2, pos.y - 1).tunit)
		{
			EnemyUnit = GetTile(pos.x + 2, pos.y - 1).tunit;
			if (GetTile(pos.x + 2, pos.y - 1).tunit->Side != tunit->Side)
				EnemyUnit->HitStack++;
		}
		else if (GetTile(pos.x, pos.y + 3).tunit)
		{
			EnemyUnit = GetTile(pos.x, pos.y + 3).tunit;
			if (GetTile(pos.x, pos.y + 3).tunit->Side != tunit->Side)
				EnemyUnit->HitStack++;
		}
		else if (GetTile(pos.x + 1, pos.y + 3).tunit)
		{
			EnemyUnit = GetTile(pos.x + 1, pos.y + 3).tunit;
			if (GetTile(pos.x + 1, pos.y + 3).tunit->Side != tunit->Side)
				EnemyUnit->HitStack++;
		}
		else if (GetTile(pos.x + 2, pos.y + 3).tunit)
		{
			EnemyUnit = GetTile(pos.x + 2, pos.y + 3).tunit;
			if (GetTile(pos.x + 2, pos.y + 3).tunit->Side != tunit->Side)
				EnemyUnit->HitStack++;
		}
		else if (GetTile(pos.x - 1, pos.y).tunit)
		{
			EnemyUnit = GetTile(pos.x - 1, pos.y).tunit;
			if (GetTile(pos.x - 1, pos.y).tunit->Side != tunit->Side)
				EnemyUnit->HitStack++;
		}
		else if (GetTile(pos.x - 1, pos.y + 1).tunit)
		{
			EnemyUnit = GetTile(pos.x - 1, pos.y + 1).tunit;
			if (GetTile(pos.x - 1, pos.y + 1).tunit->Side != tunit->Side)
				EnemyUnit->HitStack++;
		}
		else if (GetTile(pos.x - 1, pos.y + 2).tunit)
		{
			EnemyUnit = GetTile(pos.x - 1, pos.y + 2).tunit;
			if (GetTile(pos.x - 1, pos.y + 2).tunit->Side != tunit->Side)
				EnemyUnit->HitStack++;
		}
		else if (GetTile(pos.x + 3, pos.y).tunit)
		{
			EnemyUnit = GetTile(pos.x + 3, pos.y).tunit;
			if (GetTile(pos.x + 3, pos.y).tunit->Side != tunit->Side)
				EnemyUnit->HitStack++;
		}
		else if (GetTile(pos.x + 3, pos.y + 1).tunit)
		{
			EnemyUnit = GetTile(pos.x + 3, pos.y + 1).tunit;
			if (GetTile(pos.x + 3, pos.y + 1).tunit->Side != tunit->Side)
				EnemyUnit->HitStack++;
		}
		else if (GetTile(pos.x + 3, pos.y + 2).tunit)
		{
			EnemyUnit = GetTile(pos.x + 3, pos.y +2).tunit;
			if (GetTile(pos.x + 3, pos.y +2).tunit->Side != tunit->Side)
				EnemyUnit->HitStack++;
		}
	}
}

void CTileMap::RUNAWAY(CTileUnit* tunit)
{
	if (tunit->Side == ENEMY)
	{
		tunit->mTarget.x = tunit->mPosition.x;
		tunit->mTarget.y = 0;
	}
	else if (tunit->Side == PLAYER)
	{
		tunit->mTarget.x = tunit->mPosition.x;
		tunit->mTarget.y = tunit->mTilemap->tileHeight - 3;
	}
}

bool CTileMap::Check4dir(CTileUnit* tunit,int dir)
{
	POS pos = tunit->mPosition;
	if (tunit->size == 4)
	{
		switch (dir)
		{
		case UP:
			if (GetTile(pos.x, pos.y - 1).tunit == nullptr && GetTile(pos.x + 1, pos.y - 1).tunit == nullptr)
				return true;
			break;
		case DOWN:
			if (GetTile(pos.x, pos.y + 2).tunit == nullptr 
				&& GetTile(pos.x + 1, pos.y + 2).tunit == nullptr)
				return true;
			break;
		case LEFT:
			if (GetTile(pos.x-1, pos.y).tunit == nullptr
				&& GetTile(pos.x - 1, pos.y + 1).tunit == nullptr)
				return true;
			break;
		case RIGHT:
			if (GetTile(pos.x +2, pos.y).tunit == nullptr
				&& GetTile(pos.x +2, pos.y + 1).tunit == nullptr)
				return true;
			break;
		default:
			break;
		}
	}
	else if (tunit->size == 9)
	{
		switch (dir)
		{
		case UP:
			if (GetTile(pos.x, pos.y - 1).tunit == nullptr
				&& GetTile(pos.x + 1, pos.y - 1).tunit == nullptr
				&& GetTile(pos.x + 2, pos.y -1).tunit == nullptr)
				return true;
			break;
		case DOWN:
			if (GetTile(pos.x, pos.y +3).tunit == nullptr
				&& GetTile(pos.x + 1, pos.y + 3).tunit == nullptr
				&& GetTile(pos.x + 2, pos.y + 3).tunit == nullptr)
				return true;
			break;
		case LEFT:
			if (GetTile(pos.x-1, pos.y ).tunit == nullptr
				&& GetTile(pos.x - 1, pos.y + 1).tunit == nullptr
				&& GetTile(pos.x - 1, pos.y + 2).tunit == nullptr)
				return true;
			break;
		case RIGHT:
			if (GetTile(pos.x +3, pos.y).tunit == nullptr
				&& GetTile(pos.x + 3, pos.y + 1).tunit == nullptr
				&& GetTile(pos.x + 3, pos.y + 2).tunit == nullptr)
				return true;
			break;
		default:
			break;
		}
	}
	return false;
}

void CTileMap::Draw(HDC hdc)
{
	for (CTileUnit* it : mTileUnits)
		it->unit->Draw(hdc);	
}

void CTileMap::TileDraw(HDC hdc,CMap* cmap)
{
	int xx = cmap->CameraX * (-1);
	int yy = cmap->CameraY * (-1);


	int sx = cmap->mScreen.mdestX;
	int sy = cmap->mScreen.mdestY;

	for (int y = 0; y < tileHeight; y++)
	{
		for (int x = 0; x < tileWidth; x++)
		{
			if (GetTile(x, y).isMove)
				MoveO->transDraw(hdc, xx + x * 16 + sx, yy + y * 16 + sy, 0, 0, 16, 16, RGB(255, 0, 255));
			else
				MoveX->transDraw(hdc, xx + x * 16 + sx, yy + y * 16 + sy, 0, 0, 16, 16, RGB(255, 0, 255));

			if (GetTile(x, y).tunit)
				UnitO->transDraw(hdc, xx + x * 16 + sx, yy + y * 16 + sy, 0, 0, 16, 16, RGB(255, 0, 255));
		}
	}
}

void CTileMap::MoveTUnit(CTileUnit* tunit, int dir)
{
	POS pos;
	pos.x = tunit->mPosition.x;
	pos.y = tunit->mPosition.y;

	POS old = tunit->mPosition;
	CTileUnit* checkunit = new CTileUnit;

	switch (dir)
	{
	case UP:
		pos.y--;
		TUnitChangeAni(tunit,UP);
		tunit->dir = UP;
		break;
	case DOWN:
		pos.y++;
		TUnitChangeAni(tunit, DOWN);
		tunit->dir = DOWN;
		break;
	case LEFT:
		pos.x--;
		TUnitChangeAni(tunit, LEFT);
		tunit->dir = LEFT;
		break;
	case RIGHT:
		pos.x++;
		TUnitChangeAni(tunit, RIGHT);
		tunit->dir = RIGHT;
		break;
	default:
		break;
	}
	if (GetTile(pos.x, pos.y).isMove)
	{
		checkunit->mPosition = pos;

		switch (tunit->dir)
		{
		case UP:
			if (pos.y >= 10 && pos.y < tileHeight - 9)
			{
				if (mapInfo->CameraY > 0 && mapInfo->CameraY <= mapInfo->mScreen.mSrcHeight - 304)
				{
					mapInfo->CameraMove(0, -16);
				}
			}
			break;
		case DOWN:
			if (pos.y > 10 && pos.y <= tileHeight)
			{
				if (mapInfo->CameraY >= 0 && mapInfo->CameraY < mapInfo->mScreen.mSrcHeight - 304)
				{
					mapInfo->CameraMove(0, 16);
				}
			}
			break;
		case LEFT:
			if (pos.x >= 18 && pos.x < tileWidth - 18)
			{
				if (mapInfo->CameraX > 0 && mapInfo->CameraX <= mapInfo->mScreen.mSrcWidth - 608)
				{
					mapInfo->CameraMove(-16, 0);
				}
			}
			break;
		case RIGHT:
			if (pos.x > 18 && pos.x <= tileWidth - 18)
			{
				if (mapInfo->CameraX >= 0 && mapInfo->CameraX < mapInfo->mScreen.mSrcWidth - 608)
				{
					mapInfo->CameraMove(16, 0);
				}
			}
			break;
		default:
			break;
		}		

		if (!CheckMapEnd(checkunit))
		{
			if (tunit->size == 9)
			{
				SetTileUnit3X3(nullptr, tunit->mPosition);
				tunit->mPosition = pos;
				SetTileUnit3X3(tunit, tunit->mPosition);
				tunit->unit->SetPosition(tunit->mPosition.x * 16, tunit->mPosition.y * 16);
			}
			else if (tunit->size == 4)
			{
				SetTileUnit2X2(nullptr, tunit->mPosition);
				tunit->mPosition = pos;
				SetTileUnit2X2(tunit, tunit->mPosition);
				tunit->unit->SetPosition((tunit->mPosition.x * 16) + 16, (tunit->mPosition.y * 16) + 16);
			}
		}
	}
	delete checkunit;
}

void CTileMap::TUnitChangeAni(CTileUnit* tunit, int dir)
{
	if (tunit->dir == dir)
	{
		switch (dir)
		{
		case UP:
			if (tunit->unit->FrameSprite.m_CurrentFAni->m_Name != L"Char_BSUS")
				tunit->unit->ChangeAnimation(L"Char_BSUS");
			else if (tunit->unit->FrameSprite.m_CurrentFAni->m_Name != L"Char_BSDS")
				tunit->unit->ChangeAnimation(L"Char_BSDS");
			break;
		case DOWN:
			if (tunit->unit->FrameSprite.m_CurrentFAni->m_Name == L"Char_FSUS")
				tunit->unit->ChangeAnimation(L"Char_FSDS");
			else if (tunit->unit->FrameSprite.m_CurrentFAni->m_Name == L"Char_FSDS")
				tunit->unit->ChangeAnimation(L"Char_FSUS");
			break;
		case LEFT:
			if (tunit->unit->FrameSprite.m_CurrentFAni->m_Name == L"Char_LSUS")
				tunit->unit->ChangeAnimation(L"Char_LSDS");
			else if (tunit->unit->FrameSprite.m_CurrentFAni->m_Name == L"Char_LSDS")
				tunit->unit->ChangeAnimation(L"Char_LSUS");
			break;
		case RIGHT:
			if (tunit->unit->FrameSprite.m_CurrentFAni->m_Name == L"Char_RSUS")
				tunit->unit->ChangeAnimation(L"Char_RSDS");
			else if (tunit->unit->FrameSprite.m_CurrentFAni->m_Name == L"Char_RSDS")
				tunit->unit->ChangeAnimation(L"Char_RSUS");
			break;
		default:
			break;
		}
	}
	else if (tunit->dir != dir)
	{
		switch (dir)
		{
		case UP:
			tunit->unit->ChangeAnimation(L"Char_BSUS");
			break;
		case DOWN:
			tunit->unit->ChangeAnimation(L"Char_FSUS");
			break;
		case LEFT:
			tunit->unit->ChangeAnimation(L"Char_LSUS");
			break;
		case RIGHT:
			tunit->unit->ChangeAnimation(L"Char_RSUS");
			break;
		default:
			break;
		}
	}
}
void CTileMap::PlayUnitDraw(HDC hdc, CMap* cmap)
{
	int xx = cmap->CameraX * (-1);
	int yy = cmap->CameraY * (-1);
	PlayUnit->unit->SetPosition(xx + PlayUnit->mPosition.x * 16 + cmap->mScreen.mdestX, yy + PlayUnit->mPosition.y * 16 + cmap->mScreen.mdestY);
	PlayUnit->unit->Draw(hdc);
}

void CTileMap::SetTUnit(CTileUnit* tunit, POS pos)
{
	if (tunit->size == 9)
	{
		SetTileUnit3X3(nullptr, tunit->mPosition);
		tunit->mPosition = pos;
		SetTileUnit3X3(tunit, tunit->mPosition);
		tunit->unit->SetPosition(tunit->mPosition.x * 16, tunit->mPosition.y * 16);
	}
	else if (tunit->size == 4)
	{
		SetTileUnit2X2(nullptr, tunit->mPosition);
		tunit->mPosition = pos;
		SetTileUnit2X2(tunit, tunit->mPosition);
		tunit->unit->SetPosition((tunit->mPosition.x * 16) + 16, (tunit->mPosition.y * 16) + 16);
	}
}

void CTileMap::SaveToFile(const WCHAR* fileName)
{
	FILE* fp = NULL;
	errno_t err;
	err = _wfopen_s(&fp, fileName, L"wb");
	if(err != 0)
	{
		OutputDebugStringW(L"실패");
		return;
	}

	struct Header
	{
		int width;
		int height;	
	} hd;

	struct TileInfo
	{
		char tileMove;
		char tileEvent;
	} Tinfo;

	hd.width = tileWidth;
	hd.height = tileHeight;

	Tinfo.tileMove = 0;
	Tinfo.tileEvent = 0;

	fwrite(&hd, sizeof(hd), 1, fp);

	for (int y = 0; y < tileHeight; y++)
	{
		for (int x = 0; x < tileWidth; x++)
		{
			TILE& tile = GetTile(x, y);
			Tinfo.tileMove = tile.isMove;
			Tinfo.tileEvent = tile.EventTrigger;

			fwrite(&Tinfo, sizeof(Tinfo), 1, fp);
		}
	}
	fclose(fp);
}

void CTileMap::LoadFromFile(const WCHAR* fileName)
{
	FILE* fp = NULL;
	errno_t err;
	err = _wfopen_s(&fp, fileName, L"rb");
	if (err != 0)
	{
		OutputDebugStringW(L"실패");
		return;
	}

	struct Header
	{
		int width;
		int height;
	} hd;

	struct TileInfo
	{
		char tileMove;
		char tileEvent;
	} Tinfo;

	fread(&hd, sizeof(hd), 1, fp);

	for (int y = 0; y < hd.height; y++)
	{
		for (int x = 0; x < hd.width; x++)
		{
			fread(&Tinfo, sizeof(Tinfo), 1, fp);
			TILE& tile = GetTile(x, y);
			tile.isMove = Tinfo.tileMove;
			tile.EventTrigger = Tinfo.tileEvent;
		}
	}
	fclose(fp);
}

CTileUnit::CTileUnit()
{
	unit = nullptr;
	mPosition.x = 0;
	mPosition.y = 0;
	mTarget.x = 0;
	mTarget.y = 0;
	mrank = 0;
}

CTileUnit::~CTileUnit()
{

}

void CTileUnit::Tick(int delta, POS mPos)
{
	if (TickCount == 15)
	{
		State = STATE_IDLE;
		TickCount = 0;
	}

	if (HitStack > 12)
	{
		State = STATE_RUNAWAY;
		HitStack = 0;
	}
	else if (HitStack % 3 == 0)
	{
		CharAniChange(L"Char_D");
	}
	else if (HitStack % 3 != 0)
	{
		Action();
	}

	switch (State)
	{
	case STATE_IDLE:
		FindTarget();
		if (MoveCount == 5)
		{
			mTarget = mTilemap->RandPOS();
			TickCount = 0;
			MoveCount = 0;
		}
		State = STATE_MOVE;
		break;
	case STATE_MOVE:
		mTilemap->FindDirection(this);
		TickCount++;
		break;
	case STATE_ATTACK:
		mTilemap->ATTACK(this);
		break;
	case STATE_RUNAWAY:
		mTilemap->RUNAWAY(this);
		State = STATE_MOVE;
		break;
	default:
		break;
	}
}

void CTileUnit::FindTarget()
{
	if (mrank == 2 || mrank == 5)
		mTarget = mTilemap->FindGKing();
	else if (mrank == 1 || mrank == 3 || mrank == 4 || mrank == 6)
		mTarget = mTilemap->FIndAKing();
}

void CTileUnit::Action()
{
	switch (dir)
	{
	case UP:
		CharAniChange(L"Char_B");
		break;
	case DOWN:
		CharAniChange(L"Char_F");
		break;
	case LEFT:
		CharAniChange(L"Char_L");
		break;
	case RIGHT:
		CharAniChange(L"Char_R");
		break;
	default:
		break;
	}
}

void CTileUnit::CharAniChange(const WCHAR* ani)
{
	if (unit->FrameSprite.m_CurrentFAni->m_Name != ani)
		unit->ChangeAnimation(ani);
}

void CTileUnit::Move(int dir)
{
	POS pos = mPosition;
	switch (dir)
	{
	case UP:
		if (mTilemap->GetTile(pos.x, pos.y - 1).tunit == nullptr &&
			mTilemap->GetTile(pos.x + 1, pos.y - 1).tunit == nullptr)
			mTilemap->MoveTileUnit(this, UP);
			break;
	case DOWN:
		if (mTilemap->GetTile(pos.x, pos.y + 2).tunit == nullptr &&
			mTilemap->GetTile(pos.x + 1, pos.y + 2).tunit == nullptr)
			mTilemap->MoveTileUnit(this, DOWN);

			break;
	case LEFT:
		if (mTilemap->GetTile(pos.x - 1, pos.y).tunit == nullptr &&
			mTilemap->GetTile(pos.x - 1, pos.y + 1).tunit == nullptr)
			mTilemap->MoveTileUnit(this, LEFT);
			break;
	case RIGHT:
		if (mTilemap->GetTile(pos.x + 2, pos.y).tunit == nullptr
			&& mTilemap->GetTile(pos.x + 2, pos.y + 1).tunit == nullptr)
			mTilemap->MoveTileUnit(this, RIGHT);
		break;
	default:
		break;
	}
		

}


POS CTileMap::FindGKing()
{
	for (CTileUnit* it : mTileUnits)
	{
		if (it->mrank == G_KING)
			return it->mPosition;
	}
	return POS();
}
POS CTileMap::FIndAKing()
{
	for (CTileUnit* it : mTileUnits)
	{
		if (it->mrank == A_KING )
			return it->mPosition;
	}
	return POS();
}
POS CTileMap::RandPOS()
{
	srand(time(NULL));
	POS randpos;
	randpos.x = rand() % 38;
	randpos.y = rand() % 29;
	return randpos;
}
