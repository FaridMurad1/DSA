/*
Input:
    10 8
    2 3 6 7 8 8 8 9 11 12
Output
    5
    8

*/

#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
using namespace std;
ll Lower_bound(vector<ll> &arr, ll n, ll tar)
{
    ll lw = 0, hg = n - 1, ans = -1, md;
    while (lw <= hg)
    {
        md = (lw + hg) / 2;
        if (arr[md] >= tar)
        {
            ans = md + 1;
            hg = md - 1;
        }
        else
            lw = md + 1;
    }
    return ans;
}
ll Upper_bound(vector<ll> &arr, ll n, ll tar)
{
    ll lw = 0, hg = n - 1, ans = -1, md;
    while (lw <= hg)
    {
        md = (lw + hg) / 2;
        if (arr[md] > tar)
        {
            ans = md + 1;
            hg = md - 1;
        }
        else
            lw = md + 1;
    }
    return ans;
}
void solve()
{
    ll n, tar;
    cin >> n >> tar;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    cout << Lower_bound(arr, n, tar) << nl;
    cout << Upper_bound(arr, n, tar) << nl;
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
