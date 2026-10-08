#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>

/* =====================================================
                    WATER DROP
   ===================================================== */

void drawWaterDrop(int y)
{
    setcolor(BLUE);
    setfillstyle(SOLID_FILL, BLUE);

    fillellipse(300, y, 5, 8);
}

/* =====================================================
                    TRACTOR
   ===================================================== */

void drawTractor(int x)
{
    /* Back Wheel */
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    fillellipse(x, 330, 18, 18);

    /* Front Wheel */
    fillellipse(x + 55, 330, 12, 12);

    /* Wheel Rim */
    setcolor(WHITE);
    circle(x, 330, 6);
    circle(x + 55, 330, 4);

    /* Tractor Body */
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    bar(x - 15, 285, x + 50, 315);

    /* Bonnet */
    bar(x + 50, 295, x + 70, 315);

    /* Driver Cabin */
    setcolor(BLACK);

    rectangle(x + 5, 255, x + 35, 285);

    line(x + 20, 255, x + 20, 285);

    /* Roof */
    line(x, 255, x + 40, 255);

    /* Exhaust Pipe */
    line(x + 45, 285, x + 45, 245);
}

/* =====================================================
                    STATIC BACKGROUND
                    DRAW ONLY ONCE
   ===================================================== */

void drawBackground()
{
    int x, f;

    setbkcolor(CYAN);
    cleardevice();

    /* SKY */

    setfillstyle(SOLID_FILL, CYAN);
    bar(0, 0, 640, 280);

    /* GRASS */

    setfillstyle(SOLID_FILL, GREEN);
    bar(0, 280, 640, 350);

    /* SOIL */

    setfillstyle(SOLID_FILL, BROWN);
    bar(0, 350, 640, 480);

    /* BORDER */

    setcolor(BLUE);

    rectangle(5, 5, 635, 475);
    rectangle(10, 10, 630, 470);

    /* TITLE */

    setcolor(BLUE);

    settextstyle(3, 0, 5);

    outtextxy(175, 25, "SMART FARMING");

    /* SUN */

    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);

    fillellipse(560, 70, 30, 30);

    line(560, 20, 560, 0);
    line(560, 120, 560, 140);

    line(510, 70, 480, 70);
    line(610, 70, 635, 70);

    line(535, 45, 515, 25);
    line(585, 45, 605, 25);

    line(535, 95, 515, 115);
    line(585, 95, 605, 115);

    line(540, 35, 525, 10);
    line(580, 35, 595, 10);

    line(540, 105, 525, 130);
    line(580, 105, 595, 130);

    /* CLOUD 1 */

    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);

    fillellipse(60, 70, 20, 20);
    fillellipse(85, 60, 25, 25);
    fillellipse(110, 70, 20, 20);

    /* CLOUD 2 */

    fillellipse(300, 80, 20, 20);
    fillellipse(325, 65, 25, 25);
    fillellipse(350, 80, 20, 20);

    /* CLOUD 3 */

    fillellipse(450, 95, 18, 18);
    fillellipse(470, 82, 22, 22);
    fillellipse(495, 95, 18, 18);

    /* WATER TANK */

    setcolor(BLACK);

    rectangle(60, 120, 150, 250);

    setfillstyle(SOLID_FILL, LIGHTGRAY);

    floodfill(61, 121, BLACK);

    setcolor(BLUE);

    settextstyle(3, 0, 3);

    outtextxy(76, 160, "WATER");
    outtextxy(80, 200, "TANK");

    /* TANK STAND */

    setcolor(BROWN);

    line(75, 250, 75, 350);
    line(135, 250, 135, 350);

    line(75, 250, 135, 350);
    line(135, 250, 75, 350);

    /* PIPE */

    setcolor(DARKGRAY);

    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);

    line(150, 180, 300, 180);

    line(300, 180, 300, 230);

    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);

    /* PLANTS */

    setcolor(GREEN);

    for (x = 180; x <= 500; x += 40)
    {
        line(x, 350, x, 300);

        arc(x - 8, 315, 270, 90, 8);
        arc(x + 8, 315, 90, 270, 8);

        arc(x - 8, 330, 270, 90, 8);
        arc(x + 8, 330, 90, 270, 8);

        setcolor(RED);
        setfillstyle(SOLID_FILL, RED);

        fillellipse(x, 295, 4, 8);

        setcolor(GREEN);
    }

    /* FLOWERS */

    for (f = 45; f <= 590; f += 65)
    {
        setcolor(GREEN);

        line(f, 430, f, 400);

        line(f, 415, f - 6, 410);
        line(f, 415, f + 6, 410);

        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);

        fillellipse(f, 395, 3, 3);

        setcolor(RED);
        setfillstyle(SOLID_FILL, RED);

        fillellipse(f - 6, 395, 3, 3);
        fillellipse(f + 6, 395, 3, 3);
        fillellipse(f, 389, 3, 3);
        fillellipse(f, 401, 3, 3);
    }

    /* GRASS DETAILS */

    setcolor(GREEN);

    for (x = 10; x <= 630; x += 28)
    {
        line(x, 350, x + 4, 338);
        line(x + 4, 338, x + 8, 350);
        line(x + 4, 338, x + 4, 350);

        line(x, 430, x + 5, 415);
        line(x + 5, 415, x + 10, 430);
    }

    /* LEFT TREE */

    setcolor(BROWN);
    setfillstyle(SOLID_FILL, BROWN);

    bar(5, 220, 30, 350);

    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);

    fillellipse(18, 180, 28, 28);
    fillellipse(0, 205, 22, 22);
    fillellipse(35, 205, 22, 22);
    fillellipse(18, 220, 24, 20);

    /* RIGHT TREE */

    setcolor(BROWN);
    setfillstyle(SOLID_FILL, BROWN);

    bar(595, 220, 620, 350);

    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);

    fillellipse(608, 180, 28, 28);
    fillellipse(590, 205, 22, 22);
    fillellipse(625, 205, 22, 22);
    fillellipse(608, 220, 24, 20);

    /* BIRDS */

    setcolor(BLACK);

    arc(220, 80, 0, 180, 10);
    arc(240, 80, 0, 180, 10);

    arc(380, 65, 0, 180, 10);
    arc(400, 65, 0, 180, 10);

    arc(450, 105, 0, 180, 10);
    arc(470, 105, 0, 180, 10);

    /* BUTTERFLY */

    setcolor(MAGENTA);
    setfillstyle(SOLID_FILL, MAGENTA);

    fillellipse(430, 180, 8, 10);
    fillellipse(445, 180, 8, 10);

    setcolor(BLACK);

    line(438, 170, 438, 192);

    line(438, 170, 434, 165);
    line(438, 170, 442, 165);

    /* EXTRA FLOWERS */

    for (f = 220; f <= 560; f += 60)
    {
        setcolor(RED);
        setfillstyle(SOLID_FILL, RED);

        fillellipse(f, 345, 3, 3);

        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);

        fillellipse(f - 4, 341, 2, 2);
        fillellipse(f + 4, 341, 2, 2);
        fillellipse(f, 337, 2, 2);
        fillellipse(f, 349, 2, 2);
    }

    /* BOTTOM TEXT */

    setcolor(WHITE);

    settextstyle(0, 0, 1);

    outtextxy(140, 455,
              "SMART IRRIGATION SYSTEM USING COMPUTER GRAPHICS");
}

