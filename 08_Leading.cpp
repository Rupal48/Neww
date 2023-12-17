#include <iostream>
#include <string.h>
using namespace std;
void install(char x, char y);
void pop();
int pon(char u);
int pot(char v);
int checkstatus(int a, int b);

int n, d, f, xn, xt, top = -1;
char X, Y;
int a[20][20];
char terminal[20], nonterm[20];

struct production
{
    char l;
    char r[10];
};

struct stack
{
    char nt;
    char t;
};

struct stack st[20];
struct production prod[20];

int main()
{

    cout << "Provide the number of terminals: ";
    cin >> d;
    cout << "Provide the terminal symbols for your production: ";
    for (int k = 0; k < d; k++)
    {
        cin >> terminal[k];
    }

    cout << "\n Provide the number of non-terminals: ";
    cin >> f;
    cout << "Provide the non-terminal symbols for your production:";
    for (int k = 0; k < f; k++)
    {
        cin >> nonterm[k];
    }

    cout << "\nHow many productions you want to Provide?? ";
    cin >> n;
    for (int i = 0; i <= n - 1; i++)
    {
        cout << "Provide the " << i + 1 << " production: ";
        cin >> prod[i].l;
        cout << "->";
        cin >> prod[i].r;
    }

    for (int p = 0; p < f; p++)
    {
        for (int q = 0; q < d; q++)
        {
            a[p][q] = 0;
        }
    }

    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (prod[i].r[0] == terminal[j])
                install(prod[i].l, prod[i].r[0]);
            else if (prod[i].r[1] == terminal[j])
                install(prod[i].l, prod[i].r[1]);
        }
    }

    while (top > -1)
    {
        pop();
        for (int c = 0; c <= n - 1; c++)
        {
            if (prod[c].r[0] == X)
                install(prod[c].l, Y);
        }
    }

    // Output
    cout << "\n\n----------------------------------------------------------------";
    cout << "\n     leading elements are:-  ";
    cout << "\n\n-----------------------------------------------------------------";

    cout << endl << " ";
    for (int w = 0; w < d; w++)
        cout << " " << terminal[w];
    cout << endl;
    for (int p = 0; p < f; p++)
    {
        cout << nonterm[p] << " ";
        for (int q = 0; q < d; q++)
        {
            cout << a[p][q] << " ";
        }
        cout << endl;
    }

}

void install(char x, char y)
{
    int g;
    xn = pon(x);
    xt = pot(y);
    g = checkstatus(xn, xt);
    if (g == 0)
        return;
    else if (g == 1)
    {
        top++;
        st[top].nt = x;
        st[top].t = y;
        a[xn][xt] = 1;
    }
}

void pop()
{
    X = st[top].nt;
    Y = st[top].t;
    top--;
}

int pon(char u)
{
    for (int x = 0; x < f; x++)
    {
        if (u == nonterm[x])
            return x;
    }
}

int pot(char v)
{
    for (int x = 0; x < d; x++)
    {
        if (v == terminal[x])
            return x;
    }
}
int checkstatus(int xn, int xt)
{
    if (a[xn][xt] == 1)
        return 0;
    else
        return 1;
}

// Provide the number of terminals: 3
// Provide the terminal symbols for your production: a b c

//  Provide the number of non-terminals: 3
// Provide the non-terminal symbols for your production:A B C

// How many productions you want to Provide?? 3
// Provide the 1 production: A
// ->BC
// Provide the 2 production: B
// ->aAC
// Provide the 3 production: C
// ->bCc


// ----------------------------------------------------------------
//      leading elements are:-

// -----------------------------------------------------------------
//   a b c
// A 1 0 0
// B 1 0 0
// C 0 1 0