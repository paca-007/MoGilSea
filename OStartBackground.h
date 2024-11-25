#pragma once
#include "Object.h"
class OStartBackground :
    public Object
{

public:
	OStartBackground();

	void Update();
	void Render(HDC hdc);
};

