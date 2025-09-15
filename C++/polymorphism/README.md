# Polymorphism in C++

Polymorphism in C++ is the ability to have **one interface with multiple implementations**.  
This makes the code **flexible, extensible**, and helps **reduce `if/else` or `switch-case` usage**.

There are two main types:

---

## 1. Compile-time polymorphism
Also known as **static polymorphism**.  
The decision of which function to call is made **at compile time**.

### How it is achieved
- **Function overloading**: multiple functions with the same name but different parameters.
- **Operator overloading**.
- **Templates**.

### Example
```cpp
#include <iostream>
using namespace std;

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }
};

int main() {
    Calculator c;
    cout << c.add(2, 3) << endl;      // Calls add(int, int)
    cout << c.add(2.5, 3.1) << endl;  // Calls add(double, double)
    return 0;
}
```

👉 The compiler resolves which function to call during compilation.

---

## 2. Run-time polymorphism
Also known as **dynamic polymorphism**.  
The decision of which function to call is made **at runtime**.

### How it is achieved
- Using **virtual functions** in the base class.
- Managing derived objects via **base class pointers or references**.

### Example
```cpp
#include <iostream>
#include <vector>
using namespace std;

class Vehicle {
public:
    virtual void move() {
        cout << "Vehicle is moving" << endl;
    }
    virtual ~Vehicle() {} // Virtual destructor to avoid memory leaks
};

class Car : public Vehicle {
public:
    void move() override {
        cout << "Car is driving" << endl;
    }
};

class Bike : public Vehicle {
public:
    void move() override {
        cout << "Bike is cycling" << endl;
    }
};

class Bus : public Vehicle {
public:
    void move() override {
        cout << "Bus is running" << endl;
    }
};

int main() {
    // List of vehicles, all stored as Vehicle pointers
    vector<Vehicle*> vehicles = { new Car(), new Bike(), new Bus() };

    for (auto v : vehicles) {
        v->move();  // Automatically calls the correct function
    }

    // Free memory
    for (auto v : vehicles) {
        delete v; // Calls the correct destructor + frees heap memory
    }
    return 0;
}
```

### Why is it useful?
- Without run-time polymorphism, you would need lots of `if/else`:
  ```cpp
  for (auto v : vehicles) {
      if (typeid(*v) == typeid(Car)) { ... }
      else if (typeid(*v) == typeid(Bike)) { ... }
      else if (typeid(*v) == typeid(Bus)) { ... }
  }
  ```
- With **virtual functions**, you just call `v->move()` and C++ automatically chooses the right one → cleaner, more extensible code when new `Vehicle` types are added.

---

## 3. Key differences

| Feature          | Compile-time polymorphism            | Run-time polymorphism          |
|------------------|--------------------------------------|--------------------------------|
| Decision time    | Compile time                         | Run time                       |
| Techniques       | Function/Operator overloading, Template | Virtual functions, Inheritance |
| Performance      | Faster (no virtual table lookup)     | Slightly slower (uses **vtable**) |
| Flexibility      | More limited                         | Highly flexible, easily extensible |

---

## 4. Note on `delete` vs manual destructor call

- `delete v;` → calls the correct destructor **and** frees heap memory.  
- `v->~Vehicle();` → only calls the destructor, **does not free memory**, leading to leaks.  
- Always use `delete` (except when manually managing memory with `placement new`).

---
