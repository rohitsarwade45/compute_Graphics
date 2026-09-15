#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<dos.h>
void main(){
	float x ,y , x1,y1,x2,y2,dx,dy , length;
	int gd , gm ,i;
	clrscr();

	printf("Enter x1,y1,x2,y2");
	scanf("%f%f%f%f",&x1,&y1,&x2,&y2);

	detectgraph(&gm,&gd);
	initgraph(&gm, &gd, "c:\\tc\\bgi");
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);

	if(dx >= dy)
	       {	length = dx ;    }
	else
	      {	length = dy ; }

	dx= (x2 - x1)/ length;
	dy=(y2 - y1)/ length;

	 x = x1 + 0.5  ;
	 y = y1 + 0.5 ;

	 i =1 ;
	 while (i <= length){
		putpixel(x,y,17);
		x = x + dx ;
		y = y + dy ;
		i++ ;
		delay(50);
	 }

	getch();
	closegraph();
}