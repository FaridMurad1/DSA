#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
using namespace std;
void solve()
{
    ll n;
    cin >> n;
    ll sol = 0;
    for (ll i = 2; i < n; i++)
    {
        if (n % i == 0)
            sol++;
        while (n % i == 0)
        {
            n /= i;
        }
    }
    if (n > 1)
        sol++;
    cout << sol << nl;
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
