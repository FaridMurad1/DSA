#include<bits/stdc++.h>
using namespace std;
#define ll long long
int chk(vector<int>v,int n)
{
    if(n==v.size()-1)
    return v[n];
    int a=v[n];
    int b=chk(v,n+1);
    return (a*b/(__gcd(a,b)));
}
int main()
{
        vector<int>v={1,2,8,3};
        cout<<chk(v,0)<<endl;
}
