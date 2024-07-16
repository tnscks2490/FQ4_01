#include "pch.h"
#include "CIntroScene.h"
#include "CTownScene.h"
#include "CGame.h"
#include "CApplication.h"


void CGame::onCreate()
{
	mIntroScene = new CIntroScene();
	mTownScene = new CTownScene;

	mCurrent = mIntroScene;
}

void CGame::onFrameMove()
{
	mCurrent->onFrameMove();

	if (mCurrent->IsChaged())
	{
		if (mCurrent == mIntroScene)
		{
			mCurrent = mTownScene;
			mIntroScene->mIntroTime = 50;
			CApplication::theApp->ȭ�鰻��();
		}
		else if (mCurrent == mTownScene)
		{
			mCurrent = mIntroScene;
			mTownScene->mTownTime = 50;
			CApplication::theApp->ȭ�鰻��();
		}
	}

	if (mCurrent == mIntroScene && mIntroScene->mIntroTime <= 0)
	{
		mCurrent = mTownScene;
	}
}

void CGame::onDestory()
{
	delete mIntroScene;
	delete mTownScene;
}

void CGame::onDraw(HDC hdc)
{
	mCurrent->onDraw(hdc);
}

//OutputDebugStringW(L"����");
//����Ƽ debug.log�� ���� ǥ�� ������Ҷ� �����ϰ� ��밡��!!