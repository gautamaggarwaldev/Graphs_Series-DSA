#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        pq.push({0, 0, 0}); //{dst, row, col}
        dist[0][0] = 0;
        while (!pq.empty())
        {
            auto f = pq.top();
            pq.pop();
            int dst = f[0];
            int i = f[1];
            int j = f[2];
            for (int k = 0; k < 4; k++)
            {
                int ii = i + dx[k];
                int jj = j + dy[k];

                if (ii < 0 || jj < 0 || ii >= n || jj >= m)
                {
                    continue;
                }
                int newDist = max(dst, abs(grid[ii][jj] - grid[i][j]));
                if (newDist < dist[ii][jj])
                {
                    dist[ii][jj] = newDist;
                    pq.push({dist[ii][jj], ii, jj});
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};
int main()
{
    Solution Sol;
    vector<vector<int>> grid = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    cout << Sol.minimumEffortPath(grid) << endl;
}