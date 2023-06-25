#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void circleMidpoint(int h,int k, int r)
{
 int x=0,y=r,p=1-r;
void circlePlot(int,int,int,int);

circlePlot(h,k,x,y);

while(x<y)
{
x++;
if(p<0)
  p+=2*x+1;
else{
y--;
p+=2*(x-y)+1;

}
circlePlot(h,k,x,y);
}
}

void circlePlot (int h,int k,int x, int y){
putpixel (h+x,k+y,RED);
putpixel (h-x,k+y,RED);
putpixel (h+x,k-y,RED);
putpixel (h-x,k-y,RED);
putpixel (h+y,k+x,RED);
putpixel (h-y,k+x,RED);
putpixel (h+y,k-x,RED);
putpixel (h-y,k-x,RED);


}

int main(){

	int gd=DETECT,gm,i=0;
	initgraph(&gd,&gm,"C:\\turboc3\\bgi");
	  for(i=0;i<50;i++)
	   circleMidpoint(100,100,50-i);


				getch();
				closegraph();
				return 0;
				}
