#include "pch.h"
#include "TimeManager.h"

void TimeManager::Init()
{
	//현재 카운트
	QueryPerformanceCounter(&liPreCount);

	//이전 카운트
	QueryPerformanceFrequency(&liFrequency);

}



void TimeManager::Update()
{
	/*
	OutputDebugString(TEXT("PreTime: "));
	OutputDebugString(to_wstring(dwPreTime).c_str());
	OutputDebugString(TEXT("\n"));
	*/

	QueryPerformanceCounter(&liCurCount);

	deltaTime = (float)(liCurCount.QuadPart - liPreCount.QuadPart) / (float)liFrequency.QuadPart;

	liPreCount = liCurCount;

	++iCallCount;
	fTime += deltaTime;

	if (fTime >= 1.0)
	{
		fps = iCallCount;

		fTime = 0.0;
		iCallCount = 0;


		OutputDebugString(TEXT("FPS: "));
		OutputDebugString(to_wstring(fps).c_str());
		OutputDebugString(TEXT("\n"));
		OutputDebugString(TEXT("DeltaTime: "));
		OutputDebugString(to_wstring(deltaTime).c_str());
		OutputDebugString(TEXT("\n"));

	}

}


float TimeManager::getDeltaTime()
{
	return deltaTime;
}

