#pragma once
#include "IScene.h"
#include "CUnit.h"
#include "GUI.h"


class CMap;
class TIMELINE;
class GUI;
class Script;

class KarionScene1 : public IScene
{
public:

	KarionScene1();
	~KarionScene1();

	virtual bool IsFinished()  override;
	virtual void onFrameMove() override;
	virtual void onDraw(HDC hdc) override;

	virtual void onMouseDown(UINT x, UINT y, UINT left_right);
	virtual void onMouseMove(UINT x, UINT y);
	virtual void onKeyDown(KeyInput* virtual_key) override;

	void BGCharDraw(HDC hdc);
	void BGCharPosSet();

	void CharAnimation(int delta);


public:
	CMap* cmap;
	GUI* UI;

	ARCHBISHOP archbishop;
	AEKTER aekter;
	SOLDIER3 soldier3[2];
	SOLDIER4 soldier4[4];
	ARES ares;
	GONRAD gonrad;
	AERAIN aerain;

	TIMELINE* Timeline;
	

	HFONT hFont;
	Script* mScript;

	int delta;
	bool CharAniEnd;
	bool LocationEnd;
	bool anicheck;
	bool FinishedCheck;
	bool ClickLock;

};

