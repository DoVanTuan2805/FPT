#include <bits/stdc++.h>

/*
    INPUT : zerus
    start position 'a' (97)
    from 'a' to 'z' (1 rotation counterclockwise),
    from 'z' to 'e' (5 clockwise rotations),
    from 'e' to 'u' (10 rotations counterclockwise),
    from 'u' to 's' (2 counterclockwise rotations).

    total : 18 rotation

    begin   97 = 0
    end     122 = 25
    middle  12 or 13
*/

using namespace std;
int main()
{
    string inputStr;
    cin >> inputStr;
    // cout << inputStr << endl;
    int round = 0;
    int dimemsion = 0;
    dimemsion = abs(inputStr[0] - 'a'); // z(122) - a(97) = 25
    if (dimemsion <= 13)                // small than midlle
    {
        round += dimemsion;
    }
    else // large than middle
    {
        round += (26 - dimemsion);
    }
    for (int i = 0; i < inputStr.length() - 1; i++)
    {
        // cout << "I :" << i << endl;
        dimemsion = abs(inputStr[i + 1] - inputStr[i]);
        if (dimemsion <= 13) // small than midlle
        {
            round += dimemsion;
        }
        else // large than middle
        {
            round += (26 - dimemsion);
        }
        // cout << "Round :" << round << endl;
    }
    cout << round;
    return 0;
}