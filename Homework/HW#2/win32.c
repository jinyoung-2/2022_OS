#include<stdio.h>
#include<windows.h>
#include<tchar.h>

#define DIR_LEN BUFSIZ

int _tmain(int argc, TCHAR* argv[]) {
    STARTUPINFO si = { 0, };    //구조체 선언, 초기화
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
//	STARTUPINFO si; // 프로세스의 메인 윈도우에 대한 정보 저장 구조체
//	PROCESS_INFORMATION pi; // 생성될 프로세스와 기본 쓰레드에 대한 포인터 및 식별자 저장 구조체
//	const char* command = "C:\\Windows\\notepad.exe"; // 실행할 프로그램
//	ZeroMemory(&si, sizeof(si));
//	si.cb = sizeof(si);
//	ZeroMemory(&pi, sizeof(pi));
//
//	if (!CreateProcess( NULL, // 현재 프로세스의 실행파일이름
//		(LPTSTR )command, // 실행할 프로그램에 대한 명령문
//		NULL, // 프로세스 보안 속성
//		NULL, // 쓰레드 보안 속성
//		FALSE, // Set handle inheritance to FALSE
//		0, // 플래그(flag) 생성 여부
//		NULL, // 새로운 환경 블록 포인터
//		NULL, // 현재 디렉토리 이름
//		&si, // STARTUPINFO 구조체
//		&pi)) // PROCESS_INFORMATION 구조체
//	{
//		fprintf(stderr, "Create Process Failed");
//		return -1;
//	}
//
//	WaitForSingleObject(pi.hProcess, INFINITE); // 자식 프로세스가 종료할 때까지 대기
//	printf("Child Complete");
//
//	CloseHandle(pi.hProcess);
//	CloseHandle(pi.hThread);
//}