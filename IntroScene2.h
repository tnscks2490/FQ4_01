#pragma once
#include "IScene.h"
class IntroScene2 :
    public IScene
{

public:
    virtual bool IsFinished() override;
    virtual void onFrameMove() override;
    virtual void onDraw(HDC hdc) override;

    IntroScene2();
    ~IntroScene2();
    bool DelayFirst();
    bool DelayLast();

public:
    CImagefile* Introfile;
    CImagefile* Blackfile;

    HFONT hFont;
    Csprite mBG;
    Csprite BlackBG;

    const int IntroIndex = 1;
    bool FinishedCheck;
    bool checkend;
    int delta;
    int second;
    int endLine;
    int DeltaFirst;
    int DeltaLast;

};

