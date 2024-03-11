#include <bits/stdc++.h>
using namespace std;
int main()
{
    int nA, nB, k, m;
    cin >> nA >> nB;
    cin >> k >> m;

    int arrA[nA + 1], arrB[nB + 1];
    for (int i = 1; i <= nA; i++)
    {
        cin >> arrA[i];
    }
    for (int j = 1; j <= nB; j++)
    {
        cin >> arrB[j];
    }

    if (arrA[k] < arrB[nB - m + 1])
    {
        printf("YES");
        return 0;
    }
    printf("NO");
    return 0;
}