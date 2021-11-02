#include<fstream>
#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
    ofstream fout;
    fout.open("myfile.dat");
    fout<<"Hello";
    fout.close();
}

