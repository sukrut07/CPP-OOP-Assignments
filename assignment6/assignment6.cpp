#include <iostream>
#include <string>

using namespace std;

// ========================================================
// 1. SINGLE & 2. MULTILEVEL INHERITANCE
//    Person -> Student -> EngineeringStudent
// ========================================================

class Person {
protected:
    string name;
    int age;

public:
    void setPersonDetails(const string& n, int a) {
        name = n;
        age = a;
    }

    void displayPerson() const {
        cout << "Name: " << name << " | Age: " << age << endl;
    }
};

// Single Inheritance: Student inherits from Person
class Student : public Person {
protected:
    int rollNo;

public:
    void setStudentDetails(const string& n, int a, int r) {
        setPersonDetails(n, a);
        rollNo = r;
    }

    void displayStudent() const {
        displayPerson();
        cout << "Roll No: " << rollNo << endl;
    }
};

// Multilevel Inheritance: EngineeringStudent inherits from Student
class EngineeringStudent : public Student {
private:
    string branch;

public:
    void setEnggDetails(const string& n, int a, int r, const string& b) {
        setStudentDetails(n, a, r);
        branch = b;
    }

    void displayEnggStudent() const {
        displayStudent();
        cout << "Branch: " << branch << endl;
    }
};

// ========================================================
// 3. MULTIPLE INHERITANCE
//    AcademicScore + SportsScore -> Result
// ========================================================

class AcademicScore {
protected:
    float marks;

public:
    void setMarks(float m) {
        marks = m;
    }
};

class SportsScore {
protected:
    float sportsGrade;

public:
    void setSportsGrade(float s) {
        sportsGrade = s;
    }
};

// Inherits from both AcademicScore and SportsScore
class Result : public AcademicScore, public SportsScore {
public:
    void displayTotalResult() const {
        cout << "Academic Marks: " << marks
             << " | Sports Score: " << sportsGrade
             << " | Total Score: " << (marks + sportsGrade) << endl;
    }
};

// ========================================================
// 4. HIERARCHICAL & 5. HYBRID INHERITANCE (Virtual Base Class)
//          Device
//          /    \
//     Scanner  Printer
//          \    /
//      AllInOneMachine
// ========================================================

class Device {
protected:
    string brand;

public:
    void setBrand(const string& b) {
        brand = b;
    }
};

// Hierarchical: Both Scanner and Printer inherit from Device
class Scanner : virtual public Device {
public:
    void scan() const {
        cout << "[" << brand << "] Scanning document..." << endl;
    }
};

class Printer : virtual public Device {
public:
    void print() const {
        cout << "[" << brand << "] Printing document..." << endl;
    }
};

// Hybrid Inheritance: Combines Hierarchical and Multiple Inheritance
class AllInOneMachine : public Scanner, public Printer {
public:
    void copyDocument() const {
        cout << "[" << brand << "] Copying document (Scan + Print):" << endl;
        scan();
        print();
    }
};

// ========================================================
// MAIN DRIVER CODE
// ========================================================

int main() {
    cout << "=== 1. SINGLE INHERITANCE ===\n";
    Student s1;
    s1.setStudentDetails("Aarav Sharma", 19, 101);
    s1.displayStudent();

    cout << "\n=== 2. MULTILEVEL INHERITANCE ===\n";
    EngineeringStudent e1;
    e1.setEnggDetails("Riya Verma", 20, 102, "AI & ML");
    e1.displayEnggStudent();

    cout << "\n=== 3. MULTIPLE INHERITANCE ===\n";
    Result r1;
    r1.setMarks(88.5f);
    r1.setSportsGrade(9.5f);
    r1.displayTotalResult();

    cout << "\n=== 4. HIERARCHICAL INHERITANCE ===\n";
    Scanner sc;
    sc.setBrand("Canon");
    sc.scan();

    Printer pr;
    pr.setBrand("Epson");
    pr.print();

    cout << "\n=== 5. HYBRID INHERITANCE ===\n";
    AllInOneMachine aio;
    aio.setBrand("HP LaserJet");
    aio.copyDocument();

    return 0;
}