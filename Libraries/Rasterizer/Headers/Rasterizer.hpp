#pragma once
#include <Terminal.hpp>
//implementation of bresham's line algorithm
class Rasterizer {
private:
    static void plotLineHigh(Terminal& t, int x0, int y0, int x1, int y1, char c);
    static void plotLineLow(Terminal& t, int x0, int y0, int x1, int y1, char c);
public:
    static void drawLine(Terminal& t, int x0, int y0, int x1, int y1, char c);
};