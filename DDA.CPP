#include <iostream>
#include <graphics.h>
#include<math.h>
using namespace std;

void brecircle(int xc, int yc, int x, int y)
{
	putpixel(xc + x, yc + y, WHITE);
	putpixel(xc - x, yc + y, WHITE);
	putpixel(xc + x, yc - y, WHITE);
	putpixel(xc - x, yc - y, WHITE);
	putpixel(xc + y, yc + x, WHITE);
	putpixel(xc + y, yc - x, WHITE);
	putpixel(xc - y, yc + x, WHITE);
	putpixel(xc - y, yc - x, WHITE);

}
void drawline(int x_1, int y_1, int x_2, int y_2)
{
	float xin, yin, dx, dy, x, y, len;
	dx = x_2 - x_1;
	dy = y_2 - y_1;
	if (abs(dx) >= abs(dy))
		len = abs(dx);
	else
		len = abs(dy);

	xin = dx / len;
	yin = dy / len;
	x = x_1;
	y = y_1;
	for (int i = 0; i < len; i++)
	{
		putpixel(round(x), round(y), RED);
		x += xin;
		y += yin;

	}

}
int main()
{

	int xc, yc, r;
	cout << "enter the x and y coordinates:" << endl;
	cin >> xc >> yc;
	cout << "enter the radius:" << endl;
	cin >> r;
	int x = 0;
	int y = r;
	int x1 = 0;
	int y1 = r / 2;

	int D = 3 - (2 * r);
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	//int x_1 = 0;
	//int y_1 = D / 2;

	while (x < y)
	{
		brecircle(xc, yc, x, y);
		x += 1;
		if (D < 0)
			D = D + 4 * x + 6;
		else
		{
			y = y - 1;
			D = D + 4 * (x - y) + 10;
		}


	}
	drawline(xc, yc - r, xc + 0.86 * r, yc + 0.5 * r);
	drawline(xc + 0.86 * r, yc + 0.5 * r, xc - 0.86 * r, yc + 0.5 * r);
	drawline(xc - 0.86 * r, yc + 0.5 * r, xc, yc - r);
	while (x1 < y1)
	{
		brecircle(xc, yc, x1, y1);
		x1 += 1;
		if (D < 0)
			D = D + 4 * x1 + 6;
		else
		{
			y1 = y1 - 1;
			D = D + 4 * (x1 - y1) + 10;
		}
	}

	delay(500);
	getch();
	closegraph();
	return 0;
}