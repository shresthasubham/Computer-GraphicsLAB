
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<graphics.h>

int main()
{
	int x0,y0,xn,yn,steps,dx,dy,i;
	float xinc,yinc,x,y;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\turboC3\\BGI");
	printf("Enter initial point:");
	scanf("%d%d",&x0,&y0);
	printf("Enter final point:");
	scanf("%d%d",&xn,&yn);
	dx=xn-x0;
	dy=yn-y0;
	if(abs(dx)>abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);
	xinc=dx/steps;
	yinc=dy/steps;
	x=x0;
	y=y0;
	for(i=1;i<steps+1;i++)
	{

		x=x+xinc;
		y=y+yinc;
		putpixel(x0,y0,4);
		x0=x;
		y0=y;

	}


	return 0;
}