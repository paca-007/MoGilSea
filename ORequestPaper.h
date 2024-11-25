#pragma once
#include "Object.h"
class ORequestPaper :
    public Object
{

public:
	void Update();
	void Render(HDC hdc);

public:
	ORequestPaper();
	~ORequestPaper();
};

