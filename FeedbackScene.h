#pragma once
#include "Scene.h"
class FeedbackScene :
    public Scene
{

private:


public:
	virtual void Start();
	virtual void Exit();

	virtual void Update();

public:
	FeedbackScene();

	virtual ~FeedbackScene();

public:
	bool NextButtonClick = false;
	bool SkipButtonClick = false;


	int32 characterScripNum = 0;
};

