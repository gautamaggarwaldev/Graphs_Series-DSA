# include <iostream>
# include <vector>
using namespace std;
void printDirectedGraph(vector<vector<int>>& adjacencyMatrix) {
    for(int i=1;i<=4;i++) {
        cout << i << " -----> ";
        for(int j=1;j<=4;j++) {
            if(adjacencyMatrix[i][j]==1) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
}
int main() {
    vector<vector<int>> edgeList = {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {3, 2}, {4, 2}, {1, 3}};
    int n = edgeList.size();
    vector<vector<int>> adjacencyMatrix(n+1, vector<int>(n+1,0));

    for(int i=0;i<n;i++) {
        int a = edgeList[i][0];
        int b = edgeList[i][1];

        adjacencyMatrix[a][b] = 1;

    }

    printDirectedGraph(adjacencyMatrix);
}