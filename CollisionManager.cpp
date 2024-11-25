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
		// �浹ü�� �������� �ʴ� ���
		if (nullptr == vecLeft[i]->GetCollider())
		{
			continue;
		}

		for (size_t j = 0; j < vecRight.size(); ++j)
		{
			// �浹ü�� ���ų�, �ڱ� �ڽŰ��� �浹�� ���
			if (nullptr == vecRight[j]->GetCollider()
				|| vecLeft[i] == vecRight[j])
			{
				continue;
			}

			Collider* pLeftCol = vecLeft[i]->GetCollider();
			Collider* pRightCol = vecRight[i]->GetCollider();


			// �� �浹ü ���� ���̵� ����
			COLLIDER_ID ID;
			ID.Left_id = pLeftCol->GetID();
			ID.Right_id = pRightCol->GetID();

			iter = m_mapColInfo.find(ID.ID);

			// �浹 ������ �� ��� ������ ��� ���(�浹���� �ʾҴ� �� ���)
			if (m_mapColInfo.end() == iter)
			{
				m_mapColInfo.insert(make_pair(ID.ID, false));
				iter = m_mapColInfo.find(ID.ID);
			}


			if (IsCollision(pLeftCol, pRightCol))
			{
				// ���� �浹 ���̴�.
				if (iter->second)
				{
					// �������� �浹 �ϰ� �־���.
					pLeftCol->OnCollision(pRightCol);
					pRightCol->OnCollision(pLeftCol);
				}
				else
				{
					// �������� �浹���� �ʾҴ�.
					pLeftCol->OnCollisionEnter(pRightCol);
					pRightCol->OnCollisionEnter(pLeftCol);
					iter->second = true;
				}
			}
			else
			{
				// ���� �浹�ϰ� ���� �ʴ�.
				if (iter->second)
				{
					// �������� �浹�ϰ� �־���.
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
	// �� ���� ���� �׷� Ÿ���� ������,
	// ū ���� ��(��Ʈ) �� ���

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

