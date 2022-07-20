#pragma once
#include <iostream>
#include <windows.h>
class Terminal {
private:
	CONSOLE_FONT_INFOEX font;
	char* buffer;
	HANDLE handle;
	int bufferSize;
public:
	COORD screenSize;
	Terminal(); //class constructor
	void PutPixel(char, COORD);
	void PutPixel(char, short, short);
	void ClearBuffer(char = '#');
	void DrawFrame();

	//rasterization
private:
    void plotLineHigh(int x0, int y0, int x1, int y1, char c);
    void plotLineLow(int x0, int y0, int x1, int y1, char c);
public:
    void drawLine(int x0, int y0, int x1, int y1, char c);
	void drawTriangle(int x0, int y0, int x1, int y1, int x2, int y2 ,char c, bool fill = false);
};