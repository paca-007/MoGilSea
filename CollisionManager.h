#pragma once

class Collider;

union COLLIDER_ID
{
	struct {
		int32 Left_id;
		int32 Right_id;
	};
	int64 ID;
};

class CollisionManager
{
	DECLARE_SINGLE(CollisionManager)
private:
	map<ULONGLONG, bool> m_mapColInfo;			// �浹ü ���� ���� ������ �浹 ����
	int32 m_arrCheck[(int32)ObjectType::END] = {};		// �׷� ���� �浹 üũ ��Ʈ����


public:
	void Init();
	void Update();
	void CheckGroup(ObjectType _eLeft, ObjectType _eRight);
	void Reset() { memset(m_arrCheck, 0, sizeof(int32) * (int32)ObjectType::END); }

private:
	void CollisionUpdateGroup(ObjectType _eLeft, ObjectType _eRight);
	bool IsCollision(Collider* _pLeftCol, Collider* _pRightCol);

};

