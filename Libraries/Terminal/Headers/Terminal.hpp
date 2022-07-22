#pragma once

class Terminal {
private:
	//CONSOLE_FONT_INFOEX font;
	wchar_t* buffer;
	void* handle;
	int bufferSize;
public:
	int screenWidth;
	int screenHeight;
	Terminal(); //class constructor
	void PutPixel(char, short, short);
	void ClearBuffer(char = '#');
	void DrawFrame();
};