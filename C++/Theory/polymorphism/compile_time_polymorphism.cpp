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

class Subtracting {
public:
    int x, y;
    // Constructor
    Subtracting(int a, int b) : x(a), y(b) {}
    // Method to overload - operator
    Subtracting operator- (const Subtracting& v){
        return Subtracting( x - v.x, y - v.y);
    }
};

// Template
template <typename T>
class Box{
private:
    T value;
public:
    //Constructor
    Box(T v) : value(v) {}
    // Method to get value
    T getValue() { return value; }
};

int main() {
    calculator calc;
    // Test function overloading
    calc.add(2,3);
    calc.add(2.5, 3.5);
    calc.add(1,2,3);

    // Test operator + overloading
    Vector v1(1,2), v2(3,4);
    Vector v3 = v1 + v2;
    cout << "v3: (" << v3.x << ", " << v3.y << ")" << endl;

    Subtracting s1(-5,7), s2(-2,3);
    Subtracting s3 = s1 - s2;
    cout << "s3: (" << s3.x << ", " << s3.y << ")" << endl;

    // Test template
    Box<int> b1(123);
    Box<string> b2("Hello");
    cout << "Box b1 contains: " << b1.getValue() << endl;
    cout << "Box b2 contains: " << b2.getValue() << endl;

    return 0;
}