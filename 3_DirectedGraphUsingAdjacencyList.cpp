#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
void printDirectedGraph(unordered_map<int, vector<int>> &graph)
{
    for (auto x : graph)
    {
        cout << x.first << " ----> ";
        for (int i : x.second)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
int main()
{

    vector<vector<int>> edgeList = {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {3, 2}, {4, 2}, {1, 3}};
    unordered_map<int, vector<int>> graph;

    int n = edgeList.size();

    for (int i = 0; i < n; i++)
    {
        int a = edgeList[i][0];
        int b = edgeList[i][1];

        graph[a].push_back(b);
    }

    printDirectedGraph(graph);
}