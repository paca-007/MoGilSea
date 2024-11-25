#pragma once
#include "Object.h"
class ONPCEnding :
    public Object
{
public:
	void Update();
	void Render(HDC hdc);

public:
	EndingSceenType endType;
	HBITMAP endingBitMap;
	int alphaValue = 0;
};

