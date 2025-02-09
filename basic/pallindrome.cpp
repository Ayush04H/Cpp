#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    if (isPalindrome(input)) {
        cout << input << " is a palindrome!" << endl;
    } else {
        cout << input << " is not a palindrome." << endl;
    }

    return 0;
}


/*
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(const string &str) {
    int left = 0;               // Start pointer
    int right = str.size() - 1; // End pointer

    while (left < right) {
        // Skip non-alphanumeric characters (if needed)
        if (!isalnum(str[left])) {
            left++;
        } else if (!isalnum(str[right])) {
            right--;
        } else {
            // Compare characters ignoring case
            if (tolower(str[left]) != tolower(str[right])) {
                return false;  // Not a palindrome
            }
            left++;
            right--;
        }
    }
    return true; // It's a palindrome
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    if (isPalindrome(input)) {
        cout << "\"" << input << "\" is a palindrome." << endl;
    } else {
        cout << "\"" << input << "\" is not a palindrome." << endl;
    }

    return 0;
}


#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(int number) {
    // Convert the number to a string
    string numStr = to_string(number);
    
    int left = 0;
    int right = numStr.length() - 1;

    // Two-pointer approach
    while (left < right) {
        if (numStr[left] != numStr[right]) {
            return false;  // Not a palindrome
        }
        left++;
        right--;
    }

    return true;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPalindrome(num)) {
        cout << num << " is a palindrome." << endl;
    } else {
        cout << num << " is not a palindrome." << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

bool isPalindrome(int num) {
    int reversed = 0, original = num;
    while (num > 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return reversed == original;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPalindrome(num)) {
        cout << num << " is a palindrome number." << endl;
    } else {
        cout << num << " is not a palindrome number." << endl;
    }

    return 0;
}

*/