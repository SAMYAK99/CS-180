#include<stdio.h>
int convertToInt(char *,int *);
int main(int count,char *str[])
{
int value;
bool success;
if(count==1)
{
printf("Usage [convertToInt number]");
return 0;
}
value=convertToInt(str[1],&success);
if(!success) 
{
printf("Invalid number");
return 0;
}
printf("Converted to int! value= %d",value);
return 0;
}
int convertToInt(char *str,bool *success)
{
int result=0;
int y=1;
if(*str=='-')
{
y=-1;
str++;
}
while(*str)
{
if(*str<48 || *str>57)
{
*success=false;
return 0;
}
result=(result*10)+(*str-48);
str++;
}
*success=true;
return result*y;
}