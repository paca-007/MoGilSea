#pragma once
#include "Scene.h"
class StartScene :
    public Scene
{
private:
    static HWND hWnd;


public:
    virtual void Start();
    virtual void Exit();

    virtual void Update();

    static void SetHWND(HWND _hWnd) { hWnd = _hWnd; }
    

public:
    StartScene();
   virtual ~StartScene();

public:
    bool startButtonClick = false;
    bool endButtonClick = false;
    bool creditButtonClick = false;
};

