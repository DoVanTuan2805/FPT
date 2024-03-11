#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i = 0;
    string a, b, c;
    cin >> a >> b;
    c = a;
    for (i = a.length() - 1; i >= 0; i--)
    {
        while (c[i] < 'z')
        {
            c[i]++;
            if (c < b)
            {
                cout << c;
                return 0;
            }
        }
        if (c[i] == 'z')
            c[i] = 'a';
    }
    cout << "No such string";
    return 0;
}