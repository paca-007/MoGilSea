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


	// 승인 또는 거절 버튼을 눌렀을떄
	// 아이디를 바꾼다-> Ocharacter에 전달해서
	// 바꿔서 출력한다
	void ChangeADVID(wstring advID);
	wstring FindInitEventID();
	void ChangePlayEvent();
	bool GetPlayerWaitState() { return _isPlayerWait; }

	// 이 값들을 가지고 오브젝트 각각에 값들을 변경시켜야 한다.
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

	// 플레이어 대기 상태인가를 체크하는 부울 변수
	bool _isPlayerWait = false;

	// 버튼이 눌렸는가
	bool _isApplyBtnHit = false;
	bool _isApprovalBtnHit = false;
	bool _isBargainBtnHit = false;
	bool _isRefuseBtnHit = false;

	// 현재 대기열의 몇번째 모험가가 왔는지
	int32 _curNum = 1;

	// 현재 몇번째 라운드인지
	int32 _round = 1;

	// 이전 이벤트라 생각했는데
	// 이걸 기준으로 실행한다면
	// 현재 이벤트라고 이름을 바꿔야 할지도
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

