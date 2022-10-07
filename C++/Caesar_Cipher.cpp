#include <iostream>

using namespace std;

int main()
{
    string s;
    int k;
    cout<<"enter plain text : ";
    getline(cin,s);
    cout<<"\n enter Key : ";
    cin>>k;
    string c="";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!=' ')
        {
        string p;
        p= ((s[i]+k)%65)+65;
        c+=p;
        }
        else
        {
            c+=" ";
        }
    }
    cout<<"\n cipher text : "<<c;
    return 0;
}
