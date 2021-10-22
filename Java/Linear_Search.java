public class Linear_Search {

    public static int search_Linear(int ar[], int x) {

    int n = ar.length; 
    for(int i = 0; i < n; i++) { 
        if(ar[i] == x) 
            return i; 
    } 
    return -1; 
    } 

    // main method
    public static void main(String[] args) { 
    int ar[] = { 21, 83, 26, 94, 65 };  
    int x = 26; 
      
    int result = search_Linear(ar, x); 
    if(result == -1) 
        System.out.print("Element is not present in array"); 
    else
        System.out.print("Element is present at index " + result); 
    } 
}
