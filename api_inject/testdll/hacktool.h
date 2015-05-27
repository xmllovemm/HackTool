// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� TESTDLL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// HACKTOOL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
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

// �����Ǵ� testdll.dll ������
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
