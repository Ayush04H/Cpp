#include <iostream>
using namespace std;

class DeepCopy {
    int *data;

public:
    DeepCopy(int value) {
        data = new int(value);
    }

    // Deep copy constructor
    DeepCopy(const DeepCopy &obj) {
        data = new int(*obj.data);
    }

    void display() {
        cout << "Data: " << *data << endl;
    }

    ~DeepCopy() {
        delete data;
    }
};

int main() {
    DeepCopy obj1(42);
    DeepCopy obj2 = obj1;  // Deep copy ensures separate memory
    obj1.display();
    obj2.display();

    return 0;
}
