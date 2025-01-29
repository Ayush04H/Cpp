#include <iostream>
using namespace std;

class ShallowCopy {
    int *data;

public:
    ShallowCopy(int value) {
        data = new int(value);
    }

    void display() {
        cout << "Data: " << *data << endl;
    }

    ~ShallowCopy() {
        delete data;
    }
};

int main() {
    ShallowCopy obj1(42);
    ShallowCopy obj2 = obj1;  // Shallow copy (default behavior)
    obj2.display();

    return 0;
}
