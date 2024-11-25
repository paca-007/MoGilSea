#include "pch.h"
#include "OFullScreen.h"

#include "ResourceManager.h"

void OFullScreen::Update()
{

}

void OFullScreen::Render(HDC hdc)
{
	HBITMAP hBitmap2 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\ending\\ED_back.bmp");
	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hBitmap2, 0, 0, 255);

}
