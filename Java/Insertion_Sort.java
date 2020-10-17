public class Insertion_Sort {

    //Function to sort array using insertion sort
    void inser_Sort(int ar[]) 
    { 
        int n = ar.length; 
        for (int i = 1; i < n; ++i) { 
            int k = ar[i]; 
            int j = i - 1; 
  
            /* Move elements of arr[0..i-1], that are 
               greater than k, to one position ahead 
               of their current position */
            while (j >= 0 && ar[j] > k) { 
                ar[j + 1] = ar[j]; 
                j = j - 1; 
            } 
            ar[j + 1] = k; 
        } 
    } 

    static void arrayPrint(int ar[]) 
    { 
        int n = ar.length; 
        for (int i = 0; i < n; ++i) {
            System.out.print(ar[i] + " "); 
        }

        System.out.println(); 
    } 
  
     // main function
     public static void main(String[] args) 
     { 
         int ar[] = { 14, 41, 63, 95, 107 }; 
   
         Insertion_Sort sor = new Insertion_Sort(); 
         sor.inser_Sort(ar); 
   
         arrayPrint(ar); 
     } 

}
