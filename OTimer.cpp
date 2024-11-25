#include "pch.h"
#include "OTimer.h"
#include "ResourceManager.h"
#include "TimeManager.h"

void OTimer::Update()
{
	width = Timer(GET_SINGLE(TimeManager)->getDeltaTime(), width);
}

void OTimer::Render(HDC hdc)
{
	HBITMAP hBitmap2 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\Dummy\\d_Time bar.bmp");
	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hBitmap2, 600, 0, 255);

	Rectangle(hdc, 600, 0, (int)width, 30);
	
}


float OTimer::Timer(float deltaTime, float tWidth)
{
		timerTime += deltaTime;

		if (timerTime >= 1.0)
		{
			sec--;

			timerTime = 0.0;

			if (sec <= 0)
			{
				OutputDebugString(TEXT("Timer: "));
				OutputDebugString(TEXT("END"));
				OutputDebugString(TEXT("\n"));
				tWidth = 600;
			}

			else
			{
				//30ÃÊ -> 18   5ÃÊ -> 110 
				OutputDebugString(TEXT("Timer: "));
				OutputDebugString(to_wstring(sec).c_str());
				OutputDebugString(TEXT("\n"));
				tWidth -=18;
			}
		
		}
	
		return tWidth;
}
