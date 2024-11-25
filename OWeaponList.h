#pragma once
#include "Object.h"

class OWeaponList :
	public Object
{
public:
	void Update();
	void Render(HDC hdc);

	virtual void OnPicking() override;

	void setName(wstring _name) { name = _name; };


public:
	OWeaponList();
	~OWeaponList();

private:
	Vec2 m_vDragStart;      // 드래그 시작점

protected:
	//unordered_map<wstring, Quest>  questMap;

public:
	int32 isVisivle = 255;
	wstring name = L"Hello";

	int32 GetIsVisivle() { return isVisivle; }
	void SetIsVisivle(int32 _isVisivle) { isVisivle = _isVisivle; }

	int32 temp = 0;

	Vec2 _mousePos;
	bool _hoverCheck = false;

	CharacterName characterName;

	wstring _script1;
	wstring _script2;
	wstring _script3;
	wstring _script4;
	wstring _script5;
	wstring _script6;
	wstring _script7;
	wstring _script8;
	wstring _script9;
	wstring _script10;
	wstring _script11;
	wstring _script12;
};

