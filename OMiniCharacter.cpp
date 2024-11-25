#include "pch.h"
#include "OMiniCharacter.h"
#include "ResourceManager.h"

void OMiniCharacter::Update()
{
	alphaValue = GetAlpha();
	x = GetposX();
	y = GetposY();
}

void OMiniCharacter::Render(HDC hdc)
{
	CharacterName cName = GetCharacterName();
	HBITMAP HBitMap = {};

	switch (cName)
	{
	case CharacterName::catfighter1:
	{
		HBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\Character\\catfighter1.bmp");
		break;
	}
	case CharacterName::catfighter2:
	{
		HBITMAP HBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\Character\\catfighter2.bmp");
		break;
	}
	case CharacterName::dwarf_1:
	{
		HBITMAP HBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\Character\\Dwarf_1.bmp");
		break;
	}
	case CharacterName::dwarf_2:
	{
		HBITMAP HBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\Character\\Dwarf_2.bmp");
		break;
	}
	case CharacterName::herbalist1:
	{
		HBITMAP HBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\Character\\herbalist1.bmp");
		break;
	}
	case CharacterName::herbalist2:
	{
		HBITMAP HBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\Character\\herbalist2.bmp");
		break;
	}
	case CharacterName::herbalist3:
	{
		HBITMAP HBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\Character\\herbalist3.bmp");
		break;
	}
	case CharacterName::herbalist4:
	{
		HBITMAP HBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\Character\\herbalist4.bmp");
		break;
	}
	case CharacterName::ninza1:
	{
		HBITMAP HBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\Character\\ninza1.bmp");
		break;
	}
	case CharacterName::ninza2:
	{
		HBITMAP HBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\Character\\ninza2.bmp");
		break;
	}
	case CharacterName::lilian:
	{
		HBITMAP HBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\Character\\Lilian.bmp");
		break;
	}
	case CharacterName::eden:
	{
		HBITMAP HBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\Character\\eden.bmp");
		break;
	}
	case CharacterName::darius:
	{
		HBITMAP HBitMap = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\Character\\Darius.bmp");
		break;
	}

	}
	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, HBitMap, x, y, alphaValue);
}
