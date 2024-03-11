#include <bits/stdc++.h>
using namespace std;
// 3, 2, 5, 7, 6
void bubbleSort(int arr[], int n)
{
    bool swapValue;
    for (int i = 0; i < n; i++)
    {
        swapValue = false;
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapValue = true;
            }
        }
        if (swapValue != true)
            break;
    }
}
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[5] = {3, 2, 5, 1, 6};
    bubbleSort(arr, 5);
    display(arr, 5);
    return 0;
}