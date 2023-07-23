#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjacencyList;
    void addEdge(int u, int v, bool direction)
    {
        adjacencyList[u].push_back(v);
        if (!direction)
        {
            adjacencyList[v].push_back(u);
        }
    }
    void printGraph()
    {
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
};

void Matrix()
{
    int adjacencyMatrix[13][13] = {0};
    int nodes = 0, edges = 0;
    cin >> nodes >> edges;
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
void List()
{
    int nodes, edges;
    cin >> nodes >> edges;
    class Graph G;
    for (int i = 0; i < edges; ++i)
    {
        int u, v;
        cin >> u >> v;
        G.addEdge(u, v, 0);
    }
    G.printGraph();
}

int main()
{
    Matrix();
    List();
}
