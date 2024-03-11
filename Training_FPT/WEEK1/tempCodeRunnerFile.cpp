#include <bits/stdc++.h>
using namespace std;
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
    for (int j = n - 1; j >= 0; j--)
    {
        numBookR++;
        sum += arr[j];
        if (t == sum)
        {
            printf("%d", numBookR);
            return 0;
        }
        else if (t < sum)
        {
            numBookR--;
            // printf("Num Book Read : %d\n", numBookR);
            printf("%d", numBookR);
            return 0;
        }
    }
    if (t > sum)
    {
        printf("%d", numBookR);
    }
    return 0;
}