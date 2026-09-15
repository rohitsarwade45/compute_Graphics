#include <graphics.h>
#include <conio.h>

void bfill(int x, int y, int bc, int fc)
{
    if(getpixel(x,y) != bc && getpixel(x,y) != fc)
    {
        putpixel(x,y,fc);

        bfill(x+1,y,bc,fc);
        bfill(x-1,y,bc,fc);
        bfill(x,y+1,bc,fc);
        bfill(x,y-1,bc,fc);
    }
}

void main()
{
    int gm,gd;

    detectgraph(&gm,&gd);
    initgraph(&gm, &gd, "c:\\tc\\bgi");

    line(240,140,290,140);
    line(225,190,305,190);
    line(240,140,225,190);
    line(290,140,305,190);
    bfill(265,165,15,12);

    getch();
    closegraph();
}