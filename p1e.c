#include<graphics.h>
#include<conio.h>

void main(){
	int gm,gd;
	clrscr();
	detectgraph(&gm,&gd);
	initgraph(&gm, &gd, "c:\\tc\\bgi");

	rectangle(250,180,450,250);
	line(320,180,320,250);
	line(320,180,285,110);
	line(250,180,285,110);
	line(450,180,415,110);
	line(415,110,285,110);

	getch();
	closegraph();
}