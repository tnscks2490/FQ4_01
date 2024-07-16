#pragma once

#include "IScene.h"
#include "CUnit.h"
#include "Script.h"

class CMap;
class GUI;
class TIMELINE;
class Script;


class BarsiaScene3 : public IScene
{
public:

    BarsiaScene3();
    ~BarsiaScene3();

    virtual bool IsFinished() override;
    virtual void onFrameMove() override;
    virtual void onDraw(HDC hdc) override;
    virtual void onMouseDown(UINT x, UINT y, UINT left_right);
    virtual void onMouseMove(UINT x, UINT y);
    virtual void onKeyDown(KeyInput* virtual_key) override;

    void AniCharPosSet();
    void ObjectPosSet();

    void AniCharDraw(HDC hdc);
    void ObjectDraw(HDC hdc);
    void CharAnimation(int delta);

    void CharFollowCamera(int x, int y);
    void CharFollowCameraSet(int x, int y);

    void ObjAniAllStop();
    void ObjAniAllStart();


public:

    // 맵
    CMap* cmap;
    CMap* YellowFlash;
    CMap* window;
    CMap* grating_close;
    CMap* grating_open;
    CMap* cmap2;
    Script* mScript;
    
    // UI
    GUI* UI;
    HFONT hFont;  //폰트
    
    //시스템
    TIMELINE* Timeline;


    //캐릭터
    ARES ares;
    GARRARD garrard;
    SOLDIER2 soldier2[7];
    GRIFFIN griffin[6];

    // 오브젝트
    BRAZIER brazier[2];
    G_FLAG g_flag[3];


    int delta;
    bool ClickLock = false;
    bool anicheck = false;
    bool CharAniEnd = false;
	bool FinishedCheck = false;
    bool LocationEnd = false;
};

