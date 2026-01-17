#include <iostream>
using namespace std;

class Customer {

    string name;
    int acc_num;
    int acc_bal;
    static int total_count;
    static int total_bal;
    public:

    // //Direct Access from Class without Object
    // static int total_count;

    Customer (string s, int n, int b){
        name = s;
        acc_num = n;
        acc_bal = b;
        total_count++;
        total_bal = total_bal + acc_bal;
    }

    void deposit (int amount){
        total_bal = total_bal + amount;
    }
    void withdrawl (int amount){
        total_bal = total_bal - amount;
    }

    void display_total_count (){
        cout << "Total Number Of Accounts: " << total_count << endl;
    }

    //Static Member Function
    static void acceStatic (){
        cout << "Total Number Of Accounts: " << total_count << endl;
        cout << "Total Balance: " << total_bal << endl;
    }

};

int Customer::total_count = 0;
int Customer::total_bal = 0;

int main (){
    Customer C1 ("Jack", 1, 100);
    Customer C2 ("Doe", 2, 200);
    Customer C3 ("Alice", 3, 300);
    C3.display_total_count();
 
    // //Direct Access from Class without Object
    // Customer::total_count = 5;
    // C3.display_total_count();

    //Static Member Function
    C1.deposit(1000);
    C2.withdrawl(900);
    C3.acceStatic();
    // Customer::acceStatic();
}