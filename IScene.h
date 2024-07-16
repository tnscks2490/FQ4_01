#pragma once
#include "Csprite.h"
#include "KeyInput.h"

class IScene
{
public:

    virtual bool IsFinished() = 0;
    virtual void onFrameMove() = 0;
    virtual void onDraw(HDC hdc) = 0;

    virtual void onMouseDown(UINT x, UINT y, UINT left_right) {}
    virtual void onMouseMove(UINT x, UINT y) {}
    virtual void onKeyDown(KeyInput* virtual_key) {}



    // virtual::CScene를 상속받는 모든 자식 클래스는 두개의 함수를 보유해야하며
    // CScene는 구현안하겠다. (=0;)
};
// 자기 자신은 아무것도 안하고 아래 자식클래스에게 무엇을 구현해야하는지 알려주기만 하는것을 추상 클래스라 한다.

// 추상클래스 or 인터페이스 클래스
