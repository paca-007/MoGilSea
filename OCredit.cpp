#include "pch.h"
#include "OCredit.h"
#include "ResourceManager.h"

void OCredit::Update()
{
	alphaValue = GetAlpha();
}

void OCredit::Render(HDC hdc)
{
	HBITMAP hBitmap2 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\title\\credit.bmp");
	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hBitmap2, 1720, 920, 255);

	HBITMAP hBitmap3 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\title\\creditMain.bmp");
	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hBitmap3, 0, 0, alphaValue);
}
