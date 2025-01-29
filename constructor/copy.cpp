#include <iostream>
using namespace std;

class Sample {
    int value;

public:
    Sample(int v) {
        value = v;
    }

    // Copy constructor
    Sample(const Sample &obj) {
        value = obj.value;
        cout << "Copy Constructor Called" << endl;
    }

    void display() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Sample s1(10);
    Sample s2 = s1;  // Copy constructor is called
    s2.display();
    return 0;
}
