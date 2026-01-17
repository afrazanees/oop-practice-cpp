#include <iostream>
using namespace std;

class Customer{
    string name;
    int age;
    static int account_id;
    double balance;

    public:
        Customer (string name, int age, double balance){
            this->name = name;
            this->age = age;
            this->balance = balance;
            account_id++;
        }
        /*Another way
        Customer (string name, int age, double balance){
            this->name = name;
            if (age >=0){
                this->age = age;
            }else {
                cout << "Age cannot Be negative!";
            }
            if (balance >0){
                this->balance += balance;
            }else {
                cout << "Invalid Amount!";
            }
        }*/

        void deposit (int amount){
            if (amount >0){
                balance += amount;
                cout << "Deposit Done! New Balance: " << balance << endl;
            }else{
                cout << "Invalid Deposit Amount!";
            }
        }

        void withdrawl (int amount){
            if (amount <= balance && amount >0){
                balance -= amount;
                cout << "Withdrawl Done! New Balance: " << balance << endl;
            }else{
                cout << "Invalid Deposit Amount!";
            }
        }

        void display (){
            cout << "Account Name: " << name << "\nAccount ID: " << account_id << "\nBalance: " << balance << endl;
        }

};

int Customer:: account_id = 0;

int main (){
    Customer A1 ("Jack", 21, 100);
    A1.deposit (1000);
    A1.withdrawl (900);
    A1.display();
}