#include <iostream>
#include <string>
using namespace std;

// Function Overloading
class calculator {
    public:
        // Methods with same name but different parameters
        int add(int a, int b) {
            cout << "int add(int, int) called" << endl;
            return a + b;
        }
        double add(double a, double b) {
            cout << "double add(double, double) called" << endl;
            return a + b;
        }
        int add(int a, int b, int c) {
            cout << "int add(int, int, int) called" << endl;
            return a + b + c;
        }
};

// Operator Overloading
class Vector {
    public:
        int x, y;
        // Constructor
        Vector(int x, int y) : x(x), y(y)   {}

        // Method to overload + operator
        Vector operator+ (const Vector& v) {
            return Vector(x + v.x, y + v.y);
        }
};

int main() {
    calculator calc;
    // Test function overloading
    calc.add(2,3);
    calc.add(2.5, 3.5);
    calc.add(1,2,3);

    // Test operator overloading
    Vector v1(1,2), v2(3,4);
    Vector v3 = v1 + v2;
    cout << "v3: (" << v3.x << ", " << v3.y << ")" << endl;

    return 0;
}