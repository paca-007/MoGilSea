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

	//�뷡 ����
	GET_SINGLE(ResourceManager)->PlayMusicSound(0);
	
	//���ȭ��
	Object* backObj = new OStartBackground;
	AddObject(backObj, ObjectType::DEFAULT);

	//���۹�ư
	Object* startBtnObj = new OStartBtn;
	AddObject(startBtnObj, ObjectType::BUTTON);

	//�����ư
	Object* exitBtnObj = new OExitBtn;
	AddObject(exitBtnObj, ObjectType::BUTTON);

	//ũ���� ��ư
	Object* creditObj = new OCredit;
	AddObject(creditObj, ObjectType::YEAR);

	//���� ��ư
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

	//���콺 �� �޾ƿ���
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
