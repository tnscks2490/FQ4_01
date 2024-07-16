#include "pch.h"
#include "Canimation.h"


Canimation::~Canimation()
{
	for (int i = 0; i < m_FrameAnimations.size(); i++)
	{
		if (m_FrameAnimations[i])
		{
			delete m_FrameAnimations[i];
			m_FrameAnimations[i] = nullptr;
		}
	}
}

void Canimation::TOPBGSOLDIER_ANI()
{
	int w = 32;
	int h = 32;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face->m_Name = L"TOPBGSOLDIER";
	m_FrameAnimations.push_back(face);
}

void Canimation::BGSOLDIER_ANI()
{
	int w = 32;
	int h = 32;

	FrameAnimation* l_side = new FrameAnimation;
	l_side->m_Frames.push_back(FRAME(0, 0, w, h));
	l_side->m_Frames.push_back(FRAME(w, 0, w, h));
	l_side->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	l_side->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	l_side->m_Name = L"BGSOLDIER_LEFTSIDE";
	m_FrameAnimations.push_back(l_side);

	FrameAnimation* r_side = new FrameAnimation;
	r_side->m_Frames.push_back(FRAME(0, h, w, h));
	r_side->m_Frames.push_back(FRAME(w, h, w, h));
	r_side->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	r_side->m_Name = L"BGSOLDIER_RIGHTSIDE";
	m_FrameAnimations.push_back(r_side);
}

void Canimation::GENELU_ANI()
{
	int w = 32;
	int h = 32;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

	FrameAnimation* back = new FrameAnimation;
	back->m_Frames.push_back(FRAME(0, h, w, h));
	back->m_Frames.push_back(FRAME(w, h, w, h));
	back->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	back->m_Name = L"Char_B";
	m_FrameAnimations.push_back(back);

	FrameAnimation* brf_stop = new FrameAnimation;
	brf_stop->m_Frames.push_back(FRAME(0, h, w, h));
	brf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	brf_stop->m_Name = L"Char_BRS";
	m_FrameAnimations.push_back(brf_stop);

	FrameAnimation* stand = new FrameAnimation;
	stand->m_Frames.push_back(FRAME(0, h*2, w, h));
	stand->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	stand->m_Name = L"Char_ST";
	m_FrameAnimations.push_back(stand);


	FrameAnimation* frf_stop = new FrameAnimation;
	frf_stop->m_Frames.push_back(FRAME(0, 0 , w, h));
	frf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	frf_stop->m_Name = L"Char_FRS";
	m_FrameAnimations.push_back(frf_stop);

	FrameAnimation* flf_stop = new FrameAnimation;
	flf_stop->m_Frames.push_back(FRAME(w, 0, w, h));
	flf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	flf_stop->m_Name = L"Char_FLS";
	m_FrameAnimations.push_back(flf_stop);

	FrameAnimation* start_teleport = new FrameAnimation;
	start_teleport->m_Frames.push_back(FRAME(0, h*3, w, h));
	start_teleport->m_Frames.push_back(FRAME(0, h*4, w, h));
	start_teleport->m_Frames.push_back(FRAME(0, h * 2, w, h));
	start_teleport->m_Frames.push_back(FRAME(0, h * 5, w, h));
	start_teleport->m_AnimKeys.push_back(ANIM_KEY(0, 250));
	start_teleport->m_AnimKeys.push_back(ANIM_KEY(1, 250));
	start_teleport->m_AnimKeys.push_back(ANIM_KEY(2, 250));
	start_teleport->m_AnimKeys.push_back(ANIM_KEY(3, 250));
	start_teleport->m_Name = L"GENELU_START_TELEPORT";
	m_FrameAnimations.push_back(start_teleport);

	FrameAnimation* end_teleport = new FrameAnimation;
	end_teleport->m_Frames.push_back(FRAME(0, h*4, w, h));
	end_teleport->m_Frames.push_back(FRAME(0, h*3, w, h));
	end_teleport->m_Frames.push_back(FRAME(w, 0, w, h));
	end_teleport->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	end_teleport->m_AnimKeys.push_back(ANIM_KEY(1, 200));
	end_teleport->m_AnimKeys.push_back(ANIM_KEY(2, 100));
	end_teleport->m_Name = L"GENELU_END_TELEPORT";
	m_FrameAnimations.push_back(end_teleport);
}

void Canimation::OGG_ANI()
{
	int w = 32;
	int h = 32;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

	FrameAnimation* r_side = new FrameAnimation;
	r_side->m_Frames.push_back(FRAME(0, h, w, h));
	r_side->m_Frames.push_back(FRAME(w, h, w, h));
	r_side->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	r_side->m_Name = L"Char_R";
	m_FrameAnimations.push_back(r_side);

	FrameAnimation* face_rf_stop = new FrameAnimation;
	face_rf_stop->m_Frames.push_back(FRAME(0, 0, w, h));
	face_rf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_rf_stop->m_Name = L"Char_FRS";
	m_FrameAnimations.push_back(face_rf_stop);
}

void Canimation::THYHOOT_ANI()
{
	int w = 32;
	int h = 32;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

	FrameAnimation* face_rf_stop = new FrameAnimation;
	face_rf_stop->m_Frames.push_back(FRAME(0, 0, w, h));
	face_rf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_rf_stop->m_Name = L"Char_FRS";
	m_FrameAnimations.push_back(face_rf_stop);

	FrameAnimation* r_side = new FrameAnimation;
	r_side->m_Frames.push_back(FRAME(0, h, w, h));
	r_side->m_Frames.push_back(FRAME(w, h, w, h));
	r_side->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	r_side->m_Name = L"Char_R";
	m_FrameAnimations.push_back(r_side);
}

void Canimation::MOLDRED_ANI()
{
	int w = 32;
	int h = 32;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

	FrameAnimation* r_side = new FrameAnimation;
	r_side->m_Frames.push_back(FRAME(0, h, w, h));
	r_side->m_Frames.push_back(FRAME(w, h, w, h));
	r_side->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	r_side->m_Name = L"Char_R";
	m_FrameAnimations.push_back(r_side);

	FrameAnimation* fr_stop = new FrameAnimation;
	fr_stop->m_Frames.push_back(FRAME(0, 0, w, h));
	fr_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	fr_stop->m_Name = L"Char_FRS";
	m_FrameAnimations.push_back(fr_stop);

}

void Canimation::MACGAIA_ANI()
{
	int w = 32;
	int h = 32;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

	FrameAnimation* left = new FrameAnimation;
	left->m_Frames.push_back(FRAME(0, h, w, h));
	left->m_Frames.push_back(FRAME(w, h, w, h));
	left->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	left->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	left->m_Name = L"Char_L";
	m_FrameAnimations.push_back(left);

	FrameAnimation* left_stop = new FrameAnimation;
	left_stop->m_Frames.push_back(FRAME(0, h, w, h));
	left_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	left_stop->m_Name = L"Char_LS";
	m_FrameAnimations.push_back(left_stop);

	FrameAnimation* r_side_stop = new FrameAnimation;
	r_side_stop->m_Frames.push_back(FRAME(0, h, w, h));
	r_side_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side_stop->m_Name = L"Char_RRS";
	m_FrameAnimations.push_back(r_side_stop);
}

void Canimation::JANIL_ANI()
{
	int w = 32;
	int h = 32;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

	FrameAnimation* r_side = new FrameAnimation;
	r_side->m_Frames.push_back(FRAME(0, h, w, h));
	r_side->m_Frames.push_back(FRAME(w, h, w, h));
	r_side->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	r_side->m_Name = L"Char_R";
	m_FrameAnimations.push_back(r_side);
}

void Canimation::GENERAL_ANI()
{
	int w = 32;
	int h = 32;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);


	FrameAnimation* face_swordup_stop = new FrameAnimation;
	face_swordup_stop->m_Frames.push_back(FRAME(0, 0, w, h));
	face_swordup_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_swordup_stop->m_Name = L"Char_FSUS";
	m_FrameAnimations.push_back(face_swordup_stop);

	FrameAnimation* face_sworddown_stop = new FrameAnimation;
	face_sworddown_stop->m_Frames.push_back(FRAME(w, 0, w, h));
	face_sworddown_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_sworddown_stop->m_Name = L"Char_FSDS";
	m_FrameAnimations.push_back(face_sworddown_stop);

	FrameAnimation* back = new FrameAnimation;
	back->m_Frames.push_back(FRAME(0, h, w, h));
	back->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back->m_Name = L"Char_B";
	m_FrameAnimations.push_back(back);

}

void Canimation::SOLDIER1_ANI()
{
	int w = 32;
	int h = 32;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

	FrameAnimation* back = new FrameAnimation;
	back->m_Frames.push_back(FRAME(0, h, w, h));
	back->m_Frames.push_back(FRAME(w, h, w, h));
	back->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	back->m_Name = L"Char_B";
	m_FrameAnimations.push_back(back);
}

