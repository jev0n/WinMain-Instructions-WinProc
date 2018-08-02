#include <windows.h>
#include <windowsx.h>


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // �����

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {

// ������ ������ : ��� ���������
	WNDCLASSEX wndclass; //����� ���� ������
	MSG msg; // ������ ����� ���� ����� �������
	HWND hwnd; // ��� ������� ����� �� ��� �������� ���� ����� ���� �����
	static char szAppName[] = "FIRST WINDOW PROGRAM"; // ������ ���� ���� �� ��� ��������

	// ������ ������� : ��� ������� ���� ������� ������

	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;

	// ������ �������: ����� ������� ������ ��� ���� 
	if (!(RegisterClassEx(&wndclass)))
		return FALSE;

	// ������ ������� : ������ ���� ������� ������
	hwnd = CreateWindowEx(WS_EX_APPWINDOW,// Extended Window Style ��� ��� �������
		szAppName,// ��� ������� �� ������� ������
		"������� �����",// ����� ������ �� ���� �������
		WS_OVERLAPPEDWINDOW,// ���� �������
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,// ��� ������ ����� ������ x,y
		NULL, NULL,// ��� ������ ����� ������
		hInstance,// ��� �������� pid
		NULL);

	//������ ������� : ��� ������� ������
	ShowWindow(hwnd, iCmdShow); // ����� �������

	// ������ ������� : ��� ����� ������ �������
	UpdateWindow(hwnd);// ����� �������

	
/*
������ ������� : ��� ����� �������� ���� ������� �������� �������� ���� ���� ����
��� ����� ������� �� ��� ������ ��� ������� ������ �� �������
(���� ����� �����)
*/
	while (true) {
		if (!GetMessage(&msg, NULL, 0, 0))
			return msg.wParam;
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

}

//������ ������� : ����� ������� ���� ������
// ���� ��� ������ �� �������

// wndproc �� ����� �������
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	//������ ������� : ��� ������� �������
	HDC hdc; // ��� ������� ���� ��� ��� ������ --- ����� ����� --
	PAINTSTRUCT ps; // ������� �����
	RECT rect; // ������ �������
	static bool fFirstPaint = true;

	//������ ������� : ������� �� ������� 
	switch (iMsg)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
			// �� ���� ��� ��� ��� ������� ���� �������� �������
		case VK_ESCAPE:
		case VK_F12:
			PostMessage(hwnd, WM_CLOSE, 0, 0);
			return 0;
		}
		return 0;
	
	case WM_PAINT:
		// ���� ���� ������ ����� �������� ����� BeginPaint
		/*
		����� ���� ������ ���� �������� ������� �� ��� ������ �� ���� ������ �������
		PAINTSTRUCT
		���� ������� �� ��� struct
		����� ������� �������� �� ������ �����*/
		hdc = BeginPaint(hwnd, &ps);
		/* ��� ��� ���� �����
		GetClientRect
		������ ������
		RECT
		���� ������ ������� ��� ���� ��������� ����� ��� ��� ������ ���� 
		����� ������
		*/
		GetClientRect(hwnd, &rect);
		DrawText(hdc, "����� ���� ������", -1, &rect, DT_SINGLELINE |
			DT_CENTER | DT_VCENTER); // ���� ���� �� ��� ���� ��� ������
		EndPaint(hwnd, &ps);/*
							���� ��� ������� ������ ����� ��� ������� ��������
							���� ���� �������� ��������� �� �� ��� ����� ��� �� ��� �������
							*/ 
		if (fFirstPaint)
		{
			ShowCursor(TRUE);
			fFirstPaint = FALSE;
		}
		return 0;

		// ������� ������ ������ ����� ������� �� �������� ������� ��� ������ ������ �������� �������
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);// �� ������� ���� �������� �� �� ����� �� ������ ����� ����� �������� ����� �������� ����� ������
}