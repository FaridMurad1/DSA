/*
   Subarray with 0 sum

   https://www.geeksforgeeks.org/find-if-there-is-a-subarray-with-0-sum/

    Input:
            5 -2
            4 2 -3 1 6
    Output:
            Yes

                Time Com        Space Com
    Naive:          O(n)           O(1)
    Hashing:        O(n)             O(n)
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
void naive(vl &arr, ll n)
{
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            cout << "Yes" << nl;
            return;
        }
    }
    cout << "No" << nl;
}
// void two_pointer(vl &arr, ll n, ll tar)
// {
// }
// void _binarySrc(vl &arr, ll n, ll tar)
// {
// }
void _hashing(vl &arr, ll n)
{
    ll sum = 0;
    unordered_map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0 || mp[sum])
        {
            cout << "Yes" << nl;
            return;
        }
    }
    cout << "No" << nl;
}
void solve()
{
    ll n, tar;
    cin >> n >> tar;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    // naive(arr, n);
    // two_pointer(arr, n, tar);
    //_binarySrc(arr, n, tar);
    _hashing(arr, n);
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
