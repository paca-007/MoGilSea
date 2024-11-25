#pragma once
#include "Object.h"

class OTable : public Object
{
public:

	void Update();
	void Render(HDC hdc);

public:
	OTable();
	~OTable();
};

