#include<graphics.h>
#include<conio.h>

void flood(int x, int y, int oldcolor,int newcolor){
 if(getpixel(x,y)==oldcolor){
	putpixel(x,y,newcolor);
	flood(x,y+1,oldcolor,newcolor);
	flood(x,y-1,oldcolor,newcolor);
	flood(x-1,y,oldcolor,newcolor);
	flood(x+1,y,oldcolor,newcolor);
 }
}
void main(){

	int gm,gd ,i;
	clrscr();
	detectgraph(&gm,&gd);
	initgraph(&gm, &gd, "c:\\tc\\bgi");
	
	line(200,100,220,100);
	line(200,150,220,150);
	line(180,125,200,100);
	line(180,125,200,150);
	line(240,125,220,100);
	line(240,125,220,150);
	flood(210,125,0,12);

	line(420,200,400,250);
	line(400,250,440,250);
	line(420,200,440,250);
	flood(420,225,0,12);

	
	getch();
	closegraph();
}