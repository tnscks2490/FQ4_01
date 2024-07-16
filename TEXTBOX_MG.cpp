#include "pch.h"
#include "TEXTBOX_MG.h"

TEXTBOX_MG::TEXTBOX_MG()
{

	mTextChar = new TEXTCHAR;

	mTextChar->mCurrentChar = L"IDB_GENELU_LF";
}

TEXTBOX_MG::~TEXTBOX_MG()
{
	if (mTextChar->TextChar) CImagefile::Delete(mTextChar->TextChar);

	delete mTextChar;
}

void TEXTBOX_MG::TextCharDraw(HDC hdc, int index)
{
	mTextChar->textchar.Draw(hdc);
}
