#include<conio.h>
#include<iostream>

using namespace std;

class ArrayList
{
private:
    struct ControlBlock
    {
        int capacity;
        int *arr_ptr;
    };
    ControlBlock *s;

public:
    ArrayList(int capacity)
    {
        s = new ControlBlock;
        s->capacity = capacity;
        s->arr_ptr = new int[s->capacity];
    }
    void addElement(int index, int data)
    {
        if(index>=0 && index<=s->capacity-1){
            s->arr_ptr[index]=data;
        }else{
        cout<<"\nArray is not valid";
        }
    }
    void viewElement(int index, int &data)
    {
        if(index>=0 && index<=s->capacity-1)
        {
            data=s->arr_ptr[index];
        }else{
            cout<<"\nArray index is not valid";
        }
    }
};

int main()
{
    int data;
    ArrayList list1(4);
    list1.addElement(0,32);
    list1.viewElement(0,data);
    cout<<data;
}
