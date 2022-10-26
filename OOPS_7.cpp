
// SHALLOW AND DEEP 


#include<iostream>
#include<string.h>
using namespace std;

class Hero {
    
    // properties
    private:
    int health;

    public:
    char level;
    char *name;

    // Constructor
    Hero() {
        cout << "Constructor called " << endl;
        name = new char[100];
    }

    // Paramterised constructor
    Hero(int health) {
        cout << "this -> " << this <<endl;
        this -> health = health;
    }

    Hero(int health, char level) {
        this -> level = level;
        this -> health = health;
    }

    // Copy constructor
    Hero (Hero& temp) {

        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;
        
        cout<<"Copy constructor called " << endl;
        this->health = temp.health;
        this->level = temp.level;
    }

    void print(){
        cout<< endl;
        cout << "Name is: " << this->name << endl;
        cout << "Health is: " << this->health << endl;
        cout << "Level is: " << this->level << endl;
        cout<< endl;
    }

    int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }

    void setHealth(int h) {
        health = h;
    }

    void setLevel(char ch) {
        level = ch;
    }

    void setName(char name[]) {
        strcpy(this->name, name);
    }

};

int main(){

    Hero hero1;
    hero1.setHealth(12);
    hero1.setLevel('D');
    char name[7] = "Nikhil";
    hero1.setName(name);

    Hero hero2(hero1);

    hero1.name[0] = 'G';
    hero1.print();
    hero2.print();

    hero1 = hero2;
    hero1.print();
    hero2.print();
    return 0;
}

