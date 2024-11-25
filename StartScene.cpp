#include "pch.h"
#include "StartScene.h"
#include "OStartBtn.h"
#include"OFeedbackBackground.h"
#include "OExitBtn.h"
#include "OStartBackground.h"
#include "OCredit.h"
#include "OSettingButton.h"

#include "InputManager.h"
#include "ResourceManager.h"

HWND StartScene::hWnd = NULL;

StartScene::StartScene()
{

}

StartScene::~StartScene()
{

}

void StartScene::Start()
{

	//노래 시작
	GET_SINGLE(ResourceManager)->PlayMusicSound(0);
	
	//배경화면
	Object* backObj = new OStartBackground;
	AddObject(backObj, ObjectType::DEFAULT);

	//시작버튼
	Object* startBtnObj = new OStartBtn;
	AddObject(startBtnObj, ObjectType::BUTTON);

	//종료버튼
	Object* exitBtnObj = new OExitBtn;
	AddObject(exitBtnObj, ObjectType::BUTTON);

	//크레딧 버튼
	Object* creditObj = new OCredit;
	AddObject(creditObj, ObjectType::YEAR);

	//설정 버튼
	Object* settingObj = new OSettingButton;
	AddObject(settingObj, ObjectType::BUTTON);
}

void StartScene::Exit()
{
	GET_SINGLE(ResourceManager)->StopSound();
	DeleteAll();
}

void StartScene::Update()
{
	Scene::Update();
	
	Object* _creditObject = arrObj[(int32)ObjectType::YEAR][0];

	//마우스 값 받아오기
	Vec2 _mousePos = GET_SINGLE(InputManager)->GetMouseCursorPosition();

	startButtonClick = StartBtnClick(_mousePos);
	endButtonClick = EndBtnClick(_mousePos);
	creditButtonClick = CreditBtnClick(_mousePos);

	if (startButtonClick == true)
	{
		ChangeScene(SceneType::OPENING);
		startButtonClick = false;
	}

	if (endButtonClick == true)
	{
		Exit();
		DestroyWindow(hWnd);
	}

	if (creditButtonClick == true)
	{
		_creditObject->SetAlpha(255);
		creditButtonClick = false;
	}

	else if (KEY_TAP(KEY::LMB))
	{
		GET_SINGLE(ResourceManager)->PlayEffect(4);
		int alpha = _creditObject->GetAlpha();
		
		if (alpha == 255)
			_creditObject->SetAlpha(0);
	}

}
