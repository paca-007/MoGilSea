#pragma once

class Object;

class Collider
{
private:
	static UINT g_iNextID;

	Object*		m_pOwner;		// collider �� �����ϰ� �ִ� ������Ʈ
	Vec2		m_vOffSetPos;	// ������Ʈ�� ������ ������� ��ġ //������Ʈ ���� �ݶ��̴� ��ġ ������ ����ϴ� ����
	Vec2		m_vFinalPos;	// �浹ü(�ݶ��̴�)�� ���� ��ġ // FinalUpdate ���� �� �����Ӹ��� ���
	Vec2		m_vScale;		// �浹ü(�ݶ��̴�)�� ũ��

	UINT		m_iID;			// �浹ü ������ ID ��
	int			m_iCol;			// �浹 ���� ����

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
	// �浹 ���� �Լ�
	void OnCollision(Collider* _pOther);	// �浹 ���� ��� ȣ��Ǵ� �Լ�
	void OnCollisionEnter(Collider* _pToehr);	// �浹 ���� ��
	void OnCollisionExit(Collider* _pOther);	// �浹 ���� ��


	Collider& operator = (Collider& _origin) = delete;

public:
	Collider();
	Collider(const Collider& _origin);
	~Collider();

	friend class Object;
};
