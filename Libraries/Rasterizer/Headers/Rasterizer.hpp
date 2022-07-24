#pragma once
#include <Terminal.hpp>
namespace rast {
	class vec2 {
    public:
		int x;
		int y;
		vec2 operator-(vec2 a);
		vec2 operator+(vec2 a);
		vec2(); //default constructor
		vec2(int a,int b);
	};
	class vec2f {
    public:
		float x;
		float y;
		vec2f operator-(vec2f a);
		vec2f operator+(vec2f a);
		vec2f(); //default constructor
		vec2f(float a,float b);
	};
	
    void DrawLine(Terminal&, vec2, vec2, char);
	void DrawTriangle(Terminal&, vec2, vec2, vec2,char, bool fill = true);
	void DrawTriangleScreenCoordinates(Terminal&, vec2f, vec2f, vec2f, char);
}