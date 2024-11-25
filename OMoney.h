#pragma once
#include "Object.h"
class OMoney :
    public Object
{
public:

	void Update();
	void Render(HDC hdc);

protected:
	int32 money;
	wstring printWord;
};

