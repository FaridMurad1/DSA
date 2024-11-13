/*
Input:
5 4
1 2
1 3
2 4
3 5
Output:
1 2 3 4 5
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100000];
bool vis[100000];
void dfs(int node)
{
    queue<int> q;
    q.push(node);
    vis[node] = true;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout << curr << " ";
        for (auto it : adj[curr])
        {
            if (!vis[it])
            {
                vis[it] = true;
                q.push(it);
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int source;
    cin >> source;
    dfs(source);
    return 0;
}
