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
//Rasterizer
#include <cstdlib>


void Terminal::plotLineHigh(int x0, int y0, int x1, int y1, char c) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int  xi = 1;
    if (dx < 0) {
        xi = -1;
        dx = -dx;
    }
    int D = (2 * dx) - dy;
    int x = x0;

    for(int y = y0; y < y1; y++) {
        PutPixel(c, x, y);
        if (D > 0) {
            x = x + xi;
            D = D + (2 * (dx - dy));
        }
        else {
            D = D + 2*dx;
        }
    }
}
void Terminal::plotLineLow(int x0, int y0, int x1, int y1, char c)
{
    int dx = x1 - x0;
    int dy = y1 - y0;
    int  yi = 1;
    if (dy < 0) {
        yi = -1;
        dy = -dy;
    }
    int D = (2 * dy) - dx;
    int y = y0;

    for(int x = x0; x < x1; x++) {
        PutPixel(c, x, y);
        if (D > 0) {
            y = y + yi;
            D = D + (2 * (dy - dx));
        }
        else {
            D = D + 2*dy;
        }
    }
}

void Terminal::drawLine(int x0, int y0, int x1, int y1, char c) {
    if (abs(y1 - y0) < abs(x1 - x0)) {
        if (x0 > x1) {
            plotLineLow(x1, y1, x0, y0, c);
        }
        else {
            plotLineLow(x0, y0, x1, y1, c);

        }
    }
    else{
        if (y0 > y1) {
            plotLineHigh (x1, y1, x0, y0, c);

        } else {
            plotLineHigh (x0, y0, x1, y1, c);
        }

    }
}