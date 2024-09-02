#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
using namespace std;
#define vl vector<ll>
vector<vl> ans;

void fun(vl &arr, vl &vec, ll ind, ll n) {
    if (ind == n) {
        ans.push_back(vec);
        return;
    }
    // take
    vec.push_back(arr[ind]);
    fun(arr, vec, ind + 1, n);
    vec.pop_back();
    // not take
    fun(arr, vec, ind + 1, n);
}

void solve() {
    ll n;
    cin >> n;
    vl arr(n);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    vl vec;
    ans.clear();  // Clear the global vector for each test case
    fun(arr, vec, 0, n);
    
    // Print all subsets (optional)
    for (auto subset : ans) {
        for (auto x : subset)
            cout << x << ' ';
        cout << nl;
    }
}

int main() {
    int tc = 1;
    // cin >> tc;
    for (int i = 1; i <= tc; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
