#pragma once
#include "Object.h"
class OBargainBtn :
    public Object
{

public:

	void Update();
	void Render(HDC hdc);

	/*void SetIsClicked(bool state) { _isClicked = state; }
	bool GetIsClicked() { return _isClicked; }
	bool _isClicked = false;*/

protected:
	Vec2 _mousePos{};
	bool _hoverCheck;

	float _buttonX = 1520;
	float _hoverX = 1520;

	int32 _bargainNumber = 0;

public:
	bool buttonStatus;
};

