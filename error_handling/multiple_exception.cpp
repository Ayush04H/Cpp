#include <iostream>
#include <stdexcept>
using namespace std;

void throwMultiple(int x) {
    if (x == 1) throw runtime_error("Runtime error");
    if (x == 2) throw logic_error("Logic error");
}

int main() {
    try {
        throwMultiple(2);
    } catch (const runtime_error& e) {
        cout << "Caught runtime error: " << e.what() << endl;
    } catch (const logic_error& e) {
        cout << "Caught logic error: " << e.what() << endl;
    }
    return 0;
}
