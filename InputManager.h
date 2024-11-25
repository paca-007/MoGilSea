#pragma once

enum class KEY_STATE
{
	NONE,	// ������ �ʾҰ�, �������� ������ ���� ����
	TAP,	// �� ���� ����
	HOLD,	// ������ �ִ�
	AWAY,	// �� �� ����
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
	KEY_STATE	eState;		// Ű�� ���°�
	bool		bPrevPush;		// ���� �����ӿ��� ���ȴ��� ����
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

	/// å�� ����� üũ ���� �Լ���
	bool IsDeskEmpty();
	//void SetDeskCount(int32 deskCount) { m_deskCount = deskCount; }

	void SetIsRequestOntheDesk(bool requestOn) { isRequestOntheDesk = requestOn; }
	void SetIsIDcardOntheDesk(bool idCardOn) { isIDcardOntheDesk = idCardOn; }
	void SetIsDocumentOntheDesk(bool documentOn) { isDocumentOntheDesk = documentOn; }

	/// ���� ������ �ν� ���� �Լ�
	
	

protected:
	Vec2 _pos = {};
public:
	KEY_STATE GetKeyState(KEY _eKey) { return m_vecKey[(int32)_eKey].eState; }


	// ����� ������ ����ϴ°��� ����
private:
	bool m_IsRenderDebug;

public:
	bool GetIsRenderDebug() const { return m_IsRenderDebug; }

	// UI ����
private:
	int32 m_nowDepth = 0;
	int32 m_holdingDepth = 0;

public:
	int32 GetNowDepth();
	int32 GetHoldingDepth() const { return m_holdingDepth; }
	void SetHoldingDepth(int32 val) { m_holdingDepth = val; }

};

