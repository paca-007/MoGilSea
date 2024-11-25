#include "pch.h"
#include "CollisionManager.h"

#include "SceneManager.h"
#include "Scene.h"
#include "Object.h"
#include "Collider.h"




//CollisionManager::CollisionManager()
//{
//
//}
//
//CollisionManager::~CollisionManager()
//{
//
//}

void CollisionManager::Init()
{
}

void CollisionManager::Update()
{
	for (int32 iRow = 0; iRow < (int32)ObjectType::END; ++iRow)
	{
		for (int32 iCol = iRow; iCol < (int32)ObjectType::END; ++iCol)
		{
			if (m_arrCheck[iRow] & (1 << iCol))
			{
				CollisionUpdateGroup((ObjectType)iRow, (ObjectType)iCol);
			}
		}
	}


}

void CollisionManager::CollisionUpdateGroup(ObjectType _eLeft, ObjectType _eRight)
{
	Scene* pCurScene = GET_SINGLE(SceneManager)->GetCurrentScene();

	const vector<Object*> vecLeft = pCurScene->GetGroupObject(_eLeft);
	const vector<Object*> vecRight = pCurScene->GetGroupObject(_eRight);

	map<uint64, bool>::iterator iter;

	for (size_t i = 0; i < vecLeft.size(); ++i)
	{
		// 충돌체를 보유하지 않는 경우
		if (nullptr == vecLeft[i]->GetCollider())
		{
			continue;
		}

		for (size_t j = 0; j < vecRight.size(); ++j)
		{
			// 충돌체가 없거나, 자기 자신과의 충돌인 경우
			if (nullptr == vecRight[j]->GetCollider()
				|| vecLeft[i] == vecRight[j])
			{
				continue;
			}

			Collider* pLeftCol = vecLeft[i]->GetCollider();
			Collider* pRightCol = vecRight[i]->GetCollider();


			// 두 충돌체 조합 아이디 생성
			COLLIDER_ID ID;
			ID.Left_id = pLeftCol->GetID();
			ID.Right_id = pRightCol->GetID();

			iter = m_mapColInfo.find(ID.ID);

			// 충돌 정보가 미 등록 상태인 경우 등록(충돌하지 않았다 로 등록)
			if (m_mapColInfo.end() == iter)
			{
				m_mapColInfo.insert(make_pair(ID.ID, false));
				iter = m_mapColInfo.find(ID.ID);
			}


			if (IsCollision(pLeftCol, pRightCol))
			{
				// 현재 충돌 중이다.
				if (iter->second)
				{
					// 이전에도 충돌 하고 있었다.
					pLeftCol->OnCollision(pRightCol);
					pRightCol->OnCollision(pLeftCol);
				}
				else
				{
					// 이전에는 충돌하지 않았다.
					pLeftCol->OnCollisionEnter(pRightCol);
					pRightCol->OnCollisionEnter(pLeftCol);
					iter->second = true;
				}
			}
			else
			{
				// 현재 충돌하고 있지 않다.
				if (iter->second)
				{
					// 이전에는 충돌하고 있었다.
					pLeftCol->OnCollisionExit(pRightCol);
					pRightCol->OnCollisionExit(pLeftCol);
					iter->second = false;
				}

			}
		}
	}
}

bool CollisionManager::IsCollision(Collider* _pLeftCol, Collider* _pRightCol)
{
	Vec2 vLeftPos = _pLeftCol->GetFinalPos();
	Vec2 vLeftScale = _pLeftCol->GetScale();

	Vec2 vRightPos = _pRightCol->GetFinalPos();
	Vec2 vRightScale = _pRightCol->GetScale();

	if (abs(vRightPos.x - vLeftPos.x) < (vLeftScale.x + vRightScale.x) / 2.f
		&& abs(vRightPos.y - vLeftPos.y) < (vLeftScale.y + vRightScale.y) / 2.f)
	{

		return true;
	}

	return false;
}

void CollisionManager::CheckGroup(ObjectType _eLeft, ObjectType _eRight)
{
	// 더 작은 값의 그룹 타입을 행으로,
	// 큰 값을 열(비트) 로 사용

	int32 iRow = (int32)_eLeft;
	int32 iCol = (int32)_eRight;

	if (iCol < iRow)
	{
		iRow = (int32)_eRight;
		iCol = (int32)_eLeft;
	}

	if (m_arrCheck[iRow] &= (1 << iCol))
	{
		m_arrCheck[iRow] &= ~(1 << iCol);
	}
	else
	{
		m_arrCheck[iRow] |= (1 << iCol);
	}

}

