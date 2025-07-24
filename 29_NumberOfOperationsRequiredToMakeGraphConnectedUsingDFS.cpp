#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    void dfs(int node, unordered_map<int, vector<int>> &graph, vector<int> &visited)
    {
        visited[node] = 1;
        for (int x : graph[node])
        {
            if (visited[x] != 1)
            {
                dfs(x, graph, visited);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>> &edges)
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
                dfs(i, graph, visited);
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
    cout << Sol.makeConnected(n,edges) << endl;
}