/* =====================================================
                        MAIN
   ===================================================== */

int main()
{
    int gd = DETECT, gm;

    int waterY;
    int tractorX;
    int direction;

    unsigned waterSize;

    void *waterImage;

    /* =================================================
                    INITIALIZE GRAPHICS
       ================================================= */

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    /* =================================================
                    DRAW BACKGROUND
       ================================================= */

    drawBackground();

    /* =================================================
                    INITIAL POSITION
       ================================================= */

    waterY = 230;

    tractorX = 430;

    direction = 1;

    /* =================================================
                    WATER MEMORY
       ================================================= */

    waterSize = imagesize(292, 222, 308, 350);

    waterImage = malloc(waterSize);

    if (waterImage == NULL)
    {
        closegraph();
        getch();
        return 0;
    }

    /* =================================================
                SAVE WATER BACKGROUND
       ================================================= */

    getimage(292, 222, 308, 350, waterImage);

    /* =================================================
                    FIRST DRAW
       ================================================= */

    drawWaterDrop(waterY);

    drawTractor(tractorX);

    /* =================================================
                    ANIMATION LOOP
       ================================================= */

    while (!kbhit())
    {

        /* =================================================
                    REMOVE OLD WATER DROP
           ================================================= */

        putimage(292, 222, waterImage, COPY_PUT);

        /* =================================================
                    REMOVE OLD TRACTOR
                    USING XOR
           ================================================= */

        setwritemode(XOR_PUT);

        drawTractor(tractorX);

        /* =================================================
                    WATER MOVEMENT
           ================================================= */

        waterY = waterY + 7;

        if (waterY >= 345)
        {
            waterY = 230;
        }

        /* =================================================
                    TRACTOR MOVEMENT
           ================================================= */

        tractorX = tractorX + (direction * 3);

        /* Move right */

        if (tractorX >= 535)
        {
            direction = -1;
        }

        /* Move left */

        if (tractorX <= 420)
        {
            direction = 1;
        }

        /* =================================================
                    DRAW NEW TRACTOR
                    USING XOR
           ================================================= */

        drawTractor(tractorX);

        /* वापस normal drawing mode */

        setwritemode(COPY_PUT);

        /* =================================================
                    DRAW NEW WATER DROP
           ================================================= */

        drawWaterDrop(waterY);

        /* =================================================
                    ANIMATION SPEED
           ================================================= */

        delay(80);
    }

    /* =================================================
                        EXIT
       ================================================= */

    free(waterImage);

    getch();

    closegraph();

    return 0;
}