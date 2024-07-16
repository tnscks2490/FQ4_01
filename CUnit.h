#pragma once

#include "CImagefile.h"
#include "Csprite.h"
#include "resource.h"
#include "CharactorPosition.h"
#include "Canimation.h"


class CUnit
{
	/*
	void Think()
	{
		타겟 찾기
		이동해야할 목표점 설정
	}
	void Update()
	{
		Think();
		....
	}
	*/
public:
	virtual void Draw(HDC hdc);
	
	virtual void ChangeAnimation(const WCHAR* name);
	void SetPosition(int x, int y);
	void CameraFollow(int x,int y);
	void Move(int x, int y);

	ANIM_FILE mChar;
	CFrameSprite FrameSprite;
	int Id;
	bool Alive = true;
};

class TOPBGSOLDIER : public CUnit
{
public:
	TOPBGSOLDIER();
	~TOPBGSOLDIER();
};

class BGSOLDIER : public CUnit
{
public:
	BGSOLDIER();
	~BGSOLDIER();
};

class KECK : public CUnit
{
public:
	KECK();
	~KECK();

	int x;
	int y;
};

class ORASON : public CUnit
{
public:
	ORASON();
	~ORASON();
};

class GABI : public CUnit
{
public:
	GABI();
	~GABI();
};

class LAIOS : public CUnit
{
public:
	LAIOS();
	~LAIOS();
};

class MAREAM : public CUnit
{
public:
	MAREAM();
	~MAREAM();
};

class MYSOLEN : public CUnit
{
public:
	MYSOLEN();
	~MYSOLEN();
};

class SARK : public CUnit
{
public:
	SARK();
	~SARK();
};

class GENELU : public CUnit
{
public:
	GENELU();
	~GENELU();

	bool Alive;
};

class OGG : public CUnit
{
public:
	OGG();
	~OGG();
};

class THYHOOT : public CUnit
{
public:
	THYHOOT();
	~THYHOOT();
};

class MOLDRED : public CUnit
{
public:
	MOLDRED();
	~MOLDRED();
};

class MACGAIA : public CUnit
{
public:
	MACGAIA();
	~MACGAIA();
};

class JANIL : public CUnit
{
public:
	JANIL();
	~JANIL();
};

class ARCHBISHOP : public CUnit
{
public:
	ARCHBISHOP();
	~ARCHBISHOP();
};


class SOLDIER1 : public CUnit
{
public:
	SOLDIER1();
	~SOLDIER1();
};

class SOLDIER2 : public CUnit
{
public:
	SOLDIER2();
	~SOLDIER2();
};

class SOLDIER3 : public CUnit
{
public:
	SOLDIER3();
	~SOLDIER3();
};

class SOLDIER4 : public CUnit
{
public:
	SOLDIER4();
	~SOLDIER4();
};

class ARES : public CUnit
{
public:
	ARES();
	~ARES();
};

class GONRAD : public CUnit
{
public:
	GONRAD();
	~GONRAD();
};

class AERAIN : public CUnit
{
public:
	AERAIN();
	~AERAIN();
};

class AEKTER : public CUnit
{
public:
	AEKTER();
	~AEKTER();
};

class GENERAL : public CUnit
{
public:
	GENERAL();
	~GENERAL();

	bool Alive;
};

class ROCK_SOLDIER : public CUnit
{
public:
	ROCK_SOLDIER();
	ROCK_SOLDIER(bool Alive);
	~ROCK_SOLDIER();

	bool Alive;
};


class ARCHER : public CUnit
{
public:
	ARCHER();
	~ARCHER();

	bool Alive;
};

class SOLDIER5 : public CUnit
{
public:
	SOLDIER5();
	~SOLDIER5();

	bool Alive;
};

class HORSE_AEKTER : public CUnit
{
public:
	HORSE_AEKTER();
	~HORSE_AEKTER();

	bool Alive;

};

class HORSE_GENERAL : public CUnit
{
public:
	HORSE_GENERAL();
	~HORSE_GENERAL();

	bool Alive;
};

class HORSE_SOLDIER : public CUnit
{
public:
	HORSE_SOLDIER();
	~HORSE_SOLDIER();

	bool Alive;
};

class CROW : public CUnit
{
public:
	CROW();
	~CROW();
};


class CANDLESTICK : public CUnit
{
public:
	CANDLESTICK();
	~CANDLESTICK();
};

class ARMOR : public CUnit
{
public:

	ARMOR();
	~ARMOR();
};

class GARRARD : public CUnit
{
public:
	GARRARD();
	~GARRARD();
};

class BRAZIER : public CUnit
{
public:
	BRAZIER();
	~BRAZIER();
};

class GRIFFIN : public CUnit
{
public:
	GRIFFIN();
	~GRIFFIN();
};

class G_FLAG : public CUnit
{
public:
	G_FLAG();
	~G_FLAG();
};

class ALFRED : public CUnit
{
public:
	ALFRED();
	~ALFRED();
};
class RADINKAL : public CUnit
{
public:
	RADINKAL();
	~RADINKAL();
};