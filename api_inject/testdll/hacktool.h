// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 TESTDLL_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// HACKTOOL_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifndef _HACK_TOOL_H
#define _HACK_TOOL_H


#ifdef TESTDLL_EXPORTS
#define HACKTOOL_API __declspec(dllexport)
#else
#define HACKTOOL_API __declspec(dllimport)
#endif

//#define DIRECT_USE_HACKTOOL
#ifdef DIRECT_USE_HACKTOOL
#undef HACKTOOL_API
#define HACKTOOL_API
#endif

#include <windows.h>

// 此类是从 testdll.dll 导出的
class HACKTOOL_API HackTool {
public:
	HackTool();

	~HackTool();

	DWORD findProcesIdByName(const char* processname);

	// inject dll into target process
	bool injectDll(DWORD pid, const char* dllname);

	static DWORD findWindowThread(const char* windclass, const char* windname);

	static bool logReopenToFile(const char* filename);

	static bool logRecover();

private:
	int OperationSystemVersion();

	void ReplaceApiAddr(HMODULE module, const char* dllname, const char* apiname, DWORD oldaddr, DWORD newaddr, UINT type);

	// create remote thread in hProcess by NtCreateThreadEx in ntdll.dll
	bool createRemoteThread(HANDLE hProcess, LPTHREAD_START_ROUTINE pThreadProc, LPVOID pRemoteBuf);

	
private:
	HMODULE m_module;
	HHOOK	m_hook;
};

#endif	// _HACK_TOOL_H
