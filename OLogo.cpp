#include "pch.h"
#include "OLogo.h"
#include "ResourceManager.h"

void OLogo::Update()
{

}

void OLogo::Render(HDC hdc)
{
	HBITMAP logoHbitmap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\main\\guildlogo.bmp");
	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, logoHbitmap, 1520, 0, 255);
}
