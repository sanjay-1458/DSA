#include <bits/stdc++.h>

using namespace std;

void f(int arr[], int ind, int n)
{
    if (ind == n)
        return;
    cout << arr[ind] << " ";
    f(arr, ind + 1, n);
}

int main()
{
    int arr[] = {1, 2, 3, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    f(arr, 0, n);
    return 0;
}
