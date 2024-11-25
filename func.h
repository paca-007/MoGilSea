#pragma once
#include "pch.h"

class Object;

void CreateObject(Object* _pObj, ObjectType _eObject);

void ChangeScene(SceneType _eNext);



//PlaySceen btn
bool BargainBtnClick(Vec2 _mousePos, Object* _mObj, Object* _fObj, Object* _feeObj, bool buttonStatus);
bool ApplyBtnClick(Vec2 _mousePos, Object* _mObj, Object* _fObj , Object* _feeObj, int charaterOrder, bool buttonStatus);
bool ApprovalBtnClick(Vec2 _mousePos, Object* _feeObj, bool buttonStatus, int charaterOrder);
bool RefuseBtnClick(Vec2 _mousePos, Object* _feeObj, bool buttonStatus, int charaterOrder);

//FeedbackSceen btn
bool NextBtnClick(Vec2 _mousePos);
bool SkipBtnClick(Vec2 _mousePos);

//startSceen btn
bool StartBtnClick(Vec2 _mousePos);
bool EndBtnClick(Vec2 _mousePos);
bool CreditBtnClick(Vec2 _mousePos);

//script Click
bool IsScriptClick(Vec2 _mousePos);

//player loop function
void popUPImage(Object* _pObj, Object* _idObj, CharacterName characterOrder);
void popUPScript(Object* _pObj);

void popDownScript(Object* _pObj);

bool Speak(Object* _pObj, int num, int characterOrder);



