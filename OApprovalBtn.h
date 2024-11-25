#pragma once
#include "Object.h"
class OApprovalBtn :
    public Object
{

public:

	void Update();
	void Render(HDC hdc);

public:
	OApprovalBtn();
	~OApprovalBtn();

	/*void SetIsClicked(bool state) { _isClicked = state; }
	bool GetIsClicked() { return _isClicked; }
	bool _isClicked = false;*/

protected:
	Vec2 _mousePos;
	bool _hoverCheck = false;

	float _buttonX = 1520;
	float _hoverX = 1520;

public:
	bool buttonStatus;
};

