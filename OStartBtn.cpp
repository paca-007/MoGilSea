#include "pch.h"
#include "OStartBtn.h"
#include "ResourceManager.h"


void OStartBtn::Update()
{

}

void OStartBtn::Render(HDC hdc)
{
	HBITMAP hBitmap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\title\\startbutton.bmp");
	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hBitmap, 920, 700, 255);

}
