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
	bool coreFlag = false; // �ٿ� �ذ� 

public:
	int scriptNum = 0;

};

