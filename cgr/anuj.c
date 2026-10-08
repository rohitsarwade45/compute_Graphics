#include <graphics.h>
#include <conio.h>
#include <dos.h>

void fc(int c)
{
    setfillstyle(SOLID_FILL, c);
    setcolor(c);
}

void thick(int w) { setlinestyle(SOLID_LINE, 0, w); }

void box(int x1, int y1, int x2, int y2, int c)
{
    fc(c);
    bar(x1, y1, x2, y2);
}

void blob(int x, int y, int rx, int ry, int c)
{
    fc(c);
    fillellipse(x, y, rx, ry);
}

void poly4(int *p, int c)
{
    fc(c);
    fillpoly(4, p);
}

void drawGround(void)
{
    static int p[12] = {0, 400, 250, 400, 600, 330, 640, 326, 640, 479, 0, 479};

    fc(LIGHTRED);
    fillpoly(6, p);

    setcolor(BROWN);

    line(-260, 479, 0, 350);
    line(-200, 479, 60, 350);
    line(-140, 479, 120, 350);
    line(-80, 479, 180, 350);
    line(-20, 479, 240, 350);
    line(40, 479, 300, 350);
    line(100, 479, 360, 350);
    line(160, 479, 420, 350);
    line(220, 479, 480, 350);
    line(280, 479, 540, 350);

    line(0, 420, 639, 420);
    line(0, 445, 639, 445);
    line(0, 470, 639, 470);
}

void drawBackground(void)
{
    box(0, 0, 639, 479, LIGHTBLUE);
    box(600, 170, 639, 326, RED);
    box(615, 190, 639, 210, CYAN);
    box(615, 230, 639, 250, CYAN);
}

void drawWing(void)
{
    int i;

    static int wall[8] = {250, 60, 600, 165, 600, 330, 250, 400};

    static int bal[14][8] = {
        {255, 89, 295, 99, 295, 139, 255, 131},
        {305, 102, 345, 112, 345, 149, 305, 141},
        {355, 115, 395, 125, 395, 158, 355, 151},
        {405, 127, 445, 138, 445, 168, 405, 160},
        {455, 140, 495, 151, 495, 178, 455, 170},
        {505, 153, 545, 164, 545, 188, 505, 180},
        {555, 166, 595, 177, 595, 198, 555, 190},

        {255, 201, 295, 205, 295, 245, 255, 244},
        {305, 206, 345, 210, 345, 246, 305, 245},
        {355, 211, 395, 214, 395, 248, 355, 247},
        {405, 215, 445, 219, 445, 249, 405, 248},
        {455, 220, 495, 223, 495, 251, 455, 249},
        {505, 224, 545, 228, 545, 252, 505, 251},
        {555, 229, 595, 233, 595, 254, 555, 252}};

    static int win[7][8] = {
        {260, 314, 290, 312, 290, 365, 260, 370},
        {310, 310, 340, 308, 340, 357, 310, 362},
        {360, 306, 390, 304, 390, 349, 360, 354},
        {410, 303, 440, 300, 440, 341, 410, 346},
        {460, 299, 490, 297, 490, 333, 460, 338},
        {510, 295, 540, 293, 540, 325, 510, 330},
        {560, 291, 590, 289, 590, 317, 560, 322}};

    static int slab[4][8] = {
        {250, 60, 600, 165, 600, 171, 250, 74},
        {250, 173, 600, 220, 600, 226, 250, 187},
        {250, 286, 600, 275, 600, 281, 250, 300},
        {250, 385, 600, 323, 600, 330, 250, 400}};

    poly4(wall, YELLOW);

    fc(DARKGRAY);
    for (i = 0; i < 14; i++)
        fillpoly(4, bal[i]);
    for (i = 0; i < 7; i++)
        fillpoly(4, win[i]);

    setcolor(BLACK);
    line(250, 130, 600, 199);
    line(250, 244, 600, 254);

    setcolor(LIGHTGRAY);
    line(275, 313, 275, 367);
    line(325, 309, 325, 359);
    line(375, 305, 375, 351);
    line(425, 301, 425, 343);
    line(475, 298, 475, 336);
    line(525, 294, 525, 328);
    line(575, 290, 575, 320);

    for (i = 0; i < 4; i++)
        poly4(slab[i], BROWN);

    setcolor(BROWN);
    thick(THICK_WIDTH);
    line(250, 60, 250, 400);
    line(300, 75, 300, 390);
    line(350, 90, 350, 380);
    line(400, 105, 400, 370);
    line(450, 120, 450, 360);
    line(500, 135, 500, 350);
    line(550, 150, 550, 340);
    line(600, 165, 600, 330);
    thick(NORM_WIDTH);
}

