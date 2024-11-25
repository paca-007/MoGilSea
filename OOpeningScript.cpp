#include "pch.h"
#include "OOpeningScript.h"
#include "ResourceManager.h"

void OOpeningScript::Update()
{
	openingType = GetOpeningType();
	scriptNum = GetendingScript();
}

void OOpeningScript::Render(HDC hdc)
{
	switch (openingType)
	{
	case OpeningSceneType::ONE: 
	{
		if (scriptNum == 0)	openingScriptBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\opening\\text\\OP1_1.bmp");
		
	}
		break;
	case OpeningSceneType::TWO:
	{
		if (scriptNum == 0)	openingScriptBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\opening\\text\\OP2_1.bmp");
		if (scriptNum == 1)	openingScriptBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\opening\\text\\OP2_2.bmp");
	}
		break;
	case OpeningSceneType::THREE:
	{
		if (scriptNum == 0)	openingScriptBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\opening\\text\\OP3_1.bmp");
	}
		break;
	case OpeningSceneType::FOUR:
	{
		if (scriptNum == 0)	openingScriptBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\opening\\text\\OP4_1.bmp");
	}
		break;
	case OpeningSceneType::FIVE:
	{
		if (scriptNum == 0)	openingScriptBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\opening\\text\\OP5_1.bmp");
	}
		break;

	}

	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, openingScriptBitMap, 0, 700, 255);
}
