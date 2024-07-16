#pragma once
#include "IScene.h"
#include "CUnit.h"
#include "Script.h"


class CMap;
class GUI;
class TIMELINE;
class Script;

class KarionScene3 : public IScene
{
public:
	KarionScene3();
	~KarionScene3();

    virtual bool IsFinished() override;
    virtual void onFrameMove() override;
    virtual void onDraw(HDC hdc) override;
    virtual void onMouseDown(UINT x, UINT y, UINT left_right);
    virtual void onMouseMove(UINT x, UINT y);
    virtual void onKeyDown(KeyInput* virtual_key) override;


    void CharDraw(HDC hdc);
    void CharAnimation(int delta);
    void CharSetPos();


public:

    CMap* KC_Outside;
    CMap* KC_Inside;
    Script* mScript;

    GUI* UI;
    HFONT hFont;

    TIMELINE* Timeline;

    GRIFFIN griffin;
    ARES ares;
    GONRAD gonrad;
    ALFRED alfred;
    RADINKAL radinkal;




    int delta = 0;
    bool ClickLock = false;
    bool anicheck = false;
    bool CharAniEnd = false;
    bool FinishedCheck = false;
    bool LocationEnd = false;
};

