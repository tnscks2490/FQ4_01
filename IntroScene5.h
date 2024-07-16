#pragma once
#include "IScene.h"
class IntroScene5 :
    public IScene
{
public:

    IntroScene5();
    ~IntroScene5();

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

    const int IntroIndex = 4;
    bool FinishedCheck;
    bool checkend;
    int delta;
    int second;
    int endLine;
    int DeltaFirst;
    int DeltaLast;

};

