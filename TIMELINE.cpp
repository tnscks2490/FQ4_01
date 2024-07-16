#include "pch.h"
#include "TIMELINE.h"

TIMELINE::TIMELINE(int x)
{
	index = 0;
	for (int i = 0; i < x; i++)
		Textline.push_back(false);
}

TIMELINE::~TIMELINE()
{
}
