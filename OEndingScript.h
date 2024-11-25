#pragma once
#include "Object.h"
class OEndingScript :
    public Object
{

	void Update();
	void Render(HDC hdc);

public:
	EndingSceenType endType;
	int32 scriptNum = 0;
	HBITMAP endingScriptBitMap;
};

