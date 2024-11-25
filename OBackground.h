#pragma once
#include "Object.h"
class OBackground : public Object
{
public:
    OBackground();

    void Update();
	void Render(HDC hdc);

};

