/*
    Problem: https://leetcode.com/problems/3sum-with-multiplicity/
    Input:
        6 5
        1 1 2 2 2 2
    Output:
        12

*/

#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
using namespace std;
#define vl vector<ll>
const ll mod = 1000000007;
vector<vector<ll>> ans;
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
void Using_binarysearch()
{
    ll n, tar;
    cin >> n >> tar;
    vl arr(n);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            ll val = tar - arr[i] - arr[j];
            ll lw = lower_bound(arr.begin() + j + 1, arr.end(), val) - arr.begin();
            ll up = upper_bound(arr.begin() + j + 1, arr.end(), val) - arr.begin() - 1;
            if (arr[lw] == val && lw <= up)
                ans += up - lw + 1;
        }
    }
    cout << ans << nl;
}
void Using_hashing()
{
    ll n, tar;
    cin >> n >> tar;
    vl arr(n);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    unordered_map<ll, ll> mp;
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            ll val = tar - arr[i] - arr[j];
            // Check if there exists an element in the map which can be paired with form the sum
            if (mp.find(val) != mp.end())
            {
                ans += mp[val];  //  Frequency
            }
        }
        mp[arr[i]]++;   //Increment the count of the current element in the map
    }
    cout << ans << nl;
}
int main()
{
    ll tc = 1;
    // cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        // Using_binarysearch();
        Using_hashing();
    }
    return 0;
}
