#include <cstdlib>
#include <algorithm>

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

void Terminal::plotLineHigh(glm::i8vec2 a, glm::i8vec2 b, char c) {
    glm::i8vec2 d = b - a;
    int  xi = 1;
    if (d.x < 0) {
        xi = -1;
        d.x = -d.x;
    }
    int D = (2 * d.x) - d.y;
    int x = a.x;

    for(int y = a.y; y < b.y; y++) {
        PutPixel(c, x, y);
        if (D > 0) {
            x = x + xi;
            D = D + (2 * (d.x - d.y));
        }
        else {
            D = D + 2*d.x;
        }
    }
}
void Terminal::plotLineLow(glm::i8vec2 a, glm::i8vec2 b, char c)
{
	glm::i8vec2 d = b-a;
    int yi = 1;
    if (d.y < 0) {
        yi = -1;
        d.y = -d.y;
    }
    int D = (2 * d.y) - d.x;
    int y = a.y;

    for(int x = a.x; x < b.x; x++) {
        PutPixel(c, x, y);
        if (D > 0) {
            y = y + yi;
            D = D + (2 * (d.y - d.x));
        }
        else {
            D = D + 2*d.y;
        }
    }
}

void Terminal::drawLine(glm::i8vec2 a, glm::i8vec2 b, char c) {
    if (abs(b.y - a.y) < abs(b.x - a.x)) {
        if (a.x > b.x) {
            plotLineLow(b, a, c);
        }
        else {
            plotLineLow(a, b, c);

        }
    }
    else{
        if (a.y > b.y) {
            plotLineHigh (b, a, c);

        } else {
            plotLineHigh (a, b, c);
        }

    }
}

void Terminal::drawTriangle(glm::i8vec2 a, glm::i8vec2 b, glm::i8vec2 c, char chr, bool fill) {
	if(a.y < b.y) {
		std::swap(a,b);
	}
	if(a.y < c.y) {
		std::swap(a,c);
	}
	if(b.y < c.y) {
		std::swap(b,c);
	}
	if(!fill) {
		drawLine(a, b, chr);
		drawLine(b, c, chr);
		drawLine(c, a, chr);
	}
}