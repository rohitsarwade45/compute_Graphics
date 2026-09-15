#include <stdio.h> 
#include <conio.h> 
#include <graphics.h> 
#include <stdlib.h> 
 
#define MAX 50 
 
typedef struct 
{     int x;     int y; } Point; 
 
Point polygon[MAX]; 
int n; 
 
/* Check whether point is inside clipping window */ 
int inside(Point p, int edge) 
{ 
    if (edge == 0)          /* Left boundary */         return (p.x >= 220); 
 
    else if (edge == 1)     /* Right boundary */ 
        return (p.x <= 420); 
 
    else if (edge == 2)     /* Top boundary */ 
        return (p.y >= 140); 
 
    else                    /* Bottom boundary */         return (p.y <= 340); 
} 
 
 
/* Find intersection point */ 
Point intersection(Point s, Point p, int edge) 
{ 
    Point r; 
 
    if (edge == 0 || edge == 1) 
    { 
        /* Vertical boundary */ 
 
        if (edge == 0)             r.x = 220;         else 
            r.x = 420; 
 
        if (p.x != s.x) 
        { 
            r.y = s.y +                   (p.y - s.y) *                   (r.x - s.x) / 
                  (p.x - s.x); 
        }         else 
        { 
            r.y = s.y; 
        } 
    } 
    else 
    { 
        /* Horizontal boundary */ 
 
        if (edge == 2)             r.y = 140;         else 
            r.y = 340; 
 
        if (p.y != s.y) 
        { 
            r.x = s.x +                   (p.x - s.x) * 
                  (r.y - s.y) / 
                  (p.y - s.y); 
        }         else 
        { 
            r.x = s.x; 
        } 
    } 
 
    return r; 
} 
 
 
/* Sutherland-Hodgman Polygon Clipping */ void clipPolygon(int edge) 
{ 
    Point input[MAX];     Point s, p;     int count;     int i; 
 
    count = n; 
 
    /* Copy polygon */     for (i = 0; i < count; i++) 
    { 
        input[i] = polygon[i]; 
    } 
 
    n = 0; 
 
    /* Start from last vertex */ 
    s = input[count - 1]; 
 
    for (i = 0; i < count; i++) 
    { 
        p = input[i]; 
 
        /* Case 1: Current point is inside */ 
        if (inside(p, edge)) 
        { 
            /* Previous point is outside */ 
            if (!inside(s, edge)) 
            { 
                polygon[n] = intersection(s, p, edge); 
                n++; 
            } 
 
            polygon[n] = p;             n++; 
        } 
 
        /* Case 2: Current point is outside */ 
        else 
        { 
            /* Previous point is inside */ 
            if (inside(s, edge)) 
            { 
                polygon[n] = intersection(s, p, edge); 
                n++; 
            } 
        } 
         s = p; 
    } 
} 
 
 
/* Draw polygon */ 
void drawPolygon(Point p[], int count, int color) 
{     int i; 
 
    setcolor(color); 
 
    for (i = 0; i < count; i++) 
    {         line(p[i].x, 
             p[i].y,              p[(i + 1) % count].x,              p[(i + 1) % count].y);     } 
} 
 
 
/* Main function */ int main() 
{ 
    int gd = DETECT; 
    int gm; 
     int i; 
 
    /* Clipping window */ 
    int window[] = 
    { 
        220, 140, 
        420, 140, 
        420, 340, 
        220, 340, 
        220, 140 
    }; 
 
    /* Initialize graphics */ 
    initgraph(&gd, &gm, "C:\\TC\\BGI"); 
 
    printf("\n"); 
    printf("====================================\n");     printf("       POLYGON CLIPPING\n");     printf("   SUTHERLAND-HODGMAN ALGORITHM\n"); 
    printf("====================================\n\n"); 
 
 
    /* Number of vertices */ 
    printf("Enter the no. of vertices of polygon: ");     scanf("%d", &n); 
 
 
    /* Validate number of vertices */     if (n < 3 || n > MAX) 
    { 
        printf("\nInvalid number of vertices!");         printf("\nVertices must be between 3 and %d.", MAX); 
 
        getch();         closegraph();         return 0; 
    } 
 
 
    /* Enter vertices one by one */     printf("\nEnter coordinates of polygon:\n");     for (i = 0; i < n; i++) 
    { 
        printf("\nEnter coordinates of vertex %d\n", 
               i + 1); 
 
        printf("Enter x: "); 
        scanf("%d", &polygon[i].x); 
 
        printf("Enter y: "); 
        scanf("%d", &polygon[i].y); 
    } 
 
 
    /* Display original polygon */     cleardevice(); 
 
    /* Draw clipping window */     setcolor(RED); 
    drawpoly(5, window); 
 
    /* Draw original polygon */     setcolor(WHITE); 
    drawPolygon(polygon, n, WHITE); 
 
 
    printf("\n\nOriginal polygon is displayed.");     printf("\nPress any key to perform clipping..."); 
    getch(); 
 
 
    /* Clip against LEFT boundary */     clipPolygon(0); 
 
 
    /* Clip against RIGHT boundary */     if (n > 0) 
        clipPolygon(1); 
 
 
    /* Clip against TOP boundary */     if (n > 0) 
        clipPolygon(2); 
 
 
    /* Clip against BOTTOM boundary */ 
    if (n > 0)         clipPolygon(3); 
 
 
    /* Display clipped polygon */ 
    cleardevice(); 
 
    /* Draw clipping window */     setcolor(RED); 
    drawpoly(5, window); 
 
 
    /* Draw clipped polygon */ 
    if (n > 0) 
    { 
        setcolor(YELLOW); 
        drawPolygon(polygon, n, YELLOW); 
    } 
 
 
    printf("\n\nClipped polygon is displayed."); 
    printf("\nPress any key to exit..."); 
 
    getch(); 
 
    closegraph(); 
 
    return 0; 
} 
