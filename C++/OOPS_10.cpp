
// ENCAPSULATION

#include<iostream>
using namespace std;

class Student {

    private:
        string name;
        int age;
        int height;

    public:
    int getAge() {
        return this->age;
    }
};

int main(){
    
    Student first;

    cout << "Sab sahi chal raha hai" << endl;

    return 0;
}