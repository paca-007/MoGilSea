#pragma once
class VectorManager
{

	DECLARE_SINGLE(VectorManager);

public:
	void Datainit();
	
private:

	int32 totalMoney = 2000; // ����â���� �Ѳ����� ó���ؾ���
	int32 totalFame = 0;
	int32 getMoney = 0;
	int32 getFame = 0;
	int32 year = 1;
	int32 core = -1;

	// �Ƿ� ����
	int32 requestID = 0;
	int32 requestMoney = 0;
	bool  isRequestReturned = false;	// NPC ���� �Ƿڰ� ���޵Ǿ��°�
	bool  isIDCardReturned = false;	// NPC ���� ���谡 ī�带 �����־��°�
	bool  isPartyListReturned = false;	// NPC ���� ��Ƽ ����Ʈ ������ �����־��°�
	bool  isWeaponListReturned = false; // NPC ���� ��� ����Ʈ ������ �����־��°�

	
public:
	void SetMoney(int32 _money) { getMoney = _money; }
	int32 GetMoney() { return getMoney; }

	void SetFame(int32 _fame) { getFame = _fame; }
	int32 GetFame() { return getFame; }

	void SetTotalMoney(int32 _totalMoney) { totalMoney = _totalMoney; }
	int32 GetTotalMoney() { return totalMoney; }

	void SetTotalFame(int32 _totalFame) { totalFame = _totalFame; }
	int32 GetTotalFame() { return totalFame; }

	void SetYear(int32 _year) { year = _year; }
	int32 GetYear() { return year; }

	void SetCore(int32 _core) { core = _core; }
	int32 GetCore() { return core; }

	// �Ƿ� ���� ���� �� �������� �Լ�
	void SetRequestID(int32 ID) { requestID = ID; }
	int32 GetRequestID() { return requestID; }
	void SetRequestMoney(int32 money) { requestMoney = money; }
	int32 GetRequestMoney() { return requestMoney; }
	void SetIsRequestReturned(bool isReturned) { isRequestReturned = isReturned; }	// �Ƿڰ� ���޵Ǿ��°�~
	bool GetIsRequestReturned() { return isRequestReturned; }
	
	// ���谡 ī�� ���� �Լ�
	void SetIsIDCardReturned(bool isReturned) { isIDCardReturned = isReturned; }	// ���谡 ī�带 �����־��°�~
	bool GetIsIDCardReturned() { return isIDCardReturned; }

	// ��Ƽ ����Ʈ ���� ���� �Լ�
	void SetIsPartyListReturned(bool isReturned) { isPartyListReturned = isReturned; }
	bool GetIsPartyListRetuend() { return isPartyListReturned; }

	// ��� ����Ʈ ���� ���� �Լ�
	void SetIsWeaponListReturned(bool isReturned) { isWeaponListReturned = isReturned; }
	bool GetIsWeaponListRetuend() { return isWeaponListReturned; }

public:
	//���� ����
	vector<int32> successOrNot; // ������ 1 ���н� 0�� ��ȯ ������ -1
	vector<int32> npcRequestID;

	vector<CharacterName> characterAppear1;
	
	vector<int32> subArr1;
	vector<int32> mainArr1;
	vector<int32> subArr2;
	vector<int32> mainArr2;
	vector<int32> subArr3;
	vector<int32> mainArr3;

	vector<int32> bargainCount1;
	vector<int32> characterFee1;
	vector<int32> character1Fame20;
	vector<int32> character1Fame50;
	vector<int32> character1Fame100;
	
	///�Ƿ� ���� ����
	int32 requestSuccess1[22][8] = {
		{0,0,0,0,0,0,2,1},
		{0,0,0,1,0,2,0,0},
		{1,0,3,0,0,1,3,4},
		{0,0,3,0,1,1,4,1},
		{0,0,0,0,0,3,3,3},
		{4,0,4,4,4,4,4,4},
		{2,0,4,0,4,4,4,4},
		{0,1,0,1,0,2,0,4},
		{0,0,0,0,0,1,1,0},
		{0,4,4,2,0,4,1,4},
		{0,1,0,0,0,0,0,0},
		{0,2,0,0,0,4,0,0},
		{0,3,0,1,0,3,0,0},
		{2,4,0,3,0,4,0,4},
		{0,4,1,3,0,1,2,3},
		{0,1,0,0,0,0,0,1},
		{0,0,0,0,0,0,1,0},
		{0,4,2,0,0,0,3,1},
		{0,4,4,4,0,0,0,2},
		{0,2,4,1,0,0,3,3},
		{0,3,4,3,0,0,1,3},
		{4,4,4,4,4,0,0,0},
	};

	vector<wstring> script1; //0
	vector<wstring> script2; //1
	vector<wstring> script3; //2
	vector<wstring> script4; //3
	vector<wstring> script5; //4
	vector<wstring> script6; //5
	vector<wstring> script7; //6
	vector<wstring> script8; //7
	vector<wstring> script9; //8
	vector<wstring> script10; //9
	vector<wstring> scriptReturn; // 20
	
	vector<wstring> scriptBargain1; //10
	vector<wstring> scriptBargain2; //11
	vector<wstring> scriptBargain3; //12

	vector<wstring> scriptSupport; //13
	vector<wstring> scriptApproval; //14
	vector<wstring> scriptRefuse; //15
	vector<wstring> coreRequestSupport; //16
	vector<wstring> coreRequestApproval; //17
	

	vector<wstring> scriptFeedback1;

	// �Ƿ� ����
	vector<wstring> requestName1;
	vector<wstring> requestName2;
	vector<wstring> requestName3;
	vector<wstring> requestScript1;
	vector<wstring> requestScript2;
	vector<wstring> requestScript3;
	vector<wstring> requestReward1;
	vector<wstring> requestReward2;
	vector<wstring> requestReward3;
	vector<wstring> requestRank1;
	vector<wstring> requestRank2;
	vector<wstring> requestRank3;

	// ��Ƽ�� ����
	vector<wstring> partyList1;
	vector<wstring> partyList2;
	vector<wstring> partyList3;
	vector<wstring> partyList4;
	vector<wstring> partyList5;
	vector<wstring> partyList6;
	vector<wstring> partyList7;
	vector<wstring> partyList8;
	vector<wstring> partyList9;
	vector<wstring> partyList10;
	vector<wstring> partyList11;
	vector<wstring> partyList12;
	vector<wstring> partyList13;

	// ��� ����
	vector<wstring> weaponList1;
	vector<wstring> weaponList2;
	vector<wstring> weaponList3;
	vector<wstring> weaponList4;
	vector<wstring> weaponList5;
	vector<wstring> weaponList6;
	vector<wstring> weaponList7;
	vector<wstring> weaponList8;
	vector<wstring> weaponList9;
	vector<wstring> weaponList10;
	vector<wstring> weaponList11;
	vector<wstring> weaponList12;
	vector<wstring> weaponList13;

	vector<wstring> requestSucess;
	vector<wstring> requestFail;
	vector<wstring> requestNotGet;

};

