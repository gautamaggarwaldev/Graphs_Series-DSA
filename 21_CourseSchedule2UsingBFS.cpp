#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> findOrder(int v, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> graph;
        vector<int> inDegree(v, 0);
        vector<int> ans;

        for (auto edge : edges)
        {
            int a = edge[0];
            int b = edge[1];

            graph[b].push_back(a);
        }

        for (int i = 0; i < v; i++)
        {
            for (int x : graph[i])
            {
                inDegree[x]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < v; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int f = q.front();
            ans.push_back(f);
            q.pop();
            for (int x : graph[f])
            {
                inDegree[x]--;
                if (inDegree[x] == 0)
                {
                    q.push(x);
                }
            }
        }
        if (ans.size() == v)
            return ans;
        else
            return {};
    }
};
int main()
{
    Solution Sol;
    vector<vector<int>> edges = {{1, 3}, {2, 3}, {4, 1}, {4, 0}, {5, 0}, {5, 2}};
    int V = 6;
    vector<int> res = Sol.findOrder(V, edges);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}