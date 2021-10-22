/* Program to remove the adjacent duplicacy from the string */
#include<stdio.h>
char *removeAdjacent(char *s)
{
	int i,j;
	for(i=0; s[i]!='\0'; i++)
	{
		if(s[i] == s[i+1])
		{
			for(j=i; s[j]!='\0'; j++)
			{
				s[j]=s[j+1];
			}
			i--;
		}
	}
	return s;
}
int main()
{
	char s[]="AAABBBCCD";
	printf("%s",removeAdjacent(s));
	return 0;
}