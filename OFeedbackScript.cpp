#include "pch.h"
#include "OFeedbackScript.h"
#include "ResourceManager.h"


void OFeedbackScript::Update()
{
	x = GetposX();
	y = GetposY();
	x_width = GetXWidth();
	y_width = GetYWidth();

	_script = GetScript();
}

void OFeedbackScript::Render(HDC hdc)
{
	HBITMAP check = nullptr;

	// 텍스트 출력
	GET_SINGLE(ResourceManager)->FeedBackScript(hdc, check, x, y, x_width, y_width, _script.c_str(), 50);
	
}