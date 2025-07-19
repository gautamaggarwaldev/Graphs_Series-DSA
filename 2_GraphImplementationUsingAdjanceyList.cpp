# include <iostream>
# include <vector>
# include <unordered_map>
using namespace std;
void printGraph(unordered_map<int, vector<int>>& mp) {
    for(auto x : mp) {
        cout << x.first << " ----> ";
        for(int vertex : x.second) {
            cout << vertex << " ";
        }
        cout << endl;
    }
}
int main() {

    vector<vector<int>>edgeList = {{1, 2}, {2, 3}, {3, 4}, {4, 2}, {1, 3}};
    unordered_map<int, vector<int>>mp;
    int n = edgeList.size();
    for(int i=0;i<n;i++) {
        int a = edgeList[i][0];
        int b = edgeList[i][1];

        mp[a].push_back(b);
        mp[b].push_back(a);
    }

    printGraph(mp);

   
}