#include <iostream>
using namespace std;

class Base {
public:
    void showBase() {
        cout << "Base class method called" << endl;
    }
};

class Derived : public Base {
public:
    void showDerived() {
        cout << "Derived class method called" << endl;
    }
};

int main() {
    Derived obj;
    obj.showBase();
    obj.showDerived();
    return 0;
}
