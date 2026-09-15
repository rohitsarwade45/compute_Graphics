#include<graphics.h>
#include<conio.h>

void main(){
	int gm,gd;
	clrscr();
	detectgraph(&gm,&gd);
	initgraph(&gm, &gd, "c:\\tc\\bgi");

	circle(320,200,60);
	circle(290,185,15);
	circle(350,185,15);
	rectangle(290,230,350,245);
	line(310,220,330,220);
	line(310,220,320,200);
	line(330,220,320,200);

	getch();
	closegraph();
}