#include "pch.h"
#include "EventManager.h"
#include "OCharacter.h"
#include "InputManager.h"
#include "VectorManager.h"
#include "ResourceManager.h"

class Object obj;
class OCharacter cObj;



void CreateObject(Object* _pObj, ObjectType _eObject)
{
	tEvent evn = {};
	evn.eEVEN = EventType::CREATEOBJECT;
	evn.lParam = (DWORD_PTR)_pObj;
	evn.wParam = (DWORD_PTR)_eObject;

	EventManager::GetInstance()->AddEvent(evn);
}

void ChangeScene(SceneType _eNext)
{
	tEvent evn = { };
	evn.eEVEN = EventType::SCENECHANGE;
	evn.lParam = (DWORD_PTR)_eNext;

	EventManager::GetInstance()->AddEvent(evn);
}


bool BargainBtnClick(Vec2 _mousePos, Object* _mObj, Object* _fObj, Object* _feeObj, bool buttonStatus)
{
	

	if (buttonStatus == false)
		return false;

	tEvent evn = { };
	evn.eEVEN = EventType::PLAYEVENT;
	evn.pEVEN = PlayEventType::ADVON;
	int addFame = -2;
	int newFee = _feeObj->GetFee();

	if (KEY_TAP(KEY::LMB))
	{
		if (GET_SINGLE(InputManager)->ButtonClick(1520, 480, 250, 150, _mousePos) == true)
		{

			int32 fame = GET_SINGLE(VectorManager)->GetTotalFame();
			int32 nextFame = GET_SINGLE(VectorManager)->GetFame();

			OutputDebugString(L"Button1 Click!");
			OutputDebugString(TEXT("\n"));

			_fObj->SetFame(fame + addFame);
			//값 저장
			GET_SINGLE(VectorManager)->SetFame(addFame + nextFame);
			GET_SINGLE(VectorManager)->SetTotalFame(fame + addFame);

			EventManager::GetInstance()->AddEvent(evn);
			return true;
		}
	}

	return false;
}

bool ApplyBtnClick(Vec2 _mousePos, Object* _mObj, Object* _fObj, Object* _feeObj, int characterOrder, bool buttonStatus)
{

	if (buttonStatus == false)
		return false;
	int newFee = _feeObj->GetFee();
	int addFame = 0;
	int addMoney = GET_SINGLE(VectorManager)->GetRequestMoney();

	int32 money = GET_SINGLE(VectorManager)->GetTotalMoney();
	int32 fame = GET_SINGLE(VectorManager)->GetTotalFame();
	int32 nextMoney = GET_SINGLE(VectorManager)->GetMoney();
	int32 nextFame = GET_SINGLE(VectorManager)->GetFame();

	int _setMoney;
	if (KEY_TAP(KEY::LMB))
	{
		//성공여부
		int32 requestId = GET_SINGLE(VectorManager)->GetRequestID();
		int successCheck = GET_SINGLE(VectorManager)->requestSuccess1[requestId][characterOrder];

		if (GET_SINGLE(InputManager)->ButtonClick(1269, 630, 254, 30, _mousePos) == true)
		{

			//계산식
			 _setMoney = (int)((float)(newFee / 100.0) * (float)addMoney);
			addFame = GET_SINGLE(VectorManager)->character1Fame20[characterOrder];
			addMoney = (int)((float)(newFee/100.0) * (float)addMoney * 0.2);

			//수치변경
			_mObj->SetMoney(money - addMoney);
			_fObj->SetFame(fame + addFame);

			//값 저장
			GET_SINGLE(VectorManager)->SetTotalMoney(money - addMoney);
			GET_SINGLE(VectorManager)->SetTotalFame(fame + addFame);
			GET_SINGLE(VectorManager)->SetFame(addFame + nextFame);

			if (successCheck == 0 || successCheck == 1)
			{
				//값 저장
				GET_SINGLE(VectorManager)->SetMoney(_setMoney + nextMoney);
				GET_SINGLE(VectorManager)->successOrNot.push_back(1);
			}
			else
			{
				GET_SINGLE(VectorManager)->successOrNot.push_back(0);
			}

			OutputDebugString(L"Button2-1 Click!");
			OutputDebugString(TEXT("\n"));
			return true;
		}

		if (GET_SINGLE(InputManager)->ButtonClick(1269, 680, 254, 30, _mousePos) == true)
		{
			//계산식
			_setMoney = (int)((float)(newFee / 100.0) * (float)addMoney);
			addFame = GET_SINGLE(VectorManager)->character1Fame50[characterOrder];
			addMoney = (int)((float)(newFee / 100.0) * (float)addMoney * 0.5);

			//수치변경
			_mObj->SetMoney(money - addMoney);
			_fObj->SetFame(fame + addFame);

			//값 저장
			GET_SINGLE(VectorManager)->SetTotalMoney(money - addMoney);
			GET_SINGLE(VectorManager)->SetFame(addFame + nextFame);
			GET_SINGLE(VectorManager)->SetTotalFame(fame + addFame);

			//성공 여부 체크
			if (successCheck == 0 || successCheck == 1 || successCheck == 2)
			{
				GET_SINGLE(VectorManager)->SetMoney(_setMoney + nextMoney);
				GET_SINGLE(VectorManager)->successOrNot.push_back(1);
			}
			else
			{
				GET_SINGLE(VectorManager)->successOrNot.push_back(0);
			}

			OutputDebugString(L"Button2-2 Click!");
			OutputDebugString(TEXT("\n"));
			return true;
		}

		if (GET_SINGLE(InputManager)->ButtonClick(1269, 730, 254, 30, _mousePos) == true)
		{
			//계산식
			_setMoney = (int)((float)(newFee / 100.0) * (float)addMoney);
			addFame = GET_SINGLE(VectorManager)->character1Fame100[characterOrder];
			addMoney = (int)((float)(newFee / 100.0) * (float)addMoney * 0.5);

			//수치변경
			_mObj->SetMoney(money - addMoney);
			_fObj->SetFame(fame + addFame);

			//값 저장
			GET_SINGLE(VectorManager)->SetTotalMoney(money - addMoney);
			GET_SINGLE(VectorManager)->SetFame(addFame + nextFame);
			GET_SINGLE(VectorManager)->SetTotalFame(fame + addFame);

			//성공 여부 반환
			if (successCheck != 4)
			{
				GET_SINGLE(VectorManager)->SetMoney(_setMoney + nextMoney);
				GET_SINGLE(VectorManager)->successOrNot.push_back(1);
			}
			else
			{
				GET_SINGLE(VectorManager)->successOrNot.push_back(0);
			}

			OutputDebugString(L"Button2-3 Click!");
			OutputDebugString(TEXT("\n"));
			return true;
		}
		
	}
	return false;
}

