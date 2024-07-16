#pragma once
#include "pch.h"
#include "BarsiaScene1.h"
#include "CScreen.h"
#include "TIMELINE.h"
#include "GUI.h"
#include "CMap.h"

#define RESOURCE_NAME(x) MAKEINTRESOURCE(x),L#x


BarsiaScene1::BarsiaScene1()
{
    Bg = new CMap(RESOURCE_NAME(IDB_BRSIACASTLE));
    ScreenBg = new CMap(RESOURCE_NAME(IDB_BRSIACASTLE));
    ScreenUI = new CMap(MAKEINTRESOURCE(IDB_SMALL_SCREEN),L"IDB_SMALL_SCREEN", Csprite::DrawType_Transparent);
    UI = new GUI(L"BarsiaScene1");
    mScript = new Script(UI->CurruntScene);

	Timeline = new TIMELINE(17);
    hFont = CreateFontW(18, 0, 0, 0, 0, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT("±Ã¼­"));
    
	CharSetPos();
}

BarsiaScene1::~BarsiaScene1()
{
	DeleteObject(hFont);
}

bool BarsiaScene1::IsFinished()
{
	return FinishedCheck;
}


void BarsiaScene1::onFrameMove()
{
	if (anicheck)
	{
		delta++;
		CharAnimation(delta);
		if (CharAniEnd)
		{
			Timeline->Textline[Timeline->index] = true;
			anicheck = false;
			CharAniEnd = false;
			delta = 0;
		}
	}
}


