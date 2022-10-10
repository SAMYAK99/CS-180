#include < stdio.h >  
  
int main()  
{  
    int n, r, s = 0, t;  
  
    printf("Enter an integer number\n");  
    scanf("%d", &n);  
  
    t = n;  
  
    while(n)  
    {  
        r = n % 10;  
        s = s + (r * r * r);  
        n = n / 10;  
    }  
  
    if(t == s)  
    {  
        printf("%d is armstrong number\n", t);  
    }  
    else  
    {  
        printf("%d is not armstrong number\n", t);  
    }  
  
    return 0;  
}  
