#pragma once
#include "Object.h"
class OOpeningPhoto :
    public Object
{

public:

	void Update();
	void Render(HDC hdc);

public:
	OpeningSceneType openingType;
	HBITMAP openingBitMap;


};

