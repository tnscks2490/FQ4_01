#include "pch.h"
#include "CUnit.h"


// CUnit 생성자, 소멸자, 함수
void CUnit::Draw(HDC hdc)
{

	FrameSprite.Update(10);
	if(Alive) FrameSprite.Draw(hdc);
}

void CUnit::SetPosition (int x, int y)
{
	FrameSprite.mdestX = x;
	FrameSprite.mdestY = y;
}

void CUnit::CameraFollow(int x, int y)
{
	FrameSprite.mdestX -= x;
	FrameSprite.mdestY -= y;
}

void CUnit::Move(int x, int y)
{
	this->SetPosition(this->FrameSprite.mdestX + x, this->FrameSprite.mdestY + y);
}

void CUnit::ChangeAnimation(const WCHAR* name)
{
	std::wstring wname = name;
	FrameSprite.ChageAnimation(wname);
}

// 각 캐릭터 생성자

KECK::KECK()
{
	Id = IDB_KECK;
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_KECK), L"IDB_KECK");
	mChar.ani = new Canimation;
	mChar.ani->KECK_ANI();
	FrameSprite.Set2(L"Char_BRS", 275, 845, mChar.ani,mChar.imgFile, Csprite::DrawType_Transparent, RGB(255, 0, 255));

	x = FrameSprite.mdestX;
	y = FrameSprite.mdestY;
}

KECK::~KECK()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

ORASON::ORASON()
{
	Id = IDB_ORASON;
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_ORASON), L"IDB_ORASON");
	mChar.ani = new Canimation;
	mChar.ani->ORASON_ANI();
	FrameSprite.Set2(L"Char_B", 385, 825, 
					mChar.ani, mChar.imgFile, 
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
}

ORASON::~ORASON()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

GABI::GABI()
{
	Id = IDB_GABI;
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_GABI), L"IDB_GABI");
	mChar.ani = new Canimation;
	mChar.ani->GABI_ANI();
	FrameSprite.Set2(L"Char_B", 335, 845,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
}

GABI::~GABI()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

LAIOS::LAIOS()
{
	Id = IDB_LAIOS;
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_LAIOS), L"IDB_LAIOS");
	mChar.ani = new Canimation;
	mChar.ani->LAIOS_ANI();
	FrameSprite.Set2(L"Char_B", 225, 825,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
}

LAIOS::~LAIOS()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

MAREAM::MAREAM()
{
	Id = IDB_MAREAM;
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_MAREAM), L"IDB_MAREAM");
	mChar.ani = new Canimation;
	mChar.ani->MAREAM_ANI();
	FrameSprite.Set2(L"Char_B", 355, 890,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
}

MAREAM::~MAREAM()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

MYSOLEN::MYSOLEN()
{
	Id = IDB_MYSOLEN;
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_MYSOLEN), L"IDB_MYSOLEN");
	mChar.ani = new Canimation;
	mChar.ani->MYSOLEN_ANI();
	FrameSprite.Set2(L"Char_B", 225, 890,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
}

MYSOLEN::~MYSOLEN()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

SARK::SARK()
{
	Id = IDB_SARK;
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_SARK), L"IDB_SARK");
	mChar.ani = new Canimation;
	mChar.ani->SARK_ANI();
	FrameSprite.Set2(L"Char_BRS", 305, 890,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
}

SARK::~SARK()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

TOPBGSOLDIER::TOPBGSOLDIER()
{
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_TOPBGSOLDIER), L"IDB_TOPBGSOLDIER");
	mChar.ani = new Canimation;
	mChar.ani->TOPBGSOLDIER_ANI();
	FrameSprite.Set2(L"TOPBGSOLDIER", 100, 100,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
}

TOPBGSOLDIER::~TOPBGSOLDIER()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

