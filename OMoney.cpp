#include "pch.h"
#include "OMoney.h"
#include "ResourceManager.h"

void OMoney::Update()
{
	//소지금에 따라 업데이트 되어야 함
	money = GetMoney();

	printWord = to_wstring(money);
}

void OMoney::Render(HDC hdc)
{
	HBITMAP hBitmap2 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\main\\money.bmp");
	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hBitmap2, 1520, 300, 255);
	GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hBitmap2, 1680, 305, printWord.c_str(), 60);
}
