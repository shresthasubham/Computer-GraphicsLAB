#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
int main(){

	int gd=DETECT,gm,i,x1,y1,x2,y2,lx,ly,dy,dx,pk,x,y;
	initgraph(&gd,&gm,"C:\\turboc3\\bgi");
	printf("enter x1,y1,x2,y2");
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	if(x2>x1){
		lx=1;}
	else{
		lx=-1;}
	if(y2>y1){
		ly=1;}
	else{
		ly=-1;}
	putpixel(x1,y1,RED);
	if(dx>dy){
		pk=2*dy-dx;
		for(i=0;i<dx;i++){
		if(pk>0){
			x1=x1+lx;
			y1=y1;
			pk=pk+2*dy;}
		else{
			x=x1+lx;
			y1=y1+ly;
			pk=pk+2*dy-2*dx;
			}
		putpixel(x1,y1,RED);
		}}
		else{
			pk=2*dx-dy;
			for(i=0;i<dy;i++){
			if(pk<0){
				x1=x1;
				y1=y1+ly;
				pk=pk+2*dx;
				}
			else{
				x1=x1+lx;
				y1=y1+ly;
				pk=pk+2*dx-2*dy;
				}
				putpixel(x1,y1,RED);
				}}
				getch();
				closegraph();
				return 0;
				}
