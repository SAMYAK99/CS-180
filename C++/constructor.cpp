#include<conio.h>
#include<iostream>

using namespace std;

class Complex
{
private:
    int a,b;
public:
    Complex(int x, int y)
    {a=x; b=y;}
    Complex(int k)
    {
        a=k;
    }
    Conplex()
    {
        a=0;b=0;
    }
    Complex(Complex &c)
    {
        a=c.a;
        b=c.b;
    }
};

int main()
{
    Complex c1(3,4), c2(5),c3;
    Complex c4(c1);
    getch();
}
