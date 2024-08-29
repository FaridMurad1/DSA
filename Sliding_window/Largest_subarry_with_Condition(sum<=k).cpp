/*
https://www.geeksforgeeks.org/longest-sub-array-sum-k/

    Input
        5 14
        2 5 9 7 10
    Output
        3
*/

#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
using namespace std;
void solve()
{
    ll n, k;
    cin >> n >> k;
    ll arr[n];
    for (ll i = 0; i < n; i++)
        cin >> arr[i];

    /*  Brute force
        TC: 0(n^2)
        SC: 0(1)
     */

    ll mxlen = 0, sum;
    for (ll i = 0; i < n; i++)
    {
        sum = 0;
        for (ll j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum <= k)
                mxlen = max(mxlen, j - i + 1);
        }
    }
    cout << mxlen << nl;

    /*
        Optimal solution

            TC: 0(n+n)
            SC: 0(1)
    */

    ll l = 0, r = 0, mxlen = 0, sum = 0;
    while (r < n)
    {
        sum += arr[r];
        while (sum > k)
        {
            sum -= arr[l];
            l++;
        }
        if (sum <= k)
        {
            mxlen = max(mxlen, r - l + 1);
        }
        r++;
    }
    cout << mxlen << nl;
}
int main()
{
    int tc = 1;
    // cin>>tc;
    for (int i = 1; i <= tc; i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
