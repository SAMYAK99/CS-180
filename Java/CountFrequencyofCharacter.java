// header files
import java.util.Scanner;

public class Program6
{
	public static void main(String[] args) {
	    
	    // using scanner class for taking input from user
        Scanner sc = new Scanner(System.in);
	    
	    // declare varible
	    int count = 0;
	    
        
	    System.out.print("Enter the word: ");    
        
        // taking input string word from user
        String word = sc.next();  
        
        // Converts all letter into Upper Case
        String s1 = word.toUpperCase();
        
        System.out.print("Enter a character: ");
        
        // taking input character from user
        char character = sc.next().charAt(0);
        
        // Converts Character into Upper case
	    char ch = Character.toUpperCase(character);
	    
	    //Converts given string word into character array str 
	    char str[] = s1.toCharArray();  
	    
	    // loop for traverse the string word
	    for(int i=0;i<word.length();i++)
        {
            // check character in word 
            if(ch==str[i]){
                // count the character in the given word
                count++;
            }
        }	    
	    
        // display output
        System.out.println("The letter "+ character + " appears in the word " + word + " " + count + " times");

	}
}
