#pragma once

#include "CTileMap.h"

class TILE_TEST
{
public:

	CTileUnit* tunit = nullptr;
	bool isMove = true;
	int EventTrigger = 0;
	//���߿� false�� ��ġ�� �ϳ��� �����⿡�� �����Ұ�

public:
	
	TILE_TEST() :tunit(nullptr), isMove(true), EventTrigger(0) {}
	TILE_TEST(CTileUnit* Unit) :tunit(Unit), isMove(true), EventTrigger(0) {}
	TILE_TEST(CTileUnit* Unit, bool ismove) :tunit(Unit), isMove(ismove), EventTrigger(0) {}
	TILE_TEST(CTileUnit* Unit, bool ismove, int KindOfEvent) :tunit(Unit), isMove(ismove), EventTrigger(KindOfEvent) {}

	~TILE_TEST();




};

