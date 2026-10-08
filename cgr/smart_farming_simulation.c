#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <stdio.h>

int sx[5] = {360, 424, 488, 552, 616};          /* sprinkler x      */
int rowY[6] = {224, 239, 254, 275, 289, 303};   /* plant row y      */

/* sun rays: x1,y1,x2,y2 */
int ray[16][4] = {
    {227, 53, 244, 53}, {225, 62, 235, 66}, {219, 70, 231, 81}, {210, 75, 215, 84},
    {200, 77, 200, 92}, {190, 75, 185, 84}, {181, 70, 169, 81}, {175, 62, 165, 66},
    {173, 53, 156, 53}, {175, 44, 165, 40}, {181, 36, 169, 25}, {190, 31, 185, 22},
    {200, 29, 200, 14}, {210, 31, 215, 22}, {219, 36, 231, 25}, {225, 44, 235, 40}};

int cx[5] = {120, 264, 516, 584, 12};   /* clouds */
int cy[5] = {31, 56, 24, 67, 91};
int cs[5] = {100, 130, 90, 70, 60};

int bx[4] = {274, 375, 562, 87};        /* birds */
int by[4] = {51, 103, 67, 84};

int tx[12] = {14, 46, 120, 89, 140, 304, 316, 289, 329, 16, 102, 297};   /* grass */
int ty[12] = {283, 302, 271, 311, 292, 231, 246, 278, 305, 231, 222, 217};

int fx[8] = {24, 62, 100, 134, 292, 313, 332, 302};   /* flowers */
int fy[8] = {297, 312, 292, 309, 294, 312, 288, 318};
int fc[8] = {LIGHTRED, WHITE, YELLOW, LIGHTRED, WHITE, YELLOW, LIGHTRED, WHITE};

/* ---------------- drawing helpers ---------------- */
void box(int x1, int y1, int x2, int y2, int c)
{
    setcolor(c);
    setfillstyle(SOLID_FILL, c);
    bar(x1, y1, x2, y2);
}

void blob(int x, int y, int rx, int ry, int c)
{
    setcolor(c);
    setfillstyle(SOLID_FILL, c);
    fillellipse(x, y, rx, ry);
}

void ln(int x1, int y1, int x2, int y2, int c)
{
    setcolor(c);
    line(x1, y1, x2, y2);
}

void poly(int n, int *p, int c)
{
    setcolor(c);
    setfillstyle(SOLID_FILL, c);
    fillpoly(n, p);
}

void cloud(int x, int y, int s, int c)
{
    blob(x, y, 30 * s / 100, 10 * s / 100, c);
    blob(x - 20 * s / 100, y + 3 * s / 100, 21 * s / 100, 8 * s / 100, c);
    blob(x + 22 * s / 100, y + 3 * s / 100, 22 * s / 100, 8 * s / 100, c);
    blob(x - 5 * s / 100, y - 7 * s / 100, 19 * s / 100, 10 * s / 100, c);
    blob(x + 10 * s / 100, y - 4 * s / 100, 16 * s / 100, 8 * s / 100, c);
}

/* static plants: odd columns tomato, even columns wheat */
void rows(int r1, int r2)
{
    int r, c, x, y;
    for (r = r1; r <= r2; r++)
        for (c = 0; c < 16; c++)
        {
            x = 356 + c * 17 + (r % 2) * 8;
            y = rowY[r];
            ln(x, y, x, y - 14, GREEN);
            ln(x, y - 5, x - 4, y - 8, LIGHTGREEN);
            ln(x, y - 5, x + 4, y - 8, LIGHTGREEN);
            ln(x, y - 10, x - 4, y - 13, LIGHTGREEN);
            ln(x, y - 10, x + 4, y - 13, LIGHTGREEN);
            if (c % 2)
            {
                blob(x - 3, y - 7, 2, 2, LIGHTRED);
                blob(x + 3, y - 5, 2, 2, LIGHTRED);
                blob(x, y - 14, 2, 2, LIGHTRED);
            }
            else
                blob(x, y - 17, 1, 3, YELLOW);
        }
}

