#pragma once
#include "IScene.h"
class IntroScene3 :
    public IScene
{
    
public:

    virtual bool IsFinished() override;
    virtual void onFrameMove() override;
    virtual void onDraw(HDC hdc) override;
    

    IntroScene3();
    ~IntroScene3();

    bool DelayFirst();
    bool DelayLast();

public:
    CImagefile* Introfile;
    CImagefile* Blackfile;

    HFONT hFont;
    Csprite mBG;
    Csprite BlackBG;

    const int IntroIndex = 2;
    bool FinishedCheck;
    bool checkend;
    int delta;
    int second;
    int endLine;
    int DeltaFirst;
    int DeltaLast;

};

