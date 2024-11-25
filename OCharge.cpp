#include "pch.h"
#include "OCharge.h"
#include "ResourceManager.h"

void OCharge::Update()
{
	//시간에 따라 Fee 업데이트 되어야 함
	fee = GetFee();
	printWord = to_wstring(fee);
}

void OCharge::Render(HDC hdc)
{
	HBITMAP hBitmap2 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\main\\fee.bmp");
	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hBitmap2, 1720, 150, 255);
	GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hBitmap2, 1760, 195, printWord.c_str(), 60);

}
   