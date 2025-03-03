#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    multiset<int> arr;
    vector<int> arr1(n, 0);
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        arr.insert(a);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    for (int i = 0; i < n; ++i)
    {

        auto it = arr.lower_bound(arr1[i]);

        if (it != arr.end() && *it == arr1[i])
        {
            cout << *it << '\n';
            arr.erase(it);
            continue;
        }

        if (it != arr.begin())
        {
            --it;
            cout << *it << '\n';
            arr.erase(it);
            continue;
        }
        else
        {
            cout << -1 << '\n';
        }
    }
    return 0;
}
