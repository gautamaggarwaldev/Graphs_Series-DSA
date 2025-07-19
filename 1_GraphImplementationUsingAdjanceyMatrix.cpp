#include <iostream>
#include <vector>
using namespace std;
void printGraph(vector<vector<int>> &adjanceyMatrix)
{
    for (int i = 1; i <= 4; i++)
    {
        cout << i << " ----> ";
        for (int j = 1; j <= 4; j++)
        {
            if (adjanceyMatrix[i][j] == 1)
            {
                cout << j << " ";
            }
        }
        cout << endl;
    }
}
int main()
{

    vector<vector<int>> edgeList = {{1, 2}, {2, 3}, {3, 4}, {4, 2}, {1, 3}};
    vector<vector<int>> adjanceyMatrix(5, vector<int>(5, 0)); //5 X 5 

    int n = edgeList.size();

    for (int i = 0; i < n; i++)
    {
        int a = edgeList[i][0];
        int b = edgeList[i][1];

        adjanceyMatrix[a][b] = 1;
        adjanceyMatrix[b][a] = 1;
    }

    printGraph(adjanceyMatrix);
}