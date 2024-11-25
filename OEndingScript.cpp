#include "pch.h"
#include "OEndingScript.h"
#include "ResourceManager.h"

void OEndingScript::Update()
{
	endType = GetEndingType();
	scriptNum = GetendingScript();

}

void OEndingScript::Render(HDC hdc)
{


	switch (endType)
	{
	case EndingSceenType::END_1:
	{
		if (scriptNum == 0)	endingScriptBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\ending\\text\\ED1_1.bmp");
		if (scriptNum == 1)	endingScriptBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\ending\\text\\ED1_2.bmp");
		if (scriptNum == 2)	endingScriptBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\ending\\text\\ED1_3.bmp");
		OutputDebugString(TEXT("1 "));
		OutputDebugString(TEXT("\n"));
	}
	break;

	case EndingSceenType::END_2:
	{
		if (scriptNum == 0)	endingScriptBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\ending\\text\\ED2_1.bmp");
		if (scriptNum == 1)	endingScriptBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\ending\\text\\ED2_2.bmp");
		if (scriptNum == 2)	endingScriptBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\ending\\text\\ED2_3.bmp");
		OutputDebugString(TEXT("2"));
		OutputDebugString(TEXT("\n"));
	}
	break;

	case EndingSceenType::END_3:
	{
		if (scriptNum == 0)	endingScriptBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\ending\\text\\ED3_1_test.bmp");
		if (scriptNum == 1)	endingScriptBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\ending\\text\\ED3_2.bmp");
		OutputDebugString(TEXT("3"));
		OutputDebugString(TEXT("\n"));
	}
	break;

	case EndingSceenType::END_4:
	{
		if (scriptNum == 0)	endingScriptBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\ending\\text\\ED4_1.bmp");
		if (scriptNum == 1)	endingScriptBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\ending\\text\\ED4_2.bmp");
		if (scriptNum == 2)	endingScriptBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\ending\\text\\ED4_3.bmp");
		OutputDebugString(TEXT("4"));
		OutputDebugString(TEXT("\n"));
	}

	case EndingSceenType::END_5:
	{
		if (scriptNum == 0)	endingScriptBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\ending\\text\\ED5_1.bmp");
		if (scriptNum == 1)	endingScriptBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\ending\\text\\ED5_2.bmp");
		if (scriptNum == 2)	endingScriptBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\ending\\text\\ED5_3.bmp");
		OutputDebugString(TEXT("5"));
		OutputDebugString(TEXT("\n"));
	}
	break;

	case EndingSceenType::END_6:
	{
		if (scriptNum == 0)	endingScriptBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\ending\\text\\ED6_1.bmp");
		if (scriptNum == 1)	endingScriptBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\ending\\text\\ED6_2.bmp");
		if (scriptNum == 2)	endingScriptBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\ending\\text\\ED6_3.bmp");
		OutputDebugString(TEXT("6"));
		OutputDebugString(TEXT("\n"));
	}
	break;

	}

	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, endingScriptBitMap, 0, 700, 255);
}
