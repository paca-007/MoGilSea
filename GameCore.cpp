#include "pch.h"
#include "GameCore.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "ObjectManager.h"
#include "CollisionManager.h"
#include "VectorManager.h"
#include "StartScene.h"

GameCore::GameCore()
	: m_arrBrush{}
	, m_arrPen{}
{

}

GameCore::~GameCore()
{
	// 마지막에 하기
	GET_SINGLE(SceneManager)->Clear();
	GET_SINGLE(ResourceManager)->Clear();
	GET_SINGLE(ObjectManager)->Clear();


	for (int i = 0; i < (int32)PenType::END; ++i)
	{
		DeleteObject(m_arrPen[i]);
	}

	_CrtDumpMemoryLeaks();
}

void GameCore::Init(HWND hwnd)
{
	_hwnd = hwnd;
	StartScene::SetHWND(_hwnd);
	_hdc = GetDC(_hwnd);

	GetClientRect(_hwnd, &_rect);

	_hdcBack = CreateCompatibleDC(_hdc);
	_bmpBack = CreateCompatibleBitmap(_hdc, _rect.right, _rect.bottom);
	HBITMAP prev = (HBITMAP)SelectObject(_hdcBack, _bmpBack);
	DeleteObject(prev);

	// 자주 사용할 펜 및 브러쉬 생성
	CreateBrushPen();
	GET_SINGLE(ResourceManager)->Music_Init();
	GET_SINGLE(VectorManager)->Datainit();
	GET_SINGLE(TimeManager)->Init();
	GET_SINGLE(InputManager)->Init(_hwnd);
	GET_SINGLE(ResourceManager)->Init(hwnd, filesystem::path(GET_SINGLE(ResourceManager)->GetCurrentPath()));
	GET_SINGLE(ObjectManager)->Init();
	GET_SINGLE(SceneManager)->Init();
	
	ShowCursor(FALSE);
	// 이전 윈도우 스타일 가져오기
	LONG_PTR prevStyle = GetWindowLongPtr(hwnd, GWL_STYLE);

	// 메뉴창 제거하기
	//SetWindowLongPtr(hwnd, GWL_STYLE, prevStyle & ~(WS_CAPTION | WS_SYSMENU));
	//SetWindowLongPtr(hwnd, GWL_STYLE, prevStyle & ~WS_SYSMENU);
	SetWindowLongPtr(hwnd, GWL_STYLE, WS_VISIBLE | WS_POPUP);
}

void GameCore::Update()
{
	GET_SINGLE(TimeManager)->Update();
	GET_SINGLE(InputManager)->Update();
	GET_SINGLE(CollisionManager)->Update();
	GET_SINGLE(SceneManager)->Update();  
	GET_SINGLE(ResourceManager)->Music_Update();
	//GET_SINGLE(ObjectManager)->ChangePlayEvent();
}

void GameCore::Render()
{
	GET_SINGLE(SceneManager)->Render(_hdcBack);	

	Pos pos = { 100,100 };
	
	// Double Buffering
	BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY);
	PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS);


}		

void GameCore::CreateBrushPen()
{
	// hollow brush
	m_arrBrush[(UINT)BrushType::HOLLOW] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);

	// red, blue, green pen
	m_arrPen[(UINT)PenType::RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	m_arrPen[(UINT)PenType::GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	m_arrPen[(UINT)PenType::BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));

}

