#include <iostream>
using namespace std;

class Customer {
    string name;
    int acc_num;
    int acc_bal;
    static int total_count;

    public:

    // //Direct Access from Class without Object
    // static int total_count;

    Customer (string s, int n, int b){
        name = s;
        acc_num = n;
        acc_bal = b;
        total_count++;
    }

    void display_total_count (){
        cout << total_count << endl;
    }

};

int Customer :: total_count = 0;

int main (){
    Customer C1 ("Jack", 1, 100);
    Customer C2 ("Doe", 2, 200);
    C1.display_total_count();

    Customer C3 ("Alice", 3, 300);
    C3.display_total_count();
 
    // //Direct Access from Class without Object
    // Customer::total_count = 5;
    // C3.display_total_count();
}