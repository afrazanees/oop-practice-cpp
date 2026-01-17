#include <iostream>
using namespace std;

class Customer {
    string name;
    int acc_balance;
    int acc_num;

    public:
    //Defualt constructor
    Customer (){
        // cout << "Default Constructr is Called!";
        name = "Jack";
        acc_balance = 1000;
        acc_num = 1;
    }

    //Parametrized Constructor
    Customer (string name, int acc_balance, int acc_num){
        this -> name = name;
        this -> acc_balance = acc_balance;
        this -> acc_num = acc_num;
    }
    //Another Way
    // Customer (string n, int aB , int aN){
    //     name = n;
    //     acc_balance = aB;
    //     acc_num = aN;
    // }

    //Inline Constructor
    inline Customer (string a, int b) : name (a), acc_balance(b), acc_num(3) {}

    // //Constructor Overloading
    // Customer (string a, int b){
    //     name = a;
    //     acc_balance = b;
    //     //By Default Value
    //     // acc_num = 3;
    // }

    //Copy Constructor
    Customer (Customer &obj){
        name = obj.name;
        acc_balance = obj.acc_balance;
        acc_num = obj.acc_num;
    }

    void display (){
        cout << name << " " << acc_balance << " " << acc_num << endl;
    }

};

int main (){
    //Defualt Constructor
    // Customer C1, C2, C3;
    // C1.display();
    // C2.display();
    // C3.display();

    Customer C1;
    //Parametrized Constructor
    Customer C2("Doe", 100, 2);
    Customer C3("Alice", 50);
    
    //Copy Constructor
    Customer C4(C2);
    //Another Way
    Customer C5;
    C5 = C1;


    C1.display();
    C2.display();
    C3.display();
    C4.display();
    C5.display();
}