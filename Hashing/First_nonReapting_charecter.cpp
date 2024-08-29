/*
 First non reapting charecter/value in string/ array

    Input:
            s = "leetcode"
    Output:
                0
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
    string s;
    cin >> s;
    ll n = s.size();
    ll freq[26] = {0};
    for (auto it : s)
        freq[it - 'a']++; // populate the frequency array
    for (ll i = 0; i < n; i++)
    {
        if (freq[s[i] - 'a'] == 1) // find the first character with frequency 1
        {
            cout << i << nl;
            return;
        }
    }
    cout << -1 << nl;
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
