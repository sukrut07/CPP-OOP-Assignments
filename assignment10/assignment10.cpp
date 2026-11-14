#include <iostream>
#include <string>

using namespace std;

// ==========================================
// 1. FUNCTION TEMPLATES
// ==========================================

// Function template to swap two variables of any type
template <typename T>
void swapValues(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Function template to sort an array using Bubble Sort
template <typename T>
void sortArray(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swapValues(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function template to display an array
template <typename T>
void displayArray(const T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ==========================================
// 2. CLASS TEMPLATE
// ==========================================

// Class template for basic arithmetic operations on any numeric type
template <class T>
class Calculator {
private:
    T num1, num2;

public:
    Calculator(T n1, T n2) : num1(n1), num2(n2) {}

    T add() const { return num1 + num2; }
    T subtract() const { return num1 - num2; }
    T multiply() const { return num1 * num2; }
    
    T divide() const {
        if (num2 == 0) {
            cout << "Error: Division by zero! Returning 0. ";
            return 0;
        }
        return num1 / num2;
    }

    void displayResults() const {
        cout << "Numbers: " << num1 << " and " << num2 << endl;
        cout << "Addition: " << add() << endl;
        cout << "Subtraction: " << subtract() << endl;
        cout << "Multiplication: " << multiply() << endl;
        cout << "Division: " << divide() << endl;
    }
};

// ==========================================
// MAIN DRIVER CODE
// ==========================================

int main() {
    cout << "=== PART 1: FUNCTION TEMPLATE DEMONSTRATION ===\n";

    // Sorting an integer array
    int intArr[] = {45, 12, 89, 3, 27};
    int intSize = 5;
    cout << "\nOriginal Integer Array: ";
    displayArray(intArr, intSize);
    sortArray(intArr, intSize);
    cout << "Sorted Integer Array:   ";
    displayArray(intArr, intSize);

    // Sorting a floating-point array
    float floatArr[] = {4.5f, 1.2f, 8.9f, 0.3f};
    int floatSize = 4;
    cout << "\nOriginal Float Array:   ";
    displayArray(floatArr, floatSize);
    sortArray(floatArr, floatSize);
    cout << "Sorted Float Array:     ";
    displayArray(floatArr, floatSize);

    // Swapping strings
    string s1 = "World", s2 = "Hello";
    cout << "\nBefore Swap: s1 = " << s1 << ", s2 = " << s2 << endl;
    swapValues(s1, s2);
    cout << "After Swap:  s1 = " << s1 << ", s2 = " << s2 << endl;

    cout << "\n=== PART 2: CLASS TEMPLATE DEMONSTRATION ===\n";

    // Calculator object for integers
    cout << "\n--- Integer Calculator ---" << endl;
    Calculator<int> intCalc(20, 4);
    intCalc.displayResults();

    // Calculator object for doubles
    cout << "\n--- Double Calculator ---" << endl;
    Calculator<double> doubleCalc(15.5, 2.5);
    doubleCalc.displayResults();

    return 0;
}
