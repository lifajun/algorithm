#include <windows.h>
#include <stdlib.h>
#include <math.h>

#define COUNT	200

const double	SPLIT = 0.01;
const double	PI = 3.14159265;
const double	SLOPE = 150;
const int INTERVAL = 300;

DWORD WINAPI SineThread(LPVOID Sine)
{
	DWORD busySpan[COUNT];
	DWORD idleSpan[COUNT];
	int half = INTERVAL/2;
	double radian = 0.0;
	DWORD startTime;
	int i;

	for (i=0; i<COUNT; i++)
	{
		busySpan[i] = (DWORD)(half + half*sin(PI*radian));
		idleSpan[i] = (DWORD)(INTERVAL - busySpan[i]);
		radian += SPLIT;
	}
	i = 0;
	while(1)
	{
		i %= COUNT;
		startTime = GetTickCount();
		while((GetTickCount()-startTime) <= busySpan[i])
			;
		Sleep(idleSpan[i]);
		i++;
	}
	return 0;
}

DWORD WINAPI SawThread(LPVOID Saw)
{
	DWORD busySpan[COUNT];
	DWORD idleSpan[COUNT];
	int half = INTERVAL/2;
	double radian = 0.0;
	DWORD startTime;
	int i;

	for (i=0; i<COUNT; i++)
	{
		busySpan[i] = (DWORD)(SLOPE*radian);
		idleSpan[i] = (DWORD)(INTERVAL - busySpan[i]);
		radian += SPLIT;
	}
	i = 0;
	while(1)
	{
		i %= COUNT;
		startTime = GetTickCount();
		while((GetTickCount()-startTime) <= busySpan[i])
			;
		Sleep(idleSpan[i]);
		i++;
	}
	return 0;
}

int main()
{
	HANDLE hThread1, hThread2;
	DWORD dwThreadId1, dwThreadId2;

	hThread1 = CreateThread(NULL, 0, SineThread, 0, CREATE_SUSPENDED, &dwThreadId1);
	hThread2 = CreateThread(NULL, 0, SawThread, 0, CREATE_SUSPENDED, &dwThreadId2);
	SetThreadAffinityMask(hThread1, 1);
	SetThreadAffinityMask(hThread2, 2);
	ResumeThread(hThread1);
	ResumeThread(hThread2);
	SuspendThread(GetCurrentThread());
	return 0;
}