#include <iostream.h>
#include <conio.h>
#include <graphics.h>

void main()
{
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "C:\\TC\\BGI");
  int xl, xh, yl, yh, bit1, bit2, i, x1, y1, x2, y2, b3, b4, b1, b2, d, e;
  float m;
  cout << "Enter the lower window co-ordinates";
  cin >> xl >> yl;
  cout << "Enter higher window co-ordinates";
  cin >> xh >> yh;
  rectangle(xl, yl, xh, yh);
  cout << "\n Enter the two end-points of line:";
  cout << "x1:";
  cin >> x1;
  cout << "y1:";
  cin >> y1;
  cout << "x2:";
  cin >> x2;
  cout << "y2:";
  cin >> y2;
  line(x1, y1, x2, y2);
  // for 1st end-point
  if (x1 < xl && y1 > yl)
    bit1 = 5;//0101
  else if (x1 < xl && y1 > yh && y1 < yl)
    bit1 = 1;//0001
  else if (x1 < xl && y1 < yh)
    bit1 = 9;//1001
  else if (x1 > xl && x1 < xh && y1 < yh)
    bit1 = 8;//1000
  else if (x1 > xh && y1 < yh)
    bit1 = 10;//1010
  else if (x1 > xh && y1 > yh && y1 < yl)
    bit1 = 2;//0010
  else if (x1 > xh && y1 > yl)
    bit1 = 6;//0110
  else if (x1 < xh && x1 > xl && y1 > yl)
    bit1 = 4;//0100
  else
  {
    bit1 = 0;
  }
  // for 2nd end point
  if (x2 < xl && y2 > yl)
    bit2 = 5;
  else if (x2 < xl && y2 > yh && y2 < yl)
    bit2 = 1;
  else if (x2 < xl && y2 < yh)
    bit2 = 9;
  else if (x2 > xl && x2 < xh && y2 < yh)
    bit2 = 8;
  else if (x2 > xh && y2 < yh)
    bit2 = 10;
  else if (x2 > xh && y2 > yh && y2 < yl)
    bit2 = 2;
  else if (x2 > xh && y2 > yl)
    bit2 = 6;
  else if (x2 < xh && x2 > xl && y2 > yl)
    bit2 = 4;
  else
  {
    bit2 = 0;
  }
//further calculation
  m = (float)(y2 - y1) / (x2 - x1);
  b1 = m * (xl - x1) + y1;
  b2 = m * (xh - x1) + y1;
  d = yh - y1;
  e = yl - y1;
  b3 = x1 + (d / m);
  b4 = x1 + (e / m);
  if (bit1 != 0 || bit2 != 0)
  {
    setcolor(46);
    if (b1 <= yl && b1 >= yh && b2 <= yl && b2 >= yh)
      line(xl, b1, xh, b2);
    else if (b1 <= yl && b1 >= yh && b3 <= xh && b3 >= xl)
      line(xl, b1, b3, yh);
    else if (b1 <= yl && b1 >= yh && b4 <= xh && b4 >= xl)
      line(xl, b1, b4, yl);
    else if (b2 <= yl && b2 >= yh && b3 <= xh && b3 >= xl)
      line(xh, b2, b3, yh);
    else if (b2 <= yl && b2 >= yh && b4 <= xh && b4 >= xl)
      line(xh, b2, b4, yl);
    else if (b3 <= xh && b3 >= xl && b4 <= xh && b4 >= xl)
      line(b3, yh, b4, yl);
  }
  else
  {
    cout << "line lies inside the window";
  }
  getch();
  closegraph();
  return 0;
}
