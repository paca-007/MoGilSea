#include "pch.h"
#include "OpeningScene.h"
#include "ResourceManager.h"
#include "OOpeningFullScreen.h"
#include "OOpeningPhoto.h"
#include "OOpeningScript.h"
#include "InputManager.h"


OpeningScene::OpeningScene()
{

}

OpeningScene::~OpeningScene()
{

}

void OpeningScene::Start()
{
	//음악설정
	GET_SINGLE(ResourceManager)->PlayMusicSound(1);

	//뒤에 화면
	Object* openingObj = new OOpeningFullScreen;
	AddObject(openingObj, ObjectType::DEFAULT);

	//메인 그림
	Object* photoObj = new OOpeningPhoto;
	AddObject(photoObj, ObjectType::DEFAULT);

	//스크립트 그림
	Object* scriptObj = new OOpeningScript;
	AddObject(scriptObj, ObjectType::SCRIPT);

}

void OpeningScene::Exit()
{
	DeleteAll();
	GET_SINGLE(ResourceManager)->StopSound();
}

void OpeningScene::Update()
{
	Scene::Update();
	Object* _photoObject = arrObj[(int32)ObjectType::DEFAULT][1];
	Object* _scriptObject = arrObj[(int32)ObjectType::SCRIPT][0];

	if (KEY_TAP(KEY::LMB))
	{
		GET_SINGLE(ResourceManager)->PlayEffect(4);
		if (scriptNum == 1)
		{
			isTwo = false;
			_scriptObject->SetendingScript(scriptNum -= 1);
		}

		else if (Scenenum == 1)
		{
			isTwo = true;
		}

		if (isTwo == true)
		{
			scriptNum = _scriptObject->GetendingScript();
			_scriptObject->SetendingScript(scriptNum += 1);
			Scenenum--;
		}

		Scenenum++;

	}

	else
	{
		if (Scenenum == 0)
		{
			_photoObject->SetOpeningType(OpeningSceneType::ONE);
			_scriptObject->SetOpeningType(OpeningSceneType::ONE);
		}

		if (Scenenum == 1)
		{
			_photoObject->SetOpeningType(OpeningSceneType::TWO);
			_scriptObject->SetOpeningType(OpeningSceneType::TWO);

		}

		if (Scenenum == 2)
		{
			_photoObject->SetOpeningType(OpeningSceneType::THREE);
			_scriptObject->SetOpeningType(OpeningSceneType::THREE);
		}
		if (Scenenum == 3)
		{
			_photoObject->SetOpeningType(OpeningSceneType::FOUR);
			_scriptObject->SetOpeningType(OpeningSceneType::FOUR);
		}
		if (Scenenum == 4)
		{
			_photoObject->SetOpeningType(OpeningSceneType::FIVE);
			_scriptObject->SetOpeningType(OpeningSceneType::FIVE);
		}
	}

	if (Scenenum == 5)
	{
		ChangeScene(SceneType::PLAYSCENE);
	}
}

