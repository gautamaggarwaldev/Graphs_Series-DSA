#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    void bfs(int i, int j, vector<vector<string>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = "2";
        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;
            for (int k = 0; k < 4; k++)
            {
                int ii = i + dx[k];
                int jj = j + dy[k];
                if (ii >= 0 && jj >= 0 && ii < n && jj < m && grid[ii][jj] == "1")
                {
                    q.push({ii, jj});
                    grid[ii][jj] = "2";
                }
            }
        }
    }
    int numIslands(vector<vector<string>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == "1")
                {
                    bfs(i, j, grid);
                    count++;
                }
            }
        }
        return count;
    }
};
int main()
{
    Solution Sol;
    vector<vector<string>> grid = {
        {"1", "1", "1", "1", "0"},
        {"1", "1", "0", "1", "0"},
        {"1", "1", "0", "0", "0"},
        {"0", "0", "0", "0", "0"}};
    cout << Sol.numIslands(grid) << endl;
}