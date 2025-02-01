#include <graphics.h>
#include <iostream>
int main()
{
int gd = DETECT, gm;
initgraph(&gd, &gm, (char*)"");
line(200, 100, 100, 200);
line(200, 100, 300, 200);
line(100, 200, 300, 200);
getch();
closegraph();
}