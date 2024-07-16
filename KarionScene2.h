#pragma once

#include "IScene.h"
#include "CUnit.h"
#include "GUI.h"


class CMap;
class TIMELINE;
class GUI;
class Script;

class KarionScene2 : public IScene
{
public:
	KarionScene2();
	~KarionScene2();

	virtual bool IsFinished()  override;
	virtual void onFrameMove() override;
	virtual void onDraw(HDC hdc) override;

	virtual void onMouseDown(UINT x, UINT y, UINT left_right);
	virtual void onMouseMove(UINT x, UINT y);
	virtual void onKeyDown(KeyInput* virtual_key) override;

	void CharAnimation(int delta);
	void ObjectPosSet();
	void AniCharSet();
	void ObjectDraw(HDC hdc);
	void AniCharDraw(HDC hdc);

public:
	CMap* cmap;
	GUI* UI;
	
	Script* mScript;
	TIMELINE* Timeline;
	HFONT hFont;

	CANDLESTICK candlestick[2];
	ARMOR armor[2];
	GONRAD gonrad;
	AERAIN aerain;
	CROW crow[6];

	int delta;
	bool CharAniEnd;
	bool LocationEnd;
	bool anicheck;
	bool FinishedCheck;
	bool ClickLock;
};

