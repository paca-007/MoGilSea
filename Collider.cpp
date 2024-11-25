#include "pch.h"
#include "Collider.h"

#include "Object.h"
#include "GameCore.h"

#include "TimeManager.h"

#include "SelectGDI.h"

UINT Collider::g_iNextID = 0;

Collider::Collider()
	: m_pOwner(nullptr)
	, m_iID(g_iNextID++)
	, m_iCol(0)
{

}

Collider::Collider(const Collider& _origin)
	: m_pOwner(nullptr)
	, m_vOffSetPos(_origin.m_vOffSetPos)
	, m_vScale(_origin.m_vScale)
	, m_iID(g_iNextID++)
{





}

Collider::~Collider()
{
}

void Collider::FinalUpdate()
{
	//Object 의 위치를 따라간다.
	Vec2 objectPos = m_pOwner->GetPos();
	m_vFinalPos = objectPos + m_vOffSetPos;

	assert(0 <= m_iCol);
}

void Collider::Render(HDC _dc)
{
	SelectGDI p(_dc, PenType::GREEN);
	SelectGDI b(_dc, BrushType::HOLLOW);

	Rectangle(_dc
		, (int)(m_vFinalPos.x - m_vScale.x / 2.f)
		, (int)(m_vFinalPos.y - m_vScale.y / 2.f)
		, (int)(m_vFinalPos.x + m_vScale.x / 2.f)
		, (int)(m_vFinalPos.y + m_vScale.y / 2.f));

}



void Collider::OnCollision(Collider* _pOther)
{
	m_pOwner->OnCollision(_pOther);
}

void Collider::OnCollisionEnter(Collider* _pOther)
{
	OutputDebugString(TEXT("OnCollisionEnter"));
	OutputDebugString(TEXT("\n"));
	++m_iCol;
	m_pOwner->OnCollisionEnter(_pOther);
}

void Collider::OnCollisionExit(Collider* _pOther)
{
	OutputDebugString(TEXT("OnCollisionExit"));
	OutputDebugString(TEXT("\n"));
	--m_iCol;
	m_pOwner->OnCollisionExit(_pOther);
}
