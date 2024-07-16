#include "pch.h"
#include "FieldBattle.h"
#include "CMap.h"
#include "GUI.h"
#include "TIMELINE.h"
#include "CScreen.h"
#include "CTileMap.h"
#include "Script.h"


FieldBattle::FieldBattle()
{
    cmap = new CMap(RESOURCE_NAME(IDB_FIELD));
    aekter = new AEKTER;
    UI = new GUI(L"FieldBattle");
    FinishedCheck = false;
    hFont = CreateFontW(18, 0, 0, 0, 0, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH or FF_ROMAN, TEXT("궁서"));
    Timeline = new TIMELINE(4);
    CTilemap = new CTileMap(38, 29);
    mScript = new Script(UI->CurruntScene);



    soldier2  = new SOLDIER2[24];
    ares = new ARES;
    archer = new ARCHER[6];
    horse_general = new HORSE_GENERAL;
    soldier5 = new SOLDIER5[6];
    horse_soldier = new HORSE_SOLDIER[2];
    horse_aekter = new HORSE_AEKTER;



    cmap->CameraX = 0;
    cmap->CameraY = 130;
    delta=0;
    CharAniEnd = false;
    LocationEnd = false;
    anicheck = false;
    ClickLock = false;

    T_UnitAddTilemap();
}

FieldBattle::~FieldBattle()
{
    delete aekter;
    delete cmap;
    delete UI;
    delete Timeline;
}

bool FieldBattle::IsFinished()
{
    return FinishedCheck;
}