BGSOLDIER::BGSOLDIER()
{
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_BGSOLDIER), L"IDB_BGSOLDIER");
	mChar.ani = new Canimation;
	mChar.ani->BGSOLDIER_ANI();
	FrameSprite.Set2(L"BGSOLDIER_LEFTSIDE", 100, 100,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
}

BGSOLDIER::~BGSOLDIER()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

GENELU::GENELU()
{
	Id = IDB_GENELU;
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_GENELU), L"IDB_GENELU");
	mChar.ani = new Canimation;
	mChar.ani->GENELU_ANI();
	FrameSprite.Set2(L"Char_FLS", 305, 465,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
	Alive = true;
}

GENELU::~GENELU()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

// 장군들은 FRONT or SIDE

OGG::OGG()
{
	Id = IDB_OGG;
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_OGG), L"IDB_OGG");
	mChar.ani = new Canimation;
	mChar.ani->OGG_ANI();
	FrameSprite.Set2(L"Char_R", 210, 0,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));

}

OGG::~OGG()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

THYHOOT::THYHOOT()
{
	Id = IDB_THYHOOT;
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_THYHOOT), L"IDB_THYHOOT");
	mChar.ani = new Canimation;
	mChar.ani->THYHOOT_ANI();
	FrameSprite.Set2(L"Char_R", 240, 100,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
}

THYHOOT::~THYHOOT()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

MOLDRED::MOLDRED()
{
	Id = IDB_MOLDRED;
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_MOLDRED), L"IDB_MOLDRED");
	mChar.ani = new Canimation;
	mChar.ani->MOLDRED_ANI();
	FrameSprite.Set2(L"Char_R", 400, 100,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
	
}

MOLDRED::~MOLDRED()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

MACGAIA::MACGAIA()
{
	Id = IDB_MACGAIA;
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_MACGAIA), L"IDB_MACGAIA");
	mChar.ani = new Canimation;
	mChar.ani->MACGAIA_ANI();
	FrameSprite.Set2(L"Char_F", 356, 100,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
}

MACGAIA::~MACGAIA()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

JANIL::JANIL()
{
	Id = IDB_JANIL;
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_JANIL), L"IDB_JANIL");
	mChar.ani = new Canimation;
	mChar.ani->JANIL_ANI();
	FrameSprite.Set2(L"Char_R", 275, 100,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
}

JANIL::~JANIL()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

ARCHBISHOP::ARCHBISHOP()
{
	Id = IDB_ARCHBISHOP;
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_ARCHBISHOP), L"IDB_ARCHBISHOP");
	mChar.ani = new Canimation;
	mChar.ani->ARCHBISHOP_ANI();
	FrameSprite.Set2(L"Char_F", 275, 100,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
}

ARCHBISHOP::~ARCHBISHOP()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

SOLDIER3::SOLDIER3()
{
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_SOLDIER3), L"IDB_SOLDIER3");
	mChar.ani = new Canimation;
	mChar.ani->SOLDIER3_ANI();
	FrameSprite.Set2(L"Char_F", 275, 100,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
}

SOLDIER3::~SOLDIER3()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

SOLDIER4::SOLDIER4()
{
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_SOLDIER4), L"IDB_SOLDIER4");
	mChar.ani = new Canimation;
	mChar.ani->SOLDIER4_ANI();
	FrameSprite.Set2(L"Char_F", 275, 100,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
}

SOLDIER4::~SOLDIER4()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

ARES::ARES()
{
	Id = IDB_ARES;
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_ARES), L"IDB_ARES");
	mChar.ani = new Canimation;
	mChar.ani->ARES_ANI();
	FrameSprite.Set2(L"Char_F", 275, 100,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
}

ARES::~ARES()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

GONRAD::GONRAD()
{
	Id = IDB_GONRAD;
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_GONRAD), L"IDB_GONRAD");
	mChar.ani = new Canimation;
	mChar.ani->GONRAD_ANI();
	FrameSprite.Set2(L"Char_F", 275, 100,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
}

GONRAD::~GONRAD()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