void BarsiaScene1::CharAnimation(int delta)
{
    switch (Timeline->index)
    {
    case 0:
        ClickLock = false;
        if (delta < 185)
        {
            if (delta % 5 == 0)
            {
                Bg->CameraMove(0, 15);
                CharCameraFollow(0, 15);
            }
        }
        else if (delta < 245)
        {
            if (delta == 185) ScreenCharSetPos();
            
            if (delta % 5 == 0)
            {
                screeny += 16;
            }
        }
        else if (delta < 280)
        {
            if(delta == 245) ScreenOn = true;
            if (delta == 260)
            {
                sgenelu.Move(0, 32);
                sgenelu.ChangeAnimation(L"Char_FRS");
                sjanil.ChangeAnimation(L"Char_F");
            }
        }
        else if (delta > 280)
        {
            CharAniEnd = true;
            ClickLock = true; 
        }
        break;
    case 2:
        ClickLock = false;
        if (delta < 60)
        {
            if (delta == 20) keck.Move(0, -32);
        }
        else if (delta > 60)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 3:
        ClickLock = false;
        if (delta < 80)
        {
            if (delta == 10) keck.ChangeAnimation(L"Char_F");
            if (delta == 15) keck.Move(0, 32);
            if (delta == 20) keck.ChangeAnimation(L"Char_BRS");
            if (delta == 30)
            {
                sgenelu.ChangeAnimation(L"Char_BRS");
                sgenelu.Move(0, -16);
            }
            if (delta == 40) sgenelu.ChangeAnimation(L"Char_FLS");
            if (delta == 50)
            {
                sgenelu.Move(0, -16);
                sjanil.ChangeAnimation(L"Char_R");
            }
        }
        else if (delta > 80)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 4:
        ClickLock = false;
        if (delta > 40)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 5:
        ClickLock = false;
        if (delta > 40)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 6:
        ClickLock = false;
        if (delta > 40)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 7:
        ClickLock = false;
        if (delta > 40)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 8:
        ClickLock = false;
        if (delta < 60)
        {
            if (delta == 20)
            {
                sgenelu.ChangeAnimation(L"Char_ST");
                sgenelu.Move(0, 32);
                sjanil.ChangeAnimation(L"Char_F");
            }
        }
        else if (delta > 60)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 10:
        ClickLock = false;
        if (delta < 65)
        {
            if (delta == 20) sgenelu.Move(0, 32);
            if (delta == 30) sgenelu.ChangeAnimation(L"Char_FLS");
            if (delta > 30 and delta < 65)
            {
                if (delta == 35) sark.ChangeAnimation(L"Char_B");
                if (delta % 5 == 0) sark.Move(0, -16);
            }
        }
        if (delta == 65) sark.ChangeAnimation(L"Char_BLS");
        else if (delta > 80)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 11:
        ClickLock = false;
        if (delta > 40)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 12:
        ClickLock = false;
        if (delta > 40)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 13:
        ClickLock = false;
        if (delta == 20) sgenelu.Move(0, -32);
        else if (delta > 60)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 15:
        ClickLock = false;
        if (delta > 40)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 16:
        ClickLock = false;
        if (delta > 40)
        {
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    default:
        break;
    }
}

void BarsiaScene1::CharDraw(HDC hdc)
{
	for (int i = 0; i < 12; i++)
		soldier2[i].Draw(hdc);;
	soldier1[0].Draw(hdc);
	soldier1[1].Draw(hdc);

	genelu.Draw(hdc);
	janil.Draw(hdc);
	thyhoot.Draw(hdc);
	macgaia.Draw(hdc);
	ogg.Draw(hdc);
	moldred.Draw(hdc);


	keck.Draw(hdc);
	gabi.Draw(hdc);
	orason.Draw(hdc);
	laios.Draw(hdc);
	mysolen.Draw(hdc);
	maream.Draw(hdc);
	sark.Draw(hdc);
}

void BarsiaScene1::CharCameraFollow(int x, int y)
{
    soldier1[0].CameraFollow(x, y);
    soldier1[1].CameraFollow(x, y);

    for (int i = 0; i < 12; i++) soldier2[i].CameraFollow(x, y);
    
    genelu.CameraFollow(x, y);
    janil.CameraFollow(x, y);
    thyhoot.CameraFollow(x, y);
    macgaia.CameraFollow(x, y);
    ogg.CameraFollow(x, y);
    moldred.CameraFollow(x, y);

    keck.CameraFollow(x, y);
    gabi.CameraFollow(x, y);
    orason.CameraFollow(x, y);
    laios.CameraFollow(x, y);
    mysolen.CameraFollow(x, y);
    maream.CameraFollow(x, y);
    sark.CameraFollow(x, y);

}

void BarsiaScene1::CharSetPos()
{
    soldier1[0].SetPosition(210, 190);
    soldier1[1].SetPosition(400, 190);

    for (int i = 0; i < 12; i++)
    {
        if (i < 6)
        {
            soldier2[i].ChangeAnimation(L"Char_RSUS");
            soldier2[i].SetPosition(Left_Side_Pos[i][0], Left_Side_Pos[i][1]);
        }
        else
        {
            soldier2[i].ChangeAnimation(L"Char_LSUS");
            soldier2[i].SetPosition(Right_Side_Pos[i - 6][0], Right_Side_Pos[i - 6][1]);
        }
    }

    genelu.SetPosition(305, 465);
    janil.SetPosition(270, 445);
    thyhoot.SetPosition(242, 480);
    macgaia.SetPosition(365, 480);
    macgaia.ChangeAnimation(L"Char_LS");
    ogg.SetPosition(210, 495);
    moldred.SetPosition(400, 495);

    gabi.SetPosition(225, 815);
    keck.SetPosition(272, 830);
    laios.SetPosition(336, 830);
    orason.SetPosition(383, 815);

    mysolen.SetPosition(256, 875);
    sark.SetPosition(304, 875);
    maream.SetPosition(352, 875);
    
}

void BarsiaScene1::ScreenCharDraw(HDC hdc)
{
    sgenelu.Draw(hdc);
    sjanil.Draw(hdc);
    sthyhoot.Draw(hdc);
    smacgaia.Draw(hdc);
    sogg.Draw(hdc);
    smoldred.Draw(hdc);
}

void BarsiaScene1::ScreenCharSetPos()
{
    sgenelu.SetPosition(128, 83);
    sjanil.SetPosition(95, 70);
    sogg.SetPosition(34, 118);
    sthyhoot.SetPosition(64, 102);
    smacgaia.ChangeAnimation(L"Char_LS");
    smacgaia.SetPosition(192, 102);
    smoldred.SetPosition(222, 118);
}



void BarsiaScene1::onDraw(HDC hdc)
{
	HFONT oldFont;
	oldFont = (HFONT)SelectObject(hdc, hFont);
	SetBkMode(hdc, TRANSPARENT); 
    CScreen screen(hdc, 288, 192);
    ScreenUI->PosSet(0, 0);

    Bg->Draw(hdc);
    CharDraw(hdc);
    
 
    if (ScreenOn)
    {
        UI->UIDraw(hdc);
        ScreenBg->CameraPosSetting(160, 332);
        ScreenBg->Draw(screen.m_HDC);
        ScreenCharDraw(screen.m_HDC);
        ScreenUI->Draw(screen.m_HDC);
        screen.Draw(hdc, 176, -160 + screeny, 288, 192);

    }
    else
    {
        ScreenBg->PosSet(0, 0);
        ScreenBg->CameraPosSetting(160, 332);
        ScreenBg->Draw(screen.m_HDC);
        ScreenCharDraw(screen.m_HDC);
        ScreenUI->Draw(screen.m_HDC);
        screen.Draw(hdc, 176, -160 + screeny, 288, 192);

        UI->UIDraw(hdc);
    }
    

	if (!LocationEnd)
	{
		UI->LocationDraw(hdc, L"¹Ù¸£½Ã¾Æ¼º ¿Õ½Ç");
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
        if (!Timeline->Textline[Timeline->index])
        {
            if (LocationEnd) anicheck = true;
        }
        else
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
        Timeline->Textline[Timeline->index] = true;
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
        Timeline->Textline[Timeline->index] = true;
        UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
        break;
    case 15:
        if (!Timeline->Textline[Timeline->index])
        {
            if (LocationEnd) anicheck = true;
        }
        else
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
    default:
        break;
    }
}



void BarsiaScene1::onMouseDown(UINT x, UINT y, UINT left_right)
{
	if (!LocationEnd)
	{
		LocationEnd = true;
	}
	else
	{
		if (ClickLock)
		{
			if (Timeline->index < 16) Timeline->index++;
			else FinishedCheck = true;
		}
	}
}

void BarsiaScene1::onMouseMove(UINT x, UINT y)
{
}

void BarsiaScene1::onKeyDown(KeyInput* virtual_key)
{
	if(virtual_key->KeyDownkey == 32)
		FinishedCheck = true;
}



