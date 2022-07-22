#include "Headers/Terminal.hpp"


#ifdef _WIN32

#include <iostream>
#include <windows.h>
//#include <cstdlib>
#include <unordered_map>

wchar_t toWideChar(char pixel) {
	const std::unordered_map<char, wchar_t> wideChars = {
		{' ', L'\xff00'},
		{'!', L'\xff01'},
		{'"', L'\xff02'},
		{'#', L'\xff03'},
		{'$', L'\xff04'},
		{'%', L'\xff05'},
		{'&', L'\xff06'},
		{'\'', L'\xff07'},
		{'(', L'\xff08'},
		{')', L'\xff09'},
		{'*', L'\xff0a'},
		{'+', L'\xff0b'},
		{',', L'\xff0c'},
		{'-', L'\xff0d'},
		{'.', L'\xff0e'},
		{'/', L'\xff0f'},
		{'0', L'\xff10'},
		{'1', L'\xff11'},
		{'2', L'\xff12'},
		{'3', L'\xff13'},
		{'4', L'\xff14'},
		{'5', L'\xff15'},
		{'6', L'\xff16'},
		{'7', L'\xff17'},
		{'8', L'\xff18'},
		{'9', L'\xff19'},
		{':', L'\xff1a'},
		{';', L'\xff1b'},
		{'<', L'\xff1c'},
		{'=', L'\xff1d'},
		{'>', L'\xff1e'},
		{'?', L'\xff1f'},
		{'@', L'\xff20'},
		{'A', L'\xff21'},
		{'B', L'\xff22'},
		{'C', L'\xff23'},
		{'D', L'\xff24'},
		{'E', L'\xff25'},
		{'F', L'\xff26'},
		{'G', L'\xff27'},
		{'H', L'\xff28'},
		{'I', L'\xff29'},
		{'J', L'\xff2a'},
		{'K', L'\xff2b'},
		{'L', L'\xff2c'},
		{'M', L'\xff2d'},
		{'N', L'\xff2e'},
		{'O', L'\xff2f'},
		{'P', L'\xff30'},
		{'Q', L'\xff31'},
		{'R', L'\xff32'},
		{'S', L'\xff33'},
		{'T', L'\xff34'},
		{'U', L'\xff35'},
		{'V', L'\xff36'},
		{'W', L'\xff37'},
		{'X', L'\xff38'},
		{'Y', L'\xff39'},
		{'Z', L'\xff3a'},
		{'[', L'\xff3b'},
		{'\\', L'\xff3c'},
		{']', L'\xff3d'},
		{'^', L'\xff3e'},
		{'_', L'\xff3f'},
		{'`', L'\xff40'},
		{'a', L'\xff41'},
		{'b', L'\xff42'},
		{'c', L'\xff43'},
		{'d', L'\xff44'},
		{'e', L'\xff45'},
		{'f', L'\xff46'},
		{'g', L'\xff47'},
		{'h', L'\xff48'},
		{'i', L'\xff49'},
		{'j', L'\xff4a'},
		{'k', L'\xff4b'},
		{'l', L'\xff4c'},
		{'m', L'\xff4d'},
		{'n', L'\xff4e'},
		{'o', L'\xff4f'},
		{'p', L'\xff50'},
		{'q', L'\xff51'},
		{'r', L'\xff52'},
		{'s', L'\xff53'},
		{'t', L'\xff54'},
		{'u', L'\xff55'},
		{'v', L'\xff56'},
		{'w', L'\xff57'},
		{'x', L'\xff58'},
		{'y', L'\xff59'},
		{'z', L'\xff5a'},
		{'{', L'\xff5b'},
		{'|', L'\xff5c'},
		{'}', L'\xff5d'},
		{'~', L'\xff5e'},
	};
	if(wideChars.find(pixel) == wideChars.end()) {
		std::cerr << "Character cannot be write '" << pixel <<"' in wide strings" << std::endl;
		pixel = '.';
	}
	return(wideChars.at(pixel));
}

Terminal::Terminal() 
{
	//handle to the console
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//change font to square font
	CONSOLE_FONT_INFOEX font;
	font.cbSize = sizeof(font);
	font.nFont = 0;	
	font.dwFontSize.X = 7;
	font.dwFontSize.Y = 16;
	font.FontFamily = FF_DONTCARE;
	font.FontWeight = FW_NORMAL;
	wcscpy_s(font.FaceName, L"NSimSun");
	SetCurrentConsoleFontEx(handle, TRUE, &font);

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(handle, &csbi);
	screenWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	screenHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	bufferSize = screenHeight*screenWidth;
	buffer = new wchar_t[bufferSize+1];
	buffer[bufferSize] = 0x0;
}

void Terminal::PutPixel(char pixel, short x, short y) {
	buffer[y*screenWidth+x] = toWideChar(pixel);
}
void Terminal::ClearBuffer(char defaultValue) {
	for(int pos = 0; pos < bufferSize;pos++) {
		*(buffer+pos) = toWideChar(defaultValue);
	}
}
void Terminal::DrawFrame() {
	SetConsoleCursorPosition(handle, {0,0});
	std::wcout << buffer << std::flush;
	SetConsoleCursorPosition(handle, {0,0});
}


#elif __linux__

#else

#endif

