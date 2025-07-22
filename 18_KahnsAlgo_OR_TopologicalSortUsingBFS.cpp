#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        int n = edges.size();
        unordered_map<int, vector<int>> graph;
        vector<int> inDegree(V, 0);
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];

            graph[a].push_back(b);
        }

        // fill the indegree of each vertex 
        for (int i = 0; i < V; i++)
        {
            for (int x : graph[i])
            {
                inDegree[x] += 1;
            }
        }

        // push the vertex which has zero indegree
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int f = q.front();
            q.pop();
            ans.push_back(f);
            for (int nebr : graph[f])
            {
                inDegree[nebr]--; // traverse the nebr of node (f) and minus the indegree of that nebr 
                if (inDegree[nebr] == 0) // if indegree is zero push that nebr into queue
                {
                    q.push(nebr);
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution Sol;
    vector<vector<int>> edges = {{1, 3}, {2, 3}, {4, 1}, {4, 0}, {5, 0}, {5, 2}};
    int V = 6;
    vector<int> res = Sol.topoSort(V,edges);
    for(int i=0;i<res.size();i++) {
        cout << res[i] << " ";
    }
}