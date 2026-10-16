#include <iostream>
using namespace std;

// Function demonstrating Call by Reference
void changeValue(int &x)
{
    x = x + 10;
}

// Function demonstrating Pointer (Call by Address)
void changeUsingPointer(int *ptr)
{
    if (ptr != nullptr)
    {
        *ptr = *ptr + 20;
    }
}

int main()
{
    // ==================================================
    // PART A: REFERENCES AND POINTERS
    // ==================================================

    // 1. Reference
    int num = 10;
    int &ref = num;

    cout << "===== 1. REFERENCE =====" << endl;
    cout << "Original value of num : " << num << endl;
    cout << "Value using reference : " << ref << endl;

    // Changing value using reference
    ref = 50;
    cout << "\nAfter changing reference (ref = 50):" << endl;
    cout << "Value of num          : " << num << endl;
    cout << "Value of ref          : " << ref << endl;

    // 2. Pointer
    cout << "\n===== 2. POINTER =====" << endl;
    int value = 100;
    int *ptr = &value;

    cout << "Value of variable     : " << value << endl;
    cout << "Address of variable   : " << &value << endl;
    cout << "Address stored in ptr : " << ptr << endl;
    cout << "Value pointed by ptr  : " << *ptr << endl;

    // Changing value using pointer
    *ptr = 200;
    cout << "\nAfter changing using pointer (*ptr = 200):" << endl;
    cout << "Value of variable     : " << value << endl;
    cout << "Value pointed by ptr  : " << *ptr << endl;

    // 3. Call by Reference
    cout << "\n===== 3. CALL BY REFERENCE =====" << endl;
    int a = 25;
    cout << "Before function call  : " << a << endl;
    changeValue(a);
    cout << "After function call   : " << a << endl;

    // 4. Call by Pointer
    cout << "\n===== 4. CALL BY POINTER =====" << endl;
    int b = 30;
    cout << "Before function call  : " << b << endl;
    changeUsingPointer(&b);
    cout << "After function call   : " << b << endl;

    // ==================================================
    // PART B: DYNAMIC MEMORY (new and delete operators)
    // ==================================================

    // 5. Dynamic memory allocation for a single variable
    cout << "\n===== 5. DYNAMIC ALLOCATION (new & delete) =====" << endl;
    int *dynamicNum = new int;
    *dynamicNum = 500;

    cout << "Dynamically allocated value : " << *dynamicNum << endl;
    cout << "Memory address              : " << dynamicNum << endl;

    delete dynamicNum;
    dynamicNum = nullptr;
    cout << "Memory released using delete operator successfully." << endl;

    // 6. Dynamic memory allocation for an array
    cout << "\n===== 6. DYNAMIC ARRAY (new[] & delete[]) =====" << endl;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\nElements of dynamic array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    arr = nullptr;
    cout << "Dynamic array memory released using delete[] successfully." << endl;

    return 0;
}
