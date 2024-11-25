#pragma once
#include "Object.h"
class OIDCard :
    public Object
{
private:
    Vec2 m_vDragStart;      // 드래그 시작점
    

public:
    void Update();
    void Render(HDC hdc);
    
    virtual void OnPicking() override;

    Vec2 _mousePos;
    bool _hoverCheck = false;

    int32 isVisivle = 255;

    int32 GetIsVisivle() { return isVisivle; }

    int32 temp = 0;


public:
    OIDCard();
    ~OIDCard();
};

