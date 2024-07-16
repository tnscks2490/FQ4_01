#include "pch.h"
#include "BarsiaScene2.h"
#include "CMap.h"
#include "GUI.h"
#include "TIMELINE.h"
#include "CharactorPosition.h"
#include "CScreen.h"

#define RESOURCE_NAME(x) MAKEINTRESOURCE(x),L#x

BarsiaScene2::BarsiaScene2()
{
	cmap = new CMap(RESOURCE_NAME(IDB_BRSIACASTLE));
	blackmap = new CMap(RESOURCE_NAME(IDB_BLACK),Csprite::DrawType_AlphaBlend);
	Inframe = cmap;
	
	UI = new GUI(L"BarsiaScene2");
	Timeline = new TIMELINE(9);
	
	ScreenUI = CImagefile::New(MAKEINTRESOURCE(IDB_ANI_INTRO3_FRAME),L"IDB_ANI_INTRO3_FRAME");
	scrUI.setSprite(0, 0, 0, 0, Csprite::DrawType_Transparent, RGB(255, 0, 255), ScreenUI);
	scrUI_src.setSprite(16, 16, 0, 97, Csprite::DrawType_Draw, 0, cmap->BackGroundMap);
	mScript = new Script(UI->CurruntScene);
	hFont = CreateFontW(18, 0, 0, 0, 0, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT("궁서"));

	delta=0;
	FixSC = 0; 
	screenmove = false;
	ClickLock = false;
	FinishedCheck = false;
	anicheck = false;
	CharAniEnd = false;



	///////////////////기초설정

	ares.ChangeAnimation(L"Char_BSDS");
	soldier2[0].ChangeAnimation(L"Char_RSUS");
	soldier2[3].ChangeAnimation(L"Char_LSUS");


	for (int i = 0; i < 6; i++)
		r_soldier[i].Alive = false;

}

BarsiaScene2::~BarsiaScene2()
{
	delete cmap;
	delete blackmap;
	delete UI;
	delete Timeline;

	DeleteObject(hFont);
}

bool BarsiaScene2::IsFinished()
{
	return FinishedCheck;
}

void BarsiaScene2::onFrameMove()
{
	if (anicheck)
	{
		delta++;
		CharAnimation(delta);
		if(CharAniEnd)
		{
			Timeline->Textline[Timeline->index] = true;
			anicheck = false;
			CharAniEnd = false;
			delta = 0;
		}
	}
}

void BarsiaScene2::BGCharDraw(HDC hdc)
{
	soldier1[0].Draw(hdc);
	soldier1[1].Draw(hdc);

	for (int i = 0; i < 12; i++) BgSoldier2[i].Draw(hdc);
}

void BarsiaScene2::AniCharDraw(HDC hdc)
{
	for (int i = 0; i < 4; i++)
	{
		if(soldier2[i].Alive) soldier2[i].Draw(hdc);
	}

	for (int i = 0; i < 6; i++)
	{
		if (r_soldier[i].Alive)
			r_soldier[i].Draw(hdc);
	}
	
	if(genelu.Alive) genelu.Draw(hdc);
	ares.Draw(hdc);
	if (general.Alive) general.Draw(hdc);
}

void BarsiaScene2::AniCharSet()
{
	soldier2[0].SetPosition(210, 560 - (cmap->CameraY));
	soldier2[1].ChangeAnimation(L"Char_FSUS");
	soldier2[1].SetPosition(250, 530 - (cmap->CameraY));
	soldier2[2].ChangeAnimation(L"Char_FSUS");
	soldier2[2].SetPosition(360, 530 - (cmap->CameraY));
	soldier2[3].SetPosition(400, 560 - (cmap->CameraY));

	r_soldier[0].SetPosition(240, 156);
	r_soldier[1].SetPosition(240, 155);
	r_soldier[2].SetPosition(240, 152);
	r_soldier[3].SetPosition(365, 140);
	r_soldier[4].SetPosition(365, 140);
	r_soldier[5].SetPosition(365, 140);



	genelu.SetPosition(305, 465 - (cmap->CameraY));
	ares.SetPosition(305, 630 - (cmap->CameraY));
}

