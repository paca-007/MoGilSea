#pragma once
#include "DataObject.h"


class Event : public DataObject
{
public:
	Event(wstring eventID, wstring kind, wstring runEvent, wstring moneyPM,
		wstring famePM, vector<wstring> flagChange, wstring timerChange);
	Event();
	virtual ~Event();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	wstring GetRunEvent() { return _runEvent; }
	wstring GetKind() { return _kind; }

private:
	wstring _eventID = {};
	wstring _kind = {};
	wstring _runEvent = {};
	wstring _moneyPM = {};
	wstring _famePM = {};
	vector<wstring> _flagChange = {};
	wstring _timerChange = {};


};

