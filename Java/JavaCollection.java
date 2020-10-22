// Java code for stack 
import java.io.*; 
import java.util.*; 

public class JavaCollection 
{ 
    //push
	static void stack_push(Stack<Integer> stack) 
	{ 
		for(int i = 0; i < 5; i++) 
		{ 
			stack.push(i); 
		} 
	} 
	
	// Pop 
	static void stack_pop(Stack<Integer> stack) 
	{ 
		System.out.println("Poping :"); 

		for(int i = 0; i < 5; i++) 
		{ 
			Integer x = (Integer) stack.pop(); 
			System.out.println(x); 
		} 
	} 

	// top of the stack 
	static void stack_peek(Stack<Integer> stack) 
	{ 
		Integer element = (Integer) stack.peek(); 
		System.out.println("Element on stack top: " + element); 
	} 
	

	public static void main (String[] args) 
	{ 
		Stack<Integer> stack = new Stack<Integer>(); 

		stack_push(stack); 
		stack_pop(stack); 
		stack_push(stack); 
		stack_peek(stack); 
		
	} 
} 
