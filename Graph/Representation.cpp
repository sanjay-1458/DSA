#include <bits/stdc++.h>
using namespace std;

void AdjacencyMatrix()
{
    int nodes, edges;
    cin >> nodes >> edges;
    int adjacencyMatrix[nodes + 1][nodes + 1] = {0};
    for (int i = 0; i < edges; ++i)
    {
        int u, v;
        cin >> u >> v;
        adjacencyMatrix[u][v] = 1;
        adjacencyMatrix[v][u] = 1;
    }
    for (int i = 1; i <= nodes; ++i)
    {
        for (int j = 1; j <= nodes; ++j)
        {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void AdjacencyList()
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
    for (auto e : adjacencyList)
    {
        cout << e.first << " : ";
        for (auto i : e.second)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

void AdjacencyList2()
{
    int nodes, edges;
    cin >> nodes >> edges;
    vector<int> adjacencyList[nodes + 1];
    for (int i = 0; i < edges; ++i)
    {
        int u, v;
        cin >> u >> v;
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }
    for (int i = 1; i <= nodes; ++i)
    {
        cout << i << " : ";
        for (auto e : adjacencyList[i])
        {
            cout << e << " ";
        }
        cout << endl;
    }
}

int main()
{
    AdjacencyList2();
}