bool ApprovalBtnClick(Vec2 _mousePos, Object* _feeObj,  bool buttonStatus, int charaterOrder)
{

	if (buttonStatus == false)
	{
		return false;
	}

	int addFame = 0;
	int addMoney = GET_SINGLE(VectorManager)->GetRequestMoney();
	int newFee = _feeObj->GetFee();
	int32 money = GET_SINGLE(VectorManager)->GetTotalMoney();
	int32 fame = GET_SINGLE(VectorManager)->GetTotalFame();
	int32 nextMoney = GET_SINGLE(VectorManager)->GetMoney();
	int32 nextFame = GET_SINGLE(VectorManager)->GetFame();
	

	if (KEY_TAP(KEY::LMB))
	{
		if (GET_SINGLE(InputManager)->ButtonClick(1520, 780, 400, 150, _mousePos) == true)
		{
			//성공여부
			int32 requestId = GET_SINGLE(VectorManager)->GetRequestID();
			int successCheck = GET_SINGLE(VectorManager)->requestSuccess1[requestId][charaterOrder];

			if (successCheck == 0)
			{
				GET_SINGLE(VectorManager)->successOrNot.push_back(1);

				//계산식
				addMoney = (int)(addMoney * (float)(newFee / 100.0));


				//값 저장
				GET_SINGLE(VectorManager)->SetMoney(nextMoney + addMoney);
				GET_SINGLE(VectorManager)->SetFame(addFame + nextFame);
			}
			else
			{
				GET_SINGLE(VectorManager)->successOrNot.push_back(0);
			}

			OutputDebugString(L"Button3 Click!");
			OutputDebugString(TEXT("\n"));

			return true;
		}
		
	}
	return false;
}

bool RefuseBtnClick(Vec2 _mousePos, Object* _feeObj, bool buttonStatus, int charaterOrder)
{

	if (buttonStatus == false)
	{
		return false;
	}

	if (KEY_TAP(KEY::LMB))
	{
		if (GET_SINGLE(InputManager)->ButtonClick(1520, 930, 250, 150, _mousePos) == true)
		{
			//거절 넣음
			GET_SINGLE(VectorManager)->successOrNot.push_back(-1);

			OutputDebugString(L"Button4 Click!");
			OutputDebugString(TEXT("\n"));

			return true;
		}
		
	}
	return false;
}

