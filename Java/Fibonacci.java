import java.util.*;
class recursion{
    static int fibo(int n)  //using recursion
    {
        if(n<=1){
            return n;
        } 
        else{
            return fibo(n-1) + fibo(n-2);
            
        }
        
    }
    
     static void main(String[] args) {
        int n=9;
        int c=0;
        System.out.println("Sum "+fibo(n)); //prints sum
        for(int i=1;i<=n;i++){
            System.out.println(fibo(c)); // prints the series 
            c++;
        }
    }
}