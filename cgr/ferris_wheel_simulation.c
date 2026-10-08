#include <graphics.h>
#include <conio.h>
#include <dos.h>

void cabin(int x, int y)
{
	int points[18];
	points[0] = x - 30;
	points[1] = y + 35;
	points[2] = x - 13;
	points[3] = y + 35;
	points[4] = x - 13;
	points[5] = y + 48;
	points[6] = x + 13;
	points[7] = y + 48;
	points[8] = x + 13;
	points[9] = y + 35;
	points[10] = x + 30;
	points[11] = y + 35;
	points[12] = x + 18;
	points[13] = y + 63;
	points[14] = x - 18;
	points[15] = y + 63;
	points[16] = x - 30;
	points[17] = y + 35;

	setfillstyle(SOLID_FILL, LIGHTBLUE);
	fillpoly(9, points);
	line(x - 13, y + 35, x + 13, y + 35);

	line(x + 17, y + 6, x - 17, y + 6);
	line(x + 17, y + 6, x + 30, y + 31);
	line(x - 17, y + 6, x - 30, y + 31);
	line(x + 5, y + 6, x + 13, y + 31);
	line(x - 5, y + 6, x - 13, y + 31);

	circle(x, y, 2);
	circle(x, y, 5);
}

void person(int x, int y, int shirtColor)
{
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, YELLOW);
	fillellipse(x, y - 52, 10, 10);

	setcolor(shirtColor);
	line(x, y - 42, x, y - 20);
	line(x, y - 36, x - 13, y - 27);
	line(x, y - 36, x + 13, y - 27);

	setcolor(WHITE);
	line(x, y - 20, x - 9, y);
	line(x, y - 20, x + 9, y);
}

void wheelOperator()
{
	setcolor(WHITE);
	rectangle(490, 330, 610, 450);
	rectangle(500, 345, 600, 385);
	line(500, 390, 600, 390);
	outtextxy(505, 335, "OPERATOR");

	setfillstyle(SOLID_FILL, YELLOW);
	fillellipse(545, 405, 10, 10);

	setcolor(LIGHTGREEN);
	line(545, 415, 545, 438);
	line(545, 421, 532, 430);
	line(545, 421, 558, 430);

	setcolor(WHITE);
	line(545, 438, 536, 450);
	line(545, 438, 554, 450);

	setcolor(RED);
	rectangle(570, 405, 595, 430);
	circle(577, 412, 3);
	circle(588, 412, 3);
	line(575, 422, 590, 422);

    setcolor(WHITE);
}

void ferris(int fx[], int fy[], int n)
{
	int j, i;
	int p[] = {311, 215, 390, 450, 375, 450, 300, 220, 225, 450, 210, 450, 289, 215, 300, 220, 311, 215};
	while (1)
	{
		j = n - 1;
		i = 0;
		while (j >= 0 && i < n)
		{

			cleardevice();

			circle(300, 200, 142);
			circle(300, 200, 158);

			cabin(300 + fx[j], 200 + fy[j]);
			cabin(300 + fy[j], 200 - fx[j]);
			cabin(300 - fx[j], 200 - fy[j]);
			cabin(300 - fy[j], 200 + fx[j]);

			line(300 + fx[j], 200 + fy[j], 300, 200);
			line(300 + fy[j], 200 - fx[j], 300, 200);
			line(300 - fx[j], 200 - fy[j], 300, 200);
			line(300 - fy[j], 200 + fx[j], 300, 200);

			cabin(300 + fx[i], 200 - fy[i]);
			cabin(300 - fx[i], 200 + fy[i]);
			cabin(300 + fy[i], 200 + fx[i]);
			cabin(300 - fy[i], 200 - fx[i]);

			line(300, 200, 300 + fx[i], 200 - fy[i]);
			line(300, 200, 300 - fx[i], 200 + fy[i]);
			line(300, 200, 300 + fy[i], 200 + fx[i]);
			line(300, 200, 300 - fy[i], 200 - fx[i]);

			i++;
			j--;

			setfillstyle(SOLID_FILL, RED);
			fillpoly(9, p);

			setfillstyle(SOLID_FILL, YELLOW);
			fillellipse(300, 200, 20, 20);

			line(0, 450, 640, 450);

			person(80, 450, LIGHTGREEN);
			person(145, 450, LIGHTMAGENTA);
			person(625, 450, LIGHTCYAN);
			wheelOperator();

			delay(45);

			if (kbhit())
				break;
		}
		if (kbhit())
			break;
	}
}

void main()
{
	int gm, gd, fx[150], fy[150];
	int x, y, d, n = 0, r = 150;

	detectgraph(&gm, &gd);
	initgraph(&gm, &gd, "c:\\turboc3\\bgi");
	x = 0;
	y = r;
	d = 3 - 2 * r;
	do
	{
		fx[n] = x;
		fy[n] = y;
		n++;

		if (d <= 0)
			d = d + 4 * x + 6;

		else
		{
			d = d + 4 * (x - y) + 10;
			y--;
		}

		x++;
	} while (x < y);

	ferris(fx, fy, n);

	getch();
	closegraph();
}
