#include <iostream>
using namespace std;

class Student
{
private:
    int roll;
    string name;
    int marks;

public:
    Student() // setting default constructor
    // constructor overloading
    {
    }
    Student(int r, string n, int m) // constructor
    {
        roll = r;
        name = n;
        marks = m;
    }

    //    void setRoll(int r){ // setter method
    //     roll =r;
    //    }
    int getRoll()
    { // getter method
        return roll;
    }
    int getMarks()
    {
        return marks;
    }
    string getName()
    {
        return name;
    }
};

int main()
{
    Student student1(1, "Badhon", 95); // -> constructor should be callled omce
    Student student2;
    // object creation
    // student1.roll = 10;
    // student1.name = "Badhon";
    // student1.marks = 90;
    // cout<<student1.roll<<endl;

    // student1.roll =15;
    //  cout<<student1.roll<<endl;
    // student1.setRoll(10);
    cout << student1.getRoll() << endl;
    cout << student1.getMarks() << endl;
    cout << student1.getName() << endl;
}