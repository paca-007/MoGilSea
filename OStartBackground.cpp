#include "pch.h"
#include "OStartBackground.h"

#include "ResourceManager.h"


OStartBackground::OStartBackground()
{

}

void OStartBackground::Update()
{

}

void OStartBackground::Render(HDC hdc)
{
	HBITMAP hBitmap2 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\title\\title.bmp");
	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hBitmap2, 0, 0, 255);
}
