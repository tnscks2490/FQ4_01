#pragma once
#include "IScene.h"

class IntroScene9 :
    public IScene
{
public:

    IntroScene9();
    ~IntroScene9();

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

    const int IntroIndex = 8;
    bool FinishedCheck;
    bool checkend;
    int delta;
    int second;
    int endLine;
    int DeltaFirst;
    int DeltaLast;

};

