#pragma once
#include "IScene.h"

#include "MoveMapInfo.h"

class CMap;
class GUI;
class PlayMenuUI;
class CScreen;
class ActionMenuUI;
class UIManagement;



class PlayMain :
    public IScene
{
public:

    virtual bool IsFinished();
    virtual void onFrameMove() override;
    virtual void onDraw(HDC hdc) override;
    virtual void onMouseDown(UINT x, UINT y, UINT left_right);
    virtual void onMouseMove(UINT x, UINT y);
    virtual void onKeyDown(KeyInput* virtual_key) override;



public:
    PlayMain();
    ~PlayMain();

    CMap* Main;
    GUI* UI;
    PlayMenuUI* PMUI;
    ActionMenuUI* AMUI;
    UIManagement* UIM;

    CScreen* CurrentScreen = nullptr;

    CScreen* BGScreen;
    CScreen* PMenuScreen;
    CScreen* AMenuScreen;


    bool IsMainMenu = true;
    int MoveFrame = 0;
    bool IsScreenMove = false;

};

