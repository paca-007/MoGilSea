#include "pch.h"
#include "ResourceManager.h"
#include "Adventurer.h"
#include <locale>
#include "ObjectManager.h"
#include "Event.h"
#include "Quest.h"
#include "GameCore.h"

ResourceManager::~ResourceManager()
{
	Clear();
}

void ResourceManager::Init(HWND hwnd, filesystem::path resourcePath)
{
	_hwnd = hwnd;
	_resourcePath = resourcePath;

	// TEST
	/*unordered_map<wstring, Adventurer>* adventurerMap = new unordered_map<wstring, Adventurer>;
	GET_SINGLE(ObjectManager)->SetAdvMap(*adventurerMap);*/
}

void ResourceManager::Clear()
{
	/*for (auto& item : _textures)
	{
		SAFE_DELETE(item.second);
	}*/
	Release();
}

//Texture* ResourceManager::LoadTexture(const wstring& key, const wstring& path, uint32 transparent /*= RGB(255, 255, 255)*/)
//{
//	if (_textures.find(key) != _textures.end())
//	{
//		return _textures[key];
//	}
//
//	filesystem::path fullPath = _resourcePath / path;
//
//	Texture* texture = new Texture();
//	texture->LoadBmp(_hwnd, fullPath.c_str());
//	texture->SetTransparent(transparent);
//	_textures[key] = texture;
//
//	return texture;
//}

