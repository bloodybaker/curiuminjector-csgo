#include <Windows.h>
#include <TlHelp32.h>
// Junk code to make injector undetected
#include "JunkCode.h"

#define DLL_NAME "curium.dll"

// And you need:
// 1. change all bytes(0x00, 0x01, 0x03....) in define "JUNKS" to random bytes
// 2. change size this block by adding new bytes
#define JUNKS \
__asm _emit 0x06 \
__asm _emit 0x83 \
__asm _emit 0x08 \
__asm _emit 0x23 \
__asm _emit 0x61 \
__asm _emit 0x66 \
__asm _emit 0x58 \
__asm _emit 0x35 \
__asm _emit 0x53 \
__asm _emit 0x67 \
__asm _emit 0x42 \
__asm _emit 0x63 \
__asm _emit 0x54 \
__asm _emit 0x52 \
__asm _emit 0x28 \
__asm _emit 0x24 \
__asm _emit 0x07 \
__asm _emit 0x97 \
__asm _emit 0x42 \
__asm _emit 0x71 \
__asm _emit 0x44 \
__asm _emit 0x75 \
__asm _emit 0x20 \
__asm _emit 0x34 \
__asm _emit 0x59 \
__asm _emit 0x25 \
__asm _emit 0x54 \
__asm _emit 0x57 \
__asm _emit 0x77 \
__asm _emit 0x16 \
__asm _emit 0x89 \
__asm _emit 0x75 \
__asm _emit 0x76 \
__asm _emit 0x17 \
__asm _emit 0x76 \
__asm _emit 0x74 \
__asm _emit 0x51 \
__asm _emit 0x77 \
__asm _emit 0x25 \
__asm _emit 0x35 \
__asm _emit 0x50 \
__asm _emit 0x16 \
__asm _emit 0x02 \
__asm _emit 0x01 \
__asm _emit 0x66 \
__asm _emit 0x93 \
__asm _emit 0x41 \
__asm _emit 0x13 \
__asm _emit 0x83 \
__asm _emit 0x37 \


// Don't change this!
#define _JUNK_BLOCK(s) __asm jmp s JUNKS __asm s:


/////////////////////////////////////////////////////////////////////////////////////
//                                 INJECTOR CODE                                   //
/////////////////////////////////////////////////////////////////////////////////////

DWORD Process(char* ProcessName)
{
	_JUNK_BLOCK(jmp_label1)
	HANDLE hPID = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	
	_JUNK_BLOCK(jmp_label2)
	PROCESSENTRY32 ProcEntry;
	
	_JUNK_BLOCK(jmp_label3)
	ProcEntry.dwSize = sizeof(ProcEntry);
	
	_JUNK_BLOCK(jmp_label4)
	do
	{
		_JUNK_BLOCK(jmp_label5)
		if (!strcmp(ProcEntry.szExeFile, ProcessName))
		{
			_JUNK_BLOCK(jmp_label6)
			DWORD dwPID = ProcEntry.th32ProcessID;
			
			_JUNK_BLOCK(jmp_label7)
			CloseHandle(hPID);
			
			_JUNK_BLOCK(jmp_label8)
			return dwPID;
		}
		
		_JUNK_BLOCK(jmp_label9)
	}
	while (Process32Next(hPID, &ProcEntry));
	
	_JUNK_BLOCK(jmp_label10)
}

int main()
{
	_JUNK_BLOCK(jmp_label11)
	DWORD dwProcess;
	
	_JUNK_BLOCK(jmp_label12)
	char myDLL[MAX_PATH];
	
	_JUNK_BLOCK(jmp_label13)
	GetFullPathName(DLL_NAME, MAX_PATH, myDLL, 0);
	
	_JUNK_BLOCK(jmp_label4)
	dwProcess = Process("csgo.exe");
	
	_JUNK_BLOCK(jmp_label15)
	pBut();
	yAD();
	mop();
	LlKk();
	AfUh();
	HANDLE hProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, dwProcess);
	
	_JUNK_BLOCK(jmp_label16)
	xtXP();
	BNxW();
	Wchh();
	Xze();
	DbL();
	LPVOID allocatedMem = VirtualAllocEx(hProcess, NULL, sizeof(myDLL), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	
	_JUNK_BLOCK(jmp_label17)
	dmfc();
	tXm();
	dgm();
	qmY();
	MYa();
	WriteProcessMemory(hProcess, allocatedMem, myDLL, sizeof(myDLL), NULL);
	
	_JUNK_BLOCK(jmp_label18)
	gHo();
	iHj();
	TNsp();
	DHaz();
	SieU();
	CreateRemoteThread(hProcess, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibrary, allocatedMem, 0, 0);
	
	_JUNK_BLOCK(jmp_label19)
	CloseHandle(hProcess);
	
	_JUNK_BLOCK(jmp_label20)
	return 0;
}