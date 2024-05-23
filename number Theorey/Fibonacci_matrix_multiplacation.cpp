#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
using namespace std;
const ll md=1000000007;
const ll N = 10;
ll f[N][N], I[N][N];
ll mul(ll I[][N], ll f[][N], ll n)
{
    ll sol[n + 1][n + 1];
    for (ll i = 0; i <n; i++)
    {
        for (ll j = 0; j <n; j++)
        {
            sol[i][j] = 0;
            for (ll k = 0; k < n; k++)
            {
                sol[i][j] += ((I[i][k] * f[k][j])%md);
            }
        }
    }
    for (ll i = 0; i <2; i++)
    {
        for (ll j = 0; j < 2; j++)
        {
            I[i][j] = sol[i][j];   
        }
    }
}
void solve(ll a, ll b, ll p)
{
    I[0][0] = I[1][1] = 1;    // I  matrix
    I[0][1] = I[1][0] = 0;


    f[0][0] = 0;
    f[0][1] = f[1][0] = f[1][1] = 1;    //fibonacci multi** matrix
    p--;
    while (p)
    {
        if (p & 1)
        {
            mul(I, f, 2);
            p--;
        }
        else
        {
            mul(f, f, 2);
            p /= 2;
        }
    }
    ll ans=a*I[0][1]+b*I[1][1];     // next valu count
    cout<<ans%md<<nl;
}
void solve()
{
    ll a0, a1, p;
    cin >> a0 >> a1 >> p;
    solve(a0, a1, p);
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
