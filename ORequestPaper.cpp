#include "pch.h"
#include "ORequestPaper.h"
#include "ResourceManager.h"
#include "Collider.h"

ORequestPaper::ORequestPaper()
{
	CreateCollider();
	GetCollider()->SetOffsetPos(Vec2(0.f, 0.f));
	GetCollider()->SetScale(Vec2(500.f, 340.f));
}

ORequestPaper::~ORequestPaper()
{

}


void ORequestPaper::Update()
{
	
}

void ORequestPaper::Render(HDC hdc)
{
	HBITMAP hBitmapRequestPaper = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\Dummy\\d_request (desk).bmp");
	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hBitmapRequestPaper, 800, 700, 255);
	
}

