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
	bool coreFlag = false; // 근원 해결 

public:
	int scriptNum = 0;
};

