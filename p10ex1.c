#include<graphics.h>
#include<conio.h>

void main()
{
	int gd=DETECT,gm;
	int tx=50,ty=50,tz=50;

	initgraph(&gd,&gm,"c://tc//BGI");



	bar3d(50,50,100,100,10,1);
	bar3d(50+tx,50+ty,100+tx,100+ty,10+tz,1);
	//bar3d(100,100,150,150,60,1);

	getch();
	closegraph();
}