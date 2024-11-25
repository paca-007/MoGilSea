#include "pch.h"
#include "OBargainBtn.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "ObjectManager.h"

const int32 HOVERY = 480;
const int32 BTNWIDTH = 400;
const int32 BTNHEIGHT = 150;

void OBargainBtn::Update()
{
	buttonStatus = GetButtonStatus();
	_mousePos = GET_SINGLE(InputManager)->GetMouseCursorPosition();
	_hoverCheck = GET_SINGLE(InputManager)->HoverCheck((int)_hoverX, HOVERY, 400, 150, _mousePos);

	if (buttonStatus == true)
	{
		if (_hoverCheck == true)
		{
			//버튼 호버 사운드
			//GET_SINGLE(ResourceManager)->PlayEffect(13);
		}
	}
}

void OBargainBtn::Render(HDC hdc)
{
	if (buttonStatus == true)
	{
		HBITMAP hBitmap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\main\\bargain_button.bmp");
		GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hBitmap, 1520, 480, 255);
	}
	else
	{
		HBITMAP hBitmap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\main\\bargain_button_press.bmp");
		GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hBitmap, 1520, 480, 255);
	}
	
}
