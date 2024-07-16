#include "pch.h"
#include "KarionScene2.h"
#include "CMap.h"
#include "GUI.h"
#include "TIMELINE.h"
#include "CScreen.h"
#include "CTileMap.h"
#include "Script.h"

KarionScene2::KarionScene2()
{
    cmap = new CMap(RESOURCE_NAME(IDB_KARION_ROYALHOUSE));
    hFont = CreateFontW(18, 0, 0, 0, 0, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT("±Ã¼­"));
    UI = new GUI(L"KarionScene2");
    Timeline = new TIMELINE(8);
    mScript = new Script(UI->CurruntScene);

    delta = 0;
    LocationEnd = false;
    anicheck = false;
    CharAniEnd = false;
    ClickLock = false;

    ObjectPosSet();
    AniCharSet();
}

KarionScene2::~KarionScene2()
{
    delete cmap;
    delete UI;
    delete Timeline;
    delete mScript;
}

bool KarionScene2::IsFinished()
{
	return FinishedCheck;
}

void KarionScene2::onFrameMove()
{
    if (anicheck)
    {
        delta++;
        CharAnimation(delta);
        if (CharAniEnd)
        {
            Timeline->Textline[Timeline->index] = true;
            anicheck = false;
            delta = 0;
            CharAniEnd = false;
        }
    }
}

