import java.io.*;
import java.util.*;

class SortingArr_UsingStack {
    static Stack<Integer> sortStack(Stack<Integer> input) {
        Stack<Integer> tmpStack = new Stack<Integer>();

        while (!input.empty()) {
            int tmp = input.peek();
            input.pop();
            while (!tmpStack.empty() && tmpStack.peek() < tmp) {
                input.push(tmpStack.peek());
                tmpStack.pop();
            }

            tmpStack.push(tmp);
        }
        return tmpStack;
    }

    static void sortArrayUsingStacks(int []ar,  
                                     int n) 
    { 
        Stack<Integer> input =  
                        new Stack<Integer>(); 
        for (int i = 0; i < n; i++) 
            input.push(ar[i]); 

        Stack<Integer> tmpStack =  
                    sortStack(input); 
                    
        for (int i = 0; i < n; i++) { 
            ar[i] = tmpStack.peek(); 
            tmpStack.pop(); 
        } 
    }      
    // main method
    public static void main(String[] args) { 
        int []ar = {10, 5, 15, 45}; 
        int n = ar.length; 
      
        sortArrayUsingStacks(ar, n); 
      
        for (int i = 0; i < n; i++) 
            System.out.print(ar[i] + " "); 
    }     
}
        