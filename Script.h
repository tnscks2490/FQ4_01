#pragma once
#include "resource.h"
struct ScriptZip
{
	WCHAR script [5][30];
	int scriptchar;
};


class Script
{
public:

	Script(std::wstring Scene);
	~Script();
	ScriptZip T;
	std::vector<ScriptZip> ScriptV;
};
const WCHAR Empty[30] = L"";
const WCHAR BarsiaText1[17][5][30]
{
	{
		{L"바르시아왕 제넬루 : 여러분! 난 로그리"},
		{L"스의 대표로서 이제껏 많은 어려움을"  },
		{L"극복해 왔소."},
		{L""},
		{L"Char_FRS"}
	},
	{
		{L"허나, 요즘 내 우정을 배신하는 자가"},
		{L"나타났소. 그래도 나의 군대는 여러분의" },
		{L"나라를 반드시 지킬 것이오"},
		{L""},
		{L"Char_FRS"}
	},
	{
		{L"베닉크왕 케크 : 마음도 넓으시군요! 그"},
		{L"런데 남쪽과 주변 촌놈들은 무슨 생각" },
		{L"을 하고 있는지 알 수가 없소"},
		{L""},
		{L"Char_FRS"}
	},
	{
		{L"마시아왕 가비 : 만약 남쪽 녀석들이 이"},
		{L"마시아를 쳐들어 온다면 나와 루아스가"},
		{L"가만 두지는 않을것이오!"},
		{L""},
		{L"Char_FSDS"}
	},
	{
		{L"노호크왕 오라슨 : 마시아의 좌우는 배닉"},
		{L"크성과 노호크성이 단단히 지키고 있으"},
		{L"니 안심하시오"},
		{L""},
		{L"Char_FSDS"}
	},
	{
		{L"리스레이왕 라이오스 : 마시아의 뒤에는"},
		{L"우리 리스레이성과 벨더의 세 성이 있"},
		{L"소. 감히 바르시아까지 올 군대는 없소"},
		{L"."},
		{L"Char_FSDS"}
	},
	{
		{L"알카나야왕 미솔렌 : 제넬루님의 마법으로"},
		{L"드래곤과 강력한 글리펀조종사 부대는"},
		{L"내 손 안에 있소."},
		{L""},
		{L"Char_FSDS"}
	},
	{
		{L"에드윈왕 마레암 : 왕이여! 바위인간의"},
		{L"힘이 아니라도 바르시아는 무사하리라"},
		{L"생각하오만···."},
		{L""},
		{L"Char_FSDS"}
	},
	{
		{L"제넬루 : 시끄럽소 ! 전쟁으로 귀중한 생"},
		{L"명이 죽는 것이 안타까와 자닐의 힘을"},
		{L"빌어 바위인간을 만든 것이오."},
		{L""},
		{L"Char_ST"}
	},
	{
		{L"당신들마저도 배신할 생각이오?"},
		{L""},
		{L""},
		{L""},
		{L"Char_ST"}
	},
	{
		{L"세버트왕 사크 : 에드윈은 남쪽영향을 받"},
		{L"기 쉽소. 바르시아왕이여 ! 힘이 될만한"},
		{L"자를 에드윈에 보내는 것이 좋겠소."},
		{L""},
		{L"Char_FSDS"}
	},
	{
		{L"바람장군 스리후트 : 그렇다면 내가 가겠"},
		{L"소!"},
		{L""},
		{L""},
		{L"Char_FRS"}
	},
	{
		{L"흙의 장군 맥가이어 : 라이오스님이 허락"},
		{L"하신다면 난 리스레이섬에 있겠소."},
		{L""},
		{L""},
		{L"Char_F"}
	},
	{
		{L"제넬루 : 다 알고 있겠지만 내가 신뢰하"},
		{L"는 부하요. 힘이 되게 해 주시오."},
		{L""},
		{L""},
		{L"Char_FRS"}
	},
	{
		{L"지난날 불행히도 모르시왕과 벨더왕이"},
		{L"잇달아 죽었소. 참혹한 일이오. 후계자가"},
		{L"결정될 때까지 오그와 몰드레드가 지키"},
		{L"게 하시오."},
		{L"Char_FRS"}
	},
	{
		{L"물장군 오그 : 그럼, 저는 모르시아로...."},
		{L""},
		{L""},
		{L""},
		{L"Char_FRS"}
	},
	{
		{L"불장군 몰드레드 : 벨더성은 내게 맡기시"},
		{L"오."},
		{L""},
		{L""},
		{L"Char_FRS"}
	}
};

