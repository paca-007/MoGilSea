#include "pch.h"
#include "OOpeningFullScreen.h"
#include "ResourceManager.h"

void OOpeningFullScreen::Update()
{

}

void OOpeningFullScreen::Render(HDC hdc)
{
	HBITMAP hBitmap2 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\opening\\OP_back.bmp");
	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hBitmap2, 0, 0, 255);
}
