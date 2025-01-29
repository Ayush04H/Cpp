#include <iostream>
#include <string>
using namespace std;

class MyException : public exception {
    string message;
public:
    MyException(string msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

int main() {
    try {
        throw MyException("This is a custom exception!");
    } catch (const MyException& e) {
        cout << "Caught Exception: " << e.what() << endl;
    }
    return 0;
}
