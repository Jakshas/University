#include <Windows.h>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <vector>


void klientThread(LPVOID* arg)
{
	HANDLE hMutex = (HANDLE)(*arg);
	WaitForSingleObject(hMutex, INFINITE);
	int r = rand() % 4;
	printf("Klient strzyrzony\n");
	Sleep(r * 1000);
	ReleaseMutex(hMutex);
	return;

}

void lawkaThread(LPVOID* arg)
{
	std::vector<HANDLE> lawka;
	HANDLE hMutex = (HANDLE)(*arg);
	while (true) {
		int r = rand() % 4;
		Sleep(r * 1000);
		printf("Przychodzi klient\n");
		HANDLE klient = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)klientThread, &hMutex, NULL, NULL);

	}
}




int main()
{
	srand((unsigned)time(NULL));
	HANDLE klienci;
	HANDLE hMutex = CreateMutex(NULL, FALSE, "BARBER_PRACA");

	klienci = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)lawkaThread, &hMutex, NULL, NULL);
	WaitForSingleObject(klienci, INFINITE);
	return 0;
}