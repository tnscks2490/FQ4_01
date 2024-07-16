#pragma once
#include "Csprite.h"
#include "IScene.h"
#include "Canimation.h"

class IntroScene1 :
    public IScene
{
public:

    IntroScene1();
    ~IntroScene1();

    virtual bool IsFinished() override;
    virtual void onFrameMove() override;
    virtual void onDraw(HDC hdc) override;
    virtual void onKeyDown(KeyInput* virtual_key) override;

    bool DelayFirst();
    bool DelayLast();

public:
    CImagefile* Introfile;
    CImagefile* Blackfile;

    HFONT hFont;
    Csprite mBG;
    Csprite BlackBG;


    int delta;
    int second;
    int endLine;
    int DeltaFirst;
    int DeltaLast;
    bool FinishedCheck;
    bool checkend;
    

    const int IntroIndex = 0;
};

