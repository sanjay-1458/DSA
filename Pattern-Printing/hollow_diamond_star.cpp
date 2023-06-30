/*
Printing the hollow diamond star pattern in C++
    *
   * *
  *   *
 *     *
*       *
 *     *
  *   *
   * *
    *
*/
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; ++j)
        {
            if (j == 0 || j == 2 * i)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        for (int j = 0; j < n - i - 1; ++j)
        {
            cout << " ";
        }
        cout << endl;
    }
    int k = n - 1;
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * (k - i) - 1; ++j)
        {
            if (j == 0 || j == 2 * (k - i) - 2)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }

        for (int j = 0; j <= i; ++j)
        {
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}
