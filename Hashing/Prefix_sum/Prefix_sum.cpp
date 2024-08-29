/*
Input:
        6 3
        1 6 4 2 5 3
        0 3
        1 4
        2 5
Output:
        11
        12
        11

Describe:
        arr------ 1   6   4    2    5     3
        pref------1   7   11   13   18    21

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

vl psum(const vl &a)
{
    ll sz = a.size();
    vl psum(sz + 1);
    for (int i = 0; i < sz; ++i)
        psum[i + 1] = psum[i] + a[i];
    // or partial_sum(begin(a),end(a),begin(psum)+1);
    return psum;
}
int main()
{
    int N, Q;
    cin >> N >> Q;
    vl a(N);
    for (ll &x : a)
        cin >> x;
    vl p = psum(a);
    for (auto it : p)
        cout << it << " ";
    cout << "\n";
    for (int i = 0; i < Q; ++i)
    {
        int l, r;
        cin >> l >> r;
        if (l == 0)
            cout << p[r] << "\n";
        else
            cout << p[r] - p[l] << "\n";
    }
}
