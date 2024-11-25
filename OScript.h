#pragma once
#include "Object.h"
#include "ObjectManager.h"

class OScript : public Object
{
public:
	void Update();
	void Render(HDC hdc);

protected:
	int32 _speedCheck = 17;
	DWORD _displayTimer = 0;
	size_t _autoReturnCheck = 0;
	wstring _output = {};
	wstring _lastScript;
	PlayEventType _playEventState;

public:
	int alphaValue;
	wstring _script;
};

