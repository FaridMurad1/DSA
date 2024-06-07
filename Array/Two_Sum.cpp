#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
using namespace std;
void brute()
{
    //  o(n^2)
}
void better()
{
    // TC: o(nlogn)
    // SC: o(n)
    ll n, k;
    cin >> n >> k;
    vector<ll> vec;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        vec.push_back(x);
    }
    ll fst = -1, sec = -1;
    for (auto it : vec)
    {
        ll sub = k - it;
        auto a = find(vec.begin(), vec.end(), sub);
        if (a != vec.end())
        {
            fst = it;
            sec = sub;
            break;
        }
    }
    if (fst == -1 && sec == -1)
    {
        cout << "NO" << nl;
    }
    else
    {
        cout << "YES" << nl;
        cout << fst << " " << sec << nl;
    }
}
void optimal()
{
    ll n, k;
    cin >> n >> k;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    ll lft = 0, rgt = n - 1;
    while (lft < rgt)
    {
        if (arr[lft] + arr[rgt] == k)
        {
            cout << "YES" << nl;
            cout << arr[lft] << " " << arr[rgt] << nl;
            return;
        }
        else if (arr[lft] + arr[rgt] < k)
        {
            lft++;
        }
        else
        {
            rgt--;
        }
    }
    cout << "NO" << nl;
}
void two_sum()
{
    ll n, tr;
    cin >> n >> tr;
    ll arr[n];
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    vector<pair<int, int>> vp;
    vector<int> ans;
    for (ll i = 0; i < n; i++)
    {
        pair<int, int> pr = {arr[i], i};
        vp.push_back(pr);
    }
    sort(vp.begin(), vp.end());
    ll lft = 0, rgt = n - 1;
    while (lft < rgt)
    {
        ll sum = vp[lft].first + vp[rgt].first;
        if (sum == tr)
        {
            ans.push_back(vp[lft].second);
            ans.push_back(vp[rgt].second);
            break;
        }
        if (sum < tr)
            lft++;
        else
            rgt--;
    }
    return ans;
}
int main()
{
    int tc = 1;
    // cin>>tc;
    for (int i = 1; i <= tc; i++)
    {
        // cout<<"Case #"<<i<<": ";

        // brute();
        // better();
        optimal(); // two pointer
        // two_sum();    //leetcode problem

        //  solve();
    }
    return 0;
}
