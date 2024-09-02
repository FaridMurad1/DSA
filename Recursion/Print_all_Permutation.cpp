/*
    Input
            3
            1 2 3
    Output
            1 2 3
            1 3 2
            2 1 3
            2 3 1
            3 1 2
            3 2 1

*/
/*

    Time Complexity:  N! x N
    Space Complexity:  O(N)
*/
/*
    Input
            3
            1 2 3
    Output
            1 2 3
            1 3 2
            2 1 3
            2 3 1
            3 1 2
            3 2 1

*/
/*

    Time Complexity:  N! x N
    Space Complexity:  O(N)
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl '\n'
void recurPermute(vector<ll> &newarr, vector<ll> &myarr, vector<vector<ll>> &ans, vector<bool> &ck)
{
    if (newarr.size() == myarr.size()) // base case
    {
        ans.push_back(newarr);
        return;
    }
    for (ll i = 0; i < myarr.size(); i++)
    {
        if (!ck[i])
        {
            newarr.push_back(myarr[i]);
            ck[i] = true;
            recurPermute(newarr, myarr, ans, ck);
            ck[i] = false;
            newarr.pop_back();
        }
    }
}
vector<vector<ll>> permute(vector<ll> &myarr)
{
    vector<vector<ll>> ans;
    vector<ll> newarr;
    vector<bool> ck(myarr.size(), false); // boolean array (check it take before or not)
    recurPermute(newarr, myarr, ans, ck);
    return ans;
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    vector<vector<ll>> ans = permute(v);
    for (auto &it : ans)
    {
        for (auto x : it)
            cout << x << " ";
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