void BarsiaScene2::AniChar_FrameDraw(HDC hdc)
{
	genelu.Draw(hdc);
	soldier1[0].Draw(hdc);
	soldier1[1].Draw(hdc);
}

void BarsiaScene2::AniChar_FrameSet()
{
	genelu.SetPosition(305, -80 + FixSC);
	soldier1[0].SetPosition(210,-80 + FixSC);
	soldier1[1].SetPosition(400, -80 + FixSC);
}

void BarsiaScene2::CharAnimation(int delta)
{
	switch (Timeline->index)
	{
	case 0:
		ClickLock = true;
		if (delta < 160)
		{
			cmap->CameraMove(0, 2);
			BGCharSet();
			AniCharSet();
		}
		else if (delta < 180)
		{
			if (delta == 160)
				ares.SetPosition(ares.FrameSprite.mdestX, ares.FrameSprite.mdestY-25);
		}
		else if(delta > 180)
		{
			CharAniEnd = true;
 			ClickLock = false;
		}
		break;
	case 2:
		ClickLock = true;
		if (delta < 10)
		{
			if (delta == 5) ares.ChangeAnimation(L"Char_BSUS");
		}
		else if (delta > 10)
		{
			CharAniEnd = true;
			ClickLock = false;
		}
		break;
	case 3:
		ClickLock = true;
		if (delta < 35)
		{
			if (delta % 5 == 0)
			{
				if (delta == 10)
				{
					ares.ChangeAnimation(L"Char_B");
					soldier2[1].ChangeAnimation(L"Char_RSUS");
					soldier2[2].ChangeAnimation(L"Char_LSUS");
				}
				ares.SetPosition(ares.FrameSprite.mdestX, ares.FrameSprite.mdestY - 10);
			}	
		}
		else if (delta < 410 )
		{
			if (delta % 5 == 0)
			{
				if (delta == 50)
				{
					soldier2[1].ChangeAnimation(L"Char_RSUS");
					soldier2[1].SetPosition(soldier2[1].FrameSprite.mdestX + 20, soldier2[1].FrameSprite.mdestY);
				}
				if (delta >= 55 && delta < 70)
				{
					soldier2[0].ChangeAnimation(L"Char_RSUS");
					if (delta % 5 == 0)
						soldier2[0].SetPosition(soldier2[0].FrameSprite.mdestX + 20, soldier2[0].FrameSprite.mdestY);
				}
				if (delta == 60)
				{
					soldier2[2].ChangeAnimation(L"Char_LSUS");
					soldier2[2].SetPosition(soldier2[2].FrameSprite.mdestX - 20, soldier2[2].FrameSprite.mdestY);
				}
				if (delta >= 60 && delta < 75)
				{
					soldier2[3].ChangeAnimation(L"Char_LSUS");
					if (delta % 5 == 0)
						soldier2[3].SetPosition(soldier2[3].FrameSprite.mdestX - 20, soldier2[3].FrameSprite.mdestY);
				}

				if (delta == 90)
				{
					soldier2[0].ChangeAnimation(L"Char_R");
					soldier2[1].ChangeAnimation(L"Char_R");
					soldier2[2].ChangeAnimation(L"Char_L");
					soldier2[3].ChangeAnimation(L"Char_L");
					genelu.ChangeAnimation(L"Char_F");

				}
				if (delta == 120) ares.ChangeAnimation(L"Char_LSUS");
				if (delta == 130) ares.ChangeAnimation(L"Char_FSUS");
				if (delta == 140) ares.ChangeAnimation(L"Char_RSUS");
				if (delta == 150) ares.ChangeAnimation(L"Char_BSUS");
				if (delta == 160) ares.ChangeAnimation(L"Char_LSUS");
				if (delta == 170) ares.ChangeAnimation(L"Char_BS");
				if (delta == 180) ares.ChangeAnimation(L"Char_AS");

				if (delta == 190)
				{
					ares.ChangeAnimation(L"Char_LSUS");
					genelu.ChangeAnimation(L"Char_FLS");
					soldier2[0].ChangeAnimation(L"SOLDIER2_DEATH");
					soldier2[1].ChangeAnimation(L"SOLDIER2_DEATH");
					soldier2[2].ChangeAnimation(L"SOLDIER2_DEATH");
					soldier2[3].ChangeAnimation(L"SOLDIER2_DEATH");
				}
				if (delta == 265)  // 60~70 사이 찾아서 수정할것
				{
					for (int i = 0; i < 4; i++)
					{
						soldier2[i].Alive = false;
					}
				}
				if (delta == 280)
				{
					ares.ChangeAnimation(L"Char_B");
					ares.SetPosition(ares.FrameSprite.mdestX, ares.FrameSprite.mdestY - 30);
				}
				if (delta == 340) ares.ChangeAnimation(L"Char_BSUS");		
			}	
			if (delta > 350 && blackmap->mScreen.mAlpha < 251)
				blackmap->mScreen.mAlpha += 5;
		}
		else if (delta < 480)
		{
			if (delta == 420) 
			{
				blackmap->mScreen.mAlpha = 0;
				ares.ChangeAnimation(L"ARES_BACK_ROCK");
			}
		}
		else if (delta > 480)
		{
			CharAniEnd = true;
			ClickLock = false;
		}
		break;
	case 4:
		ClickLock = true;
		if (delta < 130)
		{

			if (delta == 30) genelu.ChangeAnimation(L"GENELU_START_TELEPORT");

			if (delta == 125) genelu.Alive = false;
		
		}
		else if (delta < 290)
		{
			cmap->CameraMove(0, -2);
			BGCharSet();
			ares.SetPosition(305, 520 - (cmap->CameraY));
		}
		else if (delta < 370)
		{
			if (delta == 290)
			{
				genelu.Alive = true;
				genelu.SetPosition(305, 190-(cmap->CameraY));
				genelu.ChangeAnimation(L"GENELU_END_TELEPORT");
			}

			if (delta == 310) genelu.ChangeAnimation(L"Char_FLS");
		}
		else if (delta > 370)
		{
			CharAniEnd = true;
			ClickLock = false;
		}
		break;
	case 6:
		ClickLock = true;
		if (delta < 160)
		{
			cmap->CameraMove(0, 2);
			BGCharSet();
			ares.SetPosition(305, 520 - (cmap->CameraY));
			genelu.SetPosition(305, 190 - (cmap->CameraY));
		}
		else if( delta < 620)
		{
			if (delta == 160)
			{
				r_soldier[0].Alive = true;
				r_soldier[3].Alive = true;
			}
			if (delta <200 && delta % 5 == 0)
			{
				//r_soldier[0].SetPosition(r_soldier[0].FrameSprite.mdestX, r_soldier[0].FrameSprite.mdestY + 10);
				r_soldier[0].SetPosition(240, r_soldier[0].FrameSprite.mdestY + 10);
				r_soldier[3].SetPosition(365, r_soldier[3].FrameSprite.mdestY + 12);
			}
			if (delta == 200)
			{
				
				r_soldier[0].ChangeAnimation(L"Char_RLS");
				r_soldier[1].Alive = true;

				r_soldier[3].ChangeAnimation(L"Char_LRS");
				r_soldier[4].Alive = true;
			}
			if (delta >= 200 && delta < 220 && delta % 5 == 0)
			{
				r_soldier[1].SetPosition(240, r_soldier[1].FrameSprite.mdestY + 10);
				r_soldier[4].SetPosition(365, r_soldier[4].FrameSprite.mdestY + 15);
			}
			if (delta == 220)
			{
				r_soldier[1].SetPosition(240, r_soldier[1].FrameSprite.mdestY + 9);
				r_soldier[1].ChangeAnimation(L"Char_RLS");
				r_soldier[2].Alive = true;

				r_soldier[4].SetPosition(365, r_soldier[4].FrameSprite.mdestY + 4);
				r_soldier[4].ChangeAnimation(L"Char_LRS");
				r_soldier[5].Alive = true;
			}
			if (delta >= 220 && delta < 230 && delta % 5 == 0)
			{
				r_soldier[2].SetPosition(240, r_soldier[2].FrameSprite.mdestY + 10);
				r_soldier[5].SetPosition(365, r_soldier[5].FrameSprite.mdestY + 15);
			}
			if (delta == 230)
			{
				r_soldier[2].ChangeAnimation(L"Char_RLS");
				r_soldier[0].ChangeAnimation(L"Char_R");

				r_soldier[5].SetPosition(365, r_soldier[5].FrameSprite.mdestY + 2);
				r_soldier[5].ChangeAnimation(L"Char_LRS");
			}
			if (delta >= 230 && delta < 255 && delta % 5 == 0)
			{
				r_soldier[0].SetPosition(r_soldier[0].FrameSprite.mdestX + 9, r_soldier[0].FrameSprite.mdestY);
				r_soldier[3].SetPosition(r_soldier[3].FrameSprite.mdestX - 9, r_soldier[3].FrameSprite.mdestY);
			}
			if (delta == 255)
			{
				r_soldier[0].ChangeAnimation(L"Char_BLS");
				r_soldier[3].ChangeAnimation(L"Char_BRS");

				r_soldier[0].SetPosition(r_soldier[0].FrameSprite.mdestX + 1, r_soldier[0].FrameSprite.mdestY);
				r_soldier[3].SetPosition(r_soldier[3].FrameSprite.mdestX - 1, r_soldier[3].FrameSprite.mdestY);
			}
			if (delta == 260)
			{
				r_soldier[1].SetPosition(r_soldier[1].FrameSprite.mdestX + 32, r_soldier[1].FrameSprite.mdestY);
				r_soldier[4].SetPosition(r_soldier[4].FrameSprite.mdestX - 28, r_soldier[4].FrameSprite.mdestY);

				r_soldier[1].ChangeAnimation(L"Char_RRS");
				r_soldier[4].ChangeAnimation(L"Char_LLS");
			}
			if (delta > 260 && delta < 290 && delta % 5 == 0)
			{
				r_soldier[2].SetPosition(r_soldier[2].FrameSprite.mdestX + 9, r_soldier[2].FrameSprite.mdestY);
				r_soldier[5].SetPosition(r_soldier[5].FrameSprite.mdestX - 9, r_soldier[5].FrameSprite.mdestY);
			}
			if (delta == 290)
			{
				r_soldier[2].ChangeAnimation(L"Char_FRS");
				r_soldier[5].ChangeAnimation(L"Char_FRS");

				r_soldier[2].SetPosition(r_soldier[2].FrameSprite.mdestX + 1, r_soldier[2].FrameSprite.mdestY);
				r_soldier[5].SetPosition(r_soldier[5].FrameSprite.mdestX - 1, r_soldier[5].FrameSprite.mdestY);
			}

			if (delta == 310)
			{
				r_soldier[0].ChangeAnimation(L"Char_B");
				r_soldier[3].ChangeAnimation(L"Char_B");

				r_soldier[2].ChangeAnimation(L"Char_F");
				r_soldier[5].ChangeAnimation(L"Char_F");

				r_soldier[1].ChangeAnimation(L"Char_R");
				r_soldier[4].ChangeAnimation(L"Char_L");
				ares.ChangeAnimation(L"ARES_FACE_ROCK_SCARY");
			}
			if (delta == 500)
			{
				r_soldier[0].ChangeAnimation(L"Char_BLS");
				r_soldier[3].ChangeAnimation(L"Char_BRS");

				r_soldier[2].ChangeAnimation(L"Char_FRS");
				r_soldier[5].ChangeAnimation(L"Char_FRS");

				r_soldier[1].ChangeAnimation(L"Char_RRS");
				r_soldier[4].ChangeAnimation(L"Char_LRS");
				ares.ChangeAnimation(L"ARES_FACE_ROCK_SCARY_BACKDOWN");
				general.Alive = true;
				general.SetPosition(340, 130);
			}
			if (delta == 510) general.ChangeAnimation(L"Char_B");
			if (delta == 520) screenmove = true;
			if (delta > 520 && delta < 570 && delta % 5 == 0)
			{
				
				FixSC += 16;
				if(FixSC > 52)	AniChar_FrameSet();
			}
		}
		else if (delta > 620)
		{
			CharAniEnd = true;
			ClickLock = false;
		}
		break;
	case 7:
		ClickLock = true;
		if (delta < 50 && delta % 5 == 0)
		{
			
			FixSC -= 16;
			AniChar_FrameSet();
		}
		else if (delta > 100)
		{
			CharAniEnd = true;
			ClickLock = false;
		}
		break;
	case 8:
		ClickLock = true;
		if (delta <= 10)
		{
			if (delta == 10)
			{
				ares.SetPosition(ares.FrameSprite.mdestX, ares.FrameSprite.mdestY + 20);
				general.SetPosition(general.FrameSprite.mdestX, general.FrameSprite.mdestY + 10);
				general.ChangeAnimation(L"Char_F");
			}
		}
		if (delta > 10 && delta < 170 )
		{
			cmap->CameraMove(0, 2);
			BGCharSet();
			/*if (FixCH % 2 == 0)
			{
				for (int i = 0; i < 6; i++)
					r_soldier[i].SetPosition(r_soldier[i].FrameSprite.mdestX, r_soldier[i].FrameSprite.mdestY + 1);
				ares.SetPosition(ares.FrameSprite.mdestX, ares.FrameSprite.mdestY + 1);
				general.SetPosition(general.FrameSprite.mdestX, general.FrameSprite.mdestY + 1);
			}*/
			
		}
		else if (delta > 160)
		{
			CharAniEnd = true;
			ClickLock = false;
			Timeline->Textline[Timeline->index] = true;
			FinishedCheck = true;
		}
		break;
	default:
		break;
	}
}

