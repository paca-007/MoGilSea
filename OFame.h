#pragma once
#include "Object.h"
class OFame :
    public Object
{

public:
	void Update();
	void Render(HDC hdc);

protected:
	int32 fame;
	wstring printWord;
};

