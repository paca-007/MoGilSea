#pragma once

struct tEvent
{
	EventType	eEVEN;
	PlayEventType pEVEN;
	DWORD_PTR	lParam;
	DWORD_PTR	wParam;

};

class EventManager
{
	DECLARE_SINGLE(EventManager);

private:
	vector<tEvent> mVecEvent;
	vector<Object*> mVecDead;

public:
	void Update();
	void AddEvent(const tEvent& _eve) { mVecEvent.push_back(_eve); }
	void ChangePlayerEvent(PlayEventType _playerEve);

private:
	void Excute(const tEvent& _eve);
};

