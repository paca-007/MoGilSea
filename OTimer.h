#pragma once
#include "Object.h"
class OTimer :
    public Object
{

public:
	void Update();
	void Render(HDC hdc);

	float Timer(float deltaTime, float tWidth);

protected:
	float timerTime;
	float sec = 30;
	float width = 1150;
};

