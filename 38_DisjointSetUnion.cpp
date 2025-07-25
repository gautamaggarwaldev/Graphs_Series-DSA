#include <iostream>
#include <vector>
using namespace std;
class DSU
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }
        return parent[node] = find(parent[node]);
    }

    void union_set(int a, int b)
    {
        int leaderA = find(a);
        int leaderB = find(b);
        if (leaderA != leaderB)
        {
            if (rank[leaderA] < rank[leaderB])
            {
                rank[leaderB] += rank[leaderA];
                parent[leaderA] = leaderB;
            }
            else
            {
                rank[leaderA] += rank[leaderB];
                parent[leaderB] = leaderA;
            }
        }
    }
};
int main()
{
    int n = 7; // Number of elements (0 to 6)
    DSU dsu(n);

    // Union some sets
    dsu.union_set(0, 1);
    dsu.union_set(2, 3);
    dsu.union_set(1, 2);
    dsu.union_set(4, 5);

    // Check if two elements belong to the same set
    cout << "Find(0): " << dsu.find(0) << endl;
    cout << "Find(3): " << dsu.find(3) << endl;
    cout << "Are 0 and 3 in same set? " << (dsu.find(0) == dsu.find(3) ? "Yes" : "No") << endl;

    cout << "Find(4): " << dsu.find(4) << endl;
    cout << "Find(6): " << dsu.find(6) << endl;
    cout << "Are 4 and 6 in same set? " << (dsu.find(4) == dsu.find(6) ? "Yes" : "No") << endl;

    // Join 5 and 6
    dsu.union_set(5, 6);

    cout << "After union(5,6), Are 4 and 6 in same set? " << (dsu.find(4) == dsu.find(6) ? "Yes" : "No") << endl;

    return 0;
}