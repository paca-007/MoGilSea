#pragma once
#include "Object.h"

class Adventurer;

class OCharacter : public Object
{
public :

	void Update();
	void Render(HDC hdc);
	

protected:
	bool _adventurerOn = false;
	bool _adventurerOff = false;

public:
	int alphaValue;
};

