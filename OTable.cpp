#include "pch.h"
#include "OTable.h"
#include "ResourceManager.h"
#include "InputManager.h"

#include "Collider.h"

OTable::OTable()
{

}

OTable::~OTable()
{

}

void OTable::Update()
{

}

//�÷��̾� ������ �ֵ��� �ٲٱ�
void OTable::Render(HDC hdc)
{
	bool test = GET_SINGLE(InputManager)->IsDeskEmpty();



	HBITMAP hBitmap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\main\\desk.bmp");
	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hBitmap, 0, 680, 255);
	
}
