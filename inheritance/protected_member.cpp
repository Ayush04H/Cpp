#include <iostream>
using namespace std;

class Base {
protected:
    int value = 10;
};

class Derived : public Base {
public:
    void showValue() {
        cout << "Protected value from Base: " << value << endl;
    }
};

int main() {
    Derived obj;
    obj.showValue();
    return 0;
}
