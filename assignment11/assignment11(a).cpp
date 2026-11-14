#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

// Helper function to display list elements using an iterator
void displayList(const list<int>& lst) {
    if (lst.empty()) {
        cout << "List is empty." << endl;
        return;
    }
    for (list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    list<int> myList;
    int choice, value;

    do {
        cout << "\n--- STL List Operations Menu ---\n";
        cout << "1. Insert at Front (push_front)\n";
        cout << "2. Insert at Back (push_back)\n";
        cout << "3. Delete from Front (pop_front)\n";
        cout << "4. Delete from Back (pop_back)\n";
        cout << "5. Sort List\n";
        cout << "6. Reverse List\n";
        cout << "7. Remove Specific Value\n";
        cout << "8. Display List & Size\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at front: ";
                cin >> value;
                myList.push_front(value);
                break;

            case 2:
                cout << "Enter value to insert at back: ";
                cin >> value;
                myList.push_back(value);
                break;

            case 3:
                if (!myList.empty()) {
                    cout << "Removed front element: " << myList.front() << endl;
                    myList.pop_front();
                } else {
                    cout << "List is already empty!" << endl;
                }
                break;

            case 4:
                if (!myList.empty()) {
                    cout << "Removed back element: " << myList.back() << endl;
                    myList.pop_back();
                } else {
                    cout << "List is already empty!" << endl;
                }
                break;

            case 5:
                myList.sort();
                cout << "List sorted in ascending order." << endl;
                break;

            case 6:
                myList.reverse();
                cout << "List reversed." << endl;
                break;

            case 7:
                cout << "Enter value to remove: ";
                cin >> value;
                myList.remove(value);
                cout << "All occurrences of " << value << " removed (if present)." << endl;
                break;

            case 8:
                cout << "Current List (" << myList.size() << " elements): ";
                displayList(myList);
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
