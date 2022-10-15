#include<iostream>
using namespace std;
 
int main()
  {
    int i,j,row;
    cout<<"Enter size: "; cin>>row;

    cout<<endl;

//upper part
     for(i=1;i<=row;i++)
      {
	 for(j=1; j<=i; j++)
	   cout<<"*"; for(int k=row*2; k>i+j-2; k--)
	   cout<<" ";

	 for(j=1; j<=i; j++)
	   cout<<"*";

	 cout<<endl;
      }

// lower part
     for(i=1; i<=row; i++)
      {
	 for(j=1; j<=row-i; j++)
	     cout<<"*";

	 for(int k=0; k<=(i*2); k++)
	     cout<<" ";

	 for(j=1; j<=row-i; j++)
	     cout<<"*";

	 cout<<endl;
      }
   return 0;
 }
