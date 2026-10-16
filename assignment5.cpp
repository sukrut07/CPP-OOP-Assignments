#include <iostream>
#include <string>
using namespace std;
 
class ResultAnalyzer; // Forward declaration
 
class Student
{
private:
    string name;
    int marks;
    static int studentCount;
 
public:
    // Constructor
    Student(string studentName, int studentMarks)
    {
        name = studentName;
        marks = studentMarks;
        studentCount++;
    }
 
    // Inline member function (defined inside the class)
    inline void display() const
    {
        cout << "Name: " << name << ", Marks: " << marks << endl;
    }
 
    // Demonstrates the this pointer
    void updateMarks(int marks)
    {
        this->marks = marks;
    }
 
    // Static member function
    static void showStudentCount()
    {
        cout << "Total Student objects: " << studentCount << endl;
    }
 
    // Allow ResultAnalyzer to access private members
    friend class ResultAnalyzer;
};
 
// Definition of static data member
int Student::studentCount = 0;
 
// Friend class
class ResultAnalyzer
{
public:
    void showPrivateDetails(const Student& student) const
    {
        cout << "Friend class report" << endl;
        cout << "Name: " << student.name << endl;
        cout << "Marks: " << student.marks << endl;
    }
};
 
int main()
{
    cout << "=== Student Result Management ===" << endl;
 
    Student s1("Aarav", 75);
    Student s2("Priya", 88);
 
    cout << "\nStudent details using inline function:" << endl;
    s1.display();
    s2.display();
 
    s1.updateMarks(82);
    cout << "\nAfter updating Aarav's marks using this pointer:" << endl;
    s1.display();
 
    cout << "\nUsing static member function:" << endl;
    Student::showStudentCount();
 
    cout << "\nAccessing private data through friend class:" << endl;
    ResultAnalyzer analyzer;
    analyzer.showPrivateDetails(s1);
 
    return 0;
}