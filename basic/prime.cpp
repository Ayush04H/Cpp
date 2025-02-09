#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;  // 0 and 1 are not prime
    if (n == 2) return true;   // 2 is the only even prime number
    if (n % 2 == 0) return false;  // Exclude other even numbers

    int sqrtN = sqrt(n);  // Only check up to sqrt(n)
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) return false;
    }

    return true;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPrime(num)) {
        cout << num << " is a prime number." << endl;
    } else {
        cout << num << " is not a prime number." << endl;
    }

    return 0;
}


/*
#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;  // Numbers less than 2 are not prime

    for (int i = 2; i < n; i++) {  // Check divisibility from 2 to n-1
        if (n % i == 0) return false;
    }

    return true;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPrime(num)) {
        cout << num << " is a prime number." << endl;
    } else {
        cout << num << " is not a prime number." << endl;
    }

    return 0;
}

*/