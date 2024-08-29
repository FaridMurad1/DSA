/*
Input
    8
    7 8 1 2 3 4 5 6
Output:
    1


Input
        7
        4 5 6 7 0 1 2

output:
        0
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
    ll lw = 0, hg = n - 1, md, ans = INT_MAX;
    while (lw <= hg)
    {
        md = (lw + hg) / 2;
        if (arr[lw] <= arr[md])   // if left vaue in array sorted then find the minimum value
        {
            ans = min(ans, arr[lw]);
            lw = md + 1;
        }
        else  
        {
            ans = min(ans, arr[md]);
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
