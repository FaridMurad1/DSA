#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10001];
int vis[10001], col[10001];
bool dfs(int node, int c)
{
    vis[node] = 1;
    col[node] = c;
    for (int child : adj[node])
    {
        if (!vis[child])
        {
            if (dfs(child, c ^ 1) == false)
                return false;
        }
        else
        {
            if (col[node]==col[child])
                return false;
        }
    }
    return true;
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
    bool ans = dfs(1, 1);
    if (ans)
        cout << "YES , Bipartite Graph" << endl;
    else
        cout << "Not Bipartite Graph" << endl;
    return 0;
}