AERAIN::AERAIN()
{
	Id = IDB_AERAIN;
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_AERAIN), L"IDB_AERAIN");
	mChar.ani = new Canimation;
	mChar.ani->AERAIN_ANI();
	FrameSprite.Set2(L"Char_F", 275, 100,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
}

AERAIN::~AERAIN()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

AEKTER::AEKTER()
{
	Id = IDB_AEKTER;
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_AEKTER), L"IDB_AEKTER");
	mChar.ani = new Canimation;
	mChar.ani->AEKTER_ANI();
	FrameSprite.Set2(L"Char_F", 275, 100,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
}

AEKTER::~AEKTER()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

GENERAL::GENERAL()
{
	Id = IDB_GENERAL;
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_GENERAL), L"IDB_GENERAL");
	mChar.ani = new Canimation;
	mChar.ani->GENERAL_ANI();
	FrameSprite.Set2(L"Char_F", 275, 100,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
	Alive = false;
}

GENERAL::~GENERAL()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

SOLDIER1::SOLDIER1()
{
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_SOLDIER1), L"IDB_SOLIDER1");
	mChar.ani = new Canimation;
	mChar.ani->SOLDIER1_ANI();
	FrameSprite.Set2(L"Char_F", 275, 100,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
}

SOLDIER1::~SOLDIER1()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

SOLDIER2::SOLDIER2()
{
	Id = IDB_SOLDIER2; 
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_SOLDIER2), L"IDB_SOLIDER2");
	mChar.ani = new Canimation;
	mChar.ani->SOLDIER2_ANI();
	FrameSprite.Set2(L"Char_F", 275, 100,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
}

SOLDIER2::~SOLDIER2()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

ROCK_SOLDIER::ROCK_SOLDIER()
{
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_ROCK_SOLDIER), L"IDB_ROCK_SOLDIER");
	mChar.ani = new Canimation;
	mChar.ani->ROCK_SOLDIER_ANI();
	FrameSprite.Set2(L"Char_F", 275, 100,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
	Alive = true;
}

ROCK_SOLDIER::ROCK_SOLDIER(bool alive)
{
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_ROCK_SOLDIER), L"IDB_ROCK_SOLDIER");
	mChar.ani = new Canimation;
	mChar.ani->ROCK_SOLDIER_ANI();
	FrameSprite.Set2(L"Char_F", 275, 100,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));

	Alive = alive;
}

ROCK_SOLDIER::~ROCK_SOLDIER()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

ARCHER::ARCHER()
{
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_ARCHER), L"IDB_ARCHER");
	mChar.ani = new Canimation;
	mChar.ani->ARCHER_ANI();
	FrameSprite.Set2(L"Char_F", 275, 100,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
	Alive = true;
}

ARCHER::~ARCHER()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

SOLDIER5::SOLDIER5()
{
	Id = IDB_SOLDIER5;
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_SOLDIER5), L"IDB_SOLDIER5");
	mChar.ani = new Canimation;
	mChar.ani->SOLDIER5_ANI();
	FrameSprite.Set2(L"Char_F", 275, 100,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
	Alive = true;
}

SOLDIER5::~SOLDIER5()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

HORSE_AEKTER::HORSE_AEKTER()
{
	Id = IDB_HORSE_AEKTER;
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_HORSE_AEKTER), L"IDB_HORSE_AEKTER");
	mChar.ani = new Canimation;
	mChar.ani->HORSE_AEKTER_ANI();
	FrameSprite.Set2(L"Char_F", 275, 100,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
	Alive = true;
}

HORSE_AEKTER::~HORSE_AEKTER()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

HORSE_GENERAL::HORSE_GENERAL()
{
	Id = IDB_HORSE_GENERAL;
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_HORSE_GENERAL), L"IDB_HORSE_GENERAL");
	mChar.ani = new Canimation;
	mChar.ani->HORSE_GENERAL_ANI();
	FrameSprite.Set2(L"Char_F", 275, 100,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
	Alive = true;
}

