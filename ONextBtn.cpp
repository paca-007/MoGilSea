#include "pch.h"
#include "ONextBtn.h"
#include "ResourceManager.h"
#include "InputManager.h"


void ONextBtn::Update()
{

}

void ONextBtn::Render(HDC hdc)
{
	
	HBITMAP hBitmap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\Feedback\\next_button.bmp");
	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hBitmap, 1000, 950, 255);
}