void drawFront(void)
{
    box(0, 0, 15, 300, YELLOW);
    box(15, 0, 50, 300, BROWN);
    box(50, 22, 250, 400, YELLOW);
    box(50, 12, 262, 22, RED);

    box(62, 32, 250, 105, DARKGRAY);
    box(100, 32, 108, 105, BROWN);
    box(167, 32, 175, 105, BROWN);
    box(234, 32, 242, 105, BROWN);
    box(50, 105, 262, 130, YELLOW);
    box(50, 126, 262, 132, BROWN);

    box(62, 165, 150, 235, DARKGRAY);
    setcolor(LIGHTGRAY);
    line(84, 165, 84, 235);
    line(106, 165, 106, 235);
    line(128, 165, 128, 235);
    line(62, 200, 150, 200);

    box(155, 195, 245, 225, BLUE);
    setcolor(WHITE);
    outtextxy(160, 198, "COMPUTER");
    outtextxy(160, 210, "ENGINEERING");

    box(50, 246, 262, 262, YELLOW);
    box(50, 258, 262, 264, BROWN);

    box(90, 270, 240, 400, DARKGRAY);
    box(90, 270, 100, 400, BROWN);
    box(200, 270, 212, 400, BROWN);
    box(240, 270, 252, 400, BROWN);
    box(108, 310, 142, 360, LIGHTGRAY);
    box(113, 315, 137, 355, BROWN);
    box(150, 310, 182, 392, RED);
    setcolor(BLACK);
    rectangle(150, 310, 182, 392);
    line(166, 310, 166, 392);
}

void step(int y, int x2)
{
    box(0, y, x2, y + 18, LIGHTGRAY);
    setcolor(DARKGRAY);
    rectangle(0, y, x2, y + 18);
}

void drawStairs(void)
{
    thick(THICK_WIDTH);
    setcolor(BROWN);
    line(28, 290, 98, 479);
    thick(NORM_WIDTH);

    step(290, 28);
    step(309, 35);
    step(328, 42);
    step(347, 49);
    step(366, 56);
    step(385, 63);
    step(404, 70);
    step(423, 77);
    step(442, 84);
    step(461, 91);
}

void drawTrees(void)
{

    box(466, 215, 474, 380, BROWN);
    blob(470, 215, 48, 38, GREEN);
    blob(446, 231, 32, 24, GREEN);
    blob(494, 227, 32, 24, GREEN);
    blob(458, 199, 16, 12, LIGHTGREEN);
    blob(486, 206, 12, 9, LIGHTGREEN);

    box(586, 112, 594, 335, BROWN);
    blob(590, 112, 42, 33, GREEN);
    blob(569, 126, 28, 21, GREEN);
    blob(611, 122, 28, 21, GREEN);
    blob(580, 98, 14, 10, LIGHTGREEN);
    blob(604, 104, 10, 8, LIGHTGREEN);
}

void bush(int x, int y)
{
    box(x - 5, y, x + 5, y + 8, BROWN);
    blob(x, y - 5, 9, 8, GREEN);
    blob(x - 3, y - 8, 4, 3, LIGHTGREEN);
}

void frond(int mx, int my, int ex, int ey)
{
    int i, px, py;

    setcolor(GREEN);
    thick(THICK_WIDTH);
    line(575, 360, mx, my);
    line(mx, my, ex, ey);
    thick(NORM_WIDTH);

    setcolor(LIGHTGREEN);
    for (i = 1; i <= 5; i++)
    {
        px = mx + (ex - mx) * i / 6;
        py = my + (ey - my) * i / 6;
        line(px, py, px - 5, py + 12);
        line(px, py, px + 5, py + 12);
        px = 575 + (mx - 575) * i / 6;
        py = 360 + (my - 360) * i / 6;
        line(px, py, px - 5, py + 10);
        line(px, py, px + 5, py + 10);
    }
}

void drawPalm(void)
{
    setcolor(BROWN);
    thick(THICK_WIDTH);
    line(585, 470, 575, 360);
    thick(NORM_WIDTH);

    frond(540, 328, 505, 332);
    frond(553, 311, 530, 297);
    frond(573, 306, 570, 287);
    frond(595, 313, 615, 302);
    frond(607, 333, 640, 342);
    frond(538, 346, 500, 367);
    frond(605, 353, 635, 382);
}

void cloud(int x, int y)
{
    blob(x, y, 14, 8, WHITE);
    blob(x + 14, y - 4, 12, 9, WHITE);
    blob(x + 28, y, 14, 8, WHITE);
}

void bird(int x, int y, int f)
{
    int d = f ? -4 : 3;
    setcolor(BLACK);
    line(x - 7, y + d, x, y);
    line(x, y, x + 7, y + d);
}

void animateSky(int t)
{
    int b1 = 273 + (t * 3) % 330;
    int c1 = 280 + (t * 2) % 317;
    int c2 = 280 + (t * 2 + 160) % 317;

    box(266, 0, 639, 60, LIGHTBLUE);

    blob(300, 30, 12, 12, YELLOW);
    setcolor(YELLOW);
    line(300, 8, 300, 14);
    line(300, 46, 300, 52);
    line(278, 30, 284, 30);
    line(316, 30, 322, 30);
    line(284, 14, 288, 18);
    line(312, 42, 316, 46);
    line(284, 46, 288, 42);
    line(312, 18, 316, 14);

    cloud(c1, 22);
    cloud(c2, 42);
    bird(b1, 12, (t / 2) % 2);
    bird(b1 + 30, 20, (t / 2 + 1) % 2);
}

int main()
{
    int gd = DETECT, gm, t = 0;

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    drawBackground();
    drawGround();
    drawWing();
    drawFront();
    drawTrees();
    bush(290, 394);
    bush(350, 382);
    bush(410, 370);
    bush(530, 346);
    drawPalm();
    drawStairs();

    setcolor(BLACK);
    outtextxy(230, 466, "Press any key to exit");

    animateSky(0);
    while (!kbhit())
    {
        delay(70);
        animateSky(t++);
    }

    closegraph();
    return 0;
}
