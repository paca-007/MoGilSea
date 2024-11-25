#pragma once

class Texture;
class Adventurer;
class Event;
class Quest;

class ResourceManager
{
	DECLARE_SINGLE(ResourceManager);

public:
	~ResourceManager();
	
	void Init(HWND hwnd, filesystem::path resourcePath);
	void Clear();
	static HFONT  m_font;

	const filesystem::path& GetResourcePath() { return _resourcePath; }

	//Texture* LoadTexture(const wstring& key, const wstring& path, uint32 transparent = RGB(255, 255, 255));
	unordered_map<wstring, Adventurer> ReadADVCSV(const wstring& filePath);
	unordered_map<wstring, Event> ReadEventCSV(const wstring& filePath);
	unordered_map<wstring, Quest> ReadQuestCSV(const wstring& filePath);

	filesystem::path& GetCurrentPath() { return _currentPath; }
	
	HBITMAP GetImg(const wstring& path);
	void Draw24Img(HDC hdc, HBITMAP hBitmap, int x, int y);
	void DrawBackImg(HDC hdc, HBITMAP hBitmap, int x, int y);
	void DrawAlphaImg(HDC hdc, HBITMAP hBitmap, int x, int y, int _alpha);

	void DrawTextOnBitmap(HDC hdc, HBITMAP hBitmap, int x, int y, const wchar_t* text, int fontSize);
	void FeedBackScript(HDC hdc, HBITMAP hBitmap, int x, int y, int x_width, int y_width, const wchar_t* text, int fontSize);
	
	//À½¾ÇÇÔ¼ö
	void Music_Init();
	void Release();
	void PlayMusicSound(int sound_number);
	void PlayEffect(int sound_number);
	void StopSound();
	int Music_Update();

private:
	HWND _hwnd;
	filesystem::path _resourcePath;
	filesystem::path _currentPath = filesystem::current_path();

	wstring _path[255];
	wstring _pathWithReScource[255];

	//unordered_map<wstring, Texture*> _textures;

public:
	FMOD_SYSTEM* gSystem{};
	FMOD_SOUND* sound[5]{};
	FMOD_SOUND* effectSound[20]{};
	FMOD_RESULT result{};
	FMOD_CHANNEL* channelMusic{};
	FMOD_CHANNEL* channelEffect{};
	FMOD_BOOL m_bool{};
};

