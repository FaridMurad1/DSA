#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    map<char, vector<char>> adj_list;

public:
    Graph() {}

    void add_edge(char u, char v)
    {
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    void print_adj_list()
    {
        for (auto entry : adj_list)
        {
            cout << entry.first << " -> ";
            for (char neighbor : entry.second)
            {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    void bfs(char src)
    {
        queue<char> q;
        map<char, bool> visited;
        char node;

        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            node = q.front();
            cout << node << " ";
            q.pop();

            for (char neighbor : adj_list[node])
            {
                if (!visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }
};

int main()
{
    Graph graph;

    graph.add_edge('a', 'b');
    graph.add_edge('a', 'c');
    graph.add_edge('a', 'd');
    graph.add_edge('a', 'e');
    graph.add_edge('a', 'f');
    graph.add_edge('b', 'c');
    graph.add_edge('b', 'd');
    graph.add_edge('b', 'f');
    graph.add_edge('c', 'f');
    graph.add_edge('c', 'g');
    graph.add_edge('d', 'g');
    graph.add_edge('d', 'h');
    graph.add_edge('e', 'h');
    graph.add_edge('f', 'g');
    graph.add_edge('g', 'h');

    graph.bfs('a');

    return 0;
}
