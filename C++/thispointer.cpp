#include<conio.h>
#include<iostream>

using namespace std;

class Box
{
private:
    int l,b,h;

public:
    void setDimension(int x, int y, int z)
    {
        l=x;
        b=y;
        h=z;
    }

    void showDimension()
    {
        cout<<"l="<<l<<" b="<<b<<" h="<<h;
    }
};

int main()
{
    Box smallBox, *p;

    p = &smallBox;
    p->setDimension(12,10,5);
    p->showDimension();
}
