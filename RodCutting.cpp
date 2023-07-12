#include<bits/stdc++.h>
using namespace std;
int dp[10005];
int rodcut(int n,int arr[])
{
    if(n==0)
    {
        return 0;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(n-i>=0)
        {
            ans=max(ans,rodcut(n-i,arr)+arr[i-1]);
        }
    }
    return dp[n]=ans;
}
int main()
{
    freopen("rod.txt", "r", stdin);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rodcut(n,arr)<<endl;
}
