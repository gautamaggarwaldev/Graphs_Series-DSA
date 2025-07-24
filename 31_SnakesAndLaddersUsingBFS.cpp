#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        int node = 1;
        vector<int> edges(n * n + 1, -1);
        bool flag = true;
        // store connections from board
        for (int i = n - 1; i >= 0; i--)
        {
            if (flag)
            {
                for (int j = 0; j < n; j++)
                {
                    if (board[i][j] != -1)
                    {
                        int dst = board[i][j];
                        edges[node] = dst;
                    }
                    node++;
                }
            }
            else
            { // falg==false
                for (int j = n - 1; j >= 0; j--)
                {
                    if (board[i][j] != -1)
                    {
                        int dst = board[i][j];
                        edges[node] = dst;
                    }
                    node++;
                }
            }
            flag = !flag;
        }

        // Build graph from connections
        unordered_map<int, vector<int>> graph;
        for (int i = 1; i <= (n * n) - 1; i++)
        {
            for (int cnt = 1; cnt <= 6; cnt++)
            {
                int nebr = i + cnt;
                if (nebr <= n * n)
                {
                    if (edges[nebr] != -1)
                    { // has ladder or snake
                        graph[i].push_back(edges[nebr]);
                    }
                    else
                    {
                        graph[i].push_back(nebr);
                    }
                }
            }
        }

        // find shortest path using bfs traversal
        vector<int> visited(n * n + 1, 0);
        queue<int> q;
        int level = 0;
        q.push(1);
        visited[1] = 1;
        while (!q.empty())
        {
            int s = q.size();
            while (s--)
            {
                int pos = q.front();
                q.pop();
                if (pos == n * n)
                {
                    return level;
                }
                for (int nebr : graph[pos])
                {
                    if (visited[nebr] != 1)
                    {
                        q.push(nebr);
                        visited[nebr] = 1;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
int main()
{
    Solution Sol;
    vector<vector<int>> board = {
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 35, -1, -1, 13, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 15, -1, -1, -1, -1},
    };

    cout << Sol.snakesAndLadders(board) << endl;
}