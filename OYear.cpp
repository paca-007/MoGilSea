#include "pch.h"
#include "OYear.h"
#include "ResourceManager.h"

void OYear::Update()
{
	//시간에 따라 year 업데이트 되어야 함
	year = GetYear();
	printWord = to_wstring(year);
}

void OYear::Render(HDC hdc)
{

	HBITMAP hBitmap2 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\main\\days.bmp");
	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hBitmap2, 1670, 0, 255);
	GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hBitmap2, 1730, 52, printWord.c_str(), 60);
	
}
