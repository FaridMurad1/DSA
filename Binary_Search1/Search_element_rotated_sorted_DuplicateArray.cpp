/*
Input:
9 2
3 3 1 2 3 3 3 3 3

*/


#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
using namespace std;
void solve()
{
    ll n, tar;
    cin >> n >> tar;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    ll lw = 0, hg = n - 1, md, ans = n;
    while (lw <= hg)
    {
        md = (lw + hg) / 2;
        if (arr[md] == tar)
        {
            ans = md;
            break;
        }
        if (arr[lw] == arr[md] && arr[md] == arr[hg])
        {
            lw++, hg--;
            continue;
        }
        else if (arr[lw] <= arr[md])
        {
            if (arr[lw] <= tar && tar <= arr[md])
                hg = md - 1;
            else
                lw = md + 1;
        }
        else
        {
            if (arr[md] <= tar && tar <= arr[hg])
                lw = md + 1;
            else
                hg = md - 1;
        }
    }
    cout << ans << nl;
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
