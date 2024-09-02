
/*
Input:
        abc

Output:
        abc
        ab
        ac
        a
        bc
        b
        c

*/

#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
using namespace std;
void fun(string s, string temp, ll ind)
{
    if (ind == s.size()) // base case
    {
        cout << temp;
        if(temp.size()==0)
                cout<<"{}";
        cout<<nl;
        return;
    }
    /*
    another process

         if (ind == s.size()) // base case
            {
                v.push_back(temp);
                sort(v.begin(), v.end());
                for (auto it : temp)
                    cout << it;
                cout << nl;
                return;
            }
            
    */

    // take
    fun(s, temp + s[ind], ind + 1);
    // not take
    fun(s, temp, ind + 1);
}
void solve()
{
    string s;
    cin >> s;
    string temp = "";
    fun(s, temp, 0);
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
