#pragma once

//전방선언
class Object;

class Scene
{

protected:
	vector<Object*> arrObj[(int32)ObjectType::END];
	wstring         strName; //scene name	

public:
	void SetName(const wstring& _strName) { strName = _strName; }
	const wstring& GetName() { return strName; }

	virtual void Update();
	virtual void FinalUpdate();
	virtual void Render(HDC hdc);

	virtual void Start() = 0;
	virtual void Exit() = 0;

	void AddObject(Object* _pObj, ObjectType _eType)
	{
		arrObj[(int32)_eType].push_back(_pObj);
	}
	void DeleteGroup(ObjectType _eTarget);
	void DeleteAll();
	
	const vector<Object*>& GetGroupObject(ObjectType _eType) { return arrObj[(int32)_eType]; }

	Vec2 _mousePos;

public:
	Scene();
	virtual ~Scene();

};

