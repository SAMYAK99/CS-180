#include<stdio.h>
void squeeze(char sh[],int c)
{
    int i,j;
    for(int i=j=0;sh[i]!='\0';i++)
    {
         if(sh[i]!=c)
            sh[j++]=sh[i];
    }
    sh[j]='\0';
}
int main()
{
    char a;
    char str[50];
    printf("Enter the string:\n");
    gets(str);
    printf("Enter the character to be removed: ");
    scanf("%c",&a);
    printf("Original String:%s\n",str);
    squeeze(str,a);
    printf("Edited string:%s\n",str);
}
