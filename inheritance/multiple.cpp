#include <iostream>
using namespace std;

class Base1 {
public:
    void showBase1() {
        cout << "Base1 class method" << endl;
    }
};

class Base2 {
public:
    void showBase2() {
        cout << "Base2 class method" << endl;
    }
};

class Derived : public Base1, public Base2 {
public:
    void showDerived() {
        cout << "Derived class method" << endl;
    }
};

int main() {
    Derived obj;
    obj.showBase1();
    obj.showBase2();
    obj.showDerived();
    return 0;
}
