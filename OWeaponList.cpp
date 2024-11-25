#include "pch.h"
#include "OWeaponList.h"

#include "ResourceManager.h"
#include "ObjectManager.h"

#include "TimeManager.h"
#include "InputManager.h"

OWeaponList::OWeaponList()
{
	SetScale(Vec2(500, 400));
	SetObjectState(ObjectState::ON_THE_DESK);
}

OWeaponList::~OWeaponList()
{
}

void OWeaponList::Update()
{

}

void OWeaponList::Render(HDC hdc)
{
	Vec2 vCurPos = GetPos();
	Vec2 vScale = GetScale();

	//CharacterName characterName = GetCharacterName();

	HBITMAP hWeaponList;
	_mousePos = GET_SINGLE(InputManager)->GetMouseCursorPosition();

	Vec2 rq = this->GetPos();

	/// 장비 리스트 문서가 책상 밖으로 빠져 나갔을 때
	if ((rq.y + vScale.y / 2 / 1.2 >= 680) == false)
	{
		if (GetObjectState() == ObjectState::ON_THE_DESK)
		{
			SetObjectState(ObjectState::WAS_ON_THE_DESK);
			vCurPos.x = _mousePos.x;
			vCurPos.y = _mousePos.y;
		}

		hWeaponList = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\guilddocu\\small_weapon.bmp");
		GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hWeaponList, (int)vCurPos.x, (int)vCurPos.y, isVisivle);
		/// TODO: SetIsPartyListOntheDesk 함수 만들기 @@@@@@@@@@@@@@@@@@@@@@@@
		//GET_SINGLE(InputManager)->SetIsIDcardOntheDesk(false);
		SetScale(Vec2(105, 70));

	}
	/// 장비 리스트 문서가 책상 안에 있을 때
	else
	{
		SetObjectState(ObjectState::ON_THE_DESK);

		SetScale(Vec2(500, 400));
		hWeaponList = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\guilddocu\\weaponlist.bmp");
		GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hWeaponList, (int)vCurPos.x, (int)vCurPos.y, isVisivle);
		/// TODO: SetIsPartyListOntheDesk 함수 만들기 @@@@@@@@@@@@@@@@@@@@@@@@
		//GET_SINGLE(InputManager)->SetIsIDcardOntheDesk(true);

		switch (characterName)
		{
			case CharacterName::darius:		// 다리우스
			{
				SetWeaponKindScript1(GET_SINGLE(VectorManager)->weaponList1[0]);
				SetPriceScript1(GET_SINGLE(VectorManager)->weaponList1[1]);
				SetWeaponRankScript1(GET_SINGLE(VectorManager)->weaponList1[2]);

				SetWeaponKindScript2(GET_SINGLE(VectorManager)->weaponList1[3]);
				SetPriceScript2(GET_SINGLE(VectorManager)->weaponList1[4]);
				SetWeaponRankScript2(GET_SINGLE(VectorManager)->weaponList1[5]);

				SetWeaponKindScript3(GET_SINGLE(VectorManager)->weaponList1[6]);
				SetPriceScript3(GET_SINGLE(VectorManager)->weaponList1[7]);
				SetWeaponRankScript3(GET_SINGLE(VectorManager)->weaponList1[8]);

				SetWeaponKindScript4(GET_SINGLE(VectorManager)->weaponList1[9]);
				SetPriceScript4(GET_SINGLE(VectorManager)->weaponList1[10]);
				SetWeaponRankScript4(GET_SINGLE(VectorManager)->weaponList1[11]);

				_script1 = GetWeaponKindScript1();
				_script2 = GetPriceScript1();
				_script3 = GetWeaponRankScript1();

				_script4 = GetWeaponKindScript2();
				_script5 = GetPriceScript2();
				_script6 = GetWeaponRankScript2();

				_script7 = GetWeaponKindScript3();
				_script8 = GetPriceScript3();
				_script9 = GetWeaponRankScript3();

				_script10 = GetWeaponKindScript4();
				_script11 = GetPriceScript4();
				_script12 = GetWeaponRankScript4();

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 160, _script1.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 160, _script2.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 160, _script3.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 195, _script4.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 195, _script5.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 195, _script6.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 230, _script7.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 230, _script8.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 230, _script9.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 265, _script10.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 265, _script11.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 265, _script12.c_str(), 37);

			}
			break;
			case CharacterName::catfighter1:	// 엘레나
			{
				SetWeaponKindScript1(GET_SINGLE(VectorManager)->weaponList2[0]);
				SetPriceScript1(GET_SINGLE(VectorManager)->weaponList2[1]);
				SetWeaponRankScript1(GET_SINGLE(VectorManager)->weaponList2[2]);

				SetWeaponKindScript2(GET_SINGLE(VectorManager)->weaponList2[3]);
				SetPriceScript2(GET_SINGLE(VectorManager)->weaponList2[4]);
				SetWeaponRankScript2(GET_SINGLE(VectorManager)->weaponList2[5]);

				SetWeaponKindScript3(GET_SINGLE(VectorManager)->weaponList2[6]);
				SetPriceScript3(GET_SINGLE(VectorManager)->weaponList2[7]);
				SetWeaponRankScript3(GET_SINGLE(VectorManager)->weaponList2[8]);

				SetWeaponKindScript4(GET_SINGLE(VectorManager)->weaponList2[9]);
				SetPriceScript4(GET_SINGLE(VectorManager)->weaponList2[10]);
				SetWeaponRankScript4(GET_SINGLE(VectorManager)->weaponList2[11]);

				_script1 = GetWeaponKindScript1();
				_script2 = GetPriceScript1();
				_script3 = GetWeaponRankScript1();

				_script4 = GetWeaponKindScript2();
				_script5 = GetPriceScript2();
				_script6 = GetWeaponRankScript2();

				_script7 = GetWeaponKindScript3();
				_script8 = GetPriceScript3();
				_script9 = GetWeaponRankScript3();

				_script10 = GetWeaponKindScript4();
				_script11 = GetPriceScript4();
				_script12 = GetWeaponRankScript4();

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 160, _script1.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 160, _script2.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 160, _script3.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 195, _script4.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 195, _script5.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 195, _script6.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 230, _script7.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 230, _script8.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 230, _script9.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 265, _script10.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 265, _script11.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 265, _script12.c_str(), 37);
			}
			break;
			case CharacterName::ninza2:		// 로드
			{
				SetWeaponKindScript1(GET_SINGLE(VectorManager)->weaponList3[0]);
				SetPriceScript1(GET_SINGLE(VectorManager)->weaponList3[1]);
				SetWeaponRankScript1(GET_SINGLE(VectorManager)->weaponList3[2]);

				SetWeaponKindScript2(GET_SINGLE(VectorManager)->weaponList3[3]);
				SetPriceScript2(GET_SINGLE(VectorManager)->weaponList3[4]);
				SetWeaponRankScript2(GET_SINGLE(VectorManager)->weaponList3[5]);

				SetWeaponKindScript3(GET_SINGLE(VectorManager)->weaponList3[6]);
				SetPriceScript3(GET_SINGLE(VectorManager)->weaponList3[7]);
				SetWeaponRankScript3(GET_SINGLE(VectorManager)->weaponList3[8]);

				SetWeaponKindScript4(GET_SINGLE(VectorManager)->weaponList3[9]);
				SetPriceScript4(GET_SINGLE(VectorManager)->weaponList3[10]);
				SetWeaponRankScript4(GET_SINGLE(VectorManager)->weaponList3[11]);

				_script1 = GetWeaponKindScript1();
				_script2 = GetPriceScript1();
				_script3 = GetWeaponRankScript1();

				_script4 = GetWeaponKindScript2();
				_script5 = GetPriceScript2();
				_script6 = GetWeaponRankScript2();

				_script7 = GetWeaponKindScript3();
				_script8 = GetPriceScript3();
				_script9 = GetWeaponRankScript3();

				_script10 = GetWeaponKindScript4();
				_script11 = GetPriceScript4();
				_script12 = GetWeaponRankScript4();

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 160, _script1.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 160, _script2.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 160, _script3.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 195, _script4.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 195, _script5.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 195, _script6.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 230, _script7.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 230, _script8.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 230, _script9.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 265, _script10.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 265, _script11.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 265, _script12.c_str(), 37);
			}
			break;
			case CharacterName::dwarf_2:	// 그레이지
			{
				SetWeaponKindScript1(GET_SINGLE(VectorManager)->weaponList4[0]);
				SetPriceScript1(GET_SINGLE(VectorManager)->weaponList4[1]);
				SetWeaponRankScript1(GET_SINGLE(VectorManager)->weaponList4[2]);

				SetWeaponKindScript2(GET_SINGLE(VectorManager)->weaponList4[3]);
				SetPriceScript2(GET_SINGLE(VectorManager)->weaponList4[4]);
				SetWeaponRankScript2(GET_SINGLE(VectorManager)->weaponList4[5]);

				SetWeaponKindScript3(GET_SINGLE(VectorManager)->weaponList4[6]);
				SetPriceScript3(GET_SINGLE(VectorManager)->weaponList4[7]);
				SetWeaponRankScript3(GET_SINGLE(VectorManager)->weaponList4[8]);

				SetWeaponKindScript4(GET_SINGLE(VectorManager)->weaponList4[9]);
				SetPriceScript4(GET_SINGLE(VectorManager)->weaponList4[10]);
				SetWeaponRankScript4(GET_SINGLE(VectorManager)->weaponList4[11]);

				_script1 = GetWeaponKindScript1();
				_script2 = GetPriceScript1();
				_script3 = GetWeaponRankScript1();

				_script4 = GetWeaponKindScript2();
				_script5 = GetPriceScript2();
				_script6 = GetWeaponRankScript2();

				_script7 = GetWeaponKindScript3();
				_script8 = GetPriceScript3();
				_script9 = GetWeaponRankScript3();

				_script10 = GetWeaponKindScript4();
				_script11 = GetPriceScript4();
				_script12 = GetWeaponRankScript4();

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 160, _script1.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 160, _script2.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 160, _script3.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 195, _script4.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 195, _script5.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 195, _script6.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 230, _script7.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 230, _script8.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 230, _script9.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 265, _script10.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 265, _script11.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 265, _script12.c_str(), 37);
			}
			break;
			case CharacterName::lilian:		// 릴리안
			{
				SetWeaponKindScript1(GET_SINGLE(VectorManager)->weaponList5[0]);
				SetPriceScript1(GET_SINGLE(VectorManager)->weaponList5[1]);
				SetWeaponRankScript1(GET_SINGLE(VectorManager)->weaponList5[2]);

				SetWeaponKindScript2(GET_SINGLE(VectorManager)->weaponList5[3]);
				SetPriceScript2(GET_SINGLE(VectorManager)->weaponList5[4]);
				SetWeaponRankScript2(GET_SINGLE(VectorManager)->weaponList5[5]);

				SetWeaponKindScript3(GET_SINGLE(VectorManager)->weaponList5[6]);
				SetPriceScript3(GET_SINGLE(VectorManager)->weaponList5[7]);
				SetWeaponRankScript3(GET_SINGLE(VectorManager)->weaponList5[8]);

				SetWeaponKindScript4(GET_SINGLE(VectorManager)->weaponList5[9]);
				SetPriceScript4(GET_SINGLE(VectorManager)->weaponList5[10]);
				SetWeaponRankScript4(GET_SINGLE(VectorManager)->weaponList5[11]);

				_script1 = GetWeaponKindScript1();
				_script2 = GetPriceScript1();
				_script3 = GetWeaponRankScript1();

				_script4 = GetWeaponKindScript2();
				_script5 = GetPriceScript2();
				_script6 = GetWeaponRankScript2();

				_script7 = GetWeaponKindScript3();
				_script8 = GetPriceScript3();
				_script9 = GetWeaponRankScript3();

				_script10 = GetWeaponKindScript4();
				_script11 = GetPriceScript4();
				_script12 = GetWeaponRankScript4();

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 160, _script1.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 160, _script2.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 160, _script3.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 195, _script4.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 195, _script5.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 195, _script6.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 230, _script7.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 230, _script8.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 230, _script9.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 265, _script10.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 265, _script11.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 265, _script12.c_str(), 37);
			}
			break;
			case CharacterName::herbalist1:		// 페버럴
			{
				SetWeaponKindScript1(GET_SINGLE(VectorManager)->weaponList6[0]);
				SetPriceScript1(GET_SINGLE(VectorManager)->weaponList6[1]);
				SetWeaponRankScript1(GET_SINGLE(VectorManager)->weaponList6[2]);

				SetWeaponKindScript2(GET_SINGLE(VectorManager)->weaponList6[3]);
				SetPriceScript2(GET_SINGLE(VectorManager)->weaponList6[4]);
				SetWeaponRankScript2(GET_SINGLE(VectorManager)->weaponList6[5]);

				SetWeaponKindScript3(GET_SINGLE(VectorManager)->weaponList6[6]);
				SetPriceScript3(GET_SINGLE(VectorManager)->weaponList6[7]);
				SetWeaponRankScript3(GET_SINGLE(VectorManager)->weaponList6[8]);

				SetWeaponKindScript4(GET_SINGLE(VectorManager)->weaponList6[9]);
				SetPriceScript4(GET_SINGLE(VectorManager)->weaponList6[10]);
				SetWeaponRankScript4(GET_SINGLE(VectorManager)->weaponList6[11]);

				_script1 = GetWeaponKindScript1();
				_script2 = GetPriceScript1();
				_script3 = GetWeaponRankScript1();

				_script4 = GetWeaponKindScript2();
				_script5 = GetPriceScript2();
				_script6 = GetWeaponRankScript2();

				_script7 = GetWeaponKindScript3();
				_script8 = GetPriceScript3();
				_script9 = GetWeaponRankScript3();

				_script10 = GetWeaponKindScript4();
				_script11 = GetPriceScript4();
				_script12 = GetWeaponRankScript4();

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 160, _script1.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 160, _script2.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 160, _script3.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 195, _script4.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 195, _script5.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 195, _script6.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 230, _script7.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 230, _script8.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 230, _script9.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 265, _script10.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 265, _script11.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 265, _script12.c_str(), 37);
			}
			break;
			case CharacterName::herbalist4:		// 에드릭
			{
				SetWeaponKindScript1(GET_SINGLE(VectorManager)->weaponList7[0]);
				SetPriceScript1(GET_SINGLE(VectorManager)->weaponList7[1]);
				SetWeaponRankScript1(GET_SINGLE(VectorManager)->weaponList7[2]);

				SetWeaponKindScript2(GET_SINGLE(VectorManager)->weaponList7[3]);
				SetPriceScript2(GET_SINGLE(VectorManager)->weaponList7[4]);
				SetWeaponRankScript2(GET_SINGLE(VectorManager)->weaponList7[5]);

				SetWeaponKindScript3(GET_SINGLE(VectorManager)->weaponList7[6]);
				SetPriceScript3(GET_SINGLE(VectorManager)->weaponList7[7]);
				SetWeaponRankScript3(GET_SINGLE(VectorManager)->weaponList7[8]);

				SetWeaponKindScript4(GET_SINGLE(VectorManager)->weaponList7[9]);
				SetPriceScript4(GET_SINGLE(VectorManager)->weaponList7[10]);
				SetWeaponRankScript4(GET_SINGLE(VectorManager)->weaponList7[11]);

				_script1 = GetWeaponKindScript1();
				_script2 = GetPriceScript1();
				_script3 = GetWeaponRankScript1();

				_script4 = GetWeaponKindScript2();
				_script5 = GetPriceScript2();
				_script6 = GetWeaponRankScript2();

				_script7 = GetWeaponKindScript3();
				_script8 = GetPriceScript3();
				_script9 = GetWeaponRankScript3();

				_script10 = GetWeaponKindScript4();
				_script11 = GetPriceScript4();
				_script12 = GetWeaponRankScript4();

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 160, _script1.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 160, _script2.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 160, _script3.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 195, _script4.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 195, _script5.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 195, _script6.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 230, _script7.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 230, _script8.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 230, _script9.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 265, _script10.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 265, _script11.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 265, _script12.c_str(), 37);
			}
			break;
			case CharacterName::catfighter2:	// 엘리
			{
				SetWeaponKindScript1(GET_SINGLE(VectorManager)->weaponList8[0]);
				SetPriceScript1(GET_SINGLE(VectorManager)->weaponList8[1]);
				SetWeaponRankScript1(GET_SINGLE(VectorManager)->weaponList8[2]);

				SetWeaponKindScript2(GET_SINGLE(VectorManager)->weaponList8[3]);
				SetPriceScript2(GET_SINGLE(VectorManager)->weaponList8[4]);
				SetWeaponRankScript2(GET_SINGLE(VectorManager)->weaponList8[5]);

				SetWeaponKindScript3(GET_SINGLE(VectorManager)->weaponList8[6]);
				SetPriceScript3(GET_SINGLE(VectorManager)->weaponList8[7]);
				SetWeaponRankScript3(GET_SINGLE(VectorManager)->weaponList8[8]);

				SetWeaponKindScript4(GET_SINGLE(VectorManager)->weaponList8[9]);
				SetPriceScript4(GET_SINGLE(VectorManager)->weaponList8[10]);
				SetWeaponRankScript4(GET_SINGLE(VectorManager)->weaponList8[11]);

				_script1 = GetWeaponKindScript1();
				_script2 = GetPriceScript1();
				_script3 = GetWeaponRankScript1();

				_script4 = GetWeaponKindScript2();
				_script5 = GetPriceScript2();
				_script6 = GetWeaponRankScript2();

				_script7 = GetWeaponKindScript3();
				_script8 = GetPriceScript3();
				_script9 = GetWeaponRankScript3();

				_script10 = GetWeaponKindScript4();
				_script11 = GetPriceScript4();
				_script12 = GetWeaponRankScript4();

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 160, _script1.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 160, _script2.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 160, _script3.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 195, _script4.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 195, _script5.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 195, _script6.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 230, _script7.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 230, _script8.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 230, _script9.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 265, _script10.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 265, _script11.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 265, _script12.c_str(), 37);
			}
			break;
			case CharacterName::ninza1:		// 겐지
			{
				SetWeaponKindScript1(GET_SINGLE(VectorManager)->weaponList9[0]);
				SetPriceScript1(GET_SINGLE(VectorManager)->weaponList9[1]);
				SetWeaponRankScript1(GET_SINGLE(VectorManager)->weaponList9[2]);

				SetWeaponKindScript2(GET_SINGLE(VectorManager)->weaponList9[3]);
				SetPriceScript2(GET_SINGLE(VectorManager)->weaponList9[4]);
				SetWeaponRankScript2(GET_SINGLE(VectorManager)->weaponList9[5]);

				SetWeaponKindScript3(GET_SINGLE(VectorManager)->weaponList9[6]);
				SetPriceScript3(GET_SINGLE(VectorManager)->weaponList9[7]);
				SetWeaponRankScript3(GET_SINGLE(VectorManager)->weaponList9[8]);

				SetWeaponKindScript4(GET_SINGLE(VectorManager)->weaponList9[9]);
				SetPriceScript4(GET_SINGLE(VectorManager)->weaponList9[10]);
				SetWeaponRankScript4(GET_SINGLE(VectorManager)->weaponList9[11]);

				_script1 = GetWeaponKindScript1();
				_script2 = GetPriceScript1();
				_script3 = GetWeaponRankScript1();

				_script4 = GetWeaponKindScript2();
				_script5 = GetPriceScript2();
				_script6 = GetWeaponRankScript2();

				_script7 = GetWeaponKindScript3();
				_script8 = GetPriceScript3();
				_script9 = GetWeaponRankScript3();

				_script10 = GetWeaponKindScript4();
				_script11 = GetPriceScript4();
				_script12 = GetWeaponRankScript4();

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 160, _script1.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 160, _script2.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 160, _script3.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 195, _script4.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 195, _script5.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 195, _script6.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 230, _script7.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 230, _script8.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 230, _script9.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 265, _script10.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 265, _script11.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 265, _script12.c_str(), 37);
			}
			break;
			case CharacterName::eden:		// 에덴
			{
				SetWeaponKindScript1(GET_SINGLE(VectorManager)->weaponList10[0]);
				SetPriceScript1(GET_SINGLE(VectorManager)->weaponList10[1]);
				SetWeaponRankScript1(GET_SINGLE(VectorManager)->weaponList10[2]);

				SetWeaponKindScript2(GET_SINGLE(VectorManager)->weaponList10[3]);
				SetPriceScript2(GET_SINGLE(VectorManager)->weaponList10[4]);
				SetWeaponRankScript2(GET_SINGLE(VectorManager)->weaponList10[5]);

				SetWeaponKindScript3(GET_SINGLE(VectorManager)->weaponList10[6]);
				SetPriceScript3(GET_SINGLE(VectorManager)->weaponList10[7]);
				SetWeaponRankScript3(GET_SINGLE(VectorManager)->weaponList10[8]);

				SetWeaponKindScript4(GET_SINGLE(VectorManager)->weaponList10[9]);
				SetPriceScript4(GET_SINGLE(VectorManager)->weaponList10[10]);
				SetWeaponRankScript4(GET_SINGLE(VectorManager)->weaponList10[11]);

				_script1 = GetWeaponKindScript1();
				_script2 = GetPriceScript1();
				_script3 = GetWeaponRankScript1();

				_script4 = GetWeaponKindScript2();
				_script5 = GetPriceScript2();
				_script6 = GetWeaponRankScript2();

				_script7 = GetWeaponKindScript3();
				_script8 = GetPriceScript3();
				_script9 = GetWeaponRankScript3();

				_script10 = GetWeaponKindScript4();
				_script11 = GetPriceScript4();
				_script12 = GetWeaponRankScript4();

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 160, _script1.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 160, _script2.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 160, _script3.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 195, _script4.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 195, _script5.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 195, _script6.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 230, _script7.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 230, _script8.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 230, _script9.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 265, _script10.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 265, _script11.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 265, _script12.c_str(), 37);
			}
			break;
			case CharacterName::dwarf_1:		// 그롬머
			{
				SetWeaponKindScript1(GET_SINGLE(VectorManager)->weaponList11[0]);
				SetPriceScript1(GET_SINGLE(VectorManager)->weaponList11[1]);
				SetWeaponRankScript1(GET_SINGLE(VectorManager)->weaponList11[2]);

				SetWeaponKindScript2(GET_SINGLE(VectorManager)->weaponList11[3]);
				SetPriceScript2(GET_SINGLE(VectorManager)->weaponList11[4]);
				SetWeaponRankScript2(GET_SINGLE(VectorManager)->weaponList11[5]);

				SetWeaponKindScript3(GET_SINGLE(VectorManager)->weaponList11[6]);
				SetPriceScript3(GET_SINGLE(VectorManager)->weaponList11[7]);
				SetWeaponRankScript3(GET_SINGLE(VectorManager)->weaponList11[8]);

				SetWeaponKindScript4(GET_SINGLE(VectorManager)->weaponList11[9]);
				SetPriceScript4(GET_SINGLE(VectorManager)->weaponList11[10]);
				SetWeaponRankScript4(GET_SINGLE(VectorManager)->weaponList11[11]);

				_script1 = GetWeaponKindScript1();
				_script2 = GetPriceScript1();
				_script3 = GetWeaponRankScript1();

				_script4 = GetWeaponKindScript2();
				_script5 = GetPriceScript2();
				_script6 = GetWeaponRankScript2();

				_script7 = GetWeaponKindScript3();
				_script8 = GetPriceScript3();
				_script9 = GetWeaponRankScript3();

				_script10 = GetWeaponKindScript4();
				_script11 = GetPriceScript4();
				_script12 = GetWeaponRankScript4();

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 160, _script1.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 160, _script2.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 160, _script3.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 195, _script4.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 195, _script5.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 195, _script6.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 230, _script7.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 230, _script8.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 230, _script9.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 265, _script10.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 265, _script11.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 265, _script12.c_str(), 37);
			}
			break;
			case CharacterName::herbalist3:		// 로이
			{
				SetWeaponKindScript1(GET_SINGLE(VectorManager)->weaponList12[0]);
				SetPriceScript1(GET_SINGLE(VectorManager)->weaponList12[1]);
				SetWeaponRankScript1(GET_SINGLE(VectorManager)->weaponList12[2]);

				SetWeaponKindScript2(GET_SINGLE(VectorManager)->weaponList12[3]);
				SetPriceScript2(GET_SINGLE(VectorManager)->weaponList12[4]);
				SetWeaponRankScript2(GET_SINGLE(VectorManager)->weaponList12[5]);

				SetWeaponKindScript3(GET_SINGLE(VectorManager)->weaponList12[6]);
				SetPriceScript3(GET_SINGLE(VectorManager)->weaponList12[7]);
				SetWeaponRankScript3(GET_SINGLE(VectorManager)->weaponList12[8]);

				SetWeaponKindScript4(GET_SINGLE(VectorManager)->weaponList12[9]);
				SetPriceScript4(GET_SINGLE(VectorManager)->weaponList12[10]);
				SetWeaponRankScript4(GET_SINGLE(VectorManager)->weaponList12[11]);

				_script1 = GetWeaponKindScript1();
				_script2 = GetPriceScript1();
				_script3 = GetWeaponRankScript1();

				_script4 = GetWeaponKindScript2();
				_script5 = GetPriceScript2();
				_script6 = GetWeaponRankScript2();

				_script7 = GetWeaponKindScript3();
				_script8 = GetPriceScript3();
				_script9 = GetWeaponRankScript3();

				_script10 = GetWeaponKindScript4();
				_script11 = GetPriceScript4();
				_script12 = GetWeaponRankScript4();

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 160, _script1.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 160, _script2.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 160, _script3.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 195, _script4.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 195, _script5.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 195, _script6.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 230, _script7.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 230, _script8.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 230, _script9.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 265, _script10.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 265, _script11.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 265, _script12.c_str(), 37);
			}
			break;
			case CharacterName::herbalist2:		// 피넬로
			{
				SetWeaponKindScript1(GET_SINGLE(VectorManager)->weaponList13[0]);
				SetPriceScript1(GET_SINGLE(VectorManager)->weaponList13[1]);
				SetWeaponRankScript1(GET_SINGLE(VectorManager)->weaponList13[2]);

				SetWeaponKindScript2(GET_SINGLE(VectorManager)->weaponList13[3]);
				SetPriceScript2(GET_SINGLE(VectorManager)->weaponList13[4]);
				SetWeaponRankScript2(GET_SINGLE(VectorManager)->weaponList13[5]);

				SetWeaponKindScript3(GET_SINGLE(VectorManager)->weaponList13[6]);
				SetPriceScript3(GET_SINGLE(VectorManager)->weaponList13[7]);
				SetWeaponRankScript3(GET_SINGLE(VectorManager)->weaponList13[8]);

				SetWeaponKindScript4(GET_SINGLE(VectorManager)->weaponList13[9]);
				SetPriceScript4(GET_SINGLE(VectorManager)->weaponList13[10]);
				SetWeaponRankScript4(GET_SINGLE(VectorManager)->weaponList13[11]);

				_script1 = GetWeaponKindScript1();
				_script2 = GetPriceScript1();
				_script3 = GetWeaponRankScript1();

				_script4 = GetWeaponKindScript2();
				_script5 = GetPriceScript2();
				_script6 = GetWeaponRankScript2();

				_script7 = GetWeaponKindScript3();
				_script8 = GetPriceScript3();
				_script9 = GetWeaponRankScript3();

				_script10 = GetWeaponKindScript4();
				_script11 = GetPriceScript4();
				_script12 = GetWeaponRankScript4();

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 160, _script1.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 160, _script2.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 160, _script3.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 195, _script4.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 195, _script5.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 195, _script6.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 230, _script7.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 230, _script8.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 230, _script9.c_str(), 37);

				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 40, (int)vCurPos.y + 265, _script10.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 238, (int)vCurPos.y + 265, _script11.c_str(), 37);
				GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hWeaponList, (int)vCurPos.x + 405, (int)vCurPos.y + 265, _script12.c_str(), 37);
			}
			break;
			default:
				break;
		}

	}


	SetTextColor(hdc, RGB(0, 255, 0));

	/// 호버링 중인가에 대한 디버깅 정보 출력
	if (InputManager::GetInstance()->GetIsRenderDebug() == true)
	{
		if (_hoverCheck == true)
		{
			TextOut(hdc, (int)vCurPos.x, (int)vCurPos.y, L"Hover", (int)wcslen(L"Hover"));
		}
		else
		{
			TextOut(hdc, (int)vCurPos.x, (int)vCurPos.y, L"None", (int)wcslen(L"Hover"));
		}
		TextOut(hdc, (int)vCurPos.x + 20, (int)vCurPos.y + 25, to_wstring(GetDepth()).c_str(), 4);
		TextOut(hdc, (int)vCurPos.x + 20, (int)vCurPos.y + 50, L"STATE: ", (int)wcslen(L"STATE: "));
		TextOut(hdc, (int)vCurPos.x + 90, (int)vCurPos.y + 50, to_wstring((int32)GetObjectState()).c_str(), 4);

	}

	SetTextColor(hdc, RGB(0, 0, 0));

}

