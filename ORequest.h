#pragma once
#include "Object.h"

class Quest;

class ORequest :
    public Object
{
public:
    void Update();
    void Render(HDC hdc);

    virtual void OnPicking() override;

    bool test = false;

    virtual void OnCollisionEnter(Collider* _pOther);
    virtual void OnCollisionExit(Collider* _pOther);

    void setName(wstring _name) { name = _name; };

    void SetIsVisivle(int32 visivle) { isVisivle = visivle; }


public:
    ORequest();
    ~ORequest();

private:
    Vec2 m_vDragStart;      // 드래그 시작점

protected:
    unordered_map<wstring, Quest>  questMap;

public:
    int32 isVisivle = 255;
    wstring name = L"Hello";

    int32 temp = 0;

    Vec2 _mousePos;
    bool _hoverCheck = false;

    wstring _script1;
    wstring _script2;
    wstring _script3;
};

