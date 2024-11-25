#include "pch.h"
#include "OApplyBtn.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "Collider.h"
#include "ObjectManager.h"

const int32 HOVERY = 630;
const int32 BTNWIDTH = 400;
const int32 BTNHEIGHT = 150;

OApplyBtn::OApplyBtn()
{
}

OApplyBtn::~OApplyBtn()
{

}

void OApplyBtn::Update()
{
	buttonStatus = GetButtonStatus();

	_mousePos = GET_SINGLE(InputManager)->GetMouseCursorPosition();

	_hoverCheck = GET_SINGLE(InputManager)->HoverCheck((int)_hoverX, HOVERY, 400, 150, _mousePos);
	
	
	if (buttonStatus == true)
	{
		if (_hoverCheck == true)
		{
			if (_buttonX > 1270)
			{
				_buttonX -= 10;

			}
		}
			
	}

	if (_hoverCheck == false)
	{
		if (_buttonX < 1520)
		{
			_buttonX += 10;

		}
	}

	if (_buttonX == 1270)
		_hoverX = 1270;
	else
		_hoverX = 1520;

	
}

void OApplyBtn::Render(HDC hdc)
{

	if (buttonStatus == true)
	{
		
		//btn1
		HBITMAP hBitmapButton1 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\main\\Support Options_20.bmp");
		GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hBitmapButton1, (int)_buttonX, 630, 255);

		//btn2
		HBITMAP hBitmapButton2 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\main\\Support Options_50.bmp");
		GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hBitmapButton2, (int)_buttonX, 680, 255);

		//btn3
		HBITMAP hBitmapButton3 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\main\\Support Options_100.bmp");
		GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hBitmapButton3, (int)_buttonX, 730, 255);

		HBITMAP hBitmap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\main\\support_button.bmp");
		GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hBitmap, 1520, 630, 255);
	}
	else
	{
		HBITMAP hBitmap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\main\\support_button_press.bmp");
		GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hBitmap, 1520, 630, 255);
	}
	


	
	
}


