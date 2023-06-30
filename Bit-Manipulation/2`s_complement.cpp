#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num = 918, n = 87;
    //2`s complement of n is r
    int r = ~n + 1;
    cout << num + r;
    return 0;
}
