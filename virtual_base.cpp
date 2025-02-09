#include <iostream>
using namespace std;

// Base class
class Base {
public:
    void show() {
        cout << "This is Base class" << endl;
    }
};

// Intermediate class A, virtually inherited
class A : virtual public Base {
public:
    void displayA() {
        cout << "This is class A" << endl;
    }
};

// Intermediate class B, virtually inherited
class B : virtual public Base {
public:
    void displayB() {
        cout << "This is class B" << endl;
    }
};

// Derived class inheriting from both A and B
class Derived : public A, public B {
public:
    void displayDerived() {
        cout << "This is the Derived class" << endl;
    }
};

int main() {
    Derived obj;
    
    // No ambiguity due to virtual inheritance
    obj.show();           // Calls Base::show()
    obj.displayA();        // Calls A::displayA()
    obj.displayB();        // Calls B::displayB()
    obj.displayDerived();  // Calls Derived::displayDerived()
    
    return 0;
}
