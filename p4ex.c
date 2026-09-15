#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<dos.h>
void main(){
	float d;
	int gd,gm,x,y,r;
	clrscr();

	printf("Enter radius of circle:\n");
	scanf("%d",&r);

	detectgraph(&gm,&gd);
	initgraph(&gm, &gd, "c:\\tc\\bgi");
	x = 0;
	y = r;
	d=3-2*r;

	do
	{
	  putpixel(200+x,200+y,RED);
	  putpixel(200+x,200-y,GREEN);
	  putpixel(200-x,200+y,BLUE);
	  putpixel(200-x,200-y,15);
	  putpixel(200-y,200-x,YELLOW);
	  putpixel(200+y,200+x,RED);
	  putpixel(200-y,200+x,BLUE);
	  putpixel(200+y,200-x,GREEN);

	  if(d<=0)
	  {
	    d=d+4*x+6;
	  }
	  else
	  {
	    d=d+4*(x-y)+10;
	    y=y-1;
	  }
	  x=x+1;
	  delay(100);
	}while(x<y);

	getch();
	closegraph();
}