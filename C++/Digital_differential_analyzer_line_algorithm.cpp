#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<math.h>

using namespace std;

int main()
{
    int x,y,x1,y1,x2,y2,dx,dy,step,i=1;
    int gd=DETECT,gm;

    initgraph(&gd,&gm," ");

                            cout<<"Enter values of x1,y1,x2,y2 : ";
                            cin>>x1>>y1>>x2>>y2;

                            dx=abs(x2-x1);
                            dy=abs(y2-y1);

                            if(dx>=dy)
                                step=dx;
                            else
                                step=dy;

                            dx=dx/step;
                            dy=dy/step;

                            x=x1;
                            y=y1;

                            while(i<=step)
                                    {
                                            putpixel(x,y,WHITE);
                                            x=x+dx;
                                            y=y+dy;
                                            i=i+1;
                                    }
    getch();
	closegraph();

    return 0;
}
