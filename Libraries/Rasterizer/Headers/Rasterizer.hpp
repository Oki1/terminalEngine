#pragma once
#include <Terminal.hpp>
namespace rast {
	class vec2 {
    public:
		int x;
		int y;
		vec2 operator-(vec2 a);
		vec2 operator+(vec2 a);
		vec2() {

        }; //default constructor
		vec2(int a,int b);
	};


    void DrawLine(Terminal&, vec2, vec2, char chr);
	void DrawTriangle(Terminal&, vec2, vec2, vec2,char chr, bool fill = false);
}