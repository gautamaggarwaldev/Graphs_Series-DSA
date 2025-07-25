#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
    {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // Relax edges V-1 times
        for (int i = 0; i < V - 1; i++)
        {
            for (auto edge : edges)
            {
                int node = edge[0];
                int nebr = edge[1];
                int wt = edge[2];

                if (dist[node] == INT_MAX)
                    continue;

                int newDist = dist[node] + wt;
                if (newDist < dist[nebr])
                {
                    dist[nebr] = newDist;
                }
            }
        }

        // check for -ve weight Cycle
        for (auto edge : edges)
        {
            int node = edge[0];
            int nebr = edge[1];
            int wt = edge[2];

            if (dist[node] == INT_MAX)
                continue;

            int newDist = dist[node] + wt;
            if (newDist < dist[nebr])
            {
                return {-1};
            }
        }
        return dist;
    }
};

int main()
{
    Solution Sol;
    int V = 5;
    vector<vector<int>> edges = {{1, 3, 2}, {4, 3, -1}, {2, 4, 1}, {1, 2, 1}, {0, 1, 5}};
    int src = 0;
    vector<int> ans = Sol.bellmanFord(V, edges, src);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}