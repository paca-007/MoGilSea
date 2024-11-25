#include "pch.h"
#include "Object.h"
#include "ObjectManager.h"
#include "Collider.h"

Object::Object()
	: m_pCollider(nullptr)
	, m_bAlive(true)
	, m_depth(10000)
{
}

Object::~Object()
{
	if (nullptr != m_pCollider)
		delete m_pCollider;
}

void Object::Init()
{

}

void Object::Update()
{
	//GET_SINGLE(ObjectManager)->ChangePlayEvent();
}

void Object::FinalUpdate()
{
	if (m_pCollider)		// 충돌체 보유 여부 확인
		m_pCollider->FinalUpdate();
}

void Object::Render(HDC hdc)
{

}

void Object::ComponentRender(HDC _dc)
{
	if (nullptr != m_pCollider)
	{
		m_pCollider->Render(_dc);
	}
}

void Object::CreateCollider()
{
	m_pCollider = new Collider;
	m_pCollider->m_pOwner = this;
}
