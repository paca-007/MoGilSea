#pragma once
#include "Object.h"

class Quest;

class ORequest_2 :
    public Object
{

public:
    void Update();
    void Render(HDC hdc);

    bool test = false;

    virtual void OnCollisionEnter(Collider* _pOther);
    virtual void OnCollisionExit(Collider* _pOther);

    void setName(wstring _name) { name = _name; };


public:
    ORequest_2();
    ~ORequest_2();

private:
    Vec2 m_vDragStart;      // 드래그 시작점

protected:
    unordered_map<wstring, Quest>  questMap;

public:
    uint32 isVisivle = 255;
    wstring name = L"Hello";

    Vec2 _mousePos;
    bool _hoverCheck = false;
};

