#include <graphics.h>
#include <conio.h>

void main()
{
    int gm,gd;
	clrscr();
	detectgraph(&gm,&gd);

    initgraph(&gm, &gd, "c:\\tc\\bgi");
    circle(420, 300, 55);

    //top
    line(405, 240, 420, 205);
    line(420, 205, 435, 240);
    line(405, 240, 435, 240);

    //TOP-RIGHT 
    line(480,270,495,235);
    line(495,235,460,249);
    line(460,249,480,270);

    //RIGHT 
    line(480, 285, 520, 300);
    line(520, 300, 480, 315);
    line(480, 285, 480, 315);

    //BOTTOM-RIGHT
    line(480,330,495,365);
    line(495,365,460,351);
    line(460,351,480,330);

    //BOTTOM
    line(405, 360, 420, 395);
    line(420, 395, 435, 360);
    line(405, 360, 435, 360);

    //BOTTOM-LEFT
    line(360,330, 345, 365);
    line(345, 365, 380, 351);
    line(380, 351, 360, 330);

    //LEFT
    line(360, 285, 320, 300);
    line(320, 300, 360, 315);
    line(360, 285, 360, 315);

    //TOP-LEFT
    line(360,270,345,235);
    line(345,235,380,249);
    line(380,249,360,270);

    getch();
    closegraph();
}