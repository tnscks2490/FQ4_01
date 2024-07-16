#pragma once
#include "IScene.h"
class IntroLoby :
    public IScene
{
public:

    IntroLoby();
    ~IntroLoby();

    virtual bool IsFinished() override;
    virtual void onFrameMove() override;
    virtual void onDraw(HDC hdc) override;
    virtual void onMouseMove(UINT x, UINT y) override;
    virtual void onMouseDown(UINT x, UINT y, UINT left_right) override;
    virtual void onKeyDown(KeyInput* virtual_key) override;

    void Cblock(HDC hdc);

    bool DelayFirst();
    bool DelayLast();

public:
    CImagefile* Introfile;
    CImagefile* Yellowfile;
    CImagefile* Blackfile;

    HFONT hFont;
    Csprite mBG;
    Csprite Yellowblock;
    Csprite BlackBG;


    int delta;
    int second;
    int endLine;
    int DeltaFirst;
    int DeltaLast;
    bool FinishedCheck;
    bool checkend;

    UINT xpos;
    UINT ypos;


    const int IntroIndex = 0;
};

