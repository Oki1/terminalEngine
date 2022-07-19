#include <iostream>
#include <windows.h>

class Terminal {
private:
	COORD screenSize;
	CONSOLE_FONT_INFOEX font;
	char* buffer;
	HANDLE handle;
	int bufferSize;
public:
	Terminal(); //class constructor
	void PutPixel(char, COORD);
	void PutPixel(char, short, short);
	void ClearBuffer(char = '#');
	void DrawFrame();
};