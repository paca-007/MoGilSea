#include "pch.h"
#include "ORequest_2.h"
#include "ResourceManager.h"
#include "ObjectManager.h"

#include "TimeManager.h"
#include "InputManager.h"
#include "Collider.h"

#include "PlayScene.h"

ORequest_2::ORequest_2()
{
	CreateCollider();
	GetCollider()->SetOffsetPos(Vec2(0.f, 0.f));
	GetCollider()->SetScale(Vec2(100.f, 100.f));
}

ORequest_2::~ORequest_2()
{
}

void ORequest_2::Update()
{
	Vec2 vPos = GetPos();

	_mousePos = GET_SINGLE(InputManager)->GetMouseCursorPosition();

	_hoverCheck = GET_SINGLE(InputManager)->HoverCheck(vPos.x, vPos.y, 100, 100, _mousePos);


	if (_hoverCheck)
	{
		if (KEY_TAP(KEY::LMB))
		{
			m_vDragStart = _mousePos;
			SetIsClicked(true);
		}
		if (KEY_HOLD(KEY::LMB))
		{
			SetIsClicked(true);
			Vec2 vDiff = _mousePos - m_vDragStart;

			vPos = vPos + vDiff;

			m_vDragStart = _mousePos;
			//vPos.x -= 500.f * DT;
		}
	}

	bool isClicked = GetIsClicked();

	if (KEY_AWAY(KEY::LMB))
	{
		isClicked = false;
	}


	if(isClicked)
		SetPos(vPos);

}

void ORequest_2::Render(HDC hdc)
{
	Vec2 vCurPos = GetPos();

	HBITMAP hrequest1;

	bool isDragNow = GetIsClicked();

	Vec2 rq = this->GetPos();

	if (rq.y >= 680)
	{
		hrequest1 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\Dummy\\d_request(desk).bmp");

	}
	else
	{
		hrequest1 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\Dummy\\d_request(board).bmp");
		SetIsClicked(false);
	}

	//HBITMAP hBitmap2 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\Dummy\\d_request(board).bmp");
	if (_hoverCheck == true)
		GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hrequest1, vCurPos.x + 20, vCurPos.y, name.c_str(), 24);


	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hrequest1, vCurPos.x, vCurPos.y, isVisivle);

}

void ORequest_2::OnCollisionEnter(Collider* _pOther)
{
	Object* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"Table")
	{
		test = true;
	}
}

void ORequest_2::OnCollisionExit(Collider* _pOther)
{
	Object* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"Table")
	{
		test = false;
	}
}


