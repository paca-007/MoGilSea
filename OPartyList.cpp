#include "pch.h"
#include "OPartyList.h"
#include "ResourceManager.h"
#include "ObjectManager.h"

#include "TimeManager.h"
#include "InputManager.h"

OPartyList::OPartyList()
{
	SetScale(Vec2(500, 400));
	SetObjectState(ObjectState::ON_THE_DESK);
}

OPartyList::~OPartyList()
{
}

void OPartyList::Update()
{

}

void OPartyList::Render(HDC hdc)
{
	Vec2 vCurPos = GetPos();
	Vec2 vScale = GetScale();

	//CharacterName cName = GetCharacterName();

	HBITMAP hPartyList;
	_mousePos = GET_SINGLE(InputManager)->GetMouseCursorPosition();

	Vec2 rq = this->GetPos();

	/// 파티원 리스트 문서가 책상 밖으로 빠져 나갔을 때
	if ((rq.y + vScale.y / 2 / 1.2 >= 680) == false)
	{
		if (GetObjectState() == ObjectState::ON_THE_DESK)
		{
			SetObjectState(ObjectState::WAS_ON_THE_DESK);
			vCurPos.x = _mousePos.x;
			vCurPos.y = _mousePos.y;
		}

		hPartyList = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\guilddocu\\small_party.bmp");
		GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hPartyList, (int)vCurPos.x, (int)vCurPos.y, isVisivle);
		/// TODO: SetIsPartyListOntheDesk 함수 만들기 @@@@@@@@@@@@@@@@@@@@@@@@
		//GET_SINGLE(InputManager)->SetIsIDcardOntheDesk(false);
		SetScale(Vec2(105, 70));
	}
	/// 파티언 리스트 문서가 책상 안에 있을 때
	else
	{
		SetObjectState(ObjectState::ON_THE_DESK);

		SetScale(Vec2(500, 400));
		/// TODO: SetIsPartyListOntheDesk 함수 만들기 @@@@@@@@@@@@@@@@@@@@@@@@
		//GET_SINGLE(InputManager)->SetIsIDcardOntheDesk(true);

		hPartyList = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\guilddocu\\partylist.bmp");
		GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, hPartyList, (int)vCurPos.x, (int)vCurPos.y, isVisivle);

		// switch 문으로 캐릭마다 달라져야 함.
		switch (characterName)
		{
		case CharacterName::darius:		// 다리우스
		{
			SetPartyMemberScript1(GET_SINGLE(VectorManager)->partyList1[0]);
			SetPartyScript1(GET_SINGLE(VectorManager)->partyList1[1]);
			SetPartyRankScript1(GET_SINGLE(VectorManager)->partyList1[2]);
			
			SetPartyMemberScript2(GET_SINGLE(VectorManager)->partyList1[3]);
			SetPartyScript2(GET_SINGLE(VectorManager)->partyList1[4]);
			SetPartyRankScript2(GET_SINGLE(VectorManager)->partyList1[5]);

			SetPartyMemberScript3(GET_SINGLE(VectorManager)->partyList1[6]);
			SetPartyScript3(GET_SINGLE(VectorManager)->partyList1[7]);
			SetPartyRankScript3(GET_SINGLE(VectorManager)->partyList1[8]);

			_script1 = GetPartyMemberScript1();
			_script2 = GetPartyScript1();
			_script3 = GetPartyRankScript1();

			_script4 = GetPartyMemberScript2();
			_script5 = GetPartyScript2();
			_script6 = GetPartyRankScript2();

			_script7 = GetPartyMemberScript3();
			_script8 = GetPartyScript3();
			_script9 = GetPartyRankScript3();

			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 170), _script1.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 170), _script2.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 170), _script3.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 210), _script4.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 210), _script5.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 210), _script6.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 250), _script7.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 250), _script8.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 250), _script9.c_str(), 40);
			
		}
		break;
		case CharacterName::catfighter1:	// 엘레나
		{
			SetPartyMemberScript1(GET_SINGLE(VectorManager)->partyList2[0]);
			SetPartyScript1(GET_SINGLE(VectorManager)->partyList2[1]);
			SetPartyRankScript1(GET_SINGLE(VectorManager)->partyList2[2]);

			SetPartyMemberScript2(GET_SINGLE(VectorManager)->partyList2[3]);
			SetPartyScript2(GET_SINGLE(VectorManager)->partyList2[4]);
			SetPartyRankScript2(GET_SINGLE(VectorManager)->partyList2[5]);

			SetPartyMemberScript3(GET_SINGLE(VectorManager)->partyList2[6]);
			SetPartyScript3(GET_SINGLE(VectorManager)->partyList2[7]);
			SetPartyRankScript3(GET_SINGLE(VectorManager)->partyList2[8]);

			_script1 = GetPartyMemberScript1();
			_script2 = GetPartyScript1();
			_script3 = GetPartyRankScript1();

			_script4 = GetPartyMemberScript2();
			_script5 = GetPartyScript2();
			_script6 = GetPartyRankScript2();

			_script7 = GetPartyMemberScript3();
			_script8 = GetPartyScript3();
			_script9 = GetPartyRankScript3();

			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 170), _script1.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 170), _script2.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 170), _script3.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 210), _script4.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 210), _script5.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 210), _script6.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 250), _script7.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 250), _script8.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 250), _script9.c_str(), 40);
		}
		break;
		case CharacterName::ninza2:		// 로드
		{
			SetPartyMemberScript1(GET_SINGLE(VectorManager)->partyList3[0]);
			SetPartyScript1(GET_SINGLE(VectorManager)->partyList3[1]);
			SetPartyRankScript1(GET_SINGLE(VectorManager)->partyList3[2]);

			SetPartyMemberScript2(GET_SINGLE(VectorManager)->partyList3[3]);
			SetPartyScript2(GET_SINGLE(VectorManager)->partyList3[4]);
			SetPartyRankScript2(GET_SINGLE(VectorManager)->partyList3[5]);

			SetPartyMemberScript3(GET_SINGLE(VectorManager)->partyList3[6]);
			SetPartyScript3(GET_SINGLE(VectorManager)->partyList3[7]);
			SetPartyRankScript3(GET_SINGLE(VectorManager)->partyList3[8]);

			_script1 = GetPartyMemberScript1();
			_script2 = GetPartyScript1();
			_script3 = GetPartyRankScript1();

			_script4 = GetPartyMemberScript2();
			_script5 = GetPartyScript2();
			_script6 = GetPartyRankScript2();

			_script7 = GetPartyMemberScript3();
			_script8 = GetPartyScript3();
			_script9 = GetPartyRankScript3();

			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 170), _script1.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 170), _script2.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 170), _script3.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 210), _script4.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 210), _script5.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 210), _script6.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 250), _script7.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 250), _script8.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 250), _script9.c_str(), 40);
		}
		break;
		case CharacterName::dwarf_2:	// 그레이지
		{
			SetPartyMemberScript1(GET_SINGLE(VectorManager)->partyList4[0]);
			SetPartyScript1(GET_SINGLE(VectorManager)->partyList4[1]);
			SetPartyRankScript1(GET_SINGLE(VectorManager)->partyList4[2]);

			SetPartyMemberScript2(GET_SINGLE(VectorManager)->partyList4[3]);
			SetPartyScript2(GET_SINGLE(VectorManager)->partyList4[4]);
			SetPartyRankScript2(GET_SINGLE(VectorManager)->partyList4[5]);

			SetPartyMemberScript3(GET_SINGLE(VectorManager)->partyList4[6]);
			SetPartyScript3(GET_SINGLE(VectorManager)->partyList4[7]);
			SetPartyRankScript3(GET_SINGLE(VectorManager)->partyList4[8]);

			_script1 = GetPartyMemberScript1();
			_script2 = GetPartyScript1();
			_script3 = GetPartyRankScript1();

			_script4 = GetPartyMemberScript2();
			_script5 = GetPartyScript2();
			_script6 = GetPartyRankScript2();

			_script7 = GetPartyMemberScript3();
			_script8 = GetPartyScript3();
			_script9 = GetPartyRankScript3();

			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 170), _script1.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 170), _script2.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 170), _script3.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 210), _script4.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 210), _script5.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 210), _script6.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 250), _script7.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 250), _script8.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 250), _script9.c_str(), 40);
		}
		break;
		case CharacterName::lilian:		// 릴리안
		{
			SetPartyMemberScript1(GET_SINGLE(VectorManager)->partyList5[0]);
			SetPartyScript1(GET_SINGLE(VectorManager)->partyList5[1]);
			SetPartyRankScript1(GET_SINGLE(VectorManager)->partyList5[2]);

			SetPartyMemberScript2(GET_SINGLE(VectorManager)->partyList5[3]);
			SetPartyScript2(GET_SINGLE(VectorManager)->partyList5[4]);
			SetPartyRankScript2(GET_SINGLE(VectorManager)->partyList5[5]);

			SetPartyMemberScript3(GET_SINGLE(VectorManager)->partyList5[6]);
			SetPartyScript3(GET_SINGLE(VectorManager)->partyList5[7]);
			SetPartyRankScript3(GET_SINGLE(VectorManager)->partyList5[8]);

			_script1 = GetPartyMemberScript1();
			_script2 = GetPartyScript1();
			_script3 = GetPartyRankScript1();

			_script4 = GetPartyMemberScript2();
			_script5 = GetPartyScript2();
			_script6 = GetPartyRankScript2();

			_script7 = GetPartyMemberScript3();
			_script8 = GetPartyScript3();
			_script9 = GetPartyRankScript3();

			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 170), _script1.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 170), _script2.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 170), _script3.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 210), _script4.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 210), _script5.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 210), _script6.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 250), _script7.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 250), _script8.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 250), _script9.c_str(), 40);
		}
		break;
		case CharacterName::herbalist1:		// 페버럴
		{
			SetPartyMemberScript1(GET_SINGLE(VectorManager)->partyList6[0]);
			SetPartyScript1(GET_SINGLE(VectorManager)->partyList6[1]);
			SetPartyRankScript1(GET_SINGLE(VectorManager)->partyList6[2]);

			SetPartyMemberScript2(GET_SINGLE(VectorManager)->partyList6[3]);
			SetPartyScript2(GET_SINGLE(VectorManager)->partyList6[4]);
			SetPartyRankScript2(GET_SINGLE(VectorManager)->partyList6[5]);

			SetPartyMemberScript3(GET_SINGLE(VectorManager)->partyList6[6]);
			SetPartyScript3(GET_SINGLE(VectorManager)->partyList6[7]);
			SetPartyRankScript3(GET_SINGLE(VectorManager)->partyList6[8]);

			_script1 = GetPartyMemberScript1();
			_script2 = GetPartyScript1();
			_script3 = GetPartyRankScript1();

			_script4 = GetPartyMemberScript2();
			_script5 = GetPartyScript2();
			_script6 = GetPartyRankScript2();

			_script7 = GetPartyMemberScript3();
			_script8 = GetPartyScript3();
			_script9 = GetPartyRankScript3();

			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 170), _script1.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 170), _script2.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 170), _script3.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 210), _script4.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 210), _script5.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 210), _script6.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 250), _script7.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 250), _script8.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 250), _script9.c_str(), 40);
		}
		break;
		case CharacterName::herbalist4:		// 에드릭
		{
			SetPartyMemberScript1(GET_SINGLE(VectorManager)->partyList7[0]);
			SetPartyScript1(GET_SINGLE(VectorManager)->partyList7[1]);
			SetPartyRankScript1(GET_SINGLE(VectorManager)->partyList7[2]);

			SetPartyMemberScript2(GET_SINGLE(VectorManager)->partyList7[3]);
			SetPartyScript2(GET_SINGLE(VectorManager)->partyList7[4]);
			SetPartyRankScript2(GET_SINGLE(VectorManager)->partyList7[5]);

			SetPartyMemberScript3(GET_SINGLE(VectorManager)->partyList7[6]);
			SetPartyScript3(GET_SINGLE(VectorManager)->partyList7[7]);
			SetPartyRankScript3(GET_SINGLE(VectorManager)->partyList7[8]);

			_script1 = GetPartyMemberScript1();
			_script2 = GetPartyScript1();
			_script3 = GetPartyRankScript1();

			_script4 = GetPartyMemberScript2();
			_script5 = GetPartyScript2();
			_script6 = GetPartyRankScript2();

			_script7 = GetPartyMemberScript3();
			_script8 = GetPartyScript3();
			_script9 = GetPartyRankScript3();

			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 170), _script1.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 170), _script2.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 170), _script3.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 210), _script4.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 210), _script5.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 210), _script6.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 250), _script7.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 250), _script8.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 250), _script9.c_str(), 40);
		}
		break;
		case CharacterName::catfighter2:	// 엘리
		{
			SetPartyMemberScript1(GET_SINGLE(VectorManager)->partyList8[0]);
			SetPartyScript1(GET_SINGLE(VectorManager)->partyList8[1]);
			SetPartyRankScript1(GET_SINGLE(VectorManager)->partyList8[2]);

			SetPartyMemberScript2(GET_SINGLE(VectorManager)->partyList8[3]);
			SetPartyScript2(GET_SINGLE(VectorManager)->partyList8[4]);
			SetPartyRankScript2(GET_SINGLE(VectorManager)->partyList8[5]);

			SetPartyMemberScript3(GET_SINGLE(VectorManager)->partyList8[6]);
			SetPartyScript3(GET_SINGLE(VectorManager)->partyList8[7]);
			SetPartyRankScript3(GET_SINGLE(VectorManager)->partyList8[8]);

			_script1 = GetPartyMemberScript1();
			_script2 = GetPartyScript1();
			_script3 = GetPartyRankScript1();

			_script4 = GetPartyMemberScript2();
			_script5 = GetPartyScript2();
			_script6 = GetPartyRankScript2();

			_script7 = GetPartyMemberScript3();
			_script8 = GetPartyScript3();
			_script9 = GetPartyRankScript3();

			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 170), _script1.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 170), _script2.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 170), _script3.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 210), _script4.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 210), _script5.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 210), _script6.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 250), _script7.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 250), _script8.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 250), _script9.c_str(), 40);
		}
		break;
		case CharacterName::ninza1:		// 겐지
		{
			SetPartyMemberScript1(GET_SINGLE(VectorManager)->partyList9[0]);
			SetPartyScript1(GET_SINGLE(VectorManager)->partyList9[1]);
			SetPartyRankScript1(GET_SINGLE(VectorManager)->partyList9[2]);

			SetPartyMemberScript2(GET_SINGLE(VectorManager)->partyList9[3]);
			SetPartyScript2(GET_SINGLE(VectorManager)->partyList9[4]);
			SetPartyRankScript2(GET_SINGLE(VectorManager)->partyList9[5]);

			SetPartyMemberScript3(GET_SINGLE(VectorManager)->partyList9[6]);
			SetPartyScript3(GET_SINGLE(VectorManager)->partyList9[7]);
			SetPartyRankScript3(GET_SINGLE(VectorManager)->partyList9[8]);

			_script1 = GetPartyMemberScript1();
			_script2 = GetPartyScript1();
			_script3 = GetPartyRankScript1();

			_script4 = GetPartyMemberScript2();
			_script5 = GetPartyScript2();
			_script6 = GetPartyRankScript2();

			_script7 = GetPartyMemberScript3();
			_script8 = GetPartyScript3();
			_script9 = GetPartyRankScript3();

			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 170), _script1.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 170), _script2.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 170), _script3.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 210), _script4.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 210), _script5.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 210), _script6.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 250), _script7.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 250), _script8.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 250), _script9.c_str(), 40);
		}
		break;
		case CharacterName::eden:		// 에덴
		{
			SetPartyMemberScript1(GET_SINGLE(VectorManager)->partyList10[0]);
			SetPartyScript1(GET_SINGLE(VectorManager)->partyList10[1]);
			SetPartyRankScript1(GET_SINGLE(VectorManager)->partyList10[2]);

			SetPartyMemberScript2(GET_SINGLE(VectorManager)->partyList10[3]);
			SetPartyScript2(GET_SINGLE(VectorManager)->partyList10[4]);
			SetPartyRankScript2(GET_SINGLE(VectorManager)->partyList10[5]);

			SetPartyMemberScript3(GET_SINGLE(VectorManager)->partyList10[6]);
			SetPartyScript3(GET_SINGLE(VectorManager)->partyList10[7]);
			SetPartyRankScript3(GET_SINGLE(VectorManager)->partyList10[8]);

			_script1 = GetPartyMemberScript1();
			_script2 = GetPartyScript1();
			_script3 = GetPartyRankScript1();

			_script4 = GetPartyMemberScript2();
			_script5 = GetPartyScript2();
			_script6 = GetPartyRankScript2();

			_script7 = GetPartyMemberScript3();
			_script8 = GetPartyScript3();
			_script9 = GetPartyRankScript3();

			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 170), _script1.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 170), _script2.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 170), _script3.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 210), _script4.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 210), _script5.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 210), _script6.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 250), _script7.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 250), _script8.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 250), _script9.c_str(), 40);
		}
		break;
		case CharacterName::dwarf_1:		// 그롬머
		{
			SetPartyMemberScript1(GET_SINGLE(VectorManager)->partyList11[0]);
			SetPartyScript1(GET_SINGLE(VectorManager)->partyList11[1]);
			SetPartyRankScript1(GET_SINGLE(VectorManager)->partyList11[2]);

			SetPartyMemberScript2(GET_SINGLE(VectorManager)->partyList11[3]);
			SetPartyScript2(GET_SINGLE(VectorManager)->partyList11[4]);
			SetPartyRankScript2(GET_SINGLE(VectorManager)->partyList11[5]);

			SetPartyMemberScript3(GET_SINGLE(VectorManager)->partyList11[6]);
			SetPartyScript3(GET_SINGLE(VectorManager)->partyList11[7]);
			SetPartyRankScript3(GET_SINGLE(VectorManager)->partyList11[8]);

			_script1 = GetPartyMemberScript1();
			_script2 = GetPartyScript1();
			_script3 = GetPartyRankScript1();

			_script4 = GetPartyMemberScript2();
			_script5 = GetPartyScript2();
			_script6 = GetPartyRankScript2();

			_script7 = GetPartyMemberScript3();
			_script8 = GetPartyScript3();
			_script9 = GetPartyRankScript3();

			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 170), _script1.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 170), _script2.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 170), _script3.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 210), _script4.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 210), _script5.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 210), _script6.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 250), _script7.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 250), _script8.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 250), _script9.c_str(), 40);
		}
		break;
		case CharacterName::herbalist3:		// 로이
		{
			SetPartyMemberScript1(GET_SINGLE(VectorManager)->partyList12[0]);
			SetPartyScript1(GET_SINGLE(VectorManager)->partyList12[1]);
			SetPartyRankScript1(GET_SINGLE(VectorManager)->partyList12[2]);

			SetPartyMemberScript2(GET_SINGLE(VectorManager)->partyList12[3]);
			SetPartyScript2(GET_SINGLE(VectorManager)->partyList12[4]);
			SetPartyRankScript2(GET_SINGLE(VectorManager)->partyList12[5]);

			SetPartyMemberScript3(GET_SINGLE(VectorManager)->partyList12[6]);
			SetPartyScript3(GET_SINGLE(VectorManager)->partyList12[7]);
			SetPartyRankScript3(GET_SINGLE(VectorManager)->partyList12[8]);

			_script1 = GetPartyMemberScript1();
			_script2 = GetPartyScript1();
			_script3 = GetPartyRankScript1();

			_script4 = GetPartyMemberScript2();
			_script5 = GetPartyScript2();
			_script6 = GetPartyRankScript2();

			_script7 = GetPartyMemberScript3();
			_script8 = GetPartyScript3();
			_script9 = GetPartyRankScript3();

			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 170), _script1.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 170), _script2.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 170), _script3.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 210), _script4.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 210), _script5.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 210), _script6.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 250), _script7.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 250), _script8.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 250), _script9.c_str(), 40);
		}
		break;
		case CharacterName::herbalist2:		// 피넬로
		{
			SetPartyMemberScript1(GET_SINGLE(VectorManager)->partyList13[0]);
			SetPartyScript1(GET_SINGLE(VectorManager)->partyList13[1]);
			SetPartyRankScript1(GET_SINGLE(VectorManager)->partyList13[2]);

			SetPartyMemberScript2(GET_SINGLE(VectorManager)->partyList13[3]);
			SetPartyScript2(GET_SINGLE(VectorManager)->partyList13[4]);
			SetPartyRankScript2(GET_SINGLE(VectorManager)->partyList13[5]);

			SetPartyMemberScript3(GET_SINGLE(VectorManager)->partyList13[6]);
			SetPartyScript3(GET_SINGLE(VectorManager)->partyList13[7]);
			SetPartyRankScript3(GET_SINGLE(VectorManager)->partyList13[8]);

			_script1 = GetPartyMemberScript1();
			_script2 = GetPartyScript1();
			_script3 = GetPartyRankScript1();

			_script4 = GetPartyMemberScript2();
			_script5 = GetPartyScript2();
			_script6 = GetPartyRankScript2();

			_script7 = GetPartyMemberScript3();
			_script8 = GetPartyScript3();
			_script9 = GetPartyRankScript3();

			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 170), _script1.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 170), _script2.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 170), _script3.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 210), _script4.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 210), _script5.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 210), _script6.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 55), (int)(vCurPos.y + 250), _script7.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 200), (int)(vCurPos.y + 250), _script8.c_str(), 40);
			GET_SINGLE(ResourceManager)->DrawTextOnBitmap(hdc, hPartyList, (int)(vCurPos.x + 360), (int)(vCurPos.y + 250), _script9.c_str(), 40);
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
		TextOut(hdc, (int)(vCurPos.x + 20), (int)(vCurPos.y + 25), to_wstring(GetDepth()).c_str(), 4);
		TextOut(hdc, (int)(vCurPos.x + 20), (int)(vCurPos.y + 50), L"STATE: ", (int)wcslen(L"STATE: "));
		TextOut(hdc, (int)(vCurPos.x + 90), (int)(vCurPos.y + 50), to_wstring((int32)GetObjectState()).c_str(), 4);
	}

	SetTextColor(hdc, RGB(0, 0, 0));

}

void OPartyList::OnPicking()
{

	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int32 curDepth = GetDepth();

	characterName = GetCharacterName();

	isVisivle = GetAlpha();
	//isVisivle = 255;

	_mousePos = GET_SINGLE(InputManager)->GetMouseCursorPosition();

	_hoverCheck = GET_SINGLE(InputManager)->HoverCheck((int32)(vPos.x - temp), (int32)(vPos.y - temp), (int32)(vScale.x + temp), (int32)(vScale.y + temp), _mousePos);


	if (IsHolding())
		temp = 3000;
	else
		temp = 0;

	if (_hoverCheck || IsHolding())
	{
		if (KEY_TAP(KEY::LMB))
		{
			GET_SINGLE(ResourceManager)->PlayEffect(12);
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
				if ((GET_SINGLE(VectorManager)->GetIsPartyListRetuend() == false) && isVisivle != 0)
				{
					GET_SINGLE(ResourceManager)->PlayEffect(8);
					GET_SINGLE(VectorManager)->SetIsPartyListReturned(true);

					isVisivle = 0;
					if(GetAlpha() != 0)
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

