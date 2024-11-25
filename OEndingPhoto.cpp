#include "pch.h"
#include "OEndingPhoto.h"

#include "ResourceManager.h"

void OEndingPhoto::Update()
{
	endType = GetEndingType();
}

void OEndingPhoto::Render(HDC hdc)
{
	
	switch (endType)
	{
	case EndingSceenType::END_1:
	{
		endingBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\ending\\ED_1.bmp");
	}
	break;

	case EndingSceenType::END_2:
	{
		endingBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\ending\\ED_2.bmp");
	}
	break;

	case EndingSceenType::END_3:
	{
		endingBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\ending\\ED_3.bmp");
	}
	break;

	case EndingSceenType::END_4:
	{
		endingBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\ending\\ED_4.bmp");
	}

	case EndingSceenType::END_5:
	{
		endingBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\ending\\ED_5.bmp");
	}
	break;

	case EndingSceenType::END_6:
	{
		endingBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\ending\\ED_6.bmp");
	}
	break;

	}

	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, endingBitMap, 580, 300, 255);
}
