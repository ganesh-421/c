#include<graphics.h>
#include<dos.h>
#include<stdio.h>
void main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    line(150, 150, 200, 150);
    getch();
    closegraph();
}
