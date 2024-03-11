#include <bits/stdc++.h>
using namespace std;

/*
Valera decided to choose an arbitrary book with number i and read the books one by one, starting from this book.
In other words, he will first read book number i, then book number i + 1, then book number i + 2 and so on.
He continues the process until he either runs out of the free time or finishes reading the n-th book.
Valera reads each book up to the end, that is, he doesn't start reading the book
if he doesn't have enough free time to finish reading it.
Print the maximum number of books Valera can read.

Input
The first line contains two integers n and t (1 ≤ n ≤ 105; 1 ≤ t ≤ 109) —
the number of books and the number of free minutes Valera's got.
The second line contains a sequence of n integers a1, a2, ..., an (1 ≤ ai ≤ 104),
where number ai shows the number of minutes that the boy needs to read the i-th book.

Output
Print a single integer — the maximum number of books Valera can read.

Ex1:
4 5
3 1 2 1
-> 3

Ex2:
3 3
2 2 3
-> 1
*/
int main()
{
    int n, t, numBookR = 0, sum = 0;
    cin >> n >> t;
    if (n == 0 || t == 0)
    {
        return 0;
    }
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 0)
        {
            return 0;
        }
    }
    // printf("%d\n", strlen(arr));
    // 5 -> 1 1 4
    int k = -1;
    for (int j = 0; j < n; j++)
    {
        if (sum + arr[j] <= t)
        {
            sum += arr[j];
        }
        else
        {
            sum += arr[j];
            while (sum > t)
            {
                k++;
                sum -= arr[k];
            }
        }
        numBookR = max(numBookR, j - k);
    }
    printf("%d", numBookR);
    return 0;
}