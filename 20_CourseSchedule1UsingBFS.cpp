#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution
{
public:
    bool canFinish(int v, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> graph;
        vector<int> inDegree(v, 0);
        queue<int> q;
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
            for (int nebr : graph[f])
            {
                inDegree[nebr]--;
                if (inDegree[nebr] == 0)
                {
                    q.push(nebr);
                }
            }
        }

        if (ans.size() == v)
            return true;
        else
            return false;
    }
};
int main()
{
    Solution Sol;
    vector<vector<int>> edges = {{1, 3}, {2, 3}, {4, 1}, {4, 0}, {5, 0}, {5, 2}};
    int V = 6;
    cout << Sol.canFinish(V, edges) << endl;
}