/* ---------------- whole static scene (drawn once) ---------------- */
void drawStatic(void)
{
    int i;
    int m2[] = {120, 206, 208, 150, 272, 112, 352, 206};
    int snow[] = {272, 112, 243, 129, 256, 124, 265, 133, 275, 126, 286, 129};
    int m1[] = {0, 206, 0, 164, 40, 150, 88, 119, 152, 168, 208, 206};
    int lit1[] = {88, 119, 40, 150, 0, 164, 0, 183, 49, 166, 78, 140};
    int m3[] = {336, 206, 416, 161, 472, 140, 560, 105, 640, 140, 640, 206};
    int lit3[] = {560, 105, 472, 140, 416, 161, 376, 183, 464, 165, 528, 136};
    int path[] = {204, 214, 244, 214, 276, 350, 152, 350};
    int roof[] = {6, 176, 20, 158, 35, 148, 64, 148, 78, 158, 92, 176};

    cleardevice();

    /* sky, sun, clouds, birds */
    box(0, 0, 640, 206, LIGHTBLUE);
    for (i = 0; i < 16; i++)
        ln(ray[i][0], ray[i][1], ray[i][2], ray[i][3], YELLOW);
    blob(200, 53, 22, 19, YELLOW);
    blob(193, 48, 5, 4, WHITE);
    for (i = 0; i < 5; i++)
    {
        cloud(cx[i], cy[i] + 3, cs[i], LIGHTCYAN); /* shadow */
        cloud(cx[i], cy[i], cs[i], WHITE);
    }
    for (i = 0; i < 4; i++)
    {
        ln(bx[i] - 7, by[i] - 3, bx[i], by[i], DARKGRAY);
        ln(bx[i], by[i], bx[i] + 7, by[i] - 3, DARKGRAY);
    }

    /* mountains, sea, grass, path */
    poly(4, m2, CYAN);
    poly(6, snow, WHITE);
    poly(6, m1, GREEN);
    poly(6, lit1, LIGHTGREEN);
    poly(6, m3, GREEN);
    poly(6, lit3, LIGHTGREEN);
    box(0, 198, 640, 210, BLUE);
    box(0, 210, 640, 350, LIGHTGREEN);
    box(0, 210, 640, 214, GREEN);
    poly(4, path, YELLOW);

    /* barn */
    box(14, 175, 84, 208, RED);
    poly(6, roof, DARKGRAY);
    box(14, 175, 84, 177, WHITE);
    box(41, 158, 57, 170, WHITE);   /* hayloft window */
    box(44, 160, 55, 168, DARKGRAY);
    box(35, 184, 64, 208, WHITE);   /* door frame */
    box(37, 186, 48, 208, DARKGRAY);
    box(50, 186, 61, 208, DARKGRAY);
    ln(37, 186, 48, 208, WHITE);
    ln(48, 186, 37, 208, WHITE);
    ln(50, 186, 61, 208, WHITE);
    ln(61, 186, 50, 208, WHITE);
    box(14, 175, 17, 208, WHITE);   /* corner trim */
    box(81, 175, 84, 208, WHITE);

    /* wind turbine */
    setlinestyle(SOLID_LINE, 0, 3);
    ln(132, 87, 132, 183, WHITE);
    ln(132, 87, 139, 53, WHITE);
    ln(132, 87, 161, 109, WHITE);
    ln(132, 87, 96, 99, WHITE);
    setlinestyle(SOLID_LINE, 0, 1);
    blob(132, 87, 4, 3, LIGHTGRAY);

    /* grass tufts and flowers */
    for (i = 0; i < 12; i++)
    {
        ln(tx[i], ty[i], tx[i] - 2, ty[i] - 5, GREEN);
        ln(tx[i], ty[i], tx[i], ty[i] - 6, GREEN);
        ln(tx[i], ty[i], tx[i] + 2, ty[i] - 5, GREEN);
    }
    for (i = 0; i < 8; i++)
    {
        ln(fx[i], fy[i], fx[i], fy[i] - 6, GREEN);
        blob(fx[i], fy[i] - 7, 2, 2, fc[i]);
        if (fc[i] != YELLOW)
            blob(fx[i], fy[i] - 7, 1, 1, YELLOW);
    }

    /* cow */
    box(36, 246, 41, 260, WHITE);
    box(48, 247, 52, 261, WHITE);
    box(70, 246, 75, 260, WHITE);
    box(80, 247, 84, 261, WHITE);
    blob(62, 241, 28, 14, WHITE);
    blob(52, 238, 9, 6, BLACK);
    blob(73, 245, 8, 5, BLACK);
    ln(90, 236, 96, 249, BLACK);    /* tail */
    blob(96, 249, 1, 2, BLACK);
    blob(32, 241, 8, 6, WHITE);     /* head */
    blob(26, 245, 4, 2, LIGHTRED);
    blob(30, 235, 3, 2, BLACK);

    /* BROWN field */
    box(344, 211, 632, 312, BROWN);
    for (i = 0; i < 5; i++)
    {
        blob(sx[i], 245, 32, 8, DARKGRAY);
        blob(sx[i], 282, 32, 8, DARKGRAY);
    }
    for (i = 0; i < 6; i++)
        box(344, rowY[i] - 1, 632, rowY[i] + 2, DARKGRAY);
    setcolor(DARKGRAY);
    rectangle(344, 211, 632, 312);

    rows(0, 2);                     /* back rows */

    /* water tank */
    setlinestyle(SOLID_LINE, 0, 3);
    ln(298, 267, 298, 280, DARKGRAY);
    ln(318, 267, 318, 280, DARKGRAY);
    setlinestyle(SOLID_LINE, 0, 1);
    box(294, 234, 321, 267, BLUE);
    blob(308, 234, 13, 3, LIGHTBLUE);
    for (i = 241; i <= 262; i += 7)
        ln(294, i, 321, i, LIGHTBLUE);
    box(294, 260, 321, 267, LIGHTCYAN);

    /* pipe (static part) + sprinkler heads */
    box(320, 260, 632, 264, LIGHTGRAY);
    ln(320, 260, 632, 260, DARKGRAY);
    ln(320, 264, 632, 264, DARKGRAY);
    for (i = 0; i < 5; i++)
    {
        box(sx[i] - 1, 246, sx[i] + 1, 261, LIGHTGRAY);
        blob(sx[i], 245, 4, 2, DARKGRAY);
    }

    rows(3, 5);                     /* front rows */
}

