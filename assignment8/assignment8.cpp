#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// Custom Exception Class inheriting from std::exception
class InsufficientBalanceException : public exception {
private:
    string message;

public:
    InsufficientBalanceException(double balance, double amount) {
        message = "InsufficientBalanceException: Cannot withdraw " + to_string(amount) +
                  " from available balance of " + to_string(balance);
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

// BankAccount class to demonstrate custom and standard exception throwing
class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) {
        if (initialBalance < 0) {
            throw invalid_argument("Initial balance cannot be negative.");
        }
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            throw invalid_argument("Deposit amount must be greater than zero.");
        }
        balance += amount;
        cout << "Deposited: " << amount << " | New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            throw invalid_argument("Withdrawal amount must be positive.");
        }
        if (amount > balance) {
            throw InsufficientBalanceException(balance, amount);
        }
        balance -= amount;
        cout << "Withdrawn: " << amount << " | Remaining Balance: " << balance << endl;
    }
};

// Function demonstrating division by zero and array bounds checking
void performOperations(int a, int b, int index) {
    int arr[3] = {10, 20, 30};

    if (b == 0) {
        throw runtime_error("Division by zero error!");
    }
    cout << "Division result (" << a << " / " << b << "): " << (a / b) << endl;

    if (index < 0 || index >= 3) {
        throw out_of_range("Array index out of bounds!");
    }
    cout << "Element at index " << index << ": " << arr[index] << endl;
}

int main() {
    cout << "=== PART 1: MULTIPLE CATCH BLOCKS (STANDARD EXCEPTIONS) ===\n";
    int num1, num2, idx;
    cout << "Enter numerator, denominator, and array index (0-2): ";
    cin >> num1 >> num2 >> idx;

    try {
        performOperations(num1, num2, idx);
    }
    catch (const runtime_error& e) {
        cout << "[Runtime Error Caught]: " << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cout << "[Out of Range Error Caught]: " << e.what() << endl;
    }
    catch (...) {
        cout << "[Unknown Exception Caught]" << endl;
    }

    cout << "\n=== PART 2: CUSTOM USER-DEFINED EXCEPTION ===\n";
    try {
        BankAccount acc(5000.0);
        cout << "Account created with balance: 5000.0\n";

        double withdrawAmt;
        cout << "Enter amount to withdraw: ";
        cin >> withdrawAmt;

        acc.withdraw(withdrawAmt);
    }
    catch (const InsufficientBalanceException& e) {
        cout << "[Custom Exception Caught]: " << e.what() << endl;
    }
    catch (const invalid_argument& e) {
        cout << "[Invalid Argument Caught]: " << e.what() << endl;
    }

    cout << "\nProgram execution completed safely after exception handling." << endl;
    return 0;
}
