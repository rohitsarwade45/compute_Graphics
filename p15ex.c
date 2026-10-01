#include <graphics.h>
#include <conio.h>
#include <math.h>

int x[4] = {200, 100, 200, 250};
int y[4] = {200, 150, 75, 100};

void bezier()
{
    int i;
    double t, xt, yt;

    for(t = 0.0; t <= 1.0; t += 0.0005)
    {
        xt = pow(1-t, 3) * x[0]
           + 3 * pow(1-t, 2) * t * x[1]
           + 3 * (1-t) * pow(t, 2) * x[2]
           + pow(t, 3) * x[3];

        yt = pow(1-t, 3) * y[0]
           + 3 * pow(1-t, 2) * t * y[1]
           + 3 * (1-t) * pow(t, 2) * y[2]
           + pow(t, 3) * y[3];

        putpixel((int)xt, (int)yt, WHITE);
    }

    for(i = 0; i < 4; i++)
    {
        putpixel(x[i], y[i], YELLOW);
    }

    getch();
    closegraph();
}

void main()
{
    int gd, gm;

    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    bezier();
}
