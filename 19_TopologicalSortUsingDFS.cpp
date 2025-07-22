#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
using namespace std;
class Solution
{
public:
    void dfs(int node, vector<int> &visited, unordered_map<int, vector<int>> &graph, deque<int> &dq)
    {
        visited[node] = 1;
        for (int i : graph[node])
        {
            if (visited[i] != 1)
            {
                dfs(i, visited, graph, dq);
            }
        }
        dq.push_front(node);
    }
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        int n = edges.size();
        unordered_map<int, vector<int>> graph;
        vector<int> ans;
        vector<int> visited(V, 0);
        deque<int> dq;

        for (int i = 0; i < n; i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];

            graph[a].push_back(b);
        }

        for (int i = 0; i < V; i++)
        {
            if (visited[i] != 1)
            {
                dfs(i, visited, graph, dq);
            }
        }

        for (int x : dq)
        {
            ans.push_back(x);
        }
        return ans;
    }
};
int main()
{
    Solution Sol;
    vector<vector<int>> edges = {{1, 3}, {2, 3}, {4, 1}, {4, 0}, {5, 0}, {5, 2}};
    int V = 6;
    vector<int> res = Sol.topoSort(V, edges);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}