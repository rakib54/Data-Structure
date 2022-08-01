#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // find max
    int m = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (m < arr[i])
        {
            m = arr[i];
        }
    }
    
    // create counting array
    int count[m + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    // cumulative sum
    for (int i = 1; i <= m; i++)
    {
        count[i] += count[i - 1];
    }

    // final Array
    int f[n];
    for (int i = n - 1; i >= 0; i--)
    {
        count[arr[i]]--;
        int k = count[arr[i]]--;
        f[k] = arr[i];
    }

    // print final array
    for (int i = 0; i < n; i++)
    {
        cout << f[i] << " ";
    }

    return 0;
}