void Canimation::SOLDIER2_ANI()
{
	int w = 32;
	int h = 32;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

	FrameAnimation* face_SwordUp_Stop = new FrameAnimation;
	face_SwordUp_Stop->m_Frames.push_back(FRAME(0, 0, w, h));
	face_SwordUp_Stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_SwordUp_Stop->m_Name = L"Char_FSUS";
	m_FrameAnimations.push_back(face_SwordUp_Stop);

	FrameAnimation* face_SwordDown_Stop = new FrameAnimation;
	face_SwordDown_Stop->m_Frames.push_back(FRAME(w, 0, w, h));
	face_SwordDown_Stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_SwordDown_Stop->m_Name = L"Char_FSDS";
	m_FrameAnimations.push_back(face_SwordDown_Stop);


	FrameAnimation* r_side = new FrameAnimation;
	r_side->m_Frames.push_back(FRAME(0, h, w, h));
	r_side->m_Frames.push_back(FRAME(w, h, w, h));
	r_side->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	r_side->m_Name = L"Char_R";
	m_FrameAnimations.push_back(r_side);

	FrameAnimation* r_side_sword_up_stop = new FrameAnimation;
	r_side_sword_up_stop->m_Frames.push_back(FRAME(0, h, w, h));
	r_side_sword_up_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side_sword_up_stop->m_Name = L"Char_RSUS";
	m_FrameAnimations.push_back(r_side_sword_up_stop);

	FrameAnimation* r_side_sword_down_stop = new FrameAnimation;
	r_side_sword_down_stop->m_Frames.push_back(FRAME(w, h, w, h));
	r_side_sword_down_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side_sword_down_stop->m_Name = L"Char_RSDS";
	m_FrameAnimations.push_back(r_side_sword_down_stop);


	FrameAnimation* l_side = new FrameAnimation;
	l_side->m_Frames.push_back(FRAME(0, h*2, w, h));
	l_side->m_Frames.push_back(FRAME(w, h*2, w, h));
	l_side->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	l_side->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	l_side->m_Name = L"Char_L";
	m_FrameAnimations.push_back(l_side);

	FrameAnimation* l_side_sword_up_stop = new FrameAnimation;
	l_side_sword_up_stop->m_Frames.push_back(FRAME(0, h * 2, w, h));
	l_side_sword_up_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	l_side_sword_up_stop->m_Name = L"Char_LSUS";
	m_FrameAnimations.push_back(l_side_sword_up_stop);

	FrameAnimation* l_side_sword_down_stop = new FrameAnimation;
	l_side_sword_down_stop->m_Frames.push_back(FRAME(w, h * 2, w, h));
	l_side_sword_down_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	l_side_sword_down_stop->m_Name = L"Char_LSDS";
	m_FrameAnimations.push_back(l_side_sword_down_stop);

	FrameAnimation* back = new FrameAnimation;
	back->m_Frames.push_back(FRAME(0, h * 5, w, h));
	back->m_Frames.push_back(FRAME(w, h * 5, w, h));
	back->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	back->m_Name = L"Char_B";
	m_FrameAnimations.push_back(back);

	FrameAnimation* back_sworddown_stop = new FrameAnimation;
	back_sworddown_stop->m_Frames.push_back(FRAME(0, h * 5, w, h));
	back_sworddown_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back_sworddown_stop->m_Name = L"Char_BSDS";
	m_FrameAnimations.push_back(back_sworddown_stop);

	FrameAnimation* back_swordup_stop = new FrameAnimation;
	back_swordup_stop->m_Frames.push_back(FRAME(w, h * 5, w, h));
	back_swordup_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back_swordup_stop->m_Name = L"Char_BSUS";
	m_FrameAnimations.push_back(back_swordup_stop);

	FrameAnimation* dameged = new FrameAnimation;
	dameged->m_Frames.push_back(FRAME(0, h * 3, w, h));
	dameged->m_Frames.push_back(FRAME(w, h * 3, w, h));
	dameged->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	dameged->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	dameged->m_Name = L"Char_D";
	m_FrameAnimations.push_back(dameged);




	FrameAnimation* death = new FrameAnimation;
	death->m_Frames.push_back(FRAME(0, h * 3, w, h));
	death->m_Frames.push_back(FRAME(w, h * 3, w, h));
	death->m_Frames.push_back(FRAME(0, h * 4, w, h));
	death->m_Frames.push_back(FRAME(w, h * 4, w, h));
	death->m_AnimKeys.push_back(ANIM_KEY(0, 200));
	death->m_AnimKeys.push_back(ANIM_KEY(1, 200));
	death->m_AnimKeys.push_back(ANIM_KEY(2, 200));
	death->m_AnimKeys.push_back(ANIM_KEY(3, 200));
	death->m_Name = L"SOLDIER2_DEATH";
	m_FrameAnimations.push_back(death);
}

void Canimation::ROCK_SOLDIER_ANI()
{

	int w = 32;
	int h = 32;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

	FrameAnimation* face_rf_stop = new FrameAnimation;
	face_rf_stop->m_Frames.push_back(FRAME(0, 0, w, h));
	face_rf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_rf_stop->m_Name = L"Char_FRS";
	m_FrameAnimations.push_back(face_rf_stop);

	FrameAnimation* face_lf_stop = new FrameAnimation;
	face_lf_stop->m_Frames.push_back(FRAME(w, 0, w, h));
	face_lf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_lf_stop->m_Name = L"Char_FLS";
	m_FrameAnimations.push_back(face_lf_stop);


	FrameAnimation* r_side = new FrameAnimation;
	r_side->m_Frames.push_back(FRAME(0, h, w, h));
	r_side->m_Frames.push_back(FRAME(w, h, w, h));
	r_side->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	r_side->m_Name = L"Char_R";
	m_FrameAnimations.push_back(r_side);

	FrameAnimation* r_side_rf_stop = new FrameAnimation;
	r_side_rf_stop->m_Frames.push_back(FRAME(0, h, w, h));
	r_side_rf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side_rf_stop->m_Name = L"Char_RRS";
	m_FrameAnimations.push_back(r_side_rf_stop);

	FrameAnimation* r_side_lf_stop = new FrameAnimation;
	r_side_lf_stop->m_Frames.push_back(FRAME(w, h, w, h));
	r_side_lf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side_lf_stop->m_Name = L"Char_RLS";
	m_FrameAnimations.push_back(r_side_lf_stop);


	FrameAnimation* l_side = new FrameAnimation;
	l_side->m_Frames.push_back(FRAME(0, h*2, w, h));
	l_side->m_Frames.push_back(FRAME(w, h*2, w, h));
	l_side->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	l_side->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	l_side->m_Name = L"Char_L";
	m_FrameAnimations.push_back(l_side);

	FrameAnimation* l_side_rf_stop = new FrameAnimation;
	l_side_rf_stop->m_Frames.push_back(FRAME(0, h * 2, w, h));
	l_side_rf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	l_side_rf_stop->m_Name = L"Char_LRS";
	m_FrameAnimations.push_back(l_side_rf_stop);

	FrameAnimation* l_side_lf_stop = new FrameAnimation;
	l_side_lf_stop->m_Frames.push_back(FRAME(w, h * 2, w, h));
	l_side_lf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	l_side_lf_stop->m_Name = L"Char_LLS";
	m_FrameAnimations.push_back(l_side_lf_stop);


	FrameAnimation* back = new FrameAnimation;
	back->m_Frames.push_back(FRAME(0, h*3, w, h));
	back->m_Frames.push_back(FRAME(w, h*3, w, h));
	back->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	back->m_Name = L"Char_B";
	m_FrameAnimations.push_back(back);

	FrameAnimation* back_rf_stop = new FrameAnimation;
	back_rf_stop->m_Frames.push_back(FRAME(0, h * 3, w, h));
	back_rf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back_rf_stop->m_Name = L"Char_BRS";
	m_FrameAnimations.push_back(back_rf_stop);

	FrameAnimation* back_lf_stop = new FrameAnimation;
	back_lf_stop->m_Frames.push_back(FRAME(w, h * 3, w, h));
	back_lf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back_lf_stop->m_Name = L"Char_BLS";
	m_FrameAnimations.push_back(back_lf_stop);

}

void Canimation::ARCHER_ANI()
{
	int w = 32;
	int h = 32;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

	FrameAnimation* face_lf_stop = new FrameAnimation;
	face_lf_stop->m_Frames.push_back(FRAME(0, 0, w, h));
	face_lf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_lf_stop->m_Name = L"ARCHER_FACE_LF_STOP";
	m_FrameAnimations.push_back(face_lf_stop);

	FrameAnimation* face_rf_stop = new FrameAnimation;
	face_rf_stop->m_Frames.push_back(FRAME(w, 0, w, h));
	face_rf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_rf_stop->m_Name = L"ARCHER_FACE_RF_STOP";
	m_FrameAnimations.push_back(face_rf_stop);



	FrameAnimation* l_side = new FrameAnimation;
	l_side->m_Frames.push_back(FRAME(0, h, w, h));
	l_side->m_Frames.push_back(FRAME(w, h, w, h));
	l_side->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	l_side->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	l_side->m_Name = L"Char_L";
	m_FrameAnimations.push_back(l_side);

	FrameAnimation* l_side_lf_stop = new FrameAnimation;
	l_side_lf_stop->m_Frames.push_back(FRAME(0, h, w, h));
	l_side_lf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	l_side_lf_stop->m_Name = L"ARCHER_LSIDE_LF_STOP";
	m_FrameAnimations.push_back(l_side_lf_stop);

	FrameAnimation* l_side_rf_stop = new FrameAnimation;
	l_side_rf_stop->m_Frames.push_back(FRAME(w, h, w, h));
	l_side_rf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	l_side_rf_stop->m_Name = L"ARCHER_LSIDE_RF_STOP";
	m_FrameAnimations.push_back(l_side_rf_stop);



	FrameAnimation* r_side = new FrameAnimation;
	r_side->m_Frames.push_back(FRAME(0, h*2, w, h));
	r_side->m_Frames.push_back(FRAME(w, h*2, w, h));
	r_side->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	r_side->m_Name = L"Char_R";
	m_FrameAnimations.push_back(r_side);

	FrameAnimation* r_side_lf_stop = new FrameAnimation;
	r_side_lf_stop->m_Frames.push_back(FRAME(0, h * 2, w, h));
	r_side_lf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side_lf_stop->m_Name = L"ARCHER_RSIDE_LF_STOP";
	m_FrameAnimations.push_back(r_side_lf_stop);

	FrameAnimation* r_side_rf_stop = new FrameAnimation;
	r_side_rf_stop->m_Frames.push_back(FRAME(w, h * 2, w, h));
	r_side_rf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side_rf_stop->m_Name = L"ARCHER_RSIDE_RF_STOP";
	m_FrameAnimations.push_back(r_side_rf_stop);




	FrameAnimation* back = new FrameAnimation;
	back->m_Frames.push_back(FRAME(0, h*3, w, h));
	back->m_Frames.push_back(FRAME(w, h*3, w, h));
	back->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	back->m_Name = L"Char_B";
	m_FrameAnimations.push_back(back);

	FrameAnimation* back_lf_stop = new FrameAnimation;
	back_lf_stop->m_Frames.push_back(FRAME(0, h * 3, w, h));
	back_lf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back_lf_stop->m_Name = L"ARCHER_BACK_LF_STOP";
	m_FrameAnimations.push_back(back_lf_stop);

	FrameAnimation* back_rf_stop = new FrameAnimation;
	back_rf_stop->m_Frames.push_back(FRAME(w, h * 3, w, h));
	back_rf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back_rf_stop->m_Name = L"ARCHER_BACK_RF_STOP";
	m_FrameAnimations.push_back(back_lf_stop);
}

