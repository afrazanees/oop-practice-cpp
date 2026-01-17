#include <iostream>
using namespace std;

class Customer {
    int val;

    public:
    void setValue (int val){
        this->val = val;
    }

    //Const Member Function
    int getValue() const {
        return val;
    }

    //Constructors
    Customer (){

    }
    Customer (int a){
        val = a;
    }
};

int main (){
    Customer C1;
    C1.setValue(100);
    // C1.setValue(90);
    cout << "Value: " << C1.getValue() << endl; 

    //Const Object
    const Customer C2(10);
    // C2.setValue(99); -------------------Error:-----------
    // C2.val = 999; -------------------Error:-----------
    cout << "Value: " << C2.getValue() << endl;
}