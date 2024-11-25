#include "pch.h"
#include "PlayScene.h"
#include "Object.h"
#include "OTable.h"
#include "OBackground.h"
#include "OCharacter.h"
#include "OScript.h"
#include "OBoard.h"
#include "OLogo.h"
#include "OYear.h"
#include "OWaiting.h"
#include "OCharge.h"
#include "OMoney.h"
#include "OFame.h"
#include "OBargainBtn.h"
#include "OApplyBtn.h"
#include "OApprovalBtn.h"
#include "ORefuseBtn.h"
#include "OTimer.h"
#include "Adventurer.h"
#include "ORequest.h"
#include "OPartyList.h"
#include "OWeaponList.h"
#include "OIDCard.h"
#include "ORequestPaper.h"
#include "OScreenFrame.h"

#include "TimeManager.h"
#include "CollisionManager.h"
#include "ResourceManager.h"
#include "VectorManager.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "ResourceManager.h"
#include "ObjectManager.h"

class Quest;

PlayScene::PlayScene()
{

}

PlayScene::~PlayScene()
{

}

void PlayScene::Start()
{
	///년차별 값 변경
	int32 year = GET_SINGLE(VectorManager)->GetYear();

	if (year == 1)
	{
		characterChange = 0;
	}
	if (year == 2)
	{
		characterChange = 8;
	}
	if (year == 3)
	{
		characterChange = 16;
	}

	//초기화 해야됨
	//타이머 변수
	timerTime = 0;
	sec = 2;
	isWaiting = false; //대기열

	status = 0; // 현재 상태
	scriptNum = 0; //대사 시작
	buttonCheck = 0; //버튼체크
	status = 100;
	scriptNum = 0;
	bargainCount = 1;
	alphaFadeIn = 0;
	alphaFadeOut = 255;



	//Quest 받아옴
	questMap = GET_SINGLE(ObjectManager)->GetQuestMap();
	int32 posX = 75;
	int32 posY = 120;
	int32 count = 0;

	//background
	Object* backObj = new OBackground;
	AddObject(backObj, ObjectType::DEFAULT);

	//ScreenFrame
	Object* screenFrameObj = new OScreenFrame;
	AddObject(screenFrameObj, ObjectType::SCREENFRAME);

	//character
	Object* charaObj = new OCharacter;
	AddObject(charaObj, ObjectType::Character);

	//Script
	Object* scriptObj = new OScript;
	AddObject(scriptObj, ObjectType::SCRIPT);

	//board
	Object* boardObj = new OBoard;
	AddObject(boardObj, ObjectType::DEFAULT);

	//Table
	Object* tableObj = new OTable;
	tableObj->SetName(L"Table");
	AddObject(tableObj, ObjectType::Table);

	//Logo
	Object* logoObj = new OLogo;
	AddObject(logoObj, ObjectType::DEFAULT);

	//Year
	Object* yearObj = new OYear;
	AddObject(yearObj, ObjectType::YEAR);

	//Waiting
	Object* waitingObj = new OWaiting;
	AddObject(waitingObj, ObjectType::WAITING);

	//Charge
	Object* chargeObj = new OCharge;
	AddObject(chargeObj, ObjectType::FEE);

	//Money
	Object* moneyObj = new OMoney;
	AddObject(moneyObj, ObjectType::MONEY);

	//Fame
	Object* fameObj = new OFame;
	AddObject(fameObj, ObjectType::FAME);

	//BargainBtn
	Object* bargainBtnObj = new OBargainBtn;
	AddObject(bargainBtnObj, ObjectType::BUTTON);

	//ApplyBtn
	Object* applyBtnObj = new OApplyBtn;
	AddObject(applyBtnObj, ObjectType::BUTTON);

	//ApprovalBtn
	Object* approvalBtnObj = new OApprovalBtn;
	AddObject(approvalBtnObj, ObjectType::BUTTON);

	//RefuseBtn
	Object* refuseBtnObj = new ORefuseBtn;
	AddObject(refuseBtnObj, ObjectType::BUTTON);



	// 퀘스트 N 개 생성

	requestObj_1 = new ORequest;
	requestObj_1->SetPos(Vec2((float)posX, (float)posY));
	requestObj_1->SetRequestID(0);
	AddObject(requestObj_1, ObjectType::REQUEST);

	requestObj_2 = new ORequest;
	requestObj_2->SetPos(Vec2((float)(posX + 150), (float)posY));
	requestObj_2->SetRequestMoney(3000);
	requestObj_2->SetRequestID(1);
	requestObj_2->SetRequestRankType(RequestRank::BRONZE);
	AddObject(requestObj_2, ObjectType::REQUEST);

	requestObj_3 = new ORequest;
	requestObj_3->SetPos(Vec2((float)posX, (float)(posY + 125)));
	requestObj_3->SetRequestID(2);
	requestObj_3->SetRequestRankType(RequestRank::SILVER);
	AddObject(requestObj_3, ObjectType::REQUEST);

	requestObj_4 = new ORequest;
	requestObj_4->SetPos(Vec2((float)(posX + 150), (float)(posY + 125)));
	requestObj_4->SetRequestID(3);
	requestObj_4->SetRequestRankType(RequestRank::SILVER);
	AddObject(requestObj_4, ObjectType::REQUEST);

	requestObj_5 = new ORequest;
	requestObj_5->SetPos(Vec2((float)posX, (float)(posY + 125 + 125)));
	requestObj_5->SetRequestID(4);
	requestObj_5->SetRequestRankType(RequestRank::SILVER);
	AddObject(requestObj_5, ObjectType::REQUEST);

	requestObj_6 = new ORequest;
	requestObj_6->SetPos(Vec2((float)(posX + 150), (float)(posY + 125 + 125)));
	requestObj_6->SetRequestID(5);
	AddObject(requestObj_6, ObjectType::REQUEST);

	requestObj_7 = new ORequest;
	requestObj_7->SetPos(Vec2((float)posX, (float)(posY + 125 + 125 + 125)));
	requestObj_7->SetRequestID(6);
	AddObject(requestObj_7, ObjectType::REQUEST);

	// 게임진행 3년차에 등장하는 의뢰.
	// 기본 출현상태 false로 설정
	goddnessRequestObj = new ORequest;
	/// TODO : 년차 데이터 읽어와서 1, 2 년차엔 안보이게 설정하기 -> 3년차에 등장!!
	goddnessRequestObj->SetPos(Vec2((float)(posX + 150), (float)(posY + 125 + 125 + 125)));
	//goddnessRequestObj->SetPos(Vec2(0, 0));
	goddnessRequestObj->SetRequestID(7);
	goddnessRequestObj->SetAlpha(0);
	AddObject(goddnessRequestObj, ObjectType::REQUEST);


	partyListObj = new OPartyList;
	partyListObj->SetPos(Vec2(500.f, 725.f));
	AddObject(partyListObj, ObjectType::REQUEST);

	weaponListObj = new OWeaponList;
	weaponListObj->SetPos(Vec2(900.f, 750.f));
	AddObject(weaponListObj, ObjectType::REQUEST);

	//IDcard
	idCardObj = new OIDCard;
	idCardObj->SetPos(Vec2(200.f, 800.f));
	AddObject(idCardObj, ObjectType::REQUEST);

	//for (uint32 i = 0; i < questMap.size(); i++)
	//{
	//	//생성
	//	Object* requestObj = new ORequest;
	//	//자리배치
	//	requestObj->SetPos(Vec2(posX, posY));
	//	//화면에 띄우기
	//	AddObject(requestObj, ObjectType::REQUEST);

	//	count++;
	//	posX += 150;

	//	if (count == 2)
	//	{
	//		posY += 150;
	//		count = 0;
	//		posX = 10;
	//	}
	//}

	////RequestPaper
	//Object* requestPaperObj = new ORequestPaper;
	//AddObject(requestPaperObj, ObjectType::REQUEST);

	// 충돌 지정
	// Request 그룹과 OTable 그룹 간의 충돌체크
	//GET_SINGLE(CollisionManager)->CheckGroup(ObjectType::REQUEST, ObjectType::Table);

	// TEST
	//

	vector<wstring> tempADVVector = GET_SINGLE(ObjectManager)->GetADVIDVector();
	int32 tempCurNum = GET_SINGLE(ObjectManager)->GetCurNum();
	GET_SINGLE(ObjectManager)->ChangeADVID(tempADVVector[tempCurNum - 1]);



}

