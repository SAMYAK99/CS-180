#include<iostream>
using namespace std;
int main()
{
    int i,n,f[100],d[10],count=0;
    
    cout<<"Enter the number of digits: ";
    cin>>n;
    
    cout<<"Enter the values: ";
    for(i=0;i<n;i++)
    {
      cin>>d[i];  
    }
    for(int j=1;j<n;j++)
    {
       if(d[0]!=d[j])
       {
        count++;
       } 
    }
    cout<<"number of elements dissimilar to the first element is: "<<count<<endl;
    return 0;
}