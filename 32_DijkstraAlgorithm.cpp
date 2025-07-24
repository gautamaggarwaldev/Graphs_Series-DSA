#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        int n = edges.size();
        unordered_map<int, vector<pair<int, int>>> graph;
        for (int i = 0; i < n; i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            int weight = edges[i][2];

            graph[a].push_back({b, weight});
            graph[b].push_back({a, weight});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        pq.push({0, src});
        while (!pq.empty())
        {
            auto f = pq.top();
            pq.pop();
            int distOfNodeFromSrc = f.first;
            int node = f.second;

            for (auto nebrInfo : graph[node])
            {
                int nebr = nebrInfo.first;
                int nebrDist = nebrInfo.second;

                int savedDistOfNebrFromSrc = dist[nebr];
                int newDistOfNebrFromSrc = distOfNodeFromSrc + nebrDist;

                if (newDistOfNebrFromSrc < savedDistOfNebrFromSrc)
                {
                    pq.push({newDistOfNebrFromSrc, nebr});
                    dist[nebr] = newDistOfNebrFromSrc;
                }
            }
        }
        return dist;
    }
};
int main()
{
    Solution Sol;
    int V = 5;
    int src = 0;
    vector<vector<int>> edges = {{0, 1, 4}, {0, 2, 8}, {1, 4, 6}, {2, 3, 2}, {3, 4, 10}};
    vector<int> ans = Sol.dijkstra(V, edges, src);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}