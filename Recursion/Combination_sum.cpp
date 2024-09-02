/*
INPUT: 4 7
        2 3 6 7
OUTPUT: (2 2 3)(7)
*/
//     Using take and not take
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
using namespace std;
vector<vector<ll>> ans;
void helper(vector<ll> &v, ll target, ll i, ll csum, vector<ll> &temp)
{
        // boundary condition
    if (csum > target)
        return;
        // base condition
    if (i == v.size())
    {
        if (csum == target)
        {
            ans.push_back(temp);
        }
        return;
    }
// take 
    csum += v[i];
    temp.push_back(v[i]);
    helper(v, target, i, csum, temp);
// not take 
    csum -= v[i];
    temp.pop_back();
    helper(v, target, i + 1, csum, temp);
}
void solve()
{
    ll n, target;
    cin >> n >> target;
    vector<ll> v, temp;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        v.push_back(x);
    }
    helper(v, target, 0, 0, temp);
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
    int tc = 1;
    // cin>>tc;

    for (int i = 1; i <= tc; i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
