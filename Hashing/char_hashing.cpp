/*abcdabehf
5
a
g
h
b
c
*/
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
using namespace std;
ll hashh[26] = {0};
void solve()
{
    string s;
    cin >> s;
    ll n = s.size();
    for (ll i = 0; i < n; i++)
    {
        hashh[s[i] - 'a']++;
    }
    ll tst;
    cin >> tst;
    while (tst--)
    {
        char c;
        cin >> c;
        cout << hashh[c - 'a'] << nl;
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
