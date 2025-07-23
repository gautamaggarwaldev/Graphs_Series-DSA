#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<vector<int>> chefAndWells(int n, int m, vector<vector<char>> &grid)
    {
        vector<vector<int>> ans(n, vector<int>(m, 0));
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 'W')
                {
                    q.push({i, j}); // Multi Source BFS
                }
            }
        }

        int cnt = 1;

        while (!q.empty())
        {

            int size = q.size();
            while (size--)
            {
                pair<int, int> p = q.front();
                q.pop();
                int i = p.first;
                int j = p.second;
                for (int k = 0; k < 4; k++)
                {
                    int ii = i + dx[k];
                    int jj = j + dy[k];
                    if (ii >= 0 && jj >= 0 && ii < n && jj < m && (grid[ii][jj] == 'H' || grid[ii][jj] == '.'))
                    {
                        if (grid[ii][jj] == 'H')
                        {
                            ans[ii][jj] = 2 * cnt;
                        }
                        q.push({ii, jj});
                        grid[ii][jj] = 'X';
                    }
                }
            }
            cnt++;
        }

        // check if any house remaining mark -1
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 'H')
                {
                    ans[i][j] = -1;
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution Sol;
    int n = 5;
    int m = 5;
    vector<vector<char>> grid = {
        {'H', 'N', 'H', 'H', 'H'},
        {'N', 'N', 'H', 'H', 'W'},
        {'W', 'H', 'H', 'H', 'H'},
        {'H', 'H', 'H', 'H', 'H'},
        {'H', 'H', 'H', 'H', 'H'},
    };

    vector<vector<int>> res = Sol.chefAndWells(n, m, grid);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}