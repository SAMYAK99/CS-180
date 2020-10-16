using System;  
  public class ConversionExample  
   {  
     public static void Main(string[] args)  
      {  
       int n,sum=0,r;     
       Console.Write("Enter the Number= ");    
       n= int.Parse(Console.ReadLine());     
       while(n>0)      
       {      
        r=n%10;      
        sum=sum*10+r;      
        n=n/10;      
       }      
       n=sum;      
       while(n>0)      
       {      
        r=n%10;      
        switch(r)      
        {      
         case 1:      
         Console.Write("one ");  
         break;      
         case 2:      
         Console.Write("two ");      
         break;      
         case 3:      
         Console.Write("three ");    
         break;      
         case 4:      
         Console.Write("four ");    
         break;      
         case 5:      
         Console.Write("five ");    
         break;      
         case 6:      
         Console.Write("six ");     
         break;      
         case 7:    
         Console.Write("seven ");    
         break;    
         case 8:      
         Console.Write("eight ");      
         break;      
         case 9:      
         Console.Write("nine ");    
         break;      
         case 0:      
         Console.Write("zero ");    
         break;      
         default:      
         Console.Write("tttt ");      
         break;      
        }//end of switch      
        n=n/10;      
       }//end of while loop       
   }  
  }  