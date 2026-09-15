#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main()
{
    int x1,y1,x2,y2,x3,y3;
    int sx,sy;
    int gd , gm;
    detectgraph(&gm,&gd);
    initgraph(&gm, &gd, "c:\\tc\\bgi");
    x1 = 100;
    y1 = 100;
    x2 = 120;
    y2 = 120;
    x3 = 80;
    y3 = 120;

    sx = 2;
    sy = 2;

    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x1,y1);

    line(x1*sx,y1*sy,x2*sx,y2*sy);
    line(x2*sx,y2*sy,x3*sx,y3*sy);
    line(x3*sx,y3*sy,x1*sx,y1*sy);



    getch();
    closegraph();
}