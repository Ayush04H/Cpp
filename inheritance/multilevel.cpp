#include <iostream>
using namespace std;

class Grandparent {
public:
    void showGrandparent() {
        cout << "Grandparent class method" << endl;
    }
};

class Parent : public Grandparent {
public:
    void showParent() {
        cout << "Parent class method" << endl;
    }
};

class Child : public Parent {
public:
    void showChild() {
        cout << "Child class method" << endl;
    }
};

int main() {
    Child obj;
    obj.showGrandparent();
    obj.showParent();
    obj.showChild();
    return 0;
}
