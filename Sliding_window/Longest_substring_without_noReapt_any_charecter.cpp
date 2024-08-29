/*
    Input:
        s = cadbzabcd
    Output:
        5

*/

#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
using namespace std;
void Brute_force()
{
    /*
        TC:  0(n^2)
         SC: 0(256)
     */
    string s;
    cin >> s;
    ll n = s.size(), mxlen = 0;
    for (ll i = 0; i < n; i++)
    {
        ll hash[256] = {0};
        for (ll j = i; j < n; j++)
        {
            if (hash[s[j]] == 1)
                break;
            mxlen = max(mxlen, j - i + 1);
            hash[s[j]] = 1;
        }
    }
    cout << mxlen << nl;
}
void Optimized_brute()
{
    /*
           TC: 0(n)
           SC: 0(256)
    */
    string s;
    cin >> s;
    ll n = s.size(), mxlen = 0, lft = 0, rgt = 0;
    ll hash[256] = {0};
    while (rgt < n)
    {
        if (hash[s[rgt]] != 0)
        {
            if (hash[s[rgt]] >= lft)
                lft = hash[s[rgt]] + 1;
        }
        mxlen = max(mxlen, rgt - lft + 1);
        hash[s[rgt]] = rgt;
        rgt++;
    }
    cout << mxlen << nl;
}
void solve()
{
    // Brute_force();
    // Optimized_brute();
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
