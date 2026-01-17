#include <iostream>
using namespace std;

class Human {
    protected:
    string name;
    int age;

};

class Student : public Human {
    int roll_no, fees;

    // protected:
    // string name;
    // int age;

    public:
    Student(string name, int age, int roll_no, int fees ){
        this->name = name;
        this->age = age;
        this->roll_no = roll_no;
        this->fees = fees;
    }
    void student_details(){
        cout << "Name: " << name << "\nAge: " << age << "\nRoll No: " << roll_no << "\nFees: " << fees << endl;
    }
};

class Teacher : public Human {
    int salary, id;

    // protected:
    // string name;
    // int age;

    public:
    Teacher(string name, int id, int salary){
        this->name = name;
        this->id = id;
        this->salary = salary;        
    }
    void teacher_details(){
        cout << "Name: " << name << "\nID: " << id << "\nSalary: " << salary << endl;
    }
};

int main (){
    Student A1("Jack", 10, 23, 499);
    Teacher T1("Doe", 1, 4000);

    cout << "---------------Student Details: ----------------" << endl;;
    A1.student_details();
    cout << "---------------Teacher Details: ----------------" << endl;
    T1.teacher_details();
}