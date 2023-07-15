#include<iostream.h>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
liangB(float xmin,float ymin,float xmax,float ymax,float x1,float y1,float x2,float y2){
 float dx,dy,t1=0,t2=1;
 dx=x2-x1;
 dy=y2-y1;
 p[50]={0}, q[50]={0}, r[50]={0};
 p[1]=-dx;
 p[2]=dx;
 p[3]=-dy;
 p[4]=dy;
 q[1]=x1-xmin;
 q[2]=xmax-x1;
 q[3]=y1-ymin;
 q[4]=ymax-y1;
   for(int i=1;i<=4;i++)//calculating tleft tright tbottom top
      r[i]=q[i]/p[i];
   for(int j=1;j<=4;j++){
    if(p[j]==0){
        cout<<"Line is parallel to window"<<endl;
        if(q[j]<0){
            cout<<"line is outside the window so rejected"<<endl;
            return 0;

                    }
             }
   }
   
   float max=0.0,min=1.0;
   for(int k=1;k<=4;k++){
    if(p[k]<0.00&&r[k]>max){
        max=r[k];
    }
    t1=max;
     if(p[k]>0.00&&r[k]<min){
        min=r[k];
    }
    t2=min;
   }
   if(t1>t2){
    cout<<"Line is outside the window.Rejected"<<endl;
    return 0;
   }
   else{
    float x1n,y1n,x2n,y2n;
    x1n=x1+(t1*dx);
    y1n=y1+(t1*dy);
    x2n=x1+(t2*dx);
    y2n=y1+(t2*dy);
    setcolor(GREEN);
    rectangle(xmin,ymin,xmax,ymax);
     line(x1n,y1n,x2n,y2n);

   }

}



void main(){ 
    clrscr();
	int gd = DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	 float xmin,ymin,xmax,ymax;
    cout<<"Enter the maximum window coordinates(Top-left) :"<<endl;
    cout<<"xmin and ymin =";
     cin>>xmin>>ymin;
    cout<<"Enter the maximum window coordinates(Bottom-right) :"<<endl;
    cout<<"xmax and ymax =";
     cin>>xmax>>ymax;
     float x1,y1,x2,y2;
    cout<<"\nEnter the endpoints of line = ";
    cin>>x1>>y1>>x2>>y2;
     rectangle(xmin,ymin,xmax,ymax);
     line(x1,y1,x2,y2);
    delay(2000);
    cleardevice();
     rectangle(xmin,ymin,xmax,ymax);
     liangB(xmin,ymin,xmax,ymax,x1,y1,x2,y2);
	getch();
	closegraph();
	return 0;

}