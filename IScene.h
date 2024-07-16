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



    // virtual::CScene�� ��ӹ޴� ��� �ڽ� Ŭ������ �ΰ��� �Լ��� �����ؾ��ϸ�
    // CScene�� �������ϰڴ�. (=0;)
};
// �ڱ� �ڽ��� �ƹ��͵� ���ϰ� �Ʒ� �ڽ�Ŭ�������� ������ �����ؾ��ϴ��� �˷��ֱ⸸ �ϴ°��� �߻� Ŭ������ �Ѵ�.

// �߻�Ŭ���� or �������̽� Ŭ����
