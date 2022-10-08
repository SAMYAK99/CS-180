#include <iostream>
#define n 20

using namespace std;

class queue
{
    int *arr;
    int front;
    int back;

public:
    queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void push(int x)  // enqueue
    {
        if (back == n - 1)
        {
            cout << "queue overflow" << endl;
            return;
        }

        back++;
        arr[back] = x;

        if (front == -1)
        {
            front++;
        }
    }

    void pop()  //dequeue
    {
        if (front == -1 || front > back)
        {
            cout << "no element to remove" << endl;
            return;
        }

        front++;
    }

    int peek() 
    {
        if (front == -1 || front > back)
        {
            cout << "no element to peek()" << endl;
            return -1;
        }

        return arr[front];
    }

    bool empty()
    {
        if (front == -1 || front > back)
        {
            return true;
        }

        return false;
    }
};

int main()
{

    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << q.peek() << endl;
    q.pop();

    cout << q.peek() << endl;
    q.pop();

    cout << q.peek() << endl;
    q.pop();

    cout << q.peek() << endl;
    q.pop();

    cout << q.empty() << endl;

    return 0;
}

// ----- Time Complexity ------
// Enqueue- O(N) worst case, O(1) best case, O(1) average case
// Dequeue- O(1)
// Display- O(N)

// ------ Space Complexity -------
// O(1), constant for queue using array.