bool NextBtnClick(Vec2 _mousePos)
{
	

	if (KEY_TAP(KEY::LMB))
	{
		if (GET_SINGLE(InputManager)->ButtonClick(1000, 950, 400, 120, _mousePos) == true)
		{
			//클릭 사운드
			GET_SINGLE(ResourceManager)->PlayEffect(4);

			OutputDebugString(L"NextButton Click!");
			OutputDebugString(TEXT("\n"));

			return true;
		}

	}
	return false;
}

bool SkipBtnClick(Vec2 _mousePos)
{

	if (KEY_TAP(KEY::LMB))
	{
		if (GET_SINGLE(InputManager)->ButtonClick(1500, 950, 400, 120, _mousePos) == true)
		{
			//클릭 사운드
			GET_SINGLE(ResourceManager)->PlayEffect(4);

			OutputDebugString(L"SkipButton Click!");
			OutputDebugString(TEXT("\n"));

			return true;
		}

	}
	return false;
}

bool CreditBtnClick(Vec2 _mousePos)
{
	if (KEY_TAP(KEY::LMB))
	{
		if (GET_SINGLE(InputManager)->ButtonClick(1720, 920, 150, 100, _mousePos) == true)
		{
			//클릭 사운드
			GET_SINGLE(ResourceManager)->PlayEffect(4);

			OutputDebugString(L"CreditButton Click!");
			OutputDebugString(TEXT("\n"));

			return true;
		}

	}
	return false;
}


bool StartBtnClick(Vec2 _mousePos)
{
	

	if (KEY_TAP(KEY::LMB))
	{
		if (GET_SINGLE(InputManager)->ButtonClick(920, 700, 450, 120, _mousePos) == true)
		{
			//클릭 사운드
			GET_SINGLE(ResourceManager)->PlayEffect(4);

			OutputDebugString(L"StartButton Click!");
			OutputDebugString(TEXT("\n"));

			return true;
		}

	}
	return false;
}

bool EndBtnClick(Vec2 _mousePos)
{
	

	if (KEY_TAP(KEY::LMB))
	{
		if (GET_SINGLE(InputManager)->ButtonClick(920, 870, 450, 120, _mousePos) == true)
		{
			//클릭 사운드
			GET_SINGLE(ResourceManager)->PlayEffect(4);

			OutputDebugString(L"ExitButton Click!");
			OutputDebugString(TEXT("\n"));

			return true;
		}

	}
	return false;
}

bool IsScriptClick(Vec2 _mousePos)
{
	

	if (KEY_TAP(KEY::LMB))
	{
		if (GET_SINGLE(InputManager)->ButtonClick(400, 0, 1120, 680, _mousePos) == true)
		{
			//클릭 사운드
			GET_SINGLE(ResourceManager)->PlayEffect(4);

			OutputDebugString(L"Mouse Click");
			OutputDebugString(TEXT("\n"));
			return true;
		}
	}
	return false;
}

void popUPImage(Object* _pObj, Object* _idObj, CharacterName characterName)
{
	tEvent evn = {};
	evn.eEVEN = EventType::PLAYEVENT;
	evn.lParam = (DWORD_PTR)_pObj;
	evn.pEVEN = PlayEventType::ADVON;
	//_pObj->SetAlpha(255);
	_pObj->SetCharacterName(characterName);
	//_idObj->SetPos(Vec2(200,800));
	_idObj->SetAlpha(255);
	_idObj->SetCharacterName(characterName);

	EventManager::GetInstance()->AddEvent(evn);
}

void popUPScript(Object* _pObj)
{
	tEvent evn = {};
	evn.eEVEN = EventType::PLAYEVENT;
	evn.lParam = (DWORD_PTR)_pObj;
	evn.pEVEN = PlayEventType::ADVON;
	_pObj->SetAlpha(255);

	EventManager::GetInstance()->AddEvent(evn);
}

void popDownScript(Object* _pObj)
{
	tEvent evn = {};
	evn.eEVEN = EventType::PLAYEVENT;
	evn.lParam = (DWORD_PTR)_pObj;
	evn.pEVEN = PlayEventType::ADVOFF;
	_pObj->SetAlpha(0);
	_pObj->SetScript(L" ");

	EventManager::GetInstance()->AddEvent(evn);
}


