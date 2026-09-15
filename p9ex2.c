#include <stdio.h>
#include<conio.h>
#include<graphics.h>

void main()
{
	int gd = DETECT,gm;
	float x1=0,y1=0,x2=50,y2=0,x3=0,y3=50,x4=50,y4=50;



	initgraph(&gd,&gd,"c:\\tc\\bgi");


	//square
	line(x1,y1,x2,y2);
	line(x2,y2,x4,y4);
	line(x4,y4,x3,y3);
	line(x3,y3,x1,y1);

	line(0,60,120,60);

	//ref
	line(x1,120-y1,x2,120-y2);
	line(x2,120-y2,x4,120-y4);
	line(x4,120-y4,x3,120-y3);
	line(x3,120-y3,x1,120-y1);



	getch();
}