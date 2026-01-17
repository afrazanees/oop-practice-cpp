#include <iostream>
using namespace std;

class Human {
    protected:
    string name;
    int age;

    Human (string name, int age){
        this->name = name;
        this->age = age;
    }
};

class Student : public Human {
    int roll_no, fees;

    public:
    Student(string name, int age, int roll_no, int fees ): Human(name, age)
    {
        this->roll_no = roll_no;
        this->fees = fees;
    }
    void display(){
        cout << "Name: " << name << "\nAge: " << age << "\nRoll No: " << roll_no << "\nFees: " << fees << endl;
    }
    
};

int main (){
    Student A1("Jack", 10, 23, 499);
    A1.display();
}