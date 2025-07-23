#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    void dfs(int i, int j, vector<vector<string>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != "1")
        {
            return;
        }
        grid[i][j] = "2";
        for (int k = 0; k < 4; k++)
        {
            int ii = i + dx[k];
            int jj = j + dy[k];
            dfs(ii, jj, grid);
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
                    dfs(i, j, grid);
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
    vector<vector<string>> grid = {{"1", "1", "1", "1", "0"}, {"1", "1", "0", "1", "0"}, {"1", "1", "0", "0", "0"}, {"0", "0", "0", "0", "0"}};
    cout << Sol.numIslands(grid) << endl;
}