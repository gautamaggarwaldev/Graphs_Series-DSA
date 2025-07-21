#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool dfs(int node, vector<vector<int>> &graph, vector<int> &visited, vector<int> &currPath)
    {
        visited[node] = 1;
        currPath[node] = 1;
        for (int nebr : graph[node])
        {
            if (visited[nebr] != 1)
            {
                bool res = dfs(nebr, graph, visited, currPath);
                if (res)
                    return true;
            }
            else
            {
                if (currPath[nebr] == 1)
                {
                    return true;
                }
            }
        }
        currPath[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> visited(n, 0);
        vector<int> currPath(n, 0);
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] != 1)
            {
                dfs(i, graph, visited, currPath);
            }
        }

        // check cycle detection in directed graph and then print those nodes which are not present in currPath

        for (int i = 0; i < n; i++)
        {
            if (currPath[i] != 1)
            {
                ans.push_back(i);
            }
        }
        for (int i = 0; i < ans.size(); i++)
        {

            cout << ans[i] << " ";
        }
        return ans;
    }
};
int main()
{
    Solution Sol;
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    Sol.eventualSafeNodes(graph);
}