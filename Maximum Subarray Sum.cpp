#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll sum = 0, maxi = LONG_MIN;
    ll n;
    cin >> n;
    vector<ll> nums(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    for (ll i = 0; i < n; i++)
    {
        sum = sum + nums[i];
        maxi = max(maxi, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    cout << maxi << endl;
    return 0;
}