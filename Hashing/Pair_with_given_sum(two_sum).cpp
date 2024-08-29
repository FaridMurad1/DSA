/*
    Pair with given Sum (Two Sum)


    Input:
            5 -2
            0 -1 2 -3 1
    Output:
            Yes

                Time Com        Space Com
    Naive:          O(n^2)           O(1)
    Two Pointer:    O(nlogn)         O(1)
    Binary Search:  O(nlogn)         O(1)
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
void naive(vl &arr, ll n, ll tar)
{
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == tar)
            {
                cout << "Yes" << nl;
                return;
            }
        }
    }
    cout << "No" << nl;
}
void two_pointer(vl &arr, ll n, ll tar)
{
    ll lw = 0, hg = n - 1;
    while (lw < hg)
    {
        ll sum = arr[lw] + arr[hg];
        if (sum == tar)
        {
            cout << "Yes" << nl;
            return;
        }
        else if (sum < tar)
            lw++;
        else
            hg--;
    }
    cout << "No" << nl;
}
void _binarySrc(vl &arr, ll n, ll tar)
{
    for (ll i = 0; i < n; i++)
    {
        ll rem = tar - arr[i];
        if (binary_search(arr.begin(), arr.end(), rem) == 1)
        {
            cout << "Yes" << nl;
            return;
        }
        cout << "NO" << nl;
    }
}
void _hashing(vl &arr, ll n, ll tar)
{
    unordered_map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        ll rem = tar - arr[i];
        if (mp.find(rem) != mp.end())
        {
            cout << "Yes" << nl;
            return;
        }
        mp[arr[i]] = 1;
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
    // naive(arr, n, tar);
    // two_pointer(arr, n, tar);
    //_binarySrc(arr, n, tar);
    _hashing(arr, n, tar);
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
