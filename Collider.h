#pragma once

class Object;

class Collider
{
private:
	static UINT g_iNextID;

	Object*		m_pOwner;		// collider 를 소유하고 있는 오브젝트
	Vec2		m_vOffSetPos;	// 오브젝트로 부터의 상대적인 위치 //오브젝트 기준 콜라이더 위치 조정시 사용하는 변수
	Vec2		m_vFinalPos;	// 충돌체(콜라이더)의 최종 위치 // FinalUpdate 에서 매 프레임마다 계산
	Vec2		m_vScale;		// 충돌체(콜라이더)의 크기

	UINT		m_iID;			// 충돌체 고유한 ID 값
	int			m_iCol;			// 충돌 여부 저장

public:
	void SetOffsetPos(Vec2 _vPos) { m_vOffSetPos = _vPos; }
	void SetScale(Vec2 _scale) { m_vScale = _scale; }

	Vec2 GetOffsetPos() { return m_vOffSetPos; }
	Vec2 GetScale() { return m_vScale; }

	Vec2 GetFinalPos() { return m_vFinalPos; }

	Object* GetObj() { return m_pOwner; }

	UINT GetID() { return m_iID; }

public:
	void FinalUpdate();
	void Render(HDC _dc);

public:
	// 충돌 시점 함수
	void OnCollision(Collider* _pOther);	// 충돌 중인 경우 호출되는 함수
	void OnCollisionEnter(Collider* _pToehr);	// 충돌 진입 시
	void OnCollisionExit(Collider* _pOther);	// 충돌 해제 시


	Collider& operator = (Collider& _origin) = delete;

public:
	Collider();
	Collider(const Collider& _origin);
	~Collider();

	friend class Object;
};
