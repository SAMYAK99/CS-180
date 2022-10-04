//#include<iostream>
//#include<string>
//
//
//
//struct node {           // struct to make node 
//	char data;           //declaring data members 
//	node* next;
//};
//class StackLL {           //ADT for stack using linked list 
//	node* top;
//public:
//	StackLL()           // initially initialize top to NULL
//	{
//		top = NULL;
//	}
//	void Push(char elem)                 //function to push element into stack 
//	{
//		node* newnode = new node;               //intialize newnodedata to elem and next to NULL 
//		newnode->data = elem;
//		newnode->next = NULL;
//		if (top == NULL)        //if list is empty make the newnode top of the list 
//		{
//			top = newnode;
//			return;
//		}
//		else            //if list is not empty traverse to the last of the list and insert a newnode 
//		{
//			node* curr = new node;
//			curr = top;
//
//			while (curr->next != NULL)
//			{
//				curr = curr->next;
//			}
//			curr->next = newnode;
//			curr = newnode;
//			return;
//		}
//
//	}
//	char Pop()                //function to remove an element 
//	{
//		if (top != NULL)    //if list is not empty 
//		{
//			char d;                 // make a copy of the top element 
//			node* curr = new node;
//			curr = top;
//			top = top->next;             //move the top forward and delete the previous top 
//			d = curr->data;
//			delete curr;
//			curr = NULL;
//
//			return d;
//		}
//		return 0;
//	}
//	bool IsEmpty()
//	{
//		if (top == NULL)      //if top is NULL then list is empty 
//		{
//			return true;
//		}
//
//		return false;
//	}
//
//	void display()
//	{
//		node* curr = new node;          //displaying the list using loop
//		curr = top;
//
//		while (curr)
//		{
//			std::cout << curr->data << " ";
//			curr = curr->next;
//		}
//	}
//
//};
//
//int main()
//{
//
//	std::string str1;              //declaring string for input 
//
//	while (1)
//	{
//		getline(std::cin, str1);               // take input in string 
//
//		StackLL s1, s2;
//
//		for (int i = 0; i < str1.length(); i++)                   //push string in correct order in one stack 
//		{
//			s1.Push(str1[i]);
//		}
//
//		for (int i = str1.length() - 1; i >= 0; i--)    // push string in reverse order in second stack 
//		{
//			s2.Push(str1[i]);
//		}
//
//		bool c = false;
//
//		for (int i = 0; i < str1.length(); i++)      //If palindrome both popped elements should be same 
//		{
//			char c1 = s1.Pop();
//			char c2 = s2.Pop();
//			if (c1 == c2)
//			{
//				c = true;
//			}
//			else
//			{
//				std::cout << "Not a palindrome" << std::endl;  //if not same no need to check other elements not a palindrome 
//				break;
//			}
//
//		}
//
//		if (c == true)      //if each element is same then palindrome 
//		{
//			std::cout << "Palindrome" << std::endl;
//		}
//
//	}
//
//
//
//	return 0;
//}