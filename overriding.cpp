#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() {
        cout << "Display from Base class" << endl;
    }
};

class Derived : public Base {
public:
    void display() override {  // Overriding Base::display()
        cout << "Display from Derived class" << endl;
    }
};

int main() {
    Base* basePtr;
    Derived derivedObj;
    
    basePtr = &derivedObj;
    basePtr->display();  // Calls Derived's display() due to virtual function

    return 0;
}
