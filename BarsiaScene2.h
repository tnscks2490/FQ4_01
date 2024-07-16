#pragma once

#include "IScene.h"
#include "CUnit.h"
#include "Script.h"


class CMap;
class GUI;
class TIMELINE;
class Script;

class BarsiaScene2 : public IScene
{
public:

	BarsiaScene2();
	~BarsiaScene2();

    virtual bool IsFinished() override;
    virtual void onFrameMove() override;
    virtual void onDraw(HDC hdc) override;
    virtual void onMouseDown(UINT x, UINT y, UINT left_right);
    virtual void onMouseMove(UINT x, UINT y);
    virtual void onKeyDown(KeyInput* virtual_key) override;



    void BGCharDraw(HDC hdc);
    void BGCharSet();

    void AniCharDraw(HDC hdc);
    void AniCharSet();

    void AniChar_FrameDraw(HDC hdc);
    void AniChar_FrameSet();
    void CharAnimation(int delta);


public:

    // 맵
    CMap* cmap;
    CMap* blackmap;
    CMap* Inframe;
    Script* mScript;
    // UI
    GUI* UI;
    CImagefile* ScreenUI;
    Csprite scrUI;
    Csprite scrUI_src;
    HFONT hFont;  //폰트

    // 배경 병사
    SOLDIER2 BgSoldier2[12];
    SOLDIER1 soldier1[2];
    SOLDIER2 soldier2[4];
    ROCK_SOLDIER r_soldier[6];
    ARES ares;
    GENELU genelu;
    GENERAL general;

    // 가운데 병사

    TIMELINE* Timeline;

    int delta;
    int FixSC;
    bool screenmove;
    bool ClickLock;
    bool anicheck;
    bool FinishedCheck;
    bool CharAniEnd;

};

