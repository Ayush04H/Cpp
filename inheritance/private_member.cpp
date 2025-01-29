#include <iostream>
using namespace std;

class Base {
public:
    void show() {
        cout << "Base class method" << endl;
    }
};

class Derived : private Base {
public:
    void accessBase() {
        show();
    }
};

int main() {
    Derived obj;
    obj.accessBase();
    return 0;
}
