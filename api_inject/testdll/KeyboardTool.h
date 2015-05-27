#pragma once

#include "hacktool.h"

class HACKTOOL_API KeyboardTool
{
public:
	KeyboardTool();
	
	~KeyboardTool(void);

	bool start(HINSTANCE hModule, DWORD thread);

	void stop();

	static KeyboardTool* getInstance();

private:
	static LRESULT CALLBACK keyboardProc(int code, WPARAM wParam, LPARAM lParam);

private:
	HHOOK m_hHook;

	static KeyboardTool* s_instance;
};

