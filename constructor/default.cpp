#include <iostream>
using namespace std;

class Demo {
public:
    Demo() {
        cout << "Default Constructor Called" << endl;
    }
};

int main() {
    Demo obj;  // Default constructor is called
    return 0;
}
