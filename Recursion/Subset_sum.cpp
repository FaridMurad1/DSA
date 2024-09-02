/*
    Input: 
    6 9
    3 34 4 12 5 2

    output:
    3 4 2
    4 5

*/
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
using namespace std;

void findSubsets(vector<int> &a, int n, int sum, int index, vector<int> &current, vector<vector<int>> &result)
{
    // Base case: if the end of the array is reached
    if (index == n)
    {
        if (sum == 0)
        {
            result.push_back(current); // If the current sum is equal to the target sum, add the subset to the result
        }
        return;
    }
    
    // take
    current.push_back(a[index]);
    findSubsets(a, n, sum - a[index], index + 1, current, result);
    current.pop_back(); // Backtrack

    // Not take
    findSubsets(a, n, sum, index + 1, current, result);
}

void solve()
{
    int n, sum;
    cin >> n >> sum;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> current;        // current subset
    vector<vector<int>> result; // all valid subsets
    findSubsets(a, n, sum, 0, current, result);
    for (auto &subset : result)
    {
        for (int value : subset)
            cout << value << " ";
        cout << nl;
    }
}
int main()
{
    int tc = 1;
    // cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        solve();
    }
    return 0;
}
