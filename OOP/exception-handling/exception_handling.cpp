#include <iostream>
using namespace std;

/*class Customer{
    string name;
    int balance, account_no;

    public:
    Customer (string name, int balance, int account_no){
        this->name = name;
        this->balance = balance;
        this->account_no = account_no;
    }

    void deposit (int amount){
        if (amount > 0){
            balance += amount;
            cout << "Amount deposited successfully! \nNew Balance: $" << balance << endl; 
        } else {
            // cout << "Error: Invalid Amount!";
            throw "Error: Invalid Amount!";
        }
    }

    void withdraw(int amount){
        if(amount>0 && amount<=balance){
            balance -= amount;
            cout << "Amount withdrawed successfully! \nNew Balance: $" << balance << endl;      
        }else if (amount <0){ //Handling Exception
            // cout << "Amount should be greater than 0!" << endl;
            throw "Amount should be greater than 0!";
        }else{
            // cout << "Balance is low" << endl;
            throw "Balance is low";
        }
    }

};
int main (){
    Customer C1("Jack", 100, 1);
    try {
        C1.deposit(100);
        C1.withdraw(5000);
        C1.withdraw(10);
    }
    catch(const char *S){
        cout << "Error: " << S << endl;
    }
}*/


/*int main (){
    float a, b;
    cout << "First integer: ";
    cin >> a;
    cout << "Second integer: ";
    cin >> b;

    try {
        if (b==0)
        throw "Divide by zero not possible!";

        if(b>a)
        throw "Divider cannot be greater than Divisor!";

        float c = a/b;
        cout << c;

    }catch (const char *p){
        cout << "Exception Occured: " << p << endl;
    }
}*/


/*int main (){
    float a, b;
    cout << "First integer: ";
    cin >> a;
    cout << "Second integer: ";
    cin >> b;
    float c;

    try {
        if (b==0){
            throw logic_error("Dividor cannot be zero!");
        } else if (a < b) {
            throw "Dividor cannot be greater than divisor";
        }else{
            c = a/b;
            cout << "Result: " << c << endl;
        }
    }
    catch (const logic_error &e){
        cout << "Exception Occured: " << e.what() << endl;
    }
    catch (const char *e){
        cout << "Exception Occured: " << e << endl;
    }
}*/



/*int main (){
    float a, b;
    cout << "First integer: ";
    cin >> a;
    cout << "Second integer: ";
    cin >> b;
    float c;

    try {
        if (b==0){
            throw runtime_error("Dividor cannot be zero!");
        } else if (a < b) {
            throw "Dividor cannot be greater than divisor";
        }else{
            c = a/b;
            cout << "Result: " << c << endl;
        }
    }
    catch (const runtime_error &e){
        cout << "Exception Occured: " << e.what() << endl;
    }
    catch (const char *e){
        cout << "Exception Occured: " << e << endl;
    }
}*/