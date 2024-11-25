#include "pch.h"
#include "OFeedbackBackground.h"
#include "ResourceManager.h"

void OFeedbackBackground::Update()
{
	_feedbackType = GetFeedbackType();
}

void OFeedbackBackground::Render(HDC hdc)
{


	HBITMAP background = {};
	
	switch (_feedbackType)
	{
	case FeedbackSceneType::MAIN_1:
	{
		 background = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\Feedback\\Feedback_1.bmp");
	}
		break;
	case FeedbackSceneType::MAIN_2:
	{
		 background = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\Feedback\\Feedback_2.bmp");
	}
	break;
	case FeedbackSceneType::MAIN_3:
	{
		 background = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\Feedback\\Feedback_3.bmp");
	}
	break;
	case FeedbackSceneType::EDEN:
	{
		 background = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\Feedback\\Feedback_eden.bmp");
	}
		break;
	case FeedbackSceneType::DARIUS:
	{
		 background = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\Feedback\\Feedback_Darius.bmp");
	}
		break;
	case FeedbackSceneType::LILIAN:
	{
		 background = GET_SINGLE(ResourceManager)->GetImg(L"Resources\\UI\\Feedback\\Feedback_Lilian.bmp");
	}
		break;
	}
	

	GET_SINGLE(ResourceManager)->DrawAlphaImg(hdc, background, 0, 0, 255);
}
