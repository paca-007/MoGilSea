#pragma once

#define DECLARE_SINGLE(classname)			\
private:									\
	classname() { }							\
public:										\
	static classname* GetInstance()			\
	{										\
		static classname s_instance;		\
		return &s_instance;					\
	}

#define GET_SINGLE(classname)	classname::GetInstance()

#define SAFE_DELETE(ptr)		\
	if (ptr)					\
	{							\
		delete ptr;				\
		ptr = nullptr;			\
	}

#define DT TimeManager::GetInstance()->getDeltaTime()

#define KEY_CHECK(key, state) InputManager::GetInstance()->GetKeyState(key) == state
#define KEY_HOLD(key)  KEY_CHECK(key, KEY_STATE::HOLD)
#define KEY_TAP(key)  KEY_CHECK(key, KEY_STATE::TAP)
#define KEY_AWAY(key)  KEY_CHECK(key, KEY_STATE::AWAY)
#define KEY_NONE(key)  KEY_CHECK(key, KEY_STATE::NONE)