void Canimation::HORSE_GENERAL_ANI()
{
	int w = 48;
	int h = 48;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

	FrameAnimation* face_stay_stop = new FrameAnimation;
	face_stay_stop->m_Frames.push_back(FRAME(0, 0, w, h));
	face_stay_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_stay_stop->m_Name = L"HORSE_GENERAL_FACE_STAY_STOP";
	m_FrameAnimations.push_back(face_stay_stop);

	FrameAnimation* face_run_stop = new FrameAnimation;
	face_run_stop->m_Frames.push_back(FRAME(w, 0, w, h));
	face_run_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_run_stop->m_Name = L"HORSE_GENERAL_FACE_RUN_STOP";
	m_FrameAnimations.push_back(face_run_stop);


	FrameAnimation* l_side = new FrameAnimation;
	l_side->m_Frames.push_back(FRAME(0, h, w, h));
	l_side->m_Frames.push_back(FRAME(w, h, w, h));
	l_side->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	l_side->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	l_side->m_Name = L"Char_L";
	m_FrameAnimations.push_back(l_side);

	FrameAnimation* l_side_stay_stop = new FrameAnimation;
	l_side_stay_stop->m_Frames.push_back(FRAME(0, h, w, h));
	l_side_stay_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	l_side_stay_stop->m_Name = L"HORSE_GENERAL_LSIDE_STAY_STOP";
	m_FrameAnimations.push_back(l_side_stay_stop);

	FrameAnimation* l_side_run_stop = new FrameAnimation;
	l_side_run_stop->m_Frames.push_back(FRAME(w, h, w, h));
	l_side_run_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	l_side_run_stop->m_Name = L"HORSE_GENERAL_LSIDE_RUN_STOP";
	m_FrameAnimations.push_back(l_side_run_stop);


	FrameAnimation* r_side = new FrameAnimation;
	r_side->m_Frames.push_back(FRAME(0, h*2, w, h));
	r_side->m_Frames.push_back(FRAME(w, h*2, w, h));
	r_side->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	r_side->m_Name = L"Char_R";
	m_FrameAnimations.push_back(r_side);

	FrameAnimation* r_side_stay_stop = new FrameAnimation;
	r_side_stay_stop->m_Frames.push_back(FRAME(0, h*2, w, h));
	r_side_stay_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side_stay_stop->m_Name = L"HORSE_GENERAL_RSIDE_STAY_STOP";
	m_FrameAnimations.push_back(r_side_stay_stop);

	FrameAnimation* r_side_run_stop = new FrameAnimation;
	r_side_run_stop->m_Frames.push_back(FRAME(w, h*2, w, h));
	r_side_run_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side_run_stop->m_Name = L"HORSE_GENERAL_RSIDE_RUN_STOP";
	m_FrameAnimations.push_back(r_side_run_stop);


	FrameAnimation* back = new FrameAnimation;
	back->m_Frames.push_back(FRAME(0, h*3, w, h));
	back->m_Frames.push_back(FRAME(w, h*3, w, h));
	back->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	back->m_Name = L"Char_B";
	m_FrameAnimations.push_back(back);
}

void Canimation::HORSE_SOLDIER_ANI()
{
	int w = 48;
	int h = 48;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

	FrameAnimation* face_stay_stop = new FrameAnimation;
	face_stay_stop->m_Frames.push_back(FRAME(0, 0, w, h));
	face_stay_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_stay_stop->m_Name = L"HORSE_SOLDIER_FACE_STAY_STOP";
	m_FrameAnimations.push_back(face_stay_stop);

	FrameAnimation* face_run_stop = new FrameAnimation;
	face_run_stop->m_Frames.push_back(FRAME(w, 0, w, h));
	face_run_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_run_stop->m_Name = L"HORSE_SOLDIER_FACE_RUN_STOP";
	m_FrameAnimations.push_back(face_run_stop);

	FrameAnimation* l_side = new FrameAnimation;
	l_side->m_Frames.push_back(FRAME(0, h, w, h));
	l_side->m_Frames.push_back(FRAME(w, h, w, h));
	l_side->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	l_side->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	l_side->m_Name = L"Char_L";
	m_FrameAnimations.push_back(l_side);

	FrameAnimation* l_side_stay_stop = new FrameAnimation;
	l_side_stay_stop->m_Frames.push_back(FRAME(0, h, w, h));
	l_side_stay_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	l_side_stay_stop->m_Name = L"HORSE_SOLDIER_LSIDE_STAY_STOP";
	m_FrameAnimations.push_back(l_side_stay_stop);

	FrameAnimation* l_side_run_stop = new FrameAnimation;
	l_side_run_stop->m_Frames.push_back(FRAME(w, h, w, h));
	l_side_run_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	l_side_run_stop->m_Name = L"HORSE_SOLDIER_LSIDE_RUN_STOP";
	m_FrameAnimations.push_back(l_side_run_stop);


	FrameAnimation* r_side = new FrameAnimation;
	r_side->m_Frames.push_back(FRAME(0, h*2, w, h));
	r_side->m_Frames.push_back(FRAME(w, h*2, w, h));
	r_side->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	r_side->m_Name = L"Char_R";
	m_FrameAnimations.push_back(r_side);

	FrameAnimation* r_side_stay_stop = new FrameAnimation;
	r_side_stay_stop->m_Frames.push_back(FRAME(0, h * 2, w, h));
	r_side_stay_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side_stay_stop->m_Name = L"HORSE_SOLDIER_RSIDE_STAY_STOP";
	m_FrameAnimations.push_back(r_side_stay_stop);

	FrameAnimation* r_side_run_stop = new FrameAnimation;
	r_side_run_stop->m_Frames.push_back(FRAME(w, h * 2, w, h));
	r_side_run_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side_run_stop->m_Name = L"HORSE_SOLDIER_RSIDE_RUN_STOP";
	m_FrameAnimations.push_back(r_side_run_stop);


	FrameAnimation* back = new FrameAnimation;
	back->m_Frames.push_back(FRAME(0, h*3, w, h));
	back->m_Frames.push_back(FRAME(w, h*3, w, h));
	back->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	back->m_Name = L"Char_B";
	m_FrameAnimations.push_back(back);


	FrameAnimation* dameged = new FrameAnimation;
	dameged->m_Frames.push_back(FRAME(0, h * 4, w, h));
	dameged->m_Frames.push_back(FRAME(w, h*4, w, h));
	dameged->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	dameged->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	dameged->m_Name = L"Char_D";
	m_FrameAnimations.push_back(dameged);
}

void Canimation::GRIFFIN_ANI()
{
	int w = 64;
	int h = 64;

	FrameAnimation* r_side_Stop = new FrameAnimation;
	r_side_Stop->m_Frames.push_back(FRAME(0, 0, w, h));
	r_side_Stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side_Stop->m_Name = L"Char_RS";
	m_FrameAnimations.push_back(r_side_Stop);


	FrameAnimation* sleep= new FrameAnimation;
	sleep->m_Frames.push_back(FRAME(0, h, w, h));
	sleep->m_Frames.push_back(FRAME(w, h, w, h));
	sleep->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	sleep->m_AnimKeys.push_back(ANIM_KEY(1, 50));
	sleep->m_Name = L"Char_Sleep";
	m_FrameAnimations.push_back(sleep);

	FrameAnimation* wakeup = new FrameAnimation;
	wakeup->m_Frames.push_back(FRAME(0, h*2, w, h));
	wakeup->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	wakeup->m_Name = L"Char_SS";
	m_FrameAnimations.push_back(wakeup);

	FrameAnimation* wakeup_stop = new FrameAnimation;
	wakeup_stop->m_Frames.push_back(FRAME(w, h * 2, w, h));
	wakeup_stop->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	wakeup_stop->m_Name = L"Char_WS";
	m_FrameAnimations.push_back(wakeup_stop);


	FrameAnimation* ares_ride_ready = new FrameAnimation;
	ares_ride_ready->m_Frames.push_back(FRAME(0, h * 3, w, h));
	ares_ride_ready->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	ares_ride_ready->m_Name = L"Char_ARES_R";
	m_FrameAnimations.push_back(ares_ride_ready);

	FrameAnimation* ares_ride_on = new FrameAnimation;
	ares_ride_on->m_Frames.push_back(FRAME(w, h * 3, w, h));
	ares_ride_on->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	ares_ride_on->m_Name = L"Char_ARES_RO";
	m_FrameAnimations.push_back(ares_ride_on);

	FrameAnimation* ares_fly_ready = new FrameAnimation;
	ares_fly_ready->m_Frames.push_back(FRAME(0, h * 4, w, h));
	ares_fly_ready->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	ares_fly_ready->m_Name = L"Char_ARES_FR";
	m_FrameAnimations.push_back(ares_fly_ready);

	FrameAnimation* Fly = new FrameAnimation;
	Fly->m_Frames.push_back(FRAME(0, h * 5, w, h));
	Fly->m_Frames.push_back(FRAME(w, h * 5, w, h));
	Fly->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	Fly->m_AnimKeys.push_back(ANIM_KEY(1, 50));
	Fly->m_Name = L"Char_FLY";
	m_FrameAnimations.push_back(Fly);

	FrameAnimation* Fly_alone = new FrameAnimation;
	Fly_alone->m_Frames.push_back(FRAME(0, h * 7, w, h));
	Fly_alone->m_Frames.push_back(FRAME(w, h * 7, w, h));
	Fly_alone->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	Fly_alone->m_AnimKeys.push_back(ANIM_KEY(1, 50));
	Fly_alone->m_Name = L"Char_FLY_ALONE";
	m_FrameAnimations.push_back(Fly_alone);

	FrameAnimation* Fly_ready = new FrameAnimation;
	Fly_ready->m_Frames.push_back(FRAME(0, h * 6, w, h));
	Fly_ready->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	Fly_ready->m_Name = L"Char_FR";
	m_FrameAnimations.push_back(Fly_ready);





}

