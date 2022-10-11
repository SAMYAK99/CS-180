/* 
    Sieve of Eratosthenes:
    this is a popular technique to find the prime numbers in one of the most efficient way
    Time complexity T(n)->(n.logn)
*/
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
 int a,b;
 cout<<"enter the range u need prime no."<<endl;
 cin>>a>>b;//Input two no between you want two find prime numbers.
 cout<<"Primes no. between"<<a<<"and"<<b<<endl;
 int arr[b+1];// declear a array of size equal to right most element +1
 for(int i=0;i<=b;i++)
 {
   arr[i]=1; // set all values of array to 1
 }
 arr[0]=0; arr[1]=0; // we know prime no start from 2 onwards
 for(int i=2;i<=sqrt(b);i++)
 {
   if(arr[i]==1) // initial all indexes are 1 so iterate i to 2->b (both inclusive)
   {
     for(int j=i;i*j<=b;j++)
     {

          arr[i*j]=0;// All multiples of any nos  index beacome=0.(these elements index is non-prime)

     }
   }

 }
 for(int i=a;i<=b;i++)
 {
   if(arr[i]==1) // All primes having index 1 as they are not a multiple of any number.
    cout<<i<<" ";
 }


}