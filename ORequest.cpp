#include "pch.h"
#include "ORequest.h"
#include "ResourceManager.h"
#include "ObjectManager.h"

#include "TimeManager.h"
#include "InputManager.h"
#include "Collider.h"

#include "SelectGDI.h"


ORequest::ORequest()
{
	//CreateCollider();
	//GetCollider()->SetOffsetPos(Vec2(0.f, 0.f));
	//GetCollider()->SetScale(Vec2(100.f, 100.f));

	SetScale(Vec2(100, 100));
	SetObjectState(ObjectState::OUT_OF_DESK);
}

ORequest::~ORequest()
{
}


/// <summary>
/// 모든 오브젝트에 공통적으로 갱신해야 되는 부분
/// </summary>
void ORequest::Update()
{

}

void ORequest::Render(HDC hdc)
{
	Vec2 vCurPos = GetPos();
	Vec2 vCurScale = GetScale();

	//isVisivle = GetAlpha();
	if (GetRequestRankType() == RequestRank::PLATINUM)
		isVisivle = GetAlpha();

	HBITMAP hrequest1;

	_mousePos = GET_SINGLE(InputManager)->GetMouseCursorPosition();

	Vec2 rq = this->GetPos();

	/// 의뢰서가 책상 안으로 들어왔을 때
	if (rq.y + vCurScale.y / 2 / 2 >= 680)
	{
		SetObjectState(ObjectState::ON_THE_DESK);

		switch (GetRequestRankType())
		{
			case RequestRank::BRONZE:
				hrequest1 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\guilddocu\\BRONZE_PAPER.bmp");
				break;
			case RequestRank::SILVER:
				hrequest1 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\guilddocu\\SILVER_PAPER.bmp");
				break;
			case RequestRank::GOLD:
				hrequest1 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\guilddocu\\GOLD_PAPER.bmp");
				break;
			case RequestRank::PLATINUM:
				hrequest1 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\guilddocu\\PLATINUM_PAPER.bmp");
				break;
			default:
				hrequest1 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\guilddocu\\BRONZE_PAPER.bmp");
				break;
		}

		SetScale(Vec2(500, 350));
		//OutputDebugString(TEXT("우오아아앙"));
		//SelectGDI p(hdc, PenType::GREEN);
		_script1 = GetRequestNameScript();
		_script2 = GetRequestScript();
		_script3 = GetRequestameRewardScript();

		GET_SINGLE(InputManager)->SetIsRequestOntheDesk(true);
		GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hrequest1, (int)(vCurPos.x), (int)(vCurPos.y), isVisivle);
		//GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hrequest1, vCurPos.x+50, vCurPos.y + 30, _script1.c_str(), 50);
		GET_SINGLE(ResourceManager)->FeedBackScript(hdc, hrequest1, (int)(vCurPos.x + 50), (int)(vCurPos.y + 40), 460, 200, _script1.c_str(), 50);
		GET_SINGLE(ResourceManager)->FeedBackScript(hdc, hrequest1, (int)(vCurPos.x + 110), (int)(vCurPos.y + 100), 300, 200, _script2.c_str(), 40);
		//GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hrequest1, vCurPos.x+100, vCurPos.y + 100, _script2.c_str(), 40);
		GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hrequest1, (int)(vCurPos.x + 315), (int)(vCurPos.y + 250), _script3.c_str(), 50);
	}
	/// 의뢰서가 책상 밖에 있을 때
	else
	{
		if (GetObjectState() == ObjectState::ON_THE_DESK)
		{
			SetObjectState(ObjectState::WAS_ON_THE_DESK);
			vCurPos.x = _mousePos.x;
			vCurPos.y = _mousePos.y;
		}

		//Rectangle(hdc
		//	, (int)(vCurPos.x - temp)
		//	, (int)(vCurPos.y - temp)
		//	, (int)(vCurPos.x + temp)
		//	, (int)(vCurPos.y + temp));
		switch (GetRequestRankType())
		{
			case RequestRank::BRONZE:
				hrequest1 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\guilddocu\\bronze_quest.bmp");
				break;
			case RequestRank::SILVER:
				hrequest1 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\guilddocu\\silverquest.bmp");
				break;
			case RequestRank::GOLD:
				hrequest1 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\guilddocu\\gold_quest.bmp");
				break;
			case RequestRank::PLATINUM:
				hrequest1 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\guilddocu\\platinum_quest.bmp");
				break;
			default:
				hrequest1 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\guilddocu\\bronze_quest.bmp");
				break;
		}

		GET_SINGLE(InputManager)->SetIsRequestOntheDesk(false);

		SetScale(Vec2(100, 100));
		//if(GetIsClicked())
		//	SetPos(Vec2(_mousePos.x - vCurScale.x / 2, _mousePos.y - vCurScale.y / 2));
		GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hrequest1, (int)vCurPos.x, (int)vCurPos.y, isVisivle);
	}

	//HBITMAP hBitmap2 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\Dummy\\d_request(board).bmp");
	//if (_hoverCheck)
	//	GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hrequest1, vCurPos.x + 20, vCurPos.y, name.c_str(), 24);



	SetTextColor(hdc, RGB(0, 255, 0));

	/// 호버링 중인가에 대한 디버깅 정보 출력 ////////////////
	if (InputManager::GetInstance()->GetIsRenderDebug() == true)
	{
		if (_hoverCheck == true)
		{
			TextOut(hdc, (int)vCurPos.x, (int)vCurPos.y, L"Hover", (int)wcslen(L"Hover"));
		}
		else
		{
			TextOut(hdc, (int)vCurPos.x, (int)vCurPos.y, L"None", (int)wcslen(L"Hover"));
		}
		TextOut(hdc, (int)vCurPos.x, (int)(vCurPos.y + 25), L"layer: ", (int)wcslen(L"layer: "));
		TextOut(hdc, (int)(vCurPos.x + 80), (int)(vCurPos.y + 25), to_wstring(GetDepth()).c_str(), 4);
		TextOut(hdc, (int)vCurPos.x, (int)(vCurPos.y + 50), L"money: ", (int)wcslen(L"money: "));
		TextOut(hdc, (int)(vCurPos.x + 95), (int)(vCurPos.y + 50), to_wstring(GetRequestMoney()).c_str(), 4);
		TextOut(hdc, (int)vCurPos.x, (int)(vCurPos.y + 75), L"ID: ", (int)wcslen(L"ID: "));
		TextOut(hdc, (int)(vCurPos.x + 40), (int)(vCurPos.y + 75), to_wstring(GetRequestID()).c_str(), 4);

		TextOut(hdc, (int)vCurPos.x, (int)(vCurPos.y + 100), L"RANK: ", (int)wcslen(L"RANK: "));
		TextOut(hdc, (int)(vCurPos.x + 70), (int)(vCurPos.y + 100), to_wstring((int32)GetRequestRankType()).c_str(), 4);

		TextOut(hdc, (int)vCurPos.x, (int)(vCurPos.y + 100), L"STATE: ", (int)wcslen(L"STATE: "));
		TextOut(hdc, (int)(vCurPos.x + 70), (int)(vCurPos.y + 100), to_wstring((int32)GetObjectState()).c_str(), 4);

		TextOut(hdc, 600, 300, L"의뢰서 주기", (int)wcslen(L"의뢰서 주기"));
		TextOut(hdc, 600, 600, L"의뢰서 주기", (int)wcslen(L"의뢰서 주기"));
		TextOut(hdc, 1000, 300, L"의뢰서 주기", (int)wcslen(L"의뢰서 주기"));
		TextOut(hdc, 1000, 600, L"의뢰서 주기", (int)wcslen(L"의뢰서 주기"));


	}
	SetTextColor(hdc, RGB(0, 0, 0));
	/// //////////////////////////////////////////////////
}

