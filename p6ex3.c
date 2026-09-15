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
        bfill(x+1,y+1,bc,fc);
        bfill(x-1,y-1,bc,fc);
        bfill(x+1,y-1,bc,fc);
        bfill(x-1,y+1,bc,fc);
    }
}

void main()
{
    int gm,gd;

    detectgraph(&gm,&gd);
    initgraph(&gm, &gd, "c:\\tc\\bgi");

    line(265,120,295,145);
    line(295,145,285,185);
    line(285,185,245,185);
    line(245,185,235,145);
    line(235,145,265,120);

    line(265,121,295,146);
    line(296,145,286,185);
    line(285,186,245,186);
    line(244,185,234,145);
    line(235,144,265,119);

    bfill(265,155,15,17);

    getch();
    closegraph();
}