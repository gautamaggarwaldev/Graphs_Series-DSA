#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool dfs(int node, unordered_map<int, vector<int>> &graph, vector<int> &visited, int parent)
    {
        visited[node] = 1;
        for (int nebr : graph[node])
        {
            if (visited[nebr] != 1)
            {
                int ans = dfs(nebr, graph, visited, node);
                if (ans)
                    return true;
            }
            else if (visited[nebr] == 1 && nebr != parent)
            {
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> graph;
        int n = edges.size();
        for (int i = 0; i < n; i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                bool ans = dfs(i, graph, visited, -1); // IMP
                if (ans)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
int main()
{
    Solution sol;
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 1}}; 
    cout << sol.isCycle(V, edges) << endl;                                
}
