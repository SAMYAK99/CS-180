// Github username: Priyangshu1711
// Aim: To check if any the given String with parentheses, has valid parentheses or not .
//Data Structure Used: ~STACK~ 
//Time complexity: O(n)
//Space complexity: O(n)
// Date: 08/10/2022

                                 // **************************************************************** //

import java.util.Stack;// to use the Stack class from the util package.
import java.util.Scanner; 

class Valid_Parentheses {
        public  boolean isValid(String s) {
            // creating object for the Stack class. here st.
            Stack<String> st = new Stack<String>();
            // making a character array of the string. 
            for (char c : s.toCharArray()){
                String cc = String.valueOf(c);
                // to check if the parantheis begun.
                if(c=='{'|| c=='['|| c =='('){
                    st.push(cc);
                }
                else{
                    // if the input is empty then returns false.
                    if(st.empty())return false;
                    char top  = st.peek().toCharArray()[0];
                    //if the input has any other chatacters except parantheses then ignores and continues.
                    if(c!='{' && c!='[' && c !='(' && c != '}' && c!= ']' && c!= ')' ){
                        continue;
                    }
                    // to check if the parentheses is closed respectively *
                    if((top == '{' && c == '}') ||
                      (top == '[' && c== ']') ||
                      (top == '(' && c== ')')){
                      // * if yes then we will go on popping it from stack until its empty.
                      st.pop() ; 
                    }
                    // if the algorithm couldn't remove all the parentheses from the stack then returns false *
                    else return false;
                }
            }
            // * but if it could remove all the parentheses from the stack then returns true.
            return st.empty();
                
        }
        // the main function
         public static void main(String ...args ){
            //creating object for the Valid_Parentheses class 
            
            Valid_Parentheses obj = new Valid_Parentheses();
            System.out.println("enter a valid string with parentheses eg-[{[helloworld])}] : ");
            try (Scanner sc = new Scanner (System.in)) {
                // taking the returned boolean value in flag. 
                boolean flag = obj.isValid(sc.nextLine());
                // if the flag was flase then prints false * 
                if(flag==true){
                System.out.println("True");
                }
                // *else true. 
                else{
                System.out.println("False");}
            }
        }
            
}
                                     // **************************************************************** //

