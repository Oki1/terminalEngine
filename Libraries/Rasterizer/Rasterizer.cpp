#include "Headers/Rasterizer.hpp"
#include <cstdlib>
rast::vec2 rast::vec2::operator-(vec2 a) {
	vec2 ret(x-a.x, y-a.y);
	return ret;
}
rast::vec2 rast::vec2::operator+(vec2 a) {
	vec2 ret(x+a.x, y+a.y);
	return ret;
}
rast::vec2::vec2(int a, int b) {
	x = a;
	y = b;
}
/*rast::vec2::vec2(){
    x = 0;
    y = 0;
};*/

int min(int a, int b) {
    if(a < b) {
        return a;
    }
    return b;
}
int max(int a, int b) {
    if(a > b) {
        return a;
    }
    return b;
}

int crossProduct(rast::vec2 q, rast::vec2 r, rast::vec2 s, rast::vec2 t) {
	return((r.x - q.x) * (t.y - s.y) - (t.x - s.x) * (r.y - q.y));
}

void plotLineHigh(Terminal& t, rast::vec2 a, rast::vec2 b, char c) {
    rast::vec2 d = b - a;
    int  xi = 1;
    if (d.x < 0) {
        xi = -1;
        d.x = -d.x;
    }
    int D = (2 * d.x) - d.y;
    int x = a.x;

    for(int y = a.y; y < b.y; y++) {
        t.PutPixel(c, x, y);
        if (D > 0) {
            x = x + xi;
            D = D + (2 * (d.x - d.y));
        }
        else {
            D = D + 2*d.x;
        }
    }
}
void plotLineLow(Terminal& t, rast::vec2 a, rast::vec2 b, char c)
{
	rast::vec2 d = b-a;
    int yi = 1;
    if (d.y < 0) {
        yi = -1;
        d.y = -d.y;
    }
    int D = (2 * d.y) - d.x;
    int y = a.y;

    for(int x = a.x; x < b.x; x++) {
        t.PutPixel(c, x, y);
        if (D > 0) {
            y = y + yi;
            D = D + (2 * (d.y - d.x));
        }
        else {
            D = D + 2*d.y;
        }
    }
}
void rast::DrawLine(Terminal& t, vec2 a, vec2 b, char c) {
    if (abs(b.y - a.y) < abs(b.x - a.x)) {
        if (a.x > b.x) {
            plotLineLow(t, b, a, c);
        }
        else {
            plotLineLow(t, a, b, c);

        }
    }
    else{
        if (a.y > b.y) {
            plotLineHigh (t, b, a, c);

        } else {
            plotLineHigh (t, a, b, c);
        }

    }
}
void rast::DrawTriangle(Terminal& t, vec2 a, vec2 b, vec2 c, char chr, bool fill) {
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
		DrawLine(t, a, b, chr);
		DrawLine(t, b, c, chr);
		DrawLine(t, c, a, chr);
	}
}