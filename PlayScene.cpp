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
	///������ �� ����
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

	//�ʱ�ȭ �ؾߵ�
	//Ÿ�̸� ����
	timerTime = 0;
	sec = 2;
	isWaiting = false; //��⿭

	status = 0; // ���� ����
	scriptNum = 0; //��� ����
	buttonCheck = 0; //��ưüũ
	status = 100;
	scriptNum = 0;
	bargainCount = 1;
	alphaFadeIn = 0;
	alphaFadeOut = 255;



	//Quest �޾ƿ�
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



	// ����Ʈ N �� ����

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

	// �������� 3������ �����ϴ� �Ƿ�.
	// �⺻ �������� false�� ����
	goddnessRequestObj = new ORequest;
	/// TODO : ���� ������ �о�ͼ� 1, 2 ������ �Ⱥ��̰� �����ϱ� -> 3������ ����!!
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
	//	//����
	//	Object* requestObj = new ORequest;
	//	//�ڸ���ġ
	//	requestObj->SetPos(Vec2(posX, posY));
	//	//ȭ�鿡 ����
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

	// �浹 ����
	// Request �׷�� OTable �׷� ���� �浹üũ
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

	/// ������ ���� �Ƿ� ������ �ٲ�� �ϴ� �ڵ�
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


	///���콺 �� �޾ƿ�
	Vec2 _mousePos = GET_SINGLE(InputManager)->GetMouseCursorPosition();

	///���� �Ұ����� ĳ���� Ȯ��
	CharacterName cannotBargain = GET_SINGLE(VectorManager)->characterAppear1[characterChange];

	///�� �������� ���� ������ư ��Ȱ��ȭ ��������?
	int32 cannotSupport = GET_SINGLE(VectorManager)->GetTotalMoney();

	///ĳ���� ���� üũ
	CharacterName charaName = GET_SINGLE(VectorManager)->characterAppear1[characterChange];

	///���� �ٿ� �̺�Ʈ (1. ���� ��ư ��Ȱ��ȭ 2. �ٿ� �̺�Ʈ �޾��� ��� ó�� id = 7) 
	int32 year = GET_SINGLE(VectorManager)->GetYear();

	///������ Ű���� ��

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

	///������ ù ����
	if (status == 100)
	{
		//���Ǽ���
		GET_SINGLE(ResourceManager)->PlayMusicSound(2);

		//���� ����
		GET_SINGLE(ResourceManager)->PlayEffect(18);

		status = 0;
	}


	///vector range out�� �����ϱ� ���� ���� üũ ���ǹ�
	if (status == -2)
	{
		if (_waitingObject->GetWaiting() == 8)
		{
			int totalMoney = GET_SINGLE(VectorManager)->GetTotalMoney();
			int addMoney = GET_SINGLE(VectorManager)->GetMoney();
			totalMoney = addMoney + totalMoney;
			GET_SINGLE(VectorManager)->SetTotalMoney(totalMoney);

			//���� ���� ����
			GET_SINGLE(ResourceManager)->PlayEffect(17);
			ChangeScene(SceneType::FEEDBACKSCENE);
			status = -3;
		}
		else
		{
			status = -1;
		}
	}
	///ĳ���� ���� �� �ʱ�ȭ �۾� ����
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

	///������¿��� ����
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

		//�˸��� ���� �˾�
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
			//ĳ���� ���� ����
			GET_SINGLE(ResourceManager)->PlayEffect(0);

			// ������ ���� ����(�ؽ�Ʈ�� ����Ǵ� ���� ������ ���� �ʰ� �ϱ� ����)
			GET_SINGLE(VectorManager)->SetIsRequestReturned(true);
			GET_SINGLE(VectorManager)->SetIsIDCardReturned(true);
			GET_SINGLE(VectorManager)->SetIsPartyListReturned(true);
			GET_SINGLE(VectorManager)->SetIsWeaponListReturned(true);

			//��ư ��Ȱ��ȭ
			bargainButtonActive = false; // Ȱ��ȭüũ
			_bargainBObject->SetButtonStatus(false);
			applyButtonActive = false; // Ȱ��ȭüũ	
			_applyBObject->SetButtonStatus(false);
			approvalButtonActive = false; // Ȱ��ȭüũ
			_approvalBtnBObject->SetButtonStatus(false);
			refuseButtonActive = false; // Ȱ��ȭüũ
			_refuseBObject->SetButtonStatus(false);
			int characterFee = GET_SINGLE(VectorManager)->characterFee1[characterChange];
			_feeObject->SetFee(characterFee);
			popUPImage(_cObject, idCardObj, GET_SINGLE(VectorManager)->characterAppear1[characterChange]);

			// ��Ƽ ����Ʈ ������Ʈ�� ĳ���� Ÿ�� ����
			partyListObj->SetCharacterName(GET_SINGLE(VectorManager)->characterAppear1[characterChange]);
			weaponListObj->SetCharacterName(GET_SINGLE(VectorManager)->characterAppear1[characterChange]);

			//���ǹ� Ż��
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

	///��ȭ
	else if (status == 1)
	{
		isWaiting = Timer(GET_SINGLE(TimeManager)->getDeltaTime());
		isBlank = Speak(_sObject, scriptNum, characterChange);

		if (scriptNum == 10 || isBlank == true)
		{
			status = 2;
			popDownScript(_sObject);

			//���� �ޱ� Ȱ��ȭ
			GET_SINGLE(VectorManager)->SetIsRequestReturned(false);
			GET_SINGLE(VectorManager)->SetIsIDCardReturned(false);
			GET_SINGLE(VectorManager)->SetIsPartyListReturned(false);
			GET_SINGLE(VectorManager)->SetIsWeaponListReturned(false);

			refuseButtonActive = true; // Ȱ��ȭüũ
			_refuseBObject->SetButtonStatus(true);
			isRequestGet = true;
		}
		if (isClick == true)
		{
			scriptNum++;
			isClick = false;
		}

	}

	///��ư��� -> ������ �޴� ��
	else if (status == 2)
	{
		bool requestCheck = GET_SINGLE(VectorManager)->GetIsRequestReturned();
		if (requestCheck == true && isRequestGet == true)
		{
			//����ũ NPC�� ���, ���� ������ ���� Ȯ���ؾ� ��
			if (charaName == CharacterName::lilian || charaName == CharacterName::darius || charaName == CharacterName::eden)
			{
				int requestID = GET_SINGLE(VectorManager)->GetRequestID();
				GET_SINGLE(VectorManager)->npcRequestID.push_back(requestID);
			}
			//��ưȰ��ȭ
			bargainButtonActive = true; // Ȱ��ȭüũ
			_bargainBObject->SetButtonStatus(true);
			applyButtonActive = true; // Ȱ��ȭüũ	
			_applyBObject->SetButtonStatus(true);
			approvalButtonActive = true; // Ȱ��ȭüũ
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
	///��ư �Է�
	else if (status == 3)
	{

		//��ư ��Ȱ��ȭ
		bargainButtonActive = false; // Ȱ��ȭüũ
		_bargainBObject->SetButtonStatus(false);
		applyButtonActive = false; // Ȱ��ȭüũ	
		_applyBObject->SetButtonStatus(false);
		approvalButtonActive = false; // Ȱ��ȭüũ
		_approvalBtnBObject->SetButtonStatus(false);
		refuseButtonActive = false; // Ȱ��ȭüũ
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

	///�����
	else if (status == 5)
	{
		if (alphaFadeOut == 255)
		{
			//ĳ���� ���� ����
			GET_SINGLE(ResourceManager)->PlayEffect(11);

			//��⿭ +1
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

	///Ŭ���� �� ��� ���� ��� ����
	else if (status == 6)
	{
		if (isClick == true)
		{
			status = -2;
			isClick = false;
		}

	}

	///��ưüũ 
	bargainButtonClick = BargainBtnClick(_mousePos, _moneyObject, _fameObject, _feeObject, bargainButtonActive);
	applyButtonClick = ApplyBtnClick(_mousePos, _moneyObject, _fameObject, _feeObject, characterChange, applyButtonActive);
	approvalButtonClick = ApprovalBtnClick(_mousePos, _feeObject, approvalButtonActive, characterChange);
	refuseButtonClick = RefuseBtnClick(_mousePos, _feeObject, refuseButtonActive, characterChange);

	///Ŭ��üũ
	isClick = IsScriptClick(_mousePos);

	///���̺� Empty Ȯ��
	isTableBlank = GET_SINGLE(InputManager)->IsDeskEmpty();

	///���� ��ư Ŭ��
	if (bargainButtonClick == true)
	{
		//Ŭ�� ����
		GET_SINGLE(ResourceManager)->PlayEffect(4);

		applyButtonActive = false; // Ȱ��ȭüũ	
		_applyBObject->SetButtonStatus(false);

		int32 maxCount = GET_SINGLE(VectorManager)->bargainCount1[characterChange];
		//������ ������ ���� �޾ƿ´�
		int nowFee = _feeObject->GetFee();

		if (maxCount == 0)
		{
			scriptNum = 10;
			buttonCheck = 1;
			bargainCount = 0;
			//���� ���� ��ȯ
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
					//���� ���� ��ȯ
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
					//���� ���� ��ȯ
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
				//���� ���� ��ȯ
				GET_SINGLE(VectorManager)->successOrNot.push_back(0);
			}
		}
		_feeObject->SetFee(nowFee);
		bargainButtonClick = false;

	}

	///���� ��ư Ŭ��
	if (applyButtonClick)
	{
		//Ŭ�� ����
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

	///���� ��ư Ŭ��
	if (approvalButtonClick)
	{
		//Ŭ�� ����
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

	///���� ��ư Ŭ��
	if (refuseButtonClick)
	{
		//Ŭ�� ����
		GET_SINGLE(ResourceManager)->PlayEffect(16);

		scriptNum = 15;
		buttonCheck = 1;
		refuseButtonClick = false;

		//����ũ NPC�� ���, ���� ������ ���� Ȯ���ؾ� ��
		if (charaName == CharacterName::lilian || charaName == CharacterName::darius || charaName == CharacterName::eden)
		{
			GET_SINGLE(VectorManager)->npcRequestID.push_back(0);
		}
	}


	///���� ��ư ��Ȱ��ȭ
	if (cannotBargain == CharacterName::lilian || cannotBargain == CharacterName::eden || (year == 3 && characterChange >= 20))
	{
		bargainButtonActive = false; // Ȱ��ȭüũ
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
