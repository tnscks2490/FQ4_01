#pragma once
#include "IScene.h"
class IntroScene8 :
    public IScene
{
public:

    IntroScene8();
    ~IntroScene8();

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

    const int IntroIndex = 7;
    bool FinishedCheck;
    bool checkend;
    int delta;
    int second;
    int endLine;
    int DeltaFirst;
    int DeltaLast;

};

