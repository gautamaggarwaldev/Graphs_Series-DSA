#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int minCost(int maxTime, vector<vector<int>> &edges, vector<int> &pf)
    {
        int n = pf.size();
        unordered_map<int, vector<pair<int, int>>> graph;
        for (int i = 0; i < edges.size(); i++)
        {
            if (edges[i].size() < 3)
                continue;
            int a = edges[i][0];
            int b = edges[i][1];
            int time = edges[i][2];

            graph[a].push_back({b, time});
            graph[b].push_back({a, time});
        }
        vector<int> minTime(n, INT_MAX);
        priority_queue<vector<int>, vector<vector<int>>, greater<>> q;
        q.push({pf[0], 0, 0}); // passingfees, node, timeused

        while (!q.empty())
        {
            auto f = q.top();
            q.pop();
            int cost = f[0];
            int node = f[1];
            int time = f[2];
            if (time > maxTime || minTime[node] <= time)
                continue; // This line avoids revisiting nodes through worse or unnecessary paths
            minTime[node] = time;
            if (node == n - 1)
                return cost;

            for (auto x : graph[node])
            {
                int nebr = x.first;
                int nebrTime = x.second;
                int newTime = nebrTime + time;
                if (newTime < minTime[nebr])
                {
                    q.push({cost + pf[nebr], nebr, newTime});
                }
            }
        }
        return -1;
    }
};
int main()
{
    Solution Sol;
    int maxTime = 30;
    vector<vector<int>> edges = {{0, 1, 10}, {1, 2, 10}, {2, 5, 10}, {0, 3, 1}, {3, 4, 10}, {4, 5, 15}};
    vector<int> pf = {5, 1, 2, 20, 20, 3};
    cout << Sol.minCost(maxTime, edges, pf) << endl;
}