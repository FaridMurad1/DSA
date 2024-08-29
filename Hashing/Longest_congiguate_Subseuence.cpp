/*
Input: arr[] = {1, 9, 3, 10, 4, 20, 2}
Output: 4
*/
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
using namespace std;
#define vl vector<ll>
const ll mod = 1000000007;
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
    set<ll> s;
    for (ll i = 0; i < n; i++)
        s.insert(arr[i]);
    ll ans = 1, cnt = 1;
    for (auto it : s)
    {
        if (s.find(it + 1) != s.end())
            cnt++;
        else
            cnt = 1;
        ans = max(ans, cnt);
    }
    cout << ans << nl;
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
