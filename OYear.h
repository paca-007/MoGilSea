#pragma once
#include "Object.h"
class OYear :
    public Object
{

public:
	void Update();
	void Render(HDC hdc);

protected:
	int32 year;
	wstring printWord;
};

