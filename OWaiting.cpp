#include "pch.h"
#include "OWaiting.h"
#include "ResourceManager.h"
#include "ObjectManager.h"
#include "Adventurer.h"

OWaiting::OWaiting()
{
	
}

void OWaiting::Update()
{
	//TODO
	//������� ���� ������Ʈ �Ǿ�� �� -> ���� ���� ���� �� �Ѵ�
	_totalNum = 8;
	_curNum = GetWaiting();
	_printWord = to_wstring(_curNum);
}

void OWaiting::Render(HDC hdc)
{
	HBITMAP hBitmap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\main\\queueing.bmp");
	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hBitmap, 1520, 150, 255);

	GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hBitmap, 1570, 200, _printWord.c_str(), 60);
}
