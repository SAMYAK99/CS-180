#include<bits/stdc++.h>
using namespace std ;


int stringtoint(char *s , int n ){
      if(n==0)
        return 0 ;

      int last_dig = s[n-1] -'0';     // string to int
       int sans  =   stringtoint(s,n-1);

        return sans*10 + last_dig ;   
}

int main(){
   
   char s[1000] ; 
   int n = strlen(s);

    cin>>s;
   
   int x = stringtoint(s,n);
      cout<<x<<endl;
     
  return 0 ; 
}