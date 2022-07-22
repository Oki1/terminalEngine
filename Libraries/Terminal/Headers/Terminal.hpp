#pragma once
#ifdef _WIN32
class Terminal {
private:
	char* buffer;
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
#elif __linux__
class Terminal {
private:
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
#else
#endif