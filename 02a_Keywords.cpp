#include <iostream>
#include <string.h>
using namespace std;
int main() {
    char key[32][10] = {"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
    char str[20];
    cout << "Enter your string : ";
    cin.get(str,20);
    for (int i=0;i<32;i++) {
        if (strcmp(key[i],str)==0) {
            cout << "String Contains Keyword." << endl;
            return 0;
        }
    }
    cout << "String does not contain any keyword." << endl;
    return 0;
}