
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

void processOutput(string array)
{
    int correct = -1;
    int result = 0;
    int lastPrefix = 0;
    for (int i = 0; i < array.length(); i++) // 0 - end array
    {
        if (array[i] == '<')
        {
            correct++;
            lastPrefix += 1;
        }
        else if (array[i] == '>')
        {
            if (correct >= 0)
            {
                correct--;
                lastPrefix += 1;
            }
            else
            {
                break;
            }
        }

        if (correct == -1)
        {
            result = lastPrefix;
        }
    }
    // cout << result << endl;
    printf("%d\n", result);
}
void inputParam()
{
    int num;
    cin >> num;
    if (num <= 500)
    {
        int prevLength = 0;
        while (num--)
        {
            string str;
            cin >> str;
            if (str.length() + prevLength >= (5 * pow(10, 6)))
            {
                break;
            }
            if (str.length() >= pow(10, 6))
            {
                break;
            }
            else
            {
                prevLength += str.length();
                processOutput(str);
            }
        }
    }
}

int main()
{
    inputParam();
    return 0;
}
