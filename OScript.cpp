#include "pch.h"
#include "OScript.h"
#include "ResourceManager.h"
#include "ObjectManager.h"
#include "TimeManager.h"

void OScript::Update()
{
	alphaValue = GetAlpha();
	_script = GetScript();


}

void OScript::Render(HDC hdc)
{
	HBITMAP hBitmap2 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\main\\chat.bmp");
	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hBitmap2, 1070, 100, alphaValue);
	GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hBitmap2, 1100, 150, _script.c_str(), 42);
}