bool Speak(Object* _pObj, int num, int characterOlder)
{
	if (num == 0)
	{
		_pObj->SetScript(GET_SINGLE(VectorManager)->script1[characterOlder]);
		if (GET_SINGLE(VectorManager)->script1[characterOlder] == L" ")
		{
			return true;
		}
			
	}
	if (num == 1)
	{
		_pObj->SetScript(GET_SINGLE(VectorManager)->script2[characterOlder]);
		if (GET_SINGLE(VectorManager)->script2[characterOlder] == L" ")
		{
			return true;
		}
	}
	if (num == 2)
	{
		_pObj->SetScript(GET_SINGLE(VectorManager)->script3[characterOlder]);
		if (GET_SINGLE(VectorManager)->script3[characterOlder] == L" ")
		{
			return true;
		}
	}
	if (num == 3)
	{
		_pObj->SetScript(GET_SINGLE(VectorManager)->script4[characterOlder]);
		if (GET_SINGLE(VectorManager)->script4[characterOlder] == L" ")
		{
			return true;
		}
	}
	if (num == 4)
	{
		_pObj->SetScript(GET_SINGLE(VectorManager)->script5[characterOlder]);
		if (GET_SINGLE(VectorManager)->script5[characterOlder] == L" ")
		{
			return true;
		}
	}
	if (num == 5)
	{
		_pObj->SetScript(GET_SINGLE(VectorManager)->script6[characterOlder]);
		if (GET_SINGLE(VectorManager)->script6[characterOlder] == L" ")
		{
			return true;
		}
	}
	if (num == 6)
	{
		_pObj->SetScript(GET_SINGLE(VectorManager)->script7[characterOlder]);
		if (GET_SINGLE(VectorManager)->script7[characterOlder] == L" ")
		{
			return true;
		}
	}
	if (num == 7)
	{
		_pObj->SetScript(GET_SINGLE(VectorManager)->script8[characterOlder]);
		if (GET_SINGLE(VectorManager)->script8[characterOlder] == L" ")
		{
			return true;
		}
	}
	if (num == 8)
	{
		_pObj->SetScript(GET_SINGLE(VectorManager)->script9[characterOlder]);
		if (GET_SINGLE(VectorManager)->script9[characterOlder] == L" ")
		{
			return true;
		}
	}
	if (num == 9)
	{
		_pObj->SetScript(GET_SINGLE(VectorManager)->script10[characterOlder]);
		if (GET_SINGLE(VectorManager)->script10[characterOlder] == L" ")
		{
			return true;
		}
	}
	if (num == 10)
	{
		_pObj->SetScript(GET_SINGLE(VectorManager)->scriptBargain1[characterOlder]);
		if (GET_SINGLE(VectorManager)->script10[characterOlder] == L" ")
		{
			return true;
		}
	}
	if (num == 11)
	{
		_pObj->SetScript(GET_SINGLE(VectorManager)->scriptBargain2[characterOlder]);
		if (GET_SINGLE(VectorManager)->script10[characterOlder] == L" ")
		{
			return true;
		}
	}
	if (num == 12)
	{
		_pObj->SetScript(GET_SINGLE(VectorManager)->scriptBargain3[characterOlder]);
		if (GET_SINGLE(VectorManager)->script10[characterOlder] == L" ")
		{
			return true;
		}
	}
	if (num == 13)
	{
		_pObj->SetScript(GET_SINGLE(VectorManager)->scriptSupport[characterOlder]);
		if (GET_SINGLE(VectorManager)->script10[characterOlder] == L" ")
		{
			return true;
		}
	}
	if (num == 14)
	{
		_pObj->SetScript(GET_SINGLE(VectorManager)->scriptApproval[characterOlder]);
		if (GET_SINGLE(VectorManager)->script10[characterOlder] == L" ")
		{
			return true;
		}
	}
	if (num == 15)
	{
		_pObj->SetScript(GET_SINGLE(VectorManager)->scriptRefuse[characterOlder]);
		if (GET_SINGLE(VectorManager)->script10[characterOlder] == L" ")
		{
			return true;
		}
	}
	if (num == 16)
	{
		int32 characterOrder = characterOlder - 21;
		_pObj->SetScript(GET_SINGLE(VectorManager)->coreRequestSupport[characterOrder]);
		GET_SINGLE(VectorManager)->SetCore(characterOrder);
		
	}
	if (num == 17)
	{
		int32 characterOrder = characterOlder - 21;
		_pObj->SetScript(GET_SINGLE(VectorManager)->coreRequestApproval[characterOrder]);
		GET_SINGLE(VectorManager)->SetCore(characterOrder);
		
	}

	if (num == 20)
	{
		_pObj->SetScript(GET_SINGLE(VectorManager)->scriptReturn[characterOlder]);

	}

	tEvent evn = {};
	evn.eEVEN = EventType::PLAYEVENT;
	evn.lParam = (DWORD_PTR)_pObj;
	evn.pEVEN = PlayEventType::DIALOGUE;

	EventManager::GetInstance()->AddEvent(evn);
	return false;
}




