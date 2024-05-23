#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
using namespace std;
const ll N = 101;
ll arr[N][N], I[N][N];
const int md = 1000000007;
ll mul(ll arr[][N],ll B[][N],ll n)
{
        ll res[n+1][n+1];
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=n;j++)
            {
                res[i][j]=0;
                for(ll k=1;k<=n;k++)
                {
                    ll x=(arr[i][k]*B[k][j])%md;
                    res[i][j]=(res[i][j]+x)%md;
                }
            }
        }
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=n;j++)
            {
                arr[i][j]=res[i][j];
            }
        }
}
ll power(ll ar[][N], ll n, ll p)
{
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            if (i == j)
                I[i][j] = 1;
            else
                I[i][j] = 0;
        }
    }
    while (p)
    {
        if (p & 1)
        {
            mul(I, ar, n);
            p--;
        }
        else
        {
            mul(ar, ar, n);
            p /= 2;
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            ar[i][j] = I[i][j];
        }
    }
}
void solve()
{
    ll n, p;
    cin >> n >> p;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }
    power(arr, n, p);
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << nl;
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
