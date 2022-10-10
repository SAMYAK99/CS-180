/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    string p;
    string k;
    string s="";
    cout<<"Enter plain text : ";
    getline(cin,p);
    string l;
    for(int i=0;i<p.length();)
    {
        
        if(i+1<p.length() && p[i]==p[i+1] )
        {
            
            
            s+=p[i];
            s+='x';
            s+=p[i+1];
            s+='x';
            i=i+2;
        }
        else
        {
            s+=p[i];
            i+=1;
        }
    }
    if(s.length()%2!=0)
    {
        s+='x';
    }
    
    int a[5][5]={{'m','o','n','a','r'},{'c','h','y','b','d'},{'e','f','g','i','k'},{'l','p','q','s','t'},{'u','v','w','x','z'}};
    string cp="";
    for(int i=0;i<s.length();i+=2)
    {
        char ch1=s[i];
        char ch2=s[i+1];
        int c1,c2,r1,r2;
        for(int r=0;r<5;r++)
        {
            for(int c=0;c<5;c++)
            {
                if(a[r][c]==ch1)
                {
                    r1=r;
                    c1=c;
                }
                if(a[r][c]==ch2)
                {
                    r2=r;
                    c2=c;
                }
            }
        }
        
        if(r1==r2)
        {
            cp+=a[r1][c1%5];
            cp+=a[r2][c2%5];
        }
        if(c1==c2)
        {
            cp+=a[r1%5][c1];
            cp+=a[r2%5][c2];
        }
        if(c1!=c2 && r1 != r2)
        {
            cp+=a[r2%5][c1%5];
            cp+=a[r1%5][c2%5];
        }
        
    }
    cout<<"\n play fair cipher : "<<cp;
    
    return 0;
}
