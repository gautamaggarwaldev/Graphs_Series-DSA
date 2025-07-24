#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution
{
public:
    void bfs(int node, unordered_map<int, vector<int>> &graph, vector<int> &visited)
    {
        queue<int> q;
        visited[node] = 1;
        q.push(node);
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
                }
            }
        }
    }
    int minimumConnections(int n, vector<vector<int>> &edges)
    {
        int m = edges.size();
        int count = 0;
        if (m < n - 1)
            return -1;
        unordered_map<int, vector<int>> graph;
        vector<int> visited(n, 0);

        for (int i = 0; i < m; i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for (int i = 0; i < n; i++)
        {
            if (visited[i] != 1)
            {
                bfs(i, graph, visited);
                count++;
            }
        }
        return count - 1;
    }
};
int main()
{
    Solution Sol;
    int n = 6;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
    cout << Sol.minimumConnections(n, edges) << endl;
}