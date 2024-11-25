#include "pch.h"
#include "OExitBtn.h"
#include "ResourceManager.h"

void OExitBtn::Update()
{

}

void OExitBtn::Render(HDC hdc)
{
	HBITMAP hBitmap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\title\\endbutton.bmp");
	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hBitmap, 920, 870, 255);
}