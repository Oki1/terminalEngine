#pragma once
#include <iostream>
#include <windows.h>
#include <glm/glm.hpp>
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
    void plotLineHigh(glm::i8vec2 a, glm::i8vec2 b, char c);
    void plotLineLow(glm::i8vec2 a, glm::i8vec2 b, char c);
	int crossProduct(glm::i8vec2 a, glm::i8vec2 b);
public:
    void drawLine(glm::i8vec2 a, glm::i8vec2 b, char chr);
	void drawTriangle(glm::i8vec2 a, glm::i8vec2 b, glm::i8vec2 c,char chr, bool fill = false);
};