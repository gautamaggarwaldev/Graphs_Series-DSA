#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int INF = 1e8;
    int spanningTree(int V, vector<vector<int>> adj)
    {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto edge : adj)
        {
            int a = edge[0];
            int b = edge[1];
            int wt = edge[2];

            graph[a].push_back({b, wt});
            graph[b].push_back({a, wt});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> key(V, INF); // ---> distance
        vector<bool> mst(V, false);
        vector<int> parent(V, -1);

        key[0] = 0;
        pq.push({0, 0}); // distance, vertex

        while (!pq.empty())
        {
            auto f = pq.top();
            pq.pop();
            int currKey = f.first;
            int node = f.second;
            if (mst[node])
                continue;
            mst[node] = true;
            for (auto x : graph[node])
            {
                int nebr = x.first;
                int wt = x.second;
                if (mst[nebr] == false && wt < key[nebr])
                {
                    key[nebr] = wt;
                    pq.push({key[nebr], nebr});
                    parent[nebr] = node;
                }
            }
        }
        int minimumWeight = 0;
        for (int i = 0; i < V; i++)
        {
            minimumWeight += key[i];
        }
        return minimumWeight;
    }
};
int main()
{
    Solution Sol;
    int V = 3;
    vector<vector<int>> adj = {{0, 1, 5}, {1, 2, 3}, {0, 2, 1}};
    cout << Sol.spanningTree(V, adj) << endl;
}
