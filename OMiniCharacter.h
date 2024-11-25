#pragma once
#include "Object.h"
class OMiniCharacter :
    public Object
{

public:

	void Update();
	void Render(HDC hdc);


public:
	int alphaValue;
	int x;
	int y;
};

