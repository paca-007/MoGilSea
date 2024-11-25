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
	int32 _curNum; //지나간 사람 수
	int32 _totalNum; // 총 사람 수
	wstring _printWord;
	vector<wstring> _waiting;
	bool _queueFull = false;
};

