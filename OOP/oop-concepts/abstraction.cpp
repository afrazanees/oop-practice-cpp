#include <iostream>
using namespace std;

class Customer{
    string name;
    int age;
    double balance;

    public:
        Customer (string name, int age, double balance){
            this->name = name;
            this->age = age;
            this->balance = balance;
        }

        void deposit (int amount){
            if (amount >0){
                balance += amount;
                cout << "Deposit Done! New Balance: " << balance << endl;
            }else{
                cout << "Invalid Deposit Amount!";
            }
        }

        void withdraw (int amount){
            if (amount <= balance && amount >0){
                balance -= amount;
                cout << "Withdrawl Done! New Balance: " << balance << endl;
            }else{
                cout << "Invalid Withdrawal Amount!";
            }
        }
};

int main (){
    string name;
    int age;
    double balance;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Balance: ";
    cin >> balance;

    Customer A1 (name, age, balance);
    A1.deposit (10);
    A1.withdraw (20);
}