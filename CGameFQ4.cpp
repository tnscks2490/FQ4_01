#include "pch.h"
#include "IntroHeader.h"
#include "PlayMap.h"
#include "CGameFQ4.h"

CGameFQ4::~CGameFQ4()
{
	CImagefile::DestoryAll();
}

void CGameFQ4::onCreate()
{
	mIntro1 = new IntroScene1;
	mIntro2 = new IntroScene2;
	mIntro3 = new IntroScene3;
	mIntro4 = new IntroScene4;
	mIntro5 = new IntroScene5;
	mIntro6 = new IntroScene6;
	mIntro7 = new IntroScene7;
	mIntro8 = new IntroScene8;
	mIntro9 = new IntroScene9;
	mIntro10 = new IntroScene10;

	mIntroLoby = new IntroLoby;

	mBarsiaScene1 = new BarsiaScene1;
	mBarsiaScene2 = new BarsiaScene2;
	mKarionScene1 = new KarionScene1;
	mKarionScene2 = new KarionScene2;
	mFieldBattle = new FieldBattle;
	mBarsiaScene3 = new BarsiaScene3;
	mKarionScene3 = new KarionScene3;
	

	mKarionCastle_Altar = new KarionCastle_Altar;
	mKarionCastle_AresRoom = new KarionCastle_AresRoom;
	mKarionCastle_Armory = new KarionCastle_Armory;
	mKarionCastle_Hall = new KarionCastle_Hall;
	mKarionCastle_KingRoom = new KarionCastle_KingRoom;
	mKarionCastle_Lab = new KarionCastle_Lab;
	mKarionCastle_MeetingRoom = new KarionCastle_MeetingRoom;
	mKarionCastle_Outside = new KarionCastle_Outside;




	mPlayMain = new PlayMain;

	mCurrent = mIntro1;

	tiletest = new TileTest;
}

void CGameFQ4::onDestroy()
{
	//TODO: 인트로 지우면서 날리기

	delete mIntroLoby;


	delete mKarionCastle_Altar;
	delete mKarionCastle_AresRoom;
	delete mKarionCastle_Armory;
	delete mKarionCastle_Hall;
	delete mKarionCastle_KingRoom;
	delete mKarionCastle_Lab;
	delete mKarionCastle_MeetingRoom;
	delete mKarionCastle_Outside;

	delete mPlayMain;
}

void CGameFQ4::DestoryImgIntro()
{
	delete mIntro1;
	delete mIntro2;
	delete mIntro3;
	delete mIntro4;
	delete mIntro5;
	delete mIntro6;
	delete mIntro7;
	delete mIntro8;
	delete mIntro9;
	delete mIntro10;
}

void CGameFQ4::DestoryAniIntro()
{
	delete mBarsiaScene1;
	delete mBarsiaScene2;
	delete mBarsiaScene3;
	delete mKarionScene1;
	delete mKarionScene2;
	delete mKarionScene3;
	delete mFieldBattle;
}


// 인트로 장면 변환
void CGameFQ4::onChangeScene()
{
	if (NextScene)
	{
		mCurrent = NextScene;
		NextScene = nullptr;
	}

	if (mIntro1->IsFinished())
	{
		mCurrent = mIntro2;
		mIntro1->FinishedCheck = false;
	}
	else if (mIntro2->IsFinished())
	{
		mCurrent = mIntro3;
		mIntro2->FinishedCheck = false;
	}
	else if (mIntro3->IsFinished())
	{
		mCurrent = mIntro4;
		mIntro3->FinishedCheck = false;
	}
	else if (mIntro4->IsFinished())
	{
		mCurrent = mIntro5;
		mIntro4->FinishedCheck = false;
	}
	else if (mIntro5->IsFinished())
	{
		mCurrent = mIntro6;
		mIntro5->FinishedCheck = false;
	}
	else if (mIntro6->IsFinished())
	{
		mCurrent = mIntro7;
		mIntro6->FinishedCheck = false;
	}
	else if (mIntro7->IsFinished())
	{
		mCurrent = mIntro8;
		mIntro7->FinishedCheck = false;
	}
	else if (mIntro8->IsFinished())
	{
		mCurrent = mIntro9;
		mIntro8->FinishedCheck = false;
	}
	else if (mIntro9->IsFinished())
	{
		mCurrent = mIntro10;
		mIntro9->FinishedCheck = false;
	}
	else if (mIntroLoby->IsFinished())
	{
		mCurrent = mBarsiaScene1;
		mIntroLoby->FinishedCheck = false;
	}
	else if (mBarsiaScene1->IsFinished())
	{
		mCurrent = mKarionScene1;
		mBarsiaScene1->FinishedCheck = false;
	}
	else if (mKarionScene1->IsFinished())
	{
		mCurrent = mBarsiaScene2;
		mKarionScene1->FinishedCheck = false;
	}
	else if (mBarsiaScene2->IsFinished())
	{
		mCurrent = mFieldBattle;
		mBarsiaScene2->FinishedCheck = false;
	}
	else if (mFieldBattle->IsFinished())
	{
		mCurrent = mKarionScene2;
		mFieldBattle->FinishedCheck = false;
	}
	else if (mKarionScene2->IsFinished())
	{
		mCurrent = mBarsiaScene3;
		mKarionScene2->FinishedCheck = false;
	}
	else if (mBarsiaScene3->IsFinished())
	{
		mCurrent = mKarionScene3;
		mBarsiaScene3->FinishedCheck = false;
	}
	else if (mKarionScene3->IsFinished())
	{
		mCurrent = mKarionCastle_Hall;
		mKarionScene3->FinishedCheck = false;
	}
}

void CGameFQ4::onKeyDown(KeyInput* virtual_key)
{
	__super::onKeyDown(virtual_key);

	
}