void Canimation::KECK_ANI()
{
	int w = 32;
	int h = 32;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

	FrameAnimation* frf_stop = new FrameAnimation;
	frf_stop->m_Frames.push_back(FRAME(0, 0, w, h));
	frf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	frf_stop->m_Name = L"Char_FRS";
	m_FrameAnimations.push_back(frf_stop);

	FrameAnimation* back = new FrameAnimation;
	back->m_Frames.push_back(FRAME(0, h, w, h));
	back->m_Frames.push_back(FRAME(w, h, w, h));
	back->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	back->m_Name = L"Char_B";
	m_FrameAnimations.push_back(back);

	FrameAnimation* brf_stop = new FrameAnimation;
	brf_stop->m_Frames.push_back(FRAME(0, h, w, h));
	brf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	brf_stop->m_Name = L"Char_BRS";
	m_FrameAnimations.push_back(brf_stop);

	FrameAnimation* blf_stop = new FrameAnimation;
	blf_stop->m_Frames.push_back(FRAME(w, h, w, h));
	blf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	blf_stop->m_Name = L"Char_BLS";
	m_FrameAnimations.push_back(blf_stop);
}

void Canimation::ORASON_ANI()
{
	int w = 32;
	int h = 32;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

	FrameAnimation* back = new FrameAnimation;
	back->m_Frames.push_back(FRAME(0, h, w, h));
	back->m_Frames.push_back(FRAME(w, h, w, h));
	back->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	back->m_Name = L"Char_B";
	m_FrameAnimations.push_back(back);

	FrameAnimation* face_sworddown_stop = new FrameAnimation;
	face_sworddown_stop->m_Frames.push_back(FRAME(0, 0, w, h));
	face_sworddown_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_sworddown_stop->m_Name = L"Char_FSDS";
	m_FrameAnimations.push_back(face_sworddown_stop);
}

void Canimation::GABI_ANI()
{
	int w = 32;
	int h = 32;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

	FrameAnimation* face_sworddown_stop = new FrameAnimation;
	face_sworddown_stop->m_Frames.push_back(FRAME(0, 0, w, h));
	face_sworddown_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_sworddown_stop->m_Name = L"Char_FSDS";
	m_FrameAnimations.push_back(face_sworddown_stop);

	FrameAnimation* back = new FrameAnimation;
	back->m_Frames.push_back(FRAME(0, h, w, h));
	back->m_Frames.push_back(FRAME(w, h, w, h));
	back->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	back->m_Name = L"Char_B";
	m_FrameAnimations.push_back(back);
}

void Canimation::LAIOS_ANI()
{
	int w = 32;
	int h = 32;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

	FrameAnimation* back = new FrameAnimation;
	back->m_Frames.push_back(FRAME(0, h, w, h));
	back->m_Frames.push_back(FRAME(w, h, w, h));
	back->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	back->m_Name = L"Char_B";
	m_FrameAnimations.push_back(back);

	FrameAnimation* face_sworddown_stop = new FrameAnimation;
	face_sworddown_stop->m_Frames.push_back(FRAME(0, 0, w, h));
	face_sworddown_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_sworddown_stop->m_Name = L"Char_FSDS";
	m_FrameAnimations.push_back(face_sworddown_stop);
}

void Canimation::MAREAM_ANI()
{
	int w = 32;
	int h = 32;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

	FrameAnimation* back = new FrameAnimation;
	back->m_Frames.push_back(FRAME(0, h, w, h));
	back->m_Frames.push_back(FRAME(w, h, w, h));
	back->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	back->m_Name = L"Char_B";
	m_FrameAnimations.push_back(back);

	FrameAnimation* face_sworddown_stop = new FrameAnimation;
	face_sworddown_stop->m_Frames.push_back(FRAME(0, 0, w, h));
	face_sworddown_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_sworddown_stop->m_Name = L"Char_FSDS";
	m_FrameAnimations.push_back(face_sworddown_stop);
}

void Canimation::MYSOLEN_ANI()
{
	int w = 32;
	int h = 32;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

	FrameAnimation* back = new FrameAnimation;
	back->m_Frames.push_back(FRAME(0, h, w, h));
	//back->m_Frames.push_back(FRAME(w, h, w, h));
	back->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	//back->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	back->m_Name = L"Char_B";
	m_FrameAnimations.push_back(back);

	FrameAnimation* face_sworddown_stop = new FrameAnimation;
	face_sworddown_stop->m_Frames.push_back(FRAME(0, 0, w, h));
	face_sworddown_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_sworddown_stop->m_Name = L"Char_FSDS";
	m_FrameAnimations.push_back(face_sworddown_stop);
}

void Canimation::SARK_ANI()
{
	int w = 32;
	int h = 32;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

	FrameAnimation* face_sworddown_stop = new FrameAnimation;
	face_sworddown_stop->m_Frames.push_back(FRAME(0, 0, w, h));
	face_sworddown_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_sworddown_stop->m_Name = L"Char_FSDS";
	m_FrameAnimations.push_back(face_sworddown_stop);

	FrameAnimation* back = new FrameAnimation;
	back->m_Frames.push_back(FRAME(0, h, w, h));
	back->m_Frames.push_back(FRAME(w, h, w, h));
	back->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	back->m_Name = L"Char_B";
	m_FrameAnimations.push_back(back);

	FrameAnimation* blf_stop = new FrameAnimation;
	blf_stop->m_Frames.push_back(FRAME(0, h, w, h));
	blf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	blf_stop->m_Name = L"Char_BLS";
	m_FrameAnimations.push_back(blf_stop);

	FrameAnimation* brf_stop = new FrameAnimation;
	brf_stop->m_Frames.push_back(FRAME(w, h, w, h));
	brf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	brf_stop->m_Name = L"Char_BRS";
	m_FrameAnimations.push_back(brf_stop);
}

void Canimation::ARCHBISHOP_ANI()
{
	int w = 32;
	int h = 32;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

	FrameAnimation* facestop = new FrameAnimation;
	facestop->m_Frames.push_back(FRAME(0, 0, w, h));
	facestop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	facestop->m_Name = L"Char_FS";
	m_FrameAnimations.push_back(facestop);
}

void Canimation::SOLDIER3_ANI()
{
	int w = 32;
	int h = 32;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

	FrameAnimation* r_side = new FrameAnimation;
	r_side->m_Frames.push_back(FRAME(0, h, w, h));
	r_side->m_Frames.push_back(FRAME(w, h, w, h));
	r_side->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	r_side->m_Name = L"Char_R";
	m_FrameAnimations.push_back(r_side);


	FrameAnimation* l_side = new FrameAnimation;
	l_side->m_Frames.push_back(FRAME(0, h*2, w, h));
	l_side->m_Frames.push_back(FRAME(w, h*2, w, h));
	l_side->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	l_side->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	l_side->m_Name = L"Char_L";
	m_FrameAnimations.push_back(l_side);
}

void Canimation::SOLDIER4_ANI()
{
	int w = 32;
	int h = 32;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

	FrameAnimation* r_side = new FrameAnimation;
	r_side->m_Frames.push_back(FRAME(0, h, w, h));
	r_side->m_Frames.push_back(FRAME(w, h, w, h));
	r_side->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	r_side->m_Name = L"Char_R";
	m_FrameAnimations.push_back(r_side);


	FrameAnimation* l_side = new FrameAnimation;
	l_side->m_Frames.push_back(FRAME(0, h * 2, w, h));
	l_side->m_Frames.push_back(FRAME(w, h*2, w, h));
	l_side->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	l_side->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	l_side->m_Name = L"Char_L";
	m_FrameAnimations.push_back(l_side);

	FrameAnimation* back = new FrameAnimation;
	back->m_Frames.push_back(FRAME(0, h * 3, w, h));
	back->m_Frames.push_back(FRAME(w, h*3, w, h));
	back->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	back->m_Name = L"Char_B";
	m_FrameAnimations.push_back(back);
}

