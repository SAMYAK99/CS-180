import java.util.*; 
import java.util.Collections; 

public class Bucket_Sort {

    static void bucketSort(float arr[], int n) 
    { 
        if (n <= 0) 
            return; 
  
        @SuppressWarnings("unchecked") 
        Vector<Float>[] buckets = new Vector[n]; 
  
        for (int i = 0; i < n; i++) { 
            buckets[i] = new Vector<Float>(); 
        } 

        for (int i = 0; i < n; i++) { 
            float idx = arr[i] * n; 
            buckets[(int)idx].add(arr[i]); 
        }

        for (int i = 0; i < n; i++) { 
            Collections.sort(buckets[i]); 
        } 

        int index = 0; 
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < buckets[i].size(); j++) { 
                arr[index++] = buckets[i].get(j); 
            } 
        } 
    } 

    // main method
    public static void main(String args[]) 
    { 
        float arr[] = { (float)0.17, (float)0.866, 
                        (float)0.34, (float)0.986, 
                        (float)0.675, (float)0.655}; 
  
        int n = arr.length; 
        bucketSort(arr, n); 
  
        System.out.println("Sorted array is "); 
        for (float el : arr) { 
            System.out.print(el + " "); 
        } 
    } 
}
