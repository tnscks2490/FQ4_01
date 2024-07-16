#pragma once
#include "IScene.h"
#include "CUnit.h"
#include "GUI.h"


class CMap;
class TIMELINE;
class GUI;
class CTileMap;
class CTileUnit;

class Script;


class FieldBattle :
    public IScene
{
public:
    FieldBattle();
    ~FieldBattle();


	virtual bool IsFinished()  override;
	virtual void onFrameMove() override;
	virtual void onDraw(HDC hdc) override;

	virtual void onMouseDown(UINT x, UINT y, UINT left_right);
	virtual void onMouseMove(UINT x, UINT y);
	virtual void onKeyDown(KeyInput* virtual_key) override;

	void CharAnimation(int delta);
	void CharFollowCamera(int delta);

	void CharAniStart();
	void CharAniStop();

	void T_UnitAddTilemap();

	void DebugTilemapDate();

	void timelineIndex0(int delta);
	void timelineIndex1(int delta);
	void timelineIndex2(int delta);
	void timelineIndex3(int delta);





public:

	CMap* cmap;
	GUI* UI;

	TIMELINE* Timeline;
	HFONT hFont;
	CTileMap* CTilemap;
	Script* mScript;
	//Charator
	ARES* ares;
	AEKTER* aekter;
	SOLDIER2* soldier2;
	ARCHER* archer;
	HORSE_GENERAL* horse_general;
	SOLDIER5* soldier5;
	HORSE_SOLDIER* horse_soldier;
	HORSE_AEKTER* horse_aekter;

	int delta;
	bool CharAniEnd;
	bool LocationEnd;
	bool anicheck;
	bool FinishedCheck;
	bool ClickLock;

};

