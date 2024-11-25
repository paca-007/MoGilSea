#include "pch.h"
#include "OCharacter.h"
#include "ResourceManager.h"



void OCharacter::Update()
{
	alphaValue = GetAlpha();
	//OutputDebugString(TEXT("Ocharacter :  "));
	//OutputDebugString(to_wstring(alphaValue).c_str());
	//OutputDebugString(TEXT("\n"));
}

void OCharacter::Render(HDC hdc)
{
	CharacterName cName = GetCharacterName();

	switch (cName)
	{
	case CharacterName::catfighter1:
	{
		HBITMAP catfighter1 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\Character\\catfighter1.bmp");
		GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, catfighter1, 450, 30, alphaValue);
		break;
	}
	case CharacterName::catfighter2:
	{
		HBITMAP catfighter2 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\Character\\catfighter2.bmp");
		GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, catfighter2, 450, 30, alphaValue);
		break;
	}
	case CharacterName::dwarf_1:
	{
		HBITMAP dwarf_1 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\Character\\Dwarf_1.bmp");
		GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, dwarf_1, 500, 30, alphaValue);
		break;
	}
	case CharacterName::dwarf_2:
	{
		HBITMAP dwarf_2 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\Character\\Dwarf_2.bmp");
		GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, dwarf_2, 500, 30, alphaValue);
		break;
	}
	case CharacterName::herbalist1:
	{
		HBITMAP herbalist1 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\Character\\herbalist1.bmp");
		GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, herbalist1, 500, 30, alphaValue);
		break;
	}
	case CharacterName::herbalist2:
	{
		HBITMAP herbalist2 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\Character\\herbalist2.bmp");
		GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, herbalist2, 500, 30, alphaValue);
		break;
	}
	case CharacterName::herbalist3:
	{
		HBITMAP herbalist3 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\Character\\herbalist3.bmp");
		GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, herbalist3, 500, 30, alphaValue);
		break;
	}
	case CharacterName::herbalist4:
	{
		HBITMAP herbalist4 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\Character\\herbalist4.bmp");
		GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, herbalist4, 500, 30, alphaValue);
		break;
	}
	case CharacterName::ninza1:
	{
		HBITMAP ninza1 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\Character\\ninza1.bmp");
		GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, ninza1, 500, 0, alphaValue);
		break;
	}
	case CharacterName::ninza2:
	{
		HBITMAP ninza2 = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\Character\\ninza2.bmp");
		GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, ninza2, 500, 0, alphaValue);
		break;
	}
	case CharacterName::lilian:
	{
		HBITMAP lilian = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\Character\\Lilian.bmp");
		GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, lilian, 450, 30, alphaValue);
		break;
	}
	case CharacterName::eden:
	{
		HBITMAP eden = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\Character\\eden.bmp");
		GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, eden, 500, 30, alphaValue);
		break;
	}
	case CharacterName::darius:
	{
		HBITMAP darius = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\Character\\Darius.bmp");
		GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, darius, 400, 70, alphaValue);
		break;
	}
	}

}

	