void BarsiaScene2::BGCharSet()
{
	soldier1[0].SetPosition(210, 190-(cmap->CameraY));
	soldier1[1].SetPosition(400, 190 - (cmap->CameraY));

	for (int i = 0; i < 12; i++)
	{
		if (i < 6)
		{
			BgSoldier2[i].ChangeAnimation(L"Char_RSUS");
			BgSoldier2[i].SetPosition(Left_Side_Pos[i][0], Left_Side_Pos[i][1] - (cmap->CameraY));
		}
		else
		{
			BgSoldier2[i].ChangeAnimation(L"Char_LSUS");
			BgSoldier2[i].SetPosition(Right_Side_Pos[i - 6][0], Right_Side_Pos[i - 6][1] - (cmap->CameraY));
		}
	}


}

void BarsiaScene2::onDraw(HDC hdc)
{
	HFONT oldFont;
	oldFont = (HFONT)SelectObject(hdc, hFont);
	SetBkMode(hdc, TRANSPARENT);

	cmap->Draw(hdc);
	blackmap->Draw(hdc);
	BGCharDraw(hdc);																
	AniCharDraw(hdc);

	if (screenmove)
	{
		CScreen screen(hdc, 640, 158);
		scrUI_src.Draw(screen.m_HDC);
		scrUI.Draw(screen.m_HDC);
		AniChar_FrameDraw(screen.m_HDC);

		screen.Draw(hdc, 1, 33 - 160 + FixSC, 640, 158);
	}
	
	UI->UIDraw(hdc);


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
		Timeline->Textline[Timeline->index] = true;
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
		else
			UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
		break;
	case 4:
		if (!Timeline->Textline[Timeline->index])
		{
			anicheck = true;
		}
		else
			UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
		break;
	case 5:
		Timeline->Textline[Timeline->index] = true;
		UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
		break;
	case 6:
		if (!Timeline->Textline[Timeline->index])
		{
			anicheck = true;
		}
		else
			UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
		break;
	case 7:
		if (!Timeline->Textline[Timeline->index])
		{
			anicheck = true;
		}
		else
			UI->ScriptDraw(hdc, Timeline->index, mScript->ScriptV[Timeline->index]);
		break;
	case 8:
		if (!Timeline->Textline[Timeline->index])
		{
			anicheck = true;
		}
		break;
	default:
		break;
	}
}

void BarsiaScene2::onMouseDown(UINT x, UINT y, UINT left_right)
{
	if (!ClickLock)
	{
		if (Timeline->index < 8) Timeline->index++;
		else FinishedCheck = true;
	}
}

void BarsiaScene2::onMouseMove(UINT x, UINT y)
{

}

void BarsiaScene2::onKeyDown(KeyInput* virtual_key)
{
	if(virtual_key->KeyDownkey == 32)
		FinishedCheck = true;

}