void Canimation::ARES_ANI()
{

	int w = 32;
	int h = 32;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);
 
	FrameAnimation* face_swordup_stop = new FrameAnimation;
	face_swordup_stop->m_Frames.push_back(FRAME(w, 0, w, h));
	face_swordup_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_swordup_stop->m_Name = L"Char_FSUS";
	
	m_FrameAnimations.push_back(face_swordup_stop);

	FrameAnimation* face_sworddown_stop = new FrameAnimation;
	face_sworddown_stop->m_Frames.push_back(FRAME(0, 0, w, h));
	face_sworddown_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_sworddown_stop->m_Name = L"Char_FSDS";
	m_FrameAnimations.push_back(face_sworddown_stop);

	FrameAnimation* l_side = new FrameAnimation;
	l_side->m_Frames.push_back(FRAME(0, h, w, h));
	l_side->m_Frames.push_back(FRAME(w, h, w, h));
	l_side->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	l_side->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	l_side->m_Name = L"Char_L";
	m_FrameAnimations.push_back(l_side);

	FrameAnimation* l_side_swordup_stop = new FrameAnimation;
	l_side_swordup_stop->m_Frames.push_back(FRAME(w, h, w, h));
	l_side_swordup_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	l_side_swordup_stop->m_Name = L"Char_LSUS";
	m_FrameAnimations.push_back(l_side_swordup_stop);

	FrameAnimation* l_side_sworddown_stop = new FrameAnimation;
	l_side_sworddown_stop->m_Frames.push_back(FRAME(0, h, w, h));
	l_side_sworddown_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	l_side_sworddown_stop->m_Name = L"Char_LSDS";
	m_FrameAnimations.push_back(l_side_sworddown_stop);


	FrameAnimation* r_side = new FrameAnimation;
	r_side->m_Frames.push_back(FRAME(0, h * 2, w, h));
	r_side->m_Frames.push_back(FRAME(w, h*2, w, h));
	r_side->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	r_side->m_Name = L"Char_R";
	m_FrameAnimations.push_back(r_side);

	FrameAnimation* r_side_swordup_stop = new FrameAnimation;
	r_side_swordup_stop->m_Frames.push_back(FRAME(w, h * 2, w, h));
	r_side_swordup_stop->m_AnimKeys.push_back(ANIM_KEY(0, 200));
	r_side_swordup_stop->m_Name = L"Char_RSUS";
	m_FrameAnimations.push_back(r_side_swordup_stop);

	FrameAnimation* r_side_sworddown_stop = new FrameAnimation;
	r_side_sworddown_stop->m_Frames.push_back(FRAME(0, h * 2, w, h));
	r_side_sworddown_stop->m_AnimKeys.push_back(ANIM_KEY(0, 200));
	r_side_sworddown_stop->m_Name = L"Char_RSDS";
	m_FrameAnimations.push_back(r_side_sworddown_stop);


	FrameAnimation* face_slash = new FrameAnimation;
	face_slash->m_Frames.push_back(FRAME(0, h * 3, w, h));
	face_slash->m_Frames.push_back(FRAME(w, h * 3, w, h));
	face_slash->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_slash->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face_slash->m_Name = L"Char_SLASH";
	m_FrameAnimations.push_back(face_slash);

	FrameAnimation* face_before_slash = new FrameAnimation;
	face_before_slash->m_Frames.push_back(FRAME(0, h * 3, w, h));
	face_before_slash->m_AnimKeys.push_back(ANIM_KEY(0, 200));
	face_before_slash->m_Name = L"Char_BS";
	m_FrameAnimations.push_back(face_before_slash);

	FrameAnimation* face_after_slash = new FrameAnimation;
	face_after_slash->m_Frames.push_back(FRAME(w, h * 3, w, h));
	face_after_slash->m_AnimKeys.push_back(ANIM_KEY(0, 200));
	face_after_slash->m_Name = L"Char_AS";
	m_FrameAnimations.push_back(face_after_slash);

	FrameAnimation* back = new FrameAnimation;
	back->m_Frames.push_back(FRAME(0, h * 4, w, h));
	back->m_Frames.push_back(FRAME(w, h * 4, w, h));
	back->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	back->m_Name = L"Char_B";
	m_FrameAnimations.push_back(back);

	FrameAnimation* back_sworddown_stop = new FrameAnimation;
	back_sworddown_stop->m_Frames.push_back(FRAME(w, h * 4, w, h));
	back_sworddown_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back_sworddown_stop->m_Name = L"Char_BSUS";
	m_FrameAnimations.push_back(back_sworddown_stop);

	FrameAnimation* back_swordup_stop = new FrameAnimation;
	back_swordup_stop->m_Frames.push_back(FRAME(0, h * 4, w, h));
	back_swordup_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back_swordup_stop->m_Name = L"Char_BSDS";
	m_FrameAnimations.push_back(back_swordup_stop);

	FrameAnimation* back_rock = new FrameAnimation;
	back_rock->m_Frames.push_back(FRAME(0, h * 5, w, h));
	back_rock->m_Frames.push_back(FRAME(w, h * 5, w, h));
	back_rock->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back_rock->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	back_rock->m_Name = L"ARES_BACK_ROCK";
	m_FrameAnimations.push_back(back_rock);

	FrameAnimation* face_rock_scary = new FrameAnimation;
	face_rock_scary->m_Frames.push_back(FRAME(0, h * 6, w, h));
	face_rock_scary->m_Frames.push_back(FRAME(0, h * 7, w, h));
	face_rock_scary->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_rock_scary->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face_rock_scary->m_Name = L"ARES_FACE_ROCK_SCARY";
	m_FrameAnimations.push_back(face_rock_scary);

	FrameAnimation* face_rock_scary_backdown = new FrameAnimation;
	face_rock_scary_backdown->m_Frames.push_back(FRAME(0, h * 7, w, h));
	face_rock_scary_backdown->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_rock_scary_backdown->m_Name = L"ARES_FACE_ROCK_SCARY_BACKDOWN";
	m_FrameAnimations.push_back(face_rock_scary_backdown);

	FrameAnimation* face_rock_scary_backup = new FrameAnimation;
	face_rock_scary_backup->m_Frames.push_back(FRAME(0, h * 7, w, h));
	face_rock_scary_backup->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_rock_scary_backup->m_Name = L"ARES_FACE_ROCK_SCARY_BACKUP";
	m_FrameAnimations.push_back(face_rock_scary_backup);

	FrameAnimation* face_damaged_up_stop = new FrameAnimation;
	face_damaged_up_stop->m_Frames.push_back(FRAME(0, h * 8, w, h));
	face_damaged_up_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_damaged_up_stop->m_Name = L"Char_FDUS";
	m_FrameAnimations.push_back(face_damaged_up_stop);

	FrameAnimation* face_damaged_down_stop = new FrameAnimation;
	face_damaged_down_stop->m_Frames.push_back(FRAME(0, h * 9, w, h));
	face_damaged_down_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_damaged_down_stop->m_Name = L"Char_FDDS";
	m_FrameAnimations.push_back(face_damaged_down_stop);

	FrameAnimation* face_black = new FrameAnimation;
	face_black->m_Frames.push_back(FRAME(0, h * 10, w, h));
	face_black->m_Frames.push_back(FRAME(0, h * 11, w, h));
	face_black->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_black->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face_black->m_Name = L"Char_FB";
	m_FrameAnimations.push_back(face_black);

	FrameAnimation* face_black_stop = new FrameAnimation;
	face_black_stop->m_Frames.push_back(FRAME(0, h * 11, w, h));
	face_black_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_black_stop->m_Name = L"Char_FBS";
	m_FrameAnimations.push_back(face_black_stop);

	FrameAnimation* face_lighting = new FrameAnimation;
	face_lighting->m_Frames.push_back(FRAME(0, h * 12, w*2, h*2));
	face_lighting->m_Frames.push_back(FRAME(0, h * 14, w*2, h*2));
	face_lighting->m_AnimKeys.push_back(ANIM_KEY(0, 200));
	face_lighting->m_AnimKeys.push_back(ANIM_KEY(1, 200));
	face_lighting->m_Name = L"Char_FL";
	m_FrameAnimations.push_back(face_lighting);

}

