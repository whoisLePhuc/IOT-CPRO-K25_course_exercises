#include <iostream>
#include <string>
using namespace std;

class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a rectangle" << endl;
    }
};

class Triangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a triangle" << endl;
    }
};

void printShape(Shape* shape) {
    shape->draw();
}

int main() {
    Shape* shapes[] = { new Circle(), new Rectangle(), new Triangle() };
    
    for (Shape* shape : shapes){
        printShape(shape);
        delete shape; // Clean up
    }
}
