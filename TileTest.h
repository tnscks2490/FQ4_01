#pragma once
#include "IScene.h"

class CMap;


class TileTest : public IScene
{

public:
    virtual bool IsFinished();
    virtual void onFrameMove() override;
    virtual void onDraw(HDC hdc) override;
    virtual void onMouseDown(UINT x, UINT y, UINT left_right);
    virtual void onMouseMove(UINT x, UINT y);
    virtual void onKeyDown(KeyInput* virtual_key) override;

public:

    TileTest();
    ~TileTest();

    CMap* cmap;
};