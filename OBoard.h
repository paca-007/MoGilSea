#pragma once
#include "Object.h"
class OBoard :
    public Object
{
public:

	void Update();
	void Render(HDC hdc);
};

