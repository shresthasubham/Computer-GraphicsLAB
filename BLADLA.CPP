#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h> // for delay function
#define ROUND(a) ((int) (a+0.5))

void lineDDA(int xa, int ya, int xb, int yb)
{
int dx = xb - xa, dy = yb - ya, steps, k;
float xIncrement, yIncrement, x = xa, y = ya;

if(abs(dx) > abs(dy)) steps = abs(dx);
else steps = abs(dy);
xIncrement = dx / (float) steps;
yIncrement = dy / (float) steps;

putpixel(ROUND(x), ROUND(y), RED);
for(k = 0; k < steps; k++)
{
x += xIncrement;
y += yIncrement;
putpixel(ROUND(x), ROUND(y), GREEN);
//delay(100);
}
}

void lineBres(int xa, int ya, int xb, int yb)
{
int dx = abs(xa - xb), dy = abs(ya - yb);
int p = 2 * dy - dx;
int twoDy = 2 * dy, twoDyDx = 2 * (dy - dx);
int x, y, xEnd;

// Determine which point to use as start and which as end
if(xa > xb)
{
x = xb;
y = yb;
xEnd = xa;
}
else
{
x = xa;
y = ya;
xEnd = xb;
}
putpixel(x,y,RED);

while(x < xEnd)
{
x++;
if(p < 0) p += twoDy;
else
{
y++;
p += twoDyDx;
}
putpixel(x,y,RED);
//delay(100);
}
}

int main()
{
int gd = DETECT, gm;
initgraph(&gd, &gm, "C:\\turboc3\\bgi");

int x1 = 300, y1 = 350;
int a = 100;
for(int i = 0; i < 360; i++)
{
//lineBres(200, 200, 300, 300);
lineDDA((int)(x1+a*cos(i)),(int)(y1+a*sin(i)),
(int)(x1-a*cos(180-i)),(int)(y1-a*sin(180-i)));
//lineBres(100+i,150-i,300-i,350+i);
delay(50);
}
getch();
closegraph();
return 0;
}