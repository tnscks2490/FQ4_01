#include "pch.h"
#include "KarionScene3.h"
#include "CMap.h"
#include "GUI.h"
#include "TIMELINE.h"

KarionScene3::KarionScene3()
{
    KC_Outside = new CMap(RESOURCE_NAME(IDB_KARION_CASTLE_PART1));
    KC_Outside->Visible = true;
    KC_Inside = new CMap(RESOURCE_NAME(IDB_KARION_CASTLE_ROOM1));
    KC_Inside->Visible = false;
    Timeline = new TIMELINE(27);
	hFont = CreateFontW(18, 0, 0, 0, 0, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT("궁서"));

    UI = new GUI(L"KarionScene3");
    mScript = new Script(UI->CurruntScene);



    ares.Alive = false;
    gonrad.Alive = false;
    alfred.Alive = false;
    radinkal.Alive = false;
    CharSetPos();
}

KarionScene3::~KarionScene3()
{
    DeleteObject(hFont);
}

bool KarionScene3::IsFinished()
{
	return FinishedCheck;
}

void KarionScene3::CharDraw(HDC hdc)
{
    griffin.Draw(hdc);
    ares.Draw(hdc);
    gonrad.Draw(hdc);
    alfred.Draw(hdc);
    radinkal.Draw(hdc);
}

