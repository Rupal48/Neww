#include <iostream>
#include <string>

using namespace std;

bool isConstant(const string& input) {
    for (char c : input) {
        if (!isdigit(c)) {
            return false;  // If any non-digit character is found, it's not a constant.
        }
    }
    return true;  // All characters are digits, so it's a constant.
}

int main() {
    string userInput;

    cout << "Enter a string: ";
    cin >> userInput;

    if (isConstant(userInput)) {
        cout << "The input is a constant." << endl;
    } else {
        cout << "The input is not a constant." << endl;
    }

    return 0;
}