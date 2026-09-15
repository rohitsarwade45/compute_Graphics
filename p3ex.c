#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<dos.h>
void main(){
	float x ,y , x1,y1,x2,y2,dx,dy , e;
	int gd, gm ,i;
	clrscr();
	printf("Enter x1,y1,x2,y2");
	scanf("%f%f%f%f",&x1,&y1,&x2,&y2);
	detectgraph(&gm,&gd);
	initgraph(&gm, &gd, "c:\\tc\\bgi");
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);

	x=x1;
	y=y1;

	e = 2* dy - x ;
	i=1;

	do{
		putpixel(x,y,RED);
		while(e >= 0){
		y=y+1;
		e=e -2 * dx;
		}
		x = x + 1;
		e = e + 2 * dy ;
		i++ ;
		delay(50);
	} while(i <= dx);

	getch();
	closegraph();
}