const int BarsiaChar1[17]
{
	IDB_GENELU,
	IDB_GENELU,
	IDB_KECK,
	IDB_GABI,
	IDB_ORASON,
	IDB_LAIOS,
	IDB_MYSOLEN,
	IDB_MAREAM,
	IDB_GENELU,
	IDB_GENELU,
	IDB_SARK,
	IDB_THYHOOT,
	IDB_MACGAIA,
	IDB_GENELU,
	IDB_GENELU,
	IDB_OGG,
	IDB_MOLDRED
};

const WCHAR KarionText1[11][5][30]
{
	{
		{L"아레스 : 여러분! 나는 지금부터 바르시"},
		{L"아왕 제넬루를 암살하기 위해 떠날 생각"},
		{L"이오."},
		{L""},
		{L"Char_FSUS"}
	},
	{
		{L"에크터 : 그런 일이라면 나한테 맡기시오"},
		{L"! 그는 마법으로 강한 군대를 조직했"},
		{L"소. 이제 곧 로그리스를 멸망시키고 말"},
		{L"것이오."},
		{L"Char_F"}
	},
	{
		{L"곤라트 : 그렇소! 제넬루는 우리에게 맡기"},
		{L"시오!"},
		{L""},
		{L""},
		{L"Char_FSUS"}
	},
	{
		{L"아레스 : 모르는 소리 ! 제넬루에게는 강"},
		{L"한 호위대가 있소. 나는 그를 직접 만날"},
		{L"수 있으니 없앨 기회가 있을 것이오."},
		{L""},
		{L"Char_FSUS"}
	},
	{
		{L"곤라트 : 정  그러시다면 호위병과 함께..."},
		{L""},
		{L""},
		{L""},
		{L"Char_FSUS"}
	},
	{
		{L"아레스 : 그럴 필요없소 ! 애크터, 국경을"},
		{L"맡아 주시오. 곤라트는 나에게 만약 일"},
		{L"이 생기면 뒤를 맡아 주시오."},
		{L""},
		{L"Char_FSUS"}
	},
	{
		{L"곤라트 : 왕에게 일이 생기면 뒤를 따르는"},
		{L"것은 신하된 도리. 염려마시고 바르시아를"},
		{L"빨리 무찔러 주십시오."},
		{L""},
		{L"Char_FSUS"}
	},
	{
		{L"아레스 : 서둘지 마시오! 우리에겐 아직"},
		{L"힘이 없소. 그러나 나는 반드시 살아서"},
		{L"돌아올 것이오. 그떄까지 잘 부탁하오."},
		{L""},
		{L"Char_FSUS"},
	},
	{
		{L"대주교 : 신의 가호가 있기를..."},
		{L""},
		{L""},
		{L""},
		{L"Char_F"},
	},
	{
		{L"애레인 : 기다려요! 같이 가요!"},
		{L""},
		{L""},
		{L""},
		{L"Char_FSUS"},
	},
	{
		{L"아레스 : 너는 오히려 방해가 될 뿐이야,"},
		{L"애레인. 더 걱정되거든. 무슨 뜻인지"},
		{L"알겠지?"},
		{L""},
		{L"Char_FSUS"},
	}
};

