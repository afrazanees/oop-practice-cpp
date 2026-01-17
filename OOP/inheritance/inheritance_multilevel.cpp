#include <iostream>
using namespace std;

class Person {
    protected:
    string name;
    int age;

    void display_info (){
        cout << "\nMy name is: " << name << "\nMy age is: " << age << endl;;
    }
};

class Employee : public Person {
    protected:
    int salary;

    void display_salary (){
        cout << "My salary is: " << salary << endl;
    }
};

class Manager : public Employee {
    protected:
    string department;

    public:
    void display_department (){
        cout << "My Department is: " << department << endl;
    }

    Manager(string name, int age, int salary, string department){
        this->name = name;
        this->age = age;
        this->salary = salary;
        this->department = department;
    }
    // void main_display(){
    //     cout << "\nMy name is: " << name 
    //          << "\nMy age is: " << age 
    //          << "\nMy salary is: " << salary 
    //          << "\nMy Department is: " << department << endl;
    // }

    //Another way to display info
    void main_display(){
        display_info();
        display_salary();
        display_department();
    }
};

int main (){
    string name, department;
    int age, salary;
    cout << "Name: ";
    cin >> name;
    cout << "Age: ";
    cin >> age;
    cout << "Salary: ";
    cin >> salary;
    cout << "Department: ";
    cin >> department;

    Manager A1(name, age, salary, department);
    A1.main_display();
}