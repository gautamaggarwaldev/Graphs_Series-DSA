#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int dfs(int src, unordered_map<int, vector<int>> &forwardGraph, unordered_map<int, vector<int>> &backwardGraph, vector<int> &visited)
    {
        int res = 0;
        visited[src] = 1;
        for (int nebr : forwardGraph[src])
        {
            if (visited[nebr] != 1)
            {
                res++;
                res += dfs(nebr, forwardGraph, backwardGraph, visited);
            }
        }
        for (int nebr : backwardGraph[src])
        {
            if (visited[nebr] != 1)
            {
                res += dfs(nebr, forwardGraph, backwardGraph, visited);
            }
        }
        return res;
    }
    int minReorder(int n, vector<vector<int>> &edges)
    {
        int m = edges.size();
        unordered_map<int, vector<int>> forwardGraph;
        unordered_map<int, vector<int>> backwardGraph;

        for (int i = 0; i < m; i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];

            forwardGraph[a].push_back(b);
            backwardGraph[b].push_back(a);
        }
        vector<int> visited(n + 1, 0);
        int ans = dfs(0, forwardGraph, backwardGraph, visited);
        return ans;
    }
};
int main()
{
    Solution Sol;
    int n = 6;
    vector<vector<int>> edges = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
    cout << Sol.minReorder(n,edges) << endl;
}