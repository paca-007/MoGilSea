#pragma once
#include "Scene.h"
class Openning :
    public Scene
{

private:


public:
	virtual void Start();
	virtual void Exit();

	virtual void Update();


public:
	Openning();
	virtual ~Openning();

public:
	bool coreFlag = false; // �ٿ� �ذ� 

public:
	int scriptNum = 0;
};

