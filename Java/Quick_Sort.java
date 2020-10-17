class Quick_Sort {
    
    int part(int ar[], int l, int h) 
    { 
        int piv = ar[h];  
        int v = (l-1); // index of smaller element 

        for (int i=l; i<h; i++) { 
            // If current element is smaller than the piv

            if (ar[i] < piv) { 
                v++; 
  
                // for swaping ar[v+1] (or piv)
                int temp = ar[v]; 
                ar[v] = ar[i]; 
                ar[i] = temp; 
            } 
        } 

        // swap arr[v+1] and ar[h] (or piv) 
        int temp = ar[v+1]; 
        ar[v+1] = ar[h]; 
        ar[h] = temp; 
  
        return v+1; 
    } 

     /* The main function that implements Quick_Sort() 
      ar[] --> Array to be sorted, 
      l  --> Starting index, 
      h  --> Ending index */
      void sort(int ar[], int l, int h) { 
          if (l < h) { 
              /* pi is partitioning index, arr[pi] is  
                now at right place */
              int partInd = part(ar, l, h); 
    
              // Recursively sort elements before 
              // partition and after partition 
              sort(ar, l, partInd-1); 
              sort(ar, partInd+1, h); 
          } 
      } 

       /* A utility function to print array of size n */
    static void array_Print(int ar[]) { 
        int n = ar.length; 
        for (int i=0; i<n; ++i) 
            System.out.print(ar[i]+" "); 
        System.out.println(); 
    } 
    
    // main function 
    public static void main(String args[]) { 
        int ar[] = {101, 17, 84, 69, 91, 25}; 
        int n = ar.length; 
  
        Quick_Sort sor = new Quick_Sort(); 
        sor.sort(ar, 0, n-1); 
  
        System.out.println("sorted array"); 
        array_Print(ar); 
    } 
}