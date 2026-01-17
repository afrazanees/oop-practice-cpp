#include <iostream>
using namespace std;

class Engineer {
    protected:
    string specialization;

    void displaySpecialization (){
        cout << "My specialization is: " << specialization << endl;;
    }
};

class Influencer {
    protected:
    int followers;

    void displayFollowers (){
        cout << "I have total " << followers << " followers" << endl;
    }
};

class Teacher : public Engineer, public Influencer {
    protected:
    string name;
    int age;

    public:
    void info (){
        cout << "My name is: " << name << "\nMy age is: " << age << endl;
    }

    Teacher(string name, int age, string specialization, int followers){
        this->name = name;
        this->age = age;
        this->followers = followers;
        this->specialization = specialization;
    }

    void main_display(){
        info();
        displaySpecialization();
        displayFollowers();
    }
};

int main (){
    string name, specialization;
    int age, followers;
    cout << "Name: ";
    cin >> name;
    cout << "Age: ";
    cin >> age;
    cout << "Specialization: ";
    cin >> specialization;
    cout << "Followers: ";
    cin >> followers;

    Teacher A1(name, age, specialization, followers);
    A1.main_display();
}