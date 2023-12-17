#include <iostream>
using namespace std;

// function f to exit from the loop
// if the given condition is not true
int f() {
    cout << "Not operator grammar" << endl;
    exit(0);
}

int main() {
    char grm[20][20], c;

    // Here using a flag variable,
    // considering grammar is not an operator grammar
    int i, n, j = 2, flag = 0;

    // taking the number of productions from the user
    cout << "Enter no. of productions : ";
    cin >> n;

    for (i = 0; i < n; i++) cin >> grm[i];

    for (i = 0; i < n; i++) {
        c = grm[i][2];

        while (c != '\0') {

            if (grm[i][3] == '+' || grm[i][3] == '-' || grm[i][3] == '*' || grm[i][3] == '/') flag = 1;
            else {
                flag = 0;
                f();
            }

            if (c == '$') {
                flag = 0;
                f();
            }

            c = grm[i][++j];
        }
    }

    if (flag == 1) cout << "Operator grammar" << endl;

    return 0;
}

// Enter no. of productions : 3
// A=A*A
// B=AA
// A=$
// Not operator grammar