#pragma once
#include "Object.h"
class OEndingPhoto :
    public Object
{

public:

	void Update();
	void Render(HDC hdc);

public:
	EndingSceenType endType;
	HBITMAP endingBitMap;

};

