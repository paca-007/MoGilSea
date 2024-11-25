#pragma once

class Scene;

class SceneManager
{
	DECLARE_SINGLE(SceneManager);


public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Clear();
	
	Scene* GetCurrentScene() { return _scene; }
	

private:
	Scene* _scene; //ÇöÀç ¾À ¹ÝÈ¯
	Scene* _sceneArr[(int32)SceneType::END]; //¾À¸ñ·Ï

	void ChangeScene(SceneType _eNext);
	friend class EventManager;

};

