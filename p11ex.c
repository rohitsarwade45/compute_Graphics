#include<graphics.h>
#include<conio.h>
#include<math.h>

void main()
{
	int gd,gm;
	float l=50,t=50,r=100,b=100,d=10,q;
	float a=45;
	float nl,nt,nr,nb;
	q=(a * 3.14159)/180;
	detectgraph(&gd,&gm);

	initgraph(&gd,&gm,"c://tc//BGI");

	bar3d(l,t,r,b,d,1);

	//around z-axis----


	nl= abs( l*cos(q) - t*sin(q) );
	nt= abs( l*sin(q) + t*cos(q) );
	nr= abs( r*cos(q) - b*sin(q) );
	nb= abs( r*sin(q) + b*cos(q) );

	bar3d(nl,nt,nr,nb,d,1);

	/*around x-axis----



	t= abs( t*cos(q) - d*sin(q) );
	d= abs( t*sin(q) + d*cos(q) );
	b= abs( b*cos(q) - d*sin(q) );

	bar3d(l,t,r,b,d,1);

	  */
	getch();
	closegraph();
}