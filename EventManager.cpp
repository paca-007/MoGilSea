#include "pch.h"
#include "EventManager.h"
#include "Object.h"
#include "SceneManager.h"
#include "Scene.h"
#include "ObjectManager.h"
#include "TimeManager.h"


void EventManager::Update()
{
	//Dead Object Vector 삭제
	for (size_t i = 0; i < mVecDead.size(); i++)
	{
		delete mVecDead[i];
	}	
	mVecDead.clear();

	//이벤트 처리
	for (size_t i = 0; i < mVecEvent.size(); i++)
	{
		Excute(mVecEvent[i]);
	}

	mVecEvent.clear();
}

void EventManager::ChangePlayerEvent(PlayEventType _playerEve)
{
	switch (_playerEve)
	{
	case PlayEventType::PLAYERWAIT:

		break;

	case PlayEventType::ADVOFF:
		break;

	case PlayEventType::ADVON:

		break;

	case PlayEventType::DIALOGUE:
		break;
	case PlayEventType::NONE:
		break;
	}
}

void EventManager::Excute(const tEvent& _eve)
{
	_eve.eEVEN;

	switch (_eve.eEVEN)
	{
	case EventType::INIT:

		break;
	case EventType::CREATEOBJECT:
	{
		//lParam : Object Address
		//wParam : Object Type
		Object* pNewObj = (Object*)_eve.lParam;
		ObjectType eType = (ObjectType)_eve.wParam;

		GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(pNewObj, eType);
	}
		break;

	case EventType::DELETEOBJECT:
	{
		//lParam : Object Address
		//Object를 Dead상태로 변경
		//삭제 예정 오브젝트들을 모아둔다.
		Object* pDeadObj = (Object*)_eve.lParam;
		pDeadObj->SetDead();
		mVecDead.push_back(pDeadObj);
	}
		break;

	case EventType::SCENECHANGE:
		//lParam : NextSceneType
		SceneManager::GetInstance()->ChangeScene((SceneType)_eve.lParam);
		break;


	case EventType::NONE:

		break;

	case EventType::PLAYEVENT:

		switch (_eve.pEVEN)
		{
		case PlayEventType::PLAYERWAIT:
			OutputDebugString(TEXT("Player Wait"));
			OutputDebugString(TEXT("\n"));
			break;

		case PlayEventType::ADVOFF:
			OutputDebugString(TEXT("Character OFF"));
			OutputDebugString(TEXT("\n"));
			break;

		case PlayEventType::ADVON:
		{
			OutputDebugString(TEXT("Character ON"));
			OutputDebugString(TEXT("\n"));
		}
		break;

		case PlayEventType::DIALOGUE:
			//OutputDebugString(TEXT("Speak"));
			//OutputDebugString(TEXT("\n"));
			break;

		case PlayEventType::BUTTINCHECK:
			OutputDebugString(TEXT("ButtonCheck"));
			OutputDebugString(TEXT("\n"));
			break;

		case PlayEventType::NONE:
			break;
		}
		break;
	
	}
}
