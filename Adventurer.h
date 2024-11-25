#pragma once
#include "DataObject.h"
// 오브젝트(GDI)랑 데이터 부분을 나눠야 될듯

class Adventurer : public DataObject
{
public:
	Adventurer(wstring ID, wstring name, wstring imageID, wstring initEvent,
		vector<wstring> negotiateEvent, vector<wstring> supportEvent,
		wstring acceptEvent, wstring refuseEvent, wstring level, vector<wstring> goodTask,
		vector<wstring> badTask, wstring appearanceCondition, wstring intialFee);
	Adventurer();
	virtual ~Adventurer() override;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	wstring GetImageID() { return _imageID; }
	
	wstring GetInitEvent() { return _initEvent; }

private:
	wstring _ID = {};
	wstring _name = {};
	wstring _imageID = {};
	
	// eventID 정리한 class 추가
	// 다 넣고 true/false로 구현
	wstring _initEvent = {};
	vector<wstring> _negotiateEvent = {};
	vector<wstring> _supportEvent = {};		// 3종류 있음
	wstring _acceptEvent = {};
	wstring _refuseEvent = {};
	wstring _level = 0;
	vector<wstring> _goodTask = {};
	vector<wstring> _badTask = {};

	// TODO
	// 등장 조건 클래스(구조체) 만들어야 됨
	wstring _appearanceCondition = {};
	wstring _intialFee = {};
};

