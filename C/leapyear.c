#include<stdio.h>
int main()
{
    int year;
    printf("Enter the year \n");
    scanf("%d",&year);

    if( ( (year%4) == 0) 
        && !( ( year%100) == 0 ) 
        || ((year%400) == 0) ) {
            printf(" %d year is the leap year",year);
        }
    return 0;
}
