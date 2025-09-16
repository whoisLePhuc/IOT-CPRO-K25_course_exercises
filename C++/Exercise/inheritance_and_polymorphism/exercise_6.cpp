#include <iostream>
#include <string>
using namespace std;

class Employee {
    protected:
        string name;
        int age;
        int slary;
    public:
        Employee(string n, int a, int s) : name(n), age(a), slary(s) {}
        virtual ~Employee() {}
        virtual void calculateSalary() = 0; // Pure virtual function
        virtual void displayInfo() {
            cout << "Name: " << name << ", Age: " << age << ", Salary: " << slary;
        }
};

class Developer : public Employee {
    private:
        int bonux;
    public:
        Developer(string n, int a, int s, int b) : Employee(n, a, s), bonux(b) {}
        void calculateSalary() override {
            slary += bonux;
        }
        void displayInfo() override {
            Employee::displayInfo();
            cout << ", Role: Developer, Bonus: " << bonux << endl;
        }
        ~Developer() {}
};

class Manager : public Employee {
    private:
        int teamSize;
    public:
        Manager(string n, int a, int s, int t) : Employee(n, a, s), teamSize(t) {}
        void calculateSalary() override {
            slary += teamSize * 100; // Example: each team member adds 100 to salary
        }
        void displayInfo() override {
            Employee::displayInfo();
            cout << ", Role: Manager, Team Size: " << teamSize << endl;
        }
        ~Manager() {}
};

int main() {
    Employee* employees[] = {
        new Developer("Alice", 30, 5000, 500),
        new Manager("Bob", 40, 7000, 5)
    };

    for (Employee* emp : employees) {
        emp->calculateSalary();
        emp->displayInfo();
        delete emp; // Clean up
    }

    return 0;
}


