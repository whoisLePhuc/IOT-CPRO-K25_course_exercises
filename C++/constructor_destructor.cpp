#include <iostream>
#include <string>
using namespace std;

class Student{
    private:
        string name;
        int age;
        int id;
    public:
        // Constructor
        Student(string n, int a, int i){
            name = n;
            age = a;
            id = i;
            cout << "Student " << name << " (ID: " << id << ") is created." << endl;
        }
        // Method to display student information
        void showInfo(){
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "ID: " << id << endl;
        }
        // Destructor
        ~Student(){
            cout << "Student " << name << " (ID: " << id << ") is destroyed." << endl;
        }
};

int main(){
    {
        Student s1("Alice", 20, 1001);
        s1.showInfo();
    }
    // s1 goes out of scope here and destructor is called
    Student s2("Bob", 22, 1002);
    s2.showInfo();

    return 0;
}