#include "pch.h"
#include "OSettingButton.h"
#include "ResourceManager.h"

void OSettingButton::Update()
{
}

void OSettingButton::Render(HDC hdc)
{
	HBITMAP hBitmap2 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\title\\setting.bmp");
	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hBitmap2, 1720, 780, 255);
}
