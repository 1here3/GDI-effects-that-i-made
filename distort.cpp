	POINT ptScreen = GetVirtualScreenPos();
	SIZE szScreen = GetVirtualScreenSize();

	POINT pt[3];
	pt[0] = { 0,0 };
	pt[1] = { szScreen.cx,0 };
	pt[2] = { 25,szScreen.cy };
	PlgBlt(hdcScreen, pt, hdcScreen, ptScreen.x, ptScreen.y, szScreen.cx + 25, szScreen.cy, NULL, 0, 0);

	SelectObject(hdcScreen, CreateSolidBrush(RGB(random() % 256, random() % 256, random() % 256)));
	PatBlt(hdcScreen, ptScreen.x, ptScreen.y, szScreen.cx, szScreen.cy, PATINVERT);

	Sleep(50);
}
