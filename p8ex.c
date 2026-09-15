#include <stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
void main()
{
	int gd = DETECT,gm;
	float r;
	int x1,y1,x2,y2,x3,y3,rx1,rx2,rx3,ry1,ry2,ry3;
	x1=100;
	y1=130;
	x2=150;
	y2=150;
	x3=200;
	y3=200;


	r=((45)*3.14)/180;


	rx1=abs(x1*cos(r) - y1*sin(r));
	ry1=abs(x1*sin(r) + y1*cos(r));
	rx2=abs(x2*cos(r) - y2*sin(r));
	ry2=abs(x2*sin(r) + y2*cos(r));
	rx3=abs(x3*cos(r) - y3*sin(r));
	ry3=abs(x3*sin(r) + y3*cos(r));

	initgraph(&gd,&gd,"c:\\tc\\bgi");

	//Triangle
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x1,y1,x3,y3);

	//rotated tri


	line(rx1,ry1,rx2,ry2);
	line(rx2,ry2,rx3,ry3);
	line(rx1,ry1,rx3,ry3);

	getch();
	closegraph();
}