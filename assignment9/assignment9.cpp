#include <iostream>
#include <utility>   // Required for std::move
#include <string>
#include <vector>

using namespace std;

// Custom class demonstrating Move Semantics vs Copy Semantics
class Buffer {
private:
    int* data;
    size_t size;

public:
    // Parameterized Constructor
    Buffer(size_t s) : size(s), data(new int[s]) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = static_cast<int>((i + 1) * 10);
        }
        cout << "[Constructor] Allocated buffer of size " << size << endl;
    }

    // Copy Constructor (Deep Copy)
    Buffer(const Buffer& other) : size(other.size), data(new int[other.size]) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
        cout << "[Copy Constructor] Deep copied buffer of size " << size << endl;
    }

    // Move Constructor (Transfers ownership without reallocation)
    Buffer(Buffer&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
        cout << "[Move Constructor] Ownership transferred (no memory allocated)" << endl;
    }

    // Move Assignment Operator
    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            delete[] data;          // Free existing resource
            data = other.data;      // Transfer pointer
            size = other.size;

            other.data = nullptr;   // Leave source in valid empty state
            other.size = 0;
            cout << "[Move Assignment] Ownership transferred" << endl;
        }
        return *this;
    }

    // Destructor
    ~Buffer() {
        delete[] data;
    }

    void display(const string& label) const {
        cout << label << " (size = " << size << "): ";
        if (data == nullptr || size == 0) {
            cout << "[Empty / Moved-from]";
        } else {
            for (size_t i = 0; i < size; ++i) {
                cout << data[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    cout << "=== PART 1: std::move WITH STANDARD STRINGS ===\n";
    string str1 = "Standard Template Library";
    string str2;

    cout << "Before std::move:\n";
    cout << "str1: \"" << str1 << "\"\n";
    cout << "str2: \"" << str2 << "\"\n";

    // Transfer resources from str1 to str2 without copying
    str2 = std::move(str1);

    cout << "\nAfter std::move(str1):\n";
    cout << "str1: \"" << str1 << "\" (valid but unspecified/empty state)\n";
    cout << "str2: \"" << str2 << "\"\n";

    cout << "\n=== PART 2: std::move WITH CUSTOM DYNAMIC CLASS ===\n";
    Buffer buf1(5);
    buf1.display("buf1");

    cout << "\nMoving buf1 into buf2 using std::move...\n";
    Buffer buf2 = std::move(buf1); // Invokes Move Constructor

    buf1.display("buf1 after move");
    buf2.display("buf2 after move");

    cout << "\n=== PART 3: std::move WITH STL VECTOR ===\n";
    vector<string> vec;
    string item = "Object-Oriented Programming";

    cout << "String before push_back(std::move(item)): \"" << item << "\"\n";
    vec.push_back(std::move(item));
    cout << "String after push_back(std::move(item)):  \"" << item << "\"\n";
    cout << "Vector[0]: \"" << vec[0] << "\"\n";

    return 0;
}
