#pragma once
#include "IGame.h"
#include "IntroHeader.h"
#include "PlayMap.h"
#include "KeyInput.h"

class CGameFQ4 :
    public IGame
{
public:

    ~CGameFQ4();

    void onCreate();
    void onDestroy();
    void DestoryImgIntro();
    void DestoryAniIntro();
    void onChangeScene() override;
    virtual void onKeyDown(KeyInput* virtual_key) override;
    
public:

    // ¿Œ∆Æ∑Œæ¿
    IntroScene1* mIntro1;
    IntroScene2* mIntro2;
    IntroScene3* mIntro3;
    IntroScene4* mIntro4;
    IntroScene5* mIntro5;
    IntroScene6* mIntro6;
    IntroScene7* mIntro7;
    IntroScene8* mIntro8;
    IntroScene9* mIntro9;
    IntroScene10* mIntro10; 
    IntroLoby* mIntroLoby;
    BarsiaScene1* mBarsiaScene1;
    BarsiaScene2* mBarsiaScene2;
    KarionScene1* mKarionScene1;
    KarionScene2* mKarionScene2;
    FieldBattle* mFieldBattle;
    BarsiaScene3* mBarsiaScene3;
    KarionScene3* mKarionScene3;

    // Ω«¡¶ «√∑π¿Ã ∏ 
    KarionCastle_Altar* mKarionCastle_Altar;
    KarionCastle_AresRoom* mKarionCastle_AresRoom;
    KarionCastle_Armory* mKarionCastle_Armory;
    KarionCastle_Hall* mKarionCastle_Hall;
    KarionCastle_KingRoom* mKarionCastle_KingRoom;
    KarionCastle_Lab* mKarionCastle_Lab;
    KarionCastle_MeetingRoom* mKarionCastle_MeetingRoom;
    KarionCastle_Outside* mKarionCastle_Outside;

    TileTest* tiletest;
    PlayMain* mPlayMain;


    bool check = false;

    IScene* NextScene = nullptr;
};

