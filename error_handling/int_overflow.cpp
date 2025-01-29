#include <iostream>
#include <climits>
using namespace std;

int safeAdd(int a, int b) {
    if (a > 0 && b > INT_MAX - a) {
        throw overflow_error("Integer overflow occurred");
    }
    return a + b;
}

int main() {
    try {
        int result = safeAdd(INT_MAX, 1);
        cout << "Result: " << result << endl;
    } catch (const overflow_error& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
