/*
    first find all substring and then find which substring has all three charecter
    if any substring have all three charecter then count++

        Input:
                bbacba
         output:
                9

*/
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
using namespace std;
void optimal()
{
    string s;
    cin >> s;
    ll i = 0, j = 0, ans = 0;
    unordered_map<char, ll> mp;
    while (j < s.size())
    {
        mp[s[j]]++;
        while (mp.size() == 3)
        {
            ans += (s.size() - j);
            mp[s[i]]--;
            if (mp[s[i]] == 0)
            {
                mp.erase(s[i]);
            }
            i++;
        }
        j++;
    }
    cout << ans << nl;
}
void brute_force()
{
    string s;
    cin >> s;
    ll ans = 0, n = s.size();
    for (ll i = 0; i < n; i++)
    {
        ll hash[3] = {-1};
        for (ll j = i; j < n; j++)
        {
            hash[s[j] - 'a'] = 1;
            if (hash[0] + hash[1] + hash[2] == 3)
                ans++;
        }
    }
    cout << ans << nl;
}
void solve()
{
    optimal();   //  0(N)   0(N)
    brute_force();   // 0(N^2)  0(N)
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
