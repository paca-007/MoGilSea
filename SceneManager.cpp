#include "pch.h"
#include "SceneManager.h"
#include "PlayScene.h"
#include "StartScene.h"
#include "EventManager.h"
#include "FeedbackScene.h"
#include "EndingScene.h"
#include "OpeningScene.h"

/*
SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{

}
*/

void SceneManager::Init()
{
	//¾À »ı¼º
	//¸ŞÀÎ¾À
	_sceneArr[(int32)SceneType::PLAYSCENE] = new PlayScene;
	_sceneArr[(int32)SceneType::PLAYSCENE]->SetName(L"PlayScene");

	//½ÃÀÛ¾À
	_sceneArr[(int32)SceneType::STARTSCENE] = new StartScene;
	_sceneArr[(int32)SceneType::STARTSCENE]->SetName(L"StartScene");

	//¿ÀÇÁ´×¾À
	_sceneArr[(int32)SceneType::OPENING] = new OpeningScene;
	_sceneArr[(int32)SceneType::OPENING]->SetName(L"OpeningScene");

	//ÇÇµå¹é¾À
	_sceneArr[(int32)SceneType::FEEDBACKSCENE] = new FeedbackScene;
	_sceneArr[(int32)SceneType::FEEDBACKSCENE]->SetName(L"FeedbackScene");

	//¿£µù¾À
	_sceneArr[(int32)SceneType::ENDING] = new EndingScene;
	_sceneArr[(int32)SceneType::ENDING]->SetName(L"EndingScene");

	//ÇöÀç ¾À ÁöÁ¤
	_scene = _sceneArr[(int32)SceneType::STARTSCENE];
	_scene->Start();
}

void SceneManager::Update()
{
	if (_scene)
	{
		_scene->Update();

		_scene->FinalUpdate();
	}
}

void SceneManager::Render(HDC hdc)
{

	if (_scene)
	{
		_scene->Render(hdc);
	}
}

void SceneManager::Clear()
{
	SAFE_DELETE(_scene);
}

void SceneManager::ChangeScene(SceneType _eNext)
{
	_scene->Exit();
	
	_scene = _sceneArr[(int32)_eNext];

	_scene->Start();
}
