//--------Function Overloading-------
/*#include <iostream>
using namespace std;

class Area{
    public:
    float calcArea(float r){
        return r*r;
    }
    float calcArea(float l, float b){
        return l*b;
    }
};

int main (){
    Area A1;
    cout << A1.calcArea(3) << endl;
    cout << A1.calcArea(3, 8);
}*/


// //--------Operator Overloading-------
// #include <iostream>
// using namespace std;

// class Complex{
//     int real, img;

//     public:
//     Complex(){}

//     Complex(int real, int img){
//         this->real= real;
//         this->img = img;
//     }

//     void display (){
//         cout << real << " + i" << img << endl;
//     }

//     Complex operator+(Complex &other){
//         /*Complex obj;

//         //You can access "private data member" of same type of object, within the class
//         obj.real = real + other.real; 
//         obj.img = img + other.img;
//         return obj;*/

//         //Another Way
//         return Complex(real+other.real, img+other.img); 
//     }
// };

// int main (){
//    Complex A1(3,4), A2(4,6);
//    Complex A3 = A1 + A2;

//    A3.display();
// }



//------------Virtual Function-----------
#include <iostream>
using namespace std;

class Animal{
    public:
    virtual void sound (){
        cout << "Ha Ha!";
    }
};  

class Dog : public Animal{
    public:
    void sound (){
        cout << "Bark!";
    }
};

int main (){
    Animal *ptr; //Pointer of parent class
    Dog obj; //Object of derived class
    ptr = &obj; //Parent class pointer can store address of child class
    // ptr = new Dog(); //Another way
    ptr->sound();
}