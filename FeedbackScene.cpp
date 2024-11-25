#include "pch.h"
#include "FeedbackScene.h"
#include "ONextBtn.h"
#include "OSKipBtn.h"
#include "OFeedbackBackground.h"
#include "OFeedbackScript.h"

#include "InputManager.h"

FeedbackScene::FeedbackScene()
{

}

FeedbackScene::~FeedbackScene()
{

}

void FeedbackScene::Start()
{
	//음악설정
	GET_SINGLE(ResourceManager)->PlayMusicSound(3);

	//변수 초기화
	characterScripNum = 0;
	NextButtonClick = false;
	SkipButtonClick = false;
	FeedbackSceneType feedBackType;
	int32 year = GET_SINGLE(VectorManager)->GetYear();

	if (year == 1)
	{
		feedBackType = FeedbackSceneType::MAIN_1;
	}

	if (year == 2)
	{
		feedBackType = FeedbackSceneType::MAIN_2;
	}

	if (year == 3)
	{
		feedBackType = FeedbackSceneType::MAIN_3;
	}

	//BackImg
	Object* feedBackBackObject = new OFeedbackBackground;
	AddObject(feedBackBackObject, ObjectType::DEFAULT);
	feedBackBackObject->SetFeedbackType(feedBackType);

	//NextBtn
	Object* nextBtnObj = new ONextBtn;
	AddObject(nextBtnObj, ObjectType::BUTTON);

	//SkipBtn
	Object* skipBtnObj = new OSKipBtn;
	AddObject(skipBtnObj, ObjectType::BUTTON);

	//Year
	Object* yearObj = new OFeedbackScript;
	AddObject(yearObj, ObjectType::YEAR);
	yearObj->SetScript(to_wstring(year));
	yearObj->SetposX(885);
	yearObj->SetposY(125);
	yearObj->SetXWidth(300);
	yearObj->SetYWidth(300);

	//Add Money
	Object* moneyObj = new OFeedbackScript;
	AddObject(moneyObj, ObjectType::MONEY);
	moneyObj->SetScript( to_wstring((GET_SINGLE(VectorManager)->GetMoney())));
	moneyObj->SetposX(700);
	moneyObj->SetposY(690);
	moneyObj->SetXWidth(300);
	moneyObj->SetYWidth(300);

	//Add Fame
	Object* fameObj = new OFeedbackScript;
	AddObject(fameObj, ObjectType::FAME);
	fameObj->SetScript(to_wstring((GET_SINGLE(VectorManager)->GetFame())));
	fameObj->SetposX(700);
	fameObj->SetposY(790);
	fameObj->SetXWidth(300);
	fameObj->SetYWidth(300);

	//Add TotalMoney
	Object* totalMoneyObj = new OFeedbackScript;
	AddObject(totalMoneyObj, ObjectType::MONEY);
	totalMoneyObj->SetScript(to_wstring(GET_SINGLE(VectorManager)->GetTotalMoney() + GET_SINGLE(VectorManager)->GetMoney()));
	totalMoneyObj->SetposX(1530);
	totalMoneyObj->SetposY(690);
	totalMoneyObj->SetXWidth(300);
	totalMoneyObj->SetYWidth(300);

	//Add TotalFame
	Object* totalFameObj = new OFeedbackScript;
	AddObject(totalFameObj, ObjectType::FAME);
	totalFameObj->SetScript(to_wstring((GET_SINGLE(VectorManager)->GetTotalFame())));
	totalFameObj->SetposX(1530);
	totalFameObj->SetposY(790);
	totalFameObj->SetXWidth(300);
	totalFameObj->SetYWidth(300);

	//Success or Fail or Reject
	Object* person1Object = new OFeedbackScript;
	AddObject(person1Object, ObjectType::STATUS);
	person1Object->SetScript(L" ");
	person1Object->SetposX(265);
	person1Object->SetposY(550);
	person1Object->SetXWidth(1700);
	person1Object->SetYWidth(300);

	//CharacterScript
	Object* charaterScript = new OFeedbackScript;
	AddObject(charaterScript, ObjectType::SCRIPT);
	charaterScript->SetScript(L"");
	charaterScript->SetposX(850);
	charaterScript->SetposY(500);
	charaterScript->SetXWidth(800);
	charaterScript->SetYWidth(300);


}

void FeedbackScene::Exit()
{
	DeleteAll();
	GET_SINGLE(ResourceManager)->StopSound();
}

