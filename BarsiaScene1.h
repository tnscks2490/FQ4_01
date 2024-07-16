#pragma once
#include "IScene.h"
#include "CUnit.h"

class CMap;
class TIMELINE;
class GUI;
class Script;

class BarsiaScene1 :
    public IScene
{
    //�Լ�
public:
    BarsiaScene1();
    ~BarsiaScene1();

    virtual bool IsFinished() override;
    virtual void onFrameMove() override;
    virtual void onDraw(HDC hdc) override;
    virtual void onMouseDown(UINT x, UINT y, UINT left_right);
    virtual void onMouseMove(UINT x, UINT y);
    virtual void onKeyDown(KeyInput* virtual_key) override;

    void CharAnimation(int delta);
    void CharDraw(HDC hdc);
    void CharCameraFollow(int x, int y);
    void CharSetPos();

    void ScreenCharDraw(HDC hdc);
    void ScreenCharSetPos();
    // �ѱ��� �ڵ�


    //����
public:
    //�� �̹���
    CMap* Bg;
    CMap* ScreenBg;
    CMap* ScreenUI;

    //UI �̹���
    GUI* UI;


    // ��ũ��, ������
    HFONT hFont;

    // ���� ������
    TIMELINE* Timeline;
    Script* mScript;





    SOLDIER2 soldier2[12];
    SOLDIER1 soldier1[2];
    GENELU genelu;
    JANIL janil;
    THYHOOT thyhoot;
    MACGAIA macgaia;
    OGG ogg;
    MOLDRED moldred;

    GENELU sgenelu;
    JANIL sjanil;
    THYHOOT sthyhoot;
    MACGAIA smacgaia;
    OGG sogg;
    MOLDRED smoldred;



    KECK keck;
    GABI gabi;
    ORASON orason;
    LAIOS laios;
    MYSOLEN mysolen;
    MAREAM maream;
    SARK sark;

    int screeny=0;


    int delta = 0;
    bool LocationEnd = false;
    bool ClickLock = false;
    bool anicheck = false;
    bool FinishedCheck =false;
    bool CharAniEnd =false;
    bool ScreenOn = false;
};

