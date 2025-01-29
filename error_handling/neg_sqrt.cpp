#include <iostream>
#include <cmath>
using namespace std;

double computeSqrt(double num) {
    if (num < 0) {
        throw invalid_argument("Cannot compute square root of negative number");
    }
    return sqrt(num);
}

int main() {
    try {
        cout << "Square root: " << computeSqrt(-9) << endl;
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
