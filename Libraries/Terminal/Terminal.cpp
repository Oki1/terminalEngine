#include "Headers/Terminal.hpp"
Terminal::Terminal() {
    //handle to the console
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//change font to square font
	font.cbSize = sizeof(font);
	font.nFont = 0;
	font.dwFontSize.X = 10;
	font.dwFontSize.Y = 10;
	font.FontFamily = FF_DONTCARE;
	font.FontWeight = FW_NORMAL;
	wcscpy(font.FaceName, L"Terminal");
	SetCurrentConsoleFontEx(handle, TRUE, &font);

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(handle, &csbi);
	screenSize.X = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	screenSize.Y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	bufferSize = screenSize.Y*screenSize.X;
	buffer = new char[bufferSize+1];
	buffer[bufferSize] = 0x0;
}
void Terminal::PutPixel(char pixel, COORD position) {
    buffer[position.Y*(screenSize.X)+position.X] = pixel;
}
void Terminal::PutPixel(char pixel, short x, short y) {
	buffer[y*screenSize.X+x] = pixel;
}
void Terminal::ClearBuffer(char defaultValue) {
	for(int pos = 0; pos < bufferSize;pos++) {
		*(buffer+pos) = defaultValue;
	}
}
void Terminal::DrawFrame() {
	SetConsoleCursorPosition(handle, {0,0});
	std::cout << buffer << std::flush;
	SetConsoleCursorPosition(handle, {0,0});
}