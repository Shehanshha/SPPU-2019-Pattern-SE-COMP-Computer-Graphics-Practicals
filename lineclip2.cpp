#include<iostream>
#include<graphics.h>
#include<math.h>
#include<cstdlib>
using namespace std;

static int LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8, xmin, ymin, xmax, ymax;

int getcode(int x, int y)
{
	int code = 0;
	if (y > ymax) code |= TOP;
	if (y < ymin) code |= BOTTOM;
	if (x < xmin)code |= LEFT;
	if (x > xmax)code |= RIGHT;
	return code;
}

int main()
{
	
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	setcolor(WHITE);
	cout << "Enter top left and bottom left coordinates:" << endl;
	cin >> xmin >> ymin >> xmax >> ymax;
	int x1, y1, x2, y2;
	cout << "enter the starting and end points of the line:" << endl;
	cin >> x1 >> y1 >> x2 >> y2;
	outtext("Before clipping");
	rectangle(xmin, ymin, xmax, ymax);
	line(x1, y1, x2, y2);
	int outcode1 = getcode(x1, y1);
	int outcode2 = getcode(x2, y2);
	int accept = 0;//decides if line is to be draw
	while (1)
	{
		float m = (float)(y2 - y1) / (x2 - x1);
		//Both points inside accept line
		if (outcode1 == 0 && outcode2 == 0)
		{
			accept = 1;
			break;
		}
		//iff And of both codes i=0 then line is outside .Reject line
		else if ((outcode1 & outcode2) != 0)
		{
			break;
		}
		else
		{
			int x, y;
			int temp;
			//check whether points is inside ,if not,calculated intersection
			if (outcode1 == 0)
				temp = outcode2;
			else
				temp = outcode1;
			if (temp & TOP)
			{
				//line clips at top edge
				x = x1 + (ymax - y1) / m;
				y = ymax;
			}
			else if (temp & BOTTOM) {
				x = x1 + (ymin - y1) / m;
				y = ymin;
			}
			else if (temp & LEFT) {
				x = xmin;
				y = y1 + m * (xmin - x1);
			}
			else if (temp & RIGHT) {
				x = xmax;
				y = y1 + m * (xmax - x1);

			}
			if(temp == outcode1)
			{
				x1 = x;
				y1 = y;
				outcode1 = getcode(x1, y1);
			}
			else {
				x2 = x;
				y2 = y;
				outcode2 = getcode(x2, y2);
			}
		}
	}
	setcolor(BLUE);
	if (accept)
	{
		cleardevice();
		outtext("After clipping");
		rectangle(xmin, ymin, xmax, ymax);
		line(x1, y1, x2, y2);
	}
	else
	{
		cleardevice();
		outtext("After clipping");
		rectangle(x1, y1, x2, y2);
	}
	getch();
	closegraph();
	delay(1000);
	return 0;
}