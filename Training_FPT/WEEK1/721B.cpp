/*
Vanya will enter passwords in order of non-decreasing their lengths,
and he will enter passwords of same length in arbitrary order.
Just when Vanya will have entered the correct password, he is immediately authorized on the site.
****Vanya will not enter any password twice.

**Entering any passwords takes one second for Vanya.
But if Vanya will enter wrong password k times,
then he is able to make the next try only 5 seconds after that.
Vanya makes each try immediately, that is, at each moment when Vanya is able to enter password, he is doing that.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string passReal, pass[100];
    int totalPass, k;

    cin >> totalPass >> k >> passReal;

    for (int i = 0; i < totalPass; i++)
    {
        cin >> pass[i];
    }

    int ctnL = 0, ctnLe = 0;
    int lengthPass = passReal.length();
    for (int i = 0; i < totalPass; i++)
    {
        // cout << pass[i] << endl;
        if (pass[i].length() < lengthPass)
        {
            ctnL++;
        }
        else if (pass[i].length() > lengthPass)
        {
            ctnLe++;
        }
    }

    int bestCase = ctnL + (ctnL / k) * 5 + 1;
    int worstCase = ctnLe + ((ctnLe - 1) / k) * 5;
    cout << bestCase << endl;
    cout << worstCase << endl;
    return 0;
}