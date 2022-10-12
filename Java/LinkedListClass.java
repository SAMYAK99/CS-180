class Node{
    Node next;
    Node prev;
    int data = -1;
    Node(int data){
        this.data = data;
        this.next = null;
        this.prev = null;
    }
    Node(){
        this.next = null;
        this.prev = null;
    }
}

class MyLinkedList{
    int size = 0;
    Node head;
    public MyLinkedList() {
        head = new Node();
        size = 1;
    }

    public int get(int index) {

        int i = 0;

        Node curr = head;

        while (curr != null){
            if (i == index){
                return curr.data;
            }
            else {
                i++;
                curr = curr.next;
            }
        }

        return -1;

    }

    public void addAtHead(int val) {

        Node nodeToBeAdded = new Node(val);
        if (head.next == null && head.data == -1){
            head.data = val;
        }
        else {
            nodeToBeAdded.next = head;
            head.prev = nodeToBeAdded;
            head = nodeToBeAdded;
            size++;
        }

    }

    public void addAtTail(int val) {

        Node nodeToAdd = new Node(val);
        Node curr = head;
        if (head.next == null && head.data == -1){
            head.data = val;
        }
        else {
            while (curr.next != null) {
                curr = curr.next;
            }
            curr.next = nodeToAdd;
            nodeToAdd.prev = curr;
            size++;
        }
    }

    public void addAtIndex(int index, int val) {

        int i = 0;

        Node curr = head;
        Node toBeAdded = new Node(val);

        if (index == 0){
            if (head.next == null && head.data == -1){
                head.data = val;
            }
            else {
                toBeAdded.next = head;
                head.prev = toBeAdded;
                head = toBeAdded;
                size++;
            }
            return;
        }
        while (curr != null) {
            if (i == index-1) {
                Node addr = curr.next;
                curr.next = toBeAdded;
                toBeAdded.prev = curr;
                toBeAdded.next = addr;
                size++;
                return;
            } else {
                i++;
                curr = curr.next;
            }
        }
    }

    public void deleteAtIndex(int index) {

        int i = 0;

        Node curr = head;

        if (index == 0){
            head = head.next;
            return;
        }

        while (curr != null) {
            if (i == index-1 && index<size) {
                curr.next = curr.next.next;
                if (curr.next!=null){
                    curr.next.prev = curr;
                }
                size--;
                return;
            } else {
                i++;
                curr = curr.next;
            }
        }
    }
}
