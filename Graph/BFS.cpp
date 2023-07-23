#include <bits/stdc++.h>
using namespace std;

void BFS(int node, unordered_map<int, list<int>> &adjacencyList, unordered_map<int, bool> &visited)
{
    vector<int> bfs;
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        bfs.push_back(frontNode);
        visited[frontNode] = true;
        for (auto e : adjacencyList[frontNode])
        {
            if (visited[e] != true)
            {
                q.push(e);
            }
        }
    }
    for (auto e : bfs)
    {
        cout << e << " ";
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    unordered_map<int, list<int>> adjacencyList;
    for (int i = 0; i < edges; ++i)
    {
        int u, v;
        cin >> u >> v;
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }
    // for (auto e : adjacencyList)
    // {
    //     cout << e.first << " : ";
    //     for (auto i : e.second)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }
    unordered_map<int, bool> visited;
    for (int i = 0; i < nodes; ++i)
    {
        visited[i] = false;
    }
    for (int i = 0; i < nodes; ++i)
    {
        if (!visited[i])
        {
            BFS(i, adjacencyList, visited);
        }
    }
}
