#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
using namespace std;
vector<ll>v;
void sieve(ll n)
{
    ll primes[100001];
    memset(primes,1,sizeof(primes));
    for(ll i=2;i<=sqrt(n);i++)
    {
        if(primes[i])
        {
            for(ll j=i*i;j<=n;j+=i)
            {
                primes[j]=0;
            }
        }
    }
    for(ll i=2;i<=n;i++)
    {
        if(primes[i])
        {
            v.push_back(i);
        }
    }
}
void chk(ll l,ll r)
{
    if(l==1)l++;
    ll sz=r-l+1;
    ll arr[sz];
    memset(arr,1,sizeof(arr));
    for(ll p:v)
    {
        if(p*p<=r)
        {
            ll val=(l/p)*p;
            if(val<l)val+=p;
            for(;val<=r;val+=p)
            {
                if(val!=p)
                arr[val-l]=0;
            }
        }
    }
    for(ll i=0;i<sz;i++)
    {
        if(arr[i])
        cout<<l+i<<" ";
    }
    cout<<nl;

}
void solve()
{
    ll l,r;
    cin>>l>>r;
    chk(l,r);
}
int main()
{
    sieve(100000);
    int tc = 1;
    // cin>>tc;

    for (int i = 1; i <= tc; i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
