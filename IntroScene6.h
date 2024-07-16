#pragma once
#include "IScene.h"
class IntroScene6 :
    public IScene
{
public:
    IntroScene6();
    ~IntroScene6();

    virtual bool IsFinished() override;
    virtual void onFrameMove() override;
    virtual void onDraw(HDC hdc) override;

    bool DelayFirst();
    bool DelayLast();

public:
    CImagefile* Introfile;
    CImagefile* Blackfile;
    HFONT hFont;
    Csprite mBG;
    Csprite BlackBG;

    const int IntroIndex = 5;
    bool FinishedCheck;
    bool checkend;
    int delta;
    int second;
    int endLine;
    int DeltaFirst;
    int DeltaLast;

};

