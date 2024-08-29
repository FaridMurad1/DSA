/*
Input:
        6
        3 4 5 6 1 2

output:

        4
*/

#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
using namespace std;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    ll lw = 0, hg = n - 1, md, ans = INT_MAX, pos = -1;
    while (lw <= hg)
    {
        md = (lw + hg) / 2;
        if (arr[lw] <= arr[md])
        {
            if (arr[lw] < ans)  // if arr[lw] is minimum value then update position 
            {
                ans = arr[lw];
                pos = lw;
            }
            lw = md + 1;
        }
        else
        {
            if (arr[md] < ans)
            {
                ans = arr[md];
                pos = md;
            }
            hg = md - 1;
        }
    }
    cout << pos << nl;
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
