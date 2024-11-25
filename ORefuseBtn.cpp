#include "pch.h"
#include "ORefuseBtn.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "Collider.h"
#include "ObjectManager.h"

const int32 HOVERY = 930;
const int32 BTNWIDTH = 400;
const int32 BTNHEIGHT = 150;

ORefuseBtn::ORefuseBtn()
{
	CreateCollider();
	GetCollider()->SetOffsetPos(Vec2(0.f, 0.f));
	GetCollider()->SetScale(Vec2(250.f, 150.f));
}

ORefuseBtn::~ORefuseBtn()
{

}



void ORefuseBtn::Update()
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

void ORefuseBtn::Render(HDC hdc)
{
	if (buttonStatus == true)
	{
		HBITMAP hBitmap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\main\\reject_button.bmp");
		GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hBitmap, 1520, 930, 255);
	}
	else
	{
		HBITMAP hBitmap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\main\\reject_button_press.bmp");
		GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hBitmap, 1520, 930, 255);

	}
	
	
	
}