void KarionScene3::CharAnimation(int delta)
{
    switch (Timeline->index)
    {
    case 0:
        ClickLock = false;
        if (delta < 120)
        {
            if (delta % 5 == 0) griffin.Move(0, 10);
        }
        if (delta == 130) griffin.ChangeAnimation(L"Char_ARES_FR");
        if (delta == 148) griffin.Move(0, 15);
        if (delta == 150) griffin.ChangeAnimation(L"Char_ARES_RO");
        if (delta == 170) griffin.ChangeAnimation(L"Char_ARES_R");
        if (delta == 190)
        {
            griffin.ChangeAnimation(L"Char_WS");
            ares.Alive = true;
        }
        if (delta > 200 and delta < 235)
        {
            if (delta % 5 == 0) ares.Move(0, 16);
        }
        if (delta == 235) ares.ChangeAnimation(L"Char_FSUS");
        if (delta >= 255 and delta < 300)
        {
            if (delta == 255) ares.ChangeAnimation(L"Char_R");
            if (delta % 5 == 0) ares.Move(16, 0);
        }
        if (delta == 300) ares.ChangeAnimation(L"Char_FSUS");
        if (delta == 310)
        {
            ares.ChangeAnimation(L"Char_LSUS");
            griffin.Move(0, -20);
            griffin.ChangeAnimation(L"Char_FR");
        }
        if (delta >= 320 and delta < 430)
        {
            if (delta == 320) griffin.ChangeAnimation(L"Char_FLY_ALONE");
            if (delta % 5 == 0) griffin.Move(0, 10);
        }
        if (delta >= 430 and delta < 460)
        {
            if (delta == 430) ares.ChangeAnimation(L"Char_R");
            if (delta % 5 == 0) ares.Move(16, 0);
        }
        if (delta == 460) ares.Move(8, 0);
        if (delta == 465) ares.ChangeAnimation(L"Char_FSDS");
        if (delta == 470)
        {
            ares.ChangeAnimation(L"Char_BSUS");
            ares.Move(0, -28);
        }
        if (delta == 475) ares.Move(0, -16);
        if (delta == 480) ares.ChangeAnimation(L"Char_FSDS");

        ///// 카리온 건물 안쪽
        if (delta == 490)
        {
            KC_Inside->Visible = true;
            KC_Outside->Visible = false;
            KC_Inside->CameraPosSetting(15, 175);
            ares.SetPosition(305, 320);
            ares.ChangeAnimation(L"Char_B");
        }
        if (delta > 490 and delta < 535)
        {
            if (delta % 5 == 0) ares.Move(0, -16);
        }
        if (delta == 535)
        {
            KC_Inside->CameraMove(0, -16);
            ares.ChangeAnimation(L"Char_BSUS");
            gonrad.Alive = true;
        }
        if (delta == 540)
        {
            KC_Inside->CameraMove(0, -16);
            ares.ChangeAnimation(L"Char_BSDS");
            gonrad.Move(0, 16);
        }
        if (delta == 545)
        {
            gonrad.Move(0, 16);
            gonrad.ChangeAnimation(L"Char_FSDS");
        }
        if (delta == 560) gonrad.ChangeAnimation(L"Char_R");
        if (delta > 560 and delta < 605)
        {
            if(delta % 5 == 0) gonrad.Move(16, 0);
        }
        if (delta == 605) gonrad.ChangeAnimation(L"Char_FSDS");
        if (delta >= 615 and delta < 645)
        {
            if (delta == 615) gonrad.ChangeAnimation(L"Char_F");
            if (delta % 5 == 0) gonrad.Move(0, 16);
        }
        if (delta == 645) gonrad.ChangeAnimation(L"Char_FSUS");
        else if (delta > 660)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 1:
        ClickLock = false;
        if (delta > 20)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 2:
        ClickLock = false;
        if (delta > 20)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 3:
        ClickLock = false;
        if (delta > 20)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 5:
        ClickLock = false;
        if (delta > 20)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 6:
        ClickLock = false;
        if (delta > 20)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 7:
        ClickLock = false;
        if (delta == 20) gonrad.ChangeAnimation(L"Char_LSUS");
        if (delta == 30) gonrad.ChangeAnimation(L"Char_RSUS");
        if (delta == 40) gonrad.ChangeAnimation(L"Char_FSUS");
        if (delta > 50)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 8:
        ClickLock = false;
        if (delta > 20)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 9:
        ClickLock = false;
        if (delta > 20)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 10:
        ClickLock = false;
        if (delta > 20)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 11:
        ClickLock = false;
        if (delta > 20)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 12:
        ClickLock = false;
        if (delta > 20)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 13:
        ClickLock = false;
        if (delta > 20)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 14:
        ClickLock = false;
        if (delta <= 100)
        {
            if (delta == 1)
            {
                radinkal.Alive = true;
                alfred.Alive = true;
            }
            if (delta == 5)
            {
                radinkal.Move(0, 16);
                alfred.Move(0, 16);
                gonrad.ChangeAnimation(L"Char_BSUS");
            }
            if (delta == 10)
            {
                radinkal.Move(0, 16);
                radinkal.ChangeAnimation(L"Char_FSDS");
                alfred.Move(0, 16);
                alfred.ChangeAnimation(L"Char_FSDS");
            }
            if (delta >= 20 and delta < 65)
            {
                if (delta == 20)
                {
                    alfred.ChangeAnimation(L"Char_R");
                    radinkal.ChangeAnimation(L"Char_R");
                }
                if (delta % 5 == 0)
                {
                    alfred.Move(16, 0);
                    radinkal.Move(16, 0);
                    if (delta < 40) gonrad.Move(16, 0);
                }
                if (delta == 50) gonrad.ChangeAnimation(L"Char_FSUS");
            }
            if (delta == 65)
            {

                alfred.ChangeAnimation(L"Char_FSDS");
                radinkal.ChangeAnimation(L"Char_FSDS");
            }
            if (delta > 65 and delta < 100)
            {
                if (delta == 70)
                {
                    alfred.ChangeAnimation(L"Char_F");
                    radinkal.ChangeAnimation(L"Char_F");
                }
                if (delta % 5 == 0)
                {
                    alfred.Move(0, 16);
                    radinkal.Move(0, 16);
                }
            }
            if (delta == 100)
            {
                alfred.ChangeAnimation(L"Char_FSUS");
                radinkal.ChangeAnimation(L"Char_FSUS");
            }
        }
        else if (delta > 100)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break; 
    case 16:
        ClickLock = false;
        if (delta > 20)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 17:
        ClickLock = false;
        if (delta > 20)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 18:
        ClickLock = false;
        if (delta > 20)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 19:
        ClickLock = false;
        if (delta > 20)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 20:
        ClickLock = false;
        if (delta > 20)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 21:
        ClickLock = false;
        if (delta > 20)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 22:
        ClickLock = false;
        if (delta > 20)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 23:
        ClickLock = false;
        if (delta > 20)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 24:
        ClickLock = false;
        if (delta > 20)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 25:
        ClickLock = false;
        if (delta > 20)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 26:
        ClickLock = false;
        if (delta < 200)
        {
            if (delta == 5)
            {
                KC_Inside->CameraMove(-16, 0);
                radinkal.CameraFollow(-16, 0);
                alfred.CameraFollow(-16, 0);
                gonrad.CameraFollow(-16, 0);
            }
            if (delta == 10)
            {
                ares.Move(-16, 0);
                ares.ChangeAnimation(L"Char_LSUS");
                
            }
            if (delta == 15)
            {
                ares.Move(-16, 0);
                ares.ChangeAnimation(L"Char_LSDS");
                alfred.ChangeAnimation(L"Char_LSUS");
            }

            if (delta >= 30 and delta < 75)
            {
                if (delta == 30) ares.ChangeAnimation(L"Char_B");
                if (delta == 40) radinkal.ChangeAnimation(L"Char_LSUS");
                if (delta % 5 == 0)
                {
                    KC_Inside->CameraMove(0, -16);
                    radinkal.Move(0, 16);
                    alfred.Move(0, 16);
                    gonrad.Move(0, 16);

                }

                if (delta == 45) radinkal.ChangeAnimation(L"Char_BSUS");
                if (delta == 55) alfred.ChangeAnimation(L"Char_BSUS");
            }
            if (delta == 75) ares.ChangeAnimation(L"Char_BSDS");
            if (delta >= 90 and delta < 120)
            {
                if (delta == 90) ares.ChangeAnimation(L"Char_L");
                if (delta % 5 == 0)
                {
                    ares.Move(-16, 0);
                }

                if (delta == 100) alfred.ChangeAnimation(L"Char_LSUS");
                if (delta == 110) radinkal.ChangeAnimation(L"Char_LSUS");
            }

            if (delta >= 135 and delta < 155)
            {
                if (delta == 135) ares.ChangeAnimation(L"Char_B");
                if (delta % 5 == 0)
                {
                    ares.Move(0, -16);
                }

                if (delta == 145) radinkal.ChangeAnimation(L"Char_BSUS");
                if (delta == 150) alfred.ChangeAnimation(L"Char_BSUS");
            }
        }
        else if (delta > 155)
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

void KarionScene3::CharSetPos()
{
    griffin.ChangeAnimation(L"Char_FLY");
    griffin.SetPosition(320, -50);
    ares.SetPosition(280, 220);
    ares.ChangeAnimation(L"Char_F");
    gonrad.ChangeAnimation(L"Char_FSUS");
    gonrad.SetPosition(176, 16);
    radinkal.SetPosition(143, 16);
    radinkal.ChangeAnimation(L"Char_FSUS");
    alfred.SetPosition(175, 16);
    alfred.ChangeAnimation(L"Char_FSUS");

}

void KarionScene3::onFrameMove()
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

void KarionScene3::onDraw(HDC hdc)
{
	HFONT oldFont;
	oldFont = (HFONT)SelectObject(hdc, hFont);
	SetBkMode(hdc, TRANSPARENT);

    KC_Outside->Draw(hdc);
    KC_Inside->Draw(hdc);
    CharDraw(hdc);
    UI->UIDraw(hdc);
    //KC_Inside->Draw(hdc);


    if (!LocationEnd)
    {
        UI->LocationDraw(hdc, L"카리온성");
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
        if (!Timeline->Textline[Timeline->index])
        {
            if (LocationEnd) anicheck = true;
        }
        else
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
        if (!Timeline->Textline[Timeline->index])
        {
            if (LocationEnd) anicheck = true;
        }
        else
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
        else
            UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
        break;
    case 12:
        if (!Timeline->Textline[Timeline->index])
        {
            if (LocationEnd) anicheck = true;
        }
        else
            UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
        break;
    case 13:
        if (!Timeline->Textline[Timeline->index])
        {
            if (LocationEnd) anicheck = true;
        }
        else
            UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
        break;
    case 14:
        if (!Timeline->Textline[Timeline->index])
        {
            if (LocationEnd) anicheck = true;
        }
        else
            UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
        break;
    case 15:
        Timeline->Textline[Timeline->index] = true;
        UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
        break;
    case 16:
        if (!Timeline->Textline[Timeline->index])
        {
            if (LocationEnd) anicheck = true;
        }
        else
            UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
        break;
    case 17:
        if (!Timeline->Textline[Timeline->index])
        {
            if (LocationEnd) anicheck = true;
        }
        else
            UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
        break;
    case 18:
        Timeline->Textline[Timeline->index] = true;
        UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
        break;
    case 19:
        if (!Timeline->Textline[Timeline->index])
        {
            if (LocationEnd) anicheck = true;
        }
        else
            UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
        break;
    case 20:
        if (!Timeline->Textline[Timeline->index])
        {
            if (LocationEnd) anicheck = true;
        }
        else
            UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
        break;
    case 21:
        Timeline->Textline[Timeline->index] = true;
        UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
        break;
    case 22:
        if (!Timeline->Textline[Timeline->index])
        {
            if (LocationEnd) anicheck = true;
        }
        else
            UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
        break;
    case 23:
        Timeline->Textline[Timeline->index] = true;
        UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
        break;
    case 24:
        if (!Timeline->Textline[Timeline->index])
        {
            if (LocationEnd) anicheck = true;
        }
        else
            UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
        break;
    case 25:
        if (!Timeline->Textline[Timeline->index])
        {
            if (LocationEnd) anicheck = true;
        }
        else
            UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
        break;
    case 26:
        if (!Timeline->Textline[Timeline->index])
        {
            anicheck = true;
        }
    default:
        break;
    }
}

void KarionScene3::onMouseDown(UINT x, UINT y, UINT left_right)
{
    if (!LocationEnd)
    {
        LocationEnd = true;
    }
    else
    {
        if (ClickLock)
        {
            if (Timeline->index < 27) Timeline->index++;
            else FinishedCheck = true;
        }
    }
}

void KarionScene3::onMouseMove(UINT x, UINT y)
{
}

void KarionScene3::onKeyDown(KeyInput* virtual_key)
{
    if (virtual_key->KeyDownkey == 32)
        FinishedCheck = true;
}


