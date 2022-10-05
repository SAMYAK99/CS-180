#include<bits/stdc++.h>
using namespace std;

// Algorithm of Ackermann Function  
int ack(int m,int n){
  
  if( m==0 ){
    return n+1;
  }
  else if( (m > 0) && (n == 0) ){
    return ack(m-1 , 1);
  }
  else if( (m > 0) && (n > 0) ){
    return ack(m - 1, ack(m, n - 1));
  }
  
}

int main()
{
  int m, n, a;
  cin >> m >> n;
  a = ack(m, n);
  cout << a << endl;
  return 0;
}

// This will compute the Ackermann value of m, n 