/* ---------------- main ---------------- */
int main()
{
    int gd = DETECT, gm, i, j, t, x;
    long frame = 0;
    void *buf;
    unsigned size;
    int rx1 = 318, ry1 = 205, rx2 = 639, ry2 = 321;   /* animated region */

    initgraph(&gd, &gm, "C:\\TC\\BGI");
    drawStatic();

    /* save the animated region so we can restore it every frame */
    size = imagesize(rx1, ry1, rx2, ry2);
    buf = malloc(size);
    if (buf == NULL)
    {
        closegraph();
        printf("Not enough memory");
        getch();
        return 1;
    }
    getimage(rx1, ry1, rx2, ry2, buf);

    while (!kbhit())
    {
        putimage(rx1, ry1, buf, COPY_PUT);   /* erase old water/spray */

        /* flowing water in pipe */
        for (i = 0; i < 13; i++)
        {
            x = 322 + (int)((frame * 2 + i * 24) % 300);
            box(x, 261, x + 8, 263, LIGHTBLUE);
        }

        /* sprinkler spray */
        for (i = 0; i < 5; i++)
            for (j = 0; j < 9; j++)
            {
                t = (int)((frame * 2 + j * 5 + i * 7) % 16);
                blob(sx[i] + (j - 4) * t / 2, 244 - 5 * t + t * t / 3, 1, 1,
                     (j % 3 == 0) ? WHITE : LIGHTCYAN);
            }

        frame++;
        delay(40);
    }

    free(buf);
    getch();
    closegraph();
    return 0;
}
