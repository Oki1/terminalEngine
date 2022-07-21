#pragma once
#include <iostream>
#include <windows.h>
#undef min //make c++ daddy happy and use std::max
#undef max
class Terminal {
private:
	CONSOLE_FONT_INFOEX font;
	char* buffer;
	HANDLE handle;
	int bufferSize;
public:
	COORD screenSize;
	Terminal(); //class constructor
	void PutPixel(char, short, short);
	void ClearBuffer(char = '#');
	void DrawFrame();


};