const int KarionChar1[11]
{
	IDB_ARES,
	IDB_AEKTER,
	IDB_GONRAD,
	IDB_ARES,
	IDB_GONRAD,
	IDB_ARES,
	IDB_GONRAD,
	IDB_ARES,
	IDB_ARCHBISHOP,
	IDB_AERAIN,
	IDB_ARES
};

const WCHAR BarsiaText2[8][5][30]
{
	{
		{L"아레스 : ㆍㆍㆍ그러므로 바르시아의 "},
		{L"왕이여! 신의 섭리에 따라 당신이 만든 "},
		{L"병사들을 가능한 빨리 처분하여 주기 "},
		{L"바라오."},
		{L"Char_FSUS"},
	},
	{
		{L"제넬루 : 카리온의 생각은 이미 알고 있"},
		{L"다. 그러나 나의 병사는 나의 아들과"},
		{L"마찬가지. 처분할 수는 없다. 필요하다면"},
		{L"나누어 주지."},
		{L"Char_FLS"},
	},
	{
		{L"닥치시오! 당신이 만든 악마때문에 백성"},
		{L"들도 고통받고 있소! 사람들을 몰아내고"},
		{L"로그리스를 당신의 쓰레기로 채울"},
		{L"생각이오!"},
		{L"Char_FSUS"},
	},
	{
		{L"으악! 모, 몸이ㆍㆍㆍ? !"},
		{L""},
		{L""},
		{L""},
		{L"Char_FSUS"},
	},
	{
		{L"제넬루 : 멍청한 놈! 네 머리속 쯤은"},
		{L"다 꾀뚫어 보고 있다. 미리 경계하고"},
		{L"있었지. 헤헤헤!"},
		{L""},
		{L"Char_FLS"},
	},
	{
		{L"감옥에서 천천히 머리나 식히시지. 그"},
		{L"후에 처벌하마"},
		{L""},
		{L""},
		{L"Char_FLS"},
	},
	{
		{L"제넬루 : 지금 즉시 카리온으로 출동하라"},
		{L"! 아레스가 없는 한 카리온은 문제없"},
		{L"다!!"},
		{L""},
		{L"Char_FLS"},
	},
	{
		{L"장군 : 예잇!"},
		{L""},
		{L""},
		{L""},
		{L"Char_FSUS"},
	},

};

const int BarsiaChar2[8]
{
	IDB_ARES,
	IDB_GENELU,
	IDB_ARES,
	IDB_ARES,
	IDB_GENELU,
	IDB_GENELU,
	IDB_GENELU,
	IDB_GENERAL
};

const WCHAR FieldText[3][5][30]
{
	{
		{L"적장 : 포기해라! 너의 아레스는 우리"},
		{L"군대에게 잡혔다. 덤빌수록 그 녀석의 "},
		{L"목숨만 짧아 질 뿐이다!"},
		{L""},
		{L"Char_F"}
	},
	{
		{L"애크터 : 윽! 후퇴하라! 그러나 난 물"},
		{L"러서지 않는다! 여기서 죽어도 후회는"},
		{L"없다!"},
		{L""},
		{L"Char_F"}
	},
	{
		{L"병사 : 우리도 싸우자!!"},
		{L""},
		{L""},
		{L""},
		{L"Char_F"}
	}
};

const int FieldChar[3]
{
	IDB_HORSE_GENERAL,
	IDB_HORSE_AEKTER,
	IDB_SOLDIER5,
};

