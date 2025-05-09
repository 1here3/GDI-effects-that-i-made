
	POINT ptScreen = GetVirtualScreenPos();
	SIZE szScreen = GetVirtualScreenSize();

	t *= 30;

	RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);

	HDC hcdc = CreateCompatibleDC(hdcScreen);
	HBITMAP hBitmap = CreateCompatibleBitmap(hdcScreen, szScreen.cx, szScreen.cy);
	SelectObject(hcdc, hBitmap);
	Sleep(50);
	BitBlt(hcdc, 0, 0, szScreen.cx, szScreen.cy, hdcScreen, 0, 0, NOTSRCCOPY);
	SelectObject(hdcScreen, CreatePatternBrush(hBitmap));

	Ellipse(hdcScreen, t % szScreen.cx + 20, t % szScreen.cy + 20, t % szScreen.cx + t % 101 + 180, t % szScreen.cy + t % 101 + 180);
	BitBlt(hcdc, 0, 0, szScreen.cx, szScreen.cy, hdcScreen, 0, 0, NOTSRCCOPY);
	SelectObject(hdcScreen, CreatePatternBrush(hBitmap));
	Ellipse(hdcScreen, t % szScreen.cx + 10, t % szScreen.cy + 10, t % szScreen.cx + t % 101 + 190, t % szScreen.cy + t % 101 + 190);
	Ellipse(hdcScreen, t % szScreen.cx, t % szScreen.cy, t % szScreen.cx + t % 101 + 200, t % szScreen.cy + t % 101 + 200);
	BitBlt(hcdc, 0, 0, szScreen.cx, szScreen.cy, hdcScreen, 0, 0, NOTSRCCOPY);
	SelectObject(hdcScreen, CreatePatternBrush(hBitmap));
	Ellipse(hdcScreen, t % szScreen.cx, t % szScreen.cy, t % szScreen.cx + t % 101 + 200, t % szScreen.cy + t % 101 + 200);

	SetBkColor(hdcScreen, RGB(random() % 256, random() % 256, random() % 256));
	SetTextColor(hdcScreen, RGB(random() % 256, random() % 256, random() % 256));

	for (int i = 0; i < 5; i++) {
		TextOut(hdcScreen, random() % szScreen.cx, random() % szScreen.cy, L"     ", 5);
	}

	DeleteObject(hcdc);
	DeleteObject(hBitmap);
