#include "pch.h"
#include "OScreenFrame.h"
#include "ResourceManager.h"

void OScreenFrame::Update()
{

}

void OScreenFrame::Render(HDC hdc)
{
	HBITMAP hBitmap2 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\main\\screen_frame.bmp");
	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hBitmap2, 400, 0, 255);
}
