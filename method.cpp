#include <iostream>
using namespace std;

class Calculator {
public:
    // Method with one integer parameter
    int add(int a) {
        return a + 10;
    }

    // Method with two integer parameters
    int add(int a, int b) {
        return a + b;
    }

    // Method with three integer parameters
    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Calculator calc;
    cout << "add(5) = " << calc.add(5) << endl;       // Output: 15
    cout << "add(3, 4) = " << calc.add(3, 4) << endl; // Output: 7
    cout << "add(1, 2, 3) = " << calc.add(1, 2, 3) << endl; // Output: 6
    return 0;
}
