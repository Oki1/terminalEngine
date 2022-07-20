#include "Headers/Rasterizer.hpp"
#include <cstdlib>


void Rasterizer::plotLineHigh(Terminal& t, int x0, int y0, int x1, int y1, char c) {
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
        t.PutPixel(c, x, y);
        if (D > 0) {
            x = x + xi;
            D = D + (2 * (dx - dy));
        }
        else {
            D = D + 2*dx;
        }
    }
}
void Rasterizer::plotLineLow(Terminal& t, int x0, int y0, int x1, int y1, char c)
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
        t.PutPixel(c, x, y);
        if (D > 0) {
            y = y + yi;
            D = D + (2 * (dy - dx));
        }
        else {
            D = D + 2*dy;
        }
    }
}

void Rasterizer::drawLine(Terminal& t, int x0, int y0, int x1, int y1, char c) {
    if (abs(y1 - y0) < abs(x1 - x0)) {
        if (x0 > x1) {
            plotLineLow(t, x1, y1, x0, y0, c);
        }
        else {
            plotLineLow(t, x0, y0, x1, y1, c);

        }
    }
    else{
        if (y0 > y1) {
            plotLineHigh(t, x1, y1, x0, y0, c);

        } else {
            plotLineHigh(t, x0, y0, x1, y1, c);
        }

    }
}