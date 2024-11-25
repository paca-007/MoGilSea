#include "pch.h"
#include "Quest.h"

Quest::Quest(wstring questID, wstring name, wstring content, wstring grade, wstring level, wstring pay, wstring questClearMoney, wstring questClearFame, wstring questClearFlag, wstring questClearText, wstring questFailMoney, wstring questFailFame, wstring questFailFlag, wstring questFailText, wstring certainADV, wstring certainMoney, wstring certainFame, wstring certainFlag, wstring certainText)
	: DataObject(DataObjectType::QUEST), _questID(questID), _name(name), _content(content), _grade(grade)
	, _level(level), _pay(pay), _questClearMoney(questClearMoney), _questClearFame(questClearFame)
	, _questClearFlag(questClearFlag), _questClearText(questClearText), _questFailMoney(questFailMoney)
	, _questFailFame(questFailFame), _questFailFlag(questFailFlag), _questFailText(questFailText)
	, _certainADV(certainADV), _certainMoney(certainMoney), _certainFame(certainFame)
	, _certainFlag(certainFlag), _certainText(certainText)
{

}

Quest::Quest() : DataObject(DataObjectType::QUEST)
{

}

Quest::~Quest()
{

}

void Quest::Init()
{

}

void Quest::Update()
{

}

void Quest::Render(HDC hdc)
{

}
