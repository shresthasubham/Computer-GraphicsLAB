#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

int point[4] = {100,100,200,100};


void translate(int tx, int ty)
{        /*
	int tmat[3][3]={{1,0,0},{0,1,0},(tx,ty,0)}
	int newp1 = mult(tmat,p1);
	int newp2 = mult(tmat,p2);
	*/
	int tp[4] = {point[0]+tx,point[1]+ty,point[2]+tx,point[3]+ty};
	line(tp[0],tp[1],tp[2],tp[3]);
}
void rotate(double theta,int ox,int oy)
{
	theta = (theta/180.0)*3.14;
	int rp[4];
	rp[0] = (point[0]-320-ox)*cos(theta) + (point[1]-240+oy)*sin(theta)+320;
	rp[1] = (point[0]-320-ox)*sin(theta) - (point[1]-240+oy)*cos(theta);
	rp[2] = (point[2]-320-ox)*cos(theta) + (point[3]-240+oy)*sin(theta)+320;
	rp[3] = (point[2]-320-ox)*sin(theta) - (point[3]-240+oy)*cos(theta);
	line(rp[0]+ox,240-rp[1]-oy,rp[2]+ox,240-rp[3]-oy);
}
void scale(float f, int ox, int oy)
{
	int sp[4] = {(point[0]-320-ox)*f+320+ox,(240-point[1]-oy)*f+oy,(point[2]-320-ox)*f+320+ox,(240-point[3]-oy)*f+oy};
	line(sp[0],240-sp[1],sp[2],240-sp[3]);
}
int main()
{
int gd=DETECT,gm;


printf("Choose your operation:\n");
printf("1. Translation\n");
printf("2. Rotation about origin \n");
printf("3. Rotaion about fixed point \n");
printf("4. Scaling about origin \n");
printf("5. Scaling about fixed point \n");

int choice;
printf("Enter your choice: \n ");


scanf("%d",&choice);
switch(choice)
	{
	case 1:

		int tx, ty;
		printf("Enter x and y translations \n");
		scanf("%d%d",&tx,&ty);
		clrscr();
		initgraph(&gd,&gm, "C:\\turboc3\\bgi");
		line(320,0,320,480);
		line(0,240,640,240);
		line(point[0],point[1],point[2],point[3]);
		translate(tx,ty);


		break;

	case 2:
		float th;
		printf("Enter the angle to rotate \n");
		scanf("%f",&th);
		clrscr();
		initgraph(&gd,&gm, "C:\\turboc3\\bgi");
		line(320,0,320,480);
		line(0,240,640,240);
		line(point[0],point[1],point[2],point[3]);
		rotate(th,0,0);
		break;

	case 3:
		float th2;
		printf("Enter the angle to rotate \n");
		scanf("%f",&th2);
		int ox, oy;
		scanf("%d%d",&ox,&oy);
		clrscr();
		initgraph(&gd,&gm, "C:\\turboc3\\bgi");
		line(320,0,320,480);
		line(0,240,640,240);
		line(point[0],point[1],point[2],point[3]);
		rotate(th2,ox,oy);
		break;

	default:
		printf("Invalid\n");
		clrscr();
		initgraph(&gd,&gm, "C:\\turboc3\\bgi");
		line(320,0,320,480);
		line(0,240,640,240);
		line(point[0],point[1],point[2],point[3]);
		scale(1.1,0,0);
		break;


 }
getch();
closegraph();
return 0;
}