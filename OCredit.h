#pragma once
#include "Object.h"
class OCredit :
    public Object
{

public:
	void Update();
	void Render(HDC hdc);

public:
	int32 alphaValue = 255;

};

