#pragma once
#include"VectorManager.h"

class Collider;
class Object
{
public:
	Object();
	virtual ~Object();

	friend class EventManager;


	virtual void Init();
	virtual void Update();
	virtual void FinalUpdate() final;
	virtual void Render(HDC hdc);

	virtual void OnPicking() {};

	void ComponentRender(HDC _dc);

	void SetPos(Vec2 pos) { m_vPos = pos; }
	void SetScale(Vec2 scale) { m_vScale = scale; }

	Vec2 GetPos() { return m_vPos; }
	Vec2 GetScale() { return m_vScale; }

	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }

	Collider* GetCollider() { return m_pCollider; }

	void CreateCollider();

	virtual void OnCollision(Collider* _pOther) {}
	virtual void OnCollisionEnter(Collider* _pOther) {}
	virtual void OnCollisionExit(Collider* _pOther) {}

	ObjectType GetObjectType() { return _type; }

	bool IsDead() { return !m_bAlive; }

	//alpha�� ����
	int GetAlpha() { return gAlpha; };
	void SetAlpha(int _gAlpha) { gAlpha = _gAlpha; };

	//script�� ����
	void SetScript(wstring script) { _script = script; }
	wstring GetScript() { return _script; }

	//�Ƿڼ� script �� ����
	void SetRequestNameScript(wstring script) { _requestScriptName = script; }
	wstring GetRequestNameScript() { return _requestScriptName; }

	void SetRequestScript(wstring script) { _requestScript = script; }
	wstring GetRequestScript() { return _requestScript; }

	void SetRequestRewardScript(wstring script) { _requestScriptReward = script; }
	wstring GetRequestameRewardScript() { return _requestScriptReward; }

	//��Ƽ ����Ʈ script �� ����
	void SetPartyMemberScript1(wstring script) { _partyMember1 = script; }
	wstring GetPartyMemberScript1() { return _partyMember1; }
	void SetPartyScript1(wstring script) { _partyScript1 = script; }
	wstring GetPartyScript1() { return _partyScript1; }
	void SetPartyRankScript1(wstring script) { _partyRank1 = script; }
	wstring GetPartyRankScript1() { return _partyRank1; }

	void SetPartyMemberScript2(wstring script) { _partyMember2 = script; }
	wstring GetPartyMemberScript2() { return _partyMember2; }
	void SetPartyScript2(wstring script) { _partyScript2 = script; }
	wstring GetPartyScript2() { return _partyScript2; }
	void SetPartyRankScript2(wstring script) { _partyRank2 = script; }
	wstring GetPartyRankScript2() { return _partyRank2; }

	void SetPartyMemberScript3(wstring script) { _partyMember3 = script; }
	wstring GetPartyMemberScript3() { return _partyMember3; }
	void SetPartyScript3(wstring script) { _partyScript3 = script; }
	wstring GetPartyScript3() { return _partyScript3; }
	void SetPartyRankScript3(wstring script) { _partyRank3 = script; }
	wstring GetPartyRankScript3() { return _partyRank3; }

	//��� ����Ʈ script �� ����
	void SetWeaponKindScript1(wstring script) { _weaponKind1 = script; }
	wstring GetWeaponKindScript1() { return _weaponKind1; }
	void SetPriceScript1(wstring script) { _weaponPrice1 = script; }
	wstring GetPriceScript1() { return _weaponPrice1; }
	void SetWeaponRankScript1(wstring script) { _weaponRank1 = script; }
	wstring GetWeaponRankScript1() { return _weaponRank1; }

	void SetWeaponKindScript2(wstring script) { _weaponKind2 = script; }
	wstring GetWeaponKindScript2() { return _weaponKind2; }
	void SetPriceScript2(wstring script) { _weaponPrice2 = script; }
	wstring GetPriceScript2() { return _weaponPrice2; }
	void SetWeaponRankScript2(wstring script) { _weaponRank2 = script; }
	wstring GetWeaponRankScript2() { return _weaponRank2; }

	void SetWeaponKindScript3(wstring script) { _weaponKind3 = script; }
	wstring GetWeaponKindScript3() { return _weaponKind3; }
	void SetPriceScript3(wstring script) { _weaponPrice3 = script; }
	wstring GetPriceScript3() { return _weaponPrice3; }
	void SetWeaponRankScript3(wstring script) { _weaponRank3 = script; }
	wstring GetWeaponRankScript3() { return _weaponRank3; }

	void SetWeaponKindScript4(wstring script) { _weaponKind4 = script; }
	wstring GetWeaponKindScript4() { return _weaponKind4; }
	void SetPriceScript4(wstring script) { _weaponPrice4 = script; }
	wstring GetPriceScript4() { return _weaponPrice4; }
	void SetWeaponRankScript4(wstring script) { _weaponRank4 = script; }
	wstring GetWeaponRankScript4() { return _weaponRank4; }

	//money�� ����
	void SetMoney(int32 _money) { money = _money; }
	int32 GetMoney() { return money; }

	//fame�� ����
	void SetFame(int32 _fame) { fame = _fame; }
	int32 GetFame() { return fame; }

	//fee�� ����
	void SetFee(int32 _fee) { fee = _fee; }
	int32 GetFee() { return fee; }

	//waiting�� ����
	void SetWaiting(int32 _waiting) { waiting = _waiting; }
	int32 GetWaiting() { return waiting; }

	//characterName �� ����
	void SetCharacterName(CharacterName _characterName) { characterName = _characterName; }
	CharacterName GetCharacterName() { return characterName; }

	//button���� ����
	void SetButtonStatus(bool _buttonStatus) { buttonStatus = _buttonStatus; }
	bool GetButtonStatus() { return buttonStatus; }

	//x��ǥ������
	void SetposX(int32 _posX) { posX = _posX; }
	int32 GetposX() { return posX; }

	//y��ǥ������
	void SetposY(int32 _posY) { posY = _posY; }
	int32 GetposY() { return posY; }

	//year����
	void SetYear(int32 _year) { year = _year; }
	int32 GetYear() { return year; }

	//feedbackType ����
	void SetFeedbackType(FeedbackSceneType _feedbackType) { feedbackType = _feedbackType; }
	FeedbackSceneType GetFeedbackType() { return feedbackType; }

	//endingType ����
	void SetEndingType(EndingSceenType _endingType) { endingType = _endingType; }
	EndingSceenType GetEndingType() { return endingType; }

	//scriptNumber ����
	void SetendingScript(int32 _endingScript) { endingScrpit = _endingScript; }
	int32 GetendingScript() { return endingScrpit; }

	//xWidth ����
	void SetXWidth(int32 _xWidth) { xWidth = _xWidth; }
	int32 GetXWidth() { return xWidth; }

	//yWidth ����
	void SetYWidth(int32 _yWidth) { yWidth = _yWidth; }
	int32 GetYWidth() { return yWidth; }

	//opening Ÿ�� ��ȯ
	void SetOpeningType(OpeningSceneType _openingType) { openingType = _openingType; }
	OpeningSceneType GetOpeningType() { return openingType; }

	void SetDead() { m_bAlive = false; }

	void SetDepth(int32 _depth) { m_depth = _depth; }
	int32 GetDepth() { return m_depth; }

	void SetHolding(bool state) { _isClicked = state; }
	bool IsHolding() { return _isClicked; }

	void SetIsFocused(bool isFocused) { _isFocused = isFocused; }
	bool GetIsFocused() { return _isFocused; }

	// request �� money �� ID �� ����
	void SetRequestMoney(int32 money) { m_requestMoney = money; }
	void SetRequestID(int32 ID) { m_requestID = ID; }
	int32 GetRequestMoney() { return m_requestMoney; }
	int32 GetRequestID() { return m_requestID; }

	// request �� ��� ����
	void SetRequestRankType(RequestRank _rank) { requestRankType = _rank; }
	RequestRank GetRequestRankType() { return requestRankType; }

	// object �� ���� ����
	void SetObjectState(ObjectState _ObjectState) { objectState = _ObjectState; }
	ObjectState GetObjectState() { return objectState; }

