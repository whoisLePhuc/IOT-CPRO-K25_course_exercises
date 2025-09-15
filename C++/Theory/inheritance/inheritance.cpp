#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    string name;
    Animal(string n) : name(n) {} // Constructor
    void eat(){ 
        cout << name << " is eating." << endl; 
    }    
};

class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {} // Constructor
    void bark(){ 
        cout << name << " is barking." << endl;
    }
};

class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {} // Constructor
    void meow(){ 
        cout << name << " is meowing." << endl; 
    }
};

int main(){
    Dog dog("Buddy");
    Cat cat("Whiskers");

    dog.eat();
    dog.bark();

    cat.eat();
    cat.meow();
    
    return 0;
}