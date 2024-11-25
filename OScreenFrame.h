#pragma once
#include "Object.h"
class OScreenFrame :
    public Object
{

public:
    void Update();
    void Render(HDC hdc);
};

