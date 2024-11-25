#pragma once
#include "Object.h"
class OWaiting :
    public Object
{

public:
	OWaiting();
	void Update();
	void Render(HDC hdc);
	
protected:
	int32 _curNum; //������ ��� ��
	int32 _totalNum; // �� ��� ��
	wstring _printWord;
	vector<wstring> _waiting;
	bool _queueFull = false;
};

