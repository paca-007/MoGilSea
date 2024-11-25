#pragma once
#include "Adventurer.h" 
#include "Event.h"
#include "Quest.h"

class DataObject;


class ObjectManager
{
	DECLARE_SINGLE(ObjectManager);

public:

	~ObjectManager();

	void Init();

	void Clear();

	void SetADVMap(unordered_map<wstring, Adventurer> adventurerMap);
	void SetEventMap(unordered_map<wstring, Event> eventMap);
	void SetQuestMap(unordered_map<wstring, Quest> questMap);
	void SetADVIDVector();
	void SetEventIDVector();
	vector<wstring> GetADVIDVector() { return _advIDVector; }
	vector<wstring> GetEventIDVector() { return _eventIDVector; }
	unordered_map<wstring, Adventurer> GetADVMap() { return _adventurerMap; }
	unordered_map<wstring, Event> GetEventMap() { return _eventMap; }
	unordered_map<wstring, Quest> GetQuestMap() { return _questMap; }


	// ���� �Ǵ� ���� ��ư�� ��������
	// ���̵� �ٲ۴�-> Ocharacter�� �����ؼ�
	// �ٲ㼭 ����Ѵ�
	void ChangeADVID(wstring advID);
	wstring FindInitEventID();
	void ChangePlayEvent();
	bool GetPlayerWaitState() { return _isPlayerWait; }

	// �� ������ ������ ������Ʈ ������ ������ ������Ѿ� �Ѵ�.
	wstring GetCurrentADVID() { return _currentADVID; }
	void SetCurrentADVID(wstring advID) { _currentADVID = advID; }
	wstring GetCurrentEventID() { return _currentEventState; }
	void SetPreEventID(wstring eventID) { _preEventID = eventID; }
private:
	
	unordered_map<wstring, Adventurer> _adventurerMap;
	unordered_map<wstring, Event> _eventMap;
	unordered_map<wstring, Quest> _questMap;

	vector<wstring> _advIDVector;
	vector<wstring> _eventIDVector;

	wstring _currentADVID = {};
	wstring _currentEventState = {};
	wstring _currentEventID = {};

	// vector<adv>

	// currentAdv

	// �÷��̾� ��� �����ΰ��� üũ�ϴ� �ο� ����
	bool _isPlayerWait = false;

	// ��ư�� ���ȴ°�
	bool _isApplyBtnHit = false;
	bool _isApprovalBtnHit = false;
	bool _isBargainBtnHit = false;
	bool _isRefuseBtnHit = false;

	// ���� ��⿭�� ���° ���谡�� �Դ���
	int32 _curNum = 1;

	// ���� ���° ��������
	int32 _round = 1;

	// ���� �̺�Ʈ�� �����ߴµ�
	// �̰� �������� �����Ѵٸ�
	// ���� �̺�Ʈ��� �̸��� �ٲ�� ������
	wstring _preEventID = {};
	PlayEventType _playEventState = PlayEventType::QUEUECHECK;

public:
	void SetApplyBtnState(bool state) { _isApplyBtnHit = state; }
	bool GetApplyBtnState() { return _isApplyBtnHit; }
	void SetApprovalBtnState(bool state) { _isApprovalBtnHit = state; }
	bool GetApprovalBtnState() { return _isApprovalBtnHit; }
	void SetBargainBtnState(bool state) { _isBargainBtnHit = state; }
	bool GetBargainBtnState() { return _isBargainBtnHit; }
	void SetRefuseBtnState(bool state) { _isRefuseBtnHit = state; }
	bool GetRefuseBtnState() { return _isRefuseBtnHit; }
	PlayEventType GetPlayEventState() { return _playEventState; }
	void PlayEvent();
	int32 GetCurNum() { return _curNum; }
	void SetCurNum(int32 num) { _curNum = num; }
};

