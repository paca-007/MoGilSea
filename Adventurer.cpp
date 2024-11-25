#include "pch.h"
#include "Adventurer.h"


Adventurer::Adventurer(wstring ID, wstring name, wstring imageID, wstring initEvent, vector<wstring> negotiateEvent, vector<wstring> supportEvent, wstring acceptEvent, wstring refuseEvent, wstring level, vector<wstring> goodTask, vector<wstring> badTask, wstring appearanceCondition, wstring initialFee)
	: DataObject(DataObjectType::ADVENTURER),_ID(ID),_name(name),_imageID(imageID),
	_initEvent(initEvent),_negotiateEvent(negotiateEvent),_supportEvent(supportEvent),
	_acceptEvent(acceptEvent),_refuseEvent(refuseEvent),_level(level),_goodTask(goodTask),
	_badTask(badTask),_appearanceCondition(appearanceCondition), _intialFee(initialFee)
{
	
}

Adventurer::Adventurer() : DataObject(DataObjectType::ADVENTURER)
{

}

Adventurer::~Adventurer()
{

}

void Adventurer::Init()
{

}

void Adventurer::Update()
{

}

void Adventurer::Render(HDC hdc)
{

}




