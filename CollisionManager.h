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
	map<ULONGLONG, bool> m_mapColInfo;			// 충돌체 간의 이전 프레임 충돌 정보
	int32 m_arrCheck[(int32)ObjectType::END] = {};		// 그룹 간의 충돌 체크 매트릭스


public:
	void Init();
	void Update();
	void CheckGroup(ObjectType _eLeft, ObjectType _eRight);
	void Reset() { memset(m_arrCheck, 0, sizeof(int32) * (int32)ObjectType::END); }

private:
	void CollisionUpdateGroup(ObjectType _eLeft, ObjectType _eRight);
	bool IsCollision(Collider* _pLeftCol, Collider* _pRightCol);

};

