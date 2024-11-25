#include "pch.h"
#include "OIDCard.h"
#include "ResourceManager.h"
#include "Collider.h"
#include "InputManager.h"

OIDCard::OIDCard()
{
	//CreateCollider();
	//GetCollider()->SetOffsetPos(Vec2(0.f, 0.f));
	//GetCollider()->SetScale(Vec2(350.f, 210.f));
	SetScale(Vec2(350, 200));
	SetObjectState(ObjectState::ON_THE_DESK);

}

OIDCard::~OIDCard()
{

}


void OIDCard::Update()
{
//	//isVisivle = GetAlpha();
//	Vec2 vPos = GetPos();
//	Vec2 vScale = GetScale();
//	int32 curDepth = GetDepth();
//
//	_mousePos = GET_SINGLE(InputManager)->GetMouseCursorPosition();
//
//	_hoverCheck = GET_SINGLE(InputManager)->HoverCheck(vPos.x - temp, vPos.y - temp, vScale.x + temp, vScale.y + temp, _mousePos);
//
//	if (IsHolding())
//		temp = 3000;
//	else
//		temp = 0;
//
//	if (_hoverCheck || IsHolding())
//	{
//		if (KEY_TAP(KEY::LMB))
//		{
//			SetDepth(1);
//			m_vDragStart = _mousePos;
//			SetHolding(true);
//		}
//		if (KEY_HOLD(KEY::LMB))
//		{
//			Vec2 vDiff = _mousePos - m_vDragStart;
//
//			vPos = vPos + vDiff;
//
//			m_vDragStart = _mousePos;
//
//			//vPos.x -= 500.f * DT;
//		}
//		if (KEY_AWAY(KEY::LMB))
//		{
//			SetDepth(1);
//			SetHolding(false);
//
//			// 캐릭터의 좌표에 마우스 포인터가 위치한다면 의뢰 전달 완료! 다음 인물로 넘어가게 하기
//			/// 승인 또는 거절 버튼을 누른 상태에서 전달해야 함
//			if (_mousePos.x >= 600 && _mousePos.x <= 1000 && _mousePos.y >= 300 && _mousePos.y <= 600)
//			{
//				isVisivle = 0;
//				//TextOut(hdc, 6800, 400, L"의뢰 전달 완료!", wcslen(L"의뢰 전달 완료!"));
//			}
//		}
//	}
//	else
//	{
//		SetDepth(0);
//	}
//	if ((curDepth == 1) && IsHolding())
//	{
//		SetPos(vPos);
//	}
//	else
//	{
//		SetHolding(false);
//	}
}