void ORequest::OnPicking()
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int32 curDepth = GetDepth();

	//_script = GetScript();

	_mousePos = GET_SINGLE(InputManager)->GetMouseCursorPosition();

	_hoverCheck = GET_SINGLE(InputManager)->HoverCheck((int)(vPos.x - temp), (int)(vPos.y - temp), (int)(vScale.x + temp), (int)(vScale.y + temp), _mousePos);


	//if (GetIsClicked() == true)
	//{
	//	_hoverCheck = false;
	//}
	if (IsHolding())
		temp = 3000;
	else
		temp = 0;

	if (_hoverCheck || IsHolding())
	{
		if (KEY_TAP(KEY::LMB))
		{
			/*if (GetObjectState() == ObjectState::WAS_ON_THE_DESK)
			{

			}*/
			m_vDragStart = _mousePos;
			SetDepth(InputManager::GetInstance()->GetNowDepth());
			SetHolding(true);
			InputManager::GetInstance()->SetHoldingDepth(m_depth);
		}

		if (KEY_HOLD(KEY::LMB))
		{
			SetIsFocused(true);
			if (InputManager::GetInstance()->GetHoldingDepth() == m_depth)
			{
				if (GetObjectState() == ObjectState::WAS_ON_THE_DESK)
				{
					vPos.x = _mousePos.x - 50;
					vPos.y = _mousePos.y - 50;
				}
				else
				{
					Vec2 vDiff = _mousePos - m_vDragStart;
					vPos = vPos + vDiff;
				}
				m_vDragStart = _mousePos;
				//vPos.x -= 500.f * DT;
			}
		}

		if (KEY_AWAY(KEY::LMB))
		{
			if (GetObjectState() == ObjectState::WAS_ON_THE_DESK)
				SetObjectState(ObjectState::OUT_OF_DESK);
			SetHolding(false);
			// 캐릭터의 좌표에 마우스 포인터가 위치한다면 의뢰 전달 완료! 다음 인물로 넘어가게 하기
			/// 승인 또는 거절 버튼을 누른 상태에서 전달해야 함
			// _mousePos.x >= 600 && _mousePos.x <= 1000 && _mousePos.y >= 300 && _mousePos.y <= 600
			if (vPos.x + vScale.x / 2 >= 600 && vPos.x + vScale.x / 2 <= 1000 && vPos.y + vScale.y / 2 >= 300 && vPos.y + vScale.y / 2 <= 600)
			{
				if ((GET_SINGLE(VectorManager)->GetIsRequestReturned() == false) && isVisivle != 0)
				{
					GET_SINGLE(VectorManager)->SetIsRequestReturned(true);

					GET_SINGLE(VectorManager)->SetRequestMoney(GetRequestMoney());
					GET_SINGLE(VectorManager)->SetRequestID(GetRequestID());
					//SetAlpha(0);
					isVisivle = 0;

					//TextOut(hdc, vCurPos.x + 40, vCurPos.y + 75, to_wstring(GetRequestID()).c_str(), 4);

					OutputDebugString(TEXT("*************의뢰 전달 완료!!****************"));
					OutputDebugString(TEXT("\n"));
					OutputDebugString(TEXT("전달된 의뢰의 보수: "));
					OutputDebugString(to_wstring((GET_SINGLE(VectorManager)->GetRequestMoney())).c_str());
					OutputDebugString(TEXT("\n"));
					OutputDebugString(TEXT("전달된 의뢰의 ID: "));
					OutputDebugString(to_wstring((GET_SINGLE(VectorManager)->GetRequestID())).c_str());
					OutputDebugString(TEXT("\n"));


					/// TO DO: 투명해진 문서들은 클릭되지 않게 변경하기------ 
					SetPos(Vec2(-100, -100));
				}
				//delete this; // -> 방법을 좀 더 찾아 볼 것


			}

			InputManager::GetInstance()->SetHoldingDepth(-1);
		}
	}
	//else
	//{
	//	SetDepth(0);
	//}

	if (((_mousePos.x >= 1450) == false) && ((vPos.x < -50) == false) && ((vPos.y <= 0) == false))
	{
		if (IsHolding() == true)
		{
			SetPos(vPos);
		}
	}
	else
	{
		SetHolding(false);
	}



}

void ORequest::OnCollisionEnter(Collider* _pOther)
{
	Object* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"Table")
	{
		test = true;
		OutputDebugString(TEXT("Collision ENTER"));
	}
}

void ORequest::OnCollisionExit(Collider* _pOther)
{
	Object* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"Table")
	{
		test = false;
		OutputDebugString(TEXT("Collision EXIT"));
	}
}


