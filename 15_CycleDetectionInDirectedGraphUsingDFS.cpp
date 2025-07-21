#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool dfs(int node, unordered_map<int, vector<int>> &graph, vector<int> &visited, vector<int> &currPath)
    {
        visited[node] = 1;
        currPath[node] = 1;
        for (int nebr : graph[node])
        {
            if (visited[nebr] != 1)
            {
                int res = dfs(nebr, graph, visited, currPath);
                if (res)
                    return true;
            }
            else
            {
                if (currPath[nebr] == 1)
                { // nebr is already in current path
                    return true;
                }
            }
        }
        currPath[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> graph;
        int n = edges.size();
        vector<int> visited(V, 0);
        vector<int> currPath(V, 0);

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
                bool ans = dfs(i, graph, visited, currPath);
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
    vector<vector<int>> edges = { {0,1}, {0,2}, {1,2}, {2,0}, {2,3} };
    int V = 5;
    cout << Sol.isCyclic(V,edges) << endl;
}