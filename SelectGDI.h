#pragma once

class SelectGDI
{
private:
	HDC		m_hDC;
	HPEN	m_hDefaultPen;
	HBRUSH	m_hDefaultBrush;

public:
	SelectGDI(HDC _dc, PenType _ePenType);
	SelectGDI(HDC _dc, BrushType _ePenType);
	~SelectGDI();
};

