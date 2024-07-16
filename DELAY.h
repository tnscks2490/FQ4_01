#pragma once

#include "time.h"


class DELAY
{
public:
	DELAY();
	~DELAY();
	time_t St;
	time_t Et;

	void Do(int delaytime);
};

