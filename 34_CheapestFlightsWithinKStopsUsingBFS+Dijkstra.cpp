#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        unordered_map<int, vector<pair<int, int>>> graph;
        int m = flights.size();
        for (int i = 0; i < m; i++)
        {
            int a = flights[i][0];
            int b = flights[i][1];
            int wt = flights[i][2];

            graph[a].push_back({b, wt});
        }
        queue<vector<int>> q;
        vector<int> dist(n, INT_MAX);
        q.push({0, src, 0}); // k, node, distance
        dist[src] = 0;

        while (!q.empty())
        {
            auto f = q.front();
            q.pop();
            int currK = f[0];
            int node = f[1];
            int parentDist = f[2];
            if (currK > k)
                break;
            for (auto x : graph[node])
            {
                int nebr = x.first;
                int nebrDist = x.second;
                int newDist = nebrDist + parentDist;
                if (newDist < dist[nebr])
                {
                    dist[nebr] = newDist;
                    q.push({currK + 1, nebr, newDist});
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
int main()
{
    Solution Sol;
    int n = 4;
    int src = 0;
    int dst = 3;
    int k = 1;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    cout << Sol.findCheapestPrice(n, flights, src, dst, k) << endl;
}