#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

void move(int j, int h, int& x, int& y)
{
	if (j == 11)
		y = y - h;
	else if (j == 22)
		x = x + h;
	else if (j == 33)
		y = y + h;
	else if (j == 44)
		x = x - h;
	lineto(x, y);
}
void hilbert(int d, int r, int u, int l, int i, int h, int &x, int &y)
{
	if (i > 0)
	{
		i--;
		hilbert(r, d, l, u i, h, x, y);
		move(d, h, x, y);
		hilbert(d, r, u, l, i, h, x, y);
		move(r, h, x, y);
		hilbert(d, r, u, l, i, h, x, y);
		move(u, h, x, y);
		hilbert(l, u, r, d, i, h, x, y);
	}
}
int main()
{
	int n;
	int x = 50, y = 150, h = 50, u = 11, r = 22, d = 33, l = 44;
	cout << "Entr the value of n:" << endl;
	cin >> n;
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	moveto(x, y);
	hilbert(d, r, u, l, n, h, x, y);
	getch();
	closegraph();
	delay(1000);
	return 0;
}