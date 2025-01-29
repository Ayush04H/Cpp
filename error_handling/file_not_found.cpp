#include <iostream>
#include <fstream>
using namespace std;

void openFile(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        throw runtime_error("File not found");
    }
}

int main() {
    try {
        openFile("nonexistent.txt");
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
