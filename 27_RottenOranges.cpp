#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, -1, 0, 1};
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }
        while (!q.empty())
        {
            int s = q.size();
            int temp = 0;
            while (s--)
            {
                pair<int, int> p = q.front();
                q.pop();
                int i = p.first;
                int j = p.second;
                for (int k = 0; k < 4; k++)
                {
                    int ii = i + dx[k];
                    int jj = j + dy[k];
                    if (ii >= 0 && jj >= 0 && ii < n && jj < m && grid[ii][jj] == 1)
                    {
                        grid[ii][jj] = 2;
                        q.push({ii, jj});
                        temp = 1;
                    }
                }
            }
            ans += temp;
        }
        for (auto v : grid)
        {
            for (int x : v)
            {
                if (x == 1)
                    return -1;
            }
        }
        return ans;
    }
};
int main()
{
    Solution Sol;
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout << Sol.orangesRotting(grid) << endl;
}