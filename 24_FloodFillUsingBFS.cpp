#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    void bfs(int i, int j, vector<vector<int>> &image, int orgColor, int color)
    {
        int r = image.size();
        int c = image[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        image[i][j] = color;
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
                if (ii < 0 || jj < 0 || ii >= r || jj >= c || image[ii][jj] != orgColor)
                {
                    continue;
                }
                q.push({ii, jj});
                image[ii][jj] = color;
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int orgColor = image[sr][sc];
        if (orgColor == color)
            return image;
        bfs(sr, sc, image, orgColor, color);
        return image;
    }
};
int main()
{
    Solution Sol;
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    for (int i = 0; i < image.size(); i++)
    {
        for (int j = 0; j < image[0].size(); j++)
        {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
    int sr = 1, sc = 1, color = 2;
    vector<vector<int>> ans = Sol.floodFill(image, sr, sc, color);
    cout << "*********************" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}