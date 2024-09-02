#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
using namespace std;
void fun(ll arr[], vector<ll> &vec, ll ind, ll n)
{
    if (ind == n)
    {
        for (auto it : vec)
            cout << it << " ";
        if (vec.size() == 0)
            cout << "{}";
        cout << nl;
        return;
    }
    // take
    vec.push_back(arr[ind]);
    fun(arr, vec, ind + 1, n);
    // not take
    vec.pop_back();
    fun(arr, vec, ind + 1, n);
}
void solve()
{
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    vector<ll> vec;
    fun(arr, vec, 0, n);
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
