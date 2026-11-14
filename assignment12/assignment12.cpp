
#include <cstdint>
#include <iostream>
#include <typeinfo>
using namespace std;

// ---- classes for dynamic_cast (base must have a virtual function) ----
class Animal {
public:
    virtual ~Animal() = default;
    virtual void speak() const { cout << "Animal sound\n"; }
};
class Dog : public Animal {
public:
    void speak() const override { cout << "Dog says Woof\n"; }
    void fetch() const { cout << "Dog is fetching the ball\n"; }
};
class Cat : public Animal {
public:
    void speak() const override { cout << "Cat says Meow\n"; }
};

// ---- legacy function that takes char* but never modifies the data ----
void printLegacy(char* text) { cout << "Legacy print: " << text << "\n"; }

int main() {
    // 1. Implicit conversion (done automatically by the compiler)
    cout << "=== 1. Implicit conversion ===\n";
    int i = 10;
    double d = i;                 // int -> double (safe)
    int t = 9.99;                 // double -> int (fraction is lost)
    cout << "int 10 -> double : " << d << "\n";
    cout << "double 9.99 -> int : " << t << "\n";
    cout << "7 / 2 = " << 7 / 2 << "   (integer division)\n";

    // 2. C-style cast (works, but unsafe and hard to search for)
    cout << "\n=== 2. C-style cast ===\n";
    cout << "(double)7 / 2 = " << (double)7 / 2 << "\n";

    // 3. static_cast : compile-time checked, most commonly used
    cout << "\n=== 3. static_cast ===\n";
    int a = 7, b = 2;
    double avg = static_cast<double>(a) / b;
    cout << "static_cast<double>(7) / 2 = " << avg << "\n";
    cout << "static_cast<int>(-3.99)    = " << static_cast<int>(-3.99) << "  (truncates toward zero)\n";
    cout << "static_cast<char>(65)      = " << static_cast<char>(65) << "\n";
    int n = 42;
    void* vp = &n;                              // any pointer -> void*
    int* ip = static_cast<int*>(vp);            // void* -> int* needs static_cast
    cout << "void* back to int*         = " << *ip << "\n";

    // 4. dynamic_cast : run-time checked down-casting (needs virtual functions)
    cout << "\n=== 4. dynamic_cast ===\n";
    Animal* pet = new Dog();                    // base pointer, real object is Dog
    pet->speak();
    if (Dog* dog = dynamic_cast<Dog*>(pet)) {   // succeeds
        cout << "Cast to Dog*  : success -> ";
        dog->fetch();
    }
    Cat* cat = dynamic_cast<Cat*>(pet);         // fails -> nullptr
    cout << "Cast to Cat*  : " << (cat ? "success" : "failed (nullptr)") << "\n";
    try {
        Cat& c = dynamic_cast<Cat&>(*pet);      // reference form throws on failure
        c.speak();
    } catch (const bad_cast&) {
        cout << "Cast to Cat&  : failed (std::bad_cast thrown)\n";
    }
    delete pet;

    // 5. const_cast : add or remove const / volatile
    cout << "\n=== 5. const_cast ===\n";
    int value = 100;                            // the object itself is NOT const
    const int* readOnly = &value;
    int* writable = const_cast<int*>(readOnly);
    *writable = 200;                            // OK because value was never const
    cout << "value after const_cast write = " << value << "\n";
    const char* msg = "Hello const_cast";
    printLegacy(const_cast<char*>(msg));        // pass const data to a legacy API

    // 6. reinterpret_cast : reinterpret the bits, no checks at all
    cout << "\n=== 6. reinterpret_cast ===\n";
    int number = 0x01020304;
    unsigned char* bytes = reinterpret_cast<unsigned char*>(&number);
    cout << "Bytes of 0x01020304 in memory: ";
    for (int k = 0; k < 4; k++) cout << hex << static_cast<int>(bytes[k]) << " ";
    cout << dec << "\n";
    cout << (bytes[0] == 0x04 ? "-> little-endian machine\n" : "-> big-endian machine\n");
    uintptr_t address = reinterpret_cast<uintptr_t>(&number);   // pointer -> integer
    int* again = reinterpret_cast<int*>(address);               // integer -> pointer
    cout << "Pointer round trip OK: " << boolalpha << (again == &number) << "\n";

    return 0;
}