const WCHAR KarionText2[7][5][30]
{
	{
		{L"애레인 : 곤라트, 난 지금부터 왕을 구"},
		{L"하러 가겠어요. 뒤를 부탁해요."},
		{L""},
		{L""},
		{L"Char_FSUS"}
	},
	{
		{L"곤라트 : 왕의 명령을 거역할 생각이오?"},
		{L"왕은 반드시 돌아 온다고 하지 않았소?"},
		{L""},
		{L""},
		{L"Char_FSUS"}
	},
	{
		{L"애레인 : 그럼 가만히 보고만 있으란 말"},
		{L"이예요? 이 성은 당신들이 지키겠죠."},
		{L"하지만 왕을 구하러 갈 사람은 나밖에"},
		{L"없어요"},
		{L"Char_FSUS"}
	},
	{
		{L"곤라트 : ...음, 당신이 강하다는 것은 알"},
		{L"고 있소. ...좋소! 그 대신 특수부대의"},
		{L"호위를 받으시오."},
		{L""},
		{L"Char_FSUS"}
	},
	{
		{L"애레인 : 그럴 필요 없어요. 혼자가 편해"},
		{L"요."},
		{L""},
		{L""},
		{L"Char_FSUS"}
	},
	{
		{L"곤라트 : 왕과 똑같은 말을 하는군. 하"},
		{L"지만 호위하도록 해야겠소. 환영부대, 출"},
		{L"동하라!"},
		{L""},
		{L"Char_FSUS"}
	},
	{
		{L"애레인 : 어머! 까마귀들이군요. 좋아요"},
		{L". 곧 가겠어요."},
		{L""},
		{L""},
		{L"Char_FSUS"}
	},
};

const int KarionChar2[7]
{
	IDB_AERAIN,
	IDB_GONRAD,
	IDB_AERAIN,
	IDB_GONRAD,
	IDB_AERAIN,
	IDB_GONRAD,
	IDB_AERAIN
};

const WCHAR BarsiaText3[13][5][30]
{
	{
		{L"간수 : 멈춰라! 웬 놈이냐?"},
		{L""},
		{L""},
		{L""},
		{L"Char_FSDS"}
	},
	{
		{L"사나이 : 글쎄요~, 난 누구일까? 저"},
		{L"안에 있는 사람에게 볼일이 있는데 열"},
		{L"어 줄 수 없을까?"},
		{L""},
		{L"Char_FRS"}
	},
	{
		{L"뭣이라고! 모두 이 녀석을 잡아라!"},
		{L""},
		{L""},
		{L""},
		{L"Char_FSDS"}
	},
	{
		{L"사나이 : 이크! 귀찮은 녀석들이군! 에"},
		{L"잇! 쥐새끼로나 변해라!"},
		{L""},
		{L""},
		{L"Char_FRS"}
	},
	{
		{L"사나이 : 아레스...! 음, 꽤 심하게 다쳤"},
		{L"군. 어때? 약효가 좀 있는 것 같은"},
		{L"가?"},
		{L""},
		{L"Char_FRS"}
	},
	{
		{L"아레스 : ......으, 윽!"},
		{L""},
		{L""},
		{L""},
		{L"Char_FDUS"}
	},
	{
		{L"아레스 : 앗! 이럴 수가! 고통이 사라"},
		{L"졌다! 다,당신은? 시술가요?"},
		{L""},
		{L""},
		{L"Char_FSDS"}
	},
	{
		{L"사나이 : 아니, 신경을 좀 마비시켰을 뿐"},
		{L"이야. 일어나지 않으면 곤란하거든"},
		{L""},
		{L""},
		{L"Char_FRS"}
	},
	{
		{L"아레스 : 앗! 저것은!?"},
		{L""},
		{L""},
		{L""},
		{L"Char_FSDS"}
	},
	{
		{L"사나이 : 바르시아 군대의 글리펀조종사야"},
		{L". 자 너에게 이 약을 줄께. 동물을"},
		{L"마음대로 조종하는 약이지. 나쁜데 쓰면"},
		{L"안돼!"},
		{L"Char_FRS"}
	},
	{
		{L"감옥을 나가면 그 녀석들이 자고 있을"},
		{L"거야. 그걸 써서 글리펀을 타고 카리온"},
		{L"성에 돌아가."},
		{L""},
		{L"Char_FRS"}
	},
	{
		{L"아레스 : 당신은 우리편이오?"},
		{L""},
		{L""},
		{L""},
		{L"Char_FSDS"}
	},
	{
		{L"사나이 : 맘대로 생각해. 자, 어서 마법이"},
		{L"풀리기 전에  빨리 가!"},
		{L""},
		{L""},
		{L"Char_FRS"}
	}
};

