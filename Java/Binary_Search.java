public class Binary_Search {
    
    int binarySearch(int ar[], int l, int a, int x) 
    { 
        if (a >= l) { 
            int mid = l + (a - l) / 2; 
  
            // If the element is present at the middle
            if (ar[mid] == x) 
                return mid; 
  
            // If element is smaller than mid, then it can only be present in left subarray 
            if (ar[mid] > x) 
                return binarySearch(ar, l, mid - 1, x); 
  
            // Else the element can only be present in right subarray 
            return binarySearch(ar, mid + 1, a, x); 
        }
        // We reach here when element is not present in array 
        return -1; 
    }
    // main method 
    public static void main(String[] args) { 
        Binary_Search search = new Binary_Search(); 
        int ar[] = { 21, 31, 46, 71, 81 }; 
        int n = ar.length; 
        int x = 71; 
        int result = search.binarySearch(ar, 0, n - 1, x); 
        if (result == -1) 
            System.out.println("Element not present"); 
        else
            System.out.println("Element found at index " + result); 
    } 

}
