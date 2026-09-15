#include<graphics.h>
#include<conio.h>

void main(){
	int gm,gd;
	clrscr();
	detectgraph(&gm,&gd);
	initgraph(&gm, &gd, "c:\\tc\\bgi");
	rectangle(120,120,300,180);
	circle(160,200,20);
	circle(260,200,20);
	getch();
	closegraph();
}