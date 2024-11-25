#pragma once
#include "Object.h"
#include "ResourceManager.h"

class OFeedbackScript :
    public Object
{
public:
    void Update();
    void Render(HDC hdc);

public:
    wstring _script;
    int32 x;
    int32 y;
    int32 x_width;
    int32 y_width;
};

