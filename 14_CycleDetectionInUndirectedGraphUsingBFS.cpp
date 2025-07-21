#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool bfs(int node, unordered_map<int, vector<int>> &graph, vector<int> &visited, vector<int> &parent)
    {
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        while (!q.empty())
        {
            int f = q.front();
            q.pop();
            for (int nebr : graph[f])
            {
                if (visited[nebr] != 1)
                {
                    q.push(nebr);
                    visited[nebr] = 1;
                    parent[nebr] = f;
                }
                else
                {
                    if (parent[f] != nebr) //cycle detect
                        return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>> &edges)
    {
        int n = edges.size();
        unordered_map<int, vector<int>> graph;
        vector<int> visited(V, 0);
        vector<int> parent(V, -1);
        for (int i = 0; i < n; i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for (int i = 0; i < V; i++)
        {
            if (visited[i] != 1)
            {
                bool ans = bfs(i, graph, visited, parent);
                if (ans)
                    return true;
            }
        }
        return false;
    }
};
int main()
{
    Solution Sol;
    vector<vector<int>> edges = { {0,1}, {1,2}, {2,3}, {3,4}, {4,1} };
    int V = 5;
    cout << Sol.isCycle(V,edges) << endl;
}