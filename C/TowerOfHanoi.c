#include<stdio.h>
int count=1;
void Hanoi(int n,char l,char m,char o) {
   if(n>0) 
   { 
      Hanoi(n-1,l,o,m);
      printf("Step-%d--> Move from %c to %c \n",count, l, m);
       count++;
      Hanoi(n-1,o,m,l);
   }
}
int main() {
   int n;
   printf("Enter the number of Discs:\t");
   scanf("%d",&n);
   Hanoi(n,'A','B','C');
   return 0;
}