void PlayScene::Update()
{
	Scene::Update();

	_year = GET_SINGLE(VectorManager)->GetYear();

	/// 년차에 따라 의뢰 내용이 바뀌게 하는 코드
	switch (_year)
	{
		case 1:
		{
			requestObj_1->SetRequestMoney(3000);
			requestObj_1->SetRequestNameScript(GET_SINGLE(VectorManager)->requestName1[0]);
			requestObj_1->SetRequestScript(GET_SINGLE(VectorManager)->requestScript1[0]);
			requestObj_1->SetRequestRewardScript(GET_SINGLE(VectorManager)->requestReward1[0]);
			requestObj_1->SetRequestRankType(RequestRank::BRONZE);
			requestObj_2->SetRequestMoney(3000);
			requestObj_2->SetRequestNameScript(GET_SINGLE(VectorManager)->requestName1[1]);
			requestObj_2->SetRequestScript(GET_SINGLE(VectorManager)->requestScript1[1]);
			requestObj_2->SetRequestRewardScript(GET_SINGLE(VectorManager)->requestReward1[1]);
			requestObj_2->SetRequestRankType(RequestRank::BRONZE);
			requestObj_3->SetRequestMoney(6000);
			requestObj_3->SetRequestNameScript(GET_SINGLE(VectorManager)->requestName1[2]);
			requestObj_3->SetRequestScript(GET_SINGLE(VectorManager)->requestScript1[2]);
			requestObj_3->SetRequestRewardScript(GET_SINGLE(VectorManager)->requestReward1[2]);
			requestObj_3->SetRequestRankType(RequestRank::SILVER);
			requestObj_4->SetRequestMoney(6000);
			requestObj_4->SetRequestNameScript(GET_SINGLE(VectorManager)->requestName1[3]);
			requestObj_4->SetRequestScript(GET_SINGLE(VectorManager)->requestScript1[3]);
			requestObj_4->SetRequestRewardScript(GET_SINGLE(VectorManager)->requestReward1[3]);
			requestObj_4->SetRequestRankType(RequestRank::SILVER);
			requestObj_5->SetRequestMoney(6000);
			requestObj_5->SetRequestNameScript(GET_SINGLE(VectorManager)->requestName1[4]);
			requestObj_5->SetRequestScript(GET_SINGLE(VectorManager)->requestScript1[4]);
			requestObj_5->SetRequestRewardScript(GET_SINGLE(VectorManager)->requestReward1[4]);
			requestObj_5->SetRequestRankType(RequestRank::SILVER);
			requestObj_6->SetRequestMoney(6000);
			requestObj_6->SetRequestNameScript(GET_SINGLE(VectorManager)->requestName1[5]);
			requestObj_6->SetRequestScript(GET_SINGLE(VectorManager)->requestScript1[5]);
			requestObj_6->SetRequestRewardScript(GET_SINGLE(VectorManager)->requestReward1[5]);
			requestObj_6->SetRequestRankType(RequestRank::GOLD);
			requestObj_7->SetRequestMoney(6000);
			requestObj_7->SetRequestNameScript(GET_SINGLE(VectorManager)->requestName1[6]);
			requestObj_7->SetRequestScript(GET_SINGLE(VectorManager)->requestScript1[6]);
			requestObj_7->SetRequestRewardScript(GET_SINGLE(VectorManager)->requestReward1[6]);
			requestObj_7->SetRequestRankType(RequestRank::GOLD);
			goddnessRequestObj->SetRequestMoney(0);
			goddnessRequestObj->SetRequestNameScript(GET_SINGLE(VectorManager)->requestName3[7]);
			goddnessRequestObj->SetRequestScript(GET_SINGLE(VectorManager)->requestScript3[7]);
			goddnessRequestObj->SetRequestRewardScript(GET_SINGLE(VectorManager)->requestReward3[7]);
			goddnessRequestObj->SetRequestRankType(RequestRank::PLATINUM);
			goddnessRequestObj->SetAlpha(0);
		}
		break;
		case 2:
		{
			requestObj_1->SetRequestMoney(6000);
			requestObj_1->SetRequestNameScript(GET_SINGLE(VectorManager)->requestName2[0]);
			requestObj_1->SetRequestScript(GET_SINGLE(VectorManager)->requestScript2[0]);
			requestObj_1->SetRequestRewardScript(GET_SINGLE(VectorManager)->requestReward2[0]);
			requestObj_1->SetRequestRankType(RequestRank::SILVER);
			requestObj_2->SetRequestMoney(3000);
			requestObj_2->SetRequestNameScript(GET_SINGLE(VectorManager)->requestName2[1]);
			requestObj_2->SetRequestScript(GET_SINGLE(VectorManager)->requestScript2[1]);
			requestObj_2->SetRequestRewardScript(GET_SINGLE(VectorManager)->requestReward2[1]);
			requestObj_2->SetRequestRankType(RequestRank::BRONZE);
			requestObj_3->SetRequestMoney(10000);
			requestObj_3->SetRequestNameScript(GET_SINGLE(VectorManager)->requestName2[2]);
			requestObj_3->SetRequestScript(GET_SINGLE(VectorManager)->requestScript2[2]);
			requestObj_3->SetRequestRewardScript(GET_SINGLE(VectorManager)->requestReward2[2]);
			requestObj_3->SetRequestRankType(RequestRank::GOLD);
			requestObj_4->SetRequestMoney(3000);
			requestObj_4->SetRequestNameScript(GET_SINGLE(VectorManager)->requestName2[3]);
			requestObj_4->SetRequestScript(GET_SINGLE(VectorManager)->requestScript2[3]);
			requestObj_4->SetRequestRewardScript(GET_SINGLE(VectorManager)->requestReward2[3]);
			requestObj_4->SetRequestRankType(RequestRank::BRONZE);
			requestObj_5->SetRequestMoney(6000);
			requestObj_5->SetRequestNameScript(GET_SINGLE(VectorManager)->requestName2[4]);
			requestObj_5->SetRequestScript(GET_SINGLE(VectorManager)->requestScript2[4]);
			requestObj_5->SetRequestRewardScript(GET_SINGLE(VectorManager)->requestReward2[4]);
			requestObj_5->SetRequestRankType(RequestRank::SILVER);
			requestObj_6->SetRequestMoney(6000);
			requestObj_6->SetRequestNameScript(GET_SINGLE(VectorManager)->requestName2[5]);
			requestObj_6->SetRequestScript(GET_SINGLE(VectorManager)->requestScript2[5]);
			requestObj_6->SetRequestRewardScript(GET_SINGLE(VectorManager)->requestReward2[5]);
			requestObj_6->SetRequestRankType(RequestRank::SILVER);
			requestObj_7->SetRequestMoney(10000);
			requestObj_7->SetRequestNameScript(GET_SINGLE(VectorManager)->requestName2[6]);
			requestObj_7->SetRequestScript(GET_SINGLE(VectorManager)->requestScript2[6]);
			requestObj_7->SetRequestRewardScript(GET_SINGLE(VectorManager)->requestReward2[6]);
			requestObj_7->SetRequestRankType(RequestRank::GOLD);
			goddnessRequestObj->SetRequestMoney(0);
			goddnessRequestObj->SetRequestNameScript(GET_SINGLE(VectorManager)->requestName3[7]);
			goddnessRequestObj->SetRequestScript(GET_SINGLE(VectorManager)->requestScript3[7]);
			goddnessRequestObj->SetRequestRewardScript(GET_SINGLE(VectorManager)->requestReward3[7]);
			goddnessRequestObj->SetRequestRankType(RequestRank::PLATINUM);
			goddnessRequestObj->SetAlpha(0);
		}
		break;
		case 3:
		{
			requestObj_1->SetRequestMoney(10000);
			requestObj_1->SetRequestNameScript(GET_SINGLE(VectorManager)->requestName3[0]);
			requestObj_1->SetRequestScript(GET_SINGLE(VectorManager)->requestScript3[0]);
			requestObj_1->SetRequestRewardScript(GET_SINGLE(VectorManager)->requestReward3[0]);
			requestObj_1->SetRequestRankType(RequestRank::GOLD);
			requestObj_2->SetRequestMoney(3000);
			requestObj_2->SetRequestNameScript(GET_SINGLE(VectorManager)->requestName3[1]);
			requestObj_2->SetRequestScript(GET_SINGLE(VectorManager)->requestScript3[1]);
			requestObj_2->SetRequestRewardScript(GET_SINGLE(VectorManager)->requestReward3[1]);
			requestObj_2->SetRequestRankType(RequestRank::BRONZE);
			requestObj_3->SetRequestMoney(3000);
			requestObj_3->SetRequestNameScript(GET_SINGLE(VectorManager)->requestName3[2]);
			requestObj_3->SetRequestScript(GET_SINGLE(VectorManager)->requestScript3[2]);
			requestObj_3->SetRequestRewardScript(GET_SINGLE(VectorManager)->requestReward3[2]);
			requestObj_3->SetRequestRankType(RequestRank::BRONZE);
			requestObj_4->SetRequestMoney(6000);
			requestObj_4->SetRequestNameScript(GET_SINGLE(VectorManager)->requestName3[3]);
			requestObj_4->SetRequestScript(GET_SINGLE(VectorManager)->requestScript3[3]);
			requestObj_4->SetRequestRewardScript(GET_SINGLE(VectorManager)->requestReward3[3]);
			requestObj_4->SetRequestRankType(RequestRank::SILVER);
			requestObj_5->SetRequestMoney(6000);
			requestObj_5->SetRequestNameScript(GET_SINGLE(VectorManager)->requestName3[4]);
			requestObj_5->SetRequestScript(GET_SINGLE(VectorManager)->requestScript3[4]);
			requestObj_5->SetRequestRewardScript(GET_SINGLE(VectorManager)->requestReward3[4]);
			requestObj_5->SetRequestRankType(RequestRank::SILVER);
			requestObj_6->SetRequestMoney(6000);
			requestObj_6->SetRequestNameScript(GET_SINGLE(VectorManager)->requestName3[5]);
			requestObj_6->SetRequestScript(GET_SINGLE(VectorManager)->requestScript3[5]);
			requestObj_6->SetRequestRewardScript(GET_SINGLE(VectorManager)->requestReward3[5]);
			requestObj_6->SetRequestRankType(RequestRank::SILVER);
			requestObj_7->SetRequestMoney(10000);
			requestObj_7->SetRequestNameScript(GET_SINGLE(VectorManager)->requestName3[6]);
			requestObj_7->SetRequestScript(GET_SINGLE(VectorManager)->requestScript3[6]);
			requestObj_7->SetRequestRewardScript(GET_SINGLE(VectorManager)->requestReward3[6]);
			requestObj_7->SetRequestRankType(RequestRank::GOLD);
			goddnessRequestObj->SetRequestMoney(0);
			goddnessRequestObj->SetRequestNameScript(GET_SINGLE(VectorManager)->requestName3[7]);
			goddnessRequestObj->SetRequestScript(GET_SINGLE(VectorManager)->requestScript3[7]);
			goddnessRequestObj->SetRequestRewardScript(GET_SINGLE(VectorManager)->requestReward3[7]);
			goddnessRequestObj->SetRequestRankType(RequestRank::PLATINUM);
			//goddnessRequestObj->SetPos(Vec2(75 + 150, 120 + 125 + 125 + 125));
			goddnessRequestObj->SetAlpha(255);
		}
		break;
	}

	Object* _bargainBObject = arrObj[(int32)ObjectType::BUTTON][0];
	Object* _applyBObject = arrObj[(int32)ObjectType::BUTTON][1];
	Object* _approvalBtnBObject = arrObj[(int32)ObjectType::BUTTON][2];
	Object* _refuseBObject = arrObj[(int32)ObjectType::BUTTON][3];

	Object* _moneyObject = arrObj[(int32)ObjectType::MONEY][0];
	Object* _fameObject = arrObj[(int32)ObjectType::FAME][0];

	Object* _cObject = arrObj[(int32)ObjectType::Character][0];
	//Object* _idObject = arrObj[(int32)ObjectType::IDCARD][0];
	Object* _sObject = arrObj[(int32)ObjectType::SCRIPT][0];

	Object* _feeObject = arrObj[(int32)ObjectType::FEE][0];
	Object* _waitingObject = arrObj[(int32)ObjectType::WAITING][0];
	Object* _yearObject = arrObj[(int32)ObjectType::YEAR][0];


	///마우스 값 받아옴
	Vec2 _mousePos = GET_SINGLE(InputManager)->GetMouseCursorPosition();

	///흥정 불가능한 캐릭터 확인
	CharacterName cannotBargain = GET_SINGLE(VectorManager)->characterAppear1[characterChange];

	///돈 부족으로 인한 지원버튼 비활성화 구현가능?
	int32 cannotSupport = GET_SINGLE(VectorManager)->GetTotalMoney();

	///캐릭터 상태 체크
	CharacterName charaName = GET_SINGLE(VectorManager)->characterAppear1[characterChange];

	///최종 근원 이벤트 (1. 흥정 버튼 비활성화 2. 근원 이벤트 받았을 경우 처리 id = 7) 
	int32 year = GET_SINGLE(VectorManager)->GetYear();

	///디버깅용 키보드 값

	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{
		ChangeScene(SceneType::STARTSCENE);
	}

	if (GetAsyncKeyState('R') & 0x8000)
	{
		ChangeScene(SceneType::FEEDBACKSCENE);
	}

	if (GetAsyncKeyState('E') & 0x8000)
	{
		ChangeScene(SceneType::ENDING);
	}

	///게임의 첫 루프
	if (status == 100)
	{
		//음악설정
		GET_SINGLE(ResourceManager)->PlayMusicSound(2);

		//라운드 시작
		GET_SINGLE(ResourceManager)->PlayEffect(18);

		status = 0;
	}


	///vector range out을 제거하기 위한 상태 체크 조건문
	if (status == -2)
	{
		if (_waitingObject->GetWaiting() == 8)
		{
			int totalMoney = GET_SINGLE(VectorManager)->GetTotalMoney();
			int addMoney = GET_SINGLE(VectorManager)->GetMoney();
			totalMoney = addMoney + totalMoney;
			GET_SINGLE(VectorManager)->SetTotalMoney(totalMoney);

			//라운드 종료 사운드
			GET_SINGLE(ResourceManager)->PlayEffect(17);
			ChangeScene(SceneType::FEEDBACKSCENE);
			status = -3;
		}
		else
		{
			status = -1;
		}
	}
	///캐릭터 변경 및 초기화 작업 수행
	if (status == -1)
	{
		characterChange++;
		status = 0;
		scriptNum = 0;
		bargainCount = 1;
		alphaFadeIn = 0;
		alphaFadeOut = 255;

		idCardObj->SetPos(Vec2(200, 800));
		idCardObj->SetAlpha(0);
		partyListObj->SetPos(Vec2(500, 725));
		partyListObj->SetAlpha(0);
		weaponListObj->SetPos(Vec2(900, 750));
		weaponListObj->SetAlpha(0);
		requestObj_1->SetAlpha(0);

	}

	///투명상태에서 등장
	if (status == 0)
	{
		idCardObj->SetAlpha(255);

		if (charaName == CharacterName::darius ||
			charaName == CharacterName::lilian ||
			charaName == CharacterName::ninza2 ||
			charaName == CharacterName::dwarf_1 ||
			charaName == CharacterName::dwarf_2 ||
			charaName == CharacterName::herbalist1 ||
			charaName == CharacterName::herbalist3 ||
			charaName == CharacterName::herbalist4 ||
			charaName == CharacterName::catfighter2
			)
		{
			partyListObj->SetAlpha(255);
		}
		else
		{
			partyListObj->SetAlpha(0);
		}

		//알맞은 서류 팝업
		if (charaName == CharacterName::darius ||
			charaName == CharacterName::catfighter1 ||
			charaName == CharacterName::catfighter2 ||
			charaName == CharacterName::ninza1 ||
			charaName == CharacterName::ninza2 ||
			charaName == CharacterName::lilian ||
			charaName == CharacterName::eden ||
			charaName == CharacterName::herbalist2
			)
		{
			weaponListObj->SetAlpha(255);
		}
		else
		{
			weaponListObj->SetAlpha(0);
		}

		if (alphaFadeIn == 0)
		{
			//캐릭터 등장 사운드
			GET_SINGLE(ResourceManager)->PlayEffect(0);

			// 서류를 받은 상태(텍스트가 진행되는 동안 서류를 받지 않게 하기 위해)
			GET_SINGLE(VectorManager)->SetIsRequestReturned(true);
			GET_SINGLE(VectorManager)->SetIsIDCardReturned(true);
			GET_SINGLE(VectorManager)->SetIsPartyListReturned(true);
			GET_SINGLE(VectorManager)->SetIsWeaponListReturned(true);

			//버튼 비활성화
			bargainButtonActive = false; // 활성화체크
			_bargainBObject->SetButtonStatus(false);
			applyButtonActive = false; // 활성화체크	
			_applyBObject->SetButtonStatus(false);
			approvalButtonActive = false; // 활성화체크
			_approvalBtnBObject->SetButtonStatus(false);
			refuseButtonActive = false; // 활성화체크
			_refuseBObject->SetButtonStatus(false);
			int characterFee = GET_SINGLE(VectorManager)->characterFee1[characterChange];
			_feeObject->SetFee(characterFee);
			popUPImage(_cObject, idCardObj, GET_SINGLE(VectorManager)->characterAppear1[characterChange]);

			// 파티 리스트 오브젝트에 캐릭터 타입 전달
			partyListObj->SetCharacterName(GET_SINGLE(VectorManager)->characterAppear1[characterChange]);
			weaponListObj->SetCharacterName(GET_SINGLE(VectorManager)->characterAppear1[characterChange]);

			//조건문 탈출
			alphaFadeIn += 15;

		}
		//fadeIn
		else
		{
			_cObject->SetAlpha(alphaFadeIn);
			alphaFadeIn += 15;

		}

		if (alphaFadeIn == 255)
		{
			status = 1;
			popUPScript(_sObject);
		}


	}

	///대화
	else if (status == 1)
	{
		isWaiting = Timer(GET_SINGLE(TimeManager)->getDeltaTime());
		isBlank = Speak(_sObject, scriptNum, characterChange);

		if (scriptNum == 10 || isBlank == true)
		{
			status = 2;
			popDownScript(_sObject);

			//서류 받기 활성화
			GET_SINGLE(VectorManager)->SetIsRequestReturned(false);
			GET_SINGLE(VectorManager)->SetIsIDCardReturned(false);
			GET_SINGLE(VectorManager)->SetIsPartyListReturned(false);
			GET_SINGLE(VectorManager)->SetIsWeaponListReturned(false);

			refuseButtonActive = true; // 활성화체크
			_refuseBObject->SetButtonStatus(true);
			isRequestGet = true;
		}
		if (isClick == true)
		{
			scriptNum++;
			isClick = false;
		}

	}

	///버튼대기 -> 서류를 받는 곳
	else if (status == 2)
	{
		bool requestCheck = GET_SINGLE(VectorManager)->GetIsRequestReturned();
		if (requestCheck == true && isRequestGet == true)
		{
			//유니크 NPC의 경우, 받은 서류의 값을 확인해야 함
			if (charaName == CharacterName::lilian || charaName == CharacterName::darius || charaName == CharacterName::eden)
			{
				int requestID = GET_SINGLE(VectorManager)->GetRequestID();
				GET_SINGLE(VectorManager)->npcRequestID.push_back(requestID);
			}
			//버튼활성화
			bargainButtonActive = true; // 활성화체크
			_bargainBObject->SetButtonStatus(true);
			applyButtonActive = true; // 활성화체크	
			_applyBObject->SetButtonStatus(true);
			approvalButtonActive = true; // 활성화체크
			_approvalBtnBObject->SetButtonStatus(true);
			isRequestGet = false;
		}
		else
		{

		}
		if (buttonCheck == 1)
		{
			status = 3;
			buttonCheck = 0;
			isBlank = Speak(_sObject, scriptNum, characterChange);
			popUPScript(_sObject);
		}

		if (buttonCheck == 2)
		{
			buttonCheck = 0;
			isBlank = Speak(_sObject, scriptNum, characterChange);
			popUPScript(_sObject);
		}
	}
	///버튼 입력
	else if (status == 3)
	{

		//버튼 비활성화
		bargainButtonActive = false; // 활성화체크
		_bargainBObject->SetButtonStatus(false);
		applyButtonActive = false; // 활성화체크	
		_applyBObject->SetButtonStatus(false);
		approvalButtonActive = false; // 활성화체크
		_approvalBtnBObject->SetButtonStatus(false);
		refuseButtonActive = false; // 활성화체크
		_refuseBObject->SetButtonStatus(false);

		if (isClick == true && isTableBlank == false)
		{
			scriptNum = 20;
			isBlank = Speak(_sObject, scriptNum, characterChange);
		}

		if (isClick == true && isTableBlank == true)
		{
			status = 5;
			isClick = false;
			isTableBlank = false;
		}
	}

	///사라짐
	else if (status == 5)
	{
		if (alphaFadeOut == 255)
		{
			//캐릭터 퇴장 사운드
			GET_SINGLE(ResourceManager)->PlayEffect(11);

			//대기열 +1
			int waiting = _waitingObject->GetWaiting();
			_waitingObject->SetWaiting(waiting += 1);

			popDownScript(_sObject);
			alphaFadeOut -= 15;
		}
		//fadeOut
		else
		{
			_cObject->SetAlpha(alphaFadeOut);
			alphaFadeOut -= 15;

		}

		if (alphaFadeOut <= 0)
		{
			status = 6;
		}

	}

	///클릭이 될 경우 다음 사람 입장
	else if (status == 6)
	{
		if (isClick == true)
		{
			status = -2;
			isClick = false;
		}

	}

	///버튼체크 
	bargainButtonClick = BargainBtnClick(_mousePos, _moneyObject, _fameObject, _feeObject, bargainButtonActive);
	applyButtonClick = ApplyBtnClick(_mousePos, _moneyObject, _fameObject, _feeObject, characterChange, applyButtonActive);
	approvalButtonClick = ApprovalBtnClick(_mousePos, _feeObject, approvalButtonActive, characterChange);
	refuseButtonClick = RefuseBtnClick(_mousePos, _feeObject, refuseButtonActive, characterChange);

	///클릭체크
	isClick = IsScriptClick(_mousePos);

	///테이블 Empty 확인
	isTableBlank = GET_SINGLE(InputManager)->IsDeskEmpty();

	///흥정 버튼 클릭
	if (bargainButtonClick == true)
	{
		//클릭 사운드
		GET_SINGLE(ResourceManager)->PlayEffect(4);

		applyButtonActive = false; // 활성화체크	
		_applyBObject->SetButtonStatus(false);

		int32 maxCount = GET_SINGLE(VectorManager)->bargainCount1[characterChange];
		//현재의 수수료 값을 받아온다
		int nowFee = _feeObject->GetFee();

		if (maxCount == 0)
		{
			scriptNum = 10;
			buttonCheck = 1;
			bargainCount = 0;
			//성공 여부 반환
			GET_SINGLE(VectorManager)->successOrNot.push_back(0);
		}
		else
		{

			if (bargainCount == 1)
			{
				if (bargainCount == maxCount)
				{
					scriptNum = 10;
					buttonCheck = 1;
					bargainCount = 0;
					//성공 여부 반환
					GET_SINGLE(VectorManager)->successOrNot.push_back(0);
				}
				else
				{
					scriptNum = 10;
					bargainCount = 2;
					buttonCheck = 2;
					nowFee += 10;
				}
			}

			else if (bargainCount == 2)
			{
				if (bargainCount == maxCount)
				{
					scriptNum = 11;
					buttonCheck = 1;
					bargainCount = 0;
					//성공 여부 반환
					GET_SINGLE(VectorManager)->successOrNot.push_back(0);

				}
				else
				{
					scriptNum = 11;
					bargainCount = 3;
					buttonCheck = 2;
					nowFee += 10;
				}
			}
			else if (bargainCount == maxCount)
			{
				scriptNum = 12;
				buttonCheck = 1;
				bargainCount = 0;
				//성공 여부 반환
				GET_SINGLE(VectorManager)->successOrNot.push_back(0);
			}
		}
		_feeObject->SetFee(nowFee);
		bargainButtonClick = false;

	}

	///지원 버튼 클릭
	if (applyButtonClick)
	{
		//클릭 사운드
		GET_SINGLE(ResourceManager)->PlayEffect(4);
		int32 requestId = GET_SINGLE(VectorManager)->GetRequestID();

		if (year == 3 && characterChange >= 21 && requestId == 7)
		{
			scriptNum = 16;
		}
		else
		{
			scriptNum = 13;
		}
		buttonCheck = 1;
		applyButtonClick = false;
	}

	///승인 버튼 클릭
	if (approvalButtonClick)
	{
		//클릭 사운드
		GET_SINGLE(ResourceManager)->PlayEffect(19);
		int32 requestId = GET_SINGLE(VectorManager)->GetRequestID();

		if (year == 3 && characterChange >= 21 && requestId == 7)
		{
			scriptNum = 17;
		}
		else
		{
			scriptNum = 14;
		}
		buttonCheck = 1;
		approvalButtonClick = false;
	}

	///거절 버튼 클릭
	if (refuseButtonClick)
	{
		//클릭 사운드
		GET_SINGLE(ResourceManager)->PlayEffect(16);

		scriptNum = 15;
		buttonCheck = 1;
		refuseButtonClick = false;

		//유니크 NPC의 경우, 받은 서류의 값을 확인해야 함
		if (charaName == CharacterName::lilian || charaName == CharacterName::darius || charaName == CharacterName::eden)
		{
			GET_SINGLE(VectorManager)->npcRequestID.push_back(0);
		}
	}


	///흥정 버튼 비활성화
	if (cannotBargain == CharacterName::lilian || cannotBargain == CharacterName::eden || (year == 3 && characterChange >= 20))
	{
		bargainButtonActive = false; // 활성화체크
		_bargainBObject->SetButtonStatus(false);
	}

	GET_SINGLE(ObjectManager)->ChangePlayEvent();

}



void PlayScene::Exit()
{
	DeleteAll();
	GET_SINGLE(ResourceManager)->StopSound();
	GET_SINGLE(CollisionManager)->Reset();

}



bool PlayScene::Timer(float deltaTime)
{
	timerTime += deltaTime;

	if (timerTime >= 1.0)
	{
		sec--;

		timerTime = 0.0;

		if (sec <= 0)
		{
			sec = 2;
			return true;
		}

		else
		{
			return false;
		}

	}

	else
	{
		return false;
	}
}
