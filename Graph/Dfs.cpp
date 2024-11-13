/*
Input:
5 4
1 2
1 3
2 4
3 5
1
Output:
1 3 5 2 4 
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10001]; // Adjacency list for 10,000 nodes
int vis[10001] = {0};   // Visit array for 10,000 nodes

// Iterative DFS
void Dfs(int node)
{
    stack<int> s;
    s.push(node);  // push the source node
    vis[node] = 1; // mark the source node as visited

    while (!s.empty())
    {
        int top = s.top(); // top element of stack
        cout << top << " ";
        s.pop(); // pop the top element

        for (auto it : adj[top]) // for all adjacent nodes of top
        {
            if (!vis[it])
            {
                vis[it] = 1; // mark the adjacent node as visited
                s.push(it);  // push the adjacent node if not visited
            }
        }
    }
}

// Recursive DFS

// void Dfs(int node)
// {
//     vis[node] = 1;    // if visited then true kora dibo
//     cout << node << "->";
//     for (auto it : adj[node])    // jaita visited hossa tar sokol child check korbo ja visited kina
//     {
//         if (!vis[it])    // if not visited then DFS call korbo
//         {
//             Dfs(it);
//         }
//     }
// }
int main()
{
    int n, e;
    cin >> n >> e;

    // Read edges
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int source;
    cin >> source;
    Dfs(source);

    return 0;
}
