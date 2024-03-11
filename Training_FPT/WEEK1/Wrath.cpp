/*
Namely, the i-th person kills the j-th person
        if and only if j < i and j ≥ i - Li.

    RULE KILL : i kill j -> ****  i > j and j >= i - Li
    RULE ALIVE : j < i - Li (NumToKill)
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int totalGuilty;
    scanf("%d", &totalGuilty);
    // printf("Total Guilty : %d\n", totalGuilty);

    int arrayGuilty[totalGuilty];
    int c;
    for (int i = 0; i < totalGuilty; i++)
    {
        scanf("%d", &c);
        arrayGuilty[i] = c;
    }
    // printf("%d", arrayGuilty[0]);

    int NumToKill = totalGuilty;
    int alive = 0;
    for (int j = totalGuilty - 1; j >= 0; j--)
    {
        // NumToKill = j - arrayGuilty[j];
        if (j < NumToKill)
        {
            alive++;
            // printf("Guilty :%d - I :%d - Alive :%d - Num To Kill :%d \n", arrayGuilty[j], j, alive, NumToKill);
        }
        if (NumToKill > (j - arrayGuilty[j]))
        {
            NumToKill = j - arrayGuilty[j];
        }
    }
    printf("%d", alive);
    return 0;
}