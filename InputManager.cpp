#include "pch.h"
#include "InputManager.h"
#include "ObjectManager.h"

int32 g_ArrVK[(int32)KEY::LAST] =
{
	VK_LBUTTON,//LMB,
	VK_RBUTTON,//RMB,
	VK_ESCAPE,//ESC
	VK_UP,
	VK_DOWN,

	//LAST
};

void InputManager::Init(HWND hwnd)
{
	_hwnd = hwnd;
	for (int32 i = 0; i < (int32)KEY::LAST; ++i)
	{
		m_vecKey.push_back(tKeyInfo{ KEY_STATE::NONE, false });
	}

	//m_vecKey[(int)KEY::LMB].eState;
	//m_vecKey[(int)KEY::LMB].bPrev;

	m_IsRenderDebug = false;
	m_nowDepth = 10000;
	m_holdingDepth = -1;
}

void InputManager::Update()
{
	// 윈도우 포커싱 알아내기
	HWND i_hwnd = GetFocus();

	// 윈도우 포커싱 중일 때 키 이벤트 동작
	if (nullptr != i_hwnd)
	{
		for (int32 i = 0; i < (int32)KEY::LAST; ++i)
		{
			// 키가 눌려있다.
			if (GetAsyncKeyState(g_ArrVK[i]) & 0x8000)
			{
				if (m_vecKey[i].bPrevPush)
				{
					// 이전에도 눌려있었다.
					m_vecKey[i].eState = KEY_STATE::HOLD;
				}
				else
				{
					// 이전에 눌려있지 않았다.
					m_vecKey[i].eState = KEY_STATE::TAP;
				}
				m_vecKey[i].bPrevPush = true;
			}
			// 키가 안눌려있다.
			else
			{
				if (m_vecKey[i].bPrevPush)
				{
					// 이전에 눌려있었다.
					m_vecKey[i].eState = KEY_STATE::AWAY;
				}
				else
				{
					// 이전에도 안눌려있었다.
					m_vecKey[i].eState = KEY_STATE::NONE;
				}
				m_vecKey[i].bPrevPush = false;
			}
		}
	}
	// 윈도우 포커싱 해제상태
	else
	{
		for (int32 i = 0; i < (int32)KEY::LAST; ++i)
		{
			m_vecKey[i].bPrevPush = false;

			if (KEY_STATE::TAP == m_vecKey[i].eState || KEY_STATE::HOLD == m_vecKey[i].eState)
			{
				m_vecKey[i].eState = KEY_STATE::AWAY;
			}
			else if (KEY_STATE::AWAY == m_vecKey[i].eState)
			{
				m_vecKey[i].eState = KEY_STATE::NONE;
			}
		}
	}

	if (GetAsyncKeyState(VK_F1) & 0x0001)
	{
		m_IsRenderDebug = !m_IsRenderDebug;
	}
}

Vec2 InputManager::GetMouseCursorPosition()
{
	POINT cursorPos;
	Vec2 pos;
	HWND hwnd = GetHwnd();
	if (GetCursorPos(&cursorPos))
	{
		// 스크린 좌표를 클라이언트 좌표로 변환
		ScreenToClient(hwnd, &cursorPos);

		pos.x = (float)cursorPos.x;
		pos.y = (float)cursorPos.y;
	}

	return pos;
}

bool InputManager::ButtonClick(int32 x, int32 y, int32 width, int32 height, Vec2 pos)
{

	if (pos.x >= x && pos.x <= x + width && pos.y >= y && pos.y <= y + height)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool InputManager::HoverCheck(int32 x, int32 y, int32 width, int32 height, Vec2 pos)
{
	bool isPlayerWait = GET_SINGLE(ObjectManager)->GetPlayerWaitState();
	if (isPlayerWait)
	{
		if (pos.x >= x && pos.x <= x + width && pos.y >= y && pos.y <= y + height)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	else
	{
		return false;
	}
}

bool InputManager::IsDeskEmpty()
{
	isRequestOntheDesk;
	isIDcardOntheDesk;
	isDocumentOntheDesk;
	if ((isRequestOntheDesk == false) && (isIDcardOntheDesk == false) ) //&& (isDocumentOntheDesk == false)
	{
		OutputDebugString(TEXT("@@@@@@@@@@@@책상이 비었다@@@@@@@@@@@"));
		OutputDebugString(TEXT("\n"));
		return true;
	}

	return false;
}



int32 InputManager::GetNowDepth()
{
	return --m_nowDepth;
}
