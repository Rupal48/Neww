#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> myStack; // Declare an integer stack

    while (true) {
        cout << "Stack Operations:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Enter the value to push (or enter -1 to stop pushing): ";
                cin >> value;
                while (value != -1) {
                    myStack.push(value);
                    cout << value << " has been pushed onto the stack." << endl;
                    cout << "Enter the next value to push (or enter -1 to stop pushing): ";
                    cin >> value;
                }
                break;
            }
            case 2: {
                if (!myStack.empty()) {
                    int topValue = myStack.top();
                    myStack.pop();
                    cout << topValue << " has been popped from the stack." << endl;
                } else {
                    cout << "Stack is empty. Cannot pop." << endl;
                }
                break;
            }
            case 3: {
                if (!myStack.empty()) {
                    cout << "Stack contents: ";
                    stack<int> tempStack;
                    while (!myStack.empty()) {
                        cout << myStack.top() << " ";
                        tempStack.push(myStack.top());
                        myStack.pop();
                    }
                    while (!tempStack.empty()) {
                        myStack.push(tempStack.top());
                        tempStack.pop();
                    }
                    cout << endl;
                } else {
                    cout << "Stack is empty." << endl;
                }
                break;
            }
            case 4: {
                cout << "Exiting program." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }

    return 0;
}