#include <iostream>
using namespace std;

void fibonacciIterative(int n) {
    int a = 0, b = 1;
    
    if (n <= 0) return;
    
    cout << "Fibonacci series (Iterative): ";
    for (int i = 0; i < n; i++) {
        cout << a << " ";
        int next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of terms for Fibonacci series: ";
    cin >> n;

    fibonacciIterative(n);

    return 0;
}
/*
#include <iostream>
using namespace std;

void fibonacciIterative(int n) {
    int a = 0, b = 1;
    
    if (n <= 0) return;
    
    cout << "Fibonacci series (Iterative): ";
    for (int i = 0; i < n; i++) {
        cout << a << " ";
        int next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of terms for Fibonacci series: ";
    cin >> n;

    fibonacciIterative(n);

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int fibonacciDP(int n, vector<int> &dp) {
    // Base cases
    if (n <= 1) return n;

    // Return cached result if available
    if (dp[n] != -1) return dp[n];

    // Compute and store the result
    dp[n] = fibonacciDP(n - 1, dp) + fibonacciDP(n - 2, dp);
    return dp[n];
}

int main() {
    int n;
    cout << "Enter the number of terms for Fibonacci series: ";
    cin >> n;

    vector<int> dp(n + 1, -1);

    cout << "Fibonacci series (DP with Memoization): ";
    for (int i = 0; i < n; i++) {
        cout << fibonacciDP(i, dp) << " ";
    }
    cout << endl;

    return 0;
}

*/