  
class Node:    
    def __init__(self,data):    
        self.data = data;    
        self.next = None;    
     
class CreateList:    
  
    def __init__(self):    
        self.head = Node(None);    
        self.tail = Node(None);    
        self.head.next = self.tail;    
        self.tail.next = self.head;    
        

    def add(self,data):    
        newNode = Node(data);    
    
        if self.head.data is None:    
            #If list is empty, both head and tail would point to new node.    
            self.head = newNode;    
            self.tail = newNode;    
            newNode.next = self.head;    
        else:    
           
            self.tail.next = newNode;    
            #New node will become new tail.    
            self.tail = newNode;    
            #Since, it is circular linked list tail will point to head.    
            self.tail.next = self.head;    
                
   
    def minNode(self):    
        current = self.head;    
        #Initializing min to initial node data    
        minimum = self.head.data;    
        if(self.head == None):    
            print("List is empty");    
        else:    
            while(True):    
                 
                if(minimum > current.data):    
                    minimum = current.data;    
                current= current.next;    
                if(current == self.head):    
                    break;    
        print("Minimum value node in the list: "+ str(minimum));    
     
     
    def maxNode(self):    
        current = self.head;    
        #Initializing max to initial node data    
        maximum = self.head.data;    
        if(self.head == None):    
            print("List is empty");    
        else:    
            while(True):    
              
                if(maximum < current.data):    
                    maximum = current.data;    
                current= current.next;    
                if(current == self.head):    
                    break;    
        print("Maximum value node in the list: "+ str(maximum));    
     
class CircularLinkedList:    
    cl = CreateList();    
    #Adds data to the list    
    cl.add(5);    
    cl.add(20);    
    cl.add(10);    
    cl.add(1);    
 
    cl.minNode();    
   
    cl.maxNode();    
