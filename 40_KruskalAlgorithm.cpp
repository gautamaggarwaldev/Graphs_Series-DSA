#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class DSU
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int a)
    {
        if (parent[a] == a)
            return a;
        return parent[a] = find(parent[a]);
    }

    void union_set(int x, int y)
    {
        int leaderX = find(x);
        int leaderY = find(y);
        if (leaderX != leaderY)
        {
            if (rank[leaderX] < rank[leaderY])
            {
                parent[leaderX] = leaderY;
                rank[leaderY] += rank[leaderX];
            }
            else
            {
                parent[leaderY] = leaderX;
                rank[leaderX] += rank[leaderY];
            }
        }
    }
};

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

int kruskalMST(int n, vector<vector<int>> &edges)
{
    DSU dsu(n);
    int m = edges.size();
    sort(edges.begin(), edges.end(), cmp); //sort edges based on weight
    int minimumWeight = 0;

    for (int i = 0; i < m; i++)
    {
        int u = dsu.find(edges[i][0]);
        int v = dsu.find(edges[i][1]);
        int wt = edges[i][2];

        if (u != v)
        {
            minimumWeight += wt;
            dsu.union_set(u, v);
        }
    }
    return minimumWeight;
}

int main()
{
    int n = 3; 
    vector<vector<int>> edges = {{0, 1, 5}, {1, 2, 3}, {0, 2, 1}}; 
    
    int result = kruskalMST(n, edges);
    cout << "Minimum Spanning Tree Weight: " << result << endl;
}