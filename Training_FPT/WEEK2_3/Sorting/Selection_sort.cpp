#include <bits/stdc++.h>
using namespace std;
// 3, 2, 5, 7, 6
void selectionSort(int arr[], int n)
{
    int min_index = 0;
    for (int i = 0; i < n; i++)
    {
        min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap(arr[min_index], arr[i]);
        }
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
    selectionSort(arr, 5);
    display(arr, 5);
    return 0;
}