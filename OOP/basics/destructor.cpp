#include <iostream>
using namespace std;

class Customer{
    string name;
    int *age;

    public:
    //Constructor
    Customer (string n, int a){
        name = n;
        age = new int;
        *age = a;
        cout << "Constructor is Called!\n";
    }

    //Destructor
    ~Customer(){
        cout << "Destructor is Called1\n";
    }
};

int main (){
    Customer C1 ("Jack", 10);

}