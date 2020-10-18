public class Counting_Sort {
    void count_Sort(char ar[]) { 
        int n = ar.length; 
  
        char output[] = new char[n]; 
  
        int count[] = new int[256]; 
        for (int i = 0; i < 256; ++i) {
            count[i] = 0; 
        }
  
        for (int i = 0; i < n; ++i) {
            ++count[ar[i]]; 
        }
  
        for (int i = 1; i <= 255; ++i) { 
            count[i] += count[i - 1]; 
        }
   
        for (int i = n - 1; i >= 0; i--) { 
            output[count[ar[i]] - 1] = ar[i]; 
            --count[ar[i]]; 
        } 
  
        for (int i = 0; i < n; ++i) {
            ar[i] = output[i]; 
        }
    } 
  
    // main method
    public static void main(String[] args) 
    { 
        Counting_Sort sort = new Counting_Sort(); 
        char ar[] = { 'h', 'a', 'c', 't', 'o', 'b', 'e', 
                       'r', 'f', 'e', 's', 't'}; 
  
        sort.count_Sort(ar); 
  
        System.out.print("Sorted character array is "); 
        for (int i = 0; i < ar.length; ++i) {
            System.out.print(ar[i]); 
        }
    } 
}
