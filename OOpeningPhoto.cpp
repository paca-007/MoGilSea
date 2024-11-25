#include "pch.h"
#include "OOpeningPhoto.h"
#include "ResourceManager.h"

void OOpeningPhoto::Update()
{
	openingType = GetOpeningType();
}


void OOpeningPhoto::Render(HDC hdc)
{
	switch (openingType)
	{
	case OpeningSceneType::ONE: 
	{
		openingBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\opening\\OP_1.bmp");
	}
		break;
	case OpeningSceneType::TWO:
	{
		openingBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\opening\\OP_2.bmp");
	}
		break;
	case OpeningSceneType::THREE:
	{
		openingBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\opening\\OP_3.bmp");
	}
		break;
	case OpeningSceneType::FOUR:
	{
		openingBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\opening\\OP_4.bmp");
	}
		break;
	case OpeningSceneType::FIVE:
	{
		openingBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\opening\\OP_5.bmp");
	}
		break;	
	}

	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, openingBitMap, 580, 300, 255);
}
