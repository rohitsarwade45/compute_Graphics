#include<graphics.h>
#include<conio.h>

void main()
{
	int poly[] = {320,150,370,200,350,250,290,250,270,200,320,150};
	int gd = DETECT , gm ;
	initgraph(&gd , &gm , "c:\\turboc3\\bgi");
	putpixel(100,100,WHITE);
	line(150,150,250,250);
	circle(300,300,50);
	ellipse(400,400,0,360,50,25);
	rectangle(450,150,600,300);

	line(200,200,250,100);
	line(250,100,300,200);
	line(300,200,200,200);

	drawpoly(6,poly);
	getch();
	closegraph();

}