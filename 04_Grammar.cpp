#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    bool flag = true; // Initialize flag to true

    cout << "The grammar is: aSa" << endl;
    cout << "Enter the string to be checked: " << endl;
    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'a')
        {
            flag = true;
        }
        else
        {
            flag = false;
            break; // Exit the loop as soon as a non-'a' character is found
        }
    }

    if (flag)
    {
        cout << "String belongs to the grammar." << endl;
    }
    else
    {
        cout << "String does not belong to the grammar." << endl;
    }

    return 0;
}