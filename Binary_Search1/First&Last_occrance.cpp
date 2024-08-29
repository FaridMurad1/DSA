/*
Input:
    10 8 
    2 3 5 8 8 8 8 9 11 12
Output
    4
    7

*/

#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
using namespace std;
ll Fast_occurence(vector<ll> &arr, ll n, ll tar)
{
    ll lw = 0, hg = n - 1, fst = -1, md;
    while (lw <= hg)
    {
        md = (lw + hg) / 2;
        if (arr[md] == tar)
        {
            fst = md + 1;
            hg = md - 1;
        }
        else
            lw = md + 1;
    }
    return fst;
}
ll Last_occurence(vector<ll> &arr, ll n, ll tar)
{
    ll lw = 0, hg = n - 1, lst = -1, md;
    while (lw <= hg)
    {
        md = (lw + hg) / 2;
        if (arr[md] == tar)
        {
            lst = md + 1;
            lw = md + 1;
        }
        else
            hg = md - 1;
    }
    return lst;
}
void solve()
{
    ll n, tar;
    cin >> n >> tar;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    cout << Fast_occurence(arr, n, tar) << nl;
    cout << Last_occurence(arr, n, tar) << nl;
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
