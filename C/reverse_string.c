#include <stdio.h>  
#include <string.h>  
  
void reversestr(char *str)  {  
    static int i, len, temp;  
    len = strlen(str);    
      
    if(i < len/2){  
        temp = str[i];  
        str[i] = str[len - i - 1];  
        str[len - i - 1] = temp;  
        i++;  
        reversestr(str); 
    }  
}  
      
int main()  {  
    char str[60]; 
    printf (" Enter the string: ");  
    scanf("%s",&str);
          
    printf ("Before reversing the string: %s \n", str);     
    reversestr(str);  
    printf ("After reversing the string: %s", str);  
}  