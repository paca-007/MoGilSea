#include "pch.h"
#include "OBackground.h"
#include "ResourceManager.h"

OBackground::OBackground()
{

}

void OBackground::Update()
{

}

void OBackground::Render(HDC hdc)
{
	HBITMAP hBitmap2 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\main\\main_screen.bmp");
	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hBitmap2, 400, 0, 255);
}
