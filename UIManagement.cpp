#include "pch.h"
#include "UIManagement.h"

UIManagement::UIManagement()
{
	hFont = CreateFontW(18, 0, 0, 0, 0, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT("�ü�"));
}

UIManagement::~UIManagement()
{
}

//bool UIManagement::Is���콺�����ȿ�(int mouse_x, int mouse_y)
//{
//	if (GetPosX() <= mouse_x and mouse_x <= GetPosX() + Size_x
//		and GetPosY() <= mouse_y and mouse_y <= GetPosY() + Size_y)
//	{
//		return true;
//	}
//	return false;
//}
