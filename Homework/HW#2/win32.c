#include<stdio.h>
#include<windows.h>
#include<tchar.h>

#define DIR_LEN BUFSIZ

int _tmain(int argc, TCHAR* argv[]) {
    STARTUPINFO si = { 0, };    //����ü ����, �ʱ�ȭ
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    si.dwFlags = STARTF_USEPOSITION | STARTF_USESIZE;
    si.dwX = 100;
    si.dwY = 100;
    si.dwXSize = 300;
    si.dwYSize = 300;  

    si.lpTitle = _T(" Child process! ");

    TCHAR command[] = _T("notepad 10 10");

    BOOL state;

    if (!CreateProcess(NULL, 
        command, 
        NULL, NULL,
        TRUE, 
        CREATE_NEW_CONSOLE, 
        NULL, NULL,
        &si, 
        &pi  
    )) {
        fprintf(stderr, "Create Process Failed");
        return -1;
    }

    WaitForSingleObject(pi.hProcess, INFINITE); 
    printf("Child Complete");

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}


//#include <stdio.h>
//#include <windows.h>
//
//int main() {
//	STARTUPINFO si; // ���μ����� ���� �����쿡 ���� ���� ���� ����ü
//	PROCESS_INFORMATION pi; // ������ ���μ����� �⺻ �����忡 ���� ������ �� �ĺ��� ���� ����ü
//	const char* command = "C:\\Windows\\notepad.exe"; // ������ ���α׷�
//	ZeroMemory(&si, sizeof(si));
//	si.cb = sizeof(si);
//	ZeroMemory(&pi, sizeof(pi));
//
//	if (!CreateProcess( NULL, // ���� ���μ����� ���������̸�
//		(LPTSTR )command, // ������ ���α׷��� ���� ��ɹ�
//		NULL, // ���μ��� ���� �Ӽ�
//		NULL, // ������ ���� �Ӽ�
//		FALSE, // Set handle inheritance to FALSE
//		0, // �÷���(flag) ���� ����
//		NULL, // ���ο� ȯ�� ��� ������
//		NULL, // ���� ���丮 �̸�
//		&si, // STARTUPINFO ����ü
//		&pi)) // PROCESS_INFORMATION ����ü
//	{
//		fprintf(stderr, "Create Process Failed");
//		return -1;
//	}
//
//	WaitForSingleObject(pi.hProcess, INFINITE); // �ڽ� ���μ����� ������ ������ ���
//	printf("Child Complete");
//
//	CloseHandle(pi.hProcess);
//	CloseHandle(pi.hThread);
//}