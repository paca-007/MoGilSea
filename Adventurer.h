#pragma once
#include "DataObject.h"
// ������Ʈ(GDI)�� ������ �κ��� ������ �ɵ�

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
	
	// eventID ������ class �߰�
	// �� �ְ� true/false�� ����
	wstring _initEvent = {};
	vector<wstring> _negotiateEvent = {};
	vector<wstring> _supportEvent = {};		// 3���� ����
	wstring _acceptEvent = {};
	wstring _refuseEvent = {};
	wstring _level = 0;
	vector<wstring> _goodTask = {};
	vector<wstring> _badTask = {};

	// TODO
	// ���� ���� Ŭ����(����ü) ������ ��
	wstring _appearanceCondition = {};
	wstring _intialFee = {};
};