void OWeaponList::OnPicking()
{

	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int32 curDepth = GetDepth();

	characterName = GetCharacterName();

	isVisivle = GetAlpha();
	//isVisivle = 255;

	_mousePos = GET_SINGLE(InputManager)->GetMouseCursorPosition();

	_hoverCheck = GET_SINGLE(InputManager)->HoverCheck((int)vPos.x - temp, (int)vPos.y - temp, (int)vScale.x + temp, (int)vScale.y + temp, _mousePos);


	if (IsHolding())
		temp = 3000;
	else
		temp = 0;

	if (_hoverCheck || IsHolding())
	{
		if (KEY_TAP(KEY::LMB))
		{
			GET_SINGLE(ResourceManager)->PlayEffect(5);
			SetDepth(InputManager::GetInstance()->GetNowDepth());
			m_vDragStart = _mousePos;
			SetHolding(true);
			InputManager::GetInstance()->SetHoldingDepth(m_depth);
		}

		if (KEY_HOLD(KEY::LMB))
		{
			if (InputManager::GetInstance()->GetHoldingDepth() == m_depth)
			{
				if (GetObjectState() == ObjectState::WAS_ON_THE_DESK)
				{
					vPos.x = _mousePos.x - 50;
					vPos.y = _mousePos.y - 50;
				}
				else
				{
					Vec2 vDiff = _mousePos - m_vDragStart;
					vPos = vPos + vDiff;
				}
				m_vDragStart = _mousePos;
				//vPos.x -= 500.f * DT;
			}
		}

		if (KEY_AWAY(KEY::LMB))
		{
			if (GetObjectState() == ObjectState::WAS_ON_THE_DESK)
				SetObjectState(ObjectState::OUT_OF_DESK);

			SetHolding(false);

			// 캐릭터의 좌표에 마우스 포인터가 위치한다면 의뢰 전달 완료! 다음 인물로 넘어가게 하기
			/// 승인 또는 거절 버튼을 누른 상태에서 전달해야 함
			if (vPos.x + vScale.x / 2 >= 600 && vPos.x + vScale.x / 2 <= 1000 && vPos.y + vScale.y / 2 >= 300 && vPos.y + vScale.y / 2 <= 600)
			{
				if ((GET_SINGLE(VectorManager)->GetIsWeaponListRetuend() == false) && isVisivle != 0)
				{
					GET_SINGLE(ResourceManager)->PlayEffect(6);
					GET_SINGLE(VectorManager)->SetIsWeaponListReturned(true);

					isVisivle = 0;
					if (GetAlpha() != 0)
						SetAlpha(0);
					OutputDebugString(TEXT("*************파티 리스트 문서 돌려줌!!****************"));
					OutputDebugString(TEXT("\n"));

					SetPos(Vec2(0, 0));
				}
			}
			InputManager::GetInstance()->SetHoldingDepth(-1);
		}
	}
	//else
	//{
	//	SetDepth(0);
	//}

	if (((_mousePos.x >= 1450) == false) && ((vPos.x < -200) == false) && ((vPos.y < 0) == false))
	{
		if (IsHolding() == true)
		{
			SetPos(vPos);
		}
	}
	else
	{
		SetHolding(false);
	}
}

