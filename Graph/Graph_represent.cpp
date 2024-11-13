/*
    Representation of Graph using Adjacency List
    Input:
    5 6
    1 2
    1 3
    2 3
    2 4
    3 5
    4 5
    Output:
    1 -> 2 3 
    2 -> 1 3 4 
    3 -> 1 2 5 
    4 -> 2 5 
    5 -> 3 4 
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj[n + 1];
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <=n; i++)
    {
        cout << i << " -> ";
        for (auto it : adj[i])
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}
