#pragma once
#include "Object.h"
class OLogo :
    public Object
{

public:
    
    void Update();
    void Render(HDC hdc);
};