void OIDCard::Render(HDC hdc)
{
	Vec2 vCurPos = GetPos();
	Vec2 vScale = GetScale();

	CharacterName cName = GetCharacterName();

	HBITMAP idCard;

	_mousePos = GET_SINGLE(InputManager)->GetMouseCursorPosition();

	Vec2 rq = this->GetPos();


	/// 모험가 카드가 책상 밖으로 빠져 나갔을 때
	if ((rq.y + vScale.y / 1.5 >= 680) == false)
	{
		if (GetObjectState() == ObjectState::ON_THE_DESK)
		{
			SetObjectState(ObjectState::WAS_ON_THE_DESK);
			vCurPos.x = _mousePos.x;
			vCurPos.y = _mousePos.y;
		}

		idCard = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\guild_document\\small_ID.bmp");
		GET_SINGLE(InputManager)->SetIsIDcardOntheDesk(false);
		SetScale(Vec2(105, 70));
	}
	/// 모험가 카드가 책상 안에 있을 때
	else
	{
		SetObjectState(ObjectState::ON_THE_DESK);

		SetScale(Vec2(350, 200));
		GET_SINGLE(InputManager)->SetIsIDcardOntheDesk(true);
		switch (cName)
		{
		case CharacterName::catfighter1:
		{
			idCard = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\card_ID\\ELLENA.bmp");
			break;
		}
		case CharacterName::catfighter2:
		{
			idCard = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\card_ID\\ELLY.bmp");
			break;
		}
		case CharacterName::dwarf_1:
		{
			idCard = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\card_ID\\GROMME.bmp");
			break;
		}
		case CharacterName::dwarf_2:
		{
			idCard = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\card_ID\\GRAZY.bmp");
			break;
		}
		case CharacterName::herbalist1:
		{
			idCard = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\card_ID\\PEBEREL.bmp");
			break;
		}
		case CharacterName::herbalist2:
		{
			idCard = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\card_ID\\FINELO.bmp");
			break;
		}
		case CharacterName::herbalist3:
		{
			idCard = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\card_ID\\ROY.bmp");
			break;
		}
		case CharacterName::herbalist4:
		{
			idCard = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\card_ID\\EDRIC.bmp");
			break;
		}
		case CharacterName::ninza1:
		{
			idCard = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\card_ID\\GENZI.bmp");
			break;
		}
		case CharacterName::ninza2:
		{
			idCard = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\card_ID\\LOAD.bmp");
			break;
		}
		case CharacterName::lilian:
		{
			idCard = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\card_ID\\LYLIAN.bmp");
			break;
		}
		case CharacterName::eden:
		{
			idCard = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\card_ID\\EDEN.bmp");
			break;
		}
		case CharacterName::darius:
		{
			idCard = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\card_ID\\DARIOUS.bmp");
			break;
		}
		default:
			idCard = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\card_ID\\DARIOUS.bmp");
		}
	}

	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, idCard, (int)vCurPos.x, (int)vCurPos.y, isVisivle);

	SetTextColor(hdc, RGB(0, 255, 0));

	/// 호버링 중인가에 대한 디버깅 정보 출력
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
		TextOut(hdc, (int)(vCurPos.x + 20), (int)(vCurPos.y + 25), to_wstring(GetDepth()).c_str(), 4);
		TextOut(hdc, (int)(vCurPos.x + 20), (int)(vCurPos.y + 50), L"STATE: ", (int)wcslen(L"STATE: "));
		TextOut(hdc, (int)(vCurPos.x + 90), (int)(vCurPos.y + 50), to_wstring((int32)GetObjectState()).c_str(), 4);

	}

	SetTextColor(hdc, RGB(0, 0, 0));


}

void OIDCard::OnPicking()
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int32 curDepth = GetDepth();

	isVisivle = GetAlpha();

	_mousePos = GET_SINGLE(InputManager)->GetMouseCursorPosition();

	_hoverCheck = GET_SINGLE(InputManager)->HoverCheck((int)(vPos.x - temp), (int)(vPos.y - temp), (int)(vScale.x + temp), (int)(vScale.y + temp), _mousePos);

	/// if 등장인물이 바뀌었다면!!
	/// isVisivle = 255 로 바꾸고
	/// SetPos 로 위치 처음위치로 초기화
	/// 모험가 카드를 돌려주었는지를 false 로 초기화
	/// 

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
			GET_SINGLE(ResourceManager)->PlayEffect(15);
			SetDepth(InputManager::GetInstance()->GetNowDepth());
			m_vDragStart = _mousePos;
			SetHolding(true);
			InputManager::GetInstance()->SetHoldingDepth(m_depth);
		}

		if (KEY_HOLD(KEY::LMB))
		{
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
			if (vPos.x + vScale.x / 2 >= 600 && vPos.x + vScale.x / 2 <= 1000 && vPos.y + vScale.y / 2 >= 300 && vPos.y + vScale.y / 2 <= 600)
			{				
				if ((GET_SINGLE(VectorManager)->GetIsIDCardReturned() == false) && isVisivle != 0)
				{
					GET_SINGLE(ResourceManager)->PlayEffect(7);
					GET_SINGLE(VectorManager)->SetIsIDCardReturned(true);

					isVisivle = 0;
					if (GetAlpha() != 0)
						SetAlpha(0);
					OutputDebugString(TEXT("*************모험가 카드 돌려줌!!****************"));
					OutputDebugString(TEXT("\n"));

					SetPos(Vec2(0, 0));
				}
			}
			InputManager::GetInstance()->SetHoldingDepth(-1);
		}
	}
	//else
	//{
	//	SetDepth(0);
	//}
	if (((_mousePos.x >= 1450) == false) && ((vPos.x < -100) == false) && ((vPos.y < -20) == false))
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

