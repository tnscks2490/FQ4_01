#include "pch.h"
#include "DELAY.h"
#include "time.h"

DELAY::DELAY()
{
	St = time(NULL);
	Et = time(NULL);
}

DELAY::~DELAY()
{
}

void DELAY::Do(int delaytime)
{
	OutputDebugStringW(L"5�� �������ϴ�");
}
