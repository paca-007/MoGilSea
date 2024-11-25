#pragma once
#include "Scene.h"
class OpeningScene :
    public Scene
{

public:
	virtual void Start();
	virtual void Exit();

	virtual void Update();

public:
	OpeningScene();
	virtual ~OpeningScene();

public:
	int scriptNum = 0;
	int Scenenum = 0;
	bool isTwo = false;
};

