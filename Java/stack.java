import java.util.*;
public class stack
{
	public static void main(String[] args)
	{
		Stack<Integer> list =new Stack();
		list.push(1);
		list.push(22);
		list.push(3);
		list.push(44);
		System.out.println(list);
		Collections.sort(list);
		System.out.println(list);
		System.out.println(list.peek());
		list.pop();
		System.out.println(list);
		System.out.println(list.empty());
		
		
		
	}
}
		
		
		