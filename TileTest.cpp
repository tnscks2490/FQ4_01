#include "pch.h"
#include "TileTest.h"
#include "CMap.h"

bool TileTest::IsFinished()
{
	return false;
}

void TileTest::onFrameMove()
{
}

void TileTest::onDraw(HDC hdc)
{
	cmap->Draw(hdc);
}

void TileTest::onMouseDown(UINT x, UINT y, UINT left_right)
{
}

void TileTest::onMouseMove(UINT x, UINT y)
{
}

void TileTest::onKeyDown(KeyInput* virtual_key)
{
}

TileTest::TileTest()
{
}

TileTest::~TileTest()
{
}