void KarionScene2::CharAnimation(int delta)
{
    switch (Timeline->index)
    {
    case 0:
        ClickLock = false;
        if (delta < 100)
        {
            if (delta == 1) aerain.ChangeAnimation(L"Char_F");
            if(delta % 5 == 0) aerain.SetPosition(aerain.FrameSprite.mdestX, aerain.FrameSprite.mdestY + 5);
        }
        else if (delta >= 100 and delta < 110)
        {
            if (delta == 100) aerain.ChangeAnimation(L"Char_FSDS");
        }
        else if (delta >= 110 and delta < 205)
        {
            if (delta == 110) aerain.ChangeAnimation(L"Char_L");
            if (delta % 5 == 0) aerain.SetPosition(aerain.FrameSprite.mdestX-5, aerain.FrameSprite.mdestY);
            if (delta == 201) aerain.ChangeAnimation(L"Char_LSUS");
        }
        else if (delta > 205)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 3:
        ClickLock = false;
        if (delta < 85)
        {
            if (delta == 1) aerain.ChangeAnimation(L"Char_R");
            if(delta % 5 == 0) aerain.SetPosition(aerain.FrameSprite.mdestX+5, aerain.FrameSprite.mdestY);
            if (delta == 84) aerain.ChangeAnimation(L"Char_RSUS");
        }
        else if (delta > 84 and delta < 110)
        {
            if (delta == 95) aerain.ChangeAnimation(L"Char_FSUS");
        }
        else if (delta > 109 and delta < 175)
        {
            if (delta == 110) aerain.ChangeAnimation(L"Char_F");
            if (delta % 5 == 0) aerain.SetPosition(aerain.FrameSprite.mdestX, aerain.FrameSprite.mdestY-5);
            if (delta == 174) aerain.ChangeAnimation(L"Char_FSDS");
        }
        else if (delta > 200 and delta < 230)
        {
            if (delta == 201) aerain.ChangeAnimation(L"Char_F");
            if (delta % 5 == 0) aerain.SetPosition(aerain.FrameSprite.mdestX, aerain.FrameSprite.mdestY + 10);
        }
        else if (delta >= 230 and delta < 320)
        {
            if (delta == 230) aerain.ChangeAnimation(L"Char_BS");
            if (delta == 240) aerain.SetPosition(aerain.FrameSprite.mdestX, aerain.FrameSprite.mdestY + 15);
            if (delta == 250) aerain.ChangeAnimation(L"Char_AS");
            if (delta == 270) armor[1].ChangeAnimation(L"Char_HS");
            if (delta == 300) armor[1].ChangeAnimation(L"Char_FS");

        }
        else if (delta >= 320 and delta < 400)
        {
            if (delta == 320) aerain.ChangeAnimation(L"Char_L");
            if (delta % 5 == 0) aerain.SetPosition(aerain.FrameSprite.mdestX-5, aerain.FrameSprite.mdestY);
        }
        else if (delta >= 400 and delta < 420)
        {
            if (delta == 400) aerain.ChangeAnimation(L"Char_LSUS");
        }
        else if (delta > 420)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 6:
        ClickLock = false;
        if (delta < 64)
        {
            if (delta == 1)
            {
                aerain.ChangeAnimation(L"Char_FSUS");
                gonrad.ChangeAnimation(L"Char_FSUS");
            }
            if (delta % 2 == 0)
            {
                cmap->CameraMove(0, 2);
                aerain.CameraFollow(0, 2);
                gonrad.CameraFollow(0, 2);
                candlestick[0].CameraFollow(0, 2);
                candlestick[1].CameraFollow(0, 2);
                armor[0].CameraFollow(0, 2);
                armor[1].CameraFollow(0, 2);
            }
            if (delta == 63)
            {
                cmap->CameraMove(0, 1);
                aerain.CameraFollow(0, 1);
                gonrad.CameraFollow(0, 1);
                candlestick[0].CameraFollow(0, 1);
                candlestick[1].CameraFollow(0, 1);
                armor[0].CameraFollow(0, 1);
                armor[1].CameraFollow(0, 1);
            }
        }
        else if (delta >= 80 and delta <= 340)
        {
            if (delta == 80)
            {
                crow[2].SetPosition(273, 305);
                crow[2].Alive = true;
                crow[2].ChangeAnimation(L"Char_FKD");
            }
            if (delta == 95)
            {
                crow[2].ChangeAnimation(L"Char_FKU");
            }
            if (delta == 110)
            {
                crow[2].ChangeAnimation(L"Char_BRS");
                crow[3].SetPosition(337, 305);
                crow[3].Alive = true;
                crow[3].ChangeAnimation(L"Char_FKD");
            }
            if (delta == 130)
            {
                crow[3].ChangeAnimation(L"Char_FKU");
                crow[1].SetPosition(210, 290);
                crow[1].ChangeAnimation(L"Char_FKD");
                crow[1].Alive = true;
            }
            if (delta == 135)
            {
                crow[4].SetPosition(400, 290);
                crow[4].ChangeAnimation(L"Char_FKD");
                crow[4].Alive = true;
                
            }
            if (delta == 140)
            {
                crow[0].SetPosition(145, 275);
                crow[0].ChangeAnimation(L"Char_FKD");
                crow[0].Alive = true;
            }
            if (delta == 150)
            {
                crow[1].ChangeAnimation(L"Char_FKU");
                crow[4].ChangeAnimation(L"Char_FKU");
                crow[0].ChangeAnimation(L"Char_FKU");
            }
            if (delta == 160)
            {
                crow[3].ChangeAnimation(L"Char_BRS");
                crow[1].ChangeAnimation(L"Char_BRS");
                crow[4].ChangeAnimation(L"Char_BRS");
                crow[0].ChangeAnimation(L"Char_BRS");
                crow[5].Alive = true;
                crow[5].SetPosition(460, 275);
            }
            if (delta == 165) crow[5].ChangeAnimation(L"Char_FSUS");
            if (delta == 175) crow[5].ChangeAnimation(L"Char_LLS");
            if (delta == 180) crow[5].ChangeAnimation(L"Char_RLS");
            if (delta == 185) crow[5].ChangeAnimation(L"Char_LLS");
            if (delta == 190) crow[5].ChangeAnimation(L"Char_RLS");
            if (delta == 200) crow[5].ChangeAnimation(L"Char_FKD");
            if (delta == 220) crow[5].ChangeAnimation(L"Char_FKU");

            if (delta == 240)
            {
                crow[0].ChangeAnimation(L"Char_R");
                crow[1].ChangeAnimation(L"Char_R");
                crow[5].ChangeAnimation(L"Char_L");
                crow[2].ChangeAnimation(L"Char_B");
                crow[3].ChangeAnimation(L"Char_B");
                crow[4].ChangeAnimation(L"Char_B");
            }

            if (delta == 340)
            {
                crow[0].ChangeAnimation(L"Char_RRS");
                crow[1].ChangeAnimation(L"Char_RRS");
                crow[2].ChangeAnimation(L"Char_BLS");
                crow[3].ChangeAnimation(L"Char_BLS");
                crow[4].ChangeAnimation(L"Char_BLS");
                crow[5].ChangeAnimation(L"Char_LLS");
            }
        }
        else if (delta > 340)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 7:
        ClickLock = false;
        if (delta < 10)
        {
            if (delta == 1)
            {
                crow[0].ChangeAnimation(L"Char_R");
                crow[5].ChangeAnimation(L"Char_L");
                for (int i = 1; i < 5; i++)
                    crow[i].ChangeAnimation(L"Char_B");
            }

            if (delta == 5)
            {
                aerain.ChangeAnimation(L"Char_LSDS");
                aerain.SetPosition(aerain.FrameSprite.mdestX-32, aerain.FrameSprite.mdestY);
            }
        }
        else if (delta >= 30 and delta < 100)
        {
            if (delta == 30) aerain.ChangeAnimation(L"Char_F");
            if (delta % 5 == 0)
            {
                aerain.SetPosition(aerain.FrameSprite.mdestX, aerain.FrameSprite.mdestY+10);
            }

            if (delta == 40)
            {
                crow[1].ChangeAnimation(L"Char_R");
                crow[4].ChangeAnimation(L"Char_L");
            }

            if (delta == 70)
            {
                crow[2].ChangeAnimation(L"Char_R");
                crow[3].ChangeAnimation(L"Char_L");
            }

            if (delta == 96)
            {
                aerain.SetPosition(aerain.FrameSprite.mdestX, aerain.FrameSprite.mdestY + 2);
                aerain.ChangeAnimation(L"Char_FSDS");

                crow[2].ChangeAnimation(L"Char_F");
                crow[3].ChangeAnimation(L"Char_F");
            }
        }
        else if (delta > 110)
        {
            CharAniEnd = true;
            ClickLock = true;
            FinishedCheck = true;
        }
        break;
    default:
        break;
    }
}

