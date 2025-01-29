#include <iostream>
#include <typeinfo>
using namespace std;

class Base {
    virtual void dummy() {}
};

class Derived : public Base {};

int main() {
    try {
        Base b;
        Derived& d = dynamic_cast<Derived&>(b);  // This will throw an exception
    } catch (const bad_cast& e) {
        cout << "Caught bad cast: " << e.what() << endl;
    }
    return 0;
}
