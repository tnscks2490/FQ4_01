#pragma once
#include "Csprite.h"

// 여러 모션을 각각 분리해서 저장하는 구조체
struct FRAME
{
	int x;
	int y;
	int width;
	int height;

	FRAME() :x(0), y(0), width(0), height(0) {}
	FRAME(int _x, int _y, int _w, int _h) : x(_x), y(_y), width(_w), height(_h) {}
};


// 어떤 모션인지, 얼마나 사용했는지 저장하는 구조체
struct ANIM_KEY 
{

	int frameNo;
	int delayTime;

	ANIM_KEY(): frameNo(0), delayTime(0) {}
	ANIM_KEY(int frameNo, int delayTime) : frameNo(frameNo), delayTime(delayTime) {}
};

struct FRAMEANIM_INSTANCE 
{
	int currentTime;
	int delayTime;
	int anikeyNo;
	FRAME frame;
};

// 실질적으로 애니메이션으로 할 수 있도록 각 모션과 현재 모션을 저장하여 관리
struct FrameAnimation 
{
	std::wstring m_Name;
	std::vector <FRAME> m_Frames;
	std::vector <ANIM_KEY> m_AnimKeys;

	void UpdateInstance(FRAMEANIM_INSTANCE& inst);
};



class Canimation
{
public:
	// 포인터를 사용하는 이유 값 복사가 이뤄지기때문에 편하게 작업하기위함이다.
	std::vector<FrameAnimation* > m_FrameAnimations;

	~Canimation();
	// 배경 병사
	void TOPBGSOLDIER_ANI();
	void BGSOLDIER_ANI();



	// 제넬루와 친구들
	void GENELU_ANI();
	void OGG_ANI();
	void THYHOOT_ANI();
	void MOLDRED_ANI();
	void MACGAIA_ANI();
	void JANIL_ANI();
	void GENERAL_ANI();
	void SOLDIER1_ANI();
	void SOLDIER2_ANI();
	void ROCK_SOLDIER_ANI();
	void ARCHER_ANI();
	void HORSE_GENERAL_ANI();
	void HORSE_SOLDIER_ANI();
	void GRIFFIN_ANI();

	// 반제넬루파
	void KECK_ANI();
	void ORASON_ANI();
	void GABI_ANI();
	void LAIOS_ANI();
	void MAREAM_ANI();
	void MYSOLEN_ANI();
	void SARK_ANI();

	// 카리온성 캐릭터
	void ARCHBISHOP_ANI();
	void SOLDIER3_ANI();
	void SOLDIER4_ANI();
	void ARES_ANI();
	void GONRAD_ANI();
	void AERAIN_ANI();
	void AEKTER_ANI();
	void HORSE_AEKTER_ANI();
	void SOLDIER5_ANI();
	void CROW_ANI();

	// 카리온 동맹국
	void RADINKAL_ANI();
	void ALFRED_ANI();


	// 그 외 (나중에 진영 생기면 추가할것)
	void GARRARD_ANI();


	// 배경 오브젝트
	void CANDLESTICK_ANI();
	void ARMOR_ANI();
	void BRAZIER_ANI();
	void G_FLAG_ANI();

	FrameAnimation* Find(std::wstring& name);
};

struct ANIM_FILE
{
	CImagefile* imgFile;
	Canimation* ani;
};


class CFrameSprite : public Csprite
{
public:
	Canimation* m_Animation;
	FrameAnimation* m_CurrentFAni;

	FRAMEANIM_INSTANCE m_AnimInst;

	void Set2(const WCHAR* pname, int dx, int dy, Canimation* ani, CImagefile* img, TDrawType dt, UINT color);

	void ChageAnimation(std::wstring& name);
	void Update(int dt);
};

