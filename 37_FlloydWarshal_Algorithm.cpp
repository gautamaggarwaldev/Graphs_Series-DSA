#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e8;
class Solution
{
public:
    vector<vector<int>> floydWarshall(vector<vector<int>> &dist)
    {
        int v = dist.size();
        for (int k = 0; k < v; k++) // intermediate node
        { 
            for (int i = 0; i < v; i++) // src node
            {
                for (int j = 0; j < v; j++) //dest node
                {
                    if (dist[i][k] == INF || dist[k][j] == INF)
                    {
                        continue;
                    }
                    int newDist = dist[i][k] + dist[k][j];
                    if (newDist < dist[i][j])
                    {
                        dist[i][j] = newDist;
                    }
                }
            }
        }
        return dist;
    }
};
int main()
{
    Solution Sol;
    vector<vector<int>> dist = {{0, 4, INF, 5, INF},
                                {INF, 0, 1, INF, 6},
                                {2, INF, 0, 3, INF},
                                {INF, INF, 1, 0, 2},
                                {1, INF, INF, 4, 0}};
    vector<vector<int>> ans = Sol.floydWarshall(dist);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}