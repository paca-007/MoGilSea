#include "pch.h"
#include "ONPCEnding.h"
#include "ResourceManager.h"

void ONPCEnding::Update()
{
	alphaValue = GetAlpha();
}

void ONPCEnding::Render(HDC hdc)
{
	int32 coreCheck = GET_SINGLE(VectorManager)->GetCore();

	switch (coreCheck)
	{
	case 0:
	{
		endingBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\ending\\ending_Darius.bmp");
	}
	break;

	case 1:
	{
		endingBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\ending\\ending_Lilian.bmp");
	}
	break;

	case 2:
	{
		endingBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\ending\\ending_Eden.bmp");
	}
	break;
	}

	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, endingBitMap, 0, 0, alphaValue);
}
