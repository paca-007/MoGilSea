#include "pch.h"
#include "OBoard.h"
#include "ResourceManager.h"

void OBoard::Update()
{

}

void OBoard::Render(HDC hdc)
{

	HBITMAP hBitmapBoard = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\main\\board.bmp");
	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hBitmapBoard, 0, 0, 255);
	
}
    