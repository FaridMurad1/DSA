#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
using namespace std;
void solve()
{
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll hash[13] = {0};
    for (ll i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    ll test;
    cin >> test;
    while (test--)
    {
        ll number;
        cin >> number;
        cout << hash[number] << nl;
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
