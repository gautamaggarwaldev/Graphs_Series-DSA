#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void dfs(int currLen, int node, vector<int> &edges, vector<int> &visited, vector<int> &currPath, int &longestCycleLen)
    {
        currLen++;
        visited[node] = 1;
        currPath[node] = currLen;

        int nebr = edges[node];
        if (nebr != -1)
        {
            if (visited[nebr] != 1)
            {
                dfs(currLen, nebr, edges, visited, currPath, longestCycleLen);
            }
            else
            {
                if (currPath[nebr] != 0)
                {
                    int len = currPath[node] - currPath[nebr] + 1;
                    longestCycleLen = max(longestCycleLen, len);
                }
            }
        }
        currPath[node] = 0;
    }
    int longestCycle(vector<int> &edges)
    {
        int n = edges.size();
        vector<int> visited(n, 0);
        vector<int> currPath(n, 0);
        int longestCycleLen = -1;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] != 1)
            {
                dfs(0, i, edges, visited, currPath, longestCycleLen);
            }
        }
        return longestCycleLen;
    }
};
int main()
{
    Solution Sol;
    vector<int> edges = {-3,3,4,2,3};
    cout << Sol.longestCycle(edges) << endl;
}