#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
void printGraph(unordered_map<int, vector<int>> &graph)
{
    for (auto x : graph)
    {
        cout << x.first << " ----> ";
        for (int i : x.second)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

void bfs(int src, unordered_map<int, vector<int>> &graph, int n)
{
    queue<int> q;
    vector<int> visited(n + 1, 0);
    q.push(src);
    visited[src] = 1;

    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        cout << f << " ";
        for (int nebr : graph[f])
        {
            if (visited[nebr] != 1)
            {
                q.push(nebr);
                visited[nebr] = 1;
            }
        }
    }
}
int main()
{

    vector<vector<int>> edgeList = {{1, 2}, {1, 3}, {1, 4}, {2, 5}, {3, 7}, {7, 8}, {8, 6}, {4, 6}, {4, 5}};
    unordered_map<int, vector<int>> graph;
    int n = edgeList.size();
    for (int i = 0; i < n; i++)
    {
        int a = edgeList[i][0];
        int b = edgeList[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    printGraph(graph);
    cout << "******BREADTH FIRST SEARCH TRAVERSAL******" << endl;
    bfs(1, graph, 8);
}