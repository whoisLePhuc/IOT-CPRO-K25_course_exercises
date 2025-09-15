#include <iostream>
#include <string>
using namespace std;

class Vehicle {
    public:
    string brand;
    Vehicle(string b) : brand(b) {}
    void showInfo() {
        cout << "Brand: " << brand << endl;
    }
};

class Car : public Vehicle {
    public:
        int model;
        Car(string b, int m) : Vehicle(b), model(m) {}
        void showInfo() {
            Vehicle::showInfo(); // Call base class method
            cout << "Model: " << model << endl;
        }
};

class ElectricCar : public Car {
    public:
        int batteryCapacity;
        ElectricCar(string b, int m, int bc) : Car(b, m), batteryCapacity(bc) {}
        void showInfo() {
            Car::showInfo(); // Call base class method
            cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
        }    
};

int main() {
    Vehicle vehicle("Toyota");
    vehicle.showInfo();

    cout << "------------------" << endl;

    Car car("Honda", 2020);
    car.showInfo();

    cout << "------------------" << endl;

    ElectricCar electricCar("Tesla", 2021, 100);
    electricCar.showInfo();

    return 0;
}