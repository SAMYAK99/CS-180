public class Shell_Sort {

    static void arrayPrint(int ar[]) { 
        int n = ar.length; 
        for (int i=0; i<n; ++i) 
            System.out.print(ar[i] + " "); 
        System.out.println(); 
    } 
 
    int sort(int ar[]) { 
        int n = ar.length; 

        for (int gap = n/2; gap > 0; gap /= 2) { 
            for (int i = gap; i < n; i += 1) { 
                int temp = ar[i]; 

                int j; 
                for (j = i; j >= gap && ar[j - gap] > temp; j -= gap) 
                    ar[j] = ar[j - gap]; 

                ar[j] = temp; 
            } 
        } 
        return 0; 
    } 
    
    // main method
    public static void main(String[] args) 
    { 
        int ar[] = {16,87,14,64,25,34}; 
        System.out.println("Array before sorting"); 
        printArray(ar); 
  
        Shell_Sort ssort = new Shell_Sort(); 
        ssort.sort(ar); 
  
        System.out.println("Array after sorting"); 
        arrayPrint(ar); 
    } 
}
