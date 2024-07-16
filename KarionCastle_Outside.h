#pragma once
#include "IScene.h"
#include "MoveMapInfo.h"

class CMap;
class GUI;

class KarionCastle_Outside :
    public IScene
{
public:
    virtual bool IsFinished() override;
    virtual void onFrameMove() override;
    virtual void onDraw(HDC hdc) override;
    virtual void onMouseDown(UINT x, UINT y, UINT left_right);
    virtual void onMouseMove(UINT x, UINT y);
    virtual void onKeyDown(KeyInput* virtual_key) override;


 
    void MoveMap(std::wstring mapName);
    void SendPosInfo(CTileUnit* PlayTUnit, int x, int y);

public:

    KarionCastle_Outside();
    ~KarionCastle_Outside();

    CMap* KC_OS;
    GUI* UI;
    CTileMap* mTileMap;
    //HFONT hFont;
    ARES* ares;

    bool TileDrawON = false;
    bool IsOutMap = false;
};

