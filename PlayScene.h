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
	//타이머 변수
	float timerTime = 0;
	float sec = 2;
	bool isWaiting = false; //기다림

	int32 status = 100; // 현재 상태
	int32 scriptNum = 0; //대사 시작
	int32 buttonCheck = 0; //버튼체크
	int32 characterChange = 0; // 사람 변경
	
	int32 bargainCount = 1;

	bool bargainButtonClick = false; // 흥정버튼 체크
	bool applyButtonClick = false; // 승인버튼 체크
	bool approvalButtonClick = false; // 수락 버튼 체크
	bool refuseButtonClick = false; // 거절 버튼 체크
	bool isRequestGet = false; // 종이 받았는지와 버튼 체크
	
	bool bargainButtonActive = true; // 활성화체크
	bool applyButtonActive = true; // 활성화체크	
	bool approvalButtonActive = true; // 활성화체크
	bool refuseButtonActive = true; // 활성화체크

	bool isBlank = false; // 대화창 넘기기
	bool isClick = false; //전반적인 화면 넘기기용 함수

	bool isTableBlank = false; // 테이블 비어있는지 확인용 함수

	//페이드 인 아웃 함수
	int32 alphaFadeIn = 0;
	int32 alphaFadeOut = 255;

	// 의뢰 오브젝트들
	Object* requestObj_1 = nullptr;
	Object* requestObj_2 = nullptr;
	Object* requestObj_3 = nullptr;
	Object* requestObj_4 = nullptr;
	Object* requestObj_5 = nullptr;
	Object* requestObj_6 = nullptr;
	Object* requestObj_7 = nullptr;
	Object* goddnessRequestObj = nullptr;

	// ID카드 오브젝트
	Object* idCardObj = nullptr;

	// 임무일지 오브젝트들
	Object* partyListObj = nullptr;
	Object* weaponListObj = nullptr;

	int32 _year = 0;
};

