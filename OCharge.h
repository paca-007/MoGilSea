#pragma once
#include "Object.h"
class OCharge :
    public Object
{

public:
	void Update();
	void Render(HDC hdc);

protected:
	int32 fee = 0;
	wstring printWord{};
};

