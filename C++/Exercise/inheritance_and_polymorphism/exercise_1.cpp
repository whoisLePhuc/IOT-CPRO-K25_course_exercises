#include <iostream>
#include <string>   
using namespace std;

class Person{
public:
    string name;
    int age;
    // Constructor
    Person(string n, int a) : name(n), age(a) {}
    // Method to display person information
    void showInfo(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person {
public:
    int id;
    // Constructor
    Student(string n, int a, int i) : Person(n, a), id(i) {}
    // Method to display student information
    void showInfo(){
        Person::showInfo(); // Call base class method
        cout << "ID: " << id << endl;
    }   
};

int main(){
    Person person("Alice", 30);
    person.showInfo();

    cout << "------------------" << endl;

    Student student("Bob", 20, 1001);
    student.showInfo();

    return 0;
}