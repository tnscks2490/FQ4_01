#pragma once
#include "IScene.h"


class CImagefile;
class CIntroScene :
    public IScene
{
public:
    CIntroScene();
    ~CIntroScene();

    virtual bool IsFinished() override;
    virtual void onFrameMove() override;
    virtual void onDraw(HDC hdc) override;

    bool DelayFirst();
    bool DelayLast();
    void FontSetting(HDC hdc);
public:

    CImagefile* Introfiles[10];


    Csprite mBG;
    int delta;
    int second;
    int endLine;
    int introIndex;
    int DeltaFirst;
    int DeltaLast;
};