void Canimation::GONRAD_ANI()
{
	int w = 32;
	int h = 32;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 200));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 200));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

	FrameAnimation* face_swordup_stop = new FrameAnimation;
	face_swordup_stop->m_Frames.push_back(FRAME(0, 0, w, h));
	face_swordup_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_swordup_stop->m_Name = L"Char_FSUS";
	m_FrameAnimations.push_back(face_swordup_stop);

	FrameAnimation* face_sworddown_stop = new FrameAnimation;
	face_sworddown_stop->m_Frames.push_back(FRAME(w, 0, w, h));
	face_sworddown_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_sworddown_stop->m_Name = L"Char_FSDS";
	m_FrameAnimations.push_back(face_sworddown_stop);

	FrameAnimation* r_side = new FrameAnimation;
	r_side->m_Frames.push_back(FRAME(0, h, w, h));
	r_side->m_Frames.push_back(FRAME(w, h, w, h));
	r_side->m_AnimKeys.push_back(ANIM_KEY(0, 200));
	r_side->m_AnimKeys.push_back(ANIM_KEY(1, 200));
	r_side->m_Name = L"Char_R";
	m_FrameAnimations.push_back(r_side);

	FrameAnimation* r_side_stop = new FrameAnimation;
	r_side_stop->m_Frames.push_back(FRAME(w, h, w, h));
	r_side_stop->m_AnimKeys.push_back(ANIM_KEY(0, 200));
	r_side_stop->m_Name = L"Char_RSUS";
	m_FrameAnimations.push_back(r_side_stop);

	FrameAnimation* l_side_stop = new FrameAnimation;
	l_side_stop->m_Frames.push_back(FRAME(w, h*4, w, h));
	l_side_stop->m_AnimKeys.push_back(ANIM_KEY(0, 200));
	l_side_stop->m_Name = L"Char_LSUS";
	m_FrameAnimations.push_back(l_side_stop);


	FrameAnimation* back = new FrameAnimation;
	back->m_Frames.push_back(FRAME(0, h * 2, w, h));
	back->m_Frames.push_back(FRAME(w, h*2, w, h));
	back->m_AnimKeys.push_back(ANIM_KEY(0, 200));
	back->m_AnimKeys.push_back(ANIM_KEY(1, 200));
	back->m_Name = L"Char_B";
	m_FrameAnimations.push_back(back);

	FrameAnimation* back_sds = new FrameAnimation;
	back_sds->m_Frames.push_back(FRAME(0, h * 2, w, h));
	back_sds->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back_sds->m_Name = L"Char_BSDS";
	m_FrameAnimations.push_back(back_sds);

	FrameAnimation* back_sus = new FrameAnimation;
	back_sus->m_Frames.push_back(FRAME(w, h * 2, w, h));
	back_sus->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back_sus->m_Name = L"Char_BSUS";
	m_FrameAnimations.push_back(back_sus);

	FrameAnimation* knee_down = new FrameAnimation;
	knee_down->m_Frames.push_back(FRAME(0, h * 3, w, h));
	knee_down->m_Frames.push_back(FRAME(w, h*3, w, h));
	knee_down->m_AnimKeys.push_back(ANIM_KEY(0, 200));
	knee_down->m_AnimKeys.push_back(ANIM_KEY(1, 200));
	knee_down->m_Name = L"Char_Kneel";
	m_FrameAnimations.push_back(knee_down);

}

void Canimation::AERAIN_ANI()
{
	int w = 32;
	int h = 32;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

	FrameAnimation* face_sworddown_stop = new FrameAnimation;
	face_sworddown_stop->m_Frames.push_back(FRAME(0, 0, w, h));
	face_sworddown_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_sworddown_stop->m_Name = L"Char_FSDS";
	m_FrameAnimations.push_back(face_sworddown_stop);

	FrameAnimation* face_swordup_stop = new FrameAnimation;
	face_swordup_stop->m_Frames.push_back(FRAME(w, 0, w, h));
	face_swordup_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_swordup_stop->m_Name = L"Char_FSUS";
	m_FrameAnimations.push_back(face_swordup_stop);


	FrameAnimation* l_side = new FrameAnimation;
	l_side->m_Frames.push_back(FRAME(0, h, w, h));
	l_side->m_Frames.push_back(FRAME(w, h, w, h));
	l_side->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	l_side->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	l_side->m_Name = L"Char_L";
	m_FrameAnimations.push_back(l_side);

	FrameAnimation* l_side_swordup_stop = new FrameAnimation;
	l_side_swordup_stop->m_Frames.push_back(FRAME(w, h, w, h));
	l_side_swordup_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	l_side_swordup_stop->m_Name = L"Char_LSUS";
	m_FrameAnimations.push_back(l_side_swordup_stop);

	FrameAnimation* l_side_sworddown_stop = new FrameAnimation;
	l_side_sworddown_stop->m_Frames.push_back(FRAME(0, h, w, h));
	l_side_sworddown_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	l_side_sworddown_stop->m_Name = L"Char_LSDS";
	m_FrameAnimations.push_back(l_side_sworddown_stop);




	FrameAnimation* r_side = new FrameAnimation;
	r_side->m_Frames.push_back(FRAME(0, h*2, w, h));
	r_side->m_Frames.push_back(FRAME(w, h*2, w, h));
	r_side->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	r_side->m_Name = L"Char_R";
	m_FrameAnimations.push_back(r_side);

	FrameAnimation* r_side_sworddown_stop = new FrameAnimation;
	r_side_sworddown_stop->m_Frames.push_back(FRAME(0, h * 2, w, h));
	r_side_sworddown_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side_sworddown_stop->m_Name = L"Char_RSDS";
	m_FrameAnimations.push_back(r_side_sworddown_stop);

	FrameAnimation* r_side_swordup_stop = new FrameAnimation;
	r_side_swordup_stop->m_Frames.push_back(FRAME(w, h * 2, w, h));
	r_side_swordup_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side_swordup_stop->m_Name = L"Char_RSUS";
	m_FrameAnimations.push_back(r_side_swordup_stop);


	FrameAnimation* back = new FrameAnimation;
	back->m_Frames.push_back(FRAME(0, h * 3, w, h));
	back->m_Frames.push_back(FRAME(w, h * 3, w, h));
	back->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	back->m_Name = L"Char_B";
	m_FrameAnimations.push_back(back);

	FrameAnimation* slash = new FrameAnimation;
	slash->m_Frames.push_back(FRAME(0, h * 4, w, h));
	slash->m_Frames.push_back(FRAME(w, h * 4, w, h));
	slash->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	slash->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	slash->m_Name = L"AERAIN_SLASH";
	m_FrameAnimations.push_back(slash);

	FrameAnimation* before_slash = new FrameAnimation;
	before_slash->m_Frames.push_back(FRAME(0, h * 4, w, h));
	before_slash->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	before_slash->m_Name = L"Char_BS";
	m_FrameAnimations.push_back(before_slash);

	FrameAnimation* after_slash = new FrameAnimation;
	after_slash->m_Frames.push_back(FRAME(w, h * 4, w, h));
	after_slash->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	after_slash->m_Name = L"Char_AS";
	m_FrameAnimations.push_back(after_slash);

}

void Canimation::AEKTER_ANI()
{
	int w = 31;
	int h = 32;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);
}

void Canimation::HORSE_AEKTER_ANI()
{
	int w = 48;
	int h = 48;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

	FrameAnimation* face_stay_stop = new FrameAnimation;
	face_stay_stop->m_Frames.push_back(FRAME(w, 0, w, h));
	face_stay_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_stay_stop->m_Name = L"HORSE_AEKTER_FACE_STAY_STOP";
	m_FrameAnimations.push_back(face_stay_stop);

	FrameAnimation* face_run_stop = new FrameAnimation;
	face_run_stop->m_Frames.push_back(FRAME(0, 0, w, h));
	face_run_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_run_stop->m_Name = L"HORSE_AEKTER_FACE_RUN_STOP";
	m_FrameAnimations.push_back(face_run_stop);

	FrameAnimation* l_side = new FrameAnimation;
	l_side->m_Frames.push_back(FRAME(0, h, w, h));
	l_side->m_Frames.push_back(FRAME(w, h, w, h));
	l_side->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	l_side->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	l_side->m_Name = L"Char_L";
	m_FrameAnimations.push_back(l_side);

	FrameAnimation* r_side = new FrameAnimation;
	r_side->m_Frames.push_back(FRAME(0, h*2, w, h));
	r_side->m_Frames.push_back(FRAME(w, h*2, w, h));
	r_side->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	r_side->m_Name = L"Char_R";
	m_FrameAnimations.push_back(r_side);

	FrameAnimation* back = new FrameAnimation;
	back->m_Frames.push_back(FRAME(0, h*3, w, h));
	back->m_Frames.push_back(FRAME(w, h*3, w, h));
	back->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	back->m_Name = L"Char_B";
	m_FrameAnimations.push_back(back);

	FrameAnimation* back_stay_stop = new FrameAnimation;
	back_stay_stop->m_Frames.push_back(FRAME(w, h * 3, w, h));
	back_stay_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back_stay_stop->m_Name = L"HORSE_AEKTER_BACK_STAY_STOP";
	m_FrameAnimations.push_back(back_stay_stop);

	FrameAnimation* back_run_stop = new FrameAnimation;
	back_run_stop->m_Frames.push_back(FRAME(0, h * 3, w, h));
	back_run_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back_run_stop->m_Name = L"HORSE_AEKTER_BACK_RUN_STOP";
	m_FrameAnimations.push_back(back_run_stop);

	FrameAnimation* dameged = new FrameAnimation;
	dameged->m_Frames.push_back(FRAME(0, h*4, w, h));
	dameged->m_Frames.push_back(FRAME(w, h*4, w, h));
	dameged->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	dameged->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	dameged->m_Name = L"Char_D";
	m_FrameAnimations.push_back(dameged);

}

