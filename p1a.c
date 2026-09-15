#include<graphics.h>
#include<conio.h>

void main(){

	int gm,gd;
	clrscr();
	detectgraph(&gm,&gd);
	initgraph(&gm, &gd, "c:\\tc\\bgi");
	ellipse(200,100,0,360,30,22);
	ellipse(200,160,0,360,20,35);
	line(180,150,160,170);
	line(220,150,240,170);
	circle(190,100,3);
	circle(210,100,3);

	getch();
}