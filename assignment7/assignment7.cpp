#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// ========================================================
// 1. COMPILE-TIME POLYMORPHISM (Function & Operator Overloading)
// ========================================================

class Complex {
private:
    double real, imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Operator Overloading (+)
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

class AreaCalculator {
public:
    // Function Overloading: Area of Circle
    double calculateArea(double radius) const {
        return 3.14159 * radius * radius;
    }

    // Function Overloading: Area of Rectangle
    double calculateArea(double length, double breadth) const {
        return length * breadth;
    }
};

// ========================================================
// 2. RUN-TIME POLYMORPHISM (Virtual Functions & Overriding)
// ========================================================

// Abstract Base Class
class Shape {
protected:
    string name;

public:
    Shape(const string& shapeName) : name(shapeName) {}

    // Pure virtual function enforcing interface in derived classes
    virtual double area() const = 0;

    // Virtual function for dynamic dispatch
    virtual void displayInfo() const {
        cout << "Shape: " << name << " | Area: " << area() << endl;
    }

    // Virtual destructor for safe cleanup via base pointer
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : Shape("Circle"), radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) : Shape("Rectangle"), length(l), width(w) {}

    double area() const override {
        return length * width;
    }
};

// ========================================================
// MAIN DRIVER CODE
// ========================================================

int main() {
    cout << "=== PART 1: COMPILE-TIME POLYMORPHISM ===\n";

    // 1a. Function Overloading
    AreaCalculator calc;
    cout << "Function Overloading (Circle r=5):       " << calc.calculateArea(5.0) << endl;
    cout << "Function Overloading (Rectangle 4x6):    " << calc.calculateArea(4.0, 6.0) << endl;

    // 1b. Operator Overloading
    Complex c1(3.5, 2.5), c2(1.5, 4.5);
    Complex c3 = c1 + c2;
    cout << "\nOperator Overloading (Complex Addition):\n";
    cout << "c1 = "; c1.display();
    cout << "c2 = "; c2.display();
    cout << "c1 + c2 = "; c3.display();

    cout << "\n=== PART 2: RUN-TIME POLYMORPHISM ===\n";

    // Base class pointers pointing to derived class objects
    Shape* shapes[2];
    shapes[0] = new Circle(7.0);
    shapes[1] = new Rectangle(5.0, 8.0);

    // Dynamic binding resolves area() at runtime
    for (int i = 0; i < 2; ++i) {
        shapes[i]->displayInfo();
    }

    // Free dynamically allocated memory
    for (int i = 0; i < 2; ++i) {
        delete shapes[i];
    }

    return 0;
}