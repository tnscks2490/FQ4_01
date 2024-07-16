#pragma once
#include "pch.h"
#include "KarionScene1.h"
#include "resource.h"
#include "CMap.h"
#include "TIMELINE.h"
#include "Script.h"



#define RESOURCE_NAME(x) MAEKINTRESOURCE(x),L#x


KarionScene1::KarionScene1()
{
    hFont = CreateFontW(18, 0, 0, 0, 0, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT("궁서"));
    cmap = new CMap(MAKEINTRESOURCE(IDB_KARION_MEETINGROOM),L"IDB_KARION_MEETINGROOM");
    Timeline = new TIMELINE(12);
    BGCharPosSet();
    UI = new GUI(L"KarionScene1");

    mScript = new Script(UI->CurruntScene);

    delta = 0;
    LocationEnd = false;
    anicheck = false;
    CharAniEnd = false;
    ClickLock = false;

}

KarionScene1::~KarionScene1()
{
    delete cmap;
    delete Timeline;
    delete UI;
}

bool KarionScene1::IsFinished()
{
    return FinishedCheck;
}

void KarionScene1::onFrameMove()
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

void KarionScene1::CharAnimation(int delta)
{

    switch (Timeline->index)
    {
    case 0:
        ClickLock = false;
        if (delta == 10)
            ares.ChangeAnimation(L"Char_R");
        else if (delta < 166 && delta % 5 == 0)// delta % 5 == 0 mdestX+5
        {
            ares.SetPosition(ares.FrameSprite.mdestX + 5, ares.FrameSprite.mdestY);
            if (delta == 40) soldier4[2].ChangeAnimation(L"Char_B");
            if (delta == 50) soldier3[1].ChangeAnimation(L"Char_F");
            if (delta == 100) soldier4[0].ChangeAnimation(L"Char_L");
            if (delta == 120) soldier4[2].ChangeAnimation(L"Char_L");
            if (delta == 155) soldier4[1].ChangeAnimation(L"Char_L");
        }
        else if (delta < 261 )
        {
            if (delta == 166)ares.ChangeAnimation(L"Char_B");
            if (delta % 5 == 0)
            {
                ares.SetPosition(ares.FrameSprite.mdestX, ares.FrameSprite.mdestY - 5);

                if (delta == 220)
                {
                    soldier4[2].ChangeAnimation(L"Char_B");
                    gonrad.ChangeAnimation(L"Char_RSUS");
                }
            }
        }
        else if (delta > 260 && delta < 280)
        {
            if(delta == 265) ares.ChangeAnimation(L"Char_LSUS");
        }
        else if (delta > 280)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 2:
        ClickLock = false;
        if (delta < 140 && delta % 5 == 0)
        {
            if (delta == 5)
            {
                gonrad.SetPosition(gonrad.FrameSprite.mdestX, gonrad.FrameSprite.mdestY - 30);
                gonrad.ChangeAnimation(L"Char_B");
            }
            gonrad.SetPosition(gonrad.FrameSprite.mdestX + 5, gonrad.FrameSprite.mdestY);
            if (delta == 10) gonrad.ChangeAnimation(L"Char_R");
        }
        else if (delta < 190 && delta % 5 == 0)
        {
            gonrad.SetPosition(gonrad.FrameSprite.mdestX, gonrad.FrameSprite.mdestY + 5);
            if (delta == 140) gonrad.ChangeAnimation(L"Char_F");
            if (delta == 160) ares.ChangeAnimation(L"Char_BSUS");
        }
        else if (delta > 190)
        {
            if(delta == 195) gonrad.ChangeAnimation(L"Char_FSUS");
            if (delta == 200)
            {
                CharAniEnd = true;
                ClickLock = true;
            }
        }
        break;
    case 3:
        ClickLock = false;
        if (delta < 50)
        {
            if (delta == 5)
                ares.ChangeAnimation(L"Char_L");
            else if(delta == 10)
                ares.ChangeAnimation(L"Char_R");
            else if(delta == 15)
                ares.ChangeAnimation(L"Char_L");
            else if(delta == 20)
                ares.ChangeAnimation(L"Char_R");
            else if(delta == 30)
                ares.ChangeAnimation(L"Char_BSUS");
        }
        else
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 5:
        ClickLock = false;
        if (delta < 40)
        {
            if (delta == 5)
                ares.ChangeAnimation(L"Char_L");
            else if (delta == 10)
                ares.ChangeAnimation(L"Char_FSUS");
            else if (delta == 15)
                ares.ChangeAnimation(L"Char_R");
            else if (delta == 20)
                ares.ChangeAnimation(L"Char_BSUS");
        }
        else
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 6:
        ClickLock = false;
        if (delta < 40)
        {
            if (delta == 20) gonrad.ChangeAnimation(L"Char_Kneel");
        }
        else
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 7:
        ClickLock = false;
        if (delta < 40)
        {
            if (delta == 20) gonrad.ChangeAnimation(L"Char_FSUS");
        }
        else {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 9:
        ClickLock = false;
        if (delta < 100 && delta % 5 == 0)// delta % 5 == 0 mdestX+5
        {
            if (delta == 5) ares.ChangeAnimation(L"Char_F");
            ares.SetPosition(ares.FrameSprite.mdestX, ares.FrameSprite.mdestY+5);

            if (delta == 50) soldier4[2].ChangeAnimation(L"Char_L");
        }
        else if (delta < 260 && delta % 5 == 0)
        {
            if (delta == 100)ares.ChangeAnimation(L"Char_L");
            if (delta == 110)soldier4[1].ChangeAnimation(L"Char_F");
            ares.SetPosition(ares.FrameSprite.mdestX-5, ares.FrameSprite.mdestY);

            if (delta == 160)
            {
                soldier4[2].ChangeAnimation(L"Char_B");
                soldier4[0].ChangeAnimation(L"Char_F");
            }

            if (delta == 255) soldier4[2].ChangeAnimation(L"Char_R");
        }
        else if (delta < 290)
        {
            if (delta == 275)
            {
                ares.ChangeAnimation(L"Char_FSDS");
                ares.SetPosition(ares.FrameSprite.mdestX, ares.FrameSprite.mdestY + 30);
            }
        }
        else if (delta < 310)
        {
            if (delta % 5 == 0)
                aerain.SetPosition(aerain.FrameSprite.mdestX, aerain.FrameSprite.mdestY - 10);
        }
        else if (delta > 310)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 10:
        ClickLock = false;
        if (delta < 40)
        {
            if (delta == 5) ares.ChangeAnimation(L"Char_L");
            if (delta == 10) ares.ChangeAnimation(L"Char_R");
            if (delta == 15) ares.ChangeAnimation(L"Char_L");
            if (delta == 20) ares.ChangeAnimation(L"Char_R");
            if (delta == 25) ares.ChangeAnimation(L"Char_FSDS");
        }
        else {
            CharAniEnd = true;
            ClickLock = true;        
        }
        break;
    case 11:
        ClickLock = false;
        if (delta < 30)
        {
            if (delta == 10)
            {
                ares.ChangeAnimation(L"Char_R");
                ares.SetPosition(ares.FrameSprite.mdestX + 30, ares.FrameSprite.mdestY);
            }
            if (delta == 20)
            {
                ares.ChangeAnimation(L"Char_F");
            }
        }
        else if (delta < 70 && delta % 5 == 0)
        {
            if (delta == 30)
            {
                soldier4[2].ChangeAnimation(L"Char_F");
                aerain.ChangeAnimation(L"Char_RSDS");
            }
            if (delta == 40) {
                aerain.ChangeAnimation(L"Char_FSDS");
                soldier3[0].ChangeAnimation(L"Char_F");
            }
            ares.SetPosition(ares.FrameSprite.mdestX, ares.FrameSprite.mdestY + 10);
        }
        else if (delta < 90 && delta % 5 == 0)
        {
            if (delta == 70)soldier4[2].SetPosition(soldier4[2].FrameSprite.mdestX-30, soldier4[2].FrameSprite.mdestY);
            if (delta == 75)
            {
                soldier4[2].ChangeAnimation(L"Char_R");
                soldier4[3].SetPosition(soldier4[3].FrameSprite.mdestX + 30, soldier4[3].FrameSprite.mdestY);
            }
            if (delta == 80)
            {
                soldier4[3].ChangeAnimation(L"Char_F");
                soldier4[2].ChangeAnimation(L"Char_F");
            }
        }
        else if (delta < 130 && delta % 5 == 0)
        {
            soldier4[2].SetPosition(soldier4[2].FrameSprite.mdestX, soldier4[2].FrameSprite.mdestY+10);
            soldier4[3].SetPosition(soldier4[3].FrameSprite.mdestX, soldier4[3].FrameSprite.mdestY+10);
        }
        else if (delta > 130)
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

void KarionScene1::BGCharDraw(HDC hdc)
{
    archbishop.Draw(hdc);
    ares.Draw(hdc);
    gonrad.Draw(hdc);
    aekter.Draw(hdc);
    aerain.Draw(hdc);

    for(int i=0;i <2;i++)
        soldier3[i].Draw(hdc);
    
    for(int i=0;i <4;i++)
        soldier4[i].Draw(hdc);

}

void KarionScene1::BGCharPosSet()
{
    // 배경 병사
    soldier3[0].SetPosition(100, 140);
    soldier3[0].ChangeAnimation(L"Char_R");
    soldier3[1].SetPosition(513, 140);
    soldier3[1].ChangeAnimation(L"Char_L");

    soldier4[0].SetPosition(208, 110);
    soldier4[1].SetPosition(272, 110);

    soldier4[2].SetPosition(370, 320);
    soldier4[2].ChangeAnimation(L"Char_R");

    soldier4[3].SetPosition(240, 320);
    soldier4[3].ChangeAnimation(L"Char_L");
    

    // 캐릭터
    aekter.SetPosition(400, 110);

    gonrad.SetPosition(336, 110);
    gonrad.ChangeAnimation(L"Char_FSUS");

    archbishop.SetPosition(240, 80);

    ares.SetPosition(310, 285);
    ares.ChangeAnimation(L"Char_FSUS");

    aerain.SetPosition(305, 390);
    aerain.ChangeAnimation(L"Char_B");
}

void KarionScene1::onDraw(HDC hdc)
{
    HFONT oldFont;
    oldFont = (HFONT)SelectObject(hdc, hFont);
    SetBkMode(hdc, TRANSPARENT);

    cmap->Draw(hdc);
    BGCharDraw(hdc);
    UI->UIDraw(hdc);

    if (!LocationEnd)
    {
        UI->LocationDraw(hdc, L"카리온성 회의실");
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
        if (!Timeline->Textline[Timeline->index])
        {
            if (LocationEnd) anicheck = true;
        }
        else
            UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
        break;
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
        if (!Timeline->Textline[Timeline->index])
        {
            if (LocationEnd) anicheck = true;
        }
        else
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
        else
            UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
        break;
    case 8:
        Timeline->Textline[Timeline->index] = true;
        UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
        break;
    case 9:
        if (!Timeline->Textline[Timeline->index])
        {
            if (LocationEnd) anicheck = true;
        }
        else
            UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
        break;
    case 10:
        if (!Timeline->Textline[Timeline->index])
        {
            if (LocationEnd) anicheck = true;
        }
        else
            UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
        break;
    case 11:
        if (!Timeline->Textline[Timeline->index])
        {
            if (LocationEnd) anicheck = true;
        }
        break;
    default:
        break;
    }
}

void KarionScene1::onMouseDown(UINT x, UINT y, UINT left_right)
{
    if (!LocationEnd)
    {
        LocationEnd = true;
        ares.ChangeAnimation(L"Char_R");
    }
    else
    {
        if (ClickLock)
        {
            if (Timeline->index < 11) Timeline->index++;
            else FinishedCheck = true;
        }
    } 
}

void KarionScene1::onMouseMove(UINT x, UINT y)
{

}

void KarionScene1::onKeyDown(KeyInput* virtual_key)
{
    if (virtual_key->KeyDownkey == 32)
        FinishedCheck = true;
}