const int BarsiaChar3[13]
{
	IDB_SOLDIER2,
	IDB_GARRARD,
	IDB_SOLDIER2,
	IDB_GARRARD,
	IDB_GARRARD,
	IDB_ARES,
	IDB_ARES,
	IDB_GARRARD,
	IDB_ARES,
	IDB_GARRARD,
	IDB_GARRARD,
	IDB_ARES,
	IDB_GARRARD,
};


const WCHAR KarionText3[26][5][30]
{
	{
		{L"곤라트 : 아니! 아레스왕! 무사하셨군요"},
		{L"!!"},
		{L""},
		{L""},
		{L"Char_F"}
	},
	{
		{L"아레스 : 약속했잖소. 꼭 돌아온다고...."},
		{L""},
		{L""},
		{L""},
		{L"Char_FSDS"}
	},
	{
		{L"곤라트 : 어떻게 적의 성을...?"},
		{L""},
		{L""},
		{L""},
		{L"Char_FSDS"}
	},
	{
		{L"아레스 : 마법을 쓰는 사내의 도움으로"},
		{L"탈출했으나, 오는 도중에 통증이 와 몇"},
		{L"번이나 정신을 잃었었소."},
		{L""},
		{L"Char_FSDS"}
	},
	{
		{L"그 사내를 다시 만나면 사례해야겠소."},
		{L"아참! 바르시아군의 상황은 어떻소?"},
		{L""},
		{L""},
		{L"Char_FSDS"}
	},
	{
		{L"곤라트 : 면목없소. 바르시아군은 마시아"},
		{L"부근에 큰 세력을 펼치고, 강력한 군대"},
		{L"로 우리 영토의 대부분을...."},
		{L""},
		{L"Char_FSDS"}
	},
	{
		{L"아레스 : 음..., 모두 무사하다면 영토는"},
		{L"찾을 수 있을 것이오."},
		{L""},
		{L""},
		{L"Char_FSDS"}
	},
	{
		{L"곤라트 : 그게..., 유감스럽게도 주요인물"},
		{L"들이 전쟁터에서 돌아오지 않아...."},
		{L""},
		{L""},
		{L"Char_FSDS"}
	},
	{
		{L"곤라트 : 지혜자 라모크도 전쟁터에서"},
		{L"행방불명이 되었소."},
		{L""},
		{L""},
		{L"Char_Kneel"}
	},
	{
		{L"아레스 : 뭣이! 모두 생사를 알 수 없"},
		{L"단 말이오? 애레인은?"},
		{L""},
		{L""},
		{L"Char_F"}
	},
	{
		{L"곤라트 : 그녀는 왕을 구하러 나갔소. 환"},
		{L"영부대가 호위하도록 했으니 무사하리라"},
		{L"생각하오."},
		{L""},
		{L"Char_FSDS"}
	},
	{
		{L"아레스 : 내 명을 어기고 성을 나간 자를"},
		{L"호위할것 까지야 없지. 어쨌든 좋소"},
		{L"이제 앞으로의 일을 생각해야 겠소."},
		{L"우선 제군에게 편지를 씁시다."},
		{L"Char_FSDS"}
	},
	{
		{L"곤라트 : 잠깐만! 가이아에서 원군이 와"},
		{L"있으니 한번 만나 보시오."},
		{L""},
		{L""},
		{L"Char_F"}
	},
	{
		{L"아레스 : 그래? 혹시 키프트가 아니오!?"},
		{L""},
		{L""},
		{L""},
		{L"Char_F"}
	},
	{
		{L"라딘칼 : 아레스님. 무사하니 다행이오."},
		{L"급하다는 소식을 듣고 무조건 달려왔소."},
		{L"트리스렌도 곧 뒤따라 올 것이오."},
		{L""},
		{L"Char_F"}
	},
	{
		{L"나의 아들 키프트도 함께 왔으나 어느"},
		{L"틈엔가 이 녀석이 사라져 버렸소. 여"},
		{L"느 때처럼 어딘가에 쳐 박혀 자고 있"},
		{L"을거요."},
		{L"Char_FSUS"}
	},
	{
		{L"아레스 : 라딘칼님, 당신이 와 주신것만으"},
		{L"로도 충분하오! 저기 계신분은?"},
		{L""},
		{L""},
		{L"Char_FSDS"}
	},
	{
		{L"라딘칼 : 가이아여왕 아이라의 셋째아들"},
		{L"얀후레트요. 실은 이번 싸움이 옛날 가"},
		{L"이아전투와 관계있는 것 같소."},
		{L""},
		{L"Char_FSDS"}
	},
	{
		{L"자세한 것은 그 분에게 들어주시오."},
		{L""},
		{L""},
		{L""},
		{L"Char_FSDS"}
	},
	{
		{L"얀후레트 : 처음 뵙겠습니다. 어려서부터"},
		{L"카디라에서 공부하느라 여태 찾아 뵙지"},
		{L"못했습니다. 어머님께서도 평안하십니다."},
		{L""},
		{L"Char_F"}
	},
	{
		{L"얀후레트 : 옛날, 가이아대륙에는 악마 가"},
		{L"로아와 사람들과의 싸움이 있었습니다."},
		{L""},
		{L""},
		{L"Char_FSDS"}
	},
	{
		{L"그 후, 가로아의 출생을 알아 내려고"},
		{L"많은 신들이 별세계로 떠났으나 가로아"},
		{L"는 사라지지 않은 것 같습니다."},
		{L""},
		{L"Char_FSDS"}
	},
	{
		{L"얀후레트 : 시술가들은 가로아의 혼이 로"},
		{L"그리스로 옮겨졌다고 합니다. 필시 그것"},
		{L"이 제넬루에게 큰 힘을 주었을 것입니"},
		{L"다."},
		{L"Char_FSDS"}
	},
	{
		{L"가로아를 완전히 없앨 방법은 없지만,"},
		{L"우선 제넬루를 쓰러뜨려야 합니다."},
		{L""},
		{L""},
		{L"Char_F"}
	},
	{
		{L"곤라트 : 그렇소! 적군은 마을 근처까지"},
		{L"와 있는 것 같소. 방금 리오스마을로부터"},
		{L"도움을 청하는 사자가 왔소."},
		{L""},
		{L"Char_FSDS"}
	},
	{
		{L"아레스 : 우선 잃은 땅을 찾아야 하오."},
		{L"자-! 출동하라!!"},
		{L""},
		{L""},
		{L"Char_FSDS"}
	},
};

const int KarionChar3[26]
{
	IDB_GONRAD,
	IDB_ARES,
	IDB_GONRAD,
	IDB_ARES,
	IDB_ARES,
	IDB_GONRAD,
	IDB_ARES,
	IDB_GONRAD,
	IDB_GONRAD,
	IDB_ARES,
	IDB_GONRAD,
	IDB_ARES,
	IDB_GONRAD,
	IDB_ARES,
	IDB_RADINKAL,
	IDB_RADINKAL,
	IDB_ARES,
	IDB_RADINKAL,
	IDB_RADINKAL,
	IDB_ALFRED,
	IDB_ALFRED,
	IDB_ALFRED,
	IDB_ALFRED,
	IDB_ALFRED,
	IDB_GONRAD,
	IDB_ARES,
};