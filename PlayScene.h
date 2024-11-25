#pragma once
#include "Scene.h"

class Quest;
class Object;

class PlayScene : public Scene
{

public:
	/*
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	*/

	virtual void Start();
	virtual void Exit();

	virtual void Update();
	
	unordered_map<wstring, Quest> questMap;
	vector<Object*> request;
	bool Timer(float deltaTime);

public:
	PlayScene();
	virtual ~PlayScene();

public : 
	//Ÿ�̸� ����
	float timerTime = 0;
	float sec = 2;
	bool isWaiting = false; //��ٸ�

	int32 status = 100; // ���� ����
	int32 scriptNum = 0; //��� ����
	int32 buttonCheck = 0; //��ưüũ
	int32 characterChange = 0; // ��� ����
	
	int32 bargainCount = 1;

	bool bargainButtonClick = false; // ������ư üũ
	bool applyButtonClick = false; // ���ι�ư üũ
	bool approvalButtonClick = false; // ���� ��ư üũ
	bool refuseButtonClick = false; // ���� ��ư üũ
	bool isRequestGet = false; // ���� �޾Ҵ����� ��ư üũ
	
	bool bargainButtonActive = true; // Ȱ��ȭüũ
	bool applyButtonActive = true; // Ȱ��ȭüũ	
	bool approvalButtonActive = true; // Ȱ��ȭüũ
	bool refuseButtonActive = true; // Ȱ��ȭüũ

	bool isBlank = false; // ��ȭâ �ѱ��
	bool isClick = false; //�������� ȭ�� �ѱ��� �Լ�

	bool isTableBlank = false; // ���̺� ����ִ��� Ȯ�ο� �Լ�

	//���̵� �� �ƿ� �Լ�
	int32 alphaFadeIn = 0;
	int32 alphaFadeOut = 255;

	// �Ƿ� ������Ʈ��
	Object* requestObj_1 = nullptr;
	Object* requestObj_2 = nullptr;
	Object* requestObj_3 = nullptr;
	Object* requestObj_4 = nullptr;
	Object* requestObj_5 = nullptr;
	Object* requestObj_6 = nullptr;
	Object* requestObj_7 = nullptr;
	Object* goddnessRequestObj = nullptr;

	// IDī�� ������Ʈ
	Object* idCardObj = nullptr;

	// �ӹ����� ������Ʈ��
	Object* partyListObj = nullptr;
	Object* weaponListObj = nullptr;

	int32 _year = 0;
};

