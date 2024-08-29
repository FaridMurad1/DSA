/*
    Input:
            5
            0 -1 2 -3 1
    Output:
                -3 1 2
                -1 1 0
*/
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
using namespace std;
#define vl vector<ll>
void vdbg(vector<int> &arr)
{
    for (auto it : arr)
        cout << it << " ";
    cout << nl;
}
void dbg(ll n)
{
    cout << n << " ";
    cout << nl;
}
void solve()
{
    ll n;
    cin >> n;
    vl arr(n);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<ll>> ans;
    unordered_map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            ll val = 0 - arr[i] - arr[j];
            if (mp.find(val) != mp.end())
            {
                vector<ll> sol;
                sol.push_back(arr[i]);
                sol.push_back(arr[j]);
                sol.push_back(val);
                // sol.push_back({arr[i], arr[j], val});
                ans.push_back(sol);
            }
        }
        mp[arr[i]] = i;
    }
    sort(ans.begin(), ans.end());
    for (auto it : ans)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << nl;
    }
}
int main()
{
    ll tc = 1;
    // cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        solve();
    }
    return 0;
}
