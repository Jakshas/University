#include <windows.h>
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
char szClassName[] = "Zadanie2";
int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance,
	LPSTR lpszArgument, int nFunsterStil)
{
	HWND hwnd;
	MSG messages;
	WNDCLASSEX wincl;

	wincl.hInstance = hThisInstance;
	wincl.lpszClassName = szClassName;
	wincl.lpfnWndProc = WindowProcedure;
	wincl.style = CS_DBLCLKS;
	wincl.cbSize = sizeof(WNDCLASSEX);

	wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wincl.lpszMenuName = NULL;
	wincl.cbClsExtra = 0;
	wincl.cbWndExtra = 0;

	wincl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);

	if (!RegisterClassEx(&wincl)) return 0;

	hwnd = CreateWindowEx(
		0,
		szClassName,
		"Zadanie2",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		512,
		512,
		HWND_DESKTOP,
		NULL,
		hThisInstance,
		NULL
	);
	ShowWindow(hwnd, nFunsterStil);

	SetTimer(hwnd, 1, 25, NULL);

	while (GetMessage(&messages, NULL, 0, 0))
	{
		TranslateMessage(&messages);
		DispatchMessage(&messages);
	}
	return messages.wParam;
}
int xSize, ySize, xPos = 100, yPos = 100;
int dir[2] = {1,1};
RECT r;

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	int i;
	PAINTSTRUCT ps;
	HPEN hPen;

	switch (message)
	{
	case WM_TIMER:
		if (yPos <= 20 || yPos >= ySize - 20)
		{
			dir[1] ^= 1;
		} 
		if (xPos <= 20 || xPos >= xSize - 20)
		{
			dir[0] ^= 1;
		} 

		if (dir[1] == 1) 
			yPos = yPos + 2;
		else
			yPos = yPos - 2;
		if (dir[0] == 1)
			xPos = xPos + 2;
		else
			xPos = xPos - 2;

		hdc = GetDC(hwnd);
		FillRect(hdc, &r, (HBRUSH)GetStockObject(WHITE_BRUSH));

		hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
		SelectObject(hdc, hPen);
		Ellipse(hdc, xPos - 20, yPos - 20, xPos + 20, yPos + 20);
		ReleaseDC(hwnd, hdc);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_SIZE:
		xSize = LOWORD(lParam);
		ySize = HIWORD(lParam);
		GetClientRect(hwnd, &r);
		InvalidateRect(hwnd, &r, 1);

		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}