void KarionScene2::ObjectPosSet()
{
    candlestick[0].SetPosition(80, 289 - (cmap->CameraY));
    candlestick[1].SetPosition(510, 289 - (cmap->CameraY));
    armor[0].SetPosition(190, 270 - (cmap->CameraY));
    armor[1].SetPosition(415, 270 - (cmap->CameraY));
}

void KarionScene2::ObjectDraw(HDC hdc)
{
    candlestick[0].Draw(hdc);
    candlestick[1].Draw(hdc);
    armor[0].Draw(hdc);
    armor[1].Draw(hdc);

}
void KarionScene2::AniCharSet()
{
    aerain.ChangeAnimation(L"Char_FSUS");
    aerain.SetPosition(432, 160 - (cmap->CameraY));
    gonrad.ChangeAnimation(L"Char_RSUS");
    gonrad.SetPosition(273, 255);

    for (int i = 0; i < 6; i++) crow[i].Alive = false;
}



void KarionScene2::AniCharDraw(HDC hdc)
{
    aerain.Draw(hdc);
    gonrad.Draw(hdc);
    for (int i = 0; i < 6; i++) crow[i].Draw(hdc);
}


void KarionScene2::onDraw(HDC hdc)
{
    HFONT oldFont;
    oldFont = (HFONT)SelectObject(hdc, hFont);
    SetBkMode(hdc, TRANSPARENT);

    cmap->Draw(hdc);
    AniCharDraw(hdc);
    ObjectDraw(hdc);

    UI->UIDraw(hdc);


    if (!LocationEnd)
    {
        UI->LocationDraw(hdc, L"Ä«¸®¿Â¼º ¿Õ½Ç");
    }
    switch (Timeline->index)
    {
    case 0:
        if (!Timeline->Textline[Timeline->index])
        {
            if (LocationEnd) anicheck = true;
        }
        else
            UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
        break;
    case 1:
        Timeline->Textline[Timeline->index] = true;
        UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
        break;
    case 2:
        Timeline->Textline[Timeline->index] = true;
        UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
    case 3:
        if (!Timeline->Textline[Timeline->index])
        {
            if (LocationEnd) anicheck = true;
        }
        else
            UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
        break;
    case 4:
        Timeline->Textline[Timeline->index] = true;
        UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
        break;
    case 5:
        Timeline->Textline[Timeline->index] = true;
        UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
        break;
    case 6:
        if (!Timeline->Textline[Timeline->index])
        {
            if (LocationEnd) anicheck = true;
        }
        else
            UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
        break;
    case 7:
        if (!Timeline->Textline[Timeline->index])
        {
            if (LocationEnd) anicheck = true;
        }
        break;
    default:
        break;
    }
}

void KarionScene2::onMouseDown(UINT x, UINT y, UINT left_right)
{
    if (!LocationEnd)
    {
        LocationEnd = true;
    }
    else
    {
        if (ClickLock)
        {
            if (Timeline->index < 8) Timeline->index++;
            else FinishedCheck = true;
        }
    }
}

void KarionScene2::onMouseMove(UINT x, UINT y)
{
}

void KarionScene2::onKeyDown(KeyInput* virtual_key)
{
    if (virtual_key->KeyDownkey == 32)
        FinishedCheck = true;
}

