import java.io.*;
import java.util.*;

public class Radix_Sort {
    // function for getting maximum value in ar[]
    static int getMax(int ar[], int n)
     {
         int max = ar[0];
         for (int i = 1; i < n; i++)
             if (ar[i] > max)
                 max = ar[i];
         return max;
     }

     static void sortCount(int ar[], int n, int expo)
     {
         int output[] = new int[n]; // output array
         int i;
         int count[] = new int[10];
         Arrays.fill(count, 0);

         // Store count of occurrences in count[]
         for (i = 0; i < n; i++) {
            count[(ar[i] / expo) % 10]++;
         }

         for (i = 1; i < 10; i++) {
             count[i] = count[i] + count[i - 1];
         }
          // Build the output array
         for (i = n - 1; i >= 0; i--) {
            output[count[(ar[i] / expo) % 10] - 1] = ar[i];
            count[(ar[i] / expo) % 10]--;
        }

       
        for (i = 0; i < n; i++) {
             ar[i] = output[i];
        }
    }

    static void radix_Sort(int ar[], int n)
     {
         // Find the maximum number to know number of digits
         int m = getMax(ar, n);
        
         // expo is 10^i where i is current digit number
         for (int expo = 1; m / expo > 0; expo *= 10) {
             sortCount(ar, n, expo);
         }
     }
     
     // A function to print an array 
     static void print(int ar[], int n)
     {
         for (int i = 0; i < n; i++) {
             System.out.print(ar[i] + " ");
         }
     }
  
     // main function
     public static void main(String[] args)
     {
         int ar[] = { 15, 745, 85, 12, 42, 34, 32, 51 };
         int n = ar.length;
            
           // Function Call
         radix_Sort(ar, n);
         print(ar, n);
     }

}
