#pragma once

#include "CTileMap.h"

class TILE_TEST
{
public:

	CTileUnit* tunit = nullptr;
	bool isMove = true;
	int EventTrigger = 0;
	//나중에 false로 고치고 하나씩 편집기에서 수정할것

public:
	
	TILE_TEST() :tunit(nullptr), isMove(true), EventTrigger(0) {}
	TILE_TEST(CTileUnit* Unit) :tunit(Unit), isMove(true), EventTrigger(0) {}
	TILE_TEST(CTileUnit* Unit, bool ismove) :tunit(Unit), isMove(ismove), EventTrigger(0) {}
	TILE_TEST(CTileUnit* Unit, bool ismove, int KindOfEvent) :tunit(Unit), isMove(ismove), EventTrigger(KindOfEvent) {}

	~TILE_TEST();




};

