#pragma once
#include "Scene.h"
class EndingScene :
    public Scene
{

private:


public:
	virtual void Start();
	virtual void Exit();

	virtual void Update();


public:
	EndingScene();
	virtual ~EndingScene();

public:
	bool coreFlag = false; // 근원 해결 

public:
	int scriptNum = 0;

};

