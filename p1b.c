#include<graphics.h>
#include<conio.h>

void main(){
int gd,gm;
detectgraph(&gm,&gd);
initgraph(&gm, &gd, "c:\\tc\\bgi");

rectangle(120,150,280,180);
rectangle(170,110,230,140);
rectangle(180,120,220,130);
line(170,140,150,150);
line(230,140,250,150);

getch();
closegraph();
}