void FeedbackScene::Update()
{

	Scene::Update();
	//사용할 obj 받아오기
	Object* _scriptObject = arrObj[(int32)ObjectType::SCRIPT][0];
	Object* _successOrNot = arrObj[(int32)ObjectType::STATUS][0];
	Object* _backgroundObject = arrObj[(int32)ObjectType::DEFAULT][0];

	Object* _fameObject = arrObj[(int32)ObjectType::FAME][0];
	Object* _moneyObject = arrObj[(int32)ObjectType::MONEY][0];
	Object* _totalMoneyObject = arrObj[(int32)ObjectType::MONEY][1];
	Object* _totalFameObject = arrObj[(int32)ObjectType::FAME][1];
	

	//마우스 값 받아오기
	Vec2 _mousePos = GET_SINGLE(InputManager)->GetMouseCursorPosition();

	//엔딩 체크
	int32 endingCheck = GET_SINGLE(VectorManager)->GetYear();
	int32 _npcNum;

	NextButtonClick = NextBtnClick(_mousePos);
	SkipButtonClick = SkipBtnClick(_mousePos);


		//성공실패 그리기
		if (_backgroundObject->GetFeedbackType() == FeedbackSceneType::MAIN_1 ||
			_backgroundObject->GetFeedbackType() == FeedbackSceneType::MAIN_2 ||
			_backgroundObject->GetFeedbackType() == FeedbackSceneType::MAIN_3)
		{
			wstring _statusScript = L"";
			for (int i = 0; i < 5; i++)
			{
				if (endingCheck == 1)
				{
					_npcNum = GET_SINGLE(VectorManager)->subArr1[i];
				}
				if (endingCheck == 2)
				{
					_npcNum = GET_SINGLE(VectorManager)->subArr2[i];
				}
				if (endingCheck == 3)
				{
					_npcNum = GET_SINGLE(VectorManager)->subArr3[i];
				}

				int32 _successCheck = GET_SINGLE(VectorManager)->successOrNot[_npcNum];

				if (_successCheck == 1)
				{
					_statusScript = _statusScript + L"성공                           ";
				}
				else if (_successCheck == 0)
				{
					_statusScript = _statusScript + L"실패                           ";
				}
				else if (_successCheck == -1)
				{
					_statusScript = _statusScript + L"거절                           ";
				}
			}

			_successOrNot->SetScript(_statusScript);
		}

		if (NextButtonClick == true)
		{
			//글자 안보이게 하기
			_fameObject->SetScript(L" ");
			_moneyObject->SetScript(L" ");
			_totalFameObject->SetScript(L" ");
			_totalMoneyObject->SetScript(L" ");
			_successOrNot->SetScript(L" ");


			if (characterScripNum == 3)
			{
				if (endingCheck == 3 && characterScripNum == 3)
				{
					ChangeScene(SceneType::ENDING);
				}
				else
				{
					//년차++
					int nowYear = GET_SINGLE(VectorManager)->GetYear();
					GET_SINGLE(VectorManager)->SetYear(nowYear += 1);

					//돈++
					int32 totalMoney = GET_SINGLE(VectorManager)->GetTotalMoney();
					int32 addMoney = GET_SINGLE(VectorManager)->GetMoney();
					totalMoney = totalMoney + addMoney;
					GET_SINGLE(VectorManager)->SetTotalMoney(totalMoney);

					//값 초기화
					GET_SINGLE(VectorManager)->SetFame(0);
					GET_SINGLE(VectorManager)->SetMoney(0);
					GET_SINGLE(VectorManager)->successOrNot.clear();
					GET_SINGLE(VectorManager)->npcRequestID.clear();

					ChangeScene(SceneType::PLAYSCENE);
				}
			}
			else
			{
				int32 _EdenSuccessCheck;
				int32 _DariuSucessCheck;
				int32 _LilianSucessCheck;
				wstring feedbackScript;
				int32 requestID;
				characterScripNum++;

				if (endingCheck == 1)
				{
					_EdenSuccessCheck = GET_SINGLE(VectorManager)->successOrNot[7];
					_DariuSucessCheck = GET_SINGLE(VectorManager)->successOrNot[3];
					_LilianSucessCheck = GET_SINGLE(VectorManager)->successOrNot[0];
				}

				if (endingCheck == 2)
				{
					_EdenSuccessCheck = GET_SINGLE(VectorManager)->successOrNot[1];
					_DariuSucessCheck = GET_SINGLE(VectorManager)->successOrNot[6];
					_LilianSucessCheck = GET_SINGLE(VectorManager)->successOrNot[3];
				}

				if (endingCheck == 3)
				{
					_EdenSuccessCheck = GET_SINGLE(VectorManager)->successOrNot[7];
					_DariuSucessCheck = GET_SINGLE(VectorManager)->successOrNot[5];
					_LilianSucessCheck = GET_SINGLE(VectorManager)->successOrNot[6];
				}
				
				if (characterScripNum == 1)
				{
					_backgroundObject->SetFeedbackType(FeedbackSceneType::EDEN);

					if (endingCheck == 1)
					{
						requestID = GET_SINGLE(VectorManager)->npcRequestID[2];
					}
					
					if (endingCheck == 2)
					{
						requestID = GET_SINGLE(VectorManager)->npcRequestID[0];
						requestID = requestID + 7;
					}
					if (endingCheck == 3)
					{
						requestID = GET_SINGLE(VectorManager)->npcRequestID[2];
						requestID = requestID + 14;
					}

					if (_EdenSuccessCheck == 1)
						feedbackScript = GET_SINGLE(VectorManager)->requestSucess[requestID];
					else if (_EdenSuccessCheck == 0)
						feedbackScript = GET_SINGLE(VectorManager)->requestFail[requestID];
					else if(_EdenSuccessCheck == -1)
						feedbackScript = GET_SINGLE(VectorManager)->requestNotGet[0];
				}
				if (characterScripNum == 2)
				{
					_backgroundObject->SetFeedbackType(FeedbackSceneType::DARIUS);
					
					int32 requestID = GET_SINGLE(VectorManager)->npcRequestID[1];

					if (endingCheck == 1)
					{
						requestID = GET_SINGLE(VectorManager)->npcRequestID[1];
					}

					if (endingCheck == 2)
					{
						requestID = GET_SINGLE(VectorManager)->npcRequestID[2];
						requestID = requestID + 7;
					}
					if (endingCheck == 3)
					{
						requestID = GET_SINGLE(VectorManager)->npcRequestID[0];
						requestID = requestID + 14;
					}

					if (_DariuSucessCheck == 1)
						feedbackScript = GET_SINGLE(VectorManager)->requestSucess[requestID];
					else if (_DariuSucessCheck == 0)
						feedbackScript = GET_SINGLE(VectorManager)->requestFail[requestID];
					else
						feedbackScript = feedbackScript = GET_SINGLE(VectorManager)->requestNotGet[0];
				}

				if (characterScripNum == 3)
				{
					_backgroundObject->SetFeedbackType(FeedbackSceneType::LILIAN);

					int32 requestID = GET_SINGLE(VectorManager)->npcRequestID[1];

					if (endingCheck == 1)
					{
						requestID = GET_SINGLE(VectorManager)->npcRequestID[0];
					}

					if (endingCheck == 2)
					{
						requestID = GET_SINGLE(VectorManager)->npcRequestID[1];
						requestID = requestID + 7;
					}
					if (endingCheck == 3)
					{
						requestID = GET_SINGLE(VectorManager)->npcRequestID[1];
						requestID = requestID + 14;
					}

					if (_LilianSucessCheck == 1)
						feedbackScript = GET_SINGLE(VectorManager)->requestSucess[requestID];
					else if (_LilianSucessCheck == 0)
						feedbackScript = GET_SINGLE(VectorManager)->requestFail[requestID];
					else
						feedbackScript = feedbackScript = GET_SINGLE(VectorManager)->requestNotGet[0];
				}
				_scriptObject->SetScript(feedbackScript);
			}
		
		}

		if (SkipButtonClick == true)
		{
			if (endingCheck == 3 && characterScripNum == 3)
			{
				ChangeScene(SceneType::ENDING);
	
			}
			else
			{
				//년차++
				int nowYear = GET_SINGLE(VectorManager)->GetYear();
				GET_SINGLE(VectorManager)->SetYear(nowYear += 1);

				//돈++
				int32 totalMoney = GET_SINGLE(VectorManager)->GetTotalMoney();
				int32 addMoney = GET_SINGLE(VectorManager)->GetMoney();
				totalMoney = totalMoney + addMoney;
				GET_SINGLE(VectorManager)->SetTotalMoney(totalMoney);

				//값 초기화
				GET_SINGLE(VectorManager)->SetFame(0);
				GET_SINGLE(VectorManager)->SetMoney(0);
				GET_SINGLE(VectorManager)->successOrNot.clear();
				GET_SINGLE(VectorManager)->npcRequestID.clear();

				ChangeScene(SceneType::PLAYSCENE);
			}
		}

	}




