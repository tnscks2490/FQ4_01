#include "pch.h"
#include "CMap.h"
#include "GUI.h"
#include "CTileMap.h"
#include "CScreen.h"
#include "CGameFQ4.h"
#include "PlayMain.h"
#include "PlayMenuUI.h"
#include "ActionMenuUI.h"

PlayMain::PlayMain()
{
    Main = new CMap(MAKEINTRESOURCE(IDB_MAINMENU_BG), L"IDB_MAINMENU_BG");
    Main->mScreen.mdestX = 0;
    Main->mScreen.mdestY = 0;
    
    BGScreen = new CScreen(CApplication::theApp->sHDC, 640, 480);

    PMenuScreen = new CScreen(CApplication::theApp->sHDC, 256, 256);
    PMenuScreen->SetPos(384, 0);

    AMenuScreen = new CScreen(CApplication::theApp->sHDC, 256, 256);
    AMenuScreen->Clear(RGB(255, 0, 255));
    AMenuScreen->SetPos(384, -256);

    PMUI = new PlayMenuUI;
    PMUI->pScreen = PMenuScreen;
    AMUI = new ActionMenuUI;
    AMUI->pScreen = AMenuScreen;


    CurrentScreen = PMUI->pScreen;
}

PlayMain::~PlayMain()
{
    delete PMUI;
    delete AMUI;
    delete Main;
    delete BGScreen;
    delete PMenuScreen;
    delete AMenuScreen;
}

bool PlayMain::IsFinished()
{
    return false;
}

void PlayMain::onFrameMove()
{
    //해당 숫자값은 스크린의 크기이므로 나중에 비율로 할때 바꿀것!
    //if (IsScreenMove)
    //{
    //    if (CurrentScreen == AMUI->pScreen)
    //    {
    //        if (PMUI->pScreen->posX <= 640)
    //            PMUI->pScreen->MoveScreen(16, 0);
    //        if (AMUI->pScreen->posY < 0 && PMUI->pScreen->posX > 640)
    //            AMUI->pScreen->MoveScreen(0, 16);
    //    }
    //    else if (CurrentScreen == PMUI->pScreen)
    //    {
    //        if (AMUI->pScreen->posY > -256)
    //            AMUI->pScreen->MoveScreen(0, -16);
    //        if (PMUI->pScreen->posX > 384 && AMUI->pScreen->posY <= -256)
    //            PMUI->pScreen->MoveScreen(-16, 0);
    //    }
    //}
    if (CurrentScreen == AMUI->pScreen)
    {
        if (PMUI->pScreen->posX <= 640)
            PMUI->pScreen->MoveScreen(16, 0);
        if (AMUI->pScreen->posY < 0 && PMUI->pScreen->posX > 640)
            AMUI->pScreen->MoveScreen(0, 16);
    }
    else if (CurrentScreen == PMUI->pScreen)
    {
        if (AMUI->pScreen->posY > -256)
            AMUI->pScreen->MoveScreen(0, -16);
        if (PMUI->pScreen->posX > 384 && AMUI->pScreen->posY <= -256)
            PMUI->pScreen->MoveScreen(-16, 0);
    }
  
}

void PlayMain::onDraw(HDC hdc)
{
    HFONT oldFont;
    oldFont = (HFONT)SelectObject(hdc, PMUI->hFont);
    SetBkMode(CurrentScreen->m_HDC, TRANSPARENT);
    SetTextColor(CurrentScreen->m_HDC, RGB(255, 255, 255));
    SetTextAlign(PMenuScreen->m_HDC, TA_CENTER);
    //SetTextAlign(AMenuScreen->m_HDC, TA_LEFT);
     
    Main->Draw(BGScreen->m_HDC);
    BGScreen->Draw(hdc);

    PMUI->Draw(PMUI->pScreen->m_HDC);
    PMenuScreen->Draw(hdc);
    
    AMUI->Draw(AMUI->pScreen->m_HDC);
    AMenuScreen->TransDraw(hdc);

    SelectObject(PMenuScreen->m_HDC, oldFont);
}

void PlayMain::onMouseDown(UINT x, UINT y, UINT left_right)
{
    if (CurrentScreen == PMUI->pScreen)
    {
        if(PMUI->OnMouseDown(x, y, left_right));
        {
            AMUI->CVIcon_PMUIToAMUI(PMUI->CurIcon);
            CurrentScreen = AMUI->pScreen;
        }
    }
    else if (CurrentScreen == AMUI->pScreen)
    {
        if (AMUI->OnMouseDown(x, y, left_right))
        {
            if (AMUI->CurIcon == Exit)
            {
                CurrentScreen = PMUI->pScreen;
            }
            else if (AMUI->CurIcon == Info)
            {

            }

        }
    }
}

void PlayMain::onMouseMove(UINT x, UINT y)
{
    // 메뉴에 마우스 올렸을 때 텍스트 출력
    if (CurrentScreen == PMUI->pScreen)
    {
        if (PMUI->Is마우스가내안에(x, y))
            PMUI->OnMouseMove(x, y); 
    }
    else if (CurrentScreen == AMUI->pScreen)
    {
        if (AMUI->Is마우스가내안에(x, y))
            AMUI->OnMouseMove(x, y);
    }
    
}

void PlayMain::onKeyDown(KeyInput* virtual_key)
{

}

