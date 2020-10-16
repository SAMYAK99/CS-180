using System;  
  public class PrintExample  
   {  
     public static void Main(string[] args)  
      {  
       char ch='A';      
       int i, j, k, m;      
       for(i=1; i<=5; i++)      
       {      
        for(j=5; j>=i; j--)      
         Console.Write(" ");      
        for(k=1;k<=i;k++)      
         Console.Write(ch++);      
        ch--;      
        for(m=1;m<i;m++)      
         Console.Write(--ch);      
        Console.Write("\n");      
        ch='A';      
       }      
   }  
  }  