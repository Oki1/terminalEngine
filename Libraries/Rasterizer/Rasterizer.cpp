#include "Headers/Rasterizer.hpp"
#include <cstdlib>
#include <algorithm>
#include <cmath>
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
rast::vec2::vec2(){
    x = 0;
    y = 0;
};

rast::vec2f rast::vec2f::operator-(vec2f a) {
	vec2f ret(x-a.x, y-a.y);
	return ret;
}
rast::vec2f rast::vec2f::operator+(vec2f a) {
	vec2f ret(x+a.x, y+a.y);
	return ret;
}
rast::vec2f::vec2f(float a, float b) {
	x = a;
	y = b;
}
rast::vec2f::vec2f(){
    x = 0;
    y = 0;
};

rast::vec2 screenSpaceToCoordinates(rast::vec2f a, int width, int height) {
    return(rast::vec2((int)round(a.x*(float)width), (int)round(a.x*(float)height)));
}

int min(int a, int b, int c) {
    int ret = a;
    if(b < ret) {
        ret = b;
    }
    if(c < ret) {
        ret = c;
    }
    return ret;
}
int max(int a, int b, int c) {
    int ret = a;
    if(b > ret) {
        ret = b;
    }
    if(c > ret) {
        ret = c;
    }
    return ret;
}

int crossProductSign(rast::vec2 q, rast::vec2 r, rast::vec2 s, rast::vec2 t) {
    int cross = (r.x - q.x) * (t.y - s.y) - (t.x - s.x) * (r.y - q.y);
    if(cross == 0) {
        return 0;
    }
    else if(cross > 0) {
        return 1;
    }
    return -1;
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
	} else {
        //"walk around" method
        
        vec2 maxP(max(a.x,b.x,c.x), a.y);
        vec2 minP(min(a.x, b.x, c.x), c.y);
        //std::cout << maxP.x << " " << maxP.y << " " << minP.x <<" " << minP.y << std::endl;
        vec2 p = minP;

        for(;p.y <= maxP.y; p.y++) {
            for(p.x = minP.x;p.x <= maxP.x; p.x++) {
                //t.PutPixel(chr, p.x, p.y);
                
                int cross1 = crossProductSign(c,b,c,p);
                int cross2 = crossProductSign(p,a,b,p);
                int cross3 = crossProductSign(a,c,a,p);
                if((cross1 == cross2 || cross1 == 0 || cross2 == 0) && (cross2 == cross3 || cross2 == 0 || cross3 == 0)) {
                    t.PutPixel(chr, p.x, p.y);
                }
            }
        }

    }
}

#include <iostream>
void rast::DrawTriangleScreenCoordinates(Terminal& t, vec2f a, vec2f b, vec2f c, char chr) {
    vec2 ar = screenSpaceToCoordinates(a, t.screenWidth, t.screenHeight);
    vec2 br = screenSpaceToCoordinates(b, t.screenWidth, t.screenHeight);
    vec2 cr = screenSpaceToCoordinates(c, t.screenWidth, t.screenHeight);
    /*std::cout << ar.x << "\t"<< ar.y << std::endl;
    std::cout << br.x << "\t"<<br.y << std::endl;
    std::cout << cr.x << "\t" << cr.y << std::endl;
    std::cout << "\n\n\n" << std::endl;*/
    

    DrawTriangle(t, ar, br, cr, chr);
}
