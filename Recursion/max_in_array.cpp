#include <bits/stdc++.h>

using namespace std;

int f(int arr[], int ind, int n)
{
    if (ind == n - 1)
    {
        return arr[ind];
    }
    return max(arr[ind], f(arr, ind + 1, n));
}

int main()
{
    int arr[] = {-10, 0, 8, 99, 17, 22};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << f(arr, 0, n);
}
