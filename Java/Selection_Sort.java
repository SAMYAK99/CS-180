public class Selection_Sort {

    void sort(int ar[]) { 
        int n = ar.length; 
  
        for (int i = 0; i < n-1; i++) { 
        
            int min_id = i; 
            for (int j = i+1; j < n; j++) 
                if (ar[j] < ar[min_id]) 
                    min_id = j; 
              
            int tem = ar[min_id]; 
            ar[min_id] = ar[i]; 
            ar[i] = tem; 
        } 
    }

    void arrayPrint(int ar[]) 
    { 
        int n = ar.length; 
        for (int i=0; i<n; ++i) 
            System.out.print(ar[i]+" "); 
        System.out.println(); 
    } 
  
    // main method 
    public static void main(String[] args) 
    { 
        Selection_Sort sort = new Selection_Sort(); 
        int ar[] = {61,56,23,75,98,13,54,111,42}; 
        sort.sort(ar); 
        System.out.println("Sorted array"); 
        sort.arrayPrint(ar); 
    } 
}
