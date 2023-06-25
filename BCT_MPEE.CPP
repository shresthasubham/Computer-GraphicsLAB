#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#define ROUND(a) ((int)(a+0.5))
void ellipseMidpoint(int xc,int yc, int rx,int ry)
{
 int a2=rx*rx;
 int b2=ry*ry;
 int twoa2=2*a2;
  int twob2=2*b2;
  int p,x=0,y=ry,px=0,py=twoa2*y;
void ellipsePlot(int,int,int,int);

ellipsePlot(xc,yc,x,y);


//region1
p=ROUND(b2-(a2*ry)+(0.25*a2));
while(px<py){
x++;
px+=twob2;
if(p<0)
  p+=b2+px;
else{
	y--;
	py-=twoa2;
	p+=b2+px-py;
}
ellipsePlot(xc,yc,x,y);

}


//region2
x=rx;
y=0,px=2*x*b2,py=0;
ellipsePlot(xc,yc,x,y);
p=ROUND(a2-rx*b2+0.25*b2);
while(px>py){
	y++;
py+=twoa2;
if(p<=0)
  p+=a2+py;
else{
	x--;
	px-=twob2;
	p+=a2+py-px;
}
ellipsePlot(xc,yc,x,y);
}
}



void ellipsePlot (int h,int k,int x, int y){
putpixel (h+x,k+y,RED);
putpixel (h-x,k+y,RED);
putpixel (h+x,k-y,RED);
putpixel (h-x,k-y,RED);


}

int main(){

	int gd=DETECT,gm,i=0;
	initgraph(&gd,&gm,"C:\\turboc3\\bgi");
   //	  for(i=0;i<20;i++)
	   ellipseMidpoint(100,100,25,15);


				getch();
				closegraph();
				return 0;
}