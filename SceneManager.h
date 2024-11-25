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
	Scene* _scene; //���� �� ��ȯ
	Scene* _sceneArr[(int32)SceneType::END]; //�����

	void ChangeScene(SceneType _eNext);
	friend class EventManager;

};

