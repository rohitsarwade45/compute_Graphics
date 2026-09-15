#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main()
{

    int x1, y1, x2, y2, x3, y3;
    int tx, ty;
    int a1, b1, a2, b2, a3, b3;
    int gd , gm;
    detectgraph(&gm,&gd);
    initgraph(&gm, &gd, "c:\\tc\\bgi");

    x1 = 2 * 5;
    y1 = 5 * 5;
    x2 = 7 * 5;
    y2 = 10 * 5;
    x3 = 10 * 5;
    y3 = 2 * 5;

    tx = 3 * 5;
    ty = 5 * 5;

    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    a1 = x1 + tx;
    b1 = y1 + ty;
    a2 = x2 + tx;
    b2 = y2 + ty;
    a3 = x3 + tx;
    b3 = y3 + ty;

    line(a1, b1, a2, b2);
    line(a2, b2, a3, b3);
    line(a3, b3, a1, b1);

    getch();
    closegraph();
}