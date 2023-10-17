#include <iostream>
#include <math.h>
#include <graphics.h>
using namespace std;
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    //initwindow(900, 700);
    int n;

    cout << "Enter your choice:" << endl;
    cout << "\n1.Triangle\n2.Rhombus" << endl;
    cin >> n;

    switch(n)
    {
    case 1:
    {
        int ch, choice;
        int A[3][3];
        cout << "Enter coordinates of x1,y1:";
        cin >> A[0][0] >> A[0][1];
        cout << "Enter coordinates of x2,y2:";
        cin >> A[1][0] >> A[1][1];
        cout << "Enter coordinates of x3,y3:";
        cin >> A[2][0] >> A[2][1];
        A[0][2] = A[1][2] = A[2][2] = 1;
        line(A[0][0], A[0][1], A[1][0], A[1][1]);
        line(A[1][0], A[1][1], A[2][0], A[2][1]);
        line(A[2][0], A[2][1], A[0][0], A[0][1]);


        cout << "\n1.Translation\n2.Scaling\n3.rotation";
        cout << "enter your choice" << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            int t[3][3], l[3][3];
            cout << "Enter the value of tx and ty:" << endl;
            cin >> t[2][0] >> t[2][1];
            t[0][0] = t[1][1] = t[2][2] = 1;
            t[1][0] = t[0][1] = t[0][2] = t[1][2] = 0;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    l[i][j] = 0;
                    for (int k = 0; k < 3; k++)
                    {
                        l[i][j] += A[i][k] * t[k][j];
                    }
                }
            }
            setcolor(BLUE);
            line(l[0][0], l[0][1], l[1][0], l[1][1]);
            line(l[1][0], l[1][1], l[2][0], l[2][1]);
            line(l[2][0], l[2][1], l[0][0], l[0][1]);
            delay(2000);
            //break;
        }
        case 2:
        {
            //float sx, sy;
            float t[3][3], l[3][3];
            cout << "Enter the value of sx and sy:" << endl;
            cin >> t[0][0] >> t[1][1];
            t[0][1] = t[0][2] = t[1][0] = t[1][2] = t[2][0] = t[2][1] = 0;
            t[2][2] = 1;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    l[i][j] = 0;
                    for (int k = 0; k < 3; k++)
                    {
                        l[i][j] += A[i][k] * t[k][j];
                    }
                }
            }
            setcolor(BLUE);
            line(l[0][0], l[0][1], l[1][0], l[1][1]);
            line(l[1][0], l[1][1], l[2][0], l[2][1]);
            line(l[2][0], l[2][1], l[0][0], l[0][1]);
            delay(2000);
            //break;
        }
        case 3:
        {
            float z, V;
            float t[3][3];
            float l[3][3];
            cout << "Enter the angle:";
            cin >> z;
            V = (z * 3.14) / 180;
            t[2][2] = 1;
            t[0][2] = t[1][2] = t[2][0] = t[2][1] = 0;
            t[0][0] = t[1][1] = cos(V);
            t[0][1] = sin(V);
            t[1][0] = (-sin(V));
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    l[i][j] = 0;
                    for (int k = 0; k < 3; k++)
                    {
                        l[i][j] += A[i][k] * t[k][j];
                    }
                }
            }
            setcolor(BLUE);
            line(l[0][0], l[0][1], l[1][0], l[1][1]);
            line(l[1][0], l[1][1], l[2][0], l[2][1]);
            line(l[2][0], l[2][1], l[0][0], l[0][1]);
            delay(2000);
            //break;
        }
        /*case 4:
            cout << "Enter wrong choice";
            break;*/
        }


    }
    case 2:
    {
        int a;
        int B[4][3];
        cout << "Enter coordinates of x1,y1:";
        cin >> B[0][0] >> B[0][1];
        cout << "Enter coordinates of x2,y2:";
        cin >> B[1][0] >> B[1][1];
        cout << "Enter coordinates of x3,y3:";
        cin >> B[2][0] >> B[2][1];
        cout << "Enter coordinates of x4,y4:";
        cin >> B[3][0] >> B[3][1];
        B[0][2] = B[1][2] = B[2][2] = B[3][2] = 1;
        setcolor(RED);
        line(B[0][0], B[0][1], B[1][0], B[1][1]);
        line(B[1][0], B[1][1], B[2][0], B[2][1]);
        line(B[2][0], B[2][1], B[3][0], B[3][1]);
        line(B[3][0], B[3][1], B[0][0], B[0][1]);

        cout << "Which transformation you want to perform:";
        cout << "\n1.Translation\n2.Scaling\n3.Rotation" << endl;
        cin >> a;
        switch (a)
        {
        case 1:
        {
            //int tx, ty;
            int b[3][3];
            int c[4][3];
            cout << "Enter co-ordinates of tx,ty:";
            cin >> b[2][0] >> b[2][1];
            b[0][0] = b[1][1] = b[2][2] = 1;
            b[0][1] = b[0][2] = b[1][0] = b[1][2] = 0;


             for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    c[i][j] = 0;
                    for (int k = 0; k < 3; k++)
                    {
                        c[i][j] += B[i][k] * b[k][j];
                    }
                }
            }
            setcolor(GREEN);
            line(c[0][0], c[0][1], c[1][0], c[1][1]);
            line(c[1][0], c[1][1], c[2][0], c[2][1]);
            line(c[2][0], c[2][1], c[3][0], c[3][1]);
            line(c[3][0], c[3][1], c[0][0], c[0][1]);
            //break;
        }
        case 2:
        {
            //float sx, sy;
            float t[3][3];
            float l[4][3];
            cout << "Enter the value of sx and sy:" << endl;
            cin >> t[0][0] >> t[1][1];
            t[0][1] = t[0][2] = t[1][0] = t[1][2] = t[2][0] = t[2][1] = 0;
            t[2][2] = 1;
            //int l[4][3];
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    l[i][j] = 0;
                    for (int k = 0; k < 3; k++)
                    {
                        l[i][j] += B[i][k] * t[k][j];
                    }
                }
            }
            setcolor(GREEN);
            line(l[0][0], l[0][1], l[1][0], l[1][1]);
            line(l[1][0], l[1][1], l[2][0], l[2][1]);
            line(l[2][0], l[2][1], l[3][0], l[3][1]);
            line(l[3][0], l[3][1], l[0][0], l[0][1]);
            delay(2000);
            //break;

        }
        case 3:
        {
            float z, V;
            float t[3][3];
            float l[4][3];
            cout << "Enter the angle:";
            cin >> z;
            V = (z * 3.14) / 180;
            t[2][2] = 1;
            t[0][2] = t[1][2] = t[2][0] = t[2][1] = 0;
            t[0][0] = t[1][1] = cos(V);
            t[0][1] = sin(V);
            t[1][0] = (-sin(V));
            //int l[4][3];
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    l[i][j] = 0;
                    for (int k = 0; k < 3; k++)
                    {
                        l[i][j] += B[i][k] * t[k][j];
                    }
                }
            }
            setcolor(BLUE);
            line(l[0][0], l[0][1], l[1][0], l[1][1]);
            line(l[1][0], l[1][1], l[2][0], l[2][1]);
            line(l[2][0], l[2][1], l[3][0], l[3][1]);
            line(l[3][0], l[3][1], l[0][0], l[0][1]);
            delay(2000);
            break;
        }
        case 4:
            cout << "Enter wrong choice";
            break;
        }
    }
    }
    delay(50000);
    return 0;
}