HORSE_GENERAL::~HORSE_GENERAL()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

HORSE_SOLDIER::HORSE_SOLDIER()
{
	Id = IDB_HORSE_SOLDIER;
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_HORSE_SOLDIER), L"IDB_HORSE_SOLDIER");
	mChar.ani = new Canimation;
	mChar.ani->HORSE_SOLDIER_ANI();
	FrameSprite.Set2(L"Char_F", 275, 100,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
	Alive = true;
}

HORSE_SOLDIER::~HORSE_SOLDIER()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

CANDLESTICK::CANDLESTICK()
{
	Id = IDB_CANDLESTICK;
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_CANDLESTICK), L"IDB_CANDLESTICK");
	mChar.ani = new Canimation;
	mChar.ani->CANDLESTICK_ANI();
	FrameSprite.Set2(L"Char_F", 275, 100,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
}

CANDLESTICK::~CANDLESTICK()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

ARMOR::ARMOR()
{
	Id = IDB_ARMOR;
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_ARMOR), L"IDB_ARMOR");
	mChar.ani = new Canimation;
	mChar.ani->ARMOR_ANI();
	FrameSprite.Set2(L"Char_F", 275, 100,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
}

ARMOR::~ARMOR()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

CROW::CROW()
{
	Id = IDB_CROW;
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_CROW), L"IDB_CROW");
	mChar.ani = new Canimation;
	mChar.ani->CROW_ANI();
	FrameSprite.Set2(L"Char_FKL", 275, 100,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
}

CROW::~CROW()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

GARRARD::GARRARD()
{
	Id = IDB_GARRARD;
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_GARRARD), L"IDB_GARRARD");
	mChar.ani = new Canimation;
	mChar.ani->GARRARD_ANI();
	FrameSprite.Set2(L"Char_B", 275, 100,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
}

GARRARD::~GARRARD()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

BRAZIER::BRAZIER()
{
	Id = IDB_BRAZIER;
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_BRAZIER), L"IDB_BRAZIER");
	mChar.ani = new Canimation;
	mChar.ani->BRAZIER_ANI();
	FrameSprite.Set2(L"Char_F", 275, 100,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
}

BRAZIER::~BRAZIER()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

GRIFFIN::GRIFFIN()
{
	Id = IDB_GRIFFIN;
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_GRIFFIN), L"IDB_GRIFFIN");
	mChar.ani = new Canimation;
	mChar.ani->GRIFFIN_ANI();
	FrameSprite.Set2(L"Char_RS", 275, 100,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
}

GRIFFIN::~GRIFFIN()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

G_FLAG::G_FLAG()
{
	Id = IDB_G_FLAG;
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_G_FLAG), L"IDB_G_FLAG");
	mChar.ani = new Canimation;
	mChar.ani->G_FLAG_ANI();
	FrameSprite.Set2(L"Char_F", 275, 100,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
}

G_FLAG::~G_FLAG()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

ALFRED::ALFRED()
{
	Id = IDB_ALFRED;
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_ALFRED), L"IDB_ALFRED");
	mChar.ani = new Canimation;
	mChar.ani->ALFRED_ANI();
	FrameSprite.Set2(L"Char_F", 275, 100,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
}

ALFRED::~ALFRED()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}

RADINKAL::RADINKAL()
{
	Id = IDB_RADINKAL;
	mChar.imgFile = CImagefile::New(MAKEINTRESOURCE(IDB_RADINKAL), L"IDB_RADINKAL");
	mChar.ani = new Canimation;
	mChar.ani->RADINKAL_ANI();
	FrameSprite.Set2(L"Char_F", 275, 100,
		mChar.ani, mChar.imgFile,
		Csprite::DrawType_Transparent, RGB(255, 0, 255));
}

RADINKAL::~RADINKAL()
{
	CImagefile::Delete(mChar.imgFile);
	delete mChar.ani;
}
