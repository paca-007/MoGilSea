#include "pch.h"
#include "EndingScene.h"
#include "OFullScreen.h"
#include "OEndingPhoto.h"
#include "OEndingScript.h"
#include "ResourceManager.h"
#include "ONextBtn.h"
#include "InputManager.h"
#include "ONPCEnding.h"

EndingScene::EndingScene()
{

}

EndingScene::~EndingScene()
{

}

void EndingScene::Start()
{
	//음악설정
	GET_SINGLE(ResourceManager)->PlayMusicSound(4);

	//뒤에 화면
	Object* backObj = new OFullScreen;
	AddObject(backObj, ObjectType::DEFAULT);

	//메인 그림
	Object* photoObj = new OEndingPhoto;
	AddObject(photoObj, ObjectType::DEFAULT);

	//스크립트 그림
	Object* scriptObj = new OEndingScript;
	AddObject(scriptObj, ObjectType::SCRIPT);

	//NPC 그림
	Object* npcEndingObj = new ONPCEnding;
	AddObject(npcEndingObj, ObjectType::SCREENFRAME);

}

void EndingScene::Exit()
{
	DeleteAll();
	GET_SINGLE(ResourceManager)->StopSound();
}

void EndingScene::Update()
{
	Scene::Update();

	Object* _photoObject = arrObj[(int32)ObjectType::DEFAULT][1];
	Object* _scriptObject = arrObj[(int32)ObjectType::SCRIPT][0];
	Object* _npcEndingObject = arrObj[(int32)ObjectType::SCREENFRAME][0];

	int32 money = GET_SINGLE(VectorManager)->GetTotalMoney();
	int32 fame = GET_SINGLE(VectorManager)->GetTotalFame();
	int32 coreClear = GET_SINGLE(VectorManager)->GetCore();

	if (coreClear == 0 || coreClear == 1 || coreClear == 2)
	{
		coreFlag = true;
		if (scriptNum >= 3)
		{
			_npcEndingObject->SetAlpha(255);
		}
	}

	if (KEY_TAP(KEY::LMB))
	{
		scriptNum = _scriptObject->GetendingScript();
		_scriptObject->SetendingScript(scriptNum += 1);

	}

	else
	{
		///END1
		if (money >= 10000 && coreFlag == true)
		{
			_photoObject->SetEndingType(EndingSceenType::END_1);
			_scriptObject->SetEndingType(EndingSceenType::END_1);
		}

		///END2
		if (money < 10000 && fame >= 50 && coreFlag == true)
		{
			_photoObject->SetEndingType(EndingSceenType::END_2);
			_scriptObject->SetEndingType(EndingSceenType::END_2);
		}

		///END3
		if (money < 10000 && fame < 50 && coreFlag == true)
		{
			_photoObject->SetEndingType(EndingSceenType::END_3);
			_scriptObject->SetEndingType(EndingSceenType::END_3);
		}

		///END4
		if (money >= 10000 && coreFlag == false)
		{
			_photoObject->SetEndingType(EndingSceenType::END_4);
			_scriptObject->SetEndingType(EndingSceenType::END_4);
		}

		///END5
		if (money < 10000 && fame >= 50 && coreFlag == false)
		{
			_photoObject->SetEndingType(EndingSceenType::END_5);
			_scriptObject->SetEndingType(EndingSceenType::END_5);
		}

		///END6
		if (money < 10000 && fame < 50 && coreFlag == false)
		{
			_photoObject->SetEndingType(EndingSceenType::END_6);
			_scriptObject->SetEndingType(EndingSceenType::END_6);
		}
	}

	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{
		ChangeScene(SceneType::STARTSCENE);
	}
}