protected:
	bool		_isClicked = false;
	bool		_isFocused = false;
	int32		m_depth;		// UI�� ����. �̰��� �̿��ؼ� �׸����� ���ĳ� ��ŷ�� �켱������ ���Ѵ�.
private:

	wstring		m_strName;

	Vec2		m_vPos = {};
	Vec2		m_vScale = {};

	ObjectState objectState;

	Collider*	m_pCollider;

	bool		m_bAlive;

	int32 gAlpha = 0;	// ĳ���Ͱ� �Ⱥ��̴� ����, ���̴� ���� = 255
	wstring _script;
	int32 fee = 50;
	int32 waiting = 0;
	int32 money = GET_SINGLE(VectorManager)->GetTotalMoney();
	int32 fame = GET_SINGLE(VectorManager)->GetTotalFame();
	int32 year = GET_SINGLE(VectorManager)->GetYear();

	int32 posX = 0;
	int32 posY = 0;

	int32 m_requestMoney;
	int32 m_requestID;

	wstring _requestScriptName;
	wstring _requestScript;
	wstring _requestScriptReward;

	wstring _partyMember1;
	wstring _partyScript1;
	wstring _partyRank1;
	wstring _partyMember2;
	wstring _partyScript2;
	wstring _partyRank2;
	wstring _partyMember3;
	wstring _partyScript3;
	wstring _partyRank3;

	wstring _weaponKind1;
	wstring _weaponPrice1;
	wstring _weaponRank1;
	wstring _weaponKind2;
	wstring _weaponPrice2;
	wstring _weaponRank2;
	wstring _weaponKind3;
	wstring _weaponPrice3;
	wstring _weaponRank3;
	wstring _weaponKind4;
	wstring _weaponPrice4;
	wstring _weaponRank4;

	RequestRank requestRankType;


	bool buttonStatus = true; // ��ư ���� ����

	//ĳ���� �̸� ��ȯ
	CharacterName characterName;

	//feedback�� �Լ���
	FeedbackSceneType  feedbackType;
	int32 xWidth;
	int32 yWidth;

	//Ending�� �Լ���
	EndingSceenType endingType;
	int32 endingScrpit = 0;

	//opeining�� �Լ���
	OpeningSceneType openingType;



protected:

	ObjectType _type = ObjectType::NONE;
	/*queue<wstring> waiting;
	bool queueCheck = true;*/

};

