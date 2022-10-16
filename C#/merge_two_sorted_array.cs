using System;  
public class Exercise7
{  
    public static void Main() {
	    int[] arr1 = new int[100];
	int[] arr2 = new int[100];
	int[] arr3 = new int[200];
    int s1, s2, s3;
    int i, j, k;
	
	
       Console.Write("\n\nMerge two arrays of same size sorted in ascending order.\n");
       Console.Write("------------------------------------------------------------\n");	
	   
       Console.Write("Input the number of elements to be stored in the first array :");
	   s1 = Convert.ToInt32(Console.ReadLine()); 	   
   
       Console.Write("Input {0} elements in the array :\n",s1);
       for(i=0;i<s1;i++)
            {
	      Console.Write("element - {0} : ",i);
	     arr1[i] = Convert.ToInt32(Console.ReadLine()); 		  
	    }


       Console.Write("Input the number of elements to be stored in the second array :");
	   s2 = Convert.ToInt32(Console.ReadLine()); 	   
   
       Console.Write("Input {0} elements in the array :\n",s2);
       for(i=0;i<s2;i++)
            {
	      Console.Write("element - {0} : ",i);
	     arr2[i] = Convert.ToInt32(Console.ReadLine()); 		  
	    }
    s3 = s1 + s2;
    for(i=0;i<s1; i++)
        {
            arr3[i] = arr1[i];
         }
     for(j=0;j<s2; j++)
        {
            arr3[i] = arr2[j];
            i++; 
        }
   for(i=0;i<s3; i++)
        {
           for(k=0;k<s3-1;k++)
             {
         
                if(arr3[k]>=arr3[k+1])
                 {
                   j=arr3[k+1];
                   arr3[k+1]=arr3[k];
                   arr3[k]=j;
                 }  
              }
         }  
    Console.Write("\nThe merged array in ascending order is :\n");
    for(i=0; i<s3; i++)
    {
        Console.Write("{0} ", arr3[i]);
    }
	Console.Write("\n\n");
  }
}