void FieldBattle::onFrameMove()
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
void FieldBattle::DebugTilemapDate()
{
    for (int i = 0; i < CTilemap->tileHeight - 1; i++)
    {
        for (int j = 0; j < CTilemap->tileWidth - 1; j++)
        {
            if (CTilemap->GetTile(j, i).tunit == nullptr)
                OutputDebugStringW(L"□");
            else
            {
                if(CTilemap->GetTile(j,i).tunit->mrank > 2)
                    OutputDebugStringW(L"●");
                else
                {
                    OutputDebugStringW(L"■");
                }

            }
        }
        OutputDebugStringW(L"\n"); 
    }
    OutputDebugStringW(L"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void FieldBattle::timelineIndex0(int delta)
{
    ClickLock = true;
    if (delta == 1)
    {
        CharAniStop();
        CharFollowCamera(66);
        horse_aekter->ChangeAnimation(L"Char_B");
    }
    if (delta > 1 && delta < 67)
    {
        cmap->CameraMove(0, -2);
        CharFollowCamera(-1);

    }
    else if (delta >= 70)
    {
        CharAniEnd = true;
        ClickLock = false;
        if (delta == 70)
        {
            horse_aekter->ChangeAnimation(L"HORSE_AEKTER_BACK_STAY_STOP");
            horse_soldier[0].ChangeAnimation(L"HORSE_SOLDIER_FACE_STAY_STOP");
            horse_soldier[1].ChangeAnimation(L"HORSE_SOLDIER_FACE_STAY_STOP");
            horse_general->ChangeAnimation(L"HORSE_GENERAL_FACE_STAY_STOP");

        }
    }
}

void FieldBattle::timelineIndex1(int delta)
{
    ClickLock = true;
    if (delta == 1)
    {
        horse_aekter->ChangeAnimation(L"Char_B");
        horse_soldier[0].ChangeAnimation(L"Char_F");
        horse_soldier[1].ChangeAnimation(L"Char_F");
        horse_general->ChangeAnimation(L"Char_F");
    }
    if (delta > 1 && delta < 34)
    {
        if (delta == 25) horse_aekter->ChangeAnimation(L"Char_F");

        cmap->CameraMove(0, 2);
        CharFollowCamera(1);
     }
    else if (delta >= 70)
    {
        CharAniEnd = true;
        ClickLock = false;
        if (delta == 70)
        {
            horse_aekter->ChangeAnimation(L"HORSE_AEKTER_FACE_STAY_STOP");
            horse_soldier[0].ChangeAnimation(L"HORSE_SOLDIER_FACE_STAY_STOP");
            horse_soldier[1].ChangeAnimation(L"HORSE_SOLDIER_FACE_STAY_STOP");
            horse_general->ChangeAnimation(L"HORSE_GENERAL_FACE_STAY_STOP");
        }
    }
}

void FieldBattle::timelineIndex2(int delta)
{
    ClickLock = true;
    if (delta == 1)
    {
        horse_aekter->ChangeAnimation(L"Char_F");
        horse_soldier[0].ChangeAnimation(L"Char_F");
        horse_soldier[1].ChangeAnimation(L"Char_F");
        horse_general->ChangeAnimation(L"Char_F");
    }
    if (delta >= 70)
    {
        CharAniEnd = true;
        ClickLock = false;

        if (delta == 70)
        {
            horse_aekter->ChangeAnimation(L"HORSE_AEKTER_FACE_STAY_STOP");
            horse_soldier[0].ChangeAnimation(L"HORSE_SOLDIER_FACE_STAY_STOP");
            horse_soldier[1].ChangeAnimation(L"HORSE_SOLDIER_FACE_STAY_STOP");
            horse_general->ChangeAnimation(L"HORSE_GENERAL_FACE_STAY_STOP");
        }
    }
}

void FieldBattle::timelineIndex3(int delta)
{
    ClickLock = true;
    if (delta == 1)
    {
        CharAniStart();
        // 타일맵의 모든 캐릭터들을 정지-> 애니메이션으로 바꿔준다.
    }
    if (delta < 3000)
    {
        if (delta % 10== 0)
        {
            for (CTileUnit* it : CTilemap->mTileUnits)
                it->Tick(delta, it->mPosition);
        }
       
        // 각각의 캐릭터를 시간이 다될때까지 계속해서 반복시킬것을 생각한다.

       /* if (delta % 10 == 9) {
            for (CTileUnit* it : CTilemap->mTileUnits)
            {
                CTilemap->GetTile(it->mPosition.x,it->mPosition.y).tunit = it;
            }
        }*/
    }
    else if (delta > 300 and delta < 370)
    {
        if (delta == 301)
        {
            for (CTileUnit* it : CTilemap->mTileUnits)
            {
                if (it->mrank == A_SOLDIER)
                    it->unit->ChangeAnimation(L"Char_DEATH");
            }
        } 
        if (delta % 10 == 0)
        {
            for (CTileUnit* it : CTilemap->mTileUnits)
            {
                if(it->mrank != A_SOLDIER)
                    it->Tick(delta, it->mPosition);
            }
        }
    }
    else if (delta > 3000)
    {
        CharAniEnd = true;
        ClickLock = false;
        FinishedCheck = true;
    }
}

void FieldBattle::CharAnimation(int delta)
{
    switch (Timeline->index)
    {
    case 0:
        timelineIndex0(delta);
        break;
    case 1:
        timelineIndex1(delta);
        break;
    case 2:
        timelineIndex2(delta);
        break;
    case 3:
        timelineIndex3(delta);
        break;
    default:
        break;
    }
}


void FieldBattle::CharFollowCamera(int delta)
{
     for (CTileUnit* it : CTilemap->mTileUnits)
         it->unit->FrameSprite.mdestY -= delta * 2;
}

void FieldBattle::CharAniStart()
{
    //보병
    for (int i = 1; i < 7; i++) soldier2[i].ChangeAnimation(L"Char_F");

    for (int i = 0; i < 6; i++)
    {
        if (i < 3) soldier5[i].ChangeAnimation(L"Char_R");
        else soldier5[i].ChangeAnimation(L"Char_L");
    }

    soldier2[0].ChangeAnimation(L"Char_R");
    soldier2[10].ChangeAnimation(L"Char_R");
    soldier2[11].ChangeAnimation(L"Char_R");
    soldier2[16].ChangeAnimation(L"Char_R");
    soldier2[18].ChangeAnimation(L"Char_R");
    soldier2[20].ChangeAnimation(L"Char_R");
    soldier2[22].ChangeAnimation(L"Char_R");

    soldier2[7].ChangeAnimation(L"Char_L");
    soldier2[14].ChangeAnimation(L"Char_L");
    soldier2[15].ChangeAnimation(L"Char_L");
    soldier2[17].ChangeAnimation(L"Char_L");
    soldier2[19].ChangeAnimation(L"Char_L");
    soldier2[21].ChangeAnimation(L"Char_L");
    soldier2[23].ChangeAnimation(L"Char_L");
    soldier2[8].ChangeAnimation(L"Char_F");
    soldier2[9].ChangeAnimation(L"Char_F");
    soldier2[12].ChangeAnimation(L"Char_F");
    soldier2[13].ChangeAnimation(L"Char_F");

    //// 기마
    horse_aekter->ChangeAnimation(L"Char_F");
    horse_soldier[0].ChangeAnimation(L"Char_F");
    horse_soldier[1].ChangeAnimation(L"Char_F");
    horse_general->ChangeAnimation(L"Char_F");
}

void FieldBattle::CharAniStop()
{
    for (int i = 1; i < 7; i++) soldier2[i].ChangeAnimation(L"Char_FSUS");

    for (int i = 0; i < 6; i++)
    {
        if (i < 3) soldier5[i].ChangeAnimation(L"Char_RSUS");
        else soldier5[i].ChangeAnimation(L"Char_LSUS");
    }

    soldier2[0].ChangeAnimation(L"Char_RSUS");
    soldier2[10].ChangeAnimation(L"Char_RSUS");
    soldier2[11].ChangeAnimation(L"Char_RSUS");
    soldier2[16].ChangeAnimation(L"Char_RSUS");
    soldier2[18].ChangeAnimation(L"Char_RSUS");
    soldier2[20].ChangeAnimation(L"Char_RSUS");
    soldier2[22].ChangeAnimation(L"Char_RSUS");

    soldier2[7].ChangeAnimation(L"Char_LSUS");
    soldier2[14].ChangeAnimation(L"Char_LSUS");
    soldier2[15].ChangeAnimation(L"Char_LSUS");
    soldier2[17].ChangeAnimation(L"Char_LSUS");
    soldier2[19].ChangeAnimation(L"Char_LSUS");
    soldier2[21].ChangeAnimation(L"Char_LSUS");
    soldier2[23].ChangeAnimation(L"Char_LSUS");

    soldier2[8].ChangeAnimation(L"Char_FSUS");
    soldier2[9].ChangeAnimation(L"Char_FSUS");
    soldier2[12].ChangeAnimation(L"Char_FSUS");
    soldier2[13].ChangeAnimation(L"Char_FSUS");

    //// 기마
    horse_aekter->ChangeAnimation(L"Char_F");
    horse_soldier[0].ChangeAnimation(L"Char_F");
    horse_soldier[1].ChangeAnimation(L"Char_F");
    horse_general->ChangeAnimation(L"Char_F");
}

void FieldBattle::T_UnitAddTilemap()
{

     for (int i = 0; i < 6; i++)
        archer[i].ChangeAnimation(L"ARCHER_FACE_LF_STOP");


    /*CTilemap->CreateTileUnit(&archer[0], 8, 3, G_ARCHER_SOLDIER,ENEMY);
    CTilemap->CreateTileUnit(&archer[1], 11, 3, G_ARCHER_SOLDIER, ENEMY);
    CTilemap->CreateTileUnit(&archer[2], 14, 3, G_ARCHER_SOLDIER,ENEMY);
    CTilemap->CreateTileUnit(&archer[3], 21, 3, G_ARCHER_SOLDIER,ENEMY);
    CTilemap->CreateTileUnit(&archer[4], 24, 3, G_ARCHER_SOLDIER,ENEMY);
    CTilemap->CreateTileUnit(&archer[5], 27, 3, G_ARCHER_SOLDIER,ENEMY);*/
     

    soldier2[0].ChangeAnimation(L"Char_RSUS");
    CTilemap->CreateTileUnit(&soldier2[0], 5, 6,  G_SOLDIER, ENEMY);
    // 테스트
    CTilemap->CreateTileUnit(&soldier2[1], 8, 6,  G_SOLDIER,ENEMY);
    CTilemap->CreateTileUnit(&soldier2[2], 11, 6, G_SOLDIER,ENEMY);
    CTilemap->CreateTileUnit(&soldier2[3], 14, 6, G_SOLDIER,ENEMY);
    CTilemap->CreateTileUnit(&soldier2[4], 21, 6, G_SOLDIER,ENEMY);
    CTilemap->CreateTileUnit(&soldier2[5], 24, 6, G_SOLDIER,ENEMY);
    CTilemap->CreateTileUnit(&soldier2[6], 27, 6, G_SOLDIER,ENEMY);
    soldier2[7].ChangeAnimation(L"Char_LSUS");
    CTilemap->CreateTileUnit(&soldier2[7], 30, 6, G_SOLDIER, ENEMY);

    CTilemap->CreateTileUnit(&soldier2[8], 16, 8, G_SOLDIER,ENEMY);
    CTilemap->CreateTileUnit(&soldier2[9], 19, 8, G_SOLDIER,ENEMY);

    soldier2[10].ChangeAnimation(L"Char_RSUS");
    CTilemap->CreateTileUnit(&soldier2[10], 2, 9, G_SOLDIER, ENEMY);
    soldier2[11].ChangeAnimation(L"Char_RSUS");
    CTilemap->CreateTileUnit(&soldier2[11], 8, 9, G_SOLDIER, ENEMY);
    CTilemap->CreateTileUnit(&soldier2[12], 12, 9, G_SOLDIER,ENEMY);
    CTilemap->CreateTileUnit(&soldier2[13], 23, 9, G_SOLDIER,ENEMY);
    soldier2[14].ChangeAnimation(L"Char_LSUS");
    CTilemap->CreateTileUnit(&soldier2[14], 27, 9, G_SOLDIER, ENEMY);
    soldier2[15].ChangeAnimation(L"Char_LSUS");
    CTilemap->CreateTileUnit(&soldier2[15], 33, 9, G_SOLDIER, ENEMY);

    soldier2[16].ChangeAnimation(L"Char_RSUS");
    CTilemap->CreateTileUnit(&soldier2[16], 5, 10, G_SOLDIER, ENEMY);
    soldier2[17].ChangeAnimation(L"Char_LSUS");
    CTilemap->CreateTileUnit(&soldier2[17], 30, 10,G_SOLDIER, ENEMY);

    soldier2[18].ChangeAnimation(L"Char_RSUS");
    CTilemap->CreateTileUnit(&soldier2[18], 2, 12, G_SOLDIER, ENEMY);
    soldier2[19].ChangeAnimation(L"Char_LSUS");
    CTilemap->CreateTileUnit(&soldier2[19], 33, 12,G_SOLDIER, ENEMY);

    soldier2[20].ChangeAnimation(L"Char_RSUS");
    CTilemap->CreateTileUnit(&soldier2[20], 5, 13, G_SOLDIER, ENEMY);
    soldier2[21].ChangeAnimation(L"Char_LSUS");
    CTilemap->CreateTileUnit(&soldier2[21], 30, 13,G_SOLDIER, ENEMY);

    soldier2[22].ChangeAnimation(L"Char_RSUS");
    CTilemap->CreateTileUnit(&soldier2[22], 2, 15, G_SOLDIER, ENEMY);
    soldier2[23].ChangeAnimation(L"Char_LSUS");
    CTilemap->CreateTileUnit(&soldier2[23], 33, 15,G_SOLDIER, ENEMY);

    CTilemap->CreateTileUnit(horse_general, 17, 4, G_KING, ENEMY);

    CTilemap->CreateTileUnit(&horse_soldier[0], 13, 12, G_HORSE_SOLDIER, ENEMY);
    CTilemap->CreateTileUnit(&horse_soldier[1], 21, 12, G_HORSE_SOLDIER, ENEMY);

    CTilemap->CreateTileUnit(horse_aekter, 17, 16, A_KING, PLAYER);

    soldier5[0].ChangeAnimation(L"Char_RSUS");
    CTilemap->CreateTileUnit(&soldier5[0], 9, 17, A_SOLDIER, PLAYER);
    soldier5[1].ChangeAnimation(L"Char_RSUS");
    CTilemap->CreateTileUnit(&soldier5[1], 13, 17,A_SOLDIER, PLAYER);

    soldier5[2].ChangeAnimation(L"Char_RSUS");
    CTilemap->CreateTileUnit(&soldier5[2], 11, 20,A_SOLDIER, PLAYER);
    soldier5[3].ChangeAnimation(L"Char_LSUS");
    CTilemap->CreateTileUnit(&soldier5[3], 26, 17,A_SOLDIER, PLAYER);

    soldier5[4].ChangeAnimation(L"Char_LSUS");
    CTilemap->CreateTileUnit(&soldier5[4], 22, 17,A_SOLDIER, PLAYER);

    soldier5[5].ChangeAnimation(L"Char_LSUS");
    CTilemap->CreateTileUnit(&soldier5[5], 24, 20,A_SOLDIER, PLAYER);

    for (CTileUnit* it : CTilemap->mTileUnits)
        it->FindTarget();
}

void FieldBattle::onDraw(HDC hdc)
{
    HFONT oldFont;
    oldFont = (HFONT)SelectObject(hdc, hFont);
    SetBkMode(hdc, TRANSPARENT);
    CScreen Screen(hdc, 640, 480);


    /*cmap->Draw(hdc);
    CTilemap->Draw(hdc);
    UI->PlayScreenUIDraw(hdc);*/


    //cmap->Draw(hdc);
    cmap->Draw(Screen.m_HDC);
    //UI->PlayScreenUIDraw(Screen.m_HDC);
    CTilemap->Draw(Screen.m_HDC);

    Screen.Draw(hdc);


    switch (Timeline->index)
    {
    case 0:
        if (!Timeline->Textline[Timeline->index])
        {
            anicheck = true;
        }
        else
            UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
        break;
    case 1:
        if (!Timeline->Textline[Timeline->index])
        {
            anicheck = true;
        }
        else
            UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
        break;
    case 2:
        if (!Timeline->Textline[Timeline->index])
        {
            anicheck = true;
        }
        else
            UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
        break;
    case 3:
        if (!Timeline->Textline[Timeline->index])
        {
            anicheck = true;
        }
        break;
    default:
        break;
    }

    
}

void FieldBattle::onMouseDown(UINT x, UINT y, UINT left_right)
{
    if (!ClickLock)
    {
        if (Timeline->index < 3) Timeline->index++;
        else FinishedCheck = true;
    }


}

void FieldBattle::onMouseMove(UINT x, UINT y)
{
}

void FieldBattle::onKeyDown(KeyInput* virtual_key)
{
    if (virtual_key->KeyDownkey == 32)
        FinishedCheck = true;
    //다음씬 만들때쯤 풀기


}


