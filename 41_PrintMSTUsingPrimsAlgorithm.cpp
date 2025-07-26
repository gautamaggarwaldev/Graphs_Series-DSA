#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int INF = 1e8;
    vector<vector<int>> primsMST(int V, vector<vector<int>> adj)
    {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (int i = 0; i < adj.size(); i++)
        {
            int a = adj[i][0];
            int b = adj[i][1];
            int wt = adj[i][2];

            graph[a].push_back({b, wt});
            graph[b].push_back({a, wt});
        }
        vector<bool> MST(V, false); // check that the node is part of MST or not
        vector<int> key(V, INF);    // wt of the edge
        vector<int> parent(V, -1);  // to store parent of each nose in MST;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        key[0] = 0;
        parent[0] = -1;
        pq.push({0, 0}); // in this we are storing distance and vertex

        while (!pq.empty())
        {
            auto f = pq.top();
            pq.pop();
            int currWt = f.first;
            int node = f.second;
            if (MST[node] == true)
            {
                continue;
            }
            MST[node] = true;
            for (auto x : graph[node])
            {
                int nebr = x.first;
                int wt = x.second;
                if (MST[nebr] == false && wt < key[nebr])
                {
                    key[nebr] = wt;
                    pq.push({key[nebr], nebr});
                    parent[nebr] = node;
                }
            }
        }
        // Build MST from parent array
        vector<vector<int>> mstEdges;
        for (int i = 0; i < V; i++)
        {
            if (parent[i] != -1)
            {
                mstEdges.push_back({parent[i], i, key[i]}); // u, v, weight
            }
        }
        return mstEdges;
    }
};
int main()
{
    Solution Sol;
    int V = 5;
    vector<vector<int>> adj = {{0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {2, 4, 7}, {3, 4, 9}};
    vector<vector<int>> mst = Sol.primsMST(V, adj);
    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (const auto &edge : mst)
    {
        cout << edge[0] << " - " << edge[1] << " with weight " << edge[2] << endl;
    }
    return 0;
}