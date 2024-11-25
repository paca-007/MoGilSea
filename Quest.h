#pragma once
#include "DataObject.h"

class Quest : public DataObject
{
public:
	Quest(wstring questID, wstring name, wstring content, wstring grade, wstring level, wstring pay
		, wstring questClearMoney, wstring questClearFame, wstring questClearFlag
		, wstring questClearText, wstring questFailMoney, wstring questFailFame, wstring questFailFlag
		, wstring questFailText, wstring certainADV, wstring certainMoney, wstring certainFame
		, wstring certainFlag, wstring certainText);
	Quest();
	virtual ~Quest();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

public:
	wstring _questID, _name, _content, _grade, _level, _pay, _questClearMoney, _questClearFame
		, _questClearFlag, _questClearText, _questFailMoney, _questFailFame, _questFailFlag,
		_questFailText, _certainADV, _certainMoney, _certainFame, _certainFlag, _certainText
		= {};



};

