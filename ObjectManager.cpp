#include "pch.h"
#include "ObjectManager.h"
#include "ResourceManager.h"

ObjectManager::~ObjectManager()
{
	Clear();
}

void ObjectManager::Init()
{
	SetADVMap(_adventurerMap);
	SetEventMap(_eventMap);
	SetQuestMap(_questMap);
	SetADVIDVector();
	SetEventIDVector();
}


void ObjectManager::Clear()
{
	_adventurerMap.clear();
	_eventMap.clear();
	_questMap.clear();
	_advIDVector.clear();
	_eventIDVector.clear();

}

void ObjectManager::SetADVMap(unordered_map<wstring, Adventurer> adventurerMap)
{
	adventurerMap = GET_SINGLE(ResourceManager)->ReadADVCSV(L"Resources/Data/exp_adv_csv.csv");
	_adventurerMap = adventurerMap;
}

void ObjectManager::SetEventMap(unordered_map<wstring, Event> eventMap)
{
	eventMap = GET_SINGLE(ResourceManager)->ReadEventCSV(L"Resources/Data/exp_event_csv.csv");
	_eventMap = eventMap;
}

void ObjectManager::SetQuestMap(unordered_map<wstring, Quest> questMap)
{
	questMap = GET_SINGLE(ResourceManager)->ReadQuestCSV(L"Resources/Data/exp_quest_csv.csv");
	_questMap = questMap;
}

void ObjectManager::SetADVIDVector()
{
	for (auto it = _adventurerMap.begin(); it != _adventurerMap.end(); ++it)
	{
		_advIDVector.push_back(it->first);
	}
}

void ObjectManager::SetEventIDVector()
{
	for (auto it = _eventMap.begin(); it != _eventMap.end(); ++it)
	{
		_eventIDVector.push_back(it->first);
	}
}

void ObjectManager::ChangeADVID(wstring advID)
{
	auto iter = _adventurerMap.find(advID);
	if (iter != _adventurerMap.end())
	{
		_currentADVID = iter->first;
	}
	else
	{
		assert("존재하지 않는 모험가 ID");
	}
}

std::wstring ObjectManager::FindInitEventID()
{
	// 현재 모험가를 찾는다
	Adventurer currentADV = _adventurerMap.find(_currentADVID)->second;

	// 현재 모험가의 등장 이벤트를 찾는다.
	return currentADV.GetInitEvent();
}

void ObjectManager::ChangePlayEvent()
{
	// eventMap에서 해당 eventID를 찾는다.
	_preEventID = FindInitEventID();


	// runevent값을 이용해서 그 다음 걸로 연결을 해야됨
	// 근데 이 연결을 여기서 하면 순식간에 다음걸로 넘어감
	// 나중에 텍스트 출력이 끝나면 바꾸는걸로?
	// runevent를 다시

	// 버튼 클릭을 감지하는 부울 변수를 넣어서
	// 그 버튼이 누르면 그 다음 이벤트로 넘어가도록


	// TODO 찾은 eventID를 통해서 실행 이벤트를 찾는다.
	// 플레이어 대기 상태가 아닐 때 -> 대화 상태가 쭉 이루어질때
	while (!_isPlayerWait)
	{
		Event currentEvent = _eventMap.find(_preEventID)->second;
		_currentEventState = currentEvent.GetKind();
		_currentEventID = currentEvent.GetRunEvent();

		if (_currentEventState == L"player_wait")
		{
			_isPlayerWait = true;
			_playEventState = PlayEventType::PLAYERWAIT;
		}

		else if (_currentEventState == L"dialogue")
		{
			_playEventState = PlayEventType::DIALOGUE;
			_preEventID = _currentEventID;
		}

		else
		{
			PlayEvent();
		}
	}


}

/// <summary>
/// 
/// </summary>
void ObjectManager::PlayEvent()
{
	switch (_playEventState)
	{
		case PlayEventType::QUEUECHECK:
			if (_curNum > _advIDVector.size())
			{
				if (_round == 3)
				{
					// 게임 종료
				}

				else
				{
					_round++;
				}
			}

			else
			{
				_currentADVID = _advIDVector[_curNum - 1];
			}
			break;
	}
}
