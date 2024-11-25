#include "pch.h"
#include "Scene.h"
#include "Object.h"

#include "InputManager.h"
#include "ResourceManager.h"


void Scene::Start()
{

}

void Scene::Exit()
{

}
bool compare(Object* a, Object* b)
{
	//if (a->GetObjectType() == ObjectType::SCRIPT) return b->GetDepth();
	//else if (b->GetObjectType() == ObjectType::SCRIPT) return a->GetDepth();
	return a->GetDepth() > b->GetDepth();
}

void Scene::Update()
{
	_mousePos = GET_SINGLE(InputManager)->GetMouseCursorPosition();

	for (int32 i = 0; i < (int32)ObjectType::END; i++)
	{
		// ī�װ����� �����ϴ� �迭���� ���� ī�װ��� ���͸� �����´�.
		std::vector<Object*>& _nowObject = arrObj[i];

		// �� ���͸� depth�� ���ؼ� �����Ѵ�.
		sort(_nowObject.begin(), _nowObject.end(), compare);

		for (size_t j = 0; j < _nowObject.size(); j++)
		{			
			_nowObject[j]->OnPicking();
			_nowObject[j]->Update();
		}
	}
}

void Scene::FinalUpdate()
{
	for (int32 i = 0; i < (int32)ObjectType::END; i++)
	{
		for (size_t j = 0; j < arrObj[i].size(); j++)
		{
			arrObj[i][j]->FinalUpdate();
		}
	}
}


void Scene::Render(HDC hdc)
{
	HBITMAP mouseCursor;


	for (int32 i = 0; i < (int32)ObjectType::END; i++)
	{
		// ī�װ����� �����ϴ� �迭���� ���� ī�װ��� ���͸� �����´�.
		std::vector<Object*> _nowObject = arrObj[i];



		for (size_t j = 0; j < _nowObject.size(); j++)
		{
			_nowObject[j]->Render(hdc);
		}
	}
	mouseCursor = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\main\\cursor.bmp");
	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, mouseCursor, (int)_mousePos.x, (int)_mousePos.y, 255);
}

void Scene::DeleteGroup(ObjectType _eTarget)
{

	for (size_t i = 0; i < arrObj[(int32)_eTarget].size(); i++)
	{
		delete arrObj[(int32)_eTarget][i];
	}
	arrObj[(int32)_eTarget].clear();

}

void Scene::DeleteAll()
{
	for (int32 i = 0; i < (int32)ObjectType::END; i++)
	{
		DeleteGroup((ObjectType)i);
	}
}

Scene::Scene()
{

}

Scene::~Scene()
{
	for (int32 i = 0; i < (int32)ObjectType::END; i++)
	{
		for (size_t j = 0; j < arrObj[i].size(); j++)
		{
			delete arrObj[i][j];
		}
	}
}
