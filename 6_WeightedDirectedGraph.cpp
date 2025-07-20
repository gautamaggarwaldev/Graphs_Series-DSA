#include <iostream>
#include <vector>
using namespace std;
void printWeightedDirectedGraph(vector<vector<int>> &adjacencyMatrix)
{
    for (int i = 1; i <= 4; i++)
    {
        cout << i << " ---> ";
        for (int j = 1; j <= 4; j++)
        {
            if (adjacencyMatrix[i][j] != 0)
            {
                cout << "(" << j << ", weight: " << adjacencyMatrix[i][j] << ") ";
            }
        }
        cout << endl;
    }
}
int main()
{

    vector<vector<int>> edgeList = {{1, 2, 10}, {2, 3, 20}, {3, 4, 30}, {4, 1, 40}, {3, 2, 50}, {4, 2, 60}, {1, 3, 70}};
    int n = edgeList.size();
    vector<vector<int>> adjacencyMatrix(5, vector<int>(5, 0));
    for (int i = 0; i < n; i++)
    {
        int a = edgeList[i][0];
        int b = edgeList[i][1];
        int weight = edgeList[i][2];

        adjacencyMatrix[a][b] = weight;
    }

    printWeightedDirectedGraph(adjacencyMatrix);
}