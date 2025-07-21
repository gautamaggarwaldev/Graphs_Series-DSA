# include <iostream>
# include <vector>
# include <unordered_map>
using namespace std;
void dfs(int src, unordered_map<int,vector<int>>& graph, int n, vector<int>& visited) {
    cout << src << " ";
    visited[src] = 1;
    for(int nebr : graph[src]) {
        if(!visited[nebr]) {
            dfs(nebr,graph,n,visited);
        }
    }
}
int main() {

    vector<vector<int>> edgeList = {{1, 2}, {1, 3}, {1, 4}, {2, 5}, {3, 7}, {7, 8}, {8, 6}, {4, 6}, {4, 5}};
    unordered_map<int, vector<int>>graph;
    int n = edgeList.size();
    for(int i=0;i<n;i++) {
        int a = edgeList[i][0];
        int b = edgeList[i][1];

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int>visited(9);
    cout << "********DEPTH FIRST SEARCH***********" << endl;
    dfs(1,graph,8,visited);
   
}