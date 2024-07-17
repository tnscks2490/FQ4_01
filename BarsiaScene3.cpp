#include "pch.h"
#include "BarsiaScene3.h"
#include "CMap.h"
#include "GUI.h"
#include "TIMELINE.h"

BarsiaScene3::BarsiaScene3()
{
    cmap = new CMap(RESOURCE_NAME(IDB_BARSIAJAIL));
    YellowFlash = new CMap(RESOURCE_NAME(IDB_TESTINGMAP), Csprite::DrawType_AlphaBlend);
    YellowFlash->ColorChange(RGB(0, 0, 0));
    YellowFlash->mScreen.mAlpha = 0;
    window = new CMap(RESOURCE_NAME(IDB_BAR_JAIL_WINDOW),Csprite::DrawType_Transparent);
    window->Visible = false;
    grating_close = new CMap(RESOURCE_NAME(IDB_GRATING_CLOSE),Csprite::DrawType_Transparent);
    grating_open = new CMap(RESOURCE_NAME(IDB_GRATING_OPEN), Csprite::DrawType_Transparent);
    cmap2 = new CMap(RESOURCE_NAME(IDB_BARSIACASTLE));
    cmap2->Visible = false;

    hFont = CreateFontW(18, 0, 0, 0, 0, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT("±Ã¼­"));
    UI = new GUI(L"BarsiaScene3");
    Timeline = new TIMELINE(14);
    mScript = new Script(UI->CurruntScene);
    grating_close->PosSet(135, 517);
    delta = 0;
    grating_open->Visible = false;
    cmap->CameraPosSetting(30, 0 );

    ObjectPosSet();
    AniCharPosSet();
}

BarsiaScene3::~BarsiaScene3()
{
    delete cmap;
    delete UI;
    delete Timeline;
    delete mScript;
    delete YellowFlash;
    delete grating_close;
    delete grating_open;
    delete cmap2;

    DeleteObject(hFont);
}

bool BarsiaScene3::IsFinished()
{
    return FinishedCheck;
}

void BarsiaScene3::onFrameMove()
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

