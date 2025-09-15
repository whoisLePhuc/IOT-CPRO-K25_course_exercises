#include <iostream>
#include <vector>
using namespace std;

class Vehicle {
public:
    virtual void move (){
        cout << "Vehicle is moving" << endl;
    }
    virtual ~Vehicle() {}
};

// Class car inherits from Vehicle
class Car : public Vehicle {
public:
    void move() override {
        cout << "Car is driving" << endl;
    }    
};

// Class bike inherits from Vehicle
class Bike : public Vehicle {
public:
    void move() override {
        cout << "Bike is pedaling" << endl;
    }        
};

// Class truck inherits from Vehicle
class Truck : public Vehicle {
public:
    void move() override {
        cout << "Truck is hauling" << endl;
    }
};

int main() {
    vector<Vehicle*> vehicles { new Car(), new Bike(), new Truck() };
    for (auto v : vehicles) {
        v->move(); // Calls the appropriate move() method based on the object type
    }

    for (auto v : vehicles){
        delete v; // Clean up
    }
}