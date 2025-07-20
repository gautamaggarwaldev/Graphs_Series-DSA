#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
void printUndirectedWeightedGraph(unordered_map<int, vector<pair<int, int>>> &graph)
{
    for (auto x : graph)
    {
        cout << x.first << " ----> ";
        for (auto nebr : x.second)
        {
            cout << "(" << nebr.first << ", weight: " << nebr.second << ") ";
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<int>> edgeList = {{1, 2, 10}, {2, 3, 20}, {3, 4, 30}, {4, 1, 40}, {3, 2, 50}, {4, 2, 60}, {1, 3, 70}};
    unordered_map<int, vector<pair<int, int>>> graph;
    int n = edgeList.size();
    for (int i = 0; i < n; i++)
    {
        int a = edgeList[i][0];
        int b = edgeList[i][1];
        int weight = edgeList[i][2];

        graph[a].push_back({b, weight});
        graph[b].push_back({a, weight});
    }
    printUndirectedWeightedGraph(graph);
}