void BarsiaScene3::CharAnimation(int delta)
{
    switch (Timeline->index)
    {
    case 0:
        ClickLock = false;
        if (delta < 200)
        {
            if (delta % 5 == 0)
            {
                cmap->CameraMove(0,15);
                garrard.CameraFollow(0, 15);
                CharFollowCamera(0, 15);
                grating_close->mScreen.mdestY -= 15;
            }
        }
        else if (delta < 270)
        {
            if (delta == 200)
            {
                grating_close->Visible = false;
                cmap->CameraPosSetting(30, 680);          
                CharFollowCameraSet(0, -100);
                ares.Move(0, 8);
                garrard.Alive = true;      
            }
            if (delta % 5 == 0) garrard.Move(0,-10);
        }
        else if ( delta >= 280 && delta < 305)
        {
            if (delta == 280)
            {
                garrard.ChangeAnimation(L"Char_R");
            }
            if (delta % 5 == 0)
            {
                cmap->CameraMove(10, 0);
                CharFollowCamera(10, 0);
            }
        }
        else if (delta >= 315 && delta <= 380)
        {
            if (delta == 315)
            {
                grating_close->Visible = true;
                garrard.ChangeAnimation(L"Char_B");
                grating_close->PosSet(85, -165);
            }
            if (delta % 5 == 0)
            {
                grating_close->mScreen.mdestY += 10;
                if (delta == 380)
                {
                    cmap->CameraMove(0, -8);
                    CharFollowCamera(0, -8);
                }
                else
                {
                    cmap->CameraMove(0, -10);
                    CharFollowCamera(0, -10);
                }
            }
            if (delta >= 360 && delta % 5 == 0 && delta < 380)
            {
                if (delta == 360)
                {
                    soldier2[0].ChangeAnimation(L"Char_R");
                    soldier2[1].ChangeAnimation(L"Char_L");
                }
                soldier2[0].Move(10, 0);
                soldier2[1].Move(-10, 0);
            }
        }
        else if (delta > 380 && delta < 390)
        {
            if (delta == 381)
            {
                soldier2[0].Move(10, 0);
                soldier2[1].Move(-10, 0);
                garrard.ChangeAnimation(L"Char_BLS");
            }
            if (delta == 385)
            {
                soldier2[0].ChangeAnimation(L"Char_FSUS");
            }
            if (delta == 389)
            {
                soldier2[1].ChangeAnimation(L"Char_FSUS");
            }
        }
        else if (delta > 420)
        {
            if (delta == 421) ObjAniAllStop();
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 1:
        ClickLock = false;
        if (delta < 20)
        {
            if (delta == 1)  ObjAniAllStart();
        }
        else if (delta > 20)
        {
            if (delta == 21) ObjAniAllStop();
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 2:
        ClickLock = false;
        if (delta < 20)
        {
            if (delta == 1)  ObjAniAllStart();
        }
        else if (delta > 20)
        {
            if (delta == 21) ObjAniAllStop();
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 3:
        ClickLock = false;
        if (delta < 80)
        {
            if (delta == 1)
            {
                ObjAniAllStart();
                for (int i = 2; i < 7; i++)
                {
                    soldier2[i].Alive = true;
                }
            }
            if (delta % 5 == 0)
            {
                if (delta != 35)
                {
                    for (int i = 2; i < 7; i++)
                    {
                        soldier2[i].Move(0, -10);
                    }
                }
                else
                {
                    for (int i = 3; i < 7; i++)
                    {
                        soldier2[i].Move(0, -10);
                    }
                    soldier2[2].Move(10, 0);
                }

                if (delta == 45)
                    garrard.ChangeAnimation(L"Char_FLS");
                 
                if (delta == 75)
                    soldier2[2].Move(0, -10);
            }
            
            
            if (delta == 79)
            {
                soldier2[2].ChangeAnimation(L"Char_RSDS");
                soldier2[3].ChangeAnimation(L"Char_BSDS");
                soldier2[4].ChangeAnimation(L"Char_BSDS");
                soldier2[5].ChangeAnimation(L"Char_BSDS");
                soldier2[6].ChangeAnimation(L"Char_LSDS");
            }
                
        }
        else if (delta > 120)
        {
            if (delta == 121) ObjAniAllStop();
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 4:
        ClickLock = false;
        ObjAniAllStart();
        if (delta < 120)
        {
            if (delta == 10)
                YellowFlash->mScreen.mAlpha = 255;

            if (YellowFlash->mScreen.mAlpha > 0 && delta % 2 == 0)
                YellowFlash->mScreen.mAlpha -= 5;
            if (delta == 119)
            {
                YellowFlash->Visible = false;
                grating_close->Visible = true;
                grating_close->PosSet(85, -25);
                ObjAniAllStart();
            }
        }
        else if (delta >= 140 && delta < 285)
        {
            if (delta == 140)

                garrard.ChangeAnimation(L"Char_B");
            if (delta % 5 == 0)
            {
                cmap->CameraMove(0, -10);
                CharFollowCamera(0, -10);
                grating_close->mScreen.mdestY += 10;
               
            }
        }
        else if (delta >= 295 && delta < 320)
        {
            if (delta == 295)
            {
                garrard.ChangeAnimation(L"Char_L");
                grating_close->Visible = false;
            }
            
            if (delta % 5 == 0)
            {
                cmap->CameraMove(-10, 0);
                CharFollowCamera(-10, 0);
            }

            if (delta == 319)
                garrard.ChangeAnimation(L"Char_B");
        }
        else if (delta >= 330 && delta < 375)
        {
            if (delta % 5 == 0)
            {
                cmap->CameraMove(0, -10);
                CharFollowCamera(0, -10);
            }
            if (delta == 374)
                garrard.ChangeAnimation(L"Char_BRS");
        }
        else if (delta > 380)
        {
            if (delta == 381) ObjAniAllStop();
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 5:
        ObjAniAllStart();
        ClickLock = false;
        if (delta <= 165)
        {
            if (delta == 20)
            {
                cmap->CameraMove(0, 30);
                CharFollowCamera(0, 30);
            }
            if (delta == 25)
            {
                ares.ChangeAnimation(L"Char_FL");
                ares.Move(-16, -16);
            }
            if (delta == 105)
            {
                ares.Move(16, 16);
                ares.ChangeAnimation(L"Char_FB");
            }
            if (delta == 165) ares.ChangeAnimation(L"Char_FBS");
        }
        else if (delta > 165)
        {
            if (delta == 166) ObjAniAllStop();
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 6:
        ObjAniAllStart();
        ClickLock = false;
        if (delta <= 60)
        {
            if (delta == 1) ares.ChangeAnimation(L"Char_FB");
            if (delta == 20) ares.ChangeAnimation(L"Char_FDUS");
            if (delta == 60) ares.ChangeAnimation(L"Char_FSUS");
        }
        else if (delta > 70)
        {
            if (delta == 71) ObjAniAllStop();
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 7:
        ClickLock = false;
        if (delta < 20)
        {
            if( delta == 1) ObjAniAllStart();
        }
        else if (delta > 20)
        {
            if (delta == 21) ObjAniAllStop();
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 8:
        ClickLock = false;
        if (delta < 30)
        {
            if (delta == 1) ObjAniAllStart();
            if (delta == 10) ares.ChangeAnimation(L"Char_BSUS");
        }
        else if (delta > 30)
        {
            if (delta == 31) ObjAniAllStop();
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 9:
        ClickLock = false;
        if (delta < 130)
        {
            if (delta == 1)
            {
                grating_close->Visible = false;
                cmap->CameraMove(0, -192);
                CharFollowCamera(0, -192);
                garrard.Move(0, 192);
                window->Visible = true;
                window->mScreen.mdestX = 39;
                window->mScreen.mdestY = 62;

            }
            if (delta == 10)
                griffin[0].Alive = true;
            if (delta > 10 && delta < 15)
                griffin[0].Move(0, 10);
            else if (delta >= 15 && delta < 20)
                griffin[0].Move(10, 0);
            else if (delta >= 20 && delta < 25)
                griffin[0].Move(0, 10);
            else if (delta >= 25 && delta < 80)
            {
                griffin[0].Move(10, 0);

                if (delta == 50)
                    griffin[0].Alive = false;

                if (delta == 40)
                    griffin[1].Alive = true;
                if (delta > 40 && delta < 45)
                    griffin[1].Move(5, 0);
                else if (delta >= 45 && delta < 50)
                    griffin[1].Move(0, 5);
                else if (delta >= 50 && delta < 80)
                    griffin[1].Move(10, 0);

      
                
            }
            else if (delta >= 80 && delta < 130)
            {
                griffin[1].Move(10, 0);

                if (delta == 90)
                    griffin[1].Alive = false;


                if (delta == 80)
                    griffin[2].Alive = true;
                if(delta > 80 && delta < 85)
                    griffin[2].Move(5, 0);
                else if(delta >=85 && delta < 90)
                    griffin[2].Move(0, 5);
                else if(delta >= 90 && delta <130)
                    griffin[2].Move(10, 0);

                if (delta == 129)
                {
                    ares.ChangeAnimation(L"Char_FSUS");
                    griffin[2].Alive = false;
                }
            }  
        }
        else if (delta > 150)
        {
            if (delta == 151) ObjAniAllStop();
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 11:
        ClickLock = false;
        if (delta < 20)
        {
            if (delta == 1) ObjAniAllStart();
        }
        else if (delta > 20)
        {
            if (delta == 31) ObjAniAllStop();
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 12:
        ClickLock = false;
        if (delta < 20)
        {
            if (delta == 1) ObjAniAllStart();
        }
        else if (delta > 20)
        {
            if (delta == 31) ObjAniAllStop();
            CharAniEnd = true;
            ClickLock = true;
        }
        break;
    case 13:
        ClickLock = false;
        ObjAniAllStart();
        if (delta < 185)
        {
            if (delta == 10)
            {
                window->Visible = false;
                ares.ChangeAnimation(L"Char_FSDS");
                cmap->CameraMove(0, 192);
                CharFollowCamera(0, 192);
                ares.Move(0, 30);
                garrard.Move(0, -192);
             
            }
            if (delta == 20)
            {
                ares.ChangeAnimation(L"Char_R");
                cmap->CameraMove(30, 0);
                CharFollowCamera(30, 0);
                garrard.Move(-30, 0);
            }
            if (delta >= 20 && delta <= 40)
            {
                if (delta % 5 == 0)
                {
                    ares.Move(10, 0);
                }
            }
            if (delta >= 50 && delta < 185)
            {
                if (delta == 50)
                {
                    ares.ChangeAnimation(L"Char_F");
                    grating_open->Visible = true;
                    grating_open->PosSet(105, 325);
                }

                if (delta % 5 == 0)
                {
                    grating_open->mScreen.mdestY -= 10;
                    cmap->CameraMove(0, 10);
                    CharFollowCamera(0, 10);
                    ares.CameraFollow(0, -10);
                    garrard.Move(0, -10);
                }
            }

        }
        else if (delta < 740)
        {
            if (delta == 185)
            {
                cmap->Visible = false;
                cmap2->Visible = true;
                grating_open->Visible = false;
                for (int i = 0; i < 7; i++)
                    soldier2[i].Alive = false;
                brazier[0].Alive = false;
                brazier[1].Alive = false;
                for (int i = 3; i < 6; i++)
                {
                    griffin[i].Alive = true;
                    griffin[i].ChangeAnimation(L"Char_Sleep");
                }
                cmap2->CameraMove(96, 0);
                ares.SetPosition(48, 240);
                ares.ChangeAnimation(L"Char_BSUS");

                for (int i = 0; i < 3; i++)
                    g_flag[i].Alive = true;


                
            }
            if (delta > 185 && delta < 230)
            {
                if(delta == 186) ares.ChangeAnimation(L"Char_F");
                if (delta % 5 == 0)
                {
                    ares.Move(0, 10);
                }

            }
            if (delta == 230)
                ares.ChangeAnimation(L"Char_FSUS");

            if (delta == 240)
                ares.ChangeAnimation(L"Char_R");

            if (delta > 240 && delta < 335)
            {
                if (delta % 5 == 0)
                    ares.Move(10, 0);
            }

            if (delta == 335)
                ares.ChangeAnimation(L"Char_FSUS");

            if (delta > 340 && delta < 390)
            {
                if (delta == 341)
                    ares.ChangeAnimation(L"Char_B");
                if (delta % 5 == 0)
                    ares.Move(0, -10);
            }
            if (delta == 390) ares.ChangeAnimation(L"Char_FSUS");
            if (delta == 410) ares.ChangeAnimation(L"Char_RSUS");
            if (delta == 420) ares.ChangeAnimation(L"Char_BSUS");
            if (delta == 430) ares.ChangeAnimation(L"Char_RSUS");
            if (delta == 440) ares.ChangeAnimation(L"Char_BSUS");
            if (delta == 450) ares.Move(0, -25);
            if (delta == 455) ares.ChangeAnimation(L"Char_FSUS");
            if (delta == 460) ares.ChangeAnimation(L"Char_BSUS");
            if (delta == 480) ares.ChangeAnimation(L"Char_BSDS");
            if (delta == 485) ares.ChangeAnimation(L"Char_BSUS");

            if (delta == 490) griffin[3].ChangeAnimation(L"Char_SS");
            if (delta == 510)
            {
                griffin[3].ChangeAnimation(L"Char_WS");
                griffin[3].Move(0,-15);
            }

            if (delta == 515)
            {
                ares.ChangeAnimation(L"Char_LSDS");
                ares.Move(-40, 0);
            }
            if (delta == 520)
            {
                ares.ChangeAnimation(L"Char_LSUS");
                ares.Move(-10, 0);
            }
            if (delta == 525) ares.ChangeAnimation(L"Char_FSUS");
            if (delta == 530)
            {
                ares.ChangeAnimation(L"Char_BSDS");
                ares.Move(0, -25);
            }
            if (delta == 535) ares.ChangeAnimation(L"Char_FSDS");
            if (delta >= 540 && delta < 560)
            {
                if (delta == 540) ares.ChangeAnimation(L"Char_RSUS");
                if (delta % 5 == 0)
                {
                    cmap2->CameraMove(-15, 0);
                    ares.CameraFollow(-15, 0);
                    for (int i = 0; i < 3; i++)
                    {
                        g_flag[i].CameraFollow(-15, 0);
                        griffin[i + 3].CameraFollow(-15, 0);
                    }
                }
            }
            if (delta == 560)
            {
                ares.Alive = false;
                griffin[3].ChangeAnimation(L"Char_ARES_R");
            }
            if (delta == 570) griffin[3].ChangeAnimation(L"Char_ARES_RO");
            if (delta == 580) griffin[3].Move(0, -50);
            if (delta == 585) griffin[3].ChangeAnimation(L"Char_ARES_FR");
            if (delta == 600)
            {
                griffin[3].ChangeAnimation(L"Char_FLY");
                cmap2->CameraMove(-35, 0);
                for (int i = 0; i < 3; i++)
                {
                    g_flag[i].CameraFollow(-35, 0);
                    griffin[i + 3].CameraFollow(-35, 0);
                }

                griffin[3].Move( 0, 100);
            }
            if (delta > 600 && delta <= 710)
            {
                if (delta % 2 == 0)
                {
                    cmap2->CameraMove(0, 20);
                    for (int i = 0; i < 3; i++)
                    {
                        g_flag[i].CameraFollow(0, 20);
                        
                    }
                    
                    griffin[4].CameraFollow(0, 20);
                    griffin[5].CameraFollow(0, 20);
                }
            }
            if(delta == 712) cmap2->CameraMove(0, 20);

            if (delta > 712 && delta < 740)
            {
                if (delta % 2 == 0)
                    griffin[3].Move(0, 20);
            }
        }
        else if (delta > 740)
        {
            if (delta == 741) ObjAniAllStop();
            CharAniEnd = true;
            ClickLock = true;
            FinishedCheck = true;
            Timeline->Textline[Timeline->index] = true;
        }
    default:
        break;
    }
}

void BarsiaScene3::CharFollowCamera(int x, int y)
{
    ares.CameraFollow(x, y);
    brazier[0].CameraFollow(x, y);
    brazier[1].CameraFollow(x, y);
    for (int i = 0; i < 7; i++)
    {
        soldier2[i].CameraFollow(x, y);
    }
}

void BarsiaScene3::CharFollowCameraSet(int x, int y)
{
    brazier[0].SetPosition(brazier[0].FrameSprite.mdestX + x, brazier[0].FrameSprite.mdestY + y);
    brazier[1].SetPosition(brazier[1].FrameSprite.mdestX + x, brazier[1].FrameSprite.mdestY + y);
    soldier2[0].SetPosition(soldier2[0].FrameSprite.mdestX + x, soldier2[0].FrameSprite.mdestY + y);
    soldier2[1].SetPosition(soldier2[1].FrameSprite.mdestX + x, soldier2[1].FrameSprite.mdestY + y);
    ares.SetPosition(ares.FrameSprite.mdestX + x, ares.FrameSprite.mdestY + y);
}

void BarsiaScene3::ObjAniAllStop()
{
    for (int i = 0; i < 2; i++) brazier[i].ChangeAnimation(L"Char_FS");
}

void BarsiaScene3::ObjAniAllStart()
{
    for (int i = 0; i < 2; i++) brazier[i].ChangeAnimation(L"Char_F");
}

void BarsiaScene3::AniCharPosSet()
{
    ares.SetPosition(304 , 302);
    ares.ChangeAnimation(L"Char_FDDS");
    garrard.SetPosition(304, 900);
    garrard.Alive = false;
    soldier2[0].SetPosition(290, 690);
    soldier2[0].ChangeAnimation(L"Char_FSUS");
    soldier2[1].SetPosition(420, 690);
    soldier2[1].ChangeAnimation(L"Char_FSUS");

   
    soldier2[2].SetPosition(265, 840);
    soldier2[3].SetPosition(307, 840); 
    soldier2[4].SetPosition(355, 810);
    soldier2[5].SetPosition(400, 840);
    soldier2[6].SetPosition(450, 810);
    for (int i = 2; i < 7; i++)
    {
        soldier2[i].Alive = false;
        soldier2[i].ChangeAnimation(L"Char_B");
    }

    for (int i = 0; i < 6; i++)
    {
        griffin[i].Alive = false;
    }

    griffin[0].SetPosition(160, 60);
    griffin[1].SetPosition(100, 150);
    griffin[2].SetPosition(100, 100);
    griffin[3].SetPosition(215, 140);
    griffin[4].SetPosition(415, 160);
    griffin[5].SetPosition(450, 240);
}

void BarsiaScene3::ObjectPosSet()
{
    brazier[0].SetPosition(245, 845);
    brazier[1].SetPosition(245, 735);

    for (int i = 0; i < 3; i++)
        g_flag[i].Alive = false;

    g_flag[0].SetPosition(20, 78);
    g_flag[1].SetPosition(116, 78);
    g_flag[2].SetPosition(580, 78);
}

void BarsiaScene3::AniCharDraw(HDC hdc)
{
    ares.Draw(hdc);
    garrard.Draw(hdc);
    for (int i = 0; i < 7; i++)
        soldier2[i].Draw(hdc);

    for (int i = 0; i < 6; i++)
        griffin[i].Draw(hdc);
}

void BarsiaScene3::ObjectDraw(HDC hdc)
{
    for (int i = 0; i < 2; i++)
        brazier[i].Draw(hdc);
    for (int i = 0; i < 3; i++)
        g_flag[i].Draw(hdc);
}

void BarsiaScene3::onDraw(HDC hdc)
{
    HFONT oldFont;
    oldFont = (HFONT)SelectObject(hdc, hFont);
    SetBkMode(hdc, TRANSPARENT);

    cmap->Draw(hdc);
    cmap2->Draw(hdc);
    AniCharDraw(hdc);
    ObjectDraw(hdc);
    grating_close->Draw(hdc);
    grating_open->Draw(hdc);
    YellowFlash->Draw(hdc);
    window->Draw(hdc);
    UI->UIDraw(hdc);

    if (!LocationEnd)
    {
        UI->LocationDraw(hdc, L"¹Ù¸£½Ã¾Æ¼º °¨¿Á");
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
            if (LocationEnd) 
                anicheck = true;
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
        if (!Timeline->Textline[Timeline->index])
        {
            if (LocationEnd) anicheck = true;
        }
        else
            UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
        break;
    case 10:
        Timeline->Textline[Timeline->index] = true;
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
            anicheck = true;
        }
    default:
        break;
    }
}

void BarsiaScene3::onMouseDown(UINT x, UINT y, UINT left_right)
{
    if (!LocationEnd)
    {
        LocationEnd = true;
    }
    else
    {
        if (ClickLock)
        {
            if (Timeline->index < 13) Timeline->index++;
            else FinishedCheck = true;
        }
    }
}

void BarsiaScene3::onMouseMove(UINT x, UINT y)
{

}

void BarsiaScene3::onKeyDown(KeyInput* virtual_key)
{
    if (virtual_key->KeyDownkey == 32)
        FinishedCheck = true;
}



