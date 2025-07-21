#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool bfs(int src, unordered_map<int, vector<int>> &graph, int dst, vector<int> &visited)
    {
        queue<int> q;
        q.push(src);
        visited[src] = 1;
        while (!q.empty())
        {
            int f = q.front();
            cout << f << " ";
            q.pop();
            for (int nebr : graph[f])
            {
                if (visited[nebr] != 1)
                {
                    q.push(nebr);
                    visited[nebr] = 1;
                }
            }
        }
        return visited[dst] == 1 ? true : false;
    }
    bool validPath(int n, vector<vector<int>> &edges, int src, int dst)
    {
        int m = edges.size();
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < m; i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<int> visited(n + 1, 0);
        int ans = bfs(src, graph, dst, visited);
        cout << endl;
        return ans;
    }
};
int main()
{   
    Solution Sol;
    vector<vector<int>> edges = {{4, 3}, {1, 4}, {4, 8}, {1, 7}, {6, 4}, {4, 2}, {7, 4}, {4, 0}, {0, 9}, {5, 4}};
    int src = 5;
    int dst = 9;
    int n = 10;
    cout  << Sol.validPath(n,edges,src,dst);
}