#pragma once
class GameCore
{
public:
	GameCore();
	~GameCore();

	void Init(HWND hwnd);
	void Update();
	void Render();

	HBRUSH GetBrush(BrushType _eType) { return m_arrBrush[(UINT)_eType]; }
	HPEN GetPen(PenType _eType) { return m_arrPen[(UINT)_eType]; }
	
private:
	HWND _hwnd = {};
	HDC _hdc = {};

	// Double Buffering
	RECT _rect;
	HDC _hdcBack = {};
	HBITMAP _bmpBack = {};

	// 자주 사용하는 GDI Object
	HBRUSH	m_arrBrush[(UINT)BrushType::END];
	HPEN	m_arrPen[(UINT)PenType::END];

	void CreateBrushPen();
	
};

