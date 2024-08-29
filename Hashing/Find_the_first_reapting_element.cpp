/*
    Problem link: Find the first repeating element in an array

    Input:
            10 5 3 4 3 5 6

    Output: 
            5

        Time complixity           Space Com

            O(N)                     O(N)
        

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
    {
        if (s.find(arr[i]) != s.end())
        {
            cout << "YES" << nl;
            cout<<arr[i]<<nl;
            return;
        }
        s.insert(arr[i]);
    }
    cout << "NO" << nl;
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
