#include <windows.h>
#include <windowsx.h>


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // ÊÚׁםÝ

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {

// ַב־״זֹ ַבַזבל : Úדב ַבדÊÛםַׁÊ
	WNDCLASSEX wndclass; //דÊÛםׁ ßבַ׃ ַבזהֿז
	MSG msg; // םÊÚַדב זםֽדב ּדםÚ ׁ׃ֶַב ַבהַÝ׀ֹ
	HWND hwnd; // ו׀ַ ַבדÊÛםׁ Úַָֹׁ Úה ׁÞד ָׁהַדּהַ ָֽםֻ ÊÊÚׁÝ Úבםֹ זהֿזׂ
	static char szAppName[] = "FIRST WINDOW PROGRAM"; // דּדזÚֹ ַֽׁÝ ÊÚָׁ Úה ַ׃ד ַבָׁהַדּ

	// ַב־״זֹ ַבַֻהםֹ : Úדב דֽÊזםַÊ ßבַ׃ ַבהַÝ׀ֹ ַבזהֿז

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

	// ַב־״זֹ ַבַֻבֹֻ: Ê׃ּםב דֽÊזםַÊ ַבßבַ׃ ַבל הÙַד 
	if (!(RegisterClassEx(&wndclass)))
		return FALSE;

	// ַב־״זֹ ַבַָׁÚֹ : בהֱַָֿ ָÚדב ַבהַÝ׀ֹ ַבזהֿז
	hwnd = CreateWindowEx(WS_EX_APPWINDOW,// Extended Window Style הײÚ הזÚ ַבהַÝ׀ֹ
		szAppName,// ַ׃ד ַבהַÝ׀ֹ דה ַבדÊÛםׁ ַב׃ַָÞ
		"ָׁהַדּם ַבַזב",// ַבַ׃ד ַבÙַוׁ Ýם ַÚבל ַבהַÝ׀ֹ
		WS_OVERLAPPEDWINDOW,// ױÝַÊ ַבהַÝ׀ֹ
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,// Þםד זַַּֽד ַב׃םה זַבױַֿ x,y
		NULL, NULL,// Þםד זַַּֽד ַב׃םה זַבױַֿ
		hInstance,// ׁÞד ָׁהַדּהַ pid
		NULL);

	//ַב־״זֹ ַב־ַד׃ֹ : Úׁײ ַבהַÝ׀ֹ ַבזהֿז
	ShowWindow(hwnd, iCmdShow); // ַÙוַׁ ַבהַÝ׀ֹ

	// ַב־״זֹ ַב׃ַֿ׃ֹ : Ýׁײ Êֽֿםֻ בבזהֿז ַבהַÝ׀ֹ
	UpdateWindow(hwnd);// Êּֿםֿ בבהַÝ׀ֹ

	
/*
ַב־״זֹ ַב׃ַָÚֹ : Úדב ֿזַדֹ בַהוֶַםֹ בÚׁײ ַבׁ׃ֶַב ַבדזּזֹֿ זַבÊÚַדב דÚוַ ָװßב ֿזׁם
דֻב Êֽׁםß ַבהַÝ׀ֹ ַז זײÚ ַבדִװׁ Úבל ַבהַÝ׀ֹ זÛםׁוַ דה ַבׁ׃ֶַב
(ֿזֹׁ ׁ׃ֶַב זהֿזׂ)
*/
	while (true) {
		if (!GetMessage(&msg, NULL, 0, 0))
			return msg.wParam;
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

}

//ַב־״זֹ ַבַֻדהֹ : Úדבםֹ ַ׃ÊֿÚֱַ דּֿֿ בזײםÝֹ
// Êװדב ַ־ׁ ־״זÊםה Ýם ַבהזַÝ׀

// wndproc ום זÙםÝֹ ַ׃ÊֿÚֱַ
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	//ַב־״זֹ ַבÊַ׃Úֹ : Úדב דÊÛםַׁÊ בבזײםÝֹ
	HDC hdc; // ו׀ַ ַבדÊÛםׁ םֽדב ׁÞד ßׁÊ ַבװַװֹ --- ׀ַßֹׁ ַבÚׁײ --
	PAINTSTRUCT ps; // ׃ÊׁßÊװׁ בבׁ׃ד
	RECT rect; // ד׃Ê״םב ַבהַÝ׀ֹ
	static bool fFirstPaint = true;

	//ַב־״זֹ ַבÚַװֹׁ : ַבÊÚַדב דÚ ַבׁ׃ֱַב 
	switch (iMsg)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
			// Ýם ַֽבֹ ײÛ״ Úבל ו׀ו ַבַַׁׁׂ םÞזד ַבָׁהַדּ ַָב־ׁזּ
		case VK_ESCAPE:
		case VK_F12:
			PostMessage(hwnd, WM_CLOSE, 0, 0);
			return 0;
		}
		return 0;
	
	case WM_PAINT:
		// ַבַה הÞזד ַָÚַֿֿ הַÝ׀ֹ ַבד״בזָֹ בבׁ׃ד BeginPaint
		/*
		ָדÚהל הÞזד ָÊֽֿםֿ ּדםÚ ַבדßזהַÊ ַבÙַוֹׁ Ýם Êבß ַבװַװֹ ֻד הÞזד ָÊÚֶָֹ ַבדÊÛםׁ
		PAINTSTRUCT
		זו׀ַ ַבדÊÛםׁ דה הזÚ struct
		זהÝזד ָÊÚֶָÊו ָדÚבזדַÊ Úה דßזהַÊ ַבׁ׃ד*/
		hdc = BeginPaint(hwnd, &ps);
		/* ָÚֿ ׀בß ÊÞזד זÙםÝֹ
		GetClientRect
		ָÊÚֶָֹ ַבדÛםׁ
		RECT
		ָּֽד ד׃Ê״םב ַבהַÝ׀ֹ דֻב װַװֹ ַבßדָםזÊׁ בַהוַ ׀ַÊ װßב ד׃Ê״םב ז׀ַÊ 
		ַָÚַֿ ד־ÊבÝֹ
		*/
		GetClientRect(hwnd, &rect);
		DrawText(hdc, "דַָֽׁ ַםוַ ַבÚַבד", -1, &rect, DT_SINGLELINE |
			DT_CENTER | DT_VCENTER); // הÞזד ָׁ׃ד ַז Úׁײ ּדבֹ Úבל ַבװַװֹ
		EndPaint(hwnd, &ps);/*
							ÊÞזד ו׀ו ַבזÙםÝֹ ַָהוֱַ ַבׁ׃ד Úבל ַבהַÝ׀ֹ בבָׁהַדּ
							ב׀בß םÞזד ַבָׁהַדּ ַָ׃ÊֿÚַוַ Ýם ßב דֹׁ םהÊום ׁ׃ד װֶ Úבל ַבװַװַֹ
							*/ 
		if (fFirstPaint)
		{
			ShowCursor(TRUE);
			fFirstPaint = FALSE;
		}
		return 0;

		// ַב״ׁםÞֹ ַבדֻבל בַהוֱַ ֿזַדֹ ַבׁ׃ֶַב Ýם ַבָׁהַדּ זַב־ׁזּ דהו בב׃דַֽ בבהÙַד ַָ׃Ê־ַֿד ַב׀ַßֹׁ
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);// Ýם ַבהוַםֹ הÞזד ַָבÊÛַײם Úה ַם ׁ׃ַבֹ דה ַבהÙַד בַהוַ בַÊוד ָׁהַדּהַ זהÞזד ָÊֽזםבוַ דַּֿֿ בבהÙַד
}