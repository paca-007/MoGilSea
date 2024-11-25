#pragma once
#include "Object.h"
class OOpeningScript :
    public Object
{

public:
	void Update();
	void Render(HDC hdc);

public:
	OpeningSceneType openingType;
	int32 scriptNum = 0;
	HBITMAP openingScriptBitMap;
};

