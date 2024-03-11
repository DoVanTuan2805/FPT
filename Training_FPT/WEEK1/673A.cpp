#include <bits/stdc++.h>
using namespace std;
/*
    Each minute can be either interesting or boring.
    If 15 consecutive minutes are boring then Limak immediately turns TV off.

    You know that there will be n interesting minutes t1, t2, ..., tn.
    Your task is to calculate for how many minutes Limak will watch the game.

    Input :
    The first line of the input contains one integer n (1 ≤ n ≤ 90) — the number of interesting minutes.
    The second line contains n integers t1, t2, ..., tn (1 ≤ t1 < t2 < ... tn ≤ 90), given in the increasing order.

    Output:
    Print the number of minutes Limak will watch the game.

    Ex1:
    3
    7 20 88
    -> 35

    Ex2:
    9
    16 20 30 40 50 60 70 80 90
    -> 15

    Ex1:
    9
    15 20 30 40 50 60 70 80 90
    -> 90

9
15 20 30 40 50 60 70 80 85

9
15 20 30 40 50 60 70 71 72
*/
int main()
{
    int n, i, t = 16, start = 0, sum = 0;
    cin >> n;

    int arr[n];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (i = 0; i < n; i++)
    {
        if (arr[i] - start <= 15)
        {
            start = arr[i];
            sum = start;
        }
        else if (arr[i] - start > 15)
        {
            sum += 15;
            cout << sum << endl;
            return 0;
        }
    }
    sum = max(sum, sum + 15);
    sum = min(sum, 90);
    // if (sum > 90)
    // {
    //     sum = 90;
    // }
    cout << sum << endl;
    return 0;
}