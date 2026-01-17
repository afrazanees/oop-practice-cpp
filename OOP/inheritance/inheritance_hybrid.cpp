#include <iostream>
using namespace std;

class Human {
    public:
    void displayHuman (){
        cout << "I am a human.";
    }

};

class Father : virtual public Human{
    public:
    void displayFather(){
        cout << "\nI am a father.";
    }
};

class Mother : virtual public Human{
    public:
    void displayMother(){
        cout << "\nI am a mother.";
    }
};

class Child : public Father, public Mother {
    public:
    void displayChild(){
        cout << "\nI am a child.";
    }
};

int main (){
    Child C1;
   
    //C1.displayHuman(); // Error: 'displayHuman' is ambiguous
    
    // Method 1:
    // C1.Father::displayHuman();
    
    //Method 2:
    C1.displayHuman();
    //C1.displayHuman(); // If want to use this, you should make "Virtual" to either Father/Mother Class
    C1.displayFather();
    C1.displayMother();
    C1.displayChild();
}