HBITMAP ResourceManager::GetImg(const wstring& path)
{
	filesystem::path fullPath = _resourcePath / path;

	return (HBITMAP)LoadImage(NULL, fullPath.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
}


void ResourceManager::Draw24Img(HDC hdc, HBITMAP hBitmap, int x, int y)
{
	BITMAP bitmap = {};

	//이미지 비트맵 변환
	GetObject(hBitmap, sizeof(BITMAP), &bitmap);

	//넣을 캔버스 생성
	HDC hdcMem = CreateCompatibleDC(hdc);
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(hdcMem, hBitmap);

	//OutputDebugString(to_wstring(bitmap.bmHeight).c_str());
	//OutputDebugString(TEXT("\n"));
	BitBlt(hdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);
}

void ResourceManager::DrawBackImg(HDC hdc, HBITMAP hBitmap, int x, int y)
{
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	BITMAP bitmap = {};

	//이미지 비트맵 변환
	GetObject(hBitmap, sizeof(BITMAP), &bitmap);

	//넣을 캔버스 생성
	HDC hdcMem = CreateCompatibleDC(hdc);


	//StretchBlt(hdc, x, y, screenWidth, screenHeight, hdcMem, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
	BitBlt(hdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);
}

void ResourceManager::DrawAlphaImg(HDC hdc, HBITMAP hBitmap, int x, int y, int _alpha)
{
	//빈 비트맵 생성
	BITMAP bitmap = {};

	//이미지 비트맵 변환
	GetObject(hBitmap, sizeof(BITMAP), &bitmap);

	//넣을 캔버스 생성
	HDC hdcMem = CreateCompatibleDC(hdc);
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(hdcMem, hBitmap);

	BLENDFUNCTION blendFunc{};
	blendFunc.BlendOp = AC_SRC_OVER;
	blendFunc.BlendFlags = 0;
	blendFunc.SourceConstantAlpha = _alpha; // 알파 값을 0에서 255 사이로 설정 (255는 완전 불투명)
	blendFunc.AlphaFormat = AC_SRC_ALPHA;


	AlphaBlend(hdc, x, y, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, bitmap.bmWidth, bitmap.bmHeight, blendFunc);
	SelectObject(hdcMem, hOldBitmap);
	DeleteDC(hdcMem);
	DeleteObject(hBitmap);


}



/// <param name="fileName">
/// 작업 디렉토리(솔루션 파일이 있는 폴더)를 기준으로 경로 작성
/// Resources/...etc
///</param>
std::unordered_map<std::wstring, Adventurer> ResourceManager::ReadADVCSV(const wstring& filePath)
{
	unordered_map<wstring, Adventurer> adventurerMap;

	wifstream file(filePath.c_str(), std::ios::binary | std::ios::in);
	if (!file.is_open())
	{
		assert("파일을 열 수 없습니다.");
		return adventurerMap;
	}

	locale tempLocale("ko_KR.utf8");
	file.imbue(tempLocale);

	// 맨 첫 줄 무시
	wstring header;
	getline(file, header);

	wstring line;
	while (getline(file, line))
	{
		wistringstream lineStream(line);
		wstring cell;

		// 멤버 변수
		wstring ID, name, imageID, initEvent;
		vector<wstring> negotiateEvent, supportEvent;
		wstring acceptEvent, refuseEvent, level;
		vector<wstring> goodTask, badTask;
		wstring appearanceCondition, initialFee;

		if (getline(lineStream, cell, L','))
		{
			ID = cell;
		}

		if (getline(lineStream, cell, L','))
		{
			name = cell;
		}

		if (getline(lineStream, cell, L','))
		{
			imageID = cell;
		}

		if (getline(lineStream, cell, L','))
		{
			initEvent = cell;
		}

		if (getline(lineStream, cell, L','))
		{
			wistringstream tempStream(cell);
			wstring tempCell;
			while (getline(tempStream, tempCell, L'|'))
			{
				negotiateEvent.push_back(tempCell);
			}
		}

		if (getline(lineStream, cell, L','))
		{
			wistringstream tempStream(cell);
			wstring tempCell;
			while (getline(tempStream, tempCell, L'|'))
			{
				supportEvent.push_back(tempCell);
			}
		}

		if (getline(lineStream, cell, L','))
		{
			level = cell;
		}

		if (getline(lineStream, cell, L','))
		{
			wistringstream tempStream(cell);
			wstring tempCell;
			while (getline(tempStream, tempCell, L'|'))
			{
				goodTask.push_back(tempCell);
			}
		}

		if (getline(lineStream, cell, L','))
		{
			wistringstream tempStream(cell);
			wstring tempCell;
			while (getline(tempStream, tempCell, L'|'))
			{
				badTask.push_back(tempCell);
			}
		}

		if (getline(lineStream, cell, L','))
		{
			appearanceCondition = cell;
		}

		if (getline(lineStream, cell, L','))
		{
			initialFee = cell;
		}

		Adventurer adventurer(ID, name, imageID, initEvent, negotiateEvent, supportEvent, acceptEvent
			, refuseEvent, level, goodTask, badTask, appearanceCondition, initialFee);
		adventurerMap.insert(make_pair(ID, adventurer));
	}

	file.close();

	return adventurerMap;
}


std::unordered_map<std::wstring, Event> ResourceManager::ReadEventCSV(const wstring& filePath)
{
	unordered_map<wstring, Event> eventMap;

	wifstream file(filePath.c_str(), std::ios::binary | std::ios::in);
	if (!file.is_open())
	{
		assert("파일을 열 수 없습니다.");
		return eventMap;
	}

	locale tempLocale("ko_KR.utf8");
	file.imbue(tempLocale);

	// 맨 첫 줄 무시
	wstring header;
	getline(file, header);

	wstring line;
	while (getline(file, line))
	{
		wistringstream lineStream(line);
		wstring cell;

		// 멤버 변수
		wstring eventID, kind, runEvent, moneyPM, famePM;
		vector<wstring> flagChange;
		wstring timerChange;

		if (getline(lineStream, cell, L','))
		{
			eventID = cell;
		}

		if (getline(lineStream, cell, L','))
		{
			kind = cell;
		}

		if (getline(lineStream, cell, L','))
		{
			runEvent = cell;
		}

		if (getline(lineStream, cell, L','))
		{
			moneyPM = cell;
		}

		if (getline(lineStream, cell, L','))
		{
			famePM = cell;
		}

		if (getline(lineStream, cell, L','))
		{
			wifstream tempStream(cell);
			wstring tempCell;
			while (getline(tempStream, tempCell, L'|'))
			{
				flagChange.push_back(tempCell);
			}
		}

		if (getline(lineStream, cell, L','))
		{
			timerChange = cell;
		}

		Event event(eventID, kind, runEvent, moneyPM, famePM, flagChange, timerChange);
		eventMap.insert(make_pair(eventID, event));
	}

	file.close();

	return eventMap;
}

std::unordered_map<std::wstring, Quest> ResourceManager::ReadQuestCSV(const wstring& filePath)
{
	unordered_map<wstring, Quest> questMap;
	wifstream file(filePath.c_str(), std::ios::binary | std::ios::in);
	if (!file.is_open())
	{
		assert("파일을 열 수 없습니다.");
		return questMap;
	}

	locale tempLocale("ko_KR.utf8");
	file.imbue(tempLocale);

	// 맨 첫 줄 무시
	wstring header;
	getline(file, header);

	wstring line;
	while (getline(file, line))
	{
		wistringstream lineStream(line);
		wstring cell;

		// 멤버 변수
		wstring questID; wstring name; wstring content; wstring grade; wstring level; wstring pay;
		wstring questClearMoney; wstring questClearFame; wstring questClearFlag;
		wstring questClearText; wstring questFailMoney; wstring questFailFame; wstring questFailFlag;
		wstring questFailText; wstring certainADV; wstring certainMoney; wstring certainFame;
		wstring certainFlag; wstring certainText;

		if (getline(lineStream, cell, L','))
		{
			questID = cell;
		}

		if (getline(lineStream, cell, L','))
		{
			name = cell;
		}

		if (getline(lineStream, cell, L','))
		{
			content = cell;
		}

		if (getline(lineStream, cell, L','))
		{
			grade = cell;
		}

		if (getline(lineStream, cell, L','))
		{
			level = cell;
		}

		if (getline(lineStream, cell, L','))
		{
			pay = cell;
		}

		if (getline(lineStream, cell, L','))
		{
			questClearMoney = cell;
		}

		if (getline(lineStream, cell, L','))
		{
			questClearFame = cell;
		}

		if (getline(lineStream, cell, L','))
		{
			questClearFlag = cell;
		}

		if (getline(lineStream, cell, L','))
		{
			questClearText = cell;
		}

		if (getline(lineStream, cell, L','))
		{
			questFailMoney = cell;
		}

		if (getline(lineStream, cell, L','))
		{
			questFailFame = cell;
		}

		if (getline(lineStream, cell, L','))
		{
			questFailFlag = cell;
		}

		if (getline(lineStream, cell, L','))
		{
			questFailText = cell;
		}

		if (getline(lineStream, cell, L','))
		{
			certainADV = cell;
		}

		if (getline(lineStream, cell, L','))
		{
			certainMoney = cell;
		}

		if (getline(lineStream, cell, L','))
		{
			certainFame = cell;
		}

		if (getline(lineStream, cell, L','))
		{
			certainFlag = cell;
		}

		if (getline(lineStream, cell, L','))
		{
			certainText = cell;
		}

		Quest quest(questID, name, content, grade, level, pay, questClearMoney, questClearFame, questClearFlag
			, questClearText, questFailMoney, questFailFame, questFailFlag, questFailText, certainADV
			, certainMoney, certainFame, certainFlag, certainText);
		questMap.insert(make_pair(questID, quest));
	}

	file.close();

	return questMap;
}

void ResourceManager::DrawTextOnBitmap(HDC hdc, HBITMAP hBitmap, int x, int y, const wchar_t* text, int fontSize)
{

	// 비트맵 디바이스 컨텍스트 생성
	HDC hMemDC = CreateCompatibleDC(hdc);
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBitmap);

	SetBkMode(hdc, 0);
	SetTextColor(hdc, RGB(0, 0, 0));

	HFONT  hfont = CreateFont(fontSize // 폰트의 높이
		, 0
		, 0
		, 0
		, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET
		, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY
		, DEFAULT_PITCH | FF_DONTCARE, L"KoPubWorld바탕체 Bold");

	HFONT  defalut = (HFONT)SelectObject(hdc, hfont);
	// 텍스트 출력
	//TextOut(hdc, x, y, text, lstrlen(text));

	RECT rect;
	SetRect(&rect, x + 20, y + 10, x + 270, y + 290);

	DrawText(hdc, text, lstrlen(text), &rect, DT_WORDBREAK);
	LPRECT();
	DeleteObject(SelectObject(hdc, defalut));

	// 비트맵 디바이스 컨텍스트 해제
	SelectObject(hMemDC, hOldBitmap);
	DeleteDC(hMemDC);

}

