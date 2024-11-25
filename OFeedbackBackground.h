#pragma once
#include "Object.h"
class OFeedbackBackground :
    public Object
{
public:

    void Update();
    void Render(HDC hdc);

public:
    FeedbackSceneType _feedbackType;
};

