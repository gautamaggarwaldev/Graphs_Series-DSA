#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    // Returns the largest value along any path (max color count) or -1 if a cycle exists
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        int n = colors.size(); // Number of nodes
        int ans = 0;           // Stores the largest color value found
        int processedNode = 0; // Counts processed nodes to detect cycles
        unordered_map<int, vector<int>> graph;      
        vector<vector<int>> count(n, vector<int>(26, 0)); // Color counts for each node (for 26 lowercase letters)
        vector<int> inDegree(n, 0);                     
        queue<int> q;                                      

        for (auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
        }

        for (int i = 0; i < n; i++)
        {
            for (auto x : graph[i])
            {
                inDegree[x]++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        // Process nodes in topological order
        while (!q.empty())
        {
            int f = q.front();
            q.pop();
            processedNode++; // Track how many nodes have been processed
            count[f][colors[f] - 'a']++; // Increment color count for this node

            // Update global answer if current color count is a new maximum
            ans = max(ans, count[f][colors[f] - 'a']);

            // Update color counts for all neighbor nodes
            for (int nebr : graph[f])
            {
                inDegree[nebr]--;
                if (inDegree[nebr] == 0)
                {
                    q.push(nebr);
                }

                // For each possible color, propagate the max count along the path
                for (int i = 0; i < 26; i++)
                {
                    count[nebr][i] = max(count[nebr][i], count[f][i]);
                }
            }
        }
        // If all nodes were processed graph has no cycles, otherwise return -1
        return processedNode == n ? ans : -1;
    }
};
int main()
{
    Solution Sol;
    string colors = "abaca";
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 3}, {3, 4}};
    cout << Sol.largestPathValue(colors, edges) << endl;
}