void ResourceManager::FeedBackScript(HDC hdc, HBITMAP hBitmap, int x, int y, int x_width, int y_width, const wchar_t* text, int fontSize)
{
	// 비트맵 디바이스 컨텍스트 생성
	HDC hMemDC = CreateCompatibleDC(hdc);
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBitmap);

	SetBkMode(hdc, 0);
	SetTextColor(hdc, RGB(0, 0, 0));

	HFONT  hfont = CreateFont(fontSize // 폰트의 높이
		, 0
		, 0
		, 0
		, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET
		, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY
		, DEFAULT_PITCH | FF_DONTCARE, L"KoPubWorld바탕체 Bold");

	HFONT  defalut = (HFONT)SelectObject(hdc, hfont);

	RECT rect;
	SetRect(&rect, x, y, x + x_width, y + y_width);

	DrawText(hdc, text, lstrlen(text), &rect, DT_WORDBREAK);
	LPRECT();
	DeleteObject(SelectObject(hdc, defalut));

	// 비트맵 디바이스 컨텍스트 해제
	SelectObject(hMemDC, hOldBitmap);
	DeleteDC(hMemDC);

}

void ResourceManager::Music_Init()
{

	// FMOD 시스템 객체 초기화
	/*result = FMOD_System_Create(&gSystem, FMOD_VERSION);

	result = FMOD_System_Init(gSystem, 3, FMOD_INIT_NORMAL, NULL);*/



	// 음성 파일 상대 경로
	string currentPath = _currentPath.string();
	string musicPath = currentPath + "\\Resources\\music";

	// bgm 파일
	string titleBGM = musicPath + "\\BGM\\1_Title_BGM.wav";
	string introBGM = musicPath + "\\BGM\\2_Intro_BGM.wav";
	string playSceneBGM = musicPath + "\\BGM\\3_PlayScene_BGM.wav";
	string feedbackBGM = musicPath + "\\BGM\\4_Feedback_BGM.wav";
	string endingBGM = musicPath + "\\BGM\\5_Ending_BGM.wav";

	//파일 경로 만들기

	//사운드 넣기
	result = FMOD_System_CreateSound(gSystem, titleBGM.c_str(), FMOD_DEFAULT, 0, &sound[0]);
	result = FMOD_System_CreateSound(gSystem, introBGM.c_str(), FMOD_DEFAULT, 0, &sound[1]);
	result = FMOD_System_CreateSound(gSystem, playSceneBGM.c_str(), FMOD_LOOP_NORMAL, 0, &sound[2]);
	result = FMOD_System_CreateSound(gSystem, feedbackBGM.c_str(), FMOD_DEFAULT, 0, &sound[3]);
	result = FMOD_System_CreateSound(gSystem, endingBGM.c_str(), FMOD_DEFAULT, 0, &sound[4]);

	string appearanceEffect = musicPath + "\\effect\\appearance.wav";
	string appearancePaperEffect = musicPath + "\\effect\\apperance_paper.wav";
	string buttonSlideEffect = musicPath + "\\effect\\button_slide.wav";
	string casherEffect = musicPath + "\\effect\\casher.wav";
	string click2Effect = musicPath + "\\effect\\click2.wav";
	string equipmentListEffect = musicPath + "\\effect\\equipment_list.wav";
	string giveEquipmentListEffect = musicPath + "\\effect\\give_equipment_list.wav";
	string giveIDCardEffect = musicPath + "\\effect\\give_id_card.wav";
	string giveMemberListEffect = musicPath + "\\effect\\give_member_list.wav";
	string givePaperEffect = musicPath + "\\effect\\give_paper.wav";
	string grabPaperEffect = musicPath + "\\effect\\grab_paper.wav";
	string leavingEffect = musicPath + "\\effect\\leaving.wav";
	string memberListEffect = musicPath + "\\effect\\member_list.wav";
	string mouseOverEffect = musicPath + "\\effect\\mouse_over.wav";
	string paperDeskEffect = musicPath + "\\effect\\paper_desk.wav";
	string putIDCardEffect = musicPath + "\\effect\\put_id_card.wav";
	string rejectEffect = musicPath + "\\effect\\reject.wav";
	string roundEndEffect = musicPath + "\\effect\\round_end.wav";
	string roundStartEffect = musicPath + "\\effect\\round_start.wav";
	string stampClickEffect = musicPath + "\\effect\\stamp_click.wav";

	//효과음 넣기
	result = FMOD_System_CreateSound(gSystem, appearanceEffect.c_str(), FMOD_DEFAULT, 0, &effectSound[0]);
	result = FMOD_System_CreateSound(gSystem, appearancePaperEffect.c_str(), FMOD_DEFAULT, 0, &effectSound[1]);
	result = FMOD_System_CreateSound(gSystem, buttonSlideEffect.c_str(), FMOD_DEFAULT, 0, &effectSound[2]);
	result = FMOD_System_CreateSound(gSystem, casherEffect.c_str(), FMOD_DEFAULT, 0, &effectSound[3]);
	result = FMOD_System_CreateSound(gSystem, click2Effect.c_str(), FMOD_DEFAULT, 0, &effectSound[4]);
	result = FMOD_System_CreateSound(gSystem, equipmentListEffect.c_str(), FMOD_DEFAULT, 0, &effectSound[5]);
	result = FMOD_System_CreateSound(gSystem, giveEquipmentListEffect.c_str(), FMOD_DEFAULT, 0, &effectSound[6]);
	result = FMOD_System_CreateSound(gSystem, giveIDCardEffect.c_str(), FMOD_DEFAULT, 0, &effectSound[7]);
	result = FMOD_System_CreateSound(gSystem, giveMemberListEffect.c_str(), FMOD_DEFAULT, 0, &effectSound[8]);
	result = FMOD_System_CreateSound(gSystem, givePaperEffect.c_str(), FMOD_DEFAULT, 0, &effectSound[9]);
	result = FMOD_System_CreateSound(gSystem, grabPaperEffect.c_str(), FMOD_DEFAULT, 0, &effectSound[10]);
	result = FMOD_System_CreateSound(gSystem, leavingEffect.c_str(), FMOD_DEFAULT, 0, &effectSound[11]);
	result = FMOD_System_CreateSound(gSystem, memberListEffect.c_str(), FMOD_DEFAULT, 0, &effectSound[12]);
	result = FMOD_System_CreateSound(gSystem, mouseOverEffect.c_str(), FMOD_DEFAULT, 0, &effectSound[13]);
	result = FMOD_System_CreateSound(gSystem, paperDeskEffect.c_str(), FMOD_DEFAULT, 0, &effectSound[14]);
	result = FMOD_System_CreateSound(gSystem, putIDCardEffect.c_str(), FMOD_DEFAULT, 0, &effectSound[15]);
	result = FMOD_System_CreateSound(gSystem, rejectEffect.c_str(), FMOD_DEFAULT, 0, &effectSound[16]);
	result = FMOD_System_CreateSound(gSystem, roundEndEffect.c_str(), FMOD_DEFAULT, 0, &effectSound[17]);
	result = FMOD_System_CreateSound(gSystem, roundStartEffect.c_str(), FMOD_DEFAULT, 0, &effectSound[18]);
	result = FMOD_System_CreateSound(gSystem, stampClickEffect.c_str(), FMOD_DEFAULT, 0, &effectSound[19]);
}

void ResourceManager::Release()
{
	FMOD_System_Close(gSystem);
	FMOD_System_Release(gSystem);
}

void ResourceManager::PlayMusicSound(int sound_number)
{
	FMOD_System_PlaySound(gSystem, sound[sound_number], NULL, 0, &channelMusic);
}

void ResourceManager::PlayEffect(int sound_number)
{
	FMOD_System_PlaySound(gSystem, effectSound[sound_number], NULL, 0, &channelEffect);
}

void ResourceManager::StopSound()
{
	// 재생 중인 사운드 멈추기
	FMOD_Channel_Stop(channelMusic);
}

int ResourceManager::Music_Update()
{
	FMOD_Channel_IsPlaying(channelMusic, &m_bool);

	if (m_bool) {
		FMOD_System_Update(gSystem);
	}

	return 0;
}
