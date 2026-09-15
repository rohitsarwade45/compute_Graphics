#include<graphics.h>
#include<conio.h>

void flood(int x, int y, int oldcolor,int newcolor){
 if(getpixel(x,y)==oldcolor){
	putpixel(x,y,newcolor);
	flood(x,y+1,oldcolor,newcolor);
	flood(x,y-1,oldcolor,newcolor);
	flood(x-1,y,oldcolor,newcolor);
	flood(x+1,y,oldcolor,newcolor);
	flood(x-1,y-1,oldcolor,newcolor);
	flood(x-1,y+1,oldcolor,newcolor);
	flood(x+1,y-1,oldcolor,newcolor);
	flood(x+1,y+1,oldcolor,newcolor);
 }
}
void main(){

	int gm,gd;
	clrscr();
	detectgraph(&gm,&gd);
	initgraph(&gm, &gd, "c:\\tc\\bgi");

	line(200,100,200,150);
	line(280,100,280,150);

	line(200,100,240,91);
	line(240,91,280,100);

	line(200,101,240,92);
	line(240,92,280,101);

	line(200,150,240,159);
	line(240,159,280,150);

	line(200,151,240,160);
	line(240,160,280,151);
	
	flood(240,125,0,13);

	getch();
	closegraph();
}