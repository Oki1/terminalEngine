#include <Headers/Terminal.hpp>
int main() {	
	Terminal c;
	c.ClearBuffer();
	c.DrawFrame();
	getc(stdin);
	//c.DrawFrame();
    return 0;
}