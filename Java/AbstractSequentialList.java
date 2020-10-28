// Java code to hacktoberfest
// methods of AbstractSequentialList 

import java.util.*; 
import java.util.AbstractSequentialList; 

public class AbstractSequentialList { 
	public static void main(String args[]) 
	{ 

		// Creatie an empty AbstractSequentialList as demoList 
		AbstractSequentialList<String> demoList = new LinkedList<String>(); 

		// add elements in the list 
		demoList.add("Hacktoberfest"); 
		demoList.add("2020"); 
		demoList.add("Kavindu"); 
		demoList.add("github"); 
		demoList.add("contribution"); 

		// see the list, demoList
		System.out.println("AbstractSequentialList demoList is : "+ demoList); 

    // Remove from the demoList
    demoList.remove(0); 
    demoList.remove(3);
    demoList.remove(4); 

		// Print the final list after removings
		System.out.println("Final List: "+ demoList); 

		// Fetching the specific element from the list -> use get() method 
		System.out.println("The fetching element is : "+ demoList.get(2)); 
	} 
} 
