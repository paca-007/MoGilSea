#pragma once

enum class KEY_STATE
{
	NONE,	// 눌리지 않았고, 이전에도 눌리지 않은 상태
	TAP,	// 막 누른 시점
	HOLD,	// 누르고 있는
	AWAY,	// 막 뗀 시점
};

enum class KEY	
{
	LMB,
	RMB,
	ESC,
	UP,
	DOWN,
	LAST
};

struct tKeyInfo
{
	KEY_STATE	eState;		// 키의 상태값
	bool		bPrevPush;		// 이전 프레임에서 눌렸는지 여부
};

class InputManager
{
	DECLARE_SINGLE(InputManager);

private:
	HWND _hwnd = 0;
	vector<tKeyInfo> m_vecKey;
	//int32 m_deskCount;
	bool isRequestOntheDesk = false;
	bool isIDcardOntheDesk = true;
	bool isDocumentOntheDesk = true;

public:
	void Init(HWND hwnd);
	void Update();

	void SetHwnd(HWND hwnd) { _hwnd = hwnd; }
	HWND GetHwnd() { return _hwnd; }
	

	Vec2 GetMouseCursorPosition();

	bool ButtonClick(int32 x, int32 y, int32 width, int32 height, Vec2 pos);

	bool HoverCheck(int32 x, int32 y, int32 width, int32 height, Vec2 pos);

	/// 책상 비워짐 체크 관련 함수들
	bool IsDeskEmpty();
	//void SetDeskCount(int32 deskCount) { m_deskCount = deskCount; }

	void SetIsRequestOntheDesk(bool requestOn) { isRequestOntheDesk = requestOn; }
	void SetIsIDcardOntheDesk(bool idCardOn) { isIDcardOntheDesk = idCardOn; }
	void SetIsDocumentOntheDesk(bool documentOn) { isDocumentOntheDesk = documentOn; }

	/// 문서 데이터 인식 관련 함수
	
	

protected:
	Vec2 _pos = {};
public:
	KEY_STATE GetKeyState(KEY _eKey) { return m_vecKey[(int32)_eKey].eState; }


	// 디버깅 정보를 출력하는가의 여부
private:
	bool m_IsRenderDebug;

public:
	bool GetIsRenderDebug() const { return m_IsRenderDebug; }

	// UI 관련
private:
	int32 m_nowDepth = 0;
	int32 m_holdingDepth = 0;

public:
	int32 GetNowDepth();
	int32 GetHoldingDepth() const { return m_holdingDepth; }
	void SetHoldingDepth(int32 val) { m_holdingDepth = val; }

};

