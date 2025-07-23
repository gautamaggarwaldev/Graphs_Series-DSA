#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int r, c;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    void dfs(int i, int j, vector<vector<int>> &image, int orgColor, int color)
    {
        if (i < 0 || j < 0 || i >= r || j >= c || image[i][j] != orgColor)
        {
            return;
        }
        image[i][j] = color;
        for (int k = 0; k < 4; k++)
        {
            int ii = i + dx[k];
            int jj = j + dy[k];
            dfs(ii, jj, image, orgColor, color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        r = image.size();
        c = image[0].size();

        int orgColor = image[sr][sc];
        if (orgColor == color)
            return image;
        dfs(sr, sc, image, orgColor, color);
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