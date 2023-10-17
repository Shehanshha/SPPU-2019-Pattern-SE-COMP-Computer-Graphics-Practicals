#include <iostream>
#include <graphics.h>
#include <math.h>

void man()
{
    int i, j, x, y, getmaxx();
    for (i = 0; i < getmaxx()-140 ; i++)
    {
        delay(5);
        cleardevice();

        line(0, 450, getmaxx(), 450);
        rectangle(10 + i, 360, 50 + i, 420);
        line(15 + i, 420, 45 + i, 450);
        line(45 + i, 420, 15 + i, 450);
        circle(30 + i, 345, 15);
        line(30 + i, 370, 70 + i, 410);
        line(50 + i, 390, 70 + i, 370);
        line(70 + i, 370, 70 + i, 320);
        line(0 + i, 320, 140 + i, 320);
        arc(70 + i, 320, 180, 0, 70);
        j = 0;
        while (j != 5)
        {

            x = rand() % getmaxx();
            y = rand() % getmaxy();
            line(x, y, x + 10, y + 10);
            j = j + 1;
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    man();

    delay(10000);
    closegraph();
    return 0;
}