void Canimation::SOLDIER5_ANI()
{
	int w = 32;
	int h = 32;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

	FrameAnimation* face_lf_stop = new FrameAnimation;
	face_lf_stop->m_Frames.push_back(FRAME(0, 0, w, h));
	face_lf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_lf_stop->m_Name = L"Char_FSUS";
	m_FrameAnimations.push_back(face_lf_stop);

	FrameAnimation* face_rf_stop = new FrameAnimation;
	face_lf_stop->m_Frames.push_back(FRAME(w, 0, w, h));
	face_lf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_lf_stop->m_Name = L"Char_FSDS";
	m_FrameAnimations.push_back(face_lf_stop);



	FrameAnimation* l_side = new FrameAnimation;
	l_side->m_Frames.push_back(FRAME(0, h, w, h));
	l_side->m_Frames.push_back(FRAME(w, h, w, h));
	l_side->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	l_side->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	l_side->m_Name = L"Char_L";
	m_FrameAnimations.push_back(l_side);

	FrameAnimation* l_side_rf_stop = new FrameAnimation;
	l_side_rf_stop->m_Frames.push_back(FRAME(0, h, w, h));
	l_side_rf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	l_side_rf_stop->m_Name = L"Char_LSDS";
	m_FrameAnimations.push_back(l_side_rf_stop);

	FrameAnimation* l_side_lf_stop = new FrameAnimation;
	l_side_lf_stop->m_Frames.push_back(FRAME(w, h, w, h));
	l_side_lf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	l_side_lf_stop->m_Name = L"Char_LSUS";
	m_FrameAnimations.push_back(l_side_lf_stop);


	FrameAnimation* r_side = new FrameAnimation;
	r_side->m_Frames.push_back(FRAME(0, h*2, w, h));
	r_side->m_Frames.push_back(FRAME(w, h*2, w, h));
	r_side->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	r_side->m_Name = L"Char_R";
	m_FrameAnimations.push_back(r_side);

	FrameAnimation* r_side_rf_stop = new FrameAnimation;
	r_side_rf_stop->m_Frames.push_back(FRAME(0, h * 2, w, h));
	r_side_rf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side_rf_stop->m_Name = L"Char_RSDS";
	m_FrameAnimations.push_back(r_side_rf_stop);

	FrameAnimation* r_side_lf_stop = new FrameAnimation;
	r_side_lf_stop->m_Frames.push_back(FRAME(w, h * 2, w, h));
	r_side_lf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side_lf_stop->m_Name = L"Char_RSUS";
	m_FrameAnimations.push_back(r_side_lf_stop);




	FrameAnimation* back = new FrameAnimation;
	back->m_Frames.push_back(FRAME(0, h*3, w, h));
	back->m_Frames.push_back(FRAME(w, h*3, w, h));
	back->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	back->m_Name = L"Char_B";
	m_FrameAnimations.push_back(back);

	FrameAnimation* back_rf_stop = new FrameAnimation;
	back_rf_stop->m_Frames.push_back(FRAME(0, h * 3, w, h));
	back_rf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back_rf_stop->m_Name = L"Char_BSDS";
	m_FrameAnimations.push_back(back_rf_stop);

	FrameAnimation* back_lf_stop = new FrameAnimation;
	back_lf_stop->m_Frames.push_back(FRAME(w, h * 3, w, h));
	back_lf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back_lf_stop->m_Name = L"Char_BSUS";
	m_FrameAnimations.push_back(back_lf_stop);



	FrameAnimation* dameged = new FrameAnimation;
	dameged->m_Frames.push_back(FRAME(0, h*4, w, h));
	dameged->m_Frames.push_back(FRAME(w, h*4, w, h));
	dameged->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	dameged->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	dameged->m_Name = L"Char_D";
	m_FrameAnimations.push_back(dameged);

	FrameAnimation* death = new FrameAnimation;
	death->m_Frames.push_back(FRAME(0, h * 4, w, h));
	death->m_Frames.push_back(FRAME(w, h * 4, w, h));
	death->m_Frames.push_back(FRAME(0, h*5, w, h));
	death->m_Frames.push_back(FRAME(w, h*5, w, h));
	death->m_AnimKeys.push_back(ANIM_KEY(0, 200));
	death->m_AnimKeys.push_back(ANIM_KEY(1, 200));
	death->m_AnimKeys.push_back(ANIM_KEY(2, 200));
	death->m_AnimKeys.push_back(ANIM_KEY(3, 200));
	death->m_Name = L"Char_DEATH";
	m_FrameAnimations.push_back(death);
}

void Canimation::CROW_ANI()
{
	int w = 32;
	int h = 32;

	FrameAnimation* face_kneel = new FrameAnimation;
	face_kneel->m_Frames.push_back(FRAME(0, 0, w, h));
	face_kneel->m_Frames.push_back(FRAME(w, 0, w, h));
	face_kneel->m_AnimKeys.push_back(ANIM_KEY(0, 200));
	face_kneel->m_AnimKeys.push_back(ANIM_KEY(1, 200));
	face_kneel->m_Name = L"Char_FKL";
	m_FrameAnimations.push_back(face_kneel);

	FrameAnimation* face_kneel_down = new FrameAnimation;
	face_kneel_down->m_Frames.push_back(FRAME(0, 0, w, h));
	face_kneel_down->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_kneel_down->m_Name = L"Char_FKD";
	m_FrameAnimations.push_back(face_kneel_down);

	FrameAnimation* face_kneel_up = new FrameAnimation;
	face_kneel_up->m_Frames.push_back(FRAME(w, 0, w, h));
	face_kneel_up->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_kneel_up->m_Name = L"Char_FKU";
	m_FrameAnimations.push_back(face_kneel_up);

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, h*4, w, h));
	face->m_Frames.push_back(FRAME(w, h*4, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 50));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

	FrameAnimation* face_swordup_stop = new FrameAnimation;
	face_swordup_stop->m_Frames.push_back(FRAME(0, h * 4, w, h));
	face_swordup_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_swordup_stop->m_Name = L"Char_FSUS";
	m_FrameAnimations.push_back(face_swordup_stop);

	FrameAnimation* face_sworddown_stop = new FrameAnimation;
	face_sworddown_stop->m_Frames.push_back(FRAME(w, h * 4, w, h));
	face_sworddown_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_sworddown_stop->m_Name = L"Char_FSDS";
	m_FrameAnimations.push_back(face_sworddown_stop);

	FrameAnimation* r_side = new FrameAnimation;
	r_side->m_Frames.push_back(FRAME(0, h, w, h));
	r_side->m_Frames.push_back(FRAME(w, h, w, h));
	r_side->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	r_side->m_AnimKeys.push_back(ANIM_KEY(1, 50));
	r_side->m_Name = L"Char_R";
	m_FrameAnimations.push_back(r_side);

	FrameAnimation* r_side_lf_stop = new FrameAnimation;
	r_side_lf_stop->m_Frames.push_back(FRAME(0, h, w, h));
	r_side_lf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side_lf_stop->m_Name = L"Char_RLS";
	m_FrameAnimations.push_back(r_side_lf_stop);

	FrameAnimation* r_side_rf_stop = new FrameAnimation;
	r_side_rf_stop->m_Frames.push_back(FRAME(w, h, w, h));
	r_side_rf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	r_side_rf_stop->m_Name = L"Char_RRS";
	m_FrameAnimations.push_back(r_side_rf_stop);


	FrameAnimation* l_side = new FrameAnimation;
	l_side->m_Frames.push_back(FRAME(0, h*2, w, h));
	l_side->m_Frames.push_back(FRAME(w, h*2, w, h));
	l_side->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	l_side->m_AnimKeys.push_back(ANIM_KEY(1, 50));
	l_side->m_Name = L"Char_L";
	m_FrameAnimations.push_back(l_side);

	FrameAnimation* l_side_lf_stop = new FrameAnimation;
	l_side_lf_stop->m_Frames.push_back(FRAME(0, h * 2, w, h));
	l_side_lf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	l_side_lf_stop->m_Name = L"Char_LLS";
	m_FrameAnimations.push_back(l_side_lf_stop);

	FrameAnimation* l_side_rf_stop = new FrameAnimation;
	l_side_rf_stop->m_Frames.push_back(FRAME(w, h * 2, w, h));
	l_side_rf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	l_side_rf_stop->m_Name = L"Char_LRS";
	m_FrameAnimations.push_back(l_side_rf_stop);

	FrameAnimation* back = new FrameAnimation;
	back->m_Frames.push_back(FRAME(0, h*3, w, h));
	back->m_Frames.push_back(FRAME(w, h*3, w, h));
	back->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	back->m_AnimKeys.push_back(ANIM_KEY(1, 50));
	back->m_Name = L"Char_B";
	m_FrameAnimations.push_back(back);

	FrameAnimation* back_lf_stop = new FrameAnimation;
	back_lf_stop->m_Frames.push_back(FRAME(0, h * 3, w, h));
	back_lf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back_lf_stop->m_Name = L"Char_BLS";
	m_FrameAnimations.push_back(back_lf_stop);

	FrameAnimation* back_rf_stop = new FrameAnimation;
	back_rf_stop->m_Frames.push_back(FRAME(0, h * 3, w, h));
	back_rf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back_rf_stop->m_Name = L"Char_BRS";
	m_FrameAnimations.push_back(back_rf_stop);
}

void Canimation::RADINKAL_ANI()
{
	int w = 32;
	int h = 32;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

	FrameAnimation* face_sds = new FrameAnimation;
	face_sds->m_Frames.push_back(FRAME(0, 0, w, h));
	face_sds->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_sds->m_Name = L"Char_FSDS";
	m_FrameAnimations.push_back(face_sds);

	FrameAnimation* face_sus = new FrameAnimation;
	face_sus->m_Frames.push_back(FRAME(w, 0, w, h));
	face_sus->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face_sus->m_Name = L"Char_FSUS";
	m_FrameAnimations.push_back(face_sus);

	FrameAnimation* right = new FrameAnimation;
	right->m_Frames.push_back(FRAME(0, h, w, h));
	right->m_Frames.push_back(FRAME(w, h, w, h));
	right->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	right->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	right->m_Name = L"Char_R";
	m_FrameAnimations.push_back(right);

	FrameAnimation* right_sds = new FrameAnimation;
	right_sds->m_Frames.push_back(FRAME(0, h, w, h));
	right_sds->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	right_sds->m_Name = L"Char_RSDS";
	m_FrameAnimations.push_back(right_sds);

	FrameAnimation* right_sus = new FrameAnimation;
	right_sus->m_Frames.push_back(FRAME(w, h, w, h));
	right_sus->m_AnimKeys.push_back(ANIM_KEY(0,100));
	right_sus->m_Name = L"Char_RSUS";
	m_FrameAnimations.push_back(right_sus);

	FrameAnimation* left_sus = new FrameAnimation;
	left_sus->m_Frames.push_back(FRAME(w, h * 2, w, h));
	left_sus->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	left_sus->m_Name = L"Char_LSUS";
	m_FrameAnimations.push_back(left_sus);

	FrameAnimation* back_sus = new FrameAnimation;
	back_sus->m_Frames.push_back(FRAME(w, h * 3, w, h));
	back_sus->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	back_sus->m_Name = L"Char_BSUS";
	m_FrameAnimations.push_back(back_sus);


}

