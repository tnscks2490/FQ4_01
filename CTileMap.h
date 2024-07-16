#pragma once
#include "CUnit.h"
#include "CMap.h"
#include "Position.h"


//이거 버그아니냐
//이거 버그아니냐

class CTileUnit;
class CMap;
enum STATE
{
	STATE_IDLE,
	STATE_MOVE,
	STATE_ATTACK,
	STATE_DAMEGED,
	STATE_RUNAWAY,
};
enum Dir
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};
enum RANK
{
	G_SOLDIER = 1,
	A_SOLDIER = 2,
	G_ARCHER_SOLDIER = 3,
	G_HORSE_SOLDIER = 4,
	A_KING = 5,
	G_KING = 6
};

enum SIDE
{
	PLAYER,
	ENEMY
};

enum Event
{
	None = 0,
	Talk = 1,
	Item = 2,
	Gate = 3,
};



struct TILE
{
	CTileUnit* tunit = nullptr;
	bool isMove = true;
	int EventTrigger = 0;
	//나중에 false로 고치고 하나씩 편집기에서 수정할것
};


class CTileMap
{
public:

	CTileMap(int x, int y);
	CTileMap(int x, int y,CMap* cmap);
	~CTileMap();

	TILE& GetTile(int x, int y) const { return mTiles[y * tileWidth + x]; }

	void CreateTileUnit(CUnit* cunit,int x, int y, int rank,SIDE side); // 유닛 생성함수
	void SetTileUnit2X2(CTileUnit* tunit,POS Pos);
	void SetTileUnit3X3(CTileUnit* tunit, POS Pos);
	bool CheckMapEnd(CTileUnit* tunit); // 화면안에 들어오도록 하는 함수(맵안에만 돌아다니도록)
	void MoveTileUnit(CTileUnit* tunit, int dir); // 실제로 이동하는 함수
	void TUnitChangeAni(CTileUnit* tunit,int dir);
	void FindDirection(CTileUnit* tunit); // 4방향 중 빈공간으로 이동
	bool Check4dir(CTileUnit* tunit,int dir); // 4방향으로 캐릭터가 있나 체크
	void EnemyCheck(CTileUnit* tunit);
	void ATTACK(CTileUnit* tunit);
	void RUNAWAY(CTileUnit* tunit);


	void Draw(HDC hdc);
	void TileDraw(HDC hdc,CMap* cmap);


	void MoveTUnit(CTileUnit* tunit, int dir);
	void PlayUnitDraw(HDC hdc,CMap* cmap);
	void SetTUnit(CTileUnit* tunit, POS pos);
	void SaveToFile(const WCHAR* fileName);
	void LoadFromFile(const WCHAR* fileName);

	CImagefile* MoveO = CImagefile::New(MAKEINTRESOURCE(IDB_MOVEO),L"IDB_MOVEO");
	CImagefile* MoveX = CImagefile::New(MAKEINTRESOURCE(IDB_MOVEX), L"IDB_MOVEX");
	CImagefile* UnitO = CImagefile::New(MAKEINTRESOURCE(IDB_UnitO), L"IDB_UnitO");

	POS FindGKing(); // 상대방 찾는 함수
	POS FIndAKing(); // 상대방 찾는 함수
	POS RandPOS();   // 랜덤 위치 찾는 함수
public:
	CMap* mapInfo;
	bool isTileDraw = false;
	int tileWidth;
	int tileHeight;

	std::vector<CTileUnit*> mTileUnits;

	CTileUnit* PlayUnit;
private:
	TILE* mTiles;
};




class CTileUnit
{
public:

	CTileUnit();
	~CTileUnit();

	void Tick(int delta, POS mPos);
	void FindTarget();
	void Action();
	void CharAniChange(const WCHAR* ani);
	
	void Move(int dir);

public:
	CUnit* unit;
	POS mPosition;
	POS mTarget;

	CTileMap* mTilemap;
	int TickCount = 0;
	int MoveCount = 0;
	int mrank;
	int size = 0;
	int Side;
	int HitStack = 0;
	int dir = 0;
	STATE State = STATE_IDLE;
};