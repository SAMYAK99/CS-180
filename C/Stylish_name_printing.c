#include<stdio.h>
int main()
{
 char a[50];
 printf("enter your name:");
 gets(a);
 for(int i=0;a[i]!='\0';i++)
  {
    if(a[i] == 'A' || a[i] == 'a')
        printf("\n  @@@   \n @   @  \n @@@@@  \n @   @  \n @   @  \n");
    else if(a[i] == 'B' || a[i] == 'b')
        printf("\n @@@@@  \n @   @  \n @@@@   \n @   @  \n @@@@@  \n");
    else if(a[i] =='C'|| a[i] == 'c')
        printf("\n  @@@@  \n @      \n @      \n @      \n  @@@@  \n");
    else if(a[i] == 'D' || a[i] == 'd')
        printf("\n @@@@   \n @   @  \n @   @  \n @   @  \n @@@@   \n");
    else if(a[i] == 'E' || a[i] == 'e')
        printf("\n @@@@@  \n @      \n @@@@@  \n @      \n @@@@@  \n");
    else if (a[i] == 'F' || a[i] == 'f')
        printf("\n @@@@@  \n @      \n @@@@   \n @      \n @      \n");
    else if (a[i] == 'G' || a[i] == 'g')
        printf("\n  @@@@  \n @      \n @ @@   \n @  @   \n  @@@   \n");
    else if (a[i] == 'H' || a[i] == 'h')
        printf("\n @   @  \n @   @  \n @@@@@  \n @   @  \n @   @  \n");
    else if (a[i] == 'I' || a[i] == 'i')
        printf("\n @@@@@  \n   @    \n   @    \n   @   \n @@@@@  \n");
    else if (a[i] == 'J' || a[i] == 'j')
        printf("\n @@@@@  \n   @    \n   @    \n   @    \n @@@    \n");
    else if (a[i] == 'K' || a[i] == 'k')
        printf("\n @   @  \n @  @   \n @@     \n @  @   \n @   @  \n");
    else if (a[i] == 'L' || a[i] == 'l')
        printf("\n @      \n @      \n @      \n @      \n @@@@@  \n");
    else if (a[i] == 'M' || a[i] == 'm')
        printf("\n @   @  \n @@ @@  \n @ @ @  \n @   @  \n @   @  \n");
    else if (a[i] == 'N' || a[i] == 'n')
        printf("\n @   @  \n @@  @  \n @ @ @  \n @  @@  \n @   @  \n");
    else if (a[i] == 'O' || a[i] == 'o')
        printf("\n  @@@   \n @   @  \n @   @  \n @   @  \n  @@@   \n");
    else if (a[i] == 'P' || a[i] == 'p')
        printf("\n @@@@   \n @   @  \n @@@@   \n @      \n @      \n");
    else if (a[i] == 'Q' || a[i] == 'q')
        printf("\n  @@@   \n @   @  \n @   @  \n @ @ @  \n  @@ @  \n");
    else if (a[i] == 'R' || a[i] == 'r')
        printf("\n @@@   \n @   @  \n @@@@   \n @ @    \n @   @  \n");
    else if (a[i] == 'S' || a[i] == 's')
        printf("\n  @@@@  \n @      \n  @@@   \n     @  \n @@@@   \n");
    else if (a[i] == 'T' || a[i] == 't')
        printf("\n @@@@@  \n   @    \n   @    \n   @    \n   @    \n");
    else if (a[i] == 'U' || a[i] == 'u')
        printf("\n @   @  \n @   @  \n @   @  \n @   @  \n  @@@   \n");
    else if (a[i] == 'V' || a[i] == 'v')
        printf("\n @   @  \n @   @  \n @   @  \n  @ @   \n   @    \n");
    else if (a[i] == 'W' || a[i] == 'w')
        printf("\n @   @  \n @   @  \n @ @ @  \n @@ @@  \n @   @  \n");
    else if (a[i] == 'X' || a[i] == 'x')
        printf("\n @   @  \n  @ @   \n   @    \n  @ @   \n @   @  \n");
    else if (a[i] == 'Y' || a[i] == 'y')
        printf("\n @   @  \n  @ @   \n   @    \n   @    \n   @    \n");
    else if (a[i] == 'Z' || a[i] == 'z')
        printf("\n @@@@@  \n    @   \n   @    \n  @     \n @@@@@  \n");
    else if (a[i] == ' ')
        printf("\n\n");
    else
       printf("INVALID->(Cannot printf any character other than alphabets");
 }

return 0;

}
