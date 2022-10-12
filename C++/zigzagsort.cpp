# include<iostream>
using namespace std;
int sort(int n,int num[])
{
    int temp;
    for(int i=1;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            temp=num[i];
            num[i]=num[j];
            num[j]=temp;
            break;
        }
        i+=1;
    }
    for(int k=0;k<n;k++)
    {
        cout<<num[k];
    }
    return 0;
}



int main()
{
    int i,n,num[50];
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the numbers: ";
    for (i=0;i<n;i++)
    {
    cin>>num[i];
    }
    sort(n,num);
    return 0;
}

