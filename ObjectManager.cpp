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
		assert("�������� �ʴ� ���谡 ID");
	}
}

std::wstring ObjectManager::FindInitEventID()
{
	// ���� ���谡�� ã�´�
	Adventurer currentADV = _adventurerMap.find(_currentADVID)->second;

	// ���� ���谡�� ���� �̺�Ʈ�� ã�´�.
	return currentADV.GetInitEvent();
}

void ObjectManager::ChangePlayEvent()
{
	// eventMap���� �ش� eventID�� ã�´�.
	_preEventID = FindInitEventID();


	// runevent���� �̿��ؼ� �� ���� �ɷ� ������ �ؾߵ�
	// �ٵ� �� ������ ���⼭ �ϸ� ���İ��� �����ɷ� �Ѿ
	// ���߿� �ؽ�Ʈ ����� ������ �ٲٴ°ɷ�?
	// runevent�� �ٽ�

	// ��ư Ŭ���� �����ϴ� �ο� ������ �־
	// �� ��ư�� ������ �� ���� �̺�Ʈ�� �Ѿ����


	// TODO ã�� eventID�� ���ؼ� ���� �̺�Ʈ�� ã�´�.
	// �÷��̾� ��� ���°� �ƴ� �� -> ��ȭ ���°� �� �̷������
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
					// ���� ����
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
