#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Helper function to display vector elements
void displayVector(const vector<int>& vec) {
    if (vec.empty()) {
        cout << "Vector is empty." << endl;
        return;
    }
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> myVec;
    int choice, value, index;

    do {
        cout << "\n--- STL Vector Operations Menu ---\n";
        cout << "1. Add Element at End (push_back)\n";
        cout << "2. Insert Element at Specific Index\n";
        cout << "3. Delete Last Element (pop_back)\n";
        cout << "4. Delete Element at Specific Index\n";
        cout << "5. Access Element at Index\n";
        cout << "6. Sort Vector\n";
        cout << "7. Search Element\n";
        cout << "8. Display Vector, Size & Capacity\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to add: ";
                cin >> value;
                myVec.push_back(value);
                break;

            case 2:
                cout << "Enter index (0 to " << myVec.size() << "): ";
                cin >> index;
                if (index >= 0 && index <= static_cast<int>(myVec.size())) {
                    cout << "Enter value to insert: ";
                    cin >> value;
                    myVec.insert(myVec.begin() + index, value);
                } else {
                    cout << "Invalid index!" << endl;
                }
                break;

            case 3:
                if (!myVec.empty()) {
                    cout << "Removed last element: " << myVec.back() << endl;
                    myVec.pop_back();
                } else {
                    cout << "Vector is already empty!" << endl;
                }
                break;

            case 4:
                if (!myVec.empty()) {
                    cout << "Enter index to delete (0 to " << myVec.size() - 1 << "): ";
                    cin >> index;
                    if (index >= 0 && index < static_cast<int>(myVec.size())) {
                        myVec.erase(myVec.begin() + index);
                        cout << "Element at index " << index << " deleted." << endl;
                    } else {
                        cout << "Invalid index!" << endl;
                    }
                } else {
                    cout << "Vector is empty!" << endl;
                }
                break;

            case 5:
                cout << "Enter index to access: ";
                cin >> index;
                if (index >= 0 && index < static_cast<int>(myVec.size())) {
                    cout << "Element at index " << index << " is: " << myVec.at(index) << endl;
                } else {
                    cout << "Index out of bounds!" << endl;
                }
                break;

            case 6:
                sort(myVec.begin(), myVec.end());
                cout << "Vector sorted in ascending order." << endl;
                break;

            case 7: {
                cout << "Enter value to search: ";
                cin >> value;
                auto it = find(myVec.begin(), myVec.end(), value);
                if (it != myVec.end()) {
                    cout << "Element found at index: " << distance(myVec.begin(), it) << endl;
                } else {
                    cout << "Element not found in vector." << endl;
                }
                break;
            }

            case 8:
                cout << "Elements: ";
                displayVector(myVec);
                cout << "Size: " << myVec.size() << " | Capacity: " << myVec.capacity() << endl;
                break;

            case 0:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}