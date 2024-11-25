#include "pch.h"
#include "Event.h"



Event::Event(wstring eventID, wstring kind, wstring runEvent, wstring moneyPM, wstring famePM, vector<wstring> flagChange, wstring timerChange)
	: DataObject(DataObjectType::EVENT), _eventID(eventID), _kind(kind), _runEvent(runEvent),
	_moneyPM(moneyPM), _famePM(famePM), _flagChange(flagChange), _timerChange(timerChange)
{

}

Event::Event() : DataObject(DataObjectType::EVENT)
{

}

Event::~Event()
{

}

void Event::Init()
{

}

void Event::Update()
{

}

void Event::Render(HDC hdc)
{

}

