#include "pch.h"
#include "OFame.h"
#include "ResourceManager.h"

void OFame::Update()
{
	//명성치에 따라fame 업데이트 되어야 함
	fame = GetFame();
	
	printWord = to_wstring(fame);
}

void OFame::Render(HDC hdc)
{
	HBITMAP hBitmap2 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\main\\fame.bmp");
	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hBitmap2, 1520, 390, 255);
	GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hBitmap2, 1780, 400, printWord.c_str() ,60);
	
}
