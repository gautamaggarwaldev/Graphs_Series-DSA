#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    int helper(int srcX, int srcY, int targX, int targY, int n, vector<vector<int>> &cordinates)
    {
        vector<vector<int>> visited(n, vector<int>(n, 0));
        queue<pair<int, int>> q; // queue store both x and y cordinates 
        q.push({srcX, srcY});
        visited[srcX][srcY] = 1;
        int steps = 0;
        while (!q.empty())
        {
            int Qsize = q.size(); 
            while (Qsize)
            {
                pair<int, int> p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                if (x == targX && y == targY)
                    return steps;
                for (int i = 0; i < cordinates.size(); i++)
                {
                    int newX = x + cordinates[i][0];
                    int newY = y + cordinates[i][1];
                    if (newX >= 0 && newY >= 0 && newX < n && newY < n && visited[newX][newY] != 1)
                    {
                        visited[newX][newY] = 1;
                        q.push({newX, newY});
                    }
                }
                Qsize--;
            }
            steps++;
        }
        return steps;
    }

    int minStepToReachTarget(vector<int> &knightPos, vector<int> &targetPos, int n)
    {
        // change the given cordinates into matrix positioning
        int srcX = n - knightPos[1]; 
        int srcY = knightPos[0] - 1;
        int targX = n - targetPos[1];
        int targY = targetPos[0] - 1;

        // these are the possible steps that a knight can move 
        vector<vector<int>> cordinates = {{-1, -2}, {-1, 2}, {1, -2}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {2, 1}};

        int ans = helper(srcX, srcY, targX, targY, n, cordinates);
        return ans;
    }
};
int main()
{
    Solution Sol;
    int n = 6;
    vector<int>KnightPos = {4,5};
    vector<int>targetPos = {1,1};
    cout << Sol.minStepToReachTarget(KnightPos,targetPos,n) << endl;
}