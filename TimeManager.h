#pragma once
class TimeManager
{
	DECLARE_SINGLE(TimeManager);

public:
	
	void Init();

	void Update();

	float getDeltaTime();
	

private:

	LARGE_INTEGER liPreCount{ 0,0 };
	LARGE_INTEGER liCurCount{ 0,0 };
	LARGE_INTEGER liFrequency{ 0,0 };

	float deltaTime = 0.0f;
	float fTime = 0.0f;

	int32 fps = 0;
	int32 iCallCount = 0;


};

