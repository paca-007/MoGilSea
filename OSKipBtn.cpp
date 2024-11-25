#include "pch.h"
#include "OSKipBtn.h"
#include "ResourceManager.h"

void OSKipBtn::Update()
{
}

void OSKipBtn::Render(HDC hdc)
{

	HBITMAP hBitmap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\Feedback\\skip_button.bmp");
	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hBitmap, 1500, 950, 255);
}
