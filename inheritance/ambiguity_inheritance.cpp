#include <iostream>
using namespace std;

class A {
public:
    void show() {
        cout << "Class A method" << endl;
    }
};

class B {
public:
    void show() {
        cout << "Class B method" << endl;
    }
};

class C : public A, public B {
public:
    void display() {
        A::show();  // Resolve ambiguity using scope resolution
        B::show();
    }
};

int main() {
    C obj;
    obj.display();
    return 0;
}