void Canimation::ALFRED_ANI()
{
	int w = 32;
	int h = 32;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

	FrameAnimation* face_sds = new FrameAnimation;
	face_sds->m_Frames.push_back(FRAME(0, 0, w, h));
	face_sds->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	face_sds->m_Name = L"Char_FSDS";
	m_FrameAnimations.push_back(face_sds);

	FrameAnimation* face_sus = new FrameAnimation;
	face_sus->m_Frames.push_back(FRAME(w, 0, w, h));
	face_sus->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	face_sus->m_Name = L"Char_FSUS";
	m_FrameAnimations.push_back(face_sus);


	FrameAnimation* right = new FrameAnimation;
	right->m_Frames.push_back(FRAME(0, h, w, h));
	right->m_Frames.push_back(FRAME(w, h, w, h));
	right->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	right->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	right->m_Name = L"Char_R";
	m_FrameAnimations.push_back(right);

	FrameAnimation* right_sds = new FrameAnimation;
	right_sds->m_Frames.push_back(FRAME(0, h, w, h));
	right_sds->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	right_sds->m_Name = L"Char_RSDS";
	m_FrameAnimations.push_back(right_sds);

	FrameAnimation* right_sus = new FrameAnimation;
	right_sus->m_Frames.push_back(FRAME(w, h, w, h));
	right_sus->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	right_sus->m_Name = L"Char_RSUS";
	m_FrameAnimations.push_back(right_sus);

	FrameAnimation* left_sus = new FrameAnimation;
	left_sus->m_Frames.push_back(FRAME(w, h*2, w, h));
	left_sus->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	left_sus->m_Name = L"Char_LSUS";
	m_FrameAnimations.push_back(left_sus);

	FrameAnimation* back_sus = new FrameAnimation;
	back_sus->m_Frames.push_back(FRAME(w, h * 3, w, h));
	back_sus->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	back_sus->m_Name = L"Char_BSUS";
	m_FrameAnimations.push_back(back_sus);
}

void Canimation::GARRARD_ANI()
{
	int w = 32;
	int h = 32;


	FrameAnimation* back = new FrameAnimation;
	back->m_Frames.push_back(FRAME(0, 0, w, h));
	back->m_Frames.push_back(FRAME(w, 0, w, h));
	back->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	back->m_AnimKeys.push_back(ANIM_KEY(1, 50));
	back->m_Name = L"Char_B";
	m_FrameAnimations.push_back(back);

	FrameAnimation* back_rf_stop = new FrameAnimation;
	back_rf_stop->m_Frames.push_back(FRAME(0, 0, w, h));
	back_rf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	back_rf_stop->m_Name = L"Char_BRS";
	m_FrameAnimations.push_back(back_rf_stop);

	FrameAnimation* back_lf_stop = new FrameAnimation;
	back_lf_stop->m_Frames.push_back(FRAME(w, 0, w, h));
	back_lf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	back_lf_stop->m_Name = L"Char_BLS";
	m_FrameAnimations.push_back(back_lf_stop);

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, h*2, w, h));
	face->m_Frames.push_back(FRAME(w, h*2, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 50));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

	FrameAnimation* face_rf_stop = new FrameAnimation;
	face_rf_stop->m_Frames.push_back(FRAME(0, h * 2, w, h));
	face_rf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	face_rf_stop->m_Name = L"Char_FRS";
	m_FrameAnimations.push_back(face_rf_stop);

	FrameAnimation* face_lf_stop = new FrameAnimation;
	face_lf_stop->m_Frames.push_back(FRAME(w, h * 2, w, h));
	face_lf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	face_lf_stop->m_Name = L"Char_FLS";
	m_FrameAnimations.push_back(face_lf_stop);


	FrameAnimation* r_side = new FrameAnimation;
	r_side->m_Frames.push_back(FRAME(0, h, w, h));
	r_side->m_Frames.push_back(FRAME(w, h, w, h));
	r_side->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	r_side->m_AnimKeys.push_back(ANIM_KEY(1, 50));
	r_side->m_Name = L"Char_R";
	m_FrameAnimations.push_back(r_side);

	FrameAnimation* l_side = new FrameAnimation;
	l_side->m_Frames.push_back(FRAME(0, h * 3, w, h));
	l_side->m_Frames.push_back(FRAME(w, h * 3, w, h));
	l_side->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	l_side->m_AnimKeys.push_back(ANIM_KEY(1, 50));
	l_side->m_Name = L"Char_L";
	m_FrameAnimations.push_back(l_side);

	FrameAnimation* l_side_lf_stop = new FrameAnimation;
	l_side_lf_stop->m_Frames.push_back(FRAME(0, h * 3, w, h));
	l_side_lf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	l_side_lf_stop->m_Name = L"Char_LLS";
	m_FrameAnimations.push_back(l_side_lf_stop);

	FrameAnimation* l_side_rf_stop = new FrameAnimation;
	l_side_rf_stop->m_Frames.push_back(FRAME(w, h * 3, w, h));
	l_side_rf_stop->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	l_side_rf_stop->m_Name = L"Char_LRS";
	m_FrameAnimations.push_back(l_side_rf_stop);
}

void Canimation::CANDLESTICK_ANI()
{
	int w = 48;
	int h = 96;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 50));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);


}

void Canimation::ARMOR_ANI()
{
	int w = 32;
	int h = 48;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 50));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

	FrameAnimation* slashed = new FrameAnimation;
	slashed->m_Frames.push_back(FRAME(0, 0, w, h));
	slashed->m_Frames.push_back(FRAME(0, h, w, h));
	slashed->m_Frames.push_back(FRAME(0, h*2, w, h));
	slashed->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	slashed->m_AnimKeys.push_back(ANIM_KEY(1, 100));
	slashed->m_AnimKeys.push_back(ANIM_KEY(2, 100));
	slashed->m_Name = L"Char_Slashed";
	m_FrameAnimations.push_back(slashed);

	FrameAnimation* half_slashed = new FrameAnimation;
	half_slashed->m_Frames.push_back(FRAME(0, h, w, h));
	half_slashed->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	half_slashed->m_Name = L"Char_HS";
	m_FrameAnimations.push_back(half_slashed);

	FrameAnimation* full_slashed = new FrameAnimation;
	full_slashed->m_Frames.push_back(FRAME(0, h*2, w, h));
	full_slashed->m_AnimKeys.push_back(ANIM_KEY(0, 100));
	full_slashed->m_Name = L"Char_FS";
	m_FrameAnimations.push_back(full_slashed);
}

void Canimation::BRAZIER_ANI()
{
	int w = 32;
	int h = 48;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(w, 0, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 50));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

	FrameAnimation* face_stop = new FrameAnimation;
	face_stop->m_Frames.push_back(FRAME(0, 0, w, h));
	face_stop->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	face_stop->m_Name = L"Char_FS";
	m_FrameAnimations.push_back(face_stop);
}

void Canimation::G_FLAG_ANI()
{
	int w = 26;
	int h = 40;

	FrameAnimation* face = new FrameAnimation;
	face->m_Frames.push_back(FRAME(0, 0, w, h));
	face->m_Frames.push_back(FRAME(0, h, w, h));
	face->m_Frames.push_back(FRAME(0, h*2, w, h));
	face->m_AnimKeys.push_back(ANIM_KEY(0, 50));
	face->m_AnimKeys.push_back(ANIM_KEY(1, 50));
	face->m_AnimKeys.push_back(ANIM_KEY(2, 50));
	face->m_Name = L"Char_F";
	m_FrameAnimations.push_back(face);

}

FrameAnimation* Canimation::Find(std::wstring& name)
{
	for (auto ptr : m_FrameAnimations)
	{
		if (ptr->m_Name == name)
			return ptr;
	}
	return nullptr;
}

void CFrameSprite::Set2(const WCHAR* pname, int dx, int dy, Canimation* ani, CImagefile* img,TDrawType dt,UINT color)
{

	std::wstring name(pname);
	Csprite::setSprite(dx, dy, 0, 0, dt, color, img);
	m_Animation = ani;
	ChageAnimation(name);
}

void CFrameSprite::ChageAnimation(std::wstring& name)
{
	m_CurrentFAni = m_Animation->Find(name);
	ANIM_KEY key = m_CurrentFAni->m_AnimKeys[0];

	m_AnimInst.anikeyNo = 0;
	m_AnimInst.currentTime = 0;
	m_AnimInst.delayTime = key.delayTime;
	m_AnimInst.frame = m_CurrentFAni->m_Frames[key.frameNo];
}

void CFrameSprite::Update(int dt)
{
	m_AnimInst.currentTime += dt;
	m_AnimInst.delayTime -= dt;

	m_CurrentFAni->UpdateInstance(m_AnimInst);

	mSrcX = m_AnimInst.frame.x;
	mSrcY = m_AnimInst.frame.y;
	mSrcWidth = m_AnimInst.frame.width;
	mSrcHeight = m_AnimInst.frame.height;

}

void FrameAnimation::UpdateInstance(FRAMEANIM_INSTANCE& inst)
{
	if (inst.delayTime > 0)return;
	inst.anikeyNo++;
	inst.anikeyNo = inst.anikeyNo % m_AnimKeys.size();

	inst.delayTime = m_AnimKeys[inst.anikeyNo].delayTime;
	inst.frame = m_Frames[m_AnimKeys[inst.anikeyNo].frameNo];
}
