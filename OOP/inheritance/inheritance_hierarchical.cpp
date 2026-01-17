#include <iostream>
using namespace std;

class Human {
    protected:
    string name;
    int age;

    public:
    Human (){}

    Human (string name, int age){
        this->name = name;
        this->age = age;
    }
    void info(){
        cout << "\nMy name is: " << name << "\nMy age is: " << age << endl;
    }
};

class Student : public Human {
    int roll_no, fees;

    public:
    Student(string name, int age, int roll_no, int fees )
    {
        this->name = name;
        this->age = age;
        this->roll_no = roll_no;
        this->fees = fees;
    }
    
    //Another way, to solve default constructor problem
    /*Student(string name, int age, int roll_no, int fees ) : Human (name, age)
    {
        this->roll_no = roll_no;
        this->fees = fees;
    }*/

    void display(){
        info();
        cout << "My Roll No is: " << roll_no << "\nMy fees is: " << fees << endl;
    }
    
};

class Teacher : public Human {
    int salary;

    public:
    Teacher (string name, int age, int salary): Human (name, age)
    {
        this -> salary = salary;
    }
    void display(){
        info();
        cout <<"My salary is: " << salary << endl;
    }
};

int main (){
    cout << "-------------------Student's Information-------------------";
    Student A1("Jack", 10, 23, 499);
    cout << "-------------------Teacher's Information-------------------";
    Teacher T1("Doe", 20, 1000);

    A1.display();
    T1.display();
}