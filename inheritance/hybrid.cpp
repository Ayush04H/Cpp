#include <iostream>
using namespace std;

class Base {
public:
    void showBase() {
        cout << "Base class method" << endl;
    }
};

class Derived1 : public Base {
public:
    void showDerived1() {
        cout << "Derived1 class method" << endl;
    }
};

class Derived2 : public Base {
public:
    void showDerived2() {
        cout << "Derived2 class method" << endl;
    }
};

class FinalDerived : public Derived1, public Derived2 {
public:
    void showFinal() {
        cout << "Final Derived class method" << endl;
    }
};

int main() {
    FinalDerived obj;
    obj.showFinal();
    obj.Derived1::showBase();  // Ambiguity resolved by